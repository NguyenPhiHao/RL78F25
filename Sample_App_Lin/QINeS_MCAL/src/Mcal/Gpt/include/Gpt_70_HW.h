/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Gpt_70_HW.h                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : GPT Module wrapper header                                    */
/*               The GPT is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* Specification of GPT Driver  :                                             */
/* Release     : R22-11                                                       */
/*----------------------------------------------------------------------------*/

#ifndef GPT_70_HW_H_
#define GPT_70_HW_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Gpt_Cfg.h"
#include "Gpt_70_Types.h"
#include "Gpt_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define GPT_70_VENDOR_ID_HW_H                  ( 70U )
#define GPT_70_MODULE_ID_HW_H                  ( 100U )

#define GPT_70_AR_RELEASE_MAJOR_VERSION_HW_H   ( 22U )
#define GPT_70_AR_RELEASE_MINOR_VERSION_HW_H   ( 11U )
#define GPT_70_AR_RELEASE_REVISION_VERSION_HW_H ( 0U )

#define GPT_70_SW_MAJOR_VERSION_HW_H           ( 1U )
#define GPT_70_SW_MINOR_VERSION_HW_H           ( 0U )
#define GPT_70_SW_PATCH_VERSION_HW_H           ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Gpt_Cfg.h version check start */

#if ( GPT_70_VENDOR_ID_HW_H != GPT_70_VENDOR_ID_CFG_H )
#  error "VENDOR ID for Gpt_70_HW.h and Gpt_Cfg.h are different"
#endif

#if ( GPT_70_MODULE_ID_HW_H != GPT_70_MODULE_ID_CFG_H )
#  error "MODULE ID for Gpt_70_HW.h and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_HW_H   != GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_HW_H   != GPT_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_HW_H!= GPT_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
#  error "AUTOSAR Version Numbers of Gpt_70_HW.h and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_70_SW_MAJOR_VERSION_HW_H != GPT_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_MINOR_VERSION_HW_H != GPT_70_SW_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_PATCH_VERSION_HW_H != GPT_70_SW_PATCH_VERSION_CFG_H ) )
#  error "Software Version Numbers of Gpt_70_HW.h and Gpt_Cfg.h are different"
#endif

/* Gpt_Cfg.h version check end  */

/* Gpt_70_Types.h version check start */

#if ( GPT_70_VENDOR_ID_HW_H  != GPT_70_VENDOR_ID_TYPES_H )
#  error "VENDOR ID for Gpt_70_HW.h and Gpt_70_Types.h are different"
#endif

#if ( GPT_70_MODULE_ID_HW_H  != GPT_70_MODULE_ID_TYPES_H )
#  error "MODULE ID for Gpt_70_HW.h and Gpt_70_Types.h are different"
#endif

#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_HW_H   != GPT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_HW_H   != GPT_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_HW_H!= GPT_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) )
#  error "AUTOSAR Version Numbers of Gpt_70_HW.h and Gpt_70_Types.h are different"
#endif

#if ( ( GPT_70_SW_MAJOR_VERSION_HW_H != GPT_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( GPT_70_SW_MINOR_VERSION_HW_H != GPT_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( GPT_70_SW_PATCH_VERSION_HW_H != GPT_70_SW_PATCH_VERSION_TYPES_H ) )
#  error "Software Version Numbers of Gpt_70_HW.h and Gpt_70_Types.h are different"
#endif

/* Gpt_70_Types.h version check end  */

/* Gpt_70_RL78F2X.h version check start */

#if ( GPT_70_VENDOR_ID_HW_H != GPT_70_VENDOR_ID_RL78F2X_H )
#  error "VENDOR ID for Gpt_70_HW.h and Gpt_70_RL78F2X.h are different"
#endif

#if ( GPT_70_MODULE_ID_HW_H != GPT_70_MODULE_ID_RL78F2X_H )
#  error "MODULE ID for Gpt_70_HW.h and Gpt_70_RL78F2X.h are different"
#endif

#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_HW_H    != GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_HW_H    != GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_HW_H != GPT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) )
#  error "AUTOSAR Version Numbers of Gpt_70_HW.h and Gpt_70_RL78F2X.h are different"
#endif

#if ( ( GPT_70_SW_MAJOR_VERSION_HW_H != GPT_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( GPT_70_SW_MINOR_VERSION_HW_H != GPT_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( GPT_70_SW_PATCH_VERSION_HW_H != GPT_70_SW_PATCH_VERSION_RL78F2X_H ) )
#  error "Software Version Numbers of Gpt_70_HW.h and Gpt_70_RL78F2X.h are different"
#endif

/* Gpt_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
#define Gpt_70_HW_Init_CheckConfPredefTimer( conf ) Gpt_70_RL78F2X_Init_CheckConfPredefTimer( ( conf ) )
#endif /*#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )*/

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
/* [SWS_Gpt_00280] */
extern Std_ReturnType Gpt_70_HW_Init( const Gpt_70_HW_Timer_SettingConfType* confPtr );

#if ( GPT_DEINIT_API != FALSE )
/* [SWS_Gpt_00309] */
extern void Gpt_70_HW_DeInit( const Gpt_70_HW_Timer_SettingConfType* confPtr );
#endif /* #if ( GPT_DEINIT_API != FALSE ) */

/* [SWS_Gpt_00284] */
extern void Gpt_70_HW_StartTimer( const Gpt_70_HW_Timer_SettingConfType* confPtr, Gpt_ValueType value );
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
extern void Gpt_70_HW_StartFreeRun( const Gpt_70_HW_Timer_SettingConfType* confPtr );
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
/* [SWS_Gpt_00285] */
extern void Gpt_70_HW_StopTimer( const Gpt_70_HW_Timer_SettingConfType* confPtr );

#if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) )
/* [SWS_Gpt_00282] */
extern Gpt_ValueType Gpt_70_HW_GetTimeElapsed( const Gpt_70_HW_Timer_SettingConfType* confPtr, Gpt_ValueType targetValue );
#endif /* #if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) ) */

#if ( GPT_TIME_REMAINING_API != FALSE )
/* [SWS_Gpt_00283] */
extern Gpt_ValueType Gpt_70_HW_GetTimeRemaining( const Gpt_70_HW_Timer_SettingConfType* confPtr, Gpt_ValueType targetValue );
#endif /* #if ( GPT_TIME_REMAINING_API != FALSE ) */

/* [SWS_Gpt_00206] */
extern void Gpt_70_HW_ClrInt( const Gpt_70_HW_Timer_SettingConfType* confPtr );

#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
/* [SWS_Gpt_00280] */
extern void Gpt_70_HW_InitPredefTimer( const Gpt_70_HW_PredefTimerConfType* predefConfPtr );
#if ( GPT_DEINIT_API != FALSE )
/* [SWS_Gpt_00309] */
extern void Gpt_70_HW_DeInitPredefTimer( void );
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
/* [SWS_Gpt_00390] */
extern void Gpt_70_HW_StartPredefTimer( void );
/* [SWS_Gpt_00391] */
extern void Gpt_70_HW_StopPredefTimer( void );
/* [SWS_Gpt_00394] */
extern uint32 Gpt_70_HW_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer );
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */

#endif /* #ifndef GPT_70_HW_H_ */

/* EOF Gpt_70_HW.h ************************************************************/