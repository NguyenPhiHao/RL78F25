/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Wdg_70_Types.h                                               */
/* Version     : v1.00.00                                                     */
/* Contents    : WDG Module Header                                            */
/*               The WDG is a basic software module at the service layer      */
/*               of the standardized basic software architecture of           */
/*               AUTOSAR.                                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of WDG Driver                                                */
/* R22-11                                                                     */
#ifndef WDG_70_TYPES_H
#define WDG_70_TYPES_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Wdg_Cfg.h"        /* Wdg Cfg include */
#include "WdgIf_Types.h"
#include "QiNeS_Lite.h"

#if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE )
#include "Dem.h"
#endif /* if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE) */

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/

#define WDG_70_VENDOR_ID_TYPES_H                (70U)
#define WDG_70_MODULE_ID_TYPES_H                (102U)

#define WDG_70_AR_RELEASE_MAJOR_VERSION_TYPES_H (22U)
#define WDG_70_AR_RELEASE_MINOR_VERSION_TYPES_H (11U)
#define WDG_70_AR_RELEASE_REVISION_VERSION_TYPES_H (0U)

#define WDG_70_SW_MAJOR_VERSION_TYPES_H         (1U)
#define WDG_70_SW_MINOR_VERSION_TYPES_H         (0U)
#define WDG_70_SW_PATCH_VERSION_TYPES_H         (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Wdg_Cfg.h version check start */
#if ( WDG_70_VENDOR_ID_TYPES_H != WDG_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Wdg_70_Types.h and Wdg_Cfg.h are different"
#endif

#if ( WDG_70_MODULE_ID_TYPES_H != WDG_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Wdg_70_Types.h and Wdg_Cfg.h are different"
#endif

#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != WDG_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != WDG_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( WDG_70_AR_RELEASE_REVISION_VERSION_TYPES_H != WDG_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Wdg_70_Types.h and Wdg_Cfg.h are different"
#endif

#if ( ( WDG_70_SW_MAJOR_VERSION_TYPES_H != WDG_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( WDG_70_SW_MINOR_VERSION_TYPES_H != WDG_70_SW_MINOR_VERSION_CFG_H ) || \
      ( WDG_70_SW_PATCH_VERSION_TYPES_H != WDG_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Wdg_70_Types.h and Wdg_Cfg.h are different"
#endif
/* Wdg_Cfg.h version check end */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* WdgIf_Types.h version check start */
#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != WDGIF_AR_RELEASE_MAJOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != WDGIF_AR_RELEASE_MINOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_REVISION_VERSION_TYPES_H != WDGIF_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Wdg_70_Types.h and WdgIf_Types.h are different"
#endif
/* WdgIf_Types.h version check end */
#endif /* if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* Dem.h version check start */
#if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE )
#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != DEM_AR_RELEASE_MAJOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != DEM_AR_RELEASE_MINOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_REVISION_VERSION_TYPES_H != DEM_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Wdg_70_Types.h and Dem.h are different"
#endif
#endif /* if ( WDG_70_DEM_SET_EVENT_STATUS != FALSE ) */
/* Dem.h version check end */
#endif /* if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef enum {
    WDG_UNINIT = (0U),
    WDG_IDLE   = (1U),
    WDG_BUSY   = (2U)
} Wdg_70_ModuleStateType;   /* Wdg module state */

/* Fast [ECUC_Wdg_00121] */
typedef struct {
    uint32 WdgTimerValue;
} Wdg_SettingsFastType;     /* Off [ECUC_Wdg_00122] */

/* Off [ECUC_Wdg_00122] */
typedef struct {
    uint32 WdgTimerValue;
} Wdg_SettingsOffType;

/* Slow [ECUC_Wdg_00123] */
typedef struct {
    uint32 WdgTimerValue;
} Wdg_SettingsSlowType;

/****** Structure present in Pbcfg.c ************/
typedef struct {
    WdgIf_ModeType             WdgDefaultMode;      /* [ECUC_Wdg_00120] */
    const Wdg_SettingsFastType* WdgSettingsFast;     /* [ECUC_Wdg_00121] */
    const Wdg_SettingsOffType*  WdgSettingsOff;      /* [ECUC_Wdg_00122] */
    const Wdg_SettingsSlowType* WdgSettingsSlow;     /* [ECUC_Wdg_00123] */
    uint32                     WdgIntCounter;       /* Set Interval Refresh Cycle HW Timer */
} Wdg_SettingsConfigType;      /* Configuration for the different watchdog settings [ECUC_Wdg_00082] */

/****** Structure present in cfg.c ************/

/****** Structure present in Pbcfg.c ************/
typedef struct {
    uint8                    WdgNumOfWdgSettingsConfig;
    /* ---- < hand code Start > ---- */
    Wdg_SettingsConfigType*  WdgSettingsConfigSet;  /* [ECUC_Wdg_00082] */
    /* ---- < hand code End > ---- */
} Wdg_ConfigType;              /* Structure to hold the watchdog driver configuration set [SWS_Wdg_00171] */

/* QiNeS Wdg HW Interrupt data */
typedef struct {
    uint32                   WdgTrgCycleCount;  /* Trigger refresh Count */
    uint32                   WdgRefreshCycle;   /* Trigger refresh Cycle */
    uint32                   WdgTimerCounter;   /* Trigger Driver Timer Count */
    WdgIf_ModeType           WdgMode;           /* WdgIf Mode */
    Wdg_70_ModuleStateType   WdgModState;       /* Wdg module state */
} Wdg_70_StatusValueType;

#endif    /* #ifndef WDG_70_TYPES_H */

/* EOF Wdg_70_Types.h ******************************************************/
