/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Gpt_70_HW.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : GPT Module wrapper                                           */
/*               The GPT is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of GPT Driver                                                */
/* R22-11                                                                     */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Gpt_Cfg.h"
#include "Gpt_70_HW.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define GPT_70_VENDOR_ID_HW_C                   ( 70U )
#define GPT_70_MODULE_ID_HW_C                   ( 100U )
 
#define GPT_70_AR_RELEASE_MAJOR_VERSION_HW_C    ( 22U )
#define GPT_70_AR_RELEASE_MINOR_VERSION_HW_C    ( 11U )
#define GPT_70_AR_RELEASE_REVISION_VERSION_HW_C ( 0U )
 
#define GPT_70_SW_MAJOR_VERSION_HW_C            ( 1U )
#define GPT_70_SW_MINOR_VERSION_HW_C            ( 0U )
#define GPT_70_SW_PATCH_VERSION_HW_C            ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
 
/* Gpt_Cfg.h version check start */
 
#if ( GPT_70_VENDOR_ID_HW_C != GPT_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Gpt_70_HW.c and Gpt_Cfg.h are different"
#endif
 
#if ( GPT_70_MODULE_ID_HW_C != GPT_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Gpt_70_HW.c and Gpt_Cfg.h are different"
#endif
 
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_HW_C    != GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_HW_C    != GPT_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_HW_C != GPT_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Gpt_70_HW.c and Gpt_Cfg.h are different"
#endif
 
#if ( ( GPT_70_SW_MAJOR_VERSION_HW_C != GPT_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_MINOR_VERSION_HW_C != GPT_70_SW_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_PATCH_VERSION_HW_C != GPT_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Gpt_70_HW.c and Gpt_Cfg.h are different"
#endif
 
/* Gpt_Cfg.h version check end */
 
/* Gpt_70_HW.h version check start */
 
#if ( GPT_70_VENDOR_ID_HW_C != GPT_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Gpt_70_HW.c and Gpt_70_HW.h are different"
#endif
 
#if ( GPT_70_MODULE_ID_HW_C != GPT_70_MODULE_ID_HW_H )
    #error "MODULE ID for Gpt_70_HW.c and Gpt_70_HW.h are different"
#endif
 
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_HW_C    != GPT_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_HW_C    != GPT_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_HW_C != GPT_70_AR_RELEASE_REVISION_VERSION_HW_H ) \
    )
    #error "AUTOSAR Version Numbers of Gpt_70_HW.c and Gpt_70_HW.h are different"
#endif
 
#if ( ( GPT_70_SW_MAJOR_VERSION_HW_C != GPT_70_SW_MAJOR_VERSION_HW_H ) || \
      ( GPT_70_SW_MINOR_VERSION_HW_C != GPT_70_SW_MINOR_VERSION_HW_H ) || \
      ( GPT_70_SW_PATCH_VERSION_HW_C != GPT_70_SW_PATCH_VERSION_HW_H ) \
    )
    #error "Software Version Numbers of Gpt_70_HW.c and Gpt_70_HW.h are different"
#endif
 
/* Gpt_70_HW.h version check end */
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef void ( *Gpt_70_HW_InitFuncType )( const Gpt_70_HW_Timer_SettingConfType* confPtr );
 
#if ( GPT_DEINIT_API != FALSE )
typedef void ( *Gpt_70_HW_DeInitFuncType )( const Gpt_70_HW_Timer_SettingConfType* confPtr );
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
 
typedef void ( *Gpt_70_HW_StartTimerFuncType )( const Gpt_70_HW_Timer_SettingConfType* confPtr,
                                                    Gpt_ValueType value );
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
typedef void ( *Gpt_70_HW_StartFreeRunFuncType )( const Gpt_70_HW_Timer_SettingConfType* confPtr );
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
typedef void ( *Gpt_70_HW_StopTimerFuncType )( const Gpt_70_HW_Timer_SettingConfType* confPtr );
 
#if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) )
typedef Gpt_ValueType ( *Gpt_70_HW_GetTimeElapsedFuncType )( const Gpt_70_HW_Timer_SettingConfType* confPtr,
                                                    Gpt_ValueType targetValue );
#endif /* #if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) ) */
 
#if ( GPT_TIME_REMAINING_API != FALSE )
typedef Gpt_ValueType ( *Gpt_70_HW_GetTimeRemainingFuncType )( const Gpt_70_HW_Timer_SettingConfType* confPtr,
                                                    Gpt_ValueType targetValue );
#endif /* #if ( GPT_TIME_REMAINING_API != FALSE ) */
 
typedef void ( *Gpt_70_HW_ClrIntFuncType )( const Gpt_70_HW_Timer_SettingConfType* confPtr );
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* predef timer start value for TAU ( same as TRJ/TRD ) */
#define GPT_70_HW_PREDEF_START_VALUE       ( GPT_70_TAU_PREDEF_START_VALUE )
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* const                                                                      */
/*----------------------------------------------------------------------------*/
#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"
 
/* function table for timer type */
static const Gpt_70_HW_InitFuncType s_GptHwInitFuncTbl[ GPT_70_RL78F2X_TIMERTYPE_NUM ] = {
    ( Gpt_70_HW_InitFuncType )Gpt_70_RL78F2X_TAU_Init,
    ( Gpt_70_HW_InitFuncType )Gpt_70_RL78F2X_TRJ_Init,
    ( Gpt_70_HW_InitFuncType )Gpt_70_RL78F2X_TRD_Init
};
 
#if ( GPT_DEINIT_API != FALSE )
static const Gpt_70_HW_DeInitFuncType s_GptHwDeInitFuncTbl[ GPT_70_RL78F2X_TIMERTYPE_NUM ] = {
    ( Gpt_70_HW_DeInitFuncType )Gpt_70_RL78F2X_TAU_DeInit,
    ( Gpt_70_HW_DeInitFuncType )Gpt_70_RL78F2X_TRJ_DeInit,
    ( Gpt_70_HW_DeInitFuncType )Gpt_70_RL78F2X_TRD_DeInit
};
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
 
static const Gpt_70_HW_StartTimerFuncType s_GptHwStartTimerFuncTbl[ GPT_70_RL78F2X_TIMERTYPE_NUM ] = {
    ( Gpt_70_HW_StartTimerFuncType )Gpt_70_RL78F2X_TAU_StartTimer,
    ( Gpt_70_HW_StartTimerFuncType )Gpt_70_RL78F2X_TRJ_StartTimer,
    ( Gpt_70_HW_StartTimerFuncType )Gpt_70_RL78F2X_TRD_StartTimer
};
 
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
static const Gpt_70_HW_StartFreeRunFuncType s_GptHwStartFreeRunFuncTbl[ GPT_70_RL78F2X_TIMERTYPE_NUM ] = {
    ( Gpt_70_HW_StartFreeRunFuncType )Gpt_70_RL78F2X_TAU_StartFreeRun,
    ( Gpt_70_HW_StartFreeRunFuncType )Gpt_70_RL78F2X_TRJ_StartFreeRun,
    ( Gpt_70_HW_StartFreeRunFuncType )Gpt_70_RL78F2X_TRD_StartFreeRun
};
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
static const Gpt_70_HW_StopTimerFuncType s_GptHwStopTimerFuncTbl[ GPT_70_RL78F2X_TIMERTYPE_NUM ] = {
    ( Gpt_70_HW_StopTimerFuncType )Gpt_70_RL78F2X_TAU_StopTimer,
    ( Gpt_70_HW_StopTimerFuncType )Gpt_70_RL78F2X_TRJ_StopTimer,
    ( Gpt_70_HW_StopTimerFuncType )Gpt_70_RL78F2X_TRD_StopTimer
};
 
#if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) )
static const Gpt_70_HW_GetTimeElapsedFuncType s_GptHwGetTimeElapsedFuncTbl[ GPT_70_RL78F2X_TIMERTYPE_NUM ] = {
    ( Gpt_70_HW_GetTimeElapsedFuncType )Gpt_70_RL78F2X_TAU_GetTimeElapsed,
    ( Gpt_70_HW_GetTimeElapsedFuncType )Gpt_70_RL78F2X_TRJ_GetTimeElapsed,
    ( Gpt_70_HW_GetTimeElapsedFuncType )Gpt_70_RL78F2X_TRD_GetTimeElapsed
};
#endif /* #if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) ) */
 
#if ( GPT_TIME_REMAINING_API != FALSE )
static const Gpt_70_HW_GetTimeRemainingFuncType s_GptHwGetTimeRemainingFuncTbl[ GPT_70_RL78F2X_TIMERTYPE_NUM ] = {
    ( Gpt_70_HW_GetTimeRemainingFuncType )Gpt_70_RL78F2X_TAU_GetTimeRemaining,
    ( Gpt_70_HW_GetTimeRemainingFuncType )Gpt_70_RL78F2X_TRJ_GetTimeRemaining,
    ( Gpt_70_HW_GetTimeRemainingFuncType )Gpt_70_RL78F2X_TRD_GetTimeRemaining
};
#endif /* #if ( GPT_TIME_REMAINING_API != FALSE ) */
 
static const Gpt_70_HW_ClrIntFuncType s_GptHwClrIntFuncTbl[ GPT_70_RL78F2X_TIMERTYPE_NUM ] = {
    ( Gpt_70_HW_ClrIntFuncType )NULL_PTR,
    ( Gpt_70_HW_ClrIntFuncType )NULL_PTR,
    ( Gpt_70_HW_ClrIntFuncType )Gpt_70_RL78F2X_TRD_ClrInt
};
 
#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#define GPT_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Gpt_MemMap.h"
 
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
static const Gpt_70_HW_PredefTimerConfType* s_GptPredefTimerConfPtr = NULL_PTR;
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
#define GPT_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Gpt_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define GPT_START_SEC_CODE_LOCAL
#include "Gpt_MemMap.h"
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_HW_Init                                               */
/* Param       : (in) confPtr Configuration of channel                        */
/* Return      : E_OK      Initializes this module normal.                    */
/* Contents    : Set Timer for initialization.                                */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00280]                                              */
/*----------------------------------------------------------------------------*/
Std_ReturnType Gpt_70_HW_Init( const Gpt_70_HW_Timer_SettingConfType* confPtr )
{
    Std_ReturnType retval;
    Gpt_70_HW_InitFuncType initFuncPtr;
 
    /* get function for timer type */
    initFuncPtr = s_GptHwInitFuncTbl[ confPtr->timerType ];
    /* call function for timer type */
    ( initFuncPtr )( confPtr );
 
    retval = E_OK;
    return retval;
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_HW_DeInit                                             */
/* Param       : (in) confPtr Configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer for de-initialization.                             */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00309]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_DEINIT_API != FALSE )
void Gpt_70_HW_DeInit( const Gpt_70_HW_Timer_SettingConfType* confPtr )
{
    Gpt_70_HW_DeInitFuncType deInitFuncPtr;
 
    /* get function for timer type */
    deInitFuncPtr =
        s_GptHwDeInitFuncTbl[ confPtr->timerType ];
    /* call function for timer type */
    ( deInitFuncPtr )( confPtr );
}
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_HW_StartTimer                                         */
/* Param       : (in) confPtr Configuration of channel                        */
/*             : (in) value   Target time in number of Ticks.                 */
/* Return      : None                                                         */
/* Contents    : Set Timer to start with (value-1).                           */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00284]                                              */
/*----------------------------------------------------------------------------*/
void Gpt_70_HW_StartTimer( const Gpt_70_HW_Timer_SettingConfType* confPtr, Gpt_ValueType value)
{
    Gpt_70_HW_StartTimerFuncType startTimerFuncPtr;
 
    /* get function for timer type */
    startTimerFuncPtr =
        s_GptHwStartTimerFuncTbl[ confPtr->timerType ];
    /* call function for timer type */
    ( startTimerFuncPtr )( confPtr, value );
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_HW_StartFreeRun                                       */
/* Param       : (in) confPtr Configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer to start free run (start with 0xFFFF).             */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00284]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
void Gpt_70_HW_StartFreeRun( const Gpt_70_HW_Timer_SettingConfType* confPtr )
{
    Gpt_70_HW_StartFreeRunFuncType startFreeRunFuncPtr;
 
    /* get function for timer type */
    startFreeRunFuncPtr =
        s_GptHwStartFreeRunFuncTbl[ confPtr->timerType ];
    /* call function for timer type */
    ( startFreeRunFuncPtr )( confPtr );
}
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_HW_StopTimer                                          */
/* Param       : (in) confPtr Configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer Counter Register to stop                           */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00285]                                              */
/*----------------------------------------------------------------------------*/
void Gpt_70_HW_StopTimer( const Gpt_70_HW_Timer_SettingConfType* confPtr )
{
    Gpt_70_HW_StopTimerFuncType stopTimerFuncPtr;
 
    /* get function for timer type */
    stopTimerFuncPtr =
        s_GptHwStopTimerFuncTbl[ confPtr->timerType ];
    /* call function for timer type */
    ( stopTimerFuncPtr )( confPtr );
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_HW_GetTimeElapsed                                     */
/* Param       : (in) confPtr Configuration of channel                        */
/*             : (in) targetValue target value of channel                     */
/* Return      : Elapsed Timer Value.                                         */
/* Contents    : Get Elapsed Time(register value)                             */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00282]                                              */
/*----------------------------------------------------------------------------*/
#if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) )
Gpt_ValueType Gpt_70_HW_GetTimeElapsed( const Gpt_70_HW_Timer_SettingConfType* confPtr, Gpt_ValueType targetValue )
{
    Gpt_70_HW_GetTimeElapsedFuncType getTimeElapsedFuncPtr;
 
    /* get function for timer type */
    getTimeElapsedFuncPtr =
        s_GptHwGetTimeElapsedFuncTbl[ confPtr->timerType ];
    /* call function for timer type */
    return ( getTimeElapsedFuncPtr )( confPtr, targetValue );
}
#endif /* #if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_HW_GetTimeRemaining                                   */
/* Param       : (in) confPtr Configuration of channel                        */
/*             : (in) targetValue target value of channel                     */
/* Return      : Remaining Timer Value.                                       */
/* Contents    : Get Remaining Time(register value)                           */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00283]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_TIME_REMAINING_API != FALSE )
Gpt_ValueType Gpt_70_HW_GetTimeRemaining( const Gpt_70_HW_Timer_SettingConfType* confPtr, Gpt_ValueType targetValue )
{
    Gpt_70_HW_GetTimeRemainingFuncType getTimeRemainingFuncPtr;
 
    /* get function for timer type */
    getTimeRemainingFuncPtr =
        s_GptHwGetTimeRemainingFuncTbl[ confPtr->timerType ];
    /* call function for timer type */
    return ( getTimeRemainingFuncPtr )( confPtr, targetValue );
}
#endif /* #if ( GPT_TIME_REMAINING_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_HW_ClrInt                                             */
/* Param       : (in) confPtr Configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Clear interrupt flag                                         */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
void Gpt_70_HW_ClrInt( const Gpt_70_HW_Timer_SettingConfType* confPtr )
{
    Gpt_70_HW_ClrIntFuncType clrIntFuncPtr;
 
    /* get function for timer type */
    clrIntFuncPtr = s_GptHwClrIntFuncTbl[ confPtr->timerType ];
    /* call function for timer type */
    if ( ( Gpt_70_HW_ClrIntFuncType )NULL_PTR != clrIntFuncPtr) {
        ( clrIntFuncPtr )( confPtr );
    }
}
 
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_HW_InitPredefTimer                                    */
/* Param       : (in) predefConfPtr Configuration for predef timer.           */
/* Return      : None                                                         */
/* Contents    : Initialize timer channel for predef timer.                   */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00280]                                              */
/*----------------------------------------------------------------------------*/
void Gpt_70_HW_InitPredefTimer( const Gpt_70_HW_PredefTimerConfType* predefConfPtr )
{
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED )
#if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE )
    /* Initialize 1us timer */
    ( void )Gpt_70_HW_Init( ( const Gpt_70_HW_Timer_SettingConfType* )( predefConfPtr->channelConf1us ) );
#endif /* #if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE ) */
    /* Initialize lower timer */
    ( void )Gpt_70_HW_Init( ( const Gpt_70_HW_Timer_SettingConfType* )( predefConfPtr->channelConfLower ) );
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED )
    /* Initialize higher timer */
    ( void )Gpt_70_HW_Init( ( const Gpt_70_HW_Timer_SettingConfType* )( predefConfPtr->channelConfHigher ) );
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED ) */
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED ) */
#if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE )
    /* Initialize 100us timer */
    ( void )Gpt_70_HW_Init( ( const Gpt_70_HW_Timer_SettingConfType* )( predefConfPtr->channelConf100us ) );
    /* Initialize 100us lower timer */
    ( void )Gpt_70_HW_Init( ( const Gpt_70_HW_Timer_SettingConfType* )( predefConfPtr->channelConfLower100us ) );
    /* Initialize 100us higher timer */
    ( void )Gpt_70_HW_Init( ( const Gpt_70_HW_Timer_SettingConfType* )( predefConfPtr->channelConfHigher100us ) );
#endif /* #if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) */
    /* Initialize ELC */
    Gpt_70_RL78F2X_InitPredefTimer( ( const Gpt_70_RL78F2X_PredefTimerConfType* )( predefConfPtr ) );
    /* save parameter */
    s_GptPredefTimerConfPtr = predefConfPtr;
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_HW_DeInitPredefTimer                                  */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : Deinitialize timer channel for predef timer.                 */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00309]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_DEINIT_API != FALSE )
void Gpt_70_HW_DeInitPredefTimer( void )
{
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED )
#if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE )
    /* Deinitialize 1us timer */
    Gpt_70_HW_DeInit( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConf1us ) );
#endif /* #if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE ) */
    /* Deinitialize lower timer */
    Gpt_70_HW_DeInit( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConfLower ) );
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED )
    /* Deinitialize higher timer */
    Gpt_70_HW_DeInit( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConfHigher ) );
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED ) */
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED ) */
#if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE )
    /* Deinitialize 10us timer */
    Gpt_70_HW_DeInit( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConf100us ) );
    /* Deinitialize 100us lower timer */
    Gpt_70_HW_DeInit( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConfLower100us ) );
    /* Deinitialize 100us higher timer */
    Gpt_70_HW_DeInit( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConfHigher100us ) );
#endif /* #if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) */
    /* Deinitialize ELC */
    Gpt_70_RL78F2X_DeInitPredefTimer( s_GptPredefTimerConfPtr );
    /* clear parameter */
    s_GptPredefTimerConfPtr = NULL_PTR;
}
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_HW_StartPredefTimer                                   */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : Start timer channel for predef timer.                        */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00390]                                              */
/*----------------------------------------------------------------------------*/
void Gpt_70_HW_StartPredefTimer( void )
{
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED )
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED )
    /* Start higher timer with value 0xFFFF */
    Gpt_70_HW_StartFreeRun( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConfHigher ) );
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED ) */
    /* Start lower timer with value 0xFFFF */
    Gpt_70_HW_StartFreeRun( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConfLower ) );
#if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE )
    /* Start 1us timer with configuard value-1 */
    Gpt_70_HW_StartTimer( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConf1us ), s_GptPredefTimerConfPtr->timerValue1us );
#endif /* #if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE ) */
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED ) */
#if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE )
    /* Start 100us higher with value 0xFFFF timer */
    Gpt_70_HW_StartFreeRun( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConfHigher100us ) );
    /* Start 100us lower timer with value 0xFFFF */
    Gpt_70_HW_StartFreeRun( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConfLower100us ) );
    /* Start 100us timer with configuard value-1 */
    Gpt_70_HW_StartTimer( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConf100us ), s_GptPredefTimerConfPtr->timerValue100us );
#endif /* #if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) */
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_HW_StopPredefTimer                                    */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : Stop timer channel for predef timer.                         */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00391]                                              */
/*----------------------------------------------------------------------------*/
void Gpt_70_HW_StopPredefTimer( void )
{
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED )
#if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE )
    /* Stop 1us timer */
    Gpt_70_HW_StopTimer( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConf1us ) );
#endif /* #if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE ) */
    /* Stop lower timer */
    Gpt_70_HW_StopTimer( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConfLower ) );
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED )
    /* Stop higher timer */
    Gpt_70_HW_StopTimer( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConfHigher ) );
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED ) */
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED ) */
#if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE )
    /* Stop 100us timer */
    Gpt_70_HW_StopTimer( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConf100us ) );
    /* Stop 100us lower timer */
    Gpt_70_HW_StopTimer( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConfLower100us ) );
    /* Stop 100us higher timer */
    Gpt_70_HW_StopTimer( ( const Gpt_70_HW_Timer_SettingConfType* )( s_GptPredefTimerConfPtr->channelConfHigher100us ) );
#endif /* #if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) */
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_HW_GetPredefTimerValue                                */
/* Param       : (in) PredefTimer GPT Predef Timer.                           */
/* Return      : value of predef timer                                        */
/* Contents    : Get value of predef timer.                                   */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00394]                                              */
/*----------------------------------------------------------------------------*/
uint32 Gpt_70_HW_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer )
{
    uint32 timValue = 0U;               /* return value */
#if ( ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) || \
      ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED ) || \
      ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED ) )
    uint16 timValueLower1 = 0U;         /* lower value read 1st */
    uint16 timValueHigher1 = 0U;        /* higher value read 1st */
    uint16 timValueLower2 = 0U;         /* lower value read 2nd */
    uint16 timValueHigher2 = 0U;        /* higher value read 2nd */
#endif /* #if ( ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) || \
                ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED ) || \
                ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED ) ) */
 
    if ( GPT_PREDEF_TIMER_1US_16BIT == PredefTimer ) {
        /* read once only for 16bit predef timer */
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED )
        timValue = ( uint32 )Gpt_70_HW_GetTimeElapsed(
            ( const Gpt_70_HW_Timer_SettingConfType* )s_GptPredefTimerConfPtr->channelConfLower, GPT_70_HW_PREDEF_START_VALUE );
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED ) */
 
#if ( ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) || \
      ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED ) || \
      ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED ) )
    } else {
        /* read twice for 24/32bit predef timer */
        if ( GPT_PREDEF_TIMER_100US_32BIT == PredefTimer ) {
            /* get 100us predef timer value */
#if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE )
            /* read 1st value */
            /* get value of lower timer */
            timValueLower1 = Gpt_70_HW_GetTimeElapsed(
                    s_GptPredefTimerConfPtr->channelConfLower100us, GPT_70_HW_PREDEF_START_VALUE );
            /* get value of higher timer */
            timValueHigher1 = Gpt_70_HW_GetTimeElapsed(
                    s_GptPredefTimerConfPtr->channelConfHigher100us, GPT_70_HW_PREDEF_START_VALUE );
            /* read 2nd value */
            /* get value of lower timer */
            timValueLower2 = Gpt_70_HW_GetTimeElapsed(
                    s_GptPredefTimerConfPtr->channelConfLower100us, GPT_70_HW_PREDEF_START_VALUE );
            /* get value of higher timer */
            timValueHigher2 = Gpt_70_HW_GetTimeElapsed(
                    s_GptPredefTimerConfPtr->channelConfHigher100us, GPT_70_HW_PREDEF_START_VALUE );
#endif /* #if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) */
        } else {
            /* get 1us predef timer value */
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED )
            /* read 1st value */
            /* get value of lower timer */
            timValueLower1 = Gpt_70_HW_GetTimeElapsed(
                ( const Gpt_70_HW_Timer_SettingConfType* )s_GptPredefTimerConfPtr->channelConfLower, GPT_70_HW_PREDEF_START_VALUE );
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED )
            /* get value of higher timer */
            timValueHigher1 = Gpt_70_HW_GetTimeElapsed(
                ( const Gpt_70_HW_Timer_SettingConfType* )s_GptPredefTimerConfPtr->channelConfHigher, GPT_70_HW_PREDEF_START_VALUE );
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED ) */
            /* read 2nd value */
            /* get value of lower timer */
            timValueLower2 = Gpt_70_HW_GetTimeElapsed(
                ( const Gpt_70_HW_Timer_SettingConfType* )s_GptPredefTimerConfPtr->channelConfLower, GPT_70_HW_PREDEF_START_VALUE );
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED )
            /* get value of higher timer */
            timValueHigher2 = Gpt_70_HW_GetTimeElapsed(
                ( const Gpt_70_HW_Timer_SettingConfType* )s_GptPredefTimerConfPtr->channelConfHigher, GPT_70_HW_PREDEF_START_VALUE );
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED ) */
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED ) */
        }
        /* overflow has not occurd. */
        if ( timValueLower1 > timValueLower2 ) {
            timValue = ( uint32 )timValueHigher2;
            timValue <<= 16U;
            timValue |= ( uint32 )timValueLower2;
        } else {
            timValue = ( uint32 )timValueHigher1;
            timValue <<= 16U;
            timValue |= ( uint32 )timValueLower1;
        }
#endif /* #if ( ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) || \
                ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED ) || \
                ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED ) ) */
    }
   
    return timValue;
}
 
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
#define GPT_STOP_SEC_CODE_LOCAL
#include "Gpt_MemMap.h"
 
/* EOF Gpt_70_HW.c ************************************************************/
 