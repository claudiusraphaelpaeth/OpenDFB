/*
   (c) Copyright 2001-2009  The world wide DirectFB Open Source Community (directfb.org)
   (c) Copyright 2000-2004  Convergence (integrated media) GmbH

   All rights reserved.

   Written by Denis Oliver Kropp <dok@directfb.org>,
              Andreas Hundt <andi@fischlustig.de>,
              Sven Neumann <neo@directfb.org>,
              Ville Syrjälä <syrjala@sci.fi> and
              Claudio Ciccani <klan@users.sf.net>.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the
   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#include <config.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <core/core.h>
#include <core/graphics_state.h>
#include <core/state.h>
#include <core/surface.h>

#include <fusion/conf.h>

#include <core/CoreGraphicsStateClient.h>

#include <core/CoreDFB.h>
#include <core/CoreGraphicsState.h>

D_DEBUG_DOMAIN( Core_GraphicsStateClient, "Core/GfxState/Client", "DirectFB Core Graphics State Client" );

/**********************************************************************************************************************/
typedef struct _ClientList ClientList;

struct _ClientList {
	DirectMutex	lock;
	DirectLink	*clients;
};

static ClientList client_list = {0};

__attribute__((constructor))
static void __ClientList_Init( void )
{
     direct_mutex_init( &client_list.lock );
}

__attribute__((destructor))
static void __ClientList_Deinit(void)
{
	 direct_mutex_deinit( &client_list.lock );
}

void ClientList_AddClient( ClientList *thiz, CoreGraphicsStateClient *client )
{
	 direct_mutex_lock( &thiz->lock );
	 direct_list_append( &thiz->clients, &client->link );
	 direct_mutex_unlock( &thiz->lock );
}

void ClientList_RemoveClient( ClientList *thiz, CoreGraphicsStateClient *client )
{
	 direct_mutex_lock( &thiz->lock );
	 direct_list_remove( &thiz->clients, &client->link );
	 direct_mutex_unlock( &thiz->lock );
}

void ClientList_FlushAll(ClientList *thiz)
{
	CoreGraphicsStateClient* client;

	direct_mutex_lock( &thiz->lock );

	direct_list_foreach (client, thiz->clients) {
		CoreGraphicsStateClient_Flush(client);
	}

	direct_mutex_unlock( &thiz->lock );
}

void ClientList_FlushAllDst( ClientList *thiz, CoreSurface *surface )
{
	CoreGraphicsStateClient* client;

	direct_mutex_lock( &thiz->lock );

	direct_list_foreach (client, thiz->clients) {
	if (client->state->destination == surface)
		CoreGraphicsStateClient_Flush(client);
	}

	direct_mutex_unlock( &thiz->lock );
}


DFBResult
CoreGraphicsStateClient_Init( CoreGraphicsStateClient *client,
                              CardState               *state )
{
     DFBResult ret;

     D_DEBUG_AT( Core_GraphicsStateClient, "%s( client %p, state %p )\n", __FUNCTION__, client, state );

     D_ASSERT( client != NULL );
     D_MAGIC_ASSERT( state, CardState );
     D_MAGIC_ASSERT( state->core, CoreDFB );

     client->magic    = 0;
     client->core     = state->core;
     client->state    = state;

     ret = CoreDFB_CreateState( state->core, &client->gfx_state );
     if (ret)
          return ret;

     D_MAGIC_SET( client, CoreGraphicsStateClient );

	 ClientList_AddClient( &client_list, client );

     return DFB_OK;
}

void
CoreGraphicsStateClient_Deinit( CoreGraphicsStateClient *client )
{
     D_DEBUG_AT( Core_GraphicsStateClient, "%s( client %p )\n", __FUNCTION__, client );

     D_MAGIC_ASSERT( client, CoreGraphicsStateClient );

     dfb_graphics_state_unref( client->gfx_state );

	 ClientList_RemoveClient( &client_list, client );

     D_MAGIC_CLEAR( client );
}

void
CoreGraphicsStateClient_Flush( CoreGraphicsStateClient *client )
{
     D_DEBUG_AT( Core_GraphicsStateClient, "%s( client %p )\n", __FUNCTION__, client );

     D_MAGIC_ASSERT( client, CoreGraphicsStateClient );

     CoreGraphicsState_Flush( client->gfx_state );
}

void
CoreGraphicsStateClient_FlushAll()
{
     D_DEBUG_AT( Core_GraphicsStateClient, "%s()\n", __FUNCTION__ );

	 ClientList_FlushAll( &client_list );
}

void
CoreGraphicsStateClient_FlushAllDst( CoreSurface *surface )
{
     D_DEBUG_AT( Core_GraphicsStateClient, "%s()\n", __FUNCTION__ );

	 ClientList_FlushAllDst( &client_list, surface);
}

DFBResult
CoreGraphicsStateClient_ReleaseSource( CoreGraphicsStateClient *client )
{
     D_DEBUG_AT( Core_GraphicsStateClient, "%s()\n", __FUNCTION__ );

     D_MAGIC_ASSERT( client, CoreGraphicsStateClient );

     return CoreGraphicsState_ReleaseSource( client->gfx_state );
}

DFBResult
CoreGraphicsStateClient_SetColorAndIndex( CoreGraphicsStateClient *client,
                                          const DFBColor          *color,
                                          u32                      index )
{
     D_DEBUG_AT( Core_GraphicsStateClient, "%s()\n", __FUNCTION__ );

     D_MAGIC_ASSERT( client, CoreGraphicsStateClient );

     return CoreGraphicsState_SetColorAndIndex( client->gfx_state, color, index );
}

DFBResult
CoreGraphicsStateClient_SetState( CoreGraphicsStateClient *client,
                                  CardState               *state,
                                  StateModificationFlags   flags )
{
     DFBResult ret;

     D_DEBUG_AT( Core_GraphicsStateClient, "%s( client %p, state %p, flags 0x%08x )\n", __FUNCTION__, client, state, flags );

     D_MAGIC_ASSERT( client, CoreGraphicsStateClient );
     D_MAGIC_ASSERT( state, CardState );

     if (flags & SMF_DRAWING_FLAGS) {
          ret = CoreGraphicsState_SetDrawingFlags( client->gfx_state, state->drawingflags );
          if (ret)
               return ret;
     }

     if (flags & SMF_BLITTING_FLAGS) {
          ret = CoreGraphicsState_SetBlittingFlags( client->gfx_state, state->blittingflags );
          if (ret)
               return ret;
     }

     if (flags & SMF_CLIP) {
          ret = CoreGraphicsState_SetClip( client->gfx_state, &state->clip );
          if (ret)
               return ret;
     }

     if (flags & SMF_COLOR) {
          ret = CoreGraphicsState_SetColor( client->gfx_state, &state->color );
          if (ret)
               return ret;
     }

     if (flags & SMF_SRC_BLEND) {
          ret = CoreGraphicsState_SetSrcBlend( client->gfx_state, state->src_blend );
          if (ret)
               return ret;
     }

     if (flags & SMF_DST_BLEND) {
          ret = CoreGraphicsState_SetDstBlend( client->gfx_state, state->dst_blend );
          if (ret)
               return ret;
     }

     if (flags & SMF_SRC_COLORKEY) {
          ret = CoreGraphicsState_SetSrcColorKey( client->gfx_state, state->src_colorkey );
          if (ret)
               return ret;
     }

     if (flags & SMF_DST_COLORKEY) {
          ret = CoreGraphicsState_SetDstColorKey( client->gfx_state, state->dst_colorkey );
          if (ret)
               return ret;
     }

     if (flags & SMF_DESTINATION) {
          D_DEBUG_AT( Core_GraphicsStateClient, "  -> DESTINATION %p [%d]\n", state->destination, state->destination->object.id );

          ret = CoreGraphicsState_SetDestination( client->gfx_state, state->destination );
          if (ret)
               return ret;
     }

     if (flags & SMF_SOURCE) {
          ret = CoreGraphicsState_SetSource( client->gfx_state, state->source );
          if (ret)
               return ret;
     }

     if (flags & SMF_SOURCE_MASK) {
          ret = CoreGraphicsState_SetSourceMask( client->gfx_state, state->source_mask );
          if (ret)
               return ret;
     }

     if (flags & SMF_SOURCE_MASK_VALS) {
          ret = CoreGraphicsState_SetSourceMaskVals( client->gfx_state, &state->src_mask_offset, state->src_mask_flags );
          if (ret)
               return ret;
     }

     if (flags & SMF_INDEX_TRANSLATION) {
          ret = CoreGraphicsState_SetIndexTranslation( client->gfx_state, state->index_translation, state->num_translation );
          if (ret)
               return ret;
     }

     if (flags & SMF_COLORKEY) {
          ret = CoreGraphicsState_SetColorKey( client->gfx_state, &state->colorkey );
          if (ret)
               return ret;
     }

     if (flags & SMF_RENDER_OPTIONS) {
          ret = CoreGraphicsState_SetRenderOptions( client->gfx_state, state->render_options );
          if (ret)
               return ret;
     }

     if (flags & SMF_MATRIX) {
          ret = CoreGraphicsState_SetMatrix( client->gfx_state, state->matrix );
          if (ret)
               return ret;
     }

     if (flags & SMF_SOURCE2) {
          ret = CoreGraphicsState_SetSource2( client->gfx_state, state->source2 );
          if (ret)
               return ret;
     }

     if (flags & SMF_FROM) {
          ret = CoreGraphicsState_SetFrom( client->gfx_state, state->from, state->from_eye );
          if (ret)
               return ret;
     }

     if (flags & SMF_TO) {
          ret = CoreGraphicsState_SetTo( client->gfx_state, state->to, state->to_eye );
          if (ret)
               return ret;
     }

     if (flags & SMF_SRC_CONVOLUTION) {
          ret = CoreGraphicsState_SetSrcConvolution( client->gfx_state, &state->src_convolution );
          if (ret)
               return ret;
     }

     return DFB_OK;
}

DFBResult
CoreGraphicsStateClient_Update( CoreGraphicsStateClient *client,
                                DFBAccelerationMask      accel,
                                CardState               *state )
{
     DFBResult              ret;
     StateModificationFlags flags = (StateModificationFlags)(SMF_TO | SMF_DESTINATION | SMF_CLIP | SMF_RENDER_OPTIONS);

     D_DEBUG_AT( Core_GraphicsStateClient, "%s( client %p )\n", __FUNCTION__, client );

     D_MAGIC_ASSERT( client, CoreGraphicsStateClient );
     D_MAGIC_ASSERT( state, CardState );

     /*
      * dfb_gfxcard_state_check() moves flags to mod_hw,
      * called from IDirectFBSurface::GetAccelerationMask().
      *
      * FIXME: Add GetAccelerationMask() to CoreGraphicsState flux
      *        and do not load the graphics driver at slaves anymore.
      */
     state->modified = (StateModificationFlags)(state->modified | state->mod_hw);
     state->mod_hw   = SMF_NONE;

     if (state->render_options & DSRO_MATRIX)
          flags = (StateModificationFlags)(flags | SMF_MATRIX);

     if (DFB_DRAWING_FUNCTION( accel )) {
          flags = (StateModificationFlags)(flags | SMF_DRAWING_FLAGS | SMF_COLOR);

          if (state->drawingflags & DSDRAW_BLEND)
               flags = (StateModificationFlags)(flags | SMF_SRC_BLEND | SMF_DST_BLEND);

          if (state->drawingflags & DSDRAW_DST_COLORKEY)
               flags = (StateModificationFlags)(flags | SMF_DST_COLORKEY);
     }
     else {
          flags = (StateModificationFlags)(flags | SMF_BLITTING_FLAGS | SMF_FROM | SMF_SOURCE);

          if (accel == DFXL_BLIT2)
               flags = (StateModificationFlags)(flags | SMF_FROM | SMF_SOURCE2);

          if (state->blittingflags & (DSBLIT_BLEND_COLORALPHA |
                                      DSBLIT_COLORIZE |
                                      DSBLIT_SRC_PREMULTCOLOR))
               flags = (StateModificationFlags)(flags | SMF_COLOR);

          if (state->blittingflags & (DSBLIT_BLEND_ALPHACHANNEL |
                                      DSBLIT_BLEND_COLORALPHA))
               flags = (StateModificationFlags)(flags | SMF_SRC_BLEND | SMF_DST_BLEND);

          if (state->blittingflags & DSBLIT_SRC_COLORKEY)
               flags = (StateModificationFlags)(flags | SMF_SRC_COLORKEY);

          if (state->blittingflags & DSBLIT_DST_COLORKEY)
               flags = (StateModificationFlags)(flags | SMF_DST_COLORKEY);

          if (state->blittingflags & (DSBLIT_SRC_MASK_ALPHA | DSBLIT_SRC_MASK_COLOR))
               flags = (StateModificationFlags)(flags | SMF_FROM | SMF_SOURCE_MASK | SMF_SOURCE_MASK_VALS);

          if (state->blittingflags & DSBLIT_INDEX_TRANSLATION)
               flags = (StateModificationFlags)(flags | SMF_INDEX_TRANSLATION);

          if (state->blittingflags & DSBLIT_COLORKEY_PROTECT)
               flags = (StateModificationFlags)(flags | SMF_COLORKEY);

          if (state->blittingflags & DSBLIT_SRC_CONVOLUTION)
               flags = (StateModificationFlags)(flags | SMF_SRC_CONVOLUTION);
     }

     ret = CoreGraphicsStateClient_SetState( client, state, (StateModificationFlags)(state->modified & flags) );
     if (ret)
          return ret;

     state->modified = (StateModificationFlags)(state->modified & ~flags);

     return DFB_OK;
}

DFBResult
CoreGraphicsStateClient_DrawRectangles( CoreGraphicsStateClient *client,
                                        const DFBRectangle      *rects,
                                        unsigned int             num )
{
     D_DEBUG_AT( Core_GraphicsStateClient, "%s( client %p )\n", __FUNCTION__, client );

     D_MAGIC_ASSERT( client, CoreGraphicsStateClient );
     D_ASSERT( rects != NULL );

     if (!dfb_config->call_nodirect && (dfb_core_is_master( client->core ) || !fusion_config->secure_fusion)) {
          unsigned int i;

          for (i=0; i<num; i++)
               // FIXME: will overwrite rects
               dfb_gfxcard_drawrectangle( (DFBRectangle*) &rects[i], client->state );
     }
     else {
          DFBResult ret;

          CoreGraphicsStateClient_Update( client, DFXL_DRAWRECTANGLE, client->state );

          ret = CoreGraphicsState_DrawRectangles( client->gfx_state, rects, num );
          if (ret)
               return ret;
     }

     return DFB_OK;
}

DFBResult
CoreGraphicsStateClient_DrawLines( CoreGraphicsStateClient *client,
                                   const DFBRegion         *lines,
                                   unsigned int             num )
{
     D_DEBUG_AT( Core_GraphicsStateClient, "%s( client %p )\n", __FUNCTION__, client );

     D_MAGIC_ASSERT( client, CoreGraphicsStateClient );
     D_ASSERT( lines != NULL );

     if (!dfb_config->call_nodirect && (dfb_core_is_master( client->core ) || !fusion_config->secure_fusion)) {
          // FIXME: will overwrite lines
          dfb_gfxcard_drawlines( (DFBRegion*) lines, num, client->state );
     }
     else {
          DFBResult ret;

          CoreGraphicsStateClient_Update( client, DFXL_DRAWLINE, client->state );

          ret = CoreGraphicsState_DrawLines( client->gfx_state, lines, num );
          if (ret)
               return ret;
     }

     return DFB_OK;
}

DFBResult
CoreGraphicsStateClient_FillRectangles( CoreGraphicsStateClient *client,
                                        const DFBRectangle      *rects,
                                        unsigned int             num )
{
     D_DEBUG_AT( Core_GraphicsStateClient, "%s( client %p )\n", __FUNCTION__, client );

     D_MAGIC_ASSERT( client, CoreGraphicsStateClient );
     D_ASSERT( rects != NULL );

     if (!dfb_config->call_nodirect && (dfb_core_is_master( client->core ) || !fusion_config->secure_fusion)) {
          dfb_gfxcard_fillrectangles( rects, num, client->state );
     }
     else {
          DFBResult ret;

          CoreGraphicsStateClient_Update( client, DFXL_FILLRECTANGLE, client->state );

          ret = CoreGraphicsState_FillRectangles( client->gfx_state, rects, num );
          if (ret)
               return ret;
     }

     return DFB_OK;
}

DFBResult
CoreGraphicsStateClient_Blit( CoreGraphicsStateClient *client,
                              const DFBRectangle      *rects,
                              const DFBPoint          *points,
                              unsigned int             num )
{
     D_DEBUG_AT( Core_GraphicsStateClient, "%s( client %p )\n", __FUNCTION__, client );

     D_MAGIC_ASSERT( client, CoreGraphicsStateClient );
     D_ASSERT( rects != NULL );
     D_ASSERT( points != NULL );

     if (!dfb_config->call_nodirect && (dfb_core_is_master( client->core ) || !fusion_config->secure_fusion)) {
          // FIXME: will overwrite rects, points
          dfb_gfxcard_batchblit( (DFBRectangle*) rects, (DFBPoint*) points, num, client->state );
     }
     else {
          DFBResult    ret;
          unsigned int i;

          CoreGraphicsStateClient_Update( client, DFXL_BLIT, client->state );

          for (i=0; i<num; i+=200) {
               ret = CoreGraphicsState_Blit( client->gfx_state, &rects[i], &points[i], MIN(200, num-i) );
               if (ret)
                    return ret;
          }
     }

     return DFB_OK;
}

DFBResult
CoreGraphicsStateClient_Blit2( CoreGraphicsStateClient *client,
                               const DFBRectangle      *rects,
                               const DFBPoint          *points1,
                               const DFBPoint          *points2,
                               unsigned int             num )
{
     D_DEBUG_AT( Core_GraphicsStateClient, "%s( client %p )\n", __FUNCTION__, client );

     D_MAGIC_ASSERT( client, CoreGraphicsStateClient );
     D_ASSERT( rects != NULL );
     D_ASSERT( points1 != NULL );
     D_ASSERT( points2 != NULL );

     if (!dfb_config->call_nodirect && (dfb_core_is_master( client->core ) || !fusion_config->secure_fusion)) {
          // FIXME: will overwrite rects, points
          dfb_gfxcard_batchblit2( (DFBRectangle*) rects, (DFBPoint*) points1, (DFBPoint*) points2, num, client->state );
     }
     else {
          DFBResult ret;

          CoreGraphicsStateClient_Update( client, DFXL_BLIT2, client->state );

          ret = CoreGraphicsState_Blit2( client->gfx_state, rects, points1, points2, num );
          if (ret)
               return ret;
     }

     return DFB_OK;
}

DFBResult
CoreGraphicsStateClient_StretchBlit( CoreGraphicsStateClient *client,
                                     const DFBRectangle      *srects,
                                     const DFBRectangle      *drects,
                                     unsigned int             num )
{
     D_DEBUG_AT( Core_GraphicsStateClient, "%s( client %p )\n", __FUNCTION__, client );

     D_MAGIC_ASSERT( client, CoreGraphicsStateClient );
     D_ASSERT( srects != NULL );
     D_ASSERT( drects != NULL );

     if (num == 0)
          return DFB_OK;

     if (!dfb_config->call_nodirect && (dfb_core_is_master( client->core ) || !fusion_config->secure_fusion)) {
          if (num == 1 && srects[0].w == drects[0].w && srects[0].h == drects[0].h) {
               DFBPoint point = { drects[0].x, drects[0].y };

               // FIXME: will overwrite rects, points
               dfb_gfxcard_batchblit( (DFBRectangle*) srects, &point, 1, client->state );
          }
          else {
               // FIXME: will overwrite rects
               dfb_gfxcard_batchstretchblit( (DFBRectangle*) srects, (DFBRectangle*) drects, num, client->state );
          }
     }
     else {
          DFBResult ret;

          if (num == 1 && srects[0].w == drects[0].w && srects[0].h == drects[0].h) {
               CoreGraphicsStateClient_Update( client, DFXL_BLIT, client->state );

               DFBPoint point = { drects[0].x, drects[0].y };
               ret = CoreGraphicsState_Blit( client->gfx_state, srects, &point, 1 );
               if (ret)
                    return ret;
          }
          else {
               CoreGraphicsStateClient_Update( client, DFXL_STRETCHBLIT, client->state );

               ret = CoreGraphicsState_StretchBlit( client->gfx_state, srects, drects, num );
               if (ret)
                    return ret;
          }
     }

     return DFB_OK;
}

DFBResult
CoreGraphicsStateClient_TileBlit( CoreGraphicsStateClient *client,
                                  const DFBRectangle      *rects,
                                  const DFBPoint          *points1,
                                  const DFBPoint          *points2,
                                  unsigned int             num )
{
     D_DEBUG_AT( Core_GraphicsStateClient, "%s( client %p )\n", __FUNCTION__, client );

     D_MAGIC_ASSERT( client, CoreGraphicsStateClient );
     D_ASSERT( rects != NULL );
     D_ASSERT( points1 != NULL );
     D_ASSERT( points2 != NULL );

     if (!dfb_config->call_nodirect && (dfb_core_is_master( client->core ) || !fusion_config->secure_fusion)) {
          u32 i;

          // FIXME: will overwrite rects, points
          for (i=0; i<num; i++)
               dfb_gfxcard_tileblit( (DFBRectangle*) &rects[i], points1[i].x, points1[i].y, points2[i].x, points2[i].y, client->state );
     }
     else {
          DFBResult ret;

          CoreGraphicsStateClient_Update( client, DFXL_BLIT, client->state );

          ret = CoreGraphicsState_TileBlit( client->gfx_state, rects, points1, points2, num );
          if (ret)
               return ret;
     }

     return DFB_OK;
}


