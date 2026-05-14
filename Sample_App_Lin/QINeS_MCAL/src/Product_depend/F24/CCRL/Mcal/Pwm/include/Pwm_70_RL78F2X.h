/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Pwm_70_RL78F2X.h                                             */
/* Version     : v1.00.01                                                     */
/* Contents    : PWM Module HW dependent header                               */
/*               The PWM is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of PWM Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef PWM_70_RL78F2X_H_
#define PWM_70_RL78F2X_H_

#include "Pwm_70_Types.h"

/*----------------------------------------------------------------------------*/
/* Source File Version Information                                            */
/*----------------------------------------------------------------------------*/
#define PWM_70_VENDOR_ID_RL78F2X_H                      (70U)
#define PWM_70_MODULE_ID_RL78F2X_H                      (121U)

#define PWM_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H       (22U)
#define PWM_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H       (11U)
#define PWM_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H    (0U)

#define PWM_70_SW_MAJOR_VERSION_RL78F2X_H               (1U)
#define PWM_70_SW_MINOR_VERSION_RL78F2X_H               (0U)
#define PWM_70_SW_PATCH_VERSION_RL78F2X_H               (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Pwm_70_Types.h version check start */
#if ( PWM_70_VENDOR_ID_RL78F2X_H != PWM_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Pwm_70_RL78F2X.h and Pwm_70_Types.h is different"
#endif

#if ( PWM_70_MODULE_ID_RL78F2X_H != PWM_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Pwm_70_RL78F2X.h and Pwm_70_Types.h is different"
#endif

#if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H !=        \
            PWM_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) ||    \
      ( PWM_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H !=        \
            PWM_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) ||    \
      ( PWM_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H !=     \
            PWM_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) )
    #error "AUTOSAR Version Numbers of Pwm_70_RL78F2X.h and Pwm_70_Types.h are different"
#endif

#if ( ( PWM_70_SW_MAJOR_VERSION_RL78F2X_H != PWM_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( PWM_70_SW_MINOR_VERSION_RL78F2X_H != PWM_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( PWM_70_SW_PATCH_VERSION_RL78F2X_H != PWM_70_SW_PATCH_VERSION_TYPES_H ) )
    #error "Software Version Numbers of Pwm_70_RL78F2X.h and Pwm_70_Types.h are different"
#endif
/* Pwm_70_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* macros for calling same function */

/* [SWS_Pwm_10082] */
#if ( PWM_SET_DUTY_CYCLE_API != FALSE )
#define Pwm_70_RL78F2X_TAU_SetDutyCycle ( Pwm_70_RL78F2X_TAU_SetPeriodAndDuty )
#define Pwm_70_RL78F2X_TRD_SetDutyCycle ( Pwm_70_RL78F2X_TRD_SetPeriodAndDuty )
#endif  /* #if ( PWM_SET_DUTY_CYCLE_API != FALSE ) */

/* [SWS_Pwm_10084] */
#if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE )
#define Pwm_70_RL78F2X_TAU_SetOutputToIdle ( Pwm_70_RL78F2X_TAU_SetPeriodAndDuty )
#define Pwm_70_RL78F2X_TRD_SetOutputToIdle ( Pwm_70_RL78F2X_TRD_SetPeriodAndDuty )
#endif  /* #if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#define PWM_START_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"

extern void Pwm_70_RL78F2X_TAU_StartChannel( const Pwm_70_ChannelInfoType* chInfoPtr, Pwm_OutputStateType setActiveLevel );
extern void Pwm_70_RL78F2X_TRD_StartChannel( const Pwm_70_ChannelInfoType* chInfoPtr, Pwm_OutputStateType setActiveLevel );
extern void Pwm_70_RL78F2X_TRD_ClrInt( const Pwm_70_ChannelInfoType* chInfoPtr );

/* [SWS_Pwm_10080] */
#if ( PWM_DE_INIT_API != FALSE )
extern void Pwm_70_RL78F2X_TAU_StopChannel( const Pwm_70_ChannelInfoType* chInfoPtr );
extern void Pwm_70_RL78F2X_TRD_StopChannel( const Pwm_70_ChannelInfoType* chInfoPtr );
#endif  /* #if ( PWM_DE_INIT_API != FALSE ) */

/* [SWS_Pwm_10082][SWS_Pwm_10083][SWS_Pwm_10084] */
#if ( ( PWM_SET_PERIOD_AND_DUTY_API != FALSE ) || \
      ( PWM_SET_DUTY_CYCLE_API != FALSE )      || \
      ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) )
extern void Pwm_70_RL78F2X_TAU_SetPeriodAndDuty( const Pwm_70_ChannelInfoType* chInfoPtr );
extern void Pwm_70_RL78F2X_TRD_SetPeriodAndDuty( const Pwm_70_ChannelInfoType* chInfoPtr );
#endif  /* #if ( ( PWM_SET_PERIOD_AND_DUTY_API != FALSE ) || */
        /*       ( PWM_SET_DUTY_CYCLE_API != FALSE )      || */
        /*       ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) )   */

/* [SWS_Pwm_10085] */
#if ( PWM_GET_OUTPUT_STATE_API != FALSE )
extern Pwm_OutputStateType Pwm_70_RL78F2X_TAU_GetOutputState( const Pwm_70_ChannelInfoType* chInfoPtr );
extern Pwm_OutputStateType Pwm_70_RL78F2X_TRD_GetOutputState( const Pwm_70_ChannelInfoType* chInfoPtr );
#endif  /* #if ( PWM_GET_OUTPUT_STATE_API != FALSE ) */

#define PWM_STOP_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"

#endif  /* #ifndef PWM_70_RL78F2X_H_ */

/* EOF Pwm_70_RL78F2X.h *******************************************************/