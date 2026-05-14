/******************************************************************************/
/* Copyright   : 2023 SCSK Corporation                                        */
/* System Name : AUTOSAR QINeS-Lite MCAL                                      */
/* File Name   : Gpt_70_RL78F2X.h                                             */
/* Version     : v1.00.01                                                     */
/* Contents    : GPT Module HW dependent header                               */
/*               The GPT is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : k.sawada TranNP1 s.oda                                       */
/* Note        : -                                                            */
/******************************************************************************/
/* Specification of GPT Driver                                                */
/* Release R22-11                                                             */
 
#ifndef GPT_70_RL78F2X_H_
#define GPT_70_RL78F2X_H_
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Gpt_Cfg.h"
#include "Gpt_70_Types.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define GPT_70_VENDOR_ID_RL78F2X_H                      ( 70U )
#define GPT_70_MODULE_ID_RL78F2X_H                      ( 100U )
 
#define GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H       ( 22U )
#define GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H       ( 11U )
#define GPT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H    ( 0U )
 
#define GPT_70_SW_MAJOR_VERSION_RL78F2X_H               ( 1U )
#define GPT_70_SW_MINOR_VERSION_RL78F2X_H               ( 0U )
#define GPT_70_SW_PATCH_VERSION_RL78F2X_H               ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Gpt_Cfg.h version check start */
 
#if ( GPT_70_VENDOR_ID_RL78F2X_H != GPT_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Gpt_70_RL78F2X.h and Gpt_Cfg.h are different"
#endif
 
#if ( GPT_70_MODULE_ID_RL78F2X_H != GPT_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Gpt_70_RL78F2X.h and Gpt_Cfg.h are different"
#endif
 
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H    != GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H    != GPT_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != GPT_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Gpt_70_RL78F2X.h and Gpt_Cfg.h are different"
#endif
 
#if ( ( GPT_70_SW_MAJOR_VERSION_RL78F2X_H != GPT_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_MINOR_VERSION_RL78F2X_H != GPT_70_SW_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_PATCH_VERSION_RL78F2X_H != GPT_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Gpt_70_RL78F2X.h and Gpt_Cfg.h are different"
#endif
 
/* Gpt_Cfg.h version check end */
 
/* Gpt_70_Types.h version check start */
 
#if ( GPT_70_VENDOR_ID_RL78F2X_H != GPT_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Gpt_70_RL78F2X.h and Gpt_70_Types.h are different"
#endif
 
#if ( GPT_70_MODULE_ID_RL78F2X_H != GPT_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Gpt_70_RL78F2X.h and Gpt_70_Types.h are different"
#endif
 
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H    != GPT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H    != GPT_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != GPT_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Gpt_70_RL78F2X.h and Gpt_70_Types.h are different"
#endif
 
#if ( ( GPT_70_SW_MAJOR_VERSION_RL78F2X_H != GPT_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( GPT_70_SW_MINOR_VERSION_RL78F2X_H != GPT_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( GPT_70_SW_PATCH_VERSION_RL78F2X_H != GPT_70_SW_PATCH_VERSION_TYPES_H ) \
    )
    #error "Software Version Numbers of Gpt_70_RL78F2X.h and Gpt_70_Types.h are different"
#endif
 
/* Gpt_70_Types.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define GPT_70_TAU_PREDEF_START_VALUE       ( 0xFFFFU )    /* predef timer start value for TAU */
#define GPT_70_TRJ_PREDEF_START_VALUE       ( 0xFFFFU )    /* predef timer start value for TRJ */
#define GPT_70_TRD_PREDEF_START_VALUE       ( 0xFFFFU )    /* predef timer start value for TRD */
 
 
/*----------------------------------------------------------------------------*/
/* H/W dependent definitions                                                  */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* external constant                                                          */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
/* for TAU */
/* [SWS_Gpt_00280] */
extern void Gpt_70_RL78F2X_TAU_Init( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr );
 
#if ( GPT_DEINIT_API != FALSE )
/* [SWS_Gpt_00309] */
extern void Gpt_70_RL78F2X_TAU_DeInit( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr );
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
 
/* [SWS_Gpt_00284] */
extern void Gpt_70_RL78F2X_TAU_StartTimer( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr, Gpt_ValueType value );
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
extern void Gpt_70_RL78F2X_TAU_StartFreeRun( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr );
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
/* [SWS_Gpt_00285] */
extern void Gpt_70_RL78F2X_TAU_StopTimer( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr );
 
#if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) )
/* [SWS_Gpt_00282] */
extern Gpt_ValueType Gpt_70_RL78F2X_TAU_GetTimeElapsed( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr, Gpt_ValueType targetValue );
#endif /* #if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) ) */
 
#if ( GPT_TIME_REMAINING_API != FALSE )
/* [SWS_Gpt_00283] */
extern Gpt_ValueType Gpt_70_RL78F2X_TAU_GetTimeRemaining( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr, Gpt_ValueType targetValue );
#endif /* #if ( GPT_TIME_REMAINING_API != FALSE ) */
 
extern void Gpt_70_RL78F2X_TAU_SelectUnit( uint8 tauUnit );
 
/* for TRJ */
/* [SWS_Gpt_00280] */
extern void Gpt_70_RL78F2X_TRJ_Init( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr );
 
#if ( GPT_DEINIT_API != FALSE )
/* [SWS_Gpt_00309] */
extern void Gpt_70_RL78F2X_TRJ_DeInit( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr );
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
 
/* [SWS_Gpt_00284] */
extern void Gpt_70_RL78F2X_TRJ_StartTimer( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr, Gpt_ValueType value );
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
extern void Gpt_70_RL78F2X_TRJ_StartFreeRun( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr );
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
/* [SWS_Gpt_00285] */
extern void Gpt_70_RL78F2X_TRJ_StopTimer( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr );
 
#if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) )
/* [SWS_Gpt_00282] */
extern Gpt_ValueType Gpt_70_RL78F2X_TRJ_GetTimeElapsed( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr, Gpt_ValueType targetValue );
#endif /* #if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) ) */
 
#if ( GPT_TIME_REMAINING_API != FALSE )
/* [SWS_Gpt_00283] */
extern Gpt_ValueType Gpt_70_RL78F2X_TRJ_GetTimeRemaining( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr, Gpt_ValueType targetValue );
#endif /* #if ( GPT_TIME_REMAINING_API != FALSE ) */
 
/* for TRD */
/* [SWS_Gpt_00280] */
extern void Gpt_70_RL78F2X_TRD_Init( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr );
 
#if ( GPT_DEINIT_API != FALSE )
/* [SWS_Gpt_00309] */
extern void Gpt_70_RL78F2X_TRD_DeInit( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr );
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
 
/* [SWS_Gpt_00284] */
extern void Gpt_70_RL78F2X_TRD_StartTimer( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr, Gpt_ValueType value );
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
extern void Gpt_70_RL78F2X_TRD_StartFreeRun( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr );
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
/* [SWS_Gpt_00285] */
extern void Gpt_70_RL78F2X_TRD_StopTimer( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr );
 
#if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) )
/* [SWS_Gpt_00282] */
extern Gpt_ValueType Gpt_70_RL78F2X_TRD_GetTimeElapsed( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr, Gpt_ValueType targetValue );
#endif /* #if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) ) */
 
#if ( GPT_TIME_REMAINING_API != FALSE )
/* [SWS_Gpt_00283] */
extern Gpt_ValueType Gpt_70_RL78F2X_TRD_GetTimeRemaining( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr, Gpt_ValueType targetValue );
#endif /* #if ( GPT_TIME_REMAINING_API != FALSE ) */
 
/* [SWS_Gpt_00206] */
extern void Gpt_70_RL78F2X_TRD_ClrInt( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr );
 
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
/* [SWS_Gpt_00280] */
extern void Gpt_70_RL78F2X_InitPredefTimer( const Gpt_70_RL78F2X_PredefTimerConfType* predefConfPtr );
#if ( GPT_DEINIT_API != FALSE )
/* [SWS_Gpt_00309] */
extern void Gpt_70_RL78F2X_DeInitPredefTimer( const Gpt_70_RL78F2X_PredefTimerConfType* predefConfPtr );
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
 
extern Std_ReturnType Gpt_70_RL78F2X_Init_CheckConfPredefTimer( const Gpt_70_RL78F2X_PredefTimerConfType* predefConfPtr );
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
#endif /* #ifndef GPT_70_RL78F2X_H_ */
 
/* EOF Gpt_70_RL78F2X.h *******************************************************/