/*
   (c) Copyright 2001-2011  The world wide DirectFB Open Source Community (directfb.org)
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
#include "CorePalette.h"

#include <directfb_util.h>
#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>
#include <fusion/conf.h>
#include <core/core.h>
#include <core/CoreDFB_CallMode.h>

D_DEBUG_DOMAIN( DirectFB_CorePalette, "DirectFB/CorePalette", "DirectFB CorePalette" );

/*********************************************************************************************************************/

DFBResult
CorePalette_SetEntries(
                    CorePalette                               *obj,
                    const DFBColor                            *colors,
                    u32                                        num,
                    u32                                        offset
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IPaletteReal real;
			IPalette *super = (IPalette *)&real;

			IPaletteRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetEntries( super, colors, num, offset );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IPaletteRequestor requestor;
			IPalette *super = (IPalette *)&requestor;

			IPaletteRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetEntries( super, colors, num, offset );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CorePalette_SetEntriesYUV(
                    CorePalette                               *obj,
                    const DFBColorYUV                         *colors,
                    u32                                        num,
                    u32                                        offset
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IPaletteReal real;
			IPalette *super = (IPalette *)&real;

			IPaletteRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetEntriesYUV( super, colors, num, offset );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IPaletteRequestor requestor;
			IPalette *super = (IPalette *)&requestor;

			IPaletteRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetEntriesYUV( super, colors, num, offset );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

/*********************************************************************************************************************/

static FusionCallHandlerResult
CorePalette_Dispatch( int           caller,   /* fusion id of the caller */
                     int           call_arg, /* optional call parameter */
                     void         *ptr, /* optional call parameter */
                     unsigned int  length,
                     void         *ctx,      /* optional handler context */
                     unsigned int  serial,
                     void         *ret_ptr,
                     unsigned int  ret_size,
                     unsigned int *ret_length )
{
    CorePalette *obj = (CorePalette*) ctx;
    CorePaletteDispatch__Dispatch( obj, caller, call_arg, ptr, length, ret_ptr, ret_size, ret_length );

    return FCHR_RETURN;
}

void CorePalette_Init_Dispatch(
                    CoreDFB              *core,
                    CorePalette          *obj,
                    FusionCall           *call
)
{
    fusion_call_init3( call, CorePalette_Dispatch, obj, core->world );
}

void  CorePalette_Deinit_Dispatch(
                    FusionCall           *call
)
{
     fusion_call_destroy( call );
}

/*********************************************************************************************************************/

static __inline__ void *args_alloc( void *static_buffer, size_t size )
{
    void *buffer = static_buffer;

    if (size > FLUXED_ARGS_BYTES) {
        buffer = D_MALLOC( size );
        if (!buffer)
            return NULL;
    }

    return buffer;
}

static __inline__ void args_free( void *static_buffer, void *buffer )
{
    if (buffer != static_buffer)
        D_FREE( buffer );
}

static DFBResult IPaletteRequestor_SetEntries(IPalette *thiz, const DFBColor *colors, u32 num, u32 offset)
{
	DFBResult			ret = DFB_OK;
	char		args_static[FLUXED_ARGS_BYTES];
	char		return_args_static[FLUXED_ARGS_BYTES];
	CorePaletteSetEntries		*args = (CorePaletteSetEntries*) args_alloc( args_static, sizeof(CorePaletteSetEntries) + num * sizeof(DFBColor) );
	CorePaletteSetEntriesReturn *return_args;

	if (!args)
		return (DFBResult) D_OOM();

	return_args = (CorePaletteSetEntriesReturn*) args_alloc( return_args_static, sizeof(CorePaletteSetEntriesReturn) );

	if (!return_args) {
		args_free( args_static, args );
		return (DFBResult) D_OOM();
	}

	D_DEBUG_AT( DirectFB_CorePalette, "IPalette_Requestor::%s()\n", __FUNCTION__ );

	D_ASSERT( colors != NULL );

	args->num = num;
	args->offset = offset;
	direct_memcpy( (char*) (args + 1), colors, num * sizeof(DFBColor) );

	ret = (DFBResult) CorePalette_Call( thiz->obj, FCEF_NONE, CorePaletteCall_SetEntries, args, sizeof(CorePaletteSetEntries) + num * sizeof(DFBColor), return_args, sizeof(CorePaletteSetEntriesReturn), NULL );
	if (ret) {
		D_DERROR( ret, "%s: CorePalette_Call( CorePalette_SetEntries ) failed!\n", __FUNCTION__ );
		goto out;
	}

	if (return_args->result) {
		/*D_DERROR( return_args->result, "%s: CorePalette_SetEntries failed!\n", __FUNCTION__ );*/
		ret = return_args->result;
		goto out;
	}

out:
	args_free( return_args_static, return_args );
	args_free( args_static, args );
	return ret;
}

static DFBResult IPaletteRequestor_SetEntriesYUV(IPalette *thiz, const DFBColorYUV *colors, u32 num, u32 offset)
{
	DFBResult			ret = DFB_OK;
	char		args_static[FLUXED_ARGS_BYTES];
	char		return_args_static[FLUXED_ARGS_BYTES];
	CorePaletteSetEntriesYUV	   *args = (CorePaletteSetEntriesYUV*) args_alloc( args_static, sizeof(CorePaletteSetEntriesYUV) + num * sizeof(DFBColorYUV) );
	CorePaletteSetEntriesYUVReturn *return_args;

	if (!args)
		return (DFBResult) D_OOM();

	return_args = (CorePaletteSetEntriesYUVReturn*) args_alloc( return_args_static, sizeof(CorePaletteSetEntriesYUVReturn) );

	if (!return_args) {
		args_free( args_static, args );
		return (DFBResult) D_OOM();
	}

	D_DEBUG_AT( DirectFB_CorePalette, "IPalette_Requestor::%s()\n", __FUNCTION__ );

	D_ASSERT( colors != NULL );

	args->num = num;
	args->offset = offset;
	direct_memcpy( (char*) (args + 1), colors, num * sizeof(DFBColorYUV) );

	ret = (DFBResult) CorePalette_Call( thiz->obj, FCEF_NONE, CorePaletteCall_SetEntriesYUV, args, sizeof(CorePaletteSetEntriesYUV) + num * sizeof(DFBColorYUV), return_args, sizeof(CorePaletteSetEntriesYUVReturn), NULL );
	if (ret) {
		D_DERROR( ret, "%s: CorePalette_Call( CorePalette_SetEntriesYUV ) failed!\n", __FUNCTION__ );
		goto out;
	}

	if (return_args->result) {
		/*D_DERROR( return_args->result, "%s: CorePalette_SetEntriesYUV failed!\n", __FUNCTION__ );*/
		ret = return_args->result;
		goto out;
	}

out:
	args_free( return_args_static, return_args );
	args_free( args_static, args );

	return ret;
}


void IPaletteRequestorInit(IPaletteRequestor *thiz, CoreDFB *core, CorePalette *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

	thiz->base.SetEntries = IPaletteRequestor_SetEntries;
	thiz->base.SetEntriesYUV = IPaletteRequestor_SetEntriesYUV;
}

/*********************************************************************************************************************/

static DFBResult
__CorePaletteDispatch__Dispatch( CorePalette *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    D_UNUSED
    DFBResult ret;

    IPaletteReal real;
	IPalette *super = (IPalette *)&real;
	IPaletteRealInit(&real, core_dfb, obj);

    switch (method) {
        case CorePaletteCall_SetEntries: {
            D_UNUSED
            CorePaletteSetEntries       *args        = (CorePaletteSetEntries *) ptr;
            CorePaletteSetEntriesReturn *return_args = (CorePaletteSetEntriesReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CorePalette, "=-> CorePalette_SetEntries\n" );

            return_args->result = super->SetEntries(super, (DFBColor*) ((char*)(args + 1)), args->num, args->offset );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CorePaletteSetEntriesReturn);

            return DFB_OK;
        }

        case CorePaletteCall_SetEntriesYUV: {
            D_UNUSED
            CorePaletteSetEntriesYUV       *args        = (CorePaletteSetEntriesYUV *) ptr;
            CorePaletteSetEntriesYUVReturn *return_args = (CorePaletteSetEntriesYUVReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CorePalette, "=-> CorePalette_SetEntriesYUV\n" );

            return_args->result = super->SetEntriesYUV(super, (DFBColorYUV*) ((char*)(args + 1)), args->num, args->offset );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CorePaletteSetEntriesYUVReturn);

            return DFB_OK;
        }

    }

    return DFB_NOSUCHMETHOD;
}
/*********************************************************************************************************************/

DFBResult
CorePaletteDispatch__Dispatch( CorePalette *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    DFBResult ret = DFB_OK;

    D_DEBUG_AT( DirectFB_CorePalette, "CorePaletteDispatch::%s( %p )\n", __FUNCTION__, obj );

    Core_PushIdentity( caller );

    ret = __CorePaletteDispatch__Dispatch( obj, caller, method, ptr, length, ret_ptr, ret_size, ret_length );

    Core_PopIdentity();

    return ret;
}

