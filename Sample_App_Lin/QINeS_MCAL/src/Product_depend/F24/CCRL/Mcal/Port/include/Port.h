/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Port.h                                                       */
/* Version     : v1.00.00                                                     */
/* Contents    : PORT Module header                                           */
/*               The PORT is a basic software module at the service layer of  */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of PORT Driver                                               */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef PORT_H_
#define PORT_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Port_Cfg.h"     /* AUTOSAR  [SWS_PORT_00130] */
#include "Port_70_HW.h"
#include "Port_70_Types.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define PORT_VENDOR_ID                     ( 70U )
#define PORT_MODULE_ID                     ( 124U )

#define PORT_AR_RELEASE_MAJOR_VERSION      ( 22U )
#define PORT_AR_RELEASE_MINOR_VERSION      ( 11U )
#define PORT_AR_RELEASE_REVISION_VERSION   ( 0U )

#define PORT_SW_MAJOR_VERSION              ( 1U )
#define PORT_SW_MINOR_VERSION              ( 0U )
#define PORT_SW_PATCH_VERSION              ( 0U )

/*----------------------------------------------------------------------------*/
/* version check                                                              */
/*----------------------------------------------------------------------------*/

/* Port_Cfg.h version check start */

#if ( PORT_VENDOR_ID != PORT_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Port.h and Port_Cfg.h are different"
#endif

#if ( PORT_MODULE_ID != PORT_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Port.h and Port_Cfg.h are different"
#endif

#if ( ( PORT_AR_RELEASE_MAJOR_VERSION    != PORT_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( PORT_AR_RELEASE_MINOR_VERSION    != PORT_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( PORT_AR_RELEASE_REVISION_VERSION != PORT_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Port.h and Port_Cfg.h are different"
#endif

#if ( ( PORT_SW_MAJOR_VERSION != PORT_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( PORT_SW_MINOR_VERSION != PORT_70_SW_MINOR_VERSION_CFG_H ) || \
      ( PORT_SW_PATCH_VERSION != PORT_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Port.h and Port_Cfg.h are different"
#endif

/* Port_Cfg.h version check end */

/* Port_70_HW.h version check start */

#if ( PORT_VENDOR_ID != PORT_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Port.h and Port_70_HW.h are different"
#endif

#if ( PORT_MODULE_ID != PORT_70_MODULE_ID_HW_H )
    #error "MODULE ID for Port.h and Port_70_HW.h are different"
#endif

#if ( ( PORT_AR_RELEASE_MAJOR_VERSION    != PORT_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( PORT_AR_RELEASE_MINOR_VERSION    != PORT_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( PORT_AR_RELEASE_REVISION_VERSION != PORT_70_AR_RELEASE_REVISION_VERSION_HW_H ) \
    )
    #error "AUTOSAR Version Numbers of Port.h and Port_70_HW.h are different"
#endif

#if ( ( PORT_SW_MAJOR_VERSION != PORT_70_SW_MAJOR_VERSION_HW_H ) || \
      ( PORT_SW_MINOR_VERSION != PORT_70_SW_MINOR_VERSION_HW_H ) || \
      ( PORT_SW_PATCH_VERSION != PORT_70_SW_PATCH_VERSION_HW_H ) \
    )
    #error "Software Version Numbers of Port.h and Port_70_HW.h are different"
#endif

/* Port_70_HW.h version check end */

/* Port_70_Types.h version check start */

#if ( PORT_VENDOR_ID != PORT_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Port.h and Port_70_Types.h are different"
#endif

#if ( PORT_MODULE_ID != PORT_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Port.h and Port_70_Types.h are different"
#endif

#if ( ( PORT_AR_RELEASE_MAJOR_VERSION    != PORT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( PORT_AR_RELEASE_MINOR_VERSION    != PORT_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( PORT_AR_RELEASE_REVISION_VERSION != PORT_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Port.h and Port_70_Types.h are different"
#endif

#if ( ( PORT_SW_MAJOR_VERSION != PORT_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( PORT_SW_MINOR_VERSION != PORT_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( PORT_SW_PATCH_VERSION != PORT_70_SW_PATCH_VERSION_TYPES_H ) \
    )
    #error "Software Version Numbers of Port.h and Port_70_Types.h are different"
#endif

/* Port_70_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* API Service IDs   */
#define PORT_INIT_ID                    ( 0x00U )
#define PORT_SET_PIN_DIRECTION_ID       ( 0x01U )
#define PORT_REFRESH_PORT_DIRECTION_ID  ( 0x02U )
#define PORT_GET_VERSION_INFO_ID        ( 0x03U )
#define PORT_SET_PIN_MODE_ID            ( 0x04U )

/* Error Codes */
#define PORT_E_PARAM_PIN                ( 0x0AU )
#define PORT_E_DIRECTION_UNCHANGEABLE   ( 0x0BU )
#define PORT_E_INIT_FAILED              ( 0x0CU )
#define PORT_E_PARAM_INVALID_MODE       ( 0x0DU )
#define PORT_E_MODE_UNCHANGEABLE        ( 0x0EU )
#define PORT_E_UNINIT                   ( 0x0FU )
#define PORT_E_PARAM_POINTER            ( 0x10U )

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
extern const  Port_ConfigType Port_Config;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern void Port_Init( const Port_ConfigType * ConfigPtr );                   /* [SWS_Port_00140] */

#if ( PORT_SET_PIN_DIRECTION_API != FALSE )
/* [SWS_Port_00141] */
extern void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif /* #if ( PORT_SET_PIN_DIRECTION_API != FALSE ) */

#if ( PORT_REFRESH_PORT_DIRECTION_API != FALSE )
extern void Port_RefreshPortDirection( void );                                /* [SWS_Port_00142] */
#endif /* #if ( PORT_REFRESH_PORT_DIRECTION_API != FALSE ) */

#if ( PORT_VERSION_INFO_API != FALSE )
extern void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );          /* [SWS_Port_00143] */
#endif /* #if ( PORT_VERSION_INFO_API != FALSE ) */

#if ( PORT_SET_PIN_MODE_API != FALSE )
extern void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );       /* [SWS_Port_00145] */
#endif /* #if ( PORT_SET_PIN_MODE_API != FALSE ) */

#endif /* #ifndef PORT_H_ */

/* EOF Port.h ****************************************************************/
