/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Mcu_70_RL78F2X_Types.h                                       */
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
/******************************************************************************/
#ifndef MCU_70_RL78F2X_TYPES_H_
#define MCU_70_RL78F2X_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Mcl_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* Source File Version Information                                            */
/*----------------------------------------------------------------------------*/
#define MCU_70_MODULE_ID_RL78F2X_TYPES_H            ( 101U )
#define MCU_70_VENDOR_ID_RL78F2X_TYPES_H            (  70U )

#define MCU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H    ( 22U )
#define MCU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H    ( 11U )
#define MCU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H (  0U )

#define MCU_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H      (  1U )
#define MCU_70_SW_MINOR_VERSION_RL78F2X_TYPES_H      (  0U )
#define MCU_70_SW_PATCH_VERSION_RL78F2X_TYPES_H      (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Check if header file and Std types header file are of the same Autosar version */
#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H != STD_TYPES_AR_RELEASE_MINOR_VERSION )   )
#   error "AUTOSAR Version Numbers of Mcu_70_RL78F2X_Types.h and Std_Types.h are different"
#endif

/* Mcl_70_RL78F2X.h version check start */
#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H != MCL_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H != MCL_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H )   )
#   error "AUTOSAR Version Numbers of Mcu_70_RL78F2X_Types.h and Mcl_70_RL78F2X.h are different"
#endif

/* Mcl_70_RL78F2X.h version check end */
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* Reset raw value RESF (Upper 8bit) & POCRES (Lower 8 bit) */
#define MCU_70_RL78F2X_RAW_RESET_UNDEFINED      ( 0xFFFFU )

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef struct {
    uint8  McuPer0;       /* Peripheral Enable Registers 0 data.          */
    uint8  McuPer1;       /* Peripheral Enable Registers 1 data.          */
    uint8  McuPer2;       /* Peripheral Enable Registers 2 data.          */
    uint8  McuCancksel;   /* CAN Clock Select Register data.              */
    uint8  McuLincLocsel; /* LIN Clock Select Register data.              */
    uint16 McuTps0;       /* Timer clock select register 0 data.          */
    uint16 McuTps1;       /* Timer clock select register 1 data.          */
} Mcu_70_RL78F2X_ModeSettingDataType;

typedef struct { /* RL78/F2X Specific register set */
    uint8 McuClockSettingId;    /* [ECUC_Mcu_00183] ClockSetting Id.                   */
    uint8 McuClockSettingCmc;   /* [ECUC_Mcu_00124]                                     */
    uint8 McuClockSettingOsts;  /* [ECUC_Mcu_00124] Oscillation Stabilization Time Select Register. */
    uint8 McuClockSettingCsc;   /* [ECUC_Mcu_00124] Clock Operation Status Control Register.         */
    uint8 McuClockSettingOstc;  /* [ECUC_Mcu_00124] Oscillation Stabilization Time Counter Status Register. */
    uint8 McuClockSettingCkc;   /* [ECUC_Mcu_00124] System Clock Control Register.      */
    uint8 McuClockSettingOsmc;  /* [ECUC_Mcu_00124] Operation Speed Mode Control Register. */
    uint8 McuClockSettingCksel; /* [ECUC_Mcu_00124] Clock Select Register.              */
    uint8 McuPllCtlPllDiv1;     /* [ECUC_Mcu_00124] Control of PLL output clock selection bit. */
    uint8 McuPllCtlLckSel;      /* [ECUC_Mcu_00124] Control of setting lock-up wait counter bit. */
    uint8 McuPllCtlPllDiv0;     /* [ECUC_Mcu_00124] Control of PLL division selection bit.         */
    uint8 McuPllCtlPllMula;     /* [ECUC_Mcu_00124] Control of PLL multiplication selection bit.   */
    uint8 McuPllCtlPllMul;      /* [ECUC_Mcu_00124] Control of PLL multiplication selection bit.   */
    uint8 McuPllCtlPllOn;       /* [ECUC_Mcu_00124] Control of PLL operation selection bit.        */
    uint8 McuDiv;               /* [ECUC_Mcu_00124] fMP Clock Division Register.                   */
} Mcu_70_RL78F2X_ClockSettingDataType;

#endif /* MCU_70_RL78F2X_TYPES_H_ */

/* EOF Mcu_70_RL78F2X_Types.h */
