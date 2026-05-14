/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Wdg_PBCfg.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : WDG Configuration Module                                     */
/*                The WDG is a basic software module at the service layer of  */
/*                the standardized basic software architecture of AUTOSAR.    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of WDG Driver
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include header                                                             */
/*----------------------------------------------------------------------------*/
#include "Wdg.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define WDG_70_VENDOR_ID_PBCFG_C                   (70U)
#define WDG_70_MODULE_ID_PBCFG_C                   (102U)

#define WDG_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    (22U)
#define WDG_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    (11U)
#define WDG_70_AR_RELEASE_REVISION_VERSION_PBCFG_C (0U)

#define WDG_70_SW_MAJOR_VERSION_PBCFG_C            (1U)
#define WDG_70_SW_MINOR_VERSION_PBCFG_C            (0U)
#define WDG_70_SW_PATCH_VERSION_PBCFG_C            (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Wdg.h version check start */
#if ( WDG_70_VENDOR_ID_PBCFG_C != WDG_VENDOR_ID )
    #error "VENDOR ID for Wdg_PBCfg.c and Wdg.h are different"
#endif

#if ( WDG_70_MODULE_ID_PBCFG_C != WDG_MODULE_ID )
    #error "MODULE ID for Wdg_PBCfg.c and Wdg.h are different"
#endif

#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != WDG_AR_RELEASE_MAJOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != WDG_AR_RELEASE_MINOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != WDG_AR_RELEASE_REVISION_VERSION ) )
    #error "AUTOSAR Version Numbers of Wdg_PBCfg.c and Wdg.h are different"
#endif

#if ( ( WDG_70_SW_MAJOR_VERSION_PBCFG_C != WDG_SW_MAJOR_VERSION ) || \
      ( WDG_70_SW_MINOR_VERSION_PBCFG_C != WDG_SW_MINOR_VERSION ) || \
      ( WDG_70_SW_PATCH_VERSION_PBCFG_C != WDG_SW_PATCH_VERSION ) )
    #error "Software Version Numbers of Wdg_PBCfg.c and Wdg.h are different"
#endif
/* Wdg.h version check end */

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"

static const Wdg_SettingsFastType    Wdg_SettingsFast = { /* [ECUC_Wdg_00121] */
    5U   /* Time out Value (msec) → 5 msec */
};

static const Wdg_SettingsSlowType    Wdg_SettingsSlow = { /* [ECUC_Wdg_00123] */
    20U  /* Time out Value (msec) → 20 msec */
};

static const Wdg_SettingsConfigType  WdgSettingsConfigData[WDG_70_NUM_OF_WDGSETTINGSCONFIG] = {
    {   /* No1 Internal Wdg config Wdg_SettingsConfigSet[0] */
        WDGIF_FAST_MODE,                              /* Wdg_DefaultMode */
        (const Wdg_SettingsFastType *)&Wdg_SettingsFast,    /* Wdg_SettingsFast */
        (const Wdg_SettingsOffType *)NULL,             /* Wdg_SettingsOff no data NULL set [ECUC_Wdg_00122] */
        (const Wdg_SettingsSlowType *)&Wdg_SettingsSlow,    /* Wdg_SettingsSlow */
        256000U  /* Wdg HW timer (2^9 / fWDT) * 0.75 → 25.6 ms in µs */
    }
};

const Wdg_ConfigType Wdg_Config = {
    WDG_70_NUM_OF_WDGSETTINGSCONFIG,
    &WdgSettingsConfigData[0]
};

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"

/* EOF Wdg_PBCfg.c *******************************************************/
