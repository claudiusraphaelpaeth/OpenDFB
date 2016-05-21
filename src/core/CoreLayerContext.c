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

#include "CoreLayerContext.h"


#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <fusion/conf.h>

#include <core/core.h>

#include <core/CoreDFB_CallMode.h>

D_DEBUG_DOMAIN( DirectFB_CoreLayerContext, "DirectFB/CoreLayerContext", "DirectFB CoreLayerContext" );

/*********************************************************************************************************************/

DFBResult
CoreLayerContext_GetPrimaryRegion(
                    CoreLayerContext                          *obj,
                    bool                                       create,
                    CoreLayerRegion                          **ret_region
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->GetPrimaryRegion(super, create, ret_region );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->GetPrimaryRegion( super, create, ret_region );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_TestConfiguration(
                    CoreLayerContext                          *obj,
                    const DFBDisplayLayerConfig               *config,
                    DFBDisplayLayerConfigFlags                *ret_failed
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->TestConfiguration( super, config, ret_failed );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->TestConfiguration( super, config, ret_failed );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_SetConfiguration(
                    CoreLayerContext                          *obj,
                    const DFBDisplayLayerConfig               *config
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetConfiguration( super, config );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetConfiguration( super, config );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_SetSrcColorKey(
                    CoreLayerContext                          *obj,
                    const DFBColorKey                         *key
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetSrcColorKey( super, key );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetSrcColorKey( super, key );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_SetDstColorKey(
                    CoreLayerContext                          *obj,
                    const DFBColorKey                         *key
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetDstColorKey( super, key );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetDstColorKey( super, key );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_SetSourceRectangle(
                    CoreLayerContext                          *obj,
                    const DFBRectangle                        *rectangle
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetSourceRectangle( super, rectangle );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetSourceRectangle( super, rectangle );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_SetScreenLocation(
                    CoreLayerContext                          *obj,
                    const DFBLocation                         *location
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetScreenLocation( super, location );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetScreenLocation( super, location );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_SetScreenRectangle(
                    CoreLayerContext                          *obj,
                    const DFBRectangle                        *rectangle
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetScreenRectangle( super, rectangle );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetScreenRectangle( super, rectangle );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_SetScreenPosition(
                    CoreLayerContext                          *obj,
                    const DFBPoint                            *position
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetScreenPosition( super, position );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetScreenPosition( super, position );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_SetOpacity(
                    CoreLayerContext                          *obj,
                    u8                                         opacity
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetOpacity( super, opacity );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetOpacity( super, opacity );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_SetRotation(
                    CoreLayerContext                          *obj,
                    s32                                        rotation
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetRotation( super, rotation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetRotation( super, rotation );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_SetColorAdjustment(
                    CoreLayerContext                          *obj,
                    const DFBColorAdjustment                  *adjustment
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetColorAdjustment( super, adjustment );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetColorAdjustment( super, adjustment );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_SetStereoDepth(
                    CoreLayerContext                          *obj,
                    bool                                       follow_video,
                    s32                                        z
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetStereoDepth( super, follow_video, z );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetStereoDepth( super, follow_video, z );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_SetFieldParity(
                    CoreLayerContext                          *obj,
                    u32                                        field
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetFieldParity( super, field );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetFieldParity( super, field );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_SetClipRegions(
                    CoreLayerContext                          *obj,
                    const DFBRegion                           *regions,
                    u32                                        num,
                    bool                                       positive
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetClipRegions( super, regions, num, positive );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->SetClipRegions( super, regions, num, positive );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_CreateWindow(
                    CoreLayerContext                          *obj,
                    const DFBWindowDescription                *description,
                    CoreWindow                               **ret_window
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->CreateWindow( super, description, ret_window );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->CreateWindow( super, description, ret_window );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_FindWindow(
                    CoreLayerContext                          *obj,
                    DFBWindowID                                window_id,
                    CoreWindow                               **ret_window
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->FindWindow( super, window_id, ret_window );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->FindWindow( super, window_id, ret_window );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreLayerContext_FindWindowByResourceID(
                    CoreLayerContext                          *obj,
                    u64                                        resource_id,
                    CoreWindow                               **ret_window
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			ILayerContextReal real;
			ILayerContext *super = (ILayerContext *)&real;
			ILayerContextRealInit(&real, core_dfb, obj);

            Core_PushCalling();
            ret = super->FindWindowByResourceID( super, resource_id, ret_window );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			ILayerContextRequestor requestor;
			ILayerContext *super = (ILayerContext *)&requestor;
			ILayerContextRequestorInit(&requestor, core_dfb, obj);

            Core_PushCalling();
            ret = super->FindWindowByResourceID( super, resource_id, ret_window );
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
CoreLayerContext_Dispatch( int           caller,   /* fusion id of the caller */
                     int           call_arg, /* optional call parameter */
                     void         *ptr, /* optional call parameter */
                     unsigned int  length,
                     void         *ctx,      /* optional handler context */
                     unsigned int  serial,
                     void         *ret_ptr,
                     unsigned int  ret_size,
                     unsigned int *ret_length )
{
    CoreLayerContext *obj = (CoreLayerContext*) ctx;
    CoreLayerContextDispatch__Dispatch( obj, caller, call_arg, ptr, length, ret_ptr, ret_size, ret_length );

    return FCHR_RETURN;
}

void CoreLayerContext_Init_Dispatch(
                    CoreDFB              *core,
                    CoreLayerContext     *obj,
                    FusionCall           *call
)
{
    fusion_call_init3( call, CoreLayerContext_Dispatch, obj, core->world );
}

void  CoreLayerContext_Deinit_Dispatch(
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
ILayerContextRequestor_GetPrimaryRegion(ILayerContext *thiz,
                    bool                                       create,
                    CoreLayerRegion                          **ret_region
)
{
    DFBResult           ret = DFB_OK;
    CoreLayerRegion *region = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextGetPrimaryRegion       *args = (CoreLayerContextGetPrimaryRegion*) args_alloc( args_static, sizeof(CoreLayerContextGetPrimaryRegion) );
    CoreLayerContextGetPrimaryRegionReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextGetPrimaryRegionReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextGetPrimaryRegionReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( ret_region != NULL );

    args->create = create;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_GetPrimaryRegion, args, sizeof(CoreLayerContextGetPrimaryRegion), return_args, sizeof(CoreLayerContextGetPrimaryRegionReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_GetPrimaryRegion ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_GetPrimaryRegion failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreLayerRegion_Catch( thiz->core, return_args->region_ptr, &region );
    if (ret) {
         D_DERROR( ret, "%s: Catching region by ID %u failed!\n", __FUNCTION__, return_args->region_id );
         goto out;
    }

    *ret_region = region;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_TestConfiguration(ILayerContext *thiz,
                    const DFBDisplayLayerConfig               *config,
                    DFBDisplayLayerConfigFlags                *ret_failed
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextTestConfiguration       *args = (CoreLayerContextTestConfiguration*) args_alloc( args_static, sizeof(CoreLayerContextTestConfiguration) );
    CoreLayerContextTestConfigurationReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextTestConfigurationReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextTestConfigurationReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    args->config = *config;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_TestConfiguration, args, sizeof(CoreLayerContextTestConfiguration), return_args, sizeof(CoreLayerContextTestConfigurationReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_TestConfiguration ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_TestConfiguration failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    if (ret_failed)
        *ret_failed = return_args->failed;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_SetConfiguration(ILayerContext *thiz,
                    const DFBDisplayLayerConfig               *config
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextSetConfiguration       *args = (CoreLayerContextSetConfiguration*) args_alloc( args_static, sizeof(CoreLayerContextSetConfiguration) );
    CoreLayerContextSetConfigurationReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextSetConfigurationReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextSetConfigurationReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    args->config = *config;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_SetConfiguration, args, sizeof(CoreLayerContextSetConfiguration), return_args, sizeof(CoreLayerContextSetConfigurationReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_SetConfiguration ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_SetConfiguration failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_SetSrcColorKey(ILayerContext *thiz,
                    const DFBColorKey                         *key
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextSetSrcColorKey       *args = (CoreLayerContextSetSrcColorKey*) args_alloc( args_static, sizeof(CoreLayerContextSetSrcColorKey) );
    CoreLayerContextSetSrcColorKeyReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextSetSrcColorKeyReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextSetSrcColorKeyReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( key != NULL );

    args->key = *key;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_SetSrcColorKey, args, sizeof(CoreLayerContextSetSrcColorKey), return_args, sizeof(CoreLayerContextSetSrcColorKeyReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_SetSrcColorKey ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_SetSrcColorKey failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_SetDstColorKey(ILayerContext *thiz,
                    const DFBColorKey                         *key
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextSetDstColorKey       *args = (CoreLayerContextSetDstColorKey*) args_alloc( args_static, sizeof(CoreLayerContextSetDstColorKey) );
    CoreLayerContextSetDstColorKeyReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextSetDstColorKeyReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextSetDstColorKeyReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( key != NULL );

    args->key = *key;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_SetDstColorKey, args, sizeof(CoreLayerContextSetDstColorKey), return_args, sizeof(CoreLayerContextSetDstColorKeyReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_SetDstColorKey ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_SetDstColorKey failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_SetSourceRectangle(ILayerContext *thiz,
                    const DFBRectangle                        *rectangle
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextSetSourceRectangle       *args = (CoreLayerContextSetSourceRectangle*) args_alloc( args_static, sizeof(CoreLayerContextSetSourceRectangle) );
    CoreLayerContextSetSourceRectangleReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextSetSourceRectangleReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextSetSourceRectangleReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( rectangle != NULL );

    args->rectangle = *rectangle;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_SetSourceRectangle, args, sizeof(CoreLayerContextSetSourceRectangle), return_args, sizeof(CoreLayerContextSetSourceRectangleReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_SetSourceRectangle ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_SetSourceRectangle failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_SetScreenLocation(ILayerContext *thiz,
                    const DFBLocation                         *location
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextSetScreenLocation       *args = (CoreLayerContextSetScreenLocation*) args_alloc( args_static, sizeof(CoreLayerContextSetScreenLocation) );
    CoreLayerContextSetScreenLocationReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextSetScreenLocationReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextSetScreenLocationReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( location != NULL );

    args->location = *location;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_SetScreenLocation, args, sizeof(CoreLayerContextSetScreenLocation), return_args, sizeof(CoreLayerContextSetScreenLocationReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_SetScreenLocation ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_SetScreenLocation failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_SetScreenRectangle(ILayerContext *thiz,
                    const DFBRectangle                        *rectangle
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextSetScreenRectangle       *args = (CoreLayerContextSetScreenRectangle*) args_alloc( args_static, sizeof(CoreLayerContextSetScreenRectangle) );
    CoreLayerContextSetScreenRectangleReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextSetScreenRectangleReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextSetScreenRectangleReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( rectangle != NULL );

    args->rectangle = *rectangle;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_SetScreenRectangle, args, sizeof(CoreLayerContextSetScreenRectangle), return_args, sizeof(CoreLayerContextSetScreenRectangleReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_SetScreenRectangle ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_SetScreenRectangle failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_SetScreenPosition(ILayerContext *thiz,
                    const DFBPoint                            *position
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextSetScreenPosition       *args = (CoreLayerContextSetScreenPosition*) args_alloc( args_static, sizeof(CoreLayerContextSetScreenPosition) );
    CoreLayerContextSetScreenPositionReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextSetScreenPositionReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextSetScreenPositionReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( position != NULL );

    args->position = *position;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_SetScreenPosition, args, sizeof(CoreLayerContextSetScreenPosition), return_args, sizeof(CoreLayerContextSetScreenPositionReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_SetScreenPosition ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_SetScreenPosition failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_SetOpacity(ILayerContext *thiz,
                    u8                                         opacity
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextSetOpacity       *args = (CoreLayerContextSetOpacity*) args_alloc( args_static, sizeof(CoreLayerContextSetOpacity) );
    CoreLayerContextSetOpacityReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextSetOpacityReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextSetOpacityReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );


    args->opacity = opacity;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_SetOpacity, args, sizeof(CoreLayerContextSetOpacity), return_args, sizeof(CoreLayerContextSetOpacityReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_SetOpacity ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_SetOpacity failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_SetRotation(ILayerContext *thiz,
                    s32                                        rotation
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextSetRotation       *args = (CoreLayerContextSetRotation*) args_alloc( args_static, sizeof(CoreLayerContextSetRotation) );
    CoreLayerContextSetRotationReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextSetRotationReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextSetRotationReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );


    args->rotation = rotation;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_SetRotation, args, sizeof(CoreLayerContextSetRotation), return_args, sizeof(CoreLayerContextSetRotationReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_SetRotation ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_SetRotation failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_SetColorAdjustment(ILayerContext *thiz,
                    const DFBColorAdjustment                  *adjustment
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextSetColorAdjustment       *args = (CoreLayerContextSetColorAdjustment*) args_alloc( args_static, sizeof(CoreLayerContextSetColorAdjustment) );
    CoreLayerContextSetColorAdjustmentReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextSetColorAdjustmentReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextSetColorAdjustmentReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( adjustment != NULL );

    args->adjustment = *adjustment;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_SetColorAdjustment, args, sizeof(CoreLayerContextSetColorAdjustment), return_args, sizeof(CoreLayerContextSetColorAdjustmentReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_SetColorAdjustment ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_SetColorAdjustment failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_SetStereoDepth(ILayerContext *thiz,
                    bool                                       follow_video,
                    s32                                        z
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextSetStereoDepth       *args = (CoreLayerContextSetStereoDepth*) args_alloc( args_static, sizeof(CoreLayerContextSetStereoDepth) );
    CoreLayerContextSetStereoDepthReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextSetStereoDepthReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextSetStereoDepthReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );


    args->follow_video = follow_video;
    args->z = z;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_SetStereoDepth, args, sizeof(CoreLayerContextSetStereoDepth), return_args, sizeof(CoreLayerContextSetStereoDepthReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_SetStereoDepth ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_SetStereoDepth failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_SetFieldParity(ILayerContext *thiz,
                    u32                                        field
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextSetFieldParity       *args = (CoreLayerContextSetFieldParity*) args_alloc( args_static, sizeof(CoreLayerContextSetFieldParity) );
    CoreLayerContextSetFieldParityReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextSetFieldParityReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextSetFieldParityReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );


    args->field = field;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_SetFieldParity, args, sizeof(CoreLayerContextSetFieldParity), return_args, sizeof(CoreLayerContextSetFieldParityReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_SetFieldParity ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_SetFieldParity failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_SetClipRegions(ILayerContext *thiz,
                    const DFBRegion                           *regions,
                    u32                                        num,
                    bool                                       positive
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextSetClipRegions       *args = (CoreLayerContextSetClipRegions*) args_alloc( args_static, sizeof(CoreLayerContextSetClipRegions) + num * sizeof(DFBRegion) );
    CoreLayerContextSetClipRegionsReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextSetClipRegionsReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextSetClipRegionsReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( regions != NULL );

    args->num = num;
    args->positive = positive;
    direct_memcpy( (char*) (args + 1), regions, num * sizeof(DFBRegion) );

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_SetClipRegions, args, sizeof(CoreLayerContextSetClipRegions) + num * sizeof(DFBRegion), return_args, sizeof(CoreLayerContextSetClipRegionsReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_SetClipRegions ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_SetClipRegions failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_CreateWindow(ILayerContext *thiz,
                    const DFBWindowDescription                *description,
                    CoreWindow                               **ret_window
)
{
    DFBResult           ret = DFB_OK;
    CoreWindow *window = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextCreateWindow       *args = (CoreLayerContextCreateWindow*) args_alloc( args_static, sizeof(CoreLayerContextCreateWindow) );
    CoreLayerContextCreateWindowReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextCreateWindowReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextCreateWindowReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( description != NULL );
    D_ASSERT( ret_window != NULL );

    args->description = *description;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_CreateWindow, args, sizeof(CoreLayerContextCreateWindow), return_args, sizeof(CoreLayerContextCreateWindowReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_CreateWindow ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_CreateWindow failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreWindow_Catch( thiz->core, return_args->window_ptr, &window );
    if (ret) {
         D_DERROR( ret, "%s: Catching window by ID %u failed!\n", __FUNCTION__, return_args->window_id );
         goto out;
    }

    *ret_window = window;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_FindWindow(ILayerContext *thiz,
                    DFBWindowID                                window_id,
                    CoreWindow                               **ret_window
)
{
    DFBResult           ret = DFB_OK;
    CoreWindow *window = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextFindWindow       *args = (CoreLayerContextFindWindow*) args_alloc( args_static, sizeof(CoreLayerContextFindWindow) );
    CoreLayerContextFindWindowReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextFindWindowReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextFindWindowReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( ret_window != NULL );

    args->window_id = window_id;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_FindWindow, args, sizeof(CoreLayerContextFindWindow), return_args, sizeof(CoreLayerContextFindWindowReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_FindWindow ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_FindWindow failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreWindow_Catch( thiz->core, return_args->window_ptr, &window );
    if (ret) {
         D_DERROR( ret, "%s: Catching window by ID %u failed!\n", __FUNCTION__, return_args->window_id );
         goto out;
    }

    *ret_window = window;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
ILayerContextRequestor_FindWindowByResourceID(ILayerContext *thiz,
                    u64                                        resource_id,
                    CoreWindow                               **ret_window
)
{
    DFBResult           ret = DFB_OK;
    CoreWindow *window = NULL;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreLayerContextFindWindowByResourceID       *args = (CoreLayerContextFindWindowByResourceID*) args_alloc( args_static, sizeof(CoreLayerContextFindWindowByResourceID) );
    CoreLayerContextFindWindowByResourceIDReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreLayerContextFindWindowByResourceIDReturn*) args_alloc( return_args_static, sizeof(CoreLayerContextFindWindowByResourceIDReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreLayerContext, "ILayerContextRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( ret_window != NULL );

    args->resource_id = resource_id;

    ret = (DFBResult) CoreLayerContext_Call( thiz->obj, FCEF_NONE, CoreLayerContextCall_FindWindowByResourceID, args, sizeof(CoreLayerContextFindWindowByResourceID), return_args, sizeof(CoreLayerContextFindWindowByResourceIDReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreLayerContext_Call( CoreLayerContext_FindWindowByResourceID ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreLayerContext_FindWindowByResourceID failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }


    ret = (DFBResult) CoreWindow_Catch( thiz->core, return_args->window_ptr, &window );
    if (ret) {
         D_DERROR( ret, "%s: Catching window by ID %u failed!\n", __FUNCTION__, return_args->window_id );
         goto out;
    }

    *ret_window = window;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}

void ILayerContextRequestorInit(ILayerContextRequestor *thiz, CoreDFB *core, CoreLayerContext *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

  	thiz->base.GetPrimaryRegion = ILayerContextRequestor_GetPrimaryRegion;
  	thiz->base.TestConfiguration = ILayerContextRequestor_TestConfiguration;
	thiz->base.SetConfiguration = ILayerContextRequestor_SetConfiguration;
	thiz->base.SetSrcColorKey = ILayerContextRequestor_SetSrcColorKey;
	thiz->base.SetDstColorKey = ILayerContextRequestor_SetDstColorKey;
	thiz->base.SetSourceRectangle = ILayerContextRequestor_SetSourceRectangle;
	thiz->base.SetScreenLocation = ILayerContextRequestor_SetScreenLocation;
	thiz->base.SetScreenRectangle = ILayerContextRequestor_SetScreenRectangle;
	thiz->base.SetScreenPosition = ILayerContextRequestor_SetScreenPosition;
	thiz->base.SetOpacity = ILayerContextRequestor_SetOpacity;
	thiz->base.SetRotation = ILayerContextRequestor_SetRotation;
	thiz->base.SetColorAdjustment = ILayerContextRequestor_SetColorAdjustment;
	thiz->base.SetStereoDepth = ILayerContextRequestor_SetStereoDepth;
	thiz->base.SetFieldParity = ILayerContextRequestor_SetFieldParity;
	thiz->base.SetClipRegions = ILayerContextRequestor_SetClipRegions;
	thiz->base.CreateWindow = ILayerContextRequestor_CreateWindow;
	thiz->base.FindWindow = ILayerContextRequestor_FindWindow;
	thiz->base.FindWindowByResourceID = ILayerContextRequestor_FindWindowByResourceID;
}

/*********************************************************************************************************************/

static DFBResult
__CoreLayerContextDispatch__Dispatch( CoreLayerContext *obj,
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


	ILayerContextReal real;
	ILayerContext *super = (ILayerContext *)&real;
	ILayerContextRealInit(&real, core_dfb, obj);


    switch (method) {
        case CoreLayerContextCall_GetPrimaryRegion: {
    CoreLayerRegion *region = NULL;
            D_UNUSED
            CoreLayerContextGetPrimaryRegion       *args        = (CoreLayerContextGetPrimaryRegion *) ptr;
            CoreLayerContextGetPrimaryRegionReturn *return_args = (CoreLayerContextGetPrimaryRegionReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_GetPrimaryRegion\n" );

            return_args->result = super->GetPrimaryRegion( super, args->create, &region );
            if (return_args->result == DFB_OK) {
                CoreLayerRegion_Throw( region, caller, &return_args->region_id );
                return_args->region_ptr = (void*) region;
            }

            *ret_length = sizeof(CoreLayerContextGetPrimaryRegionReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_TestConfiguration: {
            D_UNUSED
            CoreLayerContextTestConfiguration       *args        = (CoreLayerContextTestConfiguration *) ptr;
            CoreLayerContextTestConfigurationReturn *return_args = (CoreLayerContextTestConfigurationReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_TestConfiguration\n" );

            return_args->result = super->TestConfiguration( super, &args->config, &return_args->failed );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextTestConfigurationReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_SetConfiguration: {
            D_UNUSED
            CoreLayerContextSetConfiguration       *args        = (CoreLayerContextSetConfiguration *) ptr;
            CoreLayerContextSetConfigurationReturn *return_args = (CoreLayerContextSetConfigurationReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_SetConfiguration\n" );

            return_args->result = super->SetConfiguration( super, &args->config );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextSetConfigurationReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_SetSrcColorKey: {
            D_UNUSED
            CoreLayerContextSetSrcColorKey       *args        = (CoreLayerContextSetSrcColorKey *) ptr;
            CoreLayerContextSetSrcColorKeyReturn *return_args = (CoreLayerContextSetSrcColorKeyReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_SetSrcColorKey\n" );

            return_args->result = super->SetSrcColorKey( super, &args->key );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextSetSrcColorKeyReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_SetDstColorKey: {
            D_UNUSED
            CoreLayerContextSetDstColorKey       *args        = (CoreLayerContextSetDstColorKey *) ptr;
            CoreLayerContextSetDstColorKeyReturn *return_args = (CoreLayerContextSetDstColorKeyReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_SetDstColorKey\n" );

            return_args->result = super->SetDstColorKey( super, &args->key );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextSetDstColorKeyReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_SetSourceRectangle: {
            D_UNUSED
            CoreLayerContextSetSourceRectangle       *args        = (CoreLayerContextSetSourceRectangle *) ptr;
            CoreLayerContextSetSourceRectangleReturn *return_args = (CoreLayerContextSetSourceRectangleReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_SetSourceRectangle\n" );

            return_args->result = super->SetSourceRectangle( super, &args->rectangle );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextSetSourceRectangleReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_SetScreenLocation: {
            D_UNUSED
            CoreLayerContextSetScreenLocation       *args        = (CoreLayerContextSetScreenLocation *) ptr;
            CoreLayerContextSetScreenLocationReturn *return_args = (CoreLayerContextSetScreenLocationReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_SetScreenLocation\n" );

            return_args->result = super->SetScreenLocation( super, &args->location );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextSetScreenLocationReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_SetScreenRectangle: {
            D_UNUSED
            CoreLayerContextSetScreenRectangle       *args        = (CoreLayerContextSetScreenRectangle *) ptr;
            CoreLayerContextSetScreenRectangleReturn *return_args = (CoreLayerContextSetScreenRectangleReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_SetScreenRectangle\n" );

            return_args->result = super->SetScreenRectangle( super, &args->rectangle );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextSetScreenRectangleReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_SetScreenPosition: {
            D_UNUSED
            CoreLayerContextSetScreenPosition       *args        = (CoreLayerContextSetScreenPosition *) ptr;
            CoreLayerContextSetScreenPositionReturn *return_args = (CoreLayerContextSetScreenPositionReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_SetScreenPosition\n" );

            return_args->result = super->SetScreenPosition( super, &args->position );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextSetScreenPositionReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_SetOpacity: {
            D_UNUSED
            CoreLayerContextSetOpacity       *args        = (CoreLayerContextSetOpacity *) ptr;
            CoreLayerContextSetOpacityReturn *return_args = (CoreLayerContextSetOpacityReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_SetOpacity\n" );

            return_args->result = super->SetOpacity( super, args->opacity );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextSetOpacityReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_SetRotation: {
            D_UNUSED
            CoreLayerContextSetRotation       *args        = (CoreLayerContextSetRotation *) ptr;
            CoreLayerContextSetRotationReturn *return_args = (CoreLayerContextSetRotationReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_SetRotation\n" );

            return_args->result = super->SetRotation( super, args->rotation );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextSetRotationReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_SetColorAdjustment: {
            D_UNUSED
            CoreLayerContextSetColorAdjustment       *args        = (CoreLayerContextSetColorAdjustment *) ptr;
            CoreLayerContextSetColorAdjustmentReturn *return_args = (CoreLayerContextSetColorAdjustmentReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_SetColorAdjustment\n" );

            return_args->result = super->SetColorAdjustment( super, &args->adjustment );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextSetColorAdjustmentReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_SetStereoDepth: {
            D_UNUSED
            CoreLayerContextSetStereoDepth       *args        = (CoreLayerContextSetStereoDepth *) ptr;
            CoreLayerContextSetStereoDepthReturn *return_args = (CoreLayerContextSetStereoDepthReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_SetStereoDepth\n" );

            return_args->result = super->SetStereoDepth( super, args->follow_video, args->z );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextSetStereoDepthReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_SetFieldParity: {
            D_UNUSED
            CoreLayerContextSetFieldParity       *args        = (CoreLayerContextSetFieldParity *) ptr;
            CoreLayerContextSetFieldParityReturn *return_args = (CoreLayerContextSetFieldParityReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_SetFieldParity\n" );

            return_args->result = super->SetFieldParity( super, args->field );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextSetFieldParityReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_SetClipRegions: {
            D_UNUSED
            CoreLayerContextSetClipRegions       *args        = (CoreLayerContextSetClipRegions *) ptr;
            CoreLayerContextSetClipRegionsReturn *return_args = (CoreLayerContextSetClipRegionsReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_SetClipRegions\n" );

            return_args->result = super->SetClipRegions( super, (DFBRegion*) ((char*)(args + 1)), args->num, args->positive );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreLayerContextSetClipRegionsReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_CreateWindow: {
    CoreWindow *window = NULL;
            D_UNUSED
            CoreLayerContextCreateWindow       *args        = (CoreLayerContextCreateWindow *) ptr;
            CoreLayerContextCreateWindowReturn *return_args = (CoreLayerContextCreateWindowReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_CreateWindow\n" );

            return_args->result = super->CreateWindow( super, &args->description, &window );
            if (return_args->result == DFB_OK) {
                CoreWindow_Throw( window, caller, &return_args->window_id );
                return_args->window_ptr = (void*) window;
            }

            *ret_length = sizeof(CoreLayerContextCreateWindowReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_FindWindow: {
    CoreWindow *window = NULL;
            D_UNUSED
            CoreLayerContextFindWindow       *args        = (CoreLayerContextFindWindow *) ptr;
            CoreLayerContextFindWindowReturn *return_args = (CoreLayerContextFindWindowReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_FindWindow\n" );

            return_args->result = super->FindWindow( super, args->window_id, &window );
            if (return_args->result == DFB_OK) {
                CoreWindow_Throw( window, caller, &return_args->window_id );
                return_args->window_ptr = (void*) window;
            }

            *ret_length = sizeof(CoreLayerContextFindWindowReturn);

            return DFB_OK;
        }

        case CoreLayerContextCall_FindWindowByResourceID: {
    CoreWindow *window = NULL;
            D_UNUSED
            CoreLayerContextFindWindowByResourceID       *args        = (CoreLayerContextFindWindowByResourceID *) ptr;
            CoreLayerContextFindWindowByResourceIDReturn *return_args = (CoreLayerContextFindWindowByResourceIDReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreLayerContext, "=-> CoreLayerContext_FindWindowByResourceID\n" );

            return_args->result = super->FindWindowByResourceID( super, args->resource_id, &window );
            if (return_args->result == DFB_OK) {
                CoreWindow_Throw( window, caller, &return_args->window_id );
                return_args->window_ptr = (void*) window;
            }

            *ret_length = sizeof(CoreLayerContextFindWindowByResourceIDReturn);

            return DFB_OK;
        }

    }

    return DFB_NOSUCHMETHOD;
}

/*********************************************************************************************************************/

DFBResult
CoreLayerContextDispatch__Dispatch( CoreLayerContext *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    DFBResult ret = DFB_OK;

    D_DEBUG_AT( DirectFB_CoreLayerContext, "CoreLayerContextDispatch::%s( %p )\n", __FUNCTION__, obj );

    Core_PushIdentity( caller );

    ret = __CoreLayerContextDispatch__Dispatch( obj, caller, method, ptr, length, ret_ptr, ret_size, ret_length );

    Core_PopIdentity();

    return ret;
}

