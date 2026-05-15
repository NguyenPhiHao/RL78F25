/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Gpt.h                                                        */
/* Version     : v1.00.00                                                     */
/* Contents    : GPT module header                                            */
/*               The GPT is a basic software module at the service layer of   */ 
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of GPT Driver
/* Release R22-11
/*----------------------------------------------------------------------------*/

#ifndef GPT_H_
#define GPT_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "EcuM_Cbk.h"
#include "Gpt_Cfg.h"
#include "Gpt_70_Types.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define GPT_VENDOR_ID                    ( 70U )
#define GPT_MODULE_ID                    ( 100U )

#define GPT_AR_RELEASE_MAJOR_VERSION     ( 22U )
#define GPT_AR_RELEASE_MINOR_VERSION     ( 11U )
#define GPT_AR_RELEASE_REVISION_VERSION  ( 0U )

#define GPT_SW_MAJOR_VERSION             ( 1U )
#define GPT_SW_MINOR_VERSION             ( 0U )
#define GPT_SW_PATCH_VERSION             ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
  /* EcuM_Cbk.h version check start */
  #if ( GPT_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION ) || \
      ( GPT_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION )
    #error "AUTOSAR Version Numbers of Gpt.h and EcuM_Cbk.h are different"
  #endif
  /* EcuM_Cbk.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/* Gpt_Cfg.h version check start */
#if ( GPT_VENDOR_ID != GPT_70_VENDOR_ID_CFG_H )
  #error "VENDOR ID for Gpt.h and Gpt_Cfg.h are different"
#endif

#if ( GPT_MODULE_ID != GPT_70_MODULE_ID_CFG_H )
#  error "MODULE ID for Gpt.h and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_AR_RELEASE_MAJOR_VERSION    != GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( GPT_AR_RELEASE_MINOR_VERSION    != GPT_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( GPT_AR_RELEASE_REVISION_VERSION != GPT_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
#  error "AUTOSAR Version Numbers of Gpt.h and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_SW_MAJOR_VERSION != GPT_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( GPT_SW_MINOR_VERSION != GPT_70_SW_MINOR_VERSION_CFG_H ) || \
      ( GPT_SW_PATCH_VERSION != GPT_70_SW_PATCH_VERSION_CFG_H ) )
#  error "Software Version Numbers of Gpt.h and Gpt_Cfg.h are different"
#endif

/* Gpt_Cfg.h version check end */

/* Gpt_70_Types.h version check start */
#if ( GPT_VENDOR_ID != GPT_70_VENDOR_ID_TYPES_H )
#  error "VENDOR ID for Gpt.h and Gpt_70_Types.h are different"
#endif

#if ( GPT_MODULE_ID != GPT_70_MODULE_ID_TYPES_H )
#  error "MODULE ID for Gpt.h and Gpt_70_Types.h are different"
#endif

#if ( ( GPT_AR_RELEASE_MAJOR_VERSION    != GPT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( GPT_AR_RELEASE_MINOR_VERSION    != GPT_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( GPT_AR_RELEASE_REVISION_VERSION != GPT_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) )
#  error "AUTOSAR Version Numbers of Gpt.h and Gpt_70_Types.h are different"
#endif

#if ( ( GPT_SW_MAJOR_VERSION != GPT_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( GPT_SW_MINOR_VERSION != GPT_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( GPT_SW_PATCH_VERSION != GPT_70_SW_PATCH_VERSION_TYPES_H ) )
#  error "Software Version Numbers of Gpt.h and Gpt_70_Types.h are different"
#endif

/* Gpt_70_Types.h version check end */

/*----------------------------------------------------*/
/* macros                                            */
/*----------------------------------------------------*/
#define GPT_INSTANCE_ID        ( 0U )  /* Gpt module instance ID */

/* --- DET ERROR CODE DEFINE ------------------------------------------------*/
/* GPT Development Errors */
#define GPT_E_UNINIT                       ( 0x0AU )   /* [SWS_Gpt_91000] API called without module initialization */
#define GPT_E_ALREADY_INITIALIZED          ( 0x0BU )   /* [SWS_Gpt_91000] API for initialization called when already initialized */
#define GPT_E_INIT_FAILED                  ( 0x0EU )   /* [SWS_Gpt_91000] API error return code: Init function failed */
#define GPT_E_PARAM_CHANNEL                ( 0x14U )   /* [SWS_Gpt_91000] API parameter checking: invalid channel */
#define GPT_E_PARAM_VALUE                  ( 0x15U )   /* [SWS_Gpt_91000] API parameter checking: invalid value */
#define GPT_E_PARAM_POINTER                ( 0x16U )   /* [SWS_Gpt_91000] API parameter checking: invalid pointer */
#define GPT_E_PARAM_MODE                   ( 0x1FU )   /* [SWS_Gpt_91000] API parameter checking: invalid mode */
#define GPT_E_WRONG_CONFIGURATION          ( 0x2FU )   /* GPT Configuration is wrong */

/* GPT Runtime Errors */
#define GPT_E_BUSY                         ( 0x0BU )   /* [SWS_Gpt_91001] API called when timer channel is still busy (running) */
#define GPT_E_MODE                         ( 0x0CU )   /* [SWS_Gpt_91001] API called when driver is in wrong mode */
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
#define GPT_E_PARAM_PREDEF_TIMER           ( 0x17U )   /* [SWS_Gpt_91000] GPT checking: invalid Predef Timer. */
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */

/* GPT Service ID */
#define GPT_70_GETVERSIONINFO_ID           ( 0x00U )   /* [SWS_Gpt_00279] Gpt_GetVersionInfo ID */
#define GPT_70_INIT_ID                     ( 0x01U )   /* [SWS_Gpt_00280] Gpt_Init ID */
#define GPT_70_DEINIT_ID                   ( 0x02U )   /* [SWS_Gpt_00281] Gpt_DeInit ID */
#define GPT_70_GETTIMEELAPSED_ID           ( 0x03U )   /* [SWS_Gpt_00282] Gpt_GetTimeElapsed ID */
#define GPT_70_GETTIMEREMAINING_ID         ( 0x04U )   /* [SWS_Gpt_00283] Gpt_GetTimeRemaining ID */
#define GPT_70_STARTTIMER_ID               ( 0x05U )   /* [SWS_Gpt_00284] Gpt_StartTimer ID */
#define GPT_70_STOPTIMER_ID                ( 0x06U )   /* [SWS_Gpt_00285] Gpt_StopTimer ID */
#define GPT_70_ENABLENOTIFICATION_ID       ( 0x07U )   /* [SWS_Gpt_00286] Gpt_EnableNotification ID */
#define GPT_70_DISABLENOTIFICATION_ID      ( 0x08U )   /* [SWS_Gpt_00287] Gpt_DisableNotification ID */
#define GPT_70_SETMODE_ID                  ( 0x09U )   /* [SWS_Gpt_00288] Gpt_SetMode ID */
#define GPT_70_DISABLEWAKEUP_ID            ( 0x0AU )   /* [SWS_Gpt_00289] Gpt_DisableWakeup ID */
#define GPT_70_ENABLEWAKEUP_ID             ( 0x0BU )   /* [SWS_Gpt_00290] Gpt_EnableWakeup ID */
#define GPT_70_CHECKWAKEUP_ID              ( 0x0CU )   /* [SWS_Gpt_00328] Gpt_CheckWakeup ID */
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
#define GPT_70_GETPREDEFTIMERVALUE_ID      ( 0x0DU )   /* [SWS_Gpt_00394] Gpt_GetPredefTimer ID */
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */

/* Type definitions */

/* external variables                                                         */ */
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
extern const Gpt_ConfigType Gpt_Config;
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/* ---------------------------------------------------------------------------- */
/* function prototype declarations                                            */
/* ---------------------------------------------------------------------------- */
#define GPT_START_SEC_CODE_LOCAL
#include "Gpt_MemMap.h"

#if ( GPT_VERSION_INFO_API != FALSE )
extern void Gpt_GetVersionInfo( Std_VersionInfoType* VersionInfoPtr );        /* [SWS_Gpt_00279] */
#endif /*#if ( GPT_VERSION_INFO_API != FALSE ) */

extern void Gpt_Init( const Gpt_ConfigType* ConfigPtr );                      /* [SWS_Gpt_00280] */

#if ( GPT_DEINIT_API != FALSE )
extern void Gpt_DeInit( void );                                               /* [SWS_Gpt_00281] */
#endif /*#if ( GPT_DEINIT_API != FALSE ) */

#if ( GPT_TIME_ELAPSED_API != FALSE )
extern Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel );           /* [SWS_Gpt_00282] */
#endif /*#if ( GPT_TIME_ELAPSED_API != FALSE ) */

#if ( GPT_TIME_REMAINING_API != FALSE )
extern Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel );         /* [SWS_Gpt_00283] */
#endif /*#if ( GPT_TIME_REMAINING_API != FALSE ) */

extern void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value );   /* [SWS_Gpt_00284] */
extern void Gpt_StopTimer( Gpt_ChannelType Channel );                         /* [SWS_Gpt_00285] */

#if ( GPT_ENABLE_DISABLE_NOTIFICATION_API != FALSE )
extern void Gpt_EnableNotification( Gpt_ChannelType Channel );                /* [SWS_Gpt_00286] */
extern void Gpt_DisableNotification( Gpt_ChannelType Channel );               /* [SWS_Gpt_00287] */
#endif /*#if ( GPT_ENABLE_DISABLE_NOTIFICATION_API != FALSE ) */

#if ( GPT_WAKEUP_FUNCTIONALITY_API != FALSE )
extern void Gpt_SetMode( Gpt_ModeType Mode );                                 /* [SWS_Gpt_00288] */
extern void Gpt_DisableWakeup( Gpt_ChannelType Channel );                     /* [SWS_Gpt_00289] */
extern void Gpt_EnableWakeup( Gpt_ChannelType Channel );                      /* [SWS_Gpt_00290] */
extern void Gpt_CheckWakeup( EcuM_WakeupSourceType WakeupSource );            /* [SWS_Gpt_00328] */
#endif /*#if ( GPT_WAKEUP_FUNCTIONALITY_API != FALSE ) */

#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
extern Std_ReturnType Gpt_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr ); /* [SWS_Gpt_00394] */
#endif /*#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */

#if ( GPT_70_IRQ_USE != FALSE )
extern void Gpt_70_Isr_Chn( Gpt_ChannelType ChnId );                           /* [SWS_Gpt_00206] */
#endif /*#if ( GPT_70_IRQ_USE != FALSE ) */

#define GPT_STOP_SEC_CODE_LOCAL
#include "Gpt_MemMap.h"

#endif /*#ifndef GPT_H_ */

/* EOF Gpt.h ******************************************************************/