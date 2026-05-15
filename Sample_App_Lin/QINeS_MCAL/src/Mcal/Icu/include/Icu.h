/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Icu.h                                                        */
/* Version     : v1.00.00                                                     */
/* Contents    : Icu Module header                                            */
/*               The ICU is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ICU Driver                                                */
/* R22-11                                                                     */
 
#ifndef ICU_H_
#define ICU_H_
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "EcuM_Cbk.h"
#include "Icu_Cfg.h"
#include "Icu_70_Types.h"
#include "Icu_70_HW.h"
#include "QINeS_Lite.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ICU_VENDOR_ID                      (70U)
#define ICU_MODULE_ID                      (122U)
 
#define ICU_AR_RELEASE_MAJOR_VERSION       (22U)
#define ICU_AR_RELEASE_MINOR_VERSION       (11U)
#define ICU_AR_RELEASE_REVISION_VERSION    (0U)
 
#define ICU_SW_MAJOR_VERSION               (1U)
#define ICU_SW_MINOR_VERSION               (0U)
#define ICU_SW_PATCH_VERSION               (0U)
 
#define ICU_INSTANCE_ID                    (0U)        /* Module instance ID */
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* EcuM_Cbk.h version check start */
 
#if ( ( ICU_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION ) || \
      ( ICU_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Icu.h and EcuM_Cbk.h are different"
#endif
 
/* EcuM_Cbk.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
/* Icu_Cfg.h version check start */
 
#if ( ICU_VENDOR_ID != ICU_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Icu.h and Icu_Cfg.h are different"
#endif
 
#if ( ICU_MODULE_ID != ICU_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Icu.h and Icu_Cfg.h are different"
#endif
 
#if ( ( ICU_AR_RELEASE_MAJOR_VERSION    != ICU_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( ICU_AR_RELEASE_MINOR_VERSION    != ICU_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( ICU_AR_RELEASE_REVISION_VERSION != ICU_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu.h and Icu_Cfg.h are different"
#endif
 
#if ( ( ICU_SW_MAJOR_VERSION != ICU_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( ICU_SW_MINOR_VERSION != ICU_70_SW_MINOR_VERSION_CFG_H ) || \
      ( ICU_SW_PATCH_VERSION != ICU_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Icu.h and Icu_Cfg.h are different"
#endif
 
/* Icu_Cfg.h version check end */
 
/* Icu_70_Types.h version check start */
 
#if ( ICU_VENDOR_ID != ICU_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Icu.h and Icu_70_Types.h are different"
#endif
 
#if ( ICU_MODULE_ID != ICU_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Icu.h and Icu_70_Types.h are different"
#endif
 
#if ( ( ICU_AR_RELEASE_MAJOR_VERSION    != ICU_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( ICU_AR_RELEASE_MINOR_VERSION    != ICU_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( ICU_AR_RELEASE_REVISION_VERSION != ICU_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu.h and Icu_70_Types.h are different"
#endif
 
#if ( ( ICU_SW_MAJOR_VERSION != ICU_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( ICU_SW_MINOR_VERSION != ICU_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( ICU_SW_PATCH_VERSION != ICU_70_SW_PATCH_VERSION_TYPES_H ) \
    )
    #error "Software Version Numbers of Icu.h and Icu_70_Types.h are different"
#endif
 
/* Icu_70_Types.h version check end */
 
/* Icu_70_HW.h version check start */
 
#if ( ICU_VENDOR_ID != ICU_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Icu.h and Icu_70_HW.h are different"
#endif
 
#if ( ICU_MODULE_ID != ICU_70_MODULE_ID_HW_H )
    #error "MODULE ID for Icu.h and Icu_70_HW.h are different"
#endif
 
#if ( ( ICU_AR_RELEASE_MAJOR_VERSION    != ICU_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( ICU_AR_RELEASE_MINOR_VERSION    != ICU_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( ICU_AR_RELEASE_REVISION_VERSION != ICU_70_AR_RELEASE_REVISION_VERSION_HW_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu.h and Icu_70_HW.h are different"
#endif
 
#if ( ( ICU_SW_MAJOR_VERSION != ICU_70_SW_MAJOR_VERSION_HW_H ) || \
      ( ICU_SW_MINOR_VERSION != ICU_70_SW_MINOR_VERSION_HW_H ) || \
      ( ICU_SW_PATCH_VERSION != ICU_70_SW_PATCH_VERSION_HW_H ) \
    )
    #error "Software Version Numbers of Icu.h and Icu_70_HW.h are different"
#endif
 
/* Icu_70_HW.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
/* API service ID */
#define ICU_70_INIT_ID                     ( 0x00U )         /* [SWS_Icu_00191] */
#define ICU_70_DEINIT_ID                   ( 0x01U )         /* [SWS_Icu_00193] */
#define ICU_70_SETMODE_ID                  ( 0x02U )         /* [SWS_Icu_00194] */
#define ICU_70_DISABLEWAKEUP_ID            ( 0x03U )         /* [SWS_Icu_00195] */
#define ICU_70_ENABLEWAKEUP_ID             ( 0x04U )         /* [SWS_Icu_00196] */
#define ICU_70_SETACTIVATIONCONDITION_ID   ( 0x05U )         /* [SWS_Icu_00197] */
#define ICU_70_DISABLENOTIFICATION_ID      ( 0x06U )         /* [SWS_Icu_00198] */
#define ICU_70_ENABLENOTIFICATION_ID       ( 0x07U )         /* [SWS_Icu_00199] */
#define ICU_70_GETINPUTSTATE_ID            ( 0x08U )         /* [SWS_Icu_00200] */
#define ICU_70_STARTTIMESTAMP_ID           ( 0x09U )         /* [SWS_Icu_00201] */
#define ICU_70_STOPTIMESTAMP_ID            ( 0x0AU )         /* [SWS_Icu_00202] */
#define ICU_70_GETTIMESTAMPINDEX_ID        ( 0x0BU )         /* [SWS_Icu_00203] */
#define ICU_70_RESETEDGECOUNT_ID           ( 0x0CU )         /* [SWS_Icu_00204] */
#define ICU_70_ENABLEEDGECOUNT_ID          ( 0x0DU )         /* [SWS_Icu_00205] */
#define ICU_70_DISABLEEDGECOUNT_ID         ( 0x0EU )         /* [SWS_Icu_00206] */
#define ICU_70_GETEDGENUMBERS_ID           ( 0x0FU )         /* [SWS_Icu_00207] */
#define ICU_70_GETTIMEELAPSED_ID           ( 0x10U )         /* [SWS_Icu_00210] */
#define ICU_70_GETDUTYCYCLEVALUES_ID       ( 0x11U )         /* [SWS_Icu_00211] */
#define ICU_70_GETVERSIONINFO_ID           ( 0x12U )         /* [SWS_Icu_00212] */
#define ICU_70_STARTSIGNALMEASUREMENT_ID   ( 0x13U )         /* [SWS_Icu_00208] */
#define ICU_70_STOPSIGNALMEASUREMENT_ID    ( 0x14U )         /* [SWS_Icu_00209] */
#define ICU_70_CHECKWAKEUP_ID              ( 0x15U )         /* [SWS_Icu_00358] */
#define ICU_70_ENABLEEDGEDETECTION_ID      ( 0x16U )         /* [SWS_Icu_00364] */
#define ICU_70_DISABLEEDGEDETECTION_ID     ( 0x17U )         /* [SWS_Icu_00377] */
 
/* The following errors and exceptions shall be detectable by the MCU module. */
#define ICU_E_PARAM_POINTER             ( 0x0AU )
#define ICU_E_PARAM_CHANNEL             ( 0x0BU )
#define ICU_E_PARAM_ACTIVATION          ( 0x0CU )
#define ICU_E_INIT_FAILED               ( 0x0DU )
#define ICU_E_PARAM_BUFFER_SIZE         ( 0x0EU )
#define ICU_E_PARAM_MODE                ( 0x0FU )
#define ICU_E_UNINIT                    ( 0x14U )
#define ICU_E_NOT_STARTED               ( 0x15U )
#define ICU_E_BUSY_OPERATION            ( 0x16U )
#define ICU_E_ALREADY_INITIALIZED       ( 0x17U )
#define ICU_E_PARAM_NOTIFY_INTERVAL     ( 0x18U )
#define ICU_E_PARAM_VINFO               ( 0x19U )
 
#define ICU_70_SIGNALMEASUREMENT_NUM     ( 4U )
 
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* global variables                                                           */
/*----------------------------------------------------------------------------*/
extern const Icu_ConfigType  Icu_Config;
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#ifndef ICU_C_
extern void Icu_Init( const Icu_ConfigType* ConfigPtr );                /* [SWS_Icu_00191] */
 
#if ( ICU_DE_INIT_API  == TRUE )
extern void Icu_DeInit( void );                                         /* [SWS_Icu_00193] */
#endif      /* #if ( ICU_DE_INIT_API  == TRUE ) */
 
#if ( ICU_SET_MODE_API == TRUE )
extern void Icu_SetMode( Icu_ModeType Mode );                           /* [SWS_Icu_00194] */
#endif      /* #if ( ICU_SET_MODE_API == TRUE ) */
 
#if ( ICU_DISABLE_WAKEUP_API == TRUE )
extern void Icu_DisableWakeup( Icu_ChannelType Channel );               /* [SWS_Icu_00195] */
#endif      /* #if ( ICU_DISABLE_WAKEUP_API == TRUE ) */
 
#if ( ICU_ENABLE_WAKEUP_API == TRUE )
extern void Icu_EnableWakeup( Icu_ChannelType Channel );                /* [SWS_Icu_00196] */
#endif      /* #if ( ICU_ENABLE_WAKEUP_API == TRUE ) */
 
#if ( ICU_WAKEUP_FUNCTIONALITY_API == TRUE )
extern void Icu_CheckWakeup( EcuM_WakeupSourceType WakeupSource );      /* [SWS_Icu_00358] */
#endif      /* #if ( ICU_WAKEUP_FUNCTIONALITY_API == TRUE ) */
 
extern void Icu_SetActivationCondition( Icu_ChannelType Channel, Icu_ActivationType Activation );
extern void Icu_DisableNotification( Icu_ChannelType Channel );         /* [SWS_Icu_00198] */
extern void Icu_EnableNotification( Icu_ChannelType Channel );          /* [SWS_Icu_00199] */
 
#if ( ICU_GET_INPUT_STATE_API == TRUE)
extern Icu_InputStateType Icu_GetInputState( Icu_ChannelType Channel ); /* [SWS_Icu_00200] */
#endif      /* #if ( ICU_GET_INPUT_STATE_API == TRUE) */
 
#if ( ICU_TIMESTAMP_API == TRUE )
extern void Icu_StartTimestamp( Icu_ChannelType Channel, Icu_ValueType* BufferPtr,
                                uint16 BufferSize, uint16 NotifyInterval );
extern void Icu_StopTimestamp( Icu_ChannelType Channel );
extern Icu_IndexType Icu_GetTimestampIndex( Icu_ChannelType Channel );
#endif      /* #if ( ICU_TIMESTAMP_API == TRUE ) */
 
#if ( ICU_EDGE_COUNT_API != FALSE )
extern void Icu_ResetEdgeCount( Icu_ChannelType Channel );
extern void Icu_EnableEdgeCount( Icu_ChannelType Channel );
extern void Icu_DisableEdgeCount( Icu_ChannelType Channel );
extern Icu_EdgeNumberType Icu_GetEdgeNumbers( Icu_ChannelType Channel );
#endif      /* #if ( ICU_EDGE_COUNT_API != FALSE ) */
 
#if ( ICU_EDGE_DETECT_API != FALSE )
extern void Icu_EnableEdgeDetection( Icu_ChannelType Channel );
extern void Icu_DisableEdgeDetection( Icu_ChannelType Channel );
#endif
 
#if ( ICU_SIGNAL_MEASUREMENT_API == TRUE )
extern void Icu_StartSignalMeasurement( Icu_ChannelType Channel );      /* [SWS_Icu_00208] */
extern void Icu_StopSignalMeasurement( Icu_ChannelType Channel );       /* [SWS_Icu_00209] */
#endif      /* #if ( ICU_SIGNAL_MEASUREMENT_API == TRUE ) */
 
#if ( ICU_GET_TIME_ELAPSED_API == TRUE )
extern Icu_ValueType Icu_GetTimeElapsed( Icu_ChannelType Channel );     /* [SWS_Icu_00210] */
#endif      /* #if ( ICU_GET_TIME_ELAPSED_API == TRUE ) */
 
#if ( ICU_GET_DUTY_CYCLE_VALUES_API == TRUE )
/* [SWS_Icu_00211] */
extern void Icu_GetDutyCycleValues( Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues );
#endif      /* #if ( ICU_GET_DUTY_CYCLE_VALUES_API == TRUE ) */
 
#if ( ICU_GET_VERSION_INFO_API == TRUE )
extern void Icu_GetVersionInfo( Std_VersionInfoType* versioninfo );     /* [SWS_Icu_00212] */
#endif      /* #if ( ICU_GET_VERSION_INFO_API == TRUE ) */
 
#ifdef ICU_DISABLE_NOTIFICATION_ASYNC_API
extern void Icu_DisableNotificationAsync( Icu_ChannelType Channel )
#endif      /* #ifdef ICU_DISABLE_NOTIFICATION_ASYNC_API */
#ifdef ICU_ENABLE_NOTIFICATION_ASYNC_API
extern void Icu_EnableNotificationAsync( Icu_ChannelType Channel )
#endif      /* #ifdef ICU_ENABLE_NOTIFICATION_ASYNC_API */
 
extern void Icu_70_getChInfo(uint8 ch, Icu_70_ChannelInfoType** chInfo, Icu_ModeType* mode);
 
#endif      /* #ifndef ICU_C_ */
#endif      /* #ifndef ICU_H_ */

/* EOF Icu.h ******************************************************************/