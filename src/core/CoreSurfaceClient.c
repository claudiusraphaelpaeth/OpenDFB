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

#include "CoreSurfaceClient.h"

#include <directfb_util.h>
#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>
#include <fusion/conf.h>
#include <core/core.h>
#include <core/CoreDFB_CallMode.h>


D_DEBUG_DOMAIN( DirectFB_CoreSurfaceClient, "DirectFB/CoreSurfaceClient", "DirectFB CoreSurfaceClient" );

/*********************************************************************************************************************/

DFBResult
CoreSurfaceClient_FrameAck(
                    CoreSurfaceClient                         *obj,
                    u32                                        flip_count
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
            ISurfaceClientReal real;
			ISurfaceClient *super = (ISurfaceClient *)&real;
			ISurfaceClientRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->FrameAck( super, flip_count );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ISurfaceClientRequestor requestor;
			ISurfaceClient *super = (ISurfaceClient *)&requestor;

			ISurfaceClientRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->FrameAck( super, flip_count );
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
CoreSurfaceClient_Dispatch( int           caller,   /* fusion id of the caller */
                     int           call_arg, /* optional call parameter */
                     void         *ptr, /* optional call parameter */
                     unsigned int  length,
                     void         *ctx,      /* optional handler context */
                     unsigned int  serial,
                     void         *ret_ptr,
                     unsigned int  ret_size,
                     unsigned int *ret_length )
{
    CoreSurfaceClient *obj = (CoreSurfaceClient*) ctx;
    CoreSurfaceClientDispatch__Dispatch( obj, caller, call_arg, ptr, length, ret_ptr, ret_size, ret_length );

    return FCHR_RETURN;
}

void CoreSurfaceClient_Init_Dispatch(
                    CoreDFB              *core,
                    CoreSurfaceClient    *obj,
                    FusionCall           *call
)
{
    fusion_call_init3( call, CoreSurfaceClient_Dispatch, obj, core->world );
}

void  CoreSurfaceClient_Deinit_Dispatch(
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


DFBResult
ISurfaceClientRequestor_FrameAck(ISurfaceClient *thiz,
                    u32                                        flip_count
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    CoreSurfaceClientFrameAck       *args = (CoreSurfaceClientFrameAck*) args_alloc( args_static, sizeof(CoreSurfaceClientFrameAck) );

    if (!args)
        return (DFBResult) D_OOM();

    D_DEBUG_AT( DirectFB_CoreSurfaceClient, "ISurfaceClient_Requestor::%s()\n", __FUNCTION__ );


    args->flip_count = flip_count;

    ret = (DFBResult) CoreSurfaceClient_Call( thiz->obj, (FusionCallExecFlags)(FCEF_ONEWAY), CoreSurfaceClientCall_FrameAck, args, sizeof(CoreSurfaceClientFrameAck), NULL, 0, NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreSurfaceClient_Call( CoreSurfaceClient_FrameAck ) failed!\n", __FUNCTION__ );
        goto out;
    }



out:
    args_free( args_static, args );
    return ret;
}

void ISurfaceClientRequestorInit(ISurfaceClientRequestor *thiz, CoreDFB *core, CoreSurfaceClient *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

	thiz->base.FrameAck = ISurfaceClientRequestor_FrameAck;
}

/*********************************************************************************************************************/

static DFBResult
__CoreSurfaceClientDispatch__Dispatch( CoreSurfaceClient *obj,
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

	ISurfaceClientReal real;
	ISurfaceClient *super = (ISurfaceClient *)&real;
	ISurfaceClientRealInit( &real, core_dfb, obj );

    switch (method) {
        case CoreSurfaceClientCall_FrameAck: {
            D_UNUSED
            CoreSurfaceClientFrameAck       *args        = (CoreSurfaceClientFrameAck *) ptr;

            D_DEBUG_AT( DirectFB_CoreSurfaceClient, "=-> CoreSurfaceClientCall_FrameAck\n" );

            D_DEBUG_AT( DirectFB_CoreSurfaceClient, "  -> flip_count = %u\n", args->flip_count );

            super->FrameAck( super, args->flip_count );

            return DFB_OK;
        }

    }

    return DFB_NOSUCHMETHOD;
}
/*********************************************************************************************************************/

DFBResult
CoreSurfaceClientDispatch__Dispatch( CoreSurfaceClient *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    DFBResult ret = DFB_OK;

    D_DEBUG_AT( DirectFB_CoreSurfaceClient, "CoreSurfaceClientDispatch::%s( %p )\n", __FUNCTION__, obj );

    Core_PushIdentity( caller );

    ret = __CoreSurfaceClientDispatch__Dispatch( obj, caller, method, ptr, length, ret_ptr, ret_size, ret_length );

    Core_PopIdentity();

    return ret;
}

