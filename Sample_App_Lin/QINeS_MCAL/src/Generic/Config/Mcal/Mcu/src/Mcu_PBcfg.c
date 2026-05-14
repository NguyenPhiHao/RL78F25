/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Mcu_PBcfg.c                                                  */
/* Version     : v2.0.1                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of MCU Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include header                                                             */
/*----------------------------------------------------------------------------*/
#include "Mcu.h"
#include "SampleMcu.h"
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define MCU_70_VENDOR_ID_PBCFG_C                           ( 70U )
#define MCU_70_MODULE_ID_PBCFG_C                           ( 101U )

#define MCU_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C            ( 22U )
#define MCU_70_AR_RELEASE_MINOR_VERSION_PBCFG_C            ( 11U )
#define MCU_70_AR_RELEASE_REVISION_VERSION_PBCFG_C         ( 0U )

#define MCU_70_SW_MAJOR_VERSION_PBCFG_C                    ( 1U )
#define MCU_70_SW_MINOR_VERSION_PBCFG_C                    ( 0U )
#define MCU_70_SW_PATCH_VERSION_PBCFG_C                    ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Check if source file and MCU header file are of the same vendor */
#if ( MCU_70_VENDOR_ID_PBCFG_C != MCU_VENDOR_ID )
    #error "Mcu_PBcfg.c and Mcu.h have different vendor ids"
#endif

/* Check if source file and MCU header file are of the same module */
#if ( MCU_70_MODULE_ID_PBCFG_C != MCU_MODULE_ID )
    #error "Mcu_PBcfg.c and Mcu.h have different module ids"
#endif

/* Check if source file and MCU header file are of the same Autosar version */
#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C != MCU_AR_RELEASE_MAJOR_VERSION ) || \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_PBCFG_C != MCU_AR_RELEASE_MINOR_VERSION ) || \
      ( MCU_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != MCU_AR_RELEASE_REVISION_VERSION ) )
    #error "AUTOSAR Version Numbers of Mcu_PBcfg.c and Mcu.h are different"
#endif

/* Check if source file and MCU header file are of the same Software version */
#if ( ( MCU_70_SW_MAJOR_VERSION_PBCFG_C != MCU_SW_MAJOR_VERSION ) || \
      ( MCU_70_SW_MINOR_VERSION_PBCFG_C != MCU_SW_MINOR_VERSION ) || \
      ( MCU_70_SW_PATCH_VERSION_PBCFG_C != MCU_SW_PATCH_VERSION ) )
    #error "Software Version Numbers of Mcu_PBcfg.c and Mcu.h are different"
#endif

/*----------------------------------------------------------------------------*/
/* local data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

const Mcu_ClockReferencePointType McuClockReferencePointRef[ MCU_70_NUM_OF_REFERENCE_POINT ] = {
    {
        /* McuClockReferencePoint */
        {
            /* McuClockReferencePoint[0] */
            4000000U,    /* McuClockReferencePointFrequency  4.0MHz crystal clock */
            /* McuClockReferencePoint[1] */
            40000000U,    /* McuClockReferencePointFrequency  40.0MHz PLL clock */
            /* McuClockReferencePoint[2] */
            0U,    /* McuClockReferencePointFrequency  0Hz Stop clock */
            /* McuClockReferencePoint[3] */
            15000U    /* McuClockReferencePointFrequency  15.0KHz Low-speed on-chip oscillator clock */
        }
    }
};

static const Mcu_70_RL78F2X_ClockSettingDataType Mcu_70_ClockSettingData[ MCU_70_NUM_OF_CLOCK_SETTING_DATA ] = {
    {
        McuConf_McuClockSettingConfig_0,                   /* McuClockSettingId */
        0x50U,                                             /* McuClockSettingCmc */
        0x07U,                                             /* McuClockSettingOsts */
        0x00U,                                             /* McuClockSettingCsc */
        0xF0U,                                             /* McuClockSettingOstc */
        0x10U,                                             /* McuClockSettingCkc */
        0x80U,                                             /* McuClockSettingOsmc */
        0x80U,                                             /* McuClockSettingCksel */
        1U,                                                /* McuPllCtlPllDiv1 */
        0U,                                                /* McuPllCtlLckSel  */
        0U,                                                /* McuPllCtlPllDiv0 */
        1U,                                                /* McuPllCtlPllMula */
        1U,                                                /* McuPllCtlPllMul */
        1U,                                                /* McuPllCtlPllOn */
        0x01U                                              /* McuMDiv */
    }
};

static const Mcu_ClockSettingConfigType McuClockSettingConfig[MCU_70_NUM_OF_CLOCK_SETTING] = {
    {
        McuConf_McuClockSettingConfig_0,
        1U,
        &(McuClockReferencePointRef[0U]),
        &(Mcu_70_ClockSettingData[0U])
    }
};

static const Mcu_70_RL78F2X_ModeSettingDataType Mcu_70_ModeSettingData[MCU_70_MODE_TYPE_NUM] = {
    /* MCU_70_MODE_HALT */
    {
        MCU_Q_PER0_VALUE_HALT,                             /* McuPer0 */
        MCU_Q_PER1_VALUE_HALT,                             /* McuPer1 */
        MCU_Q_PER2_VALUE_HALT,                             /* McuPer2 */
        MCU_Q_CANCKSEL_HALT,                               /* McuCancksel */
        MCU_Q_LINCKSEL_HALT,                               /* McuLincksel */
        0x0000U,                                           /* McuTps0 */
        0x0000U                                            /* McuTps1 */
    },
    /* MCU_70_MODE_STOP */
    {
        MCU_Q_PER0_VALUE_STOP,                             /* McuPer0 */
        MCU_Q_PER1_VALUE_STOP,                             /* McuPer1 */
        MCU_Q_PER2_VALUE_STOP,                             /* McuPer2 */
        MCU_Q_CANCKSEL_STOP,                               /* McuCancksel */
        MCU_Q_LINCKSEL_STOP,                               /* McuLincksel */
        0x7050U,                                           /* McuTps0 */
        0x7050U                                            /* McuTps1 */
    },
    /* MCU_70_MODE_NORMAL */
    {
        MCU_Q_PER0_VALUE_NORMAL,                           /* McuPer0 */
        MCU_Q_PER1_VALUE_NORMAL,                           /* McuPer1 */
        MCU_Q_PER2_VALUE_NORMAL,                           /* McuPer2 */
        MCU_Q_CANCKSEL_NORMAL,                             /* McuCancksel */
        MCU_Q_LINCKSEL_NORMAL,                             /* McuLincksel */
        0x7055U,                                           /* McuTps0 */
        0x7050U                                            /* McuTps1 */
    }
};

static const Mcu_ModeSettingConfType McuModeSettingConf[MCU_70_NUM_OF_MODE_SETTING_CONF] = {
    {
        MCU_70_MODE_HALT,            /* McuMode, HALT Mode */
        &(Mcu_70_ModeSettingData[0U])
    },
    {
        MCU_70_MODE_STOP,            /* McuMode, STOP Mode */
        &(Mcu_70_ModeSettingData[1U])
    },
    {
        MCU_70_MODE_NORMAL,            /* McuMode, Normal Mode 32MHz */
        &(Mcu_70_ModeSettingData[2U])
    }
 
};

static const Mcu_RamSectorSettingConfType Mcu_RamSectorSettingConf[1] = {
    {
        0x55U,
        &SampleMcu_Buf[0U],
        20U,
        1U
    }
};

const Mcu_ConfigType Mcu_Config = {
    {
        /* McuModuleConfiguration  [ECUC_Mcu_00119]  */
        MCU_DISABLED,                                      /* McuClockSrcFailureNotification */
        ( Mcu_ModeType )MCU_70_MODE_TYPE_NUM,              /* McuNumberOfMcuModes */
        ( Mcu_RamSectionType )MCU_70_RAM_SECTOR_NUM,       /* McuRamSectors */
        MCU_70_NUM_OF_CLOCK_SETTING,
        &(McuClockSettingConfig[0U]),
        MCU_70_NUM_OF_MODE_SETTING_CONF,
        (const Mcu_ModeSettingConfType *)&(McuModeSettingConf[0U]),
        MCU_70_NUM_OF_RAM_SECTOR_SETTING_CONF,
        (Mcu_RamSectorSettingConfType *)&Mcu_RamSectorSettingConf[0U] /* Mcu_RamSectorSettingConfType */
    }
};

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/* End of Mcu_PBcfg.c */
