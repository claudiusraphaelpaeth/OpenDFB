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

#include "SaWManManager.h"
#include "SaWManProcess.h"

#include <directfb_util.h>

#include <direct/debug.h>
#include <direct/mem.h>
#include <direct/memcpy.h>
#include <direct/messages.h>

#include <fusion/conf.h>

#include <core/core.h>


D_DEBUG_DOMAIN( DirectFB_SaWManProcess, "DirectFB/SaWManProcess", "DirectFB SaWManProcess" );

/*********************************************************************************************************************/

DFBResult
SaWManProcessReal_SetExiting(ISaWManProcess *thiz
)
{
     D_DEBUG_AT( DirectFB_SaWManProcess, "%s()\n", __FUNCTION__ );

     /* Set 'cleanly exiting' flag. */
     thiz->obj->flags = (SaWManProcessFlags)(thiz->obj->flags | SWMPF_EXITING);

     return DFB_OK;
}

DFBResult
SaWManProcessReal_RegisterManager(ISaWManProcess *thiz,
                    const SaWManRegisterManagerData           *data,
                    SaWManManager                            **ret_manager
)
{
     D_DEBUG_AT( DirectFB_SaWManProcess, "%s()\n", __FUNCTION__ );

     sawman_lock( m_sawman );

     if (m_sawman->manager.present) {
          sawman_unlock( m_sawman );
          return DFB_BUSY;
     }

     /* Initialize manager data. */
     m_sawman->manager.call      = data->call;
     m_sawman->manager.callbacks = data->callbacks;
     m_sawman->manager.context   = data->context;

     /* Set manager flag for our process. */
     thiz->obj->flags = (SaWManProcessFlags)(thiz->obj->flags | SWMPF_MANAGER);

     m_sawman->manager.present = true;

     SaWManManager_Init_Dispatch( thiz->core, &m_sawman->manager, &m_sawman->manager.call_from );

     sawman_unlock( m_sawman );


     *ret_manager = &m_sawman->manager;

     return DFB_OK;
}


void ISaWManProcessRealInit(ISaWManProcessReal *thiz, CoreDFB *core, SaWManProcess *obj)
{
	thiz->base.core = core;
	thiz->base.obj = obj;

	thiz->base.SetExiting = SaWManProcessReal_SetExiting;
	thiz->base.RegisterManager = SaWManProcessReal_RegisterManager;
}


