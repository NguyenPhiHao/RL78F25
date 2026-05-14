/*----------------------------------------------------------------------------*/
/* Copyright   : FPT Software Co., Ltd                                        */
/* System Name : QINeS-Lite                                                   */
/* File Name   : Mcu_Lcfg.c                                                   */
/* Version     : v2.0.1                                                       */
/* Contents    : Ecu Configuration (EcuC)                                     */
/* Author      : QINeS-Tools                                                  */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of MCU Driver
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include header                                                             */
/*----------------------------------------------------------------------------*/
#include "Mcu.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define MCU_70_VENDOR_ID_LCFG_C                    (70U)
#define MCU_70_MODULE_ID_LCFG_C                    (101U)

#define MCU_70_AR_RELEASE_MAJOR_VERSION_LCFG_C     (22U)
#define MCU_70_AR_RELEASE_MINOR_VERSION_LCFG_C     (11U)
#define MCU_70_AR_RELEASE_REVISION_VERSION_LCFG_C  (0U)

#define MCU_70_SW_MAJOR_VERSION_LCFG_C             (1U)
#define MCU_70_SW_MINOR_VERSION_LCFG_C             (0U)
#define MCU_70_SW_PATCH_VERSION_LCFG_C             (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Check if source file and MCU header file are of the same vendor */
#if ( MCU_70_VENDOR_ID_LCFG_C != MCU_VENDOR_ID )
    #error "Mcu_Lcfg.c and Mcu.h have different vendor ids"
#endif

/* Check if source file and MCU header file are of the same module */
#if ( MCU_70_MODULE_ID_LCFG_C != MCU_MODULE_ID )
    #error "Mcu_Lcfg.c and Mcu.h have different module ids"
#endif

/* Check if source file and MCU header file are of the same Autosar version */
#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_LCFG_C    != MCU_AR_RELEASE_MAJOR_VERSION ) || \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_LCFG_C    != MCU_AR_RELEASE_MINOR_VERSION ) || \
      ( MCU_70_AR_RELEASE_REVISION_VERSION_LCFG_C != MCU_AR_RELEASE_REVISION_VERSION ) )
    #error "AUTOSAR Version Numbers of Mcu_Lcfg.c and Mcu.h are different"
#endif

/* Check if source file and MCU header file are of the same Software version */
#if ( ( MCU_70_SW_MAJOR_VERSION_LCFG_C != MCU_SW_MAJOR_VERSION ) || \
      ( MCU_70_SW_MINOR_VERSION_LCFG_C != MCU_SW_MINOR_VERSION ) || \
      ( MCU_70_SW_PATCH_VERSION_LCFG_C != MCU_SW_PATCH_VERSION ) )
    #error "Software Version Numbers of Mcu_Lcfg.c and Mcu.h are different"
#endif

/* End of Mcu_Lcfg.c */
