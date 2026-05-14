/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_NvM_Type.h                                               */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef RTE_NVM_TYPE_H
#define RTE_NVM_TYPE_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/* Identification of a NVRAM block via a unique block identifier. */
typedef uint16 NvM_BlockIdType;

/* Identifies the type of request performed on a block when signaled via      */
/* the callback function                                                      */
typedef uint8  NvM_BlockRequestType;
#define NVM_READ_BLOCK                  ( ( NvM_BlockRequestType )0x00U )
#define NVM_WRITE_BLOCK                 ( ( NvM_BlockRequestType )0x01U )
#define NVM_RESTORE_BLOCK_DEFAULTS      ( ( NvM_BlockRequestType )0x02U )
#define NVM_ERASE_NV_BLOCK              ( ( NvM_BlockRequestType )0x03U )
#define NVM_INVALIDATE_NV_BLOCK         ( ( NvM_BlockRequestType )0x04U )
#define NVM_READ_ALL_BLOCK              ( ( NvM_BlockRequestType )0x05U )

/* Identifies the type of initialization request performed on a block when    */
/* signaled via the callback function                                         */
typedef uint8  NvM_InitBlockRequestType;
#define NVM_INIT_READ_BLOCK             ( ( NvM_InitBlockRequestType )0x00U )
#define NVM_INIT_RESTORE_BLOCK_DEFAULTS ( ( NvM_InitBlockRequestType )0x01U )
#define NVM_INIT_READ_ALL_BLOCK         ( ( NvM_InitBlockRequestType )0x02U )
#define NVM_INIT_FIRST_INIT_ALL         ( ( NvM_InitBlockRequestType )0x03U )

/* This is an asynchronous request result returned by NvM_GetErrorStatus.     */
/* Availability can also be signaled via the callback function.               */
typedef uint8  NvM_RequestResultType;
#define NVM_REQ_OK                      ( ( NvM_RequestResultType )0x00U )
#define NVM_REQ_NOT_OK                  ( ( NvM_RequestResultType )0x01U )
#define NVM_REQ_PENDING                 ( ( NvM_RequestResultType )0x02U )
#define NVM_REQ_INTEGRITY_FAILED        ( ( NvM_RequestResultType )0x03U )
#define NVM_REQ_BLOCK_SKIPPED           ( ( NvM_RequestResultType )0x04U )
#define NVM_REQ_NV_INVALIDATED          ( ( NvM_RequestResultType )0x05U )
#define NVM_REQ_CANCELED                ( ( NvM_RequestResultType )0x06U )
#define NVM_REQ_RESTORED_DEFAULTS       ( ( NvM_RequestResultType )0x07U )

#endif /* RTE_NVM_TYPE_H */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/* EOF Rte_NvM_Type.h */
