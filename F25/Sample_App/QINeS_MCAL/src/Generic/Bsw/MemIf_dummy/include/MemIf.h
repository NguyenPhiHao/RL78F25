/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */   
/* File Name   : MemIf.h                                                      */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/
#ifndef MEMIF_H
#define MEMIF_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "MemIf_AR.h"
#include "Std_Types.h"
#include "MemIf_Cfg.h"
#if ( MEMIF_Q_FEE_EXIST != FALSE )
#include "Fee.h"
#endif /* ( MEMIF_Q_FEE_EXIST != FALSE ) */

#if ( MEMIF_Q_EA_EXIST != FALSE )
#include "Ea.h"
#endif /* ( MEMIF_Q_EA_EXIST != FALSE ) */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
#define MEMIF_Q_CONST     const
#define MEMIF_Q_STATIC    static

/* [ECUC_MemIf_00034] MemIfGeneral */
typedef struct {
    bool_t  MemIfDevErrorDetect;           /* [ECUC_MemIf_00035] (1)          */
    uint8   MemIfNumberOfDevices;          /* [ECUC_MemIf_00033] (1) (1..255) */
    bool_t  MemIfVersionInfoApi;           /* [ECUC_MemIf_00032] (1)          */
} MemIf_GeneralType;

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* sw version definition */
#define MEMIF_SW_MAJOR_VERSION          ( 1U )
#define MEMIF_SW_MINOR_VERSION          ( 0U )
#define MEMIF_SW_PATCH_VERSION          ( 0U )

/* ServiceID */
#define MEMIF_SETMODE_ID                (0x01U)
#define MEMIF_READ_ID                   (0x02U)
#define MEMIF_WRITE_ID                  (0x03U)
#define MEMIF_CANCEL_ID                 (0x04U)
#define MEMIF_GETSTATUS_ID              (0x05U)
#define MEMIF_GETJOBRESULT_ID           (0x06U)
#define MEMIF_INVALIDATEBLOCK_ID        (0x07U)
#define MEMIF_GETVERSIONINFO_ID         (0x08U)
#define MEMIF_ERASEIMMEDIATEBLOCK_ID    (0x09U)

/* Error classification */
#define MEMIF_E_PARAM_DEVICE            (0x01U)
#define MEMIF_E_PARAM_POINTER           (0x02U)
#define MEMIF_E_PARAM_MODE              (0xFFU)

/* DeviceIndex */
#if ( MEMIF_Q_FEE_EXIST == FALSE ) && ( MEMIF_Q_EA_EXIST == FALSE )
#error CONFIGURATION ERROR
#endif /* ( MEMIF_Q_FEE_EXIST == FALSE ) && ( MEMIF_Q_EA_EXIST == FALSE ) */

#if ( MEMIF_Q_FEE_EXIST == FALSE )  /* Ea only */
#define MEMIF_Q_EA_ID                   (0x00U)
#elif ( MEMIF_Q_EA_EXIST == FALSE ) /* Fee only */
#define MEMIF_Q_FEE_ID                  (0x00U)
#else                               
/* Both Fee and Ea */
#define MEMIF_Q_FEE_ID                  (0x00U)
#define MEMIF_Q_EA_ID                   (0x01U)
#endif /* MEMIF_Q_FEE_EXIST, MEMIF_Q_EA_EXIST */
#define MEMIF_BROADCAST_ID              (0xffU)

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
void MemIf_SetMode( MemIf_ModeType Mode );
Std_ReturnType MemIf_Read( uint8 DeviceIndex, uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length );
Std_ReturnType MemIf_Write( uint8 DeviceIndex, uint16 BlockNumber, MEMIF_Q_CONST uint8* DataBufferPtr );
void MemIf_Cancel( uint8 DeviceIndex );
MemIf_StatusType MemIf_GetStatus( uint8 DeviceIndex );
MemIf_JobResultType MemIf_GetJobResult( uint8 DeviceIndex );
Std_ReturnType MemIf_InvalidateBlock( uint8 DeviceIndex, uint16 BlockNumber );
void MemIf_GetVersionInfo( Std_VersionInfoType* VersionInfoPtr );
Std_ReturnType MemIf_EraseImmediateBlock( uint8 DeviceIndex, uint16 BlockNumber );

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

#endif /* MEMIF_H */

/* EOF MemIf.h ****************************************************************/
