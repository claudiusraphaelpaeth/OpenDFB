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

#include "CoreScreen.h"

#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <fusion/conf.h>
#include <core/core.h>
#include <core/CoreDFB_CallMode.h>

D_DEBUG_DOMAIN( DirectFB_CoreScreen, "DirectFB/CoreScreen", "DirectFB CoreScreen" );

/*********************************************************************************************************************/

DFBResult
CoreScreen_SetPowerMode(
                    CoreScreen                                *obj,
                    DFBScreenPowerMode                         mode
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IScreenReal real;
			IScreen *super = (IScreen *)&real;
			IScreenRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetPowerMode( super, mode );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IScreenRequestor requestor;
			IScreen *super = (IScreen *)&requestor;
			IScreenRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetPowerMode( super, mode );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreScreen_WaitVSync(
                    CoreScreen                                *obj

)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IScreenReal real;
			IScreen *super = (IScreen *)&real;
			IScreenRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->WaitVSync( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IScreenRequestor requestor;
			IScreen *super = (IScreen *)&requestor;
			IScreenRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->WaitVSync( super );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreScreen_GetVSyncCount(
                    CoreScreen                                *obj,
                    u64                                       *ret_count
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IScreenReal real;
			IScreen *super = (IScreen *)&real;
			IScreenRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetVSyncCount( super, ret_count );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IScreenRequestor requestor;
			IScreen *super = (IScreen *)&requestor;
			IScreenRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetVSyncCount( super, ret_count );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreScreen_TestMixerConfig(
                    CoreScreen                                *obj,
                    u32                                        mixer,
                    const DFBScreenMixerConfig                *config,
                    DFBScreenMixerConfigFlags                 *ret_failed
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IScreenReal real;
			IScreen *super = (IScreen *)&real;
			IScreenRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->TestMixerConfig( super, mixer, config, ret_failed );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IScreenRequestor requestor;
			IScreen *super = (IScreen *)&requestor;
			IScreenRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->TestMixerConfig( super, mixer, config, ret_failed );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreScreen_SetMixerConfig(
                    CoreScreen                                *obj,
                    u32                                        mixer,
                    const DFBScreenMixerConfig                *config
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IScreenReal real;
			IScreen *super = (IScreen *)&real;
			IScreenRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetMixerConfig( super, mixer, config );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IScreenRequestor requestor;
			IScreen *super = (IScreen *)&requestor;
			IScreenRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetMixerConfig( super, mixer, config );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreScreen_TestEncoderConfig(
                    CoreScreen                                *obj,
                    u32                                        encoder,
                    const DFBScreenEncoderConfig              *config,
                    DFBScreenEncoderConfigFlags               *ret_failed
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IScreenReal real;
			IScreen *super = (IScreen *)&real;
			IScreenRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->TestEncoderConfig( super, encoder, config, ret_failed );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IScreenRequestor requestor;
			IScreen *super = (IScreen *)&requestor;
			IScreenRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->TestEncoderConfig( super, encoder, config, ret_failed );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreScreen_SetEncoderConfig(
                    CoreScreen                                *obj,
                    u32                                        encoder,
                    const DFBScreenEncoderConfig              *config
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IScreenReal real;
			IScreen *super = (IScreen *)&real;
			IScreenRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetEncoderConfig( super, encoder, config );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IScreenRequestor requestor;
			IScreen *super = (IScreen *)&requestor;
			IScreenRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetEncoderConfig( super, encoder, config );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreScreen_TestOutputConfig(
                    CoreScreen                                *obj,
                    u32                                        output,
                    const DFBScreenOutputConfig               *config,
                    DFBScreenOutputConfigFlags                *ret_failed
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IScreenReal real;
			IScreen *super = (IScreen *)&real;
			IScreenRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->TestOutputConfig( super, output, config, ret_failed );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IScreenRequestor requestor;
			IScreen *super = (IScreen *)&requestor;
			IScreenRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->TestOutputConfig( super, output, config, ret_failed );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreScreen_SetOutputConfig(
                    CoreScreen                                *obj,
                    u32                                        output,
                    const DFBScreenOutputConfig               *config
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IScreenReal real;
			IScreen *super = (IScreen *)&real;
			IScreenRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetOutputConfig( super, output, config );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IScreenRequestor requestor;
			IScreen *super = (IScreen *)&requestor;
			IScreenRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->SetOutputConfig( super, output, config );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreScreen_GetScreenSize(
                    CoreScreen                                *obj,
                    DFBDimension                              *ret_size
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IScreenReal real;
			IScreen *super = (IScreen *)&real;
			IScreenRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetScreenSize( super, ret_size );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IScreenRequestor requestor;
			IScreen *super = (IScreen *)&requestor;
			IScreenRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetScreenSize( super, ret_size );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_DENY:
            return DFB_DEAD;
    }

    return DFB_UNIMPLEMENTED;
}

DFBResult
CoreScreen_GetLayerDimension(
                    CoreScreen                                *obj,
                    CoreLayer                                 *layer,
                    DFBDimension                              *ret_size
)
{
    DFBResult ret;

    switch (CoreDFB_CallMode( core_dfb )) {
        case COREDFB_CALL_DIRECT:{
			IScreenReal real;
			IScreen *super = (IScreen *)&real;
			IScreenRealInit( &real, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetLayerDimension( super, layer, ret_size );
            Core_PopCalling();

            return ret;
        }
        case COREDFB_CALL_INDIRECT: {
			IScreenRequestor requestor;
			IScreen *super = (IScreen *)&requestor;
			IScreenRequestorInit( &requestor, core_dfb, obj );

            Core_PushCalling();
            ret = super->GetLayerDimension( super, layer, ret_size );
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
CoreScreen_Dispatch( int           caller,   /* fusion id of the caller */
                     int           call_arg, /* optional call parameter */
                     void         *ptr, /* optional call parameter */
                     unsigned int  length,
                     void         *ctx,      /* optional handler context */
                     unsigned int  serial,
                     void         *ret_ptr,
                     unsigned int  ret_size,
                     unsigned int *ret_length )
{
    CoreScreen *obj = (CoreScreen*) ctx;
    CoreScreenDispatch__Dispatch( obj, caller, call_arg, ptr, length, ret_ptr, ret_size, ret_length );

    return FCHR_RETURN;
}

void CoreScreen_Init_Dispatch(
                    CoreDFB              *core,
                    CoreScreen           *obj,
                    FusionCall           *call
)
{
    fusion_call_init3( call, CoreScreen_Dispatch, obj, core->world );
}

void  CoreScreen_Deinit_Dispatch(
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
IScreenRequestor_SetPowerMode(IScreen *thiz,
                    DFBScreenPowerMode                         mode
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreScreenSetPowerMode       *args = (CoreScreenSetPowerMode*) args_alloc( args_static, sizeof(CoreScreenSetPowerMode) );
    CoreScreenSetPowerModeReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreScreenSetPowerModeReturn*) args_alloc( return_args_static, sizeof(CoreScreenSetPowerModeReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreScreen, "IScreenRequestor_%s()\n", __FUNCTION__ );


    args->mode = mode;

    ret = (DFBResult) CoreScreen_Call( thiz->obj, FCEF_NONE, CoreScreenCall_SetPowerMode, args, sizeof(CoreScreenSetPowerMode), return_args, sizeof(CoreScreenSetPowerModeReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreScreen_Call( CoreScreenCall_SetPowerMode ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreScreenCall_SetPowerMode failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IScreenRequestor_WaitVSync(IScreen *thiz

)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreScreenWaitVSync       *args = (CoreScreenWaitVSync*) args_alloc( args_static, sizeof(CoreScreenWaitVSync) );
    CoreScreenWaitVSyncReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreScreenWaitVSyncReturn*) args_alloc( return_args_static, sizeof(CoreScreenWaitVSyncReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreScreen, "IScreenRequestor_%s()\n", __FUNCTION__ );



    ret = (DFBResult) CoreScreen_Call( thiz->obj, FCEF_NONE, CoreScreenCall_WaitVSync, args, sizeof(CoreScreenWaitVSync), return_args, sizeof(CoreScreenWaitVSyncReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreScreen_Call( CoreScreen_WaitVSync ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreScreen_WaitVSync failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IScreenRequestor_GetVSyncCount(IScreen *thiz,
                    u64                                       *ret_count
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreScreenGetVSyncCount       *args = (CoreScreenGetVSyncCount*) args_alloc( args_static, sizeof(CoreScreenGetVSyncCount) );
    CoreScreenGetVSyncCountReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreScreenGetVSyncCountReturn*) args_alloc( return_args_static, sizeof(CoreScreenGetVSyncCountReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreScreen, "IScreenRequestor_%s()\n", __FUNCTION__ );



    ret = (DFBResult) CoreScreen_Call( thiz->obj, FCEF_NONE, CoreScreenCall_GetVSyncCount, args, sizeof(CoreScreenGetVSyncCount), return_args, sizeof(CoreScreenGetVSyncCountReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreScreen_Call( CoreScreen_GetVSyncCount ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreScreen_GetVSyncCount failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_count = return_args->count;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IScreenRequestor_TestMixerConfig(IScreen *thiz,
                    u32                                        mixer,
                    const DFBScreenMixerConfig                *config,
                    DFBScreenMixerConfigFlags                 *ret_failed
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreScreenTestMixerConfig       *args = (CoreScreenTestMixerConfig*) args_alloc( args_static, sizeof(CoreScreenTestMixerConfig) );
    CoreScreenTestMixerConfigReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreScreenTestMixerConfigReturn*) args_alloc( return_args_static, sizeof(CoreScreenTestMixerConfigReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreScreen, "IScreenRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    args->mixer = mixer;
    args->config = *config;

    ret = (DFBResult) CoreScreen_Call( thiz->obj, FCEF_NONE, CoreScreenCall_TestMixerConfig, args, sizeof(CoreScreenTestMixerConfig), return_args, sizeof(CoreScreenTestMixerConfigReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreScreen_Call( CoreScreen_TestMixerConfig ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreScreen_TestMixerConfig failed!\n", __FUNCTION__ );*/
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
IScreenRequestor_SetMixerConfig(IScreen *thiz,
                    u32                                        mixer,
                    const DFBScreenMixerConfig                *config
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreScreenSetMixerConfig       *args = (CoreScreenSetMixerConfig*) args_alloc( args_static, sizeof(CoreScreenSetMixerConfig) );
    CoreScreenSetMixerConfigReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreScreenSetMixerConfigReturn*) args_alloc( return_args_static, sizeof(CoreScreenSetMixerConfigReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreScreen, "IScreenRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    args->mixer = mixer;
    args->config = *config;

    ret = (DFBResult) CoreScreen_Call( thiz->obj, FCEF_NONE, CoreScreenCall_SetMixerConfig, args, sizeof(CoreScreenSetMixerConfig), return_args, sizeof(CoreScreenSetMixerConfigReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreScreen_Call( CoreScreen_SetMixerConfig ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreScreen_SetMixerConfig failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IScreenRequestor_TestEncoderConfig(IScreen *thiz,
                    u32                                        encoder,
                    const DFBScreenEncoderConfig              *config,
                    DFBScreenEncoderConfigFlags               *ret_failed
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreScreenTestEncoderConfig       *args = (CoreScreenTestEncoderConfig*) args_alloc( args_static, sizeof(CoreScreenTestEncoderConfig) );
    CoreScreenTestEncoderConfigReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreScreenTestEncoderConfigReturn*) args_alloc( return_args_static, sizeof(CoreScreenTestEncoderConfigReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreScreen, "IScreenRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    args->encoder = encoder;
    args->config = *config;

    ret = (DFBResult) CoreScreen_Call( thiz->obj, FCEF_NONE, CoreScreenCall_TestEncoderConfig, args, sizeof(CoreScreenTestEncoderConfig), return_args, sizeof(CoreScreenTestEncoderConfigReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreScreen_Call( CoreScreen_TestEncoderConfig ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreScreen_TestEncoderConfig failed!\n", __FUNCTION__ );*/
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
IScreenRequestor_SetEncoderConfig(IScreen *thiz,
                    u32                                        encoder,
                    const DFBScreenEncoderConfig              *config
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreScreenSetEncoderConfig       *args = (CoreScreenSetEncoderConfig*) args_alloc( args_static, sizeof(CoreScreenSetEncoderConfig) );
    CoreScreenSetEncoderConfigReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreScreenSetEncoderConfigReturn*) args_alloc( return_args_static, sizeof(CoreScreenSetEncoderConfigReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreScreen, "IScreenRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    args->encoder = encoder;
    args->config = *config;

    ret = (DFBResult) CoreScreen_Call( thiz->obj, FCEF_NONE, CoreScreenCall_SetEncoderConfig, args, sizeof(CoreScreenSetEncoderConfig), return_args, sizeof(CoreScreenSetEncoderConfigReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreScreen_Call( CoreScreen_SetEncoderConfig ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreScreen_SetEncoderConfig failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IScreenRequestor_TestOutputConfig(IScreen *thiz,
                    u32                                        output,
                    const DFBScreenOutputConfig               *config,
                    DFBScreenOutputConfigFlags                *ret_failed
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreScreenTestOutputConfig       *args = (CoreScreenTestOutputConfig*) args_alloc( args_static, sizeof(CoreScreenTestOutputConfig) );
    CoreScreenTestOutputConfigReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreScreenTestOutputConfigReturn*) args_alloc( return_args_static, sizeof(CoreScreenTestOutputConfigReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreScreen, "IScreenRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    args->output = output;
    args->config = *config;

    ret = (DFBResult) CoreScreen_Call( thiz->obj, FCEF_NONE, CoreScreenCall_TestOutputConfig, args, sizeof(CoreScreenTestOutputConfig), return_args, sizeof(CoreScreenTestOutputConfigReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreScreen_Call( CoreScreen_TestOutputConfig ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreScreen_TestOutputConfig failed!\n", __FUNCTION__ );*/
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
IScreenRequestor_SetOutputConfig(IScreen *thiz,
                    u32                                        output,
                    const DFBScreenOutputConfig               *config
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreScreenSetOutputConfig       *args = (CoreScreenSetOutputConfig*) args_alloc( args_static, sizeof(CoreScreenSetOutputConfig) );
    CoreScreenSetOutputConfigReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreScreenSetOutputConfigReturn*) args_alloc( return_args_static, sizeof(CoreScreenSetOutputConfigReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreScreen, "IScreenRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( config != NULL );

    args->output = output;
    args->config = *config;

    ret = (DFBResult) CoreScreen_Call( thiz->obj, FCEF_NONE, CoreScreenCall_SetOutputConfig, args, sizeof(CoreScreenSetOutputConfig), return_args, sizeof(CoreScreenSetOutputConfigReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreScreen_Call( CoreScreen_SetOutputConfig ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreScreen_SetOutputConfig failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }



out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IScreenRequestor_GetScreenSize(IScreen *thiz,
                    DFBDimension                              *ret_size
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreScreenGetScreenSize       *args = (CoreScreenGetScreenSize*) args_alloc( args_static, sizeof(CoreScreenGetScreenSize) );
    CoreScreenGetScreenSizeReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreScreenGetScreenSizeReturn*) args_alloc( return_args_static, sizeof(CoreScreenGetScreenSizeReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreScreen, "IScreenRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( ret_size != NULL );


    ret = (DFBResult) CoreScreen_Call( thiz->obj, FCEF_NONE, CoreScreenCall_GetScreenSize, args, sizeof(CoreScreenGetScreenSize), return_args, sizeof(CoreScreenGetScreenSizeReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreScreen_Call( CoreScreen_GetScreenSize ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreScreen_GetScreenSize failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_size = return_args->size;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}


DFBResult
IScreenRequestor_GetLayerDimension(IScreen *thiz,
                    CoreLayer                                 *layer,
                    DFBDimension                              *ret_size
)
{
    DFBResult           ret = DFB_OK;
    char        args_static[FLUXED_ARGS_BYTES];
    char        return_args_static[FLUXED_ARGS_BYTES];
    CoreScreenGetLayerDimension       *args = (CoreScreenGetLayerDimension*) args_alloc( args_static, sizeof(CoreScreenGetLayerDimension) );
    CoreScreenGetLayerDimensionReturn *return_args;

    if (!args)
        return (DFBResult) D_OOM();

    return_args = (CoreScreenGetLayerDimensionReturn*) args_alloc( return_args_static, sizeof(CoreScreenGetLayerDimensionReturn) );

    if (!return_args) {
        args_free( args_static, args );
        return (DFBResult) D_OOM();
    }

    D_DEBUG_AT( DirectFB_CoreScreen, "IScreenRequestor_%s()\n", __FUNCTION__ );

    D_ASSERT( layer != NULL );
    D_ASSERT( ret_size != NULL );

    args->layer_id = CoreLayer_GetID( layer );

    ret = (DFBResult) CoreScreen_Call( thiz->obj, FCEF_NONE, CoreScreenCall_GetLayerDimension, args, sizeof(CoreScreenGetLayerDimension), return_args, sizeof(CoreScreenGetLayerDimensionReturn), NULL );
    if (ret) {
        D_DERROR( ret, "%s: CoreScreen_Call( CoreScreen_GetLayerDimension ) failed!\n", __FUNCTION__ );
        goto out;
    }

    if (return_args->result) {
        /*D_DERROR( return_args->result, "%s: CoreScreen_GetLayerDimension failed!\n", __FUNCTION__ );*/
        ret = return_args->result;
        goto out;
    }

    *ret_size = return_args->size;


out:
    args_free( return_args_static, return_args );
    args_free( args_static, args );
    return ret;
}

void IScreenRequestorInit(IScreenRequestor *thiz, CoreDFB *core, CoreScreen *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

	thiz->base.SetPowerMode = IScreenRequestor_SetPowerMode;
	thiz->base.WaitVSync = IScreenRequestor_WaitVSync;
	thiz->base.GetVSyncCount = IScreenRequestor_GetVSyncCount;
	thiz->base.TestMixerConfig = IScreenRequestor_TestMixerConfig;
	thiz->base.SetMixerConfig = IScreenRequestor_SetMixerConfig;
	thiz->base.TestEncoderConfig = IScreenRequestor_TestEncoderConfig;
	thiz->base.SetEncoderConfig = IScreenRequestor_SetEncoderConfig;
	thiz->base.TestOutputConfig = IScreenRequestor_TestOutputConfig;
	thiz->base.SetOutputConfig = IScreenRequestor_SetOutputConfig;
	thiz->base.GetScreenSize = IScreenRequestor_GetScreenSize;
	thiz->base.GetLayerDimension = IScreenRequestor_GetLayerDimension;
}

/*********************************************************************************************************************/

static DFBResult
__CoreScreenDispatch__Dispatch( CoreScreen *obj,
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

	IScreenReal real;
	IScreen *super = (IScreen *)&real;
	IScreenRealInit( &real, core_dfb, obj );

    switch (method) {
        case CoreScreenCall_SetPowerMode: {
            D_UNUSED
            CoreScreenSetPowerMode       *args        = (CoreScreenSetPowerMode *) ptr;
            CoreScreenSetPowerModeReturn *return_args = (CoreScreenSetPowerModeReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreScreen, "=-> CoreScreenCall_SetPowerMode\n" );

            return_args->result = super->SetPowerMode( super, args->mode );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreScreenSetPowerModeReturn);

            return DFB_OK;
        }

        case CoreScreenCall_WaitVSync: {
            D_UNUSED
            CoreScreenWaitVSync       *args        = (CoreScreenWaitVSync *) ptr;
            CoreScreenWaitVSyncReturn *return_args = (CoreScreenWaitVSyncReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreScreen, "=-> CoreScreenCall_WaitVSync\n" );

            return_args->result = super->WaitVSync( super );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreScreenWaitVSyncReturn);

            return DFB_OK;
        }

        case CoreScreenCall_GetVSyncCount: {
            D_UNUSED
            CoreScreenGetVSyncCount       *args        = (CoreScreenGetVSyncCount *) ptr;
            CoreScreenGetVSyncCountReturn *return_args = (CoreScreenGetVSyncCountReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreScreen, "=-> CoreScreenCall_GetVSyncCount\n" );

            return_args->result = super->GetVSyncCount( super, &return_args->count );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreScreenGetVSyncCountReturn);

            return DFB_OK;
        }

        case CoreScreenCall_TestMixerConfig: {
            D_UNUSED
            CoreScreenTestMixerConfig       *args        = (CoreScreenTestMixerConfig *) ptr;
            CoreScreenTestMixerConfigReturn *return_args = (CoreScreenTestMixerConfigReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreScreen, "=-> CoreScreenCall_TestMixerConfig\n" );

            return_args->result = super->TestMixerConfig( super, args->mixer, &args->config, &return_args->failed );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreScreenTestMixerConfigReturn);

            return DFB_OK;
        }

        case CoreScreenCall_SetMixerConfig: {
            D_UNUSED
            CoreScreenSetMixerConfig       *args        = (CoreScreenSetMixerConfig *) ptr;
            CoreScreenSetMixerConfigReturn *return_args = (CoreScreenSetMixerConfigReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreScreen, "=-> CoreScreenCall_SetMixerConfig\n" );

            return_args->result = super->SetMixerConfig( super, args->mixer, &args->config );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreScreenSetMixerConfigReturn);

            return DFB_OK;
        }

        case CoreScreenCall_TestEncoderConfig: {
            D_UNUSED
            CoreScreenTestEncoderConfig       *args        = (CoreScreenTestEncoderConfig *) ptr;
            CoreScreenTestEncoderConfigReturn *return_args = (CoreScreenTestEncoderConfigReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreScreen, "=-> CoreScreenCall_TestEncoderConfig\n" );

            return_args->result = super->TestEncoderConfig( super, args->encoder, &args->config, &return_args->failed );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreScreenTestEncoderConfigReturn);

            return DFB_OK;
        }

        case CoreScreenCall_SetEncoderConfig: {
            D_UNUSED
            CoreScreenSetEncoderConfig       *args        = (CoreScreenSetEncoderConfig *) ptr;
            CoreScreenSetEncoderConfigReturn *return_args = (CoreScreenSetEncoderConfigReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreScreen, "=-> CoreScreenCall_SetEncoderConfig\n" );

            return_args->result = super->SetEncoderConfig( super, args->encoder, &args->config );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreScreenSetEncoderConfigReturn);

            return DFB_OK;
        }

        case CoreScreenCall_TestOutputConfig: {
            D_UNUSED
            CoreScreenTestOutputConfig       *args        = (CoreScreenTestOutputConfig *) ptr;
            CoreScreenTestOutputConfigReturn *return_args = (CoreScreenTestOutputConfigReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreScreen, "=-> CoreScreenCall_TestOutputConfig\n" );

            return_args->result = super->TestOutputConfig( super, args->output, &args->config, &return_args->failed );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreScreenTestOutputConfigReturn);

            return DFB_OK;
        }

        case CoreScreenCall_SetOutputConfig: {
            D_UNUSED
            CoreScreenSetOutputConfig       *args        = (CoreScreenSetOutputConfig *) ptr;
            CoreScreenSetOutputConfigReturn *return_args = (CoreScreenSetOutputConfigReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreScreen, "=-> CoreScreenCall_SetOutputConfig\n" );

            return_args->result = super->SetOutputConfig( super, args->output, &args->config );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreScreenSetOutputConfigReturn);

            return DFB_OK;
        }

        case CoreScreenCall_GetScreenSize: {
            D_UNUSED
            CoreScreenGetScreenSize       *args        = (CoreScreenGetScreenSize *) ptr;
            CoreScreenGetScreenSizeReturn *return_args = (CoreScreenGetScreenSizeReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreScreen, "=-> CoreScreenCall_GetScreenSize\n" );

            return_args->result = super->GetScreenSize( super, &return_args->size );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreScreenGetScreenSizeReturn);

            return DFB_OK;
        }

        case CoreScreenCall_GetLayerDimension: {
    CoreLayer *layer = NULL;
            D_UNUSED
            CoreScreenGetLayerDimension       *args        = (CoreScreenGetLayerDimension *) ptr;
            CoreScreenGetLayerDimensionReturn *return_args = (CoreScreenGetLayerDimensionReturn *) ret_ptr;

            D_DEBUG_AT( DirectFB_CoreScreen, "=-> CoreScreenCall_GetLayerDimension\n" );

            ret = (DFBResult) CoreLayer_Lookup( core_dfb, args->layer_id, caller, &layer );
            if (ret) {
                 D_DERROR( ret, "%s: Looking up layer by ID %u failed!\n", __FUNCTION__, args->layer_id );
                 return_args->result = ret;
                 return ret;
            }

            return_args->result = super->GetLayerDimension( super, layer, &return_args->size );
            if (return_args->result == DFB_OK) {
            }

            *ret_length = sizeof(CoreScreenGetLayerDimensionReturn);

            if (layer)
                CoreLayer_Unref( layer );

            return DFB_OK;
        }

    }

    return DFB_NOSUCHMETHOD;
}
/*********************************************************************************************************************/

DFBResult
CoreScreenDispatch__Dispatch( CoreScreen *obj,
                                FusionID      caller,
                                int           method,
                                void         *ptr,
                                unsigned int  length,
                                void         *ret_ptr,
                                unsigned int  ret_size,
                                unsigned int *ret_length )
{
    DFBResult ret = DFB_OK;

    D_DEBUG_AT( DirectFB_CoreScreen, "CoreScreenDispatch::%s( %p )\n", __FUNCTION__, obj );

    Core_PushIdentity( caller );

    ret = __CoreScreenDispatch__Dispatch( obj, caller, method, ptr, length, ret_ptr, ret_size, ret_length );

    Core_PopIdentity();

    return ret;
}

