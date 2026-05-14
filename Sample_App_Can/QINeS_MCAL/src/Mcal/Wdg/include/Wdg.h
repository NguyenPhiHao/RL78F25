/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Wdg.h                                                        */
/* Version     : v1.00.00                                                     */
/* Contents    : WDG Module Header                                            */
/*               The WDG is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of WDG Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
 
#ifndef WDG_H
#define WDG_H
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Wdg_Cfg.h"
#include "Wdg_70_Types.h"
#include "Wdg_70_HW.h"
#include "QINeS_Lite.h"
 
#define WDG_VENDOR_ID                   ( 70U )
#define WDG_MODULE_ID                   ( 102U )
 
#define WDG_AR_RELEASE_MAJOR_VERSION    ( 22U )
#define WDG_AR_RELEASE_MINOR_VERSION    ( 11U )
#define WDG_AR_RELEASE_REVISION_VERSION ( 0U )
 
#define WDG_SW_MAJOR_VERSION            ( 1U )
#define WDG_SW_MINOR_VERSION            ( 0U )
#define WDG_SW_PATCH_VERSION            ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
 
/* Wdg_Cfg.h version check start */
 
#if ( WDG_VENDOR_ID != WDG_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Wdg.h and Wdg_Cfg.h are different"
#endif
 
#if ( WDG_MODULE_ID != WDG_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Wdg.h and Wdg_Cfg.h are different"
#endif
 
#if ( ( WDG_AR_RELEASE_MAJOR_VERSION    != WDG_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( WDG_AR_RELEASE_MINOR_VERSION    != WDG_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( WDG_AR_RELEASE_REVISION_VERSION != WDG_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Wdg.h and Wdg_Cfg.h are different"
#endif
 
#if ( ( WDG_SW_MAJOR_VERSION != WDG_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( WDG_SW_MINOR_VERSION != WDG_70_SW_MINOR_VERSION_CFG_H ) || \
      ( WDG_SW_PATCH_VERSION != WDG_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Wdg.h and Wdg_Cfg.h are different"
#endif
 
/* Wdg_Cfg.h version check end */
 
/* Wdg_70_Types.h version check start */
 
#if ( WDG_VENDOR_ID != WDG_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Wdg.h and Wdg_70_Types.h are different"
#endif
 
#if ( WDG_MODULE_ID != WDG_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Wdg.h and Wdg_70_Types.h are different"
#endif
 
#if ( ( WDG_AR_RELEASE_MAJOR_VERSION    != WDG_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( WDG_AR_RELEASE_MINOR_VERSION    != WDG_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( WDG_AR_RELEASE_REVISION_VERSION != WDG_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Wdg.h and Wdg_70_Types.h are different"
#endif
 
#if ( ( WDG_SW_MAJOR_VERSION != WDG_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( WDG_SW_MINOR_VERSION != WDG_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( WDG_SW_PATCH_VERSION != WDG_70_SW_PATCH_VERSION_TYPES_H ) \
    )
    #error "Software Version Numbers of Wdg.h and Wdg_70_Types.h are different"
#endif
 
/* Wdg_70_Types.h version check end */
 
/* Wdg_70_HW.h version check start */
 
#if ( WDG_VENDOR_ID != WDG_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Wdg.h and Wdg_70_HW.h are different"
#endif
 
#if ( WDG_MODULE_ID != WDG_70_MODULE_ID_HW_H )
    #error "MODULE ID for Wdg.h and Wdg_70_HW.h are different"
#endif
 
#if ( ( WDG_AR_RELEASE_MAJOR_VERSION    != WDG_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( WDG_AR_RELEASE_MINOR_VERSION    != WDG_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( WDG_AR_RELEASE_REVISION_VERSION != WDG_70_AR_RELEASE_REVISION_VERSION_HW_H ) \
    )
    #error "AUTOSAR Version Numbers of Wdg.h and Wdg_70_HW.h are different"
#endif
 
#if ( ( WDG_SW_MAJOR_VERSION != WDG_70_SW_MAJOR_VERSION_HW_H ) || \
      ( WDG_SW_MINOR_VERSION != WDG_70_SW_MINOR_VERSION_HW_H ) || \
      ( WDG_SW_PATCH_VERSION != WDG_70_SW_PATCH_VERSION_HW_H ) \
    )
    #error "Software Version Numbers of Wdg.h and Wdg_70_HW.h are different"
#endif
 
/* Wdg_70_HW.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define WDG_INSTANCE_ID                ( 0U )
 
#define WDG_70_INTERNAL_INDEX          ( 0x00U )       /* Internal Wdg Index No. */
 
#define WDG_SET_REFRESH_OK             ( 0U )
#define WDG_SET_REFRESH_NOT_OK         ( 1U )
 
#define WDG_ONE                        ( 1U )
 
/* API service ID */
#define WDG_INIT_ID                      ( 0x00U )      /* [SWS_Wdg_00106] */
#define WDG_SETMODE_ID                   ( 0x01U )      /* [SWS_Wdg_00107] */
#define WDG_SETTRIGGERCONDITION_ID       ( 0x03U )      /* [SWS_Wdg_00155] */
#define WDG_GETVERSIONINFO_ID            ( 0x04U )      /* [SWS_Wdg_00109] */
 
/* --- DET ERROR CODE DEFINE --------------------------------------------------- */
/* The following errors and exceptions shall be detectable by the WDG module. */
/* API service used in wrong context (e.g. module not initialized). */
#define WDG_E_DRIVER_STATE             ( 0x10U )                              /* [SWS_Wdg_00010] */
/* API service called with wrong / inconsistent parameter(s) */
#define WDG_E_PARAM_MODE               ( 0x11U )                              /* [SWS_Wdg_00010] */
/* API service called with wrong / inconsistent parameter(s) */
#define WDG_E_PARAM_CONFIG             ( 0x12U )                              /* [SWS_Wdg_00010] */
/* The passed timeout value is higher than the maximum timeout value */
#define WDG_E_PARAM_TIMEOUT            ( 0x13U )                              /* [SWS_Wdg_00010] */
/* API is called with wrong pointer value (e.g. NULL pointer) */
#define WDG_E_PARAM_POINTER            ( 0x14U )                              /* [SWS_Wdg_00010] */
/* Invalid configuration set selection */
#define WDG_E_INIT_FAILED              ( 0x15U )                              /* [SWS_Wdg_00010] */
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"
 
extern const Wdg_ConfigType     Wdg_Config;
 
#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#define WDG_START_SEC_CODE_LOCAL
#include "Wdg_MemMap.h"
 
extern void             Wdg_Init( const Wdg_ConfigType* ConfigPtr );
extern void             Wdg_SetTriggerCondition( uint16 timeout );
extern Std_ReturnType   Wdg_SetMode( WdgIf_ModeType Mode );
extern Wdg_70_StatusValueType* Wdg_70_GetRefreshTimeValue( void );
#if ( WDG_VERSION_INFO_API != FALSE )
extern void             Wdg_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif      /*#if ( WDG_VERSION_INFO_API != FALSE ) */
 
#define WDG_STOP_SEC_CODE_LOCAL
#include "Wdg_MemMap.h"
 
#endif      /* #ifndef WDG_H */
 
/* EOF Wdg.h ******************************************************************/
