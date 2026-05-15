/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Mcu_70_HW_Types.h                                            */
/* Version     : v1.00.00                                                     */
/* Contents    : Mcu Module type definition header                            */
/*               The MCU is a basic software module at the service layer at   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of MCU Driver                                                */
/* R22-11                                                                     */
#ifndef MCU_70_HW_TYPES_H_
#define MCU_70_HW_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Mcu_70_RL78F2X_Types.h"

/* Source File Version Information */
#define MCU_70_MODULE_ID_HW_TYPES_H            ( 101U )
#define MCU_70_VENDOR_ID_HW_TYPES_H            (  70U )

#define MCU_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H    ( 22U )
#define MCU_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H    ( 11U )
#define MCU_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H (  0U )

#define MCU_70_SW_MAJOR_VERSION_HW_TYPES_H      ( 1U )
#define MCU_70_SW_MINOR_VERSION_HW_TYPES_H      ( 0U )
#define MCU_70_SW_PATCH_VERSION_HW_TYPES_H      ( 0U )

/* file version checks                                                        */
/* Mcu_70_RL78F2X_Types.h version check start */
#if ( MCU_70_VENDOR_ID_HW_TYPES_H != MCU_70_VENDOR_ID_RL78F2X_TYPES_H )
#   error "VENDOR ID for Mcu_70_HW_Types.h and Mcu_70_RL78F2X_Types.h is different"
#endif

#if ( MCU_70_MODULE_ID_HW_TYPES_H != MCU_70_MODULE_ID_RL78F2X_TYPES_H )
#   error "MODULE ID for Mcu_70_HW_Types.h and Mcu_70_RL78F2X_Types.h is different"
#endif

#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H    != MCU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H    != MCU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( MCU_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H != MCU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H )   \
    )
#   error "AUTOSAR Version Numbers of Mcu_70_HW_Types.h and Mcu_70_RL78F2X_Types.h is different"
#endif

#if ( ( MCU_70_SW_MAJOR_VERSION_HW_TYPES_H != MCU_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( MCU_70_SW_MINOR_VERSION_HW_TYPES_H != MCU_70_SW_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( MCU_70_SW_PATCH_VERSION_HW_TYPES_H != MCU_70_SW_PATCH_VERSION_RL78F2X_TYPES_H )     \
    )
#   error "Software Version Numbers of Mcu_70_HW_Types.h and Mcu_70_RL78F2X_Types.h is different"
#endif
/* Mcu_70_RL78F2X_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define MCU_70_HW_RAW_RESET_UNDEFINED     ( MCU_70_RL78F2X_RAW_RESET_UNDEFINED )

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef Mcu_70_RL78F2X_ModeSettingDataType   Mcu_70_HW_ModeSettingDataType;
typedef Mcu_70_RL78F2X_ClockSettingDataType  Mcu_70_HW_ClockSettingDataType;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */   */
/*----------------------------------------------------------------------------*/

#endif /* MCU_70_HW_TYPES_H_ */

/* EOF Mcu_70_HW_Types.h */
