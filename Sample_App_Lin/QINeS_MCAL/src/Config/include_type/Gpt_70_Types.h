/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Gpt_70_Types.h                                               */
/* Version     : v1.00.00                                                     */
/* Contents    : GPT Module type definition header                            */
/*               The GPT is a basic software module at the service layer      */
/*               of the standardized basic software architecture of AUTOSAR.  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of GPT Driver                                                */
/* R22-11                                                                     */

#ifndef GPT_70_TYPES_H
#define GPT_70_TYPES_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Gpt_Cfg.h"
#include "Gpt_70_HW_Types.h"
#include "EcuM_Cbk.h"
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/

#define GPT_70_VENDOR_ID_TYPES_H                    ( 70U )
#define GPT_70_MODULE_ID_TYPES_H                    (100U )

#define GPT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H     (22U )
#define GPT_70_AR_RELEASE_MINOR_VERSION_TYPES_H     (11U )
#define GPT_70_AR_RELEASE_REVISION_VERSION_TYPES_H  ( 0U )

#define GPT_70_SW_MAJOR_VERSION_TYPES_H             ( 1U )
#define GPT_70_SW_MINOR_VERSION_TYPES_H             ( 0U )
#define GPT_70_SW_PATCH_VERSION_TYPES_H             ( 0U )

/* file version checks                                                        */
/* Std_Types.h version check start */
#if   ( GPT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MINOR_VERSION )
    #error "AUTOSAR Version Numbers of Gpt_70_Types.h and Std_Types.h are different"
#endif

/* Std_Types.h version check end */

/* Gpt_Cfg.h version check start */
#if ( GPT_70_VENDOR_ID_TYPES_H    != GPT_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Gpt_70_Types.h and Gpt_Cfg.h are different"
#endif

#if ( GPT_70_MODULE_ID_TYPES_H    != GPT_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Gpt_70_Types.h and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_H    ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != GPT_70_AR_RELEASE_MINOR_VERSION_CFG_H    ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_TYPES_H != GPT_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
    #error "AUTOSAR Version Numbers of Gpt_70_Types.h and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_70_SW_MAJOR_VERSION_TYPES_H != GPT_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_MINOR_VERSION_TYPES_H != GPT_70_SW_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_PATCH_VERSION_TYPES_H != GPT_70_SW_PATCH_VERSION_CFG_H ) )
    #error "Software Version Numbers of Gpt_70_Types.h and Gpt_Cfg.h are different"
#endif
/* Gpt_Cfg.h version check end */

/* Gpt_70_HW_Types.h version check start */
#if ( GPT_70_VENDOR_ID_TYPES_H    != GPT_70_VENDOR_ID_HW_TYPES_H )
    #error "VENDOR ID for Gpt_70_Types.h and Gpt_70_HW_Types.h are different"
#endif

#if ( GPT_70_MODULE_ID_TYPES_H    != GPT_70_MODULE_ID_HW_TYPES_H )
    #error "MODULE ID for Gpt_70_Types.h and Gpt_70_HW_Types.h are different"
#endif

#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != GPT_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H    ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != GPT_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H    ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_TYPES_H != GPT_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H ) )
    #error "AUTOSAR Version Numbers of Gpt_70_Types.h and Gpt_70_HW_Types.h are different"
#endif

#if ( ( GPT_70_SW_MAJOR_VERSION_TYPES_H != GPT_70_SW_MAJOR_VERSION_HW_TYPES_H ) || \
      ( GPT_70_SW_MINOR_VERSION_TYPES_H != GPT_70_SW_MINOR_VERSION_HW_TYPES_H ) || \
      ( GPT_70_SW_PATCH_VERSION_TYPES_H != GPT_70_SW_PATCH_VERSION_HW_TYPES_H ) )
    #error "Software Version Numbers of Gpt_70_Types.h and Gpt_70_HW_Types.h are different"
#endif

/* Gpt_70_HW_Types.h version check end */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* EcuM_Cbk.h version check start */
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H != ECUM_AR_RELEASE_MAJOR_VERSION ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_TYPES_H != ECUM_AR_RELEASE_MINOR_VERSION ) )
    #error "AUTOSAR Version Numbers of Gpt_70_Types.h and EcuM_Cbk.h are different"
#endif
/* EcuM_Cbk.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions (AUTOSAR)                                                 */
/*----------------------------------------------------------------------------*/

/* --- [SWS_Gpt_00360] Mode of the GPT DRIVERS -------- */
typedef enum {
    GPT_70_MODE_UNINITIALIZED = ( 0U ), /* Uninitialized status mode */
    GPT_70_MODE_NORMAL        = ( 1U ), /* Normal operation mode of the GPT */
    GPT_70_MODE_SLEEP         = ( 2U )  /* Sleep mode */
} Gpt_ModeType;

/* --- [ECUC_Gpt_00309] Modes of the GPT DRIVERS ---------------- */
typedef enum {
    GPT_CH_MODE_ONESHOT    = ( 0U ),
    GPT_CH_MODE_CONTINUOUS = ( 1U )
} Gpt_70_ChannelModeType;

/* [SWS_Gpt_00359] Gpt timer count value. */
typedef uint16 Gpt_ValueType;

/* [SWS_Gpt_00358] Numeric ID of a Gpt channel. */
typedef uint8  Gpt_ChannelType;

#if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE )
/* [ECUC_Gpt_00235] Wakeup Configuration */
typedef struct {
    /* [ECUC_Gpt_00235] Function pointer to callback function (for wakeup notification) */
    void (*Gpt_70_WakeupNotification)( void );
    /* [ECUC_Gpt_00313] this value is transmitted to the EcuState Manager */
    EcuM_WakeupSourceType  GptWakeupSourceRef;
} Gpt_WakeupConfigurationType;
#endif /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */

Line 152