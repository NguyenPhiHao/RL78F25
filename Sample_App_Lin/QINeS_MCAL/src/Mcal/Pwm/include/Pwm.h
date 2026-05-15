/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Pwm.h                                                        */
/* Version     : v1.00.01                                                     */
/* Contents    : PWM Module header                                            */
/*               The PWM is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of PWM Driver                                                */
/* R22-11                                                                     */
#ifndef PWM_H
#define PWM_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Pwm_70_Types.h"
#include "Pwm_70_HW.h"

/*----------------------------------------------------------------------------*/
/* Source File Version Information                                            */
/*----------------------------------------------------------------------------*/
#define PWM_VENDOR_ID                       (70U)
#define PWM_MODULE_ID                       (121U)

#define PWM_AR_RELEASE_MAJOR_VERSION        (22U)
#define PWM_AR_RELEASE_MINOR_VERSION        (11U)
#define PWM_AR_RELEASE_REVISION_VERSION     (00U)

#define PWM_SW_MAJOR_VERSION                (1U)
#define PWM_SW_MINOR_VERSION                (0U)
#define PWM_SW_PATCH_VERSION                (0U)

/*----------------------------------------------------------------------------*/
/* File version check                                                         */
/*----------------------------------------------------------------------------*/
/* Pwm_70_Types.h version check start */
#if ( PWM_VENDOR_ID != PWM_70_VENDOR_ID_TYPES_H )
  #error "VENDOR ID for Pwm.h and Pwm_70_Types.h is different"
#endif

#if ( PWM_MODULE_ID != PWM_70_MODULE_ID_TYPES_H )
  #error "MODULE ID for Pwm.h and Pwm_70_Types.h is different"
#endif

#if ( ( PWM_AR_RELEASE_MAJOR_VERSION    != PWM_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( PWM_AR_RELEASE_MINOR_VERSION    != PWM_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( PWM_AR_RELEASE_REVISION_VERSION != PWM_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) )
  #error "AUTOSAR Version Numbers of Pwm.h and Pwm_70_Types.h are different"
#endif

#if ( ( PWM_SW_MAJOR_VERSION != PWM_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( PWM_SW_MINOR_VERSION != PWM_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( PWM_SW_PATCH_VERSION != PWM_70_SW_PATCH_VERSION_TYPES_H ) )
  #error "Software Version Numbers of Pwm.h and Pwm_70_Types.h are different"
#endif
/* Pwm_70_Types.h version check end */

/* Pwm_Cfg.h version check start */
#if ( PWM_VENDOR_ID != PWM_70_VENDOR_ID_CFG_H )
  #error "VENDOR ID for Pwm.h and Pwm_Cfg.h is different"
#endif

#if ( PWM_MODULE_ID != PWM_70_MODULE_ID_CFG_H )
  #error "MODULE ID for Pwm.h and Pwm_Cfg.h is different"
#endif

#if ( ( PWM_AR_RELEASE_MAJOR_VERSION    != PWM_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( PWM_AR_RELEASE_MINOR_VERSION    != PWM_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( PWM_AR_RELEASE_REVISION_VERSION != PWM_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
  #error "AUTOSAR Version Numbers of Pwm.h and Pwm_Cfg.h are different"
#endif

#if ( ( PWM_SW_MAJOR_VERSION != PWM_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( PWM_SW_MINOR_VERSION != PWM_70_SW_MINOR_VERSION_CFG_H ) || \
      ( PWM_SW_PATCH_VERSION != PWM_70_SW_PATCH_VERSION_CFG_H ) )
  #error "Software Version Numbers of Pwm.h and Pwm_Cfg.h are different"
#endif
/* Pwm_Cfg.h version check end */

/* Pwm_70_HW.h version check start */
#if ( PWM_VENDOR_ID != PWM_70_VENDOR_ID_HW_H )
  #error "VENDOR ID for Pwm.h and Pwm_70_HW.h are different"
#endif

#if ( PWM_MODULE_ID != PWM_70_MODULE_ID_HW_H )
  #error "MODULE ID for Pwm.h and Pwm_70_HW.h are different"
#endif

#if ( ( PWM_AR_RELEASE_MAJOR_VERSION    != PWM_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( PWM_AR_RELEASE_MINOR_VERSION    != PWM_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( PWM_AR_RELEASE_REVISION_VERSION != PWM_70_AR_RELEASE_REVISION_VERSION_HW_H ) )
  #error "AUTOSAR Version Numbers of Pwm.h and Pwm_70_HW.h are different"
#endif

#if ( ( PWM_SW_MAJOR_VERSION != PWM_70_SW_MAJOR_VERSION_HW_H ) || \
      ( PWM_SW_MINOR_VERSION != PWM_70_SW_MINOR_VERSION_HW_H ) || \
      ( PWM_SW_PATCH_VERSION != PWM_70_SW_PATCH_VERSION_HW_H ) )
  #error "Software Version Numbers of Pwm.h and Pwm_70_HW.h are different"
#endif
/* Pwm_70_HW.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define PWM_70_100PER               (0x8000U)  /* Pwm 100% duty ratio setting value */

#define PWM_70_MASTER_CHANNEL_MAX   ( PWM_70_HW_MASTER_CHANNEL_MAX )

/* API Service ID */
#define PWM_70_INIT_ID                   ( 0x00U )  /* [SWS_Pwm_00095] */
#define PWM_70_DEINIT_ID                 ( 0x01U )  /* [SWS_Pwm_00096] */
#define PWM_70_SETDUTYCYCLE_ID           ( 0x02U )  /* [SWS_Pwm_10001] */
#define PWM_70_SETPERIODANDDUTY_ID       ( 0x03U )  /* [SWS_Pwm_10002] */
#define PWM_70_SETOUTPUTTOIDLE_ID        ( 0x04U )  /* [SWS_Pwm_10003] */
#define PWM_70_GETOUTPUTSTATE_ID         ( 0x06U )  /* [SWS_Pwm_10005] */
#define PWM_70_GETVERSIONINFO_ID         ( 0x08U )  /* [SWS_Pwm_00103] */

/* DET errors that the PWM can produce. */
/* [SWS_Pwm_00201] */
#define PWM_E_INIT_FAILED                ( 0x10U )
#define PWM_E_UNINIT                     ( 0x11U )
#define PWM_E_PARAM_CHANNEL              ( 0x12U )
#define PWM_E_PARAM_UNCHANGEABLE         ( 0x13U )
#define PWM_E_ALREADY_INITIALIZED        ( 0x14U )
#define PWM_E_PARAM_POINTER              ( 0x15U )

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external constant                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* global variables                                                           */
/*----------------------------------------------------------------------------*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#ifndef PWM_PBCFG_C
extern const Pwm_ConfigType               Pwm_Config;
#endif /* #ifndef PWM_PBCFG_C */
#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_NO_INIT_LOCAL_UNSPECIFIED
#include "Pwm_MemMap.h"
extern Pwm_70_ChannelInfoType             Pwm_ChInfo[ PWM_70_NUM_OF_PWMCHANNEL ];  /* Pwm channel info */
#define PWM_STOP_SEC_VAR_NO_INIT_LOCAL_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_INIT_LOCAL_32
#include "Pwm_MemMap.h"
extern Pwm_70_ModuleStateType             Pwm_ModuleState;                        /* Pwm module state */
#define PWM_STOP_SEC_VAR_INIT_LOCAL_32
#include "Pwm_MemMap.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#define PWM_START_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"

extern void Pwm_Init( const Pwm_ConfigType* ConfigPtr );

#if ( PWM_DE_INIT_API != FALSE )
extern void Pwm_DeInit( void );
#endif  /* #if ( PWM_DE_INIT_API != FALSE ) */

#if ( PWM_SET_PERIOD_AND_DUTY_API != FALSE )
extern void Pwm_SetPeriodAndDuty( Pwm_ChannelType ChannelNumber,
                                  Pwm_PeriodType   Period,
                                  uint16           DutyCycle );
#endif  /* #if ( PWM_SET_PERIOD_AND_DUTY_API != FALSE ) */

#if ( PWM_SET_DUTY_CYCLE_API != FALSE )
extern void Pwm_SetDutyCycle( Pwm_ChannelType ChannelNumber,
                              uint16           DutyCycle );
#endif  /* #if ( PWM_SET_DUTY_CYCLE_API != FALSE ) */

#if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE )
extern void Pwm_SetOutputToIdle( Pwm_ChannelType ChannelNumber );
#endif  /* #if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) */

#if ( PWM_GET_OUTPUT_STATE_API != FALSE )
extern Pwm_OutputStateType Pwm_GetOutputState( Pwm_ChannelType ChannelNumber );
#endif  /* #if ( PWM_GET_OUTPUT_STATE_API != FALSE ) */

#if ( PWM_NOTIFICATION_SUPPORTED != FALSE )
extern void Pwm_DisableNotification( Pwm_ChannelType ChannelNumber );
#endif  /* #if ( PWM_NOTIFICATION_SUPPORTED != FALSE ) */

#if ( PWM_NOTIFICATION_SUPPORTED != FALSE )
extern void Pwm_EnableNotification( Pwm_ChannelType             ChannelNumber,
                                    Pwm_EdgeNotificationType    Notification );
#endif  /* #if ( PWM_NOTIFICATION_SUPPORTED != FALSE ) */

#if ( PWM_VERSION_INFO_API != FALSE )
extern void Pwm_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif  /* #if ( PWM_VERSION_INFO_API != FALSE ) */

#define PWM_STOP_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"

#endif  /* #ifndef PWM_H */

/* EOF Pwm.h ******************************************************************/