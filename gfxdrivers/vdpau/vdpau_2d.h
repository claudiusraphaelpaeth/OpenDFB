/*
   (c) Copyright 2001-2009  The world wide DirectFB Open Source Community (directfb.org)
   (c) Copyright 2000-2004  Convergence (integrated media) GmbH

   All rights reserved.

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

#ifndef __VDPAU_2D_H__
#define __VDPAU_2D_H__


#define VDPAU_SUPPORTED_DRAWINGFLAGS      (DSDRAW_BLEND              | \
                                           DSDRAW_SRC_PREMULTIPLY)

#define VDPAU_SUPPORTED_DRAWINGFUNCTIONS  (DFXL_FILLRECTANGLE)

#define VDPAU_SUPPORTED_BLITTINGFLAGS     (DSBLIT_BLEND_ALPHACHANNEL | \
                                           DSBLIT_BLEND_COLORALPHA   | \
                                           DSBLIT_COLORIZE           | \
                                           DSBLIT_SRC_PREMULTCOLOR)

#define VDPAU_SUPPORTED_BLITTINGFUNCTIONS (DFXL_BLIT | DFXL_STRETCHBLIT)


DFBResult vdpauEngineSync   ( void                *drv,
                              void                *dev );

void      vdpauEngineReset  ( void                *drv,
                              void                *dev );

void      vdpauEmitCommands ( void                *drv,
                              void                *dev );

void      vdpauCheckState   ( void                *drv,
                              void                *dev,
                              CardState           *state,
                              DFBAccelerationMask  accel );

void      vdpauSetState     ( void                *drv,
                              void                *dev,
                              GraphicsDeviceFuncs *funcs,
                              CardState           *state,
                              DFBAccelerationMask  accel );

bool      vdpauFillRectangle( void                *drv,
                              void                *dev,
                              DFBRectangle        *rect );

bool      vdpauBlit         ( void                *drv,
                              void                *dev,
                              DFBRectangle        *srect,
                              int                  dx,
                              int                  dy );

bool      vdpauStretchBlit  ( void                *drv,
                              void                *dev,
                              DFBRectangle        *srect,
                              DFBRectangle        *drect );

#endif

