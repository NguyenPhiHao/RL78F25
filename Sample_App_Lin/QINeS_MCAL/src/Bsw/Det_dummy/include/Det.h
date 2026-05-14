/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Det.h                                                        */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/
#ifndef DET_H
#define DET_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Det_AR.h"
#include "Std_Types.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/* define const macro */
#define DET_Q_CONST const

/* [ECUC_Det_00002] (1) */
/* container of DetGeneral */
typedef struct {
    bool_t DetForwardToDlt;                     /* [ECUC_Det_00006] (0..1) */
    bool_t DetVersionInfoApi;                   /* [ECUC_Det_00003] (1)    */
} Det_GeneralType;

/* function definition of DetErrorHook */
typedef Std_ReturnType (*Det_ErrorHookType)( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );

#if ( DET_Q_DETNOTIFICATION_ENABLED != FALSE )
/* [ECUC_Det_00004] (0..1) */
/* container of DetNotification */
typedef struct {
    uint16 DetNumOfDetErrorHook;                  /* [QINeS_ECUC_Det_00001] (1) */
    DET_Q_CONST Det_ErrorHookType* DetErrorHook;  /* [ECUC_Det_00005] (0..*)    */
} Det_NotificationType;
#endif /* DET_Q_DETNOTIFICATION_ENABLED */

#if ( DET_Q_DETNOTIFICATION_ENABLED != FALSE )
/* configuration structure of Det module */
typedef struct {
    DET_Q_CONST Det_NotificationType* DetNotification;
} Det_Q_ConfigType;
#endif /* DET_Q_DETNOTIFICATION_ENABLED */

/* status of Det module */
typedef uint8 Det_DetStatusType;

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* ModuleID */
#define DET_MODULE_ID                       ( MODULE_ID_DET )

/* InstanceID */
#define DET_INSTANCE_ID                     ( 0U )

/* sw version definition */
#define DET_SW_MAJOR_VERSION                ( 1U )
#define DET_SW_MINOR_VERSION                ( 0U )
#define DET_SW_PATCH_VERSION                ( 0U )

/* ServiceID */
#define DET_INIT_ID                         ( 0x00U )
#define DET_REPORTERROR_ID                  ( 0x01U )
#define DET_START_ID                        ( 0x02U )
#define DET_GETVERSIONINFO_ID               ( 0x03U )
#define DET_CHECKCONFIG_ID                  ( 0xa0U )

/* Error classification */
#define DET_E_PARAM_POINTER                 ( 0x01U )

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
void Det_Init( void );
Std_ReturnType Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );
void Det_Start( void );
Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );

#endif /* DET_H */

/* EOF Det.h *****************************************************************/
