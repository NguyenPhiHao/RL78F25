/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Pwm_70_HW_Types.h                                            */
/* Version     : v1.00.00                                                     */
/* Contents    : PWM Module type definition header                            */
/*               The PWM is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of PWM Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef PWM_70_HW_TYPES_H_
#define PWM_70_HW_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Pwm_70_RL78F2X_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define PWM_70_VENDOR_ID_HW_TYPES_H             ( 70U )
#define PWM_70_MODULE_ID_HW_TYPES_H             (121U)

#define PWM_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H    ( 22U )
#define PWM_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H    ( 11U )
#define PWM_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H (  0U )

#define PWM_70_SW_MAJOR_VERSION_HW_TYPES_H       ( 1U )
#define PWM_70_SW_MINOR_VERSION_HW_TYPES_H       ( 0U )
#define PWM_70_SW_PATCH_VERSION_HW_TYPES_H       ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Pwm_70_RL78F2X_Types.h version check start */
#if ( PWM_70_VENDOR_ID_HW_TYPES_H    != PWM_70_VENDOR_ID_RL78F2X_TYPES_H )
#   error "VENDOR ID for Pwm_70_HW_Types.h and Pwm_70_RL78F2X_Types.h is different"
#endif

#if ( PWM_70_MODULE_ID_HW_TYPES_H    != PWM_70_MODULE_ID_RL78F2X_TYPES_H )
#   error "MODULE ID for Pwm_70_HW_Types.h and Pwm_70_RL78F2X_Types.h is different"
#endif

#if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H    != PWM_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( PWM_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H    != PWM_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( PWM_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H != PWM_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H )   )
#   error "AUTOSAR Version Numbers of Pwm_70_HW_Types.h and Pwm_70_RL78F2X_Types.h are different"
#endif

#if ( ( PWM_70_SW_MAJOR_VERSION_HW_TYPES_H != PWM_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( PWM_70_SW_MINOR_VERSION_HW_TYPES_H != PWM_70_SW_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( PWM_70_SW_PATCH_VERSION_HW_TYPES_H != PWM_70_SW_PATCH_VERSION_RL78F2X_TYPES_H )     )
#   error "Software Version Numbers of Pwm_70_HW_Types.h and Pwm_70_RL78F2X_Types.h are different"
#endif
/* Pwm_70_RL78F2X_Types.h version check end */

/* [QINeS_SWS_PWM_00004] */
typedef struct {
    uint8         pwmPrescale;        /* prescale register select           */
    uint8         timerType;
    uint8         unitId;
    uint8         masterChId;
    const void*   masterRegInfoPtr;
    const void*   slaveRegInfoPtr;
} Pwm_70_Hw_ConfigType;

#endif /* PWM_70_HW_TYPES_H_ */

/* EOF Pwm_70_HW_Types.h ****************************************************/```
