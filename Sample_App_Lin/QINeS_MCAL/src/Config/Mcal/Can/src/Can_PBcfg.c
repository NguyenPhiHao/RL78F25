/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Can_PBcfg.c                                                  */
/* Version     : v1.00.02                                                     */
/* Contents    : This module provides services for initiating transmissions   */
/*               and calls the callback functions of the CanIf module for     */
/*               notifying events, independently from the hardware. Also it   */
/*               provides services to control the behavior and state of the   */
/*               CAN controllers that belong to the same CAN Hardware Unit.   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of CAN Driver                                                */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Can.h"
#include "Can_Cfg.h"    /* [CAN034] */
#include "Mcu.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define CAN_70_VENDOR_ID_PBCFG_C                                 ( 70U )
#define CAN_70_MODULE_ID_PBCFG_C                                 ( 80U )

#define CAN_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C                  ( 22U )
#define CAN_70_AR_RELEASE_MINOR_VERSION_PBCFG_C                  ( 11U )
#define CAN_70_AR_RELEASE_REVISION_VERSION_PBCFG_C               (  0U )

#define CAN_70_SW_MAJOR_VERSION_PBCFG_C                          (  1U )
#define CAN_70_SW_MINOR_VERSION_PBCFG_C                          (  0U )
#define CAN_70_SW_PATCH_VERSION_PBCFG_C                          (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Check if current file and Can.h header file are of the same Vendor ID */
#if (CAN_70_VENDOR_ID_PBCFG_C    != CAN_VENDOR_ID)
    #error "VENDOR ID for Can_PBcfg.c and Can.h are different"
#endif      /* End of Vendor Id Version check */
#if (CAN_70_MODULE_ID_PBCFG_C    != CAN_MODULE_ID)
    #error "MODULE ID for Can_PBcfg.c and Can.h are different"
#endif      /* End of Vendor Id Version check */

/* Check if current file and Can.h header file are of the same Software version */
#if ((CAN_70_SW_MAJOR_VERSION_PBCFG_C    != CAN_SW_MAJOR_VERSION) ||\
     (CAN_70_SW_MINOR_VERSION_PBCFG_C    != CAN_SW_MINOR_VERSION) ||\
     (CAN_70_SW_PATCH_VERSION_PBCFG_C    != CAN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Can_PBcfg.c and Can.h are different"
#endif      /* End of S/W Version check */

/* Check if current file and Can.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != CAN_AR_RELEASE_MAJOR_VERSION)   ||\
     (CAN_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != CAN_AR_RELEASE_MINOR_VERSION)   ||\
     (CAN_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != CAN_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Can_PBcfg.c and Can.h are different"
#endif      /* End of Autosar Version check */

/*---------------Can_Cfg.h--------------------------------------------------*/

/* Check if current file and Can_Cfg.h header file are of the same Vendor ID */
#if (CAN_70_VENDOR_ID_PBCFG_C    != CAN_70_VENDOR_ID_CFG_H)
    #error "VENDOR ID of Can_PBcfg.c and Can_Cfg.h are different"
#endif      /* End of Vendor Id Version check */
#if (CAN_70_MODULE_ID_PBCFG_C    != CAN_70_MODULE_ID_CFG_H)
    #error "MODULE ID of Can_PBcfg.c and Can_Cfg.h are different"
#endif      /* End of Vendor Id Version check */
 
/* Check if current file and Can_Cfg.h header file are of the same Software version */
#if ((CAN_70_SW_MAJOR_VERSION_PBCFG_C    != CAN_70_SW_MAJOR_VERSION_CFG_H) ||\
     (CAN_70_SW_MINOR_VERSION_PBCFG_C    != CAN_70_SW_MINOR_VERSION_CFG_H) ||\
     (CAN_70_SW_PATCH_VERSION_PBCFG_C    != CAN_70_SW_PATCH_VERSION_CFG_H))
    #error "Software Version Numbers of Can_PBcfg.c and Can_Cfg.h are different"
#endif      /* End of S/W Version check */

/* Check if current file and Can_Cfg.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != CAN_70_AR_RELEASE_MAJOR_VERSION_CFG_H)   ||\
     (CAN_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != CAN_70_AR_RELEASE_MINOR_VERSION_CFG_H)   ||\
     (CAN_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != CAN_70_AR_RELEASE_REVISION_VERSION_CFG_H))
    #error "AUTOSAR Version Numbers of Can_PBcfg.c and Can_Cfg.h are different"
#endif      /* End of Autosar Version check */

/*---------------------Mcu.h------------------------------------------------*/

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )

/* Check if source file and MCU header file are of the same Autosar version */
#if ( ( CAN_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C != MCU_AR_RELEASE_MAJOR_VERSION ) || \
      ( CAN_70_AR_RELEASE_MINOR_VERSION_PBCFG_C != MCU_AR_RELEASE_MINOR_VERSION ) )
    #error "AUTOSAR Version Numbers of Can_PBcfg.c and Mcu.h are different"
#endif

#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data                                                                 */
/*----------------------------------------------------------------------------*/
#define CAN_START_SEC_CONFIG_DATA_32
#include "Can_MemMap.h"

/* [ECUC_Can_00468] */
static const Can_HwFilterType Can_HwFilterData[CAN_70_NUM_OF_FILTER_MASK] =
{
    /* Filter ID = 0x0 */
    {
        0x00000000UL,                               /* CanHwFilterCode */
        0x00000000UL,                               /* CanHwFilterMask */
    }  
};

#define CAN_STOP_SEC_CONFIG_DATA_32
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

/* [ECUC_Can_00387] */
static const Can_ControllerBaudrateConfigType
             CanControllerBaudrateConfig[CAN_70_NUM_OF_BAUDRATE_TABLE] =
{
    /* Baudrate Config ID = 0x0 */
    {
        500000U,                                    /* CanControllerBaudRate */
        0U,                                         /* CanControllerBaudRateConfigID */
        0U,                                         /* CanControllerPropSeg */          /* no use */
        5U,                                         /* CanControllerSeg1 */             /* range:2Tq-256Tq */
        2U,                                         /* CanControllerSeg2 */             /* range:2Tq-128Tq */
        1U,                                         /* CanControllerSyncJumpWidth */    /* range:1Tq-128Tq */
        NULL_PTR                                    /* CanControllerFdBaudrateConfig */
    }
};

/* [ECUC_Can_00354] */
static const Can_ControllerType Can_ControllerData[CAN_70_NUM_OF_CONTROLLER] =
{
    /* Controller ID = 0 */
    {
        TRUE,                                       /* CanControllerActivation */
        0xF03A0000UL,                               /* CanControllerBaseAddress */
        0U,                                         /* CanControllerId */
        CAN_70_CAN_CHANNEL_CAN0,                    /* CanQChannelId */
        0x10U,                                      /* CanQClockSource */
        CAN_PROCESSING_POLLING,                     /* CanTxProcessing */
        CAN_PROCESSING_POLLING,                     /* CanRxProcessing */
        CAN_PROCESSING_POLLING,                     /* CanBusoffProcessing */
        CAN_PROCESSING_POLLING,                     /* CanWakeupProcessing */
        TRUE,                                       /* CanWakeupSupport */
        &CanControllerBaudrateConfig[0x0U],         /* CanControllerDefaultBaudrate */
        4000000UL,                                  /* CanCpuClockRef */
        0x00000040UL,                               /* CanWakeupSourceRef */
        CanControllerBaudrateConfig,                /* CanControllerBaudrateConfig */
    }
};

/* [ECUC_Can_00437] */
static const Can_MainFunctionRWPeriodsType Can_MainFunctionRWPeriodsData[CAN_70_NUM_OF_MAIN_FUNCTION_PERIODS] =
{
    /* Period ID = 0 */
    {
        10                                          /* CanMainFunctionPeriod */ /* seconds */
    }
};

/* [ECUC_Can_00324] */
static const Can_HardwareObjectType Can_HardwareObjectData[CAN_70_NUM_OF_HARDWARE_OBJECT] =
{
    /* CanObjectId = 0 */
    {

#if ( CAN_70_USE_CANFD == TRUE )
        0U,                                          /* CanFdPaddingValue */
#endif /* #if ( CAN_70_USE_CANFD == TRUE ) */
       
        CAN_70_FULL,                                 /* CanHandleType */
        TRUE,                                        /* CanHardwareObjectUsesPolling */
        1U,                                          /* CanHwObjectCount */
        CAN_70_STANDARD,                             /* CanIdType */
        0U,                                          /* CanObjectId */
        CAN_OBJECT_PL_64,                            /* CanObjectPayloadLength */
        CAN_70_TRANSMIT,                             /* CanObjectType */
        FALSE,                                       /* CanTriggerTransmitEnable */
        &Can_ControllerData[0],                      /* CanControllerRef */
        &Can_MainFunctionRWPeriodsData[0],           /* CanMainFunctionRWPeriodRef */
        NULL_PTR,                                    /* CanHwFilter */
    },
   
    /* CanObjectId = 1 */
    {

#if ( CAN_70_USE_CANFD == TRUE )
        0U,                                          /* CanFdPaddingValue */
#endif /* #if ( CAN_70_USE_CANFD == TRUE ) */
       
        CAN_70_FULL,                                 /* CanHandleType */
        TRUE,                                        /* CanHardwareObjectUsesPolling */
        CAN_70_RL78F2X_HWOBJECTCOUNT_HRH_8,          /* CanHwObjectCount */
        CAN_70_STANDARD,                             /* CanIdType */
        0U,                                          /* CanObjectId */
        CAN_OBJECT_PL_64,                            /* CanObjectPayloadLength */
        CAN_70_RECEIVE,                              /* CanObjectType */
        FALSE,                                       /* CanTriggerTransmitEnable */
        &Can_ControllerData[0],                      /* CanControllerRef */
        &Can_MainFunctionRWPeriodsData[0],           /* CanMainFunctionRWPeriodRef */
        &Can_HwFilterData[0],                        /* CanHwFilter */
    },
   
};

/* [ECUC_Can_00343] */
static const Can_ConfigSetType Can_ConfigSetData =
{
    &Can_ControllerData[0U],                         /* CanController */
    &Can_HardwareObjectData[0U],                     /* CanHardwareObject */
};

/* [ECUC_Can_00489] */
const Can_ConfigType Can_Config =
{
    &Can_ConfigSetData                               /* CanConfigSet */
};

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"
/* EOF Can_PBcfg.c ****************************************************************/
