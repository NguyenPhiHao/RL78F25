/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Pwm_70_HW.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : PWM Module wrapper                                           */
/*               The PWM is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of PWM Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Pwm_70_HW.h"
 
/*----------------------------------------------------------------------------*/
/* Source File Version Information                                            */
/*----------------------------------------------------------------------------*/
#define PWM_70_VENDOR_ID_HW_C                      (70U)
#define PWM_70_MODULE_ID_HW_C                      (121U)
 
#define PWM_70_AR_RELEASE_MAJOR_VERSION_HW_C       (22U)
#define PWM_70_AR_RELEASE_MINOR_VERSION_HW_C       (11U)
#define PWM_70_AR_RELEASE_REVISION_VERSION_HW_C    (0U)
 
#define PWM_70_SW_MAJOR_VERSION_HW_C               (1U)
#define PWM_70_SW_MINOR_VERSION_HW_C               (0U)
#define PWM_70_SW_PATCH_VERSION_HW_C               (0U)
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Pwm_70_HW.h version check start */
#if ( PWM_70_VENDOR_ID_HW_C != PWM_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Pwm_70_HW.c and Pwm_70_HW.h is different"
#endif
 
#if ( PWM_70_MODULE_ID_HW_C != PWM_70_MODULE_ID_HW_H )
    #error "MODULE ID for Pwm_70_HW.c and Pwm_70_HW.h is different"
#endif
 
#if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_HW_C    != PWM_70_AR_RELEASE_MAJOR_VERSION_HW_H )  || \
      ( PWM_70_AR_RELEASE_MINOR_VERSION_HW_C    != PWM_70_AR_RELEASE_MINOR_VERSION_HW_H )  || \
      ( PWM_70_AR_RELEASE_REVISION_VERSION_HW_C != PWM_70_AR_RELEASE_REVISION_VERSION_HW_H ) )
    #error "AUTOSAR Version Numbers of Pwm_70_HW.c and Pwm_70_HW.h are different"
#endif
 
#if ( ( PWM_70_SW_MAJOR_VERSION_HW_C != PWM_70_SW_MAJOR_VERSION_HW_H ) || \
      ( PWM_70_SW_MINOR_VERSION_HW_C != PWM_70_SW_MINOR_VERSION_HW_H ) || \
      ( PWM_70_SW_PATCH_VERSION_HW_C != PWM_70_SW_PATCH_VERSION_HW_H ) )
    #error "Software Version Numbers of Pwm_70_HW.c and Pwm_70_HW.h are different"
#endif
/* Pwm_70_HW.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

typedef void ( *Pwm_70_HW_StartChannelFuncType )( const Pwm_70_ChannelInfoType* chInfoPtr, Pwm_OutputStateType setActiveLevel );
 
/* [SWS_Pwm_10080] */
#if ( PWM_DE_INIT_API != FALSE )
typedef void ( *Pwm_70_HW_StopChannelFuncType )( const Pwm_70_ChannelInfoType* chInfoPtr );
#endif  /* #if ( PWM_DE_INIT_API != FALSE )  */
 
/* [SWS_Pwm_10082] */
#if ( PWM_SET_DUTY_CYCLE_API != FALSE )
typedef void ( *Pwm_70_HW_SetDutyCycleFuncType )( const Pwm_70_ChannelInfoType* chInfoPtr );
#endif  /* #if ( PWM_SET_DUTY_CYCLE_API != FALSE ) */
 
/* [SWS_Pwm_10083] */
#if ( ( PWM_SET_PERIOD_AND_DUTY_API != FALSE ) || \
      ( PWM_SET_DUTY_CYCLE_API != FALSE )      || \
      ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) )
typedef void ( *Pwm_70_HW_SetPeriodAndDutyFuncType )( const Pwm_70_ChannelInfoType* chInfoPtr );
#endif  /* #if ( PWM_SET_PERIOD_AND_DUTY_API != FALSE ) */
 
/* [SWS_Pwm_10084] */
#if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE )
typedef void ( *Pwm_70_HW_SetOutputToIdleFuncType )( const Pwm_70_ChannelInfoType* chInfoPtr );
#endif  /* #if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) */
 
/* [SWS_Pwm_10085] */
#if ( PWM_GET_OUTPUT_STATE_API != FALSE )
typedef Pwm_OutputStateType ( *Pwm_70_HW_GetOutputStateFuncType )( const Pwm_70_ChannelInfoType* chInfoPtr );
#endif  /* #if ( PWM_GET_OUTPUT_STATE_API != FALSE ) */
 
typedef void ( *Pwm_70_HW_ClrIntFuncType)( const Pwm_70_ChannelInfoType* chInfoPtr );
 
/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"
 
static const Pwm_70_HW_StartChannelFuncType
s_PwmHwStartChannelFuncTbl[ PWM_70_HW_TIMERTYPE_NUM ] = {
    ( Pwm_70_HW_StartChannelFuncType ) &Pwm_70_RL78F2X_TAU_StartChannel,
    ( Pwm_70_HW_StartChannelFuncType ) &Pwm_70_RL78F2X_TRD_StartChannel
};
 
/* [SWS_Pwm_10080] */
#if ( PWM_DE_INIT_API != FALSE )
static const Pwm_70_HW_StopChannelFuncType
s_PwmHwStopChannelFuncTbl[ PWM_70_HW_TIMERTYPE_NUM ] = {
    ( Pwm_70_HW_StopChannelFuncType ) &Pwm_70_RL78F2X_TAU_StopChannel,
    ( Pwm_70_HW_StopChannelFuncType ) &Pwm_70_RL78F2X_TRD_StopChannel
};
#endif  /* #if ( PWM_DE_INIT_API != FALSE )  */
 
/* [SWS_Pwm_10082] */
#if ( PWM_SET_DUTY_CYCLE_API != FALSE )
static const Pwm_70_HW_SetDutyCycleFuncType
s_PwmHwSetDutyCycleFuncTbl[ PWM_70_HW_TIMERTYPE_NUM ] = {
    ( Pwm_70_HW_SetDutyCycleFuncType ) &Pwm_70_RL78F2X_TAU_SetDutyCycle,
    ( Pwm_70_HW_SetDutyCycleFuncType ) &Pwm_70_RL78F2X_TRD_SetDutyCycle
};
#endif  /* #if ( PWM_SET_DUTY_CYCLE_API != FALSE ) */
 
/* [SWS_Pwm_10083] */
#if ( PWM_SET_PERIOD_AND_DUTY_API != FALSE )
static const Pwm_70_HW_SetPeriodAndDutyFuncType
s_PwmHwSetPeriodAndDutyFuncTbl[ PWM_70_HW_TIMERTYPE_NUM ] = {
    ( Pwm_70_HW_SetPeriodAndDutyFuncType ) &Pwm_70_RL78F2X_TAU_SetPeriodAndDuty,
    ( Pwm_70_HW_SetPeriodAndDutyFuncType ) &Pwm_70_RL78F2X_TRD_SetPeriodAndDuty
};
#endif  /* #if ( PWM_SET_PERIOD_AND_DUTY_API != FALSE ) */
 
/* [SWS_Pwm_10084] */
#if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE )
static const Pwm_70_HW_SetOutputToIdleFuncType
s_PwmHwSetOutputToIdleFuncTbl[ PWM_70_HW_TIMERTYPE_NUM ] = {
    ( Pwm_70_HW_SetOutputToIdleFuncType ) &Pwm_70_RL78F2X_TAU_SetOutputToIdle,
    ( Pwm_70_HW_SetOutputToIdleFuncType ) &Pwm_70_RL78F2X_TRD_SetOutputToIdle
};
#endif  /* #if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) */
 
/* [SWS_Pwm_10085] */
#if ( PWM_GET_OUTPUT_STATE_API != FALSE )
static const Pwm_70_HW_GetOutputStateFuncType
s_PwmHwGetOutputStateFuncTbl[ PWM_70_HW_TIMERTYPE_NUM ] = {
    ( Pwm_70_HW_GetOutputStateFuncType ) &Pwm_70_RL78F2X_TAU_GetOutputState,
    ( Pwm_70_HW_GetOutputStateFuncType ) &Pwm_70_RL78F2X_TRD_GetOutputState
};
#endif  /* #if ( PWM_GET_OUTPUT_STATE_API != FALSE ) */
 
static const Pwm_70_HW_ClrIntFuncType
s_PwmHwClrIntFuncTbl[PWM_70_HW_TIMERTYPE_NUM] = {
    ( Pwm_70_HW_ClrIntFuncType) NULL_PTR,
    ( Pwm_70_HW_ClrIntFuncType) &Pwm_70_RL78F2X_TRD_ClrInt
};
 
#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define PWM_START_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_HW_StartChannel                                       */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : None                                                         */
/* Contents    : Pwm Set Initialize                                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Pwm_70_HW_StartChannel( const Pwm_70_ChannelInfoType* chInfoPtr, Pwm_OutputStateType setActiveLevel )
{
    Pwm_70_HW_StartChannelFuncType  startChannelFuncPtr;
   
    /* get function for timer type */
    startChannelFuncPtr =
        s_PwmHwStartChannelFuncTbl[ chInfoPtr->setChInfoPtr->timerType ];
    /* call function for timer type */
    ( startChannelFuncPtr )( chInfoPtr, setActiveLevel );
}
 
/* [SWS_Pwm_10080]*/
#if ( PWM_DE_INIT_API != FALSE )
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_HW_StopChannel                                        */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : None                                                         */
/* Contents    : Pwm Set deInitialize                                         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Pwm_70_HW_StopChannel( const Pwm_70_ChannelInfoType* chInfoPtr )
{
    Pwm_70_HW_StopChannelFuncType   stopChannelFuncPtr;
   
    /* get function for timer type */
    stopChannelFuncPtr =
        s_PwmHwStopChannelFuncTbl[ chInfoPtr->setChInfoPtr->timerType ];
    /* call function for timer type */
    ( stopChannelFuncPtr )( chInfoPtr );
}
#endif  /* #if ( PWM_DE_INIT_API != FALSE )  */
 
/* [SWS_Pwm_10082] */
#if ( PWM_SET_DUTY_CYCLE_API != FALSE )
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_HW_SetDutyCycle                                       */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : None                                                         */
/* Contents    : Pwm Set Duty Cycle                                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Pwm_70_HW_SetDutyCycle( const Pwm_70_ChannelInfoType* chInfoPtr )
{
    Pwm_70_HW_SetDutyCycleFuncType  setDutyCycleFuncPtr;
 
    /* get function for timer type */
    setDutyCycleFuncPtr =
        s_PwmHwSetDutyCycleFuncTbl[ chInfoPtr->setChInfoPtr->timerType ];
    /* call function for timer type */
    ( setDutyCycleFuncPtr )( chInfoPtr );
}
#endif  /* #if ( PWM_SET_DUTY_CYCLE_API != FALSE ) */
 
/* [SWS_Pwm_10083] */
#if ( PWM_SET_PERIOD_AND_DUTY_API != FALSE )
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_HW_SetPeriodAndDuty                                   */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : None                                                         */
/* Contents    : Pwm Set Duty Cycle and Period                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Pwm_70_HW_SetPeriodAndDuty( const Pwm_70_ChannelInfoType* chInfoPtr )
{
    Pwm_70_HW_SetPeriodAndDutyFuncType  setPeriodAndDutyFuncPtr;
 
    /* get function for timer type */
    setPeriodAndDutyFuncPtr =
        s_PwmHwSetPeriodAndDutyFuncTbl[ chInfoPtr->setChInfoPtr->timerType ];
    /* call function for timer type */
    ( setPeriodAndDutyFuncPtr )( chInfoPtr );
}
#endif  /* #if ( PWM_SET_PERIOD_AND_DUTY_API != FALSE ) */
 
/* [SWS_Pwm_10084] */
#if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE )
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_HW_SetOutputToIdle                                    */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : None                                                         */
/* Contents    : Pwm Set Output to Idle                                       */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Pwm_70_HW_SetOutputToIdle( Pwm_70_ChannelInfoType* chInfoPtr )
{
    Pwm_70_HW_SetOutputToIdleFuncType   setOutputToIdleFuncPtr;
   
    /* Set duty cycle to 0% or 100% to out put the idle status */
    if ( chInfoPtr->activeLevel == chInfoPtr->idleState ) {
        chInfoPtr->duty = chInfoPtr->period;
    } else {
        chInfoPtr->duty = 0U;
    }
 
    /* get function for timer type */
    setOutputToIdleFuncPtr =
        s_PwmHwSetOutputToIdleFuncTbl[ chInfoPtr->setChInfoPtr->timerType ];
    /* call function for timer type */
    ( setOutputToIdleFuncPtr )( chInfoPtr );
}
#endif  /* #if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) */
 
/* [SWS_Pwm_10085] */
#if ( PWM_GET_OUTPUT_STATE_API != FALSE )
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_HW_GetOutputState                                     */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : Current state of PWM waveform(PWM_HIGH or PWM_LOW)           */
/* Contents    : Pwm Get Output State                                         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Pwm_OutputStateType Pwm_70_HW_GetOutputState( const Pwm_70_ChannelInfoType* chInfoPtr )
{
    Pwm_70_HW_GetOutputStateFuncType    getOutputStateFuncPtr;
 
    /* get function for timer type */
    getOutputStateFuncPtr =
        s_PwmHwGetOutputStateFuncTbl[ chInfoPtr->setChInfoPtr->timerType ];
    /* call function for timer type */
    return ( getOutputStateFuncPtr )( chInfoPtr );
}
#endif  /* #if ( PWM_GET_OUTPUT_STATE_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_PWM (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_HW_ClrInt                                             */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : None                                                         */
/* Contents    : Set Timer Counter Register to stop                           */
/* Author      : --                                                           */
/* Note        : The interrupt flag is automatically reset in TAU,            */
/*               but not in TRD,                                              */
/*               so execute the Pwm_70_RL78F2X_TRD_ClrInt function.           */
/*----------------------------------------------------------------------------*/
void Pwm_70_HW_ClrInt( const Pwm_70_ChannelInfoType* chInfoPtr )
{
    Pwm_70_HW_ClrIntFuncType clrIntFuncPtr;
 
    /* get function for timer type */
    clrIntFuncPtr = s_PwmHwClrIntFuncTbl[ chInfoPtr->setChInfoPtr->timerType ];
    /* call function for timer type */
    if ( (Pwm_70_HW_ClrIntFuncType)NULL_PTR != clrIntFuncPtr) {
        /* Interrupt flags are not automatically reset in TRD, so perform interrupt flag reset processing. */
        ( clrIntFuncPtr )( chInfoPtr );
    } else {
        /* Do nothing, Interrupt flags are automatically reset in TAU */
    }
}
 
#define PWM_STOP_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"
 
/* EOF Pwm_70_HW.c ************************************************************/
 