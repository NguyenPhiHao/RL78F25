/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Gpt_70_HW_Types.h                                            */
/* Version     : v1.00.00                                                     */
/* Contents    : GPT Module type definition header                            */
/*               The GPT is a basic software module at the service            */
/*               layer of the standardized basic software                     */
/*               architecture of AUTOSAR.                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of GPT Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef GPT_70_HW_TYPES_H_
#define GPT_70_HW_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Gpt_Cfg.h"
#include "Gpt_70_RL78F2X_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define GPT_70_VENDOR_ID_HW_TYPES_H           ( 70U )
#define GPT_70_MODULE_ID_HW_TYPES_H           (100U)

#define GPT_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H   ( 22U )
#define GPT_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H   ( 11U )
#define GPT_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H(  0U )

#define GPT_70_SW_MAJOR_VERSION_HW_TYPES_H     ( 1U )
#define GPT_70_SW_MINOR_VERSION_HW_TYPES_H     ( 0U )
#define GPT_70_SW_PATCH_VERSION_HW_TYPES_H     ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H != STD_TYPES_AR_RELEASE_MINOR_VERSION ) )
# error "AUTOSAR Version Numbers of Gpt_70_HW_Types.h and Std_Types.h are different"
#endif

/* Std_Types.h version check end */

/* Gpt_Cfg.h version check start */
#if ( GPT_70_VENDOR_ID_HW_TYPES_H   != GPT_70_VENDOR_ID_CFG_H )
# error "VENDOR ID for Gpt_70_HW_Types.h and Gpt_Cfg.h are different"
#endif

#if ( GPT_70_MODULE_ID_HW_TYPES_H   != GPT_70_MODULE_ID_CFG_H )
# error "MODULE ID for Gpt_70_HW_Types.h and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H    != GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_H   ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H    != GPT_70_AR_RELEASE_MINOR_VERSION_CFG_H   ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H != GPT_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
# error "AUTOSAR Version Numbers of Gpt_70_HW_Types.h and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_70_SW_MAJOR_VERSION_HW_TYPES_H != GPT_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_MINOR_VERSION_HW_TYPES_H != GPT_70_SW_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_PATCH_VERSION_HW_TYPES_H != GPT_70_SW_PATCH_VERSION_CFG_H ) )
# error "Software Version Numbers of Gpt_70_HW_Types.h and Gpt_Cfg.h are different"
#endif
/* Gpt_Cfg.h version check end */

/* Gpt_70_RL78F2X_Types.h version check start */
#if ( GPT_70_VENDOR_ID_HW_TYPES_H   != GPT_70_VENDOR_ID_RL78F2X_TYPES_H )
# error "VENDOR ID for Gpt_70_HW_Types.h and Gpt_70_RL78F2X_Types.h are different"
#endif

#if ( GPT_70_MODULE_ID_HW_TYPES_H   != GPT_70_MODULE_ID_RL78F2X_TYPES_H )
# error "MODULE ID for Gpt_70_HW_Types.h and Gpt_70_RL78F2X_Types.h are different"
#endif

#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H    != GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H   ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H    != GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H   ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H != GPT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H ) )
# error "AUTOSAR Version Numbers of Gpt_70_HW_Types.h and Gpt_70_RL78F2X_Types.h are different"
#endif

#if ( ( GPT_70_SW_MAJOR_VERSION_HW_TYPES_H != GPT_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( GPT_70_SW_MINOR_VERSION_HW_TYPES_H != GPT_70_SW_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( GPT_70_SW_PATCH_VERSION_HW_TYPES_H != GPT_70_SW_PATCH_VERSION_RL78F2X_TYPES_H ) )
# error "Software Version Numbers of Gpt_70_HW_Types.h and Gpt_70_RL78F2X_Types.h are different"
#endif

/* Gpt_70_RL78F2X_Types.h version check end */

#define GPT_70_CHANNEL_TICK_VALUE_MAX    ( MCL_70_CHANNEL_TICK_VALUE_MAX_16 )

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/* H/W dependent timer setting register/bit definition wrapper type */
typedef Gpt_70_HW_RL78F2X_SettingConfType   Gpt_70_HW_Timer_SettingConfType;

#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
/* [ECUC_Gpt_00183] Gpt Driver Configuration */
typedef Gpt_70_RL78F2X_PredefTimerConfType  Gpt_70_HW_PredefTimerConfType;
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */

/*----------------------------------------------------------------------------*/
/* external variables                                                         */                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

#endif /* #ifndef GPT_70_HW_TYPES_H_ */

/* EOF Gpt_70_HW_Types.h ****************************************/
