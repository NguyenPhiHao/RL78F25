/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Lin.h                                                        */
/* Version     : v1.00.02                                                     */
/* Contents    : LIN  Module API Header                                       */
/*               The file contains extern decelerations of AUTOSAR APIs and   */
/*               Macros used for configurations as per AUTOSAR.               */
/*               The LIN is a basic software module at the service layer      */
/*               of the standardized basic software architecture of AUTOSAR.  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of LIN Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
 
#ifndef LIN_H
#define LIN_H
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "ComStack_Types.h"     /* [SWS_Lin_00226] */
#include "Lin_GeneralTypes.h"   /* [SWS_Lin_00245] */
#include "Lin_70_Types.h"
#include "Lin_70_RL78F2X.h"
#include "Lin_Slave_70_RL78F2X.h"
#include "Lin_70_HW.h"
#include "Lin_Cfg.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define LIN_VENDOR_ID                   ( 70U )
#define LIN_MODULE_ID                   ( 82U )
 
#define LIN_AR_RELEASE_MAJOR_VERSION    ( 22U )
#define LIN_AR_RELEASE_MINOR_VERSION    ( 11U )
#define LIN_AR_RELEASE_REVISION_VERSION ( 0U )
 
#define LIN_SW_MAJOR_VERSION            ( 1U )
#define LIN_SW_MINOR_VERSION            ( 0U )
#define LIN_SW_PATCH_VERSION            ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
 
/*-------------------ComStack_Types.h version check start-----------------------*/
#if ( ( LIN_AR_RELEASE_MAJOR_VERSION    != COMSTACKTYPE_AR_RELEASE_MAJOR_VERSION ) || \
      ( LIN_AR_RELEASE_MINOR_VERSION    != COMSTACKTYPE_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Lin.h and ComStack_Types.h are different"
#endif
 
/*-------------------Lin_Cfg.h -----------------------------------------------*/
#if ( LIN_VENDOR_ID != LIN_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Lin.h and Lin_Cfg.h are different"
#endif
 
#if ( LIN_MODULE_ID != LIN_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Lin.h and Lin_Cfg.h are different"
#endif
 
#if ( ( LIN_AR_RELEASE_MAJOR_VERSION    != LIN_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( LIN_AR_RELEASE_MINOR_VERSION    != LIN_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( LIN_AR_RELEASE_REVISION_VERSION != LIN_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Lin.h and Lin_Cfg.h are different"
#endif
 
#if ( ( LIN_SW_MAJOR_VERSION != LIN_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( LIN_SW_MINOR_VERSION != LIN_70_SW_MINOR_VERSION_CFG_H ) || \
      ( LIN_SW_PATCH_VERSION != LIN_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Lin.h and Lin_Cfg.h are different"
#endif
 
/*-------------------Lin_70_Types.h ------------------------------------------*/
#if ( LIN_VENDOR_ID != LIN_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Lin.h and Lin_70_Types.h are different"
#endif
 
#if ( LIN_MODULE_ID != LIN_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Lin.h and Lin_70_Types.h are different"
#endif
 
#if ( ( LIN_AR_RELEASE_MAJOR_VERSION    != LIN_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( LIN_AR_RELEASE_MINOR_VERSION    != LIN_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( LIN_AR_RELEASE_REVISION_VERSION != LIN_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Lin.h and Lin_70_Types.h are different"
#endif
 
#if ( ( LIN_SW_MAJOR_VERSION != LIN_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( LIN_SW_MINOR_VERSION != LIN_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( LIN_SW_PATCH_VERSION != LIN_70_SW_PATCH_VERSION_TYPES_H ) \
    )
    #error "Software Version Numbers of Lin.h and Lin_70_Types.h are different"
#endif
 
/*------------------Lin_70_HW.h ----------------------------------------------*/
#if ( LIN_VENDOR_ID != LIN_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Lin.h and Lin_70_HW.h are different"
#endif
 
#if ( LIN_MODULE_ID != LIN_70_MODULE_ID_HW_H )
    #error "MODULE ID for Lin.h and Lin_70_HW.h are different"
#endif
 
#if ( ( LIN_AR_RELEASE_MAJOR_VERSION    != LIN_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( LIN_AR_RELEASE_MINOR_VERSION    != LIN_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( LIN_AR_RELEASE_REVISION_VERSION != LIN_70_AR_RELEASE_REVISION_VERSION_HW_H ) \
    )
    #error "AUTOSAR Version Numbers of Lin.h and Lin_70_HW.h are different"
#endif
 
#if ( ( LIN_SW_MAJOR_VERSION != LIN_70_SW_MAJOR_VERSION_HW_H ) || \
      ( LIN_SW_MINOR_VERSION != LIN_70_SW_MINOR_VERSION_HW_H ) || \
      ( LIN_SW_PATCH_VERSION != LIN_70_SW_PATCH_VERSION_HW_H ) \
    )
    #error "Software Version Numbers of Lin.h and Lin_70_HW.h are different"
#endif
 
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
/* API service IDs */
#define LIN_INIT_ID                      ( 0x00U )
#define LIN_CHECKWAKEUP_ID               ( 0x0AU )
#define LIN_GETVERSIONINFO_ID            ( 0x01U )
#define LIN_SENDFRAME_ID                 ( 0x04U )
#define LIN_GOTOSLEEP_ID                 ( 0x06U )
#define LIN_GOTOSLEEPINTERNAL_ID         ( 0x09U )
#define LIN_WAKEUP_ID                    ( 0x07U )
#define LIN_GETSTATUS_ID                 ( 0x08U )
#define LIN_WAKEUPINTERNAL_ID            ( 0x0bU )
 
/* Error message Ids for Det errors */
#define LIN_E_UNINIT                     ( 0x00U )
#define LIN_E_INVALID_CHANNEL            ( 0x02U )
#define LIN_E_INVALID_POINTER            ( 0x03U )
#define LIN_E_STATE_TRANSITION           ( 0x04U )
#define LIN_E_PARAM_POINTER              ( 0x05U )
#define LIN_70_E_INIT_FAILED             ( 0x0FU )
 
/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
extern const Lin_ConfigType*    s_Lin_Config;
 
#if ( LIN_70_DEM_REPORT_ERROR_STATUS != FALSE )
extern const Lin_DemEventParameterRefsType Lin_DemEventParameterRefs;
#endif
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
/* AUTOSAR API prototype declarations */
extern void Lin_Init( const Lin_ConfigType* Config );
extern Std_ReturnType Lin_CheckWakeup( uint8 Channel );
#if ( LIN_VERSION_INFO_API != FALSE )
extern void Lin_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif
extern Std_ReturnType Lin_SendFrame( uint8 Channel, Lin_PduType* PduInfoPtr );
extern Std_ReturnType Lin_GoToSleep( uint8 Channel );
extern Std_ReturnType Lin_GoToSleepInternal( uint8 Channel );
extern Std_ReturnType Lin_Wakeup( uint8 Channel );
extern Std_ReturnType Lin_WakeupInternal( uint8 Channel );
extern Lin_StatusType Lin_GetStatus( uint8 Channel, uint8** Lin_SduPtr );
extern Std_ReturnType lin_chModeChange( uint8 mode );
 
/* Interrupt Handler prototype declarations */
void Lin_70_Isr_Tx( uint8 channelId );
void Lin_70_Isr_Rx( uint8 channelId );
void Lin_70_Isr_Err( uint8 channelId );
 
Std_ReturnType Lin_searchChIndex( const uint8 channelId, uint8* const chIndex );
 
#endif /* LIN_H */
/* EOF Lin.h ******************************************************************/