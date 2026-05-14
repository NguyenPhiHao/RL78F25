/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Mcu_70_HW.h                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : MCU Module wrapper header                                    */
/*               The MCU is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of MCU Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef MCU_70_HW_H
#define MCU_70_HW_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Mcu_70_HW_Types.h"
#include "Mcu_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* Source File Version Information                             */
/*----------------------------------------------------------------------------*/
#define MCU_70_MODULE_ID_HW_H                ( 101U )
#define MCU_70_VENDOR_ID_HW_H                (  70U )

#define MCU_70_AR_RELEASE_MAJOR_VERSION_HW_H ( 22U )
#define MCU_70_AR_RELEASE_MINOR_VERSION_HW_H ( 11U )
#define MCU_70_AR_RELEASE_REVISION_VERSION_HW_H ( 00U )

#define MCU_70_SW_MAJOR_VERSION_HW_H         (  1U )
#define MCU_70_SW_MINOR_VERSION_HW_H         (  0U )
#define MCU_70_SW_PATCH_VERSION_HW_H         (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Mcu_70_HW_Types.h version check start */
#if ( MCU_70_VENDOR_ID_HW_H  != MCU_70_VENDOR_ID_HW_TYPES_H )
  #error "VENDOR ID for Mcu_70_HW.h and Mcu_70_HW_Types.h is different"
#endif

#if ( MCU_70_MODULE_ID_HW_H != MCU_70_MODULE_ID_HW_TYPES_H )
  #error "MODULE ID for Mcu_70_HW.h and Mcu_70_HW_Types.h is different"
#endif

#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_HW_H != MCU_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H ) || \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_HW_H != MCU_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H ) || \
      ( MCU_70_AR_RELEASE_REVISION_VERSION_HW_H != MCU_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H ) )
  #error "AUTOSAR Version Numbers of Mcu_70_HW.h and Mcu_70_HW_Types.h are different"
#endif

#if ( ( MCU_70_SW_MAJOR_VERSION_HW_H != MCU_70_SW_MAJOR_VERSION_HW_TYPES_H ) || \
      ( MCU_70_SW_MINOR_VERSION_HW_H != MCU_70_SW_MINOR_VERSION_HW_TYPES_H ) || \
      ( MCU_70_SW_PATCH_VERSION_HW_H != MCU_70_SW_PATCH_VERSION_HW_TYPES_H ) )
  #error "Software Version Numbers of Mcu_70_HW.h and Mcu_70_HW_Types.h is different"
#endif
/* Mcu_70_HW_Types.h version check end */

/* Mcu_70_RL78F2X.h version check start */
#if ( MCU_70_VENDOR_ID_HW_H != MCU_70_VENDOR_ID_RL78F2X_H )
  #error "VENDOR ID for Mcu_70_HW.h and Mcu_70_RL78F2X.h is different"
#endif

#if ( MCU_70_MODULE_ID_HW_H != MCU_70_MODULE_ID_RL78F2X_H )
  #error "MODULE ID for Mcu_70_HW.h and Mcu_70_RL78F2X.h is different"
#endif

#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_HW_H != MCU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_HW_H != MCU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) || \
      ( MCU_70_AR_RELEASE_REVISION_VERSION_HW_H != MCU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) )
  #error "AUTOSAR Version Numbers of Mcu_70_HW.h and Mcu_70_RL78F2X.h is different"
#endif

#if ( ( MCU_70_SW_MAJOR_VERSION_HW_H != MCU_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( MCU_70_SW_MINOR_VERSION_HW_H != MCU_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( MCU_70_SW_PATCH_VERSION_HW_H != MCU_70_SW_PATCH_VERSION_RL78F2X_H ) )
  #error "Software Version Numbers of Mcu_70_HW.h and Mcu_70_RL78F2X.h is different"
#endif
/* Mcu_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                     */
/*----------------------------------------------------------------------------*/

/* macro function definitions */
#define Mcu_70_Hw_Init( ConfigPtr )               Mcu_70_RL78F2X_Init( (ConfigPtr) )

#if ( MCU_INIT_CLOCK != FALSE )
  #define Mcu_70_Hw_InitClock( ClockSetCfgPtr )    Mcu_70_RL78F2X_InitClock( (ClockSetCfgPtr) )
#endif /* #if ( MCU_INIT_CLOCK != FALSE ) */

#if ( MCU_NO_PLL == FALSE )
  #define Mcu_70_Hw_DistributePllClock()          Mcu_70_RL78F2X_DistributePllClock()
#endif /* #if ( MCU_NO_PLL == FALSE ) */

#define Mcu_70_Hw_GetPllStatus()                  Mcu_70_RL78F2X_GetPllStatus()
#define Mcu_70_Hw_GetResetReason()                Mcu_70_RL78F2X_GetResetReason()

#define Mcu_70_Hw_GetResetRawValue()              Mcu_70_RL78F2X_GetResetRawValue()
#define Mcu_70_Hw_SetMode( McuMode )              Mcu_70_RL78F2X_SetMode( (McuMode) )

#if ( MCU_GET_RAM_STATE_API != FALSE )
  #define Mcu_70_Hw_GetRamState()                 Mcu_70_RL78F2X_GetRamState()
  #define Mcu_70_Hw_RamStateIsr()                 Mcu_70_RL78F2X_RamStateIsr()
#endif /* #if ( MCU_GET_RAM_STATE_API != FALSE ) */

#endif /* #ifndef MCU_70_HW_H */

/* EOF Mcu_70_HW.h **************************************************/
