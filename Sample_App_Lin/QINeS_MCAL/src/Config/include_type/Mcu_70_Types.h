/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Mcu_70_Types.h                                               */
/* Version     : v1.00.00                                                     */
/* Contents    : Mcu Module type definition header                            */
/*               The MCU is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of MCU Driver                                                */
/* R22-11                                                                     */
#ifndef MCU_70_TYPES_H_
#define MCU_70_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Mcu_Cfg.h"
#include "Mcu_70_HW_Types.h"
#if ( MCU_70_DEM_SET_EVENT_STATUS != FALSE )
#include "Dem.h"
#endif /* #if ( MCU_70_DEM_SET_EVENT_STATUS != FALSE ) */

/*----------------------------------------------------------------------------*/
/* Source File Version Information                                            */
/*----------------------------------------------------------------------------*/
#define MCU_70_MODULE_ID_TYPES_H                     ( 101U )
#define MCU_70_VENDOR_ID_TYPES_H                     (  70U )

#define MCU_70_AR_RELEASE_MAJOR_VERSION_TYPES_H      ( 22U )
#define MCU_70_AR_RELEASE_MINOR_VERSION_TYPES_H      ( 11U )
#define MCU_70_AR_RELEASE_REVISION_VERSION_TYPES_H   (  0U )

#define MCU_70_SW_MAJOR_VERSION_TYPES_H              (  1U )
#define MCU_70_SW_MINOR_VERSION_TYPES_H              (  0U )
#define MCU_70_SW_PATCH_VERSION_TYPES_H              (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Check if header file and Std types header file are the same Autosar version */
#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MINOR_VERSION )   )
#   error "AUTOSAR Version Numbers of Mcu_70_Types.h and Std_Types.h are different"
#endif

/* Mcu_Cfg.h version check start */
#if   ( MCU_70_VENDOR_ID_TYPES_H    != MCU_70_VENDOR_ID_CFG_H )
#   error "Mcu_70_Types.h and Mcu_Cfg.h have different vendor ids"
#endif

#if   ( MCU_70_MODULE_ID_TYPES_H    != MCU_70_MODULE_ID_CFG_H )
#   error "Mcu_70_Types.h and Mcu_Cfg.h have different module ids"
#endif

#if   ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != MCU_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
        ( MCU_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != MCU_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
        ( MCU_70_AR_RELEASE_REVISION_VERSION_TYPES_H != MCU_70_AR_RELEASE_REVISION_VERSION_CFG_H )   )
#   error "AUTOSAR Version Numbers of Mcu_70_Types.h and Mcu_Cfg.h are different"
#endif

#if   ( ( MCU_70_SW_MAJOR_VERSION_TYPES_H != MCU_70_SW_MAJOR_VERSION_CFG_H ) || \
        ( MCU_70_SW_MINOR_VERSION_TYPES_H != MCU_70_SW_MINOR_VERSION_CFG_H ) || \
        ( MCU_70_SW_PATCH_VERSION_TYPES_H != MCU_70_SW_PATCH_VERSION_CFG_H )     )
#   error "Software Version Numbers of Mcu_70_Types.h and Mcu_Cfg.h are different"
#endif
/* Mcu_Cfg.h version check end */

/* Mcu_70_HW_Types.h version check start */
#if   ( MCU_70_VENDOR_ID_TYPES_H    != MCU_70_VENDOR_ID_HW_TYPES_H )
#   error "Mcu_70_Types.h and Mcu_70_HW_Types.h have different vendor ids"
#endif

#if   ( MCU_70_MODULE_ID_TYPES_H    != MCU_70_MODULE_ID_HW_TYPES_H )
#   error "Mcu_70_Types.h and Mcu_70_HW_Types.h have different module ids"
#endif

#if   ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != MCU_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H ) || \
        ( MCU_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != MCU_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H ) || \
        ( MCU_70_AR_RELEASE_REVISION_VERSION_TYPES_H != MCU_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H )   )
#   error "AUTOSAR Version Numbers of Mcu_70_Types.h and Mcu_70_HW_Types.h are different"
#endif

#if   ( ( MCU_70_SW_MAJOR_VERSION_TYPES_H != MCU_70_SW_MAJOR_VERSION_HW_TYPES_H ) || \
        ( MCU_70_SW_MINOR_VERSION_TYPES_H != MCU_70_SW_MINOR_VERSION_HW_TYPES_H ) || \
        ( MCU_70_SW_PATCH_VERSION_TYPES_H != MCU_70_SW_PATCH_VERSION_HW_TYPES_H )     )
#   error "Software Version Numbers of Mcu_70_Types.h and Mcu_70_HW_Types.h are different"
#endif
/* Mcu_70_HW_Types.h version check end */

#if ( QINES_MCAL_VERSION_NO_CHECK    != TRUE )
# if ( MCU_70_DEM_SET_EVENT_STATUS  != FALSE )
    /* Check if header file and DEM header file are of the same software version */
#   if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_TYPES_H != DEM_AR_RELEASE_MAJOR_VERSION ) || \
         ( MCU_70_AR_RELEASE_MINOR_VERSION_TYPES_H != DEM_AR_RELEASE_MINOR_VERSION )   )
#     error "AUTOSAR Version Numbers of Mcu_70_Types.h and Dem.h are different"
#   endif
# endif /* MCU_70_DEM_SET_EVENT_STATUS != FALSE */
#endif   /* QINES_MCAL_VERSION_NO_CHECK    != TRUE */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define MCU_70_MAX_NUMBER_EVENT_ID                          ( 1U )  /* Dem Error Event ID No. */
/* mode type code configured. */
/* [SWS_Mcu_00254] */
/* [SWS_Mcu_00237] */
#define MCU_70_MODE_HALT                                    ( 0U )
#define MCU_70_MODE_STOP                                    ( 1U )
#define MCU_70_MODE_NORMAL                                  ( 2U )
#define MCU_70_MODE_TYPE_NUM                                ( 3U )  /* number of mode types */

/* number of max of clock reference point frequency table. */
#define MCU_70_NUM_OF_CLOCK_REFERENCE_POINT_FREQUENCY       ( 4U )

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/* [SWS_Mcu_00250] */
typedef enum {
    MCU_PLL_LOCKED           = 0,  /* PLL is locked */
    MCU_PLL_UNLOCKED         = 1,  /* PLL is unlocked */
    MCU_PLL_STATUS_UNDEFINED = 2   /* PLL Status is unknown */
} Mcu_PllStatusType;

/* [SWS_Mcu_00251] */
typedef uint8 Mcu_ClockType;

/* [SWS_Mcu_00252] */
/* Reset Configuration */
typedef enum {
    MCU_POWER_ON_RESET   = 0,  /* Power On Reset */
    MCU_WATCHDOG_RESET   = 1,  /* Watchdog Timer underflows */
    MCU_SW_RESET         = 2,  /* Software Reset */
    MCU_RESET_UNDEFINED  = 3   /* Reset is undefined */
} Mcu_ResetType;

/* [SWS_Mcu_00253] */
/* RAW Reset Configuration */
typedef uint32 Mcu_RawResetType;

/* [SWS_Mcu_00254] */
/* Mode Type Configuration */
typedef uint16 Mcu_ModeType;        /* 0.. <number of MCU modes>-1 */

/* [SWS_Mcu_00255] */
/* Ram Section TypeConfiguration */
typedef uint16 Mcu_RamSectionType;  /* 0.. <number of RAM sections>-1 */

/* [SWS_Mcu_00256] */
/* Ram Section State */
typedef enum {
    MCU_RAMSTATE_INVALID = 1,  /* Ram content is not valid or unknown (default) */
    MCU_RAMSTATE_VALID   = 2   /* Ram content is valid */
} Mcu_RamStateType;

/* [ECUC_Mcu_00170] */
/* Enables/Disables clock failure notification */
typedef enum {
    MCU_DISABLED = 0,
    MCU_ENABLED  = 1
} Mcu_ClockSrcFailureNotificationType;

/* Indicates the initialization status. */
typedef enum {
    MCU_70_STATE_UNINITIALIZED = 1,
    MCU_70_STATE_INITIALIZED   = 2
} Mcu_70_ModuleStateType;

/* [ECUC_Mcu_00120] */
/* This container contains the configuration (parameters) for the RAM sector setting. */
typedef struct {
    uint8  McuRamDefaultValue;        /* [ECUC_Mcu_00177] */
    uint8* McuRamSectionBaseAddress;  /* [ECUC_Mcu_00178] */
    uint32 McuRamSectionSize;         /* [ECUC_Mcu_00179] */
    uint32 McuRamSectionWriteSize;    /* [ECUC_Mcu_00190] */
} Mcu_RamSectorSettingConfType;

/* [ECUC_Mcu_00123] */
/* This container contains the configuration (parameters) for the Mode setting of the MCU. */
typedef struct {
    Mcu_ModeType                           McuMode;              /* [ECUC_Mcu_00176] */
    const Mcu_70_HW_ModeSettingDataType*  McuModeSettingDataPtr;/* H/W dependent configuration */
} Mcu_ModeSettingConfType;

/* [ECUC_Mcu_00174] */
/* This container defines a reference point in the Mcu Clock tree. It defines the frequency
 * which then can be used by other modules as an input value. Lower multiplicity is 1,
 * as even in the simplest case (only one frequency is used), there is one frequency to be defined.
 */
typedef struct {
    uint32 McuClockReferencePointFrequency[MCU_70_NUM_OF_CLOCK_REFERENCE_POINT_FREQUENCY]; /* [ECUC_Mcu_00175] */
    /* note: this parameter is required EcuCFloatParamDef by SWS,
     *       but modified to uint32 for ease of use.
     */
} Mcu_ClockReferencePointType;

/* [ECUC_Mcu_00124] */
/* This container contains the configuration (parameters) for the Clock setting of the MCU. */
typedef struct { /* McuClockSettingConfig[MCU_70_CLOCK_TYPE_NUM] */
    uint8                                   McuClockSettingId;            /* [ECUC_Mcu_00183] */
    uint8                                   McuNumOfClockReferencePoint;
    const Mcu_ClockReferencePointType*     McuClockReferencePointPtr;    /* [MCU_70_NUM_OF_REFERENCE_POINT][ECUC_Mcu_00174] */
    const Mcu_70_HW_ClockSettingDataType*  McuClockSettingDataPtr;       /* H/W dependent clock configuration */
} Mcu_ClockSettingConfigType;

/* [ECUC_Mcu_00119] */
/* This container contains the configuration (parameters) of the MCU driver. */
/* [SWS_Mcu_00131] */
/* [SWS_Mcu_00035] */
/* [SWS_Mcu_00031] */
/* [SWS_Mcu_00030] */
typedef struct {
    Mcu_ClockSrcFailureNotificationType    McuClockSrcFailureNotification; /* [ECUC_Mcu_00170] */
    Mcu_ModeType                           McuNumberOfMcuModes;            /* [ECUC_Mcu_00171] */
    Mcu_RamSectionType                     McuRamSectors;                  /* [ECUC_Mcu_00172] */
    uint8                                  McuNumOfClockSetting;           /* [MCU_70_CLOCK_TYPE_NUM][ECUC_Mcu_00124] */
    const Mcu_ClockSettingConfigType*      McuClockSettingConfigPtr;       /* [MCU_70_CLOCK_TYPE_NUM][ECUC_Mcu_00124] */
    uint8                                  McuNumOfModeSettingConf;        /* [MCU_MODE_TYPE_NUM][ECUC_Mcu_00123] */
    const Mcu_ModeSettingConfType*         McuModeSettingConfPtr;          /* [MCU_MODE_TYPE_NUM][ECUC_Mcu_00123] */
    uint16                                 McuNumOfRamSectorSettingConf;   /* [MCU_RAM_SECTOR_NUM][ECUC_Mcu_00120] */
    const Mcu_RamSectorSettingConfType*    McuRamSectorSettingConfPtr;     /* [MCU_RAM_SECTOR_NUM][ECUC_Mcu_00120] */
} Mcu_ModuleConfigurationType;

/* [SWS_Mcu_00249] */
/* A pointer to such a structure is provided to the MCU initialization routines for configuration. */
typedef struct {
    Mcu_ModuleConfigurationType    McuModuleConfiguration;
} Mcu_ConfigType;

#endif /* MCU_70_TYPES_H_ */

/* EOF Mcu_70_Types.h */
