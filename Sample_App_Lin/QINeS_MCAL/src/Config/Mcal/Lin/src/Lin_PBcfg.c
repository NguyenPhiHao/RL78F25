/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Lin_PBcfg.c                                                  */
/* Version     : v1.00.01                                                     */
/* Contents    : This file is LIN Driver Post-build Time Configuration Source */
/*               and it contains different configuration sets, if supported   */
/*               by hardware                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of LIN Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Mcu_Cfg.h"
#include "Lin.h"
#if ( LIN_70_DEM_REPORT_ERROR_STATUS != FALSE )
#include "Dem.h"
#endif

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define LIN_70_VENDOR_ID_PBCFG_C                       ( 70U )
#define LIN_70_MODULE_ID_PBCFG_C                       ( 82U )

#define LIN_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C        ( 22U )
#define LIN_70_AR_RELEASE_MINOR_VERSION_PBCFG_C        ( 11U )
#define LIN_70_AR_RELEASE_REVISION_VERSION_PBCFG_C     ( 0U )

#define LIN_70_SW_MAJOR_VERSION_PBCFG_C                ( 1U )
#define LIN_70_SW_MINOR_VERSION_PBCFG_C                ( 0U )
#define LIN_70_SW_PATCH_VERSION_PBCFG_C                ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/*---------------Mcu_Cfg.h ---------------------------------------------------*/
/* Check if current file and Mcu_Cfg.h header file are of the same Autosar version */
#if ((LIN_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != MCU_70_AR_RELEASE_MAJOR_VERSION_CFG_H)   ||\
     (LIN_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != MCU_70_AR_RELEASE_MINOR_VERSION_CFG_H)   ||\
     (LIN_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != MCU_70_AR_RELEASE_REVISION_VERSION_CFG_H))
    #error "AutoSar Version Numbers of Lin_PBcfg.c and Mcu_Cfg.h are different"
#endif

/*-------------------Lin.h ---------------------------------------------------*/
/* Check if current file and Lin.h header file are of the same Vendor ID */
#if (LIN_70_VENDOR_ID_PBCFG_C    != LIN_VENDOR_ID)
    #error "Vendor ID of Lin_PBcfg.c and Lin.h are different"
#endif

#if (LIN_70_MODULE_ID_PBCFG_C    != LIN_MODULE_ID)
    #error "Module ID of Lin_PBcfg.c and Lin.h are different"
#endif

/* Check if current file and Lin.h header file are of the same Software version */
#if ((LIN_70_SW_MAJOR_VERSION_PBCFG_C    != LIN_SW_MAJOR_VERSION) ||\
     (LIN_70_SW_MINOR_VERSION_PBCFG_C    != LIN_SW_MINOR_VERSION) ||\
     (LIN_70_SW_PATCH_VERSION_PBCFG_C    != LIN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lin_PBcfg.c and Lin.h are different"
#endif

/* Check if current file and Lin.h header file are of the same Autosar version */
#if ((LIN_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != LIN_AR_RELEASE_MAJOR_VERSION)   ||\
     (LIN_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != LIN_AR_RELEASE_MINOR_VERSION)   ||\
     (LIN_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != LIN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lin_PBcfg.c and Lin.h are different"
#endif

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

#define LIN_START_SEC_VAR_INIT_LOCAL_8
#include "Lin_MemMap.h"

#define LIN_STOP_SEC_VAR_INIT_LOCAL_8
#include "Lin_MemMap.h"

#define LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"

static const Lin_ChannelType Lin_Channel[ LIN_70_NUM_OF_CHANNEL ] = {
        {
            19200U,                                                    /* LinChannelBaudRate */
            LIN_CHANNEL_ID0,                                           /* LinChannelId */
            LIN_CHANNEL_WAKE_UP_SUPPORT,                               /* LinChannelWakeupSupport */
            LIN_CHANNEL_ECUM_WAKEUP_SOURCE,                            /* LinChannelEcuMWakeupSource */
            40000000U,                                                 /* LinClockRef */
            LIN_70_MASTER                                               /* LinNodeType */
        },
};
/* [LIN187_Conf] */
/* Reference to [DemEventParameter] */
#if ( LIN_70_DEM_REPORT_ERROR_STATUS != FALSE )
const Lin_DemEventParameterRefsType  Lin_DemEventParameterRefs = {
        {
            {
                ( uint32 )STD_ON,
                ( Dem_EventIdType )DemConf_DemEventParameter_LIN_E_TIMEOUT
            }
        }
};
#endif /* #if ( LIN_70_DEM_REPORT_ERROR_STATUS != FALSE ) */

static const Lin_GlobalConfigType Lin_GlobalConfigData = {
        &Lin_Channel[0],
#if ( LIN_70_DEM_REPORT_ERROR_STATUS != FALSE )
        &Lin_DemEventParameterRefs
#endif
};
const Lin_ConfigType Lin_Config = {
        &Lin_GlobalConfigData
};

#define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/* EOF Lin_PBcfg.c *************************************************/
