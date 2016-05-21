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

#ifndef ___DataBuffer__H___
#define ___DataBuffer__H___

#include "DataBuffer_includes.h"

/**********************************************************************************************************************
 * DataBuffer
 */

DFBResult DataBuffer_Flush(
                    DataBuffer                                *obj
);

DFBResult DataBuffer_Finish(
                    DataBuffer                                *obj
);

DFBResult DataBuffer_SeekTo(
                    DataBuffer                                *obj,
                    u64                                        offset);

DFBResult DataBuffer_GetPosition(
                    DataBuffer                                *obj,
                    u64                                       *ret_offset);

DFBResult DataBuffer_GetLength(
                    DataBuffer                                *obj,
                    u64                                       *ret_length);

DFBResult DataBuffer_WaitForData(
                    DataBuffer                                *obj,
                    u64                                        length);

DFBResult DataBuffer_WaitForDataWithTimeout(
                    DataBuffer                                *obj,
                    u64                                        length,
                    u64                                        timeout_ms);

DFBResult DataBuffer_GetData(
                    DataBuffer                                *obj,
                    u32                                        length,
                    u8                                        *ret_data,
                    u32                                       *ret_read);

DFBResult DataBuffer_PeekData(
                    DataBuffer                                *obj,
                    u32                                        length,
                    s64                                        offset,
                    u8                                        *ret_data,
                    u32                                       *ret_read);

DFBResult DataBuffer_HasData(
                    DataBuffer                                *obj
);

DFBResult DataBuffer_PutData(
                    DataBuffer                                *obj,
                    const u8                                  *data,
                    u32                                        length);


void DataBuffer_Init_Dispatch(
                    CoreDFB              *core,
                    IDirectFBDataBuffer  *obj,
                    FusionCall           *call
);

void  DataBuffer_Deinit_Dispatch(
                    FusionCall           *call
);

/*
 * DataBuffer Calls
 */
typedef enum {
    DataBufferCall_Flush = 1,
    DataBufferCall_Finish = 2,
    DataBufferCall_SeekTo = 3,
    DataBufferCall_GetPosition = 4,
    DataBufferCall_GetLength = 5,
    DataBufferCall_WaitForData = 6,
    DataBufferCall_WaitForDataWithTimeout = 7,
    DataBufferCall_GetData = 8,
    DataBufferCall_PeekData = 9,
    DataBufferCall_HasData = 10,
    DataBufferCall_PutData = 11,
} DataBufferCall;

/*
 * DataBuffer_Flush
 */
typedef struct {
} DataBufferFlush;

typedef struct {
    DFBResult                                  result;
} DataBufferFlushReturn;


/*
 * DataBuffer_Finish
 */
typedef struct {
} DataBufferFinish;

typedef struct {
    DFBResult                                  result;
} DataBufferFinishReturn;


/*
 * DataBuffer_SeekTo
 */
typedef struct {
    u64                                        offset;
} DataBufferSeekTo;

typedef struct {
    DFBResult                                  result;
} DataBufferSeekToReturn;


/*
 * DataBuffer_GetPosition
 */
typedef struct {
} DataBufferGetPosition;

typedef struct {
    DFBResult                                  result;
    u64                                        offset;
} DataBufferGetPositionReturn;


/*
 * DataBuffer_GetLength
 */
typedef struct {
} DataBufferGetLength;

typedef struct {
    DFBResult                                  result;
    u64                                        length;
} DataBufferGetLengthReturn;


/*
 * DataBuffer_WaitForData
 */
typedef struct {
    u64                                        length;
} DataBufferWaitForData;

typedef struct {
    DFBResult                                  result;
} DataBufferWaitForDataReturn;


/*
 * DataBuffer_WaitForDataWithTimeout
 */
typedef struct {
    u64                                        length;
    u64                                        timeout_ms;
} DataBufferWaitForDataWithTimeout;

typedef struct {
    DFBResult                                  result;
} DataBufferWaitForDataWithTimeoutReturn;


/*
 * DataBuffer_GetData
 */
typedef struct {
    u32                                        length;
} DataBufferGetData;

typedef struct {
    DFBResult                                  result;
    u32                                        read;
    /* 'read' u8 follow (data) */
} DataBufferGetDataReturn;


/*
 * DataBuffer_PeekData
 */
typedef struct {
    u32                                        length;
    s64                                        offset;
} DataBufferPeekData;

typedef struct {
    DFBResult                                  result;
    u32                                        read;
    /* 'read' u8 follow (data) */
} DataBufferPeekDataReturn;


/*
 * DataBuffer_HasData
 */
typedef struct {
} DataBufferHasData;

typedef struct {
    DFBResult                                  result;
} DataBufferHasDataReturn;


/*
 * DataBuffer_PutData
 */
typedef struct {
    u32                                        length;
    /* 'length' u8 follow (data) */
} DataBufferPutData;

typedef struct {
    DFBResult                                  result;
} DataBufferPutDataReturn;


typedef struct _IDataBuffer IDataBuffer;
typedef struct _IDataBufferReal IDataBufferReal;
typedef struct _IDataBufferRequestor IDataBufferRequestor;


struct _IDataBuffer
{
	CoreDFB *core;

    DFBResult (*Flush)(IDataBuffer *thiz

    );

    DFBResult (*Finish)(IDataBuffer *thiz

    );

    DFBResult (*SeekTo)(IDataBuffer *thiz,
                    u64                                        offset
    );

    DFBResult (*GetPosition)(IDataBuffer *thiz,
                    u64                                       *ret_offset
    );

    DFBResult (*GetLength)(IDataBuffer *thiz,
                    u64                                       *ret_length
    );

    DFBResult (*WaitForData)(IDataBuffer *thiz,
                    u64                                        length
    );

    DFBResult (*WaitForDataWithTimeout)(IDataBuffer *thiz,
                    u64                                        length,
                    u64                                        timeout_ms
    );

    DFBResult (*GetData)(IDataBuffer *thiz,
                    u32                                        length,
                    u8                                        *ret_data,
                    u32                                       *ret_read
    );

    DFBResult (*PeekData)(IDataBuffer *thiz,
                    u32                                        length,
                    s64                                        offset,
                    u8                                        *ret_data,
                    u32                                       *ret_read
    );

    DFBResult (*HasData)(IDataBuffer *thiz

    );

    DFBResult (*PutData)(IDataBuffer *thiz,
                    const u8                                  *data,
                    u32                                        length
    );

};


struct _IDataBufferReal
{
	IDataBuffer base;

    IDirectFBDataBuffer *obj;

};

void IDataBufferRealInit(IDataBufferReal *thiz, CoreDFB *core, IDirectFBDataBuffer *obj);


struct _IDataBufferRequestor
{
	IDataBuffer base;

    DataBuffer *obj;
};

void IDataBufferRequestorInit(IDataBufferRequestor *thiz, CoreDFB *core, DataBuffer *obj);


DFBResult DataBufferDispatch__Dispatch( IDirectFBDataBuffer *obj,
                    FusionID      caller,
                    int           method,
                    void         *ptr,
                    unsigned int  length,
                    void         *ret_ptr,
                    unsigned int  ret_size,
                    unsigned int *ret_length );


#endif
