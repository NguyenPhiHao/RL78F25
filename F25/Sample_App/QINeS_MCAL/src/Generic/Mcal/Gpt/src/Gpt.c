/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Gpt.c                                                        */
/* Version     : v1.00.01                                                     */
/* Contents    : This specification specifies the functionality, API and the  */
/*              configuration of the AUTOSAR Basic Software module GPT driver.*/
/*               The GPT driver provides services and configuration parameters*/
/*               for                                                          */
/*               -Starting and stopping hardware timers                       */
/*               -Getting timer values                                        */
/*               -Controlling time triggered interrupt notifications,         */
/*                if supported by hardware                                    */
/*               -Controlling time triggered wakeup interrupts,               */
/*                if supported by hardware                                    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of GPT Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Gpt.h"
#include "SchM_Gpt.h"
#include "Det.h"            /* [SWS_Gpt_00375] */
 
#include "Gpt_70_HW.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define GPT_70_VENDOR_ID_C                   ( 70U )
#define GPT_70_MODULE_ID_C                   ( 100U )
 
#define GPT_70_AR_RELEASE_MAJOR_VERSION_C    ( 22U )
#define GPT_70_AR_RELEASE_MINOR_VERSION_C    ( 11U )
#define GPT_70_AR_RELEASE_REVISION_VERSION_C ( 0U )
 
#define GPT_70_SW_MAJOR_VERSION_C            ( 1U )
#define GPT_70_SW_MINOR_VERSION_C            ( 0U )
#define GPT_70_SW_PATCH_VERSION_C            ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
 
/* Gpt.h version check start */
 
#if ( GPT_70_VENDOR_ID_C != GPT_VENDOR_ID )
    #error "VENDOR ID for Gpt.c and Gpt.h are different"
#endif
 
#if ( GPT_70_MODULE_ID_C != GPT_MODULE_ID )
    #error "MODULE ID for Gpt.c and Gpt.h are different"
#endif
 
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_C    != GPT_AR_RELEASE_MAJOR_VERSION ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_C    != GPT_AR_RELEASE_MINOR_VERSION ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Gpt.c and Gpt.h are different"
#endif
 
#if ( ( GPT_70_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION ) || \
      ( GPT_70_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION ) || \
      ( GPT_70_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Gpt.c and Gpt.h are different"
#endif
 
/* Gpt.h version check end */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* SchM_Gpt.h version check start */
 
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_C    != RTE_AR_RELEASE_MAJOR_VERSION ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_C    != RTE_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Gpt.c and SchM_Gpt.h are different"
#endif
 
/* SchM_Gpt.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
/* Gpt_70_HW.h version check start */
 
#if ( GPT_70_VENDOR_ID_C != GPT_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Gpt.c and Gpt_70_HW.h are different"
#endif
 
#if ( GPT_70_MODULE_ID_C != GPT_70_MODULE_ID_HW_H )
    #error "MODULE ID for Gpt.c and Gpt_70_HW.h are different"
#endif
 
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_C    != GPT_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_C    != GPT_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_C != GPT_70_AR_RELEASE_REVISION_VERSION_HW_H ) \
    )
    #error "AUTOSAR Version Numbers of Gpt.c and Gpt_70_HW.h are different"
#endif
 
#if ( ( GPT_70_SW_MAJOR_VERSION_C != GPT_70_SW_MAJOR_VERSION_HW_H ) || \
      ( GPT_70_SW_MINOR_VERSION_C != GPT_70_SW_MINOR_VERSION_HW_H ) || \
      ( GPT_70_SW_PATCH_VERSION_C != GPT_70_SW_PATCH_VERSION_HW_H ) \
    )
    #error "Software Version Numbers of Gpt.c and Gpt_70_HW.h are different"
#endif
 
/* Gpt_70_HW.h version check end */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* Det.h version check start */
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Gpt.c and Det.h are different"
#endif
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
/* Det.h version check stop */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
/* definisitions for predef timer */
#define GPT_70_PREDEF_16BITMASK               ( 0xFFFFUL )     /* mask of predef timer 16bit */
#define GPT_70_PREDEF_24BITMASK               ( 0xFFFFFFUL )   /* mask of predef timer 24bit */
#define GPT_70_PREDEF_32BITMASK               ( 0xFFFFFFFFUL ) /* mask of predef timer 32bit */
 
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
/*----------------------------------------------------------------------------*/
/*  const data declarations                                                   */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#define GPT_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Gpt_MemMap.h"
 
/* work information table for channels. */
static Gpt_70_ChannelInfoType s_GptChInfo[ GPT_70_NUM_OF_GPTCHANNELCONF ] = { 0U };
 
#define GPT_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Gpt_MemMap.h"
 
#define GPT_START_SEC_VAR_INIT_LOCAL_8
#include "Gpt_MemMap.h"
 
static Gpt_ModeType s_GptDriverMode = GPT_70_MODE_UNINITIALIZED;       /* GPT Driver Mode */
 
#define GPT_STOP_SEC_VAR_INIT_LOCAL_8
#include "Gpt_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define GPT_START_SEC_CODE_LOCAL
#include "Gpt_MemMap.h"
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPT_70_GETVERSIONINFO_ID (0x00)                              */
/* Name        : Gpt_GetVersionInfo                                           */
/* Param       : (out) VersionInfoPtr  pointer for version information.       */
/* Return      : None                                                         */
/* Contents    : Version Information return function                          */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00279]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_VERSION_INFO_API != FALSE )
void Gpt_GetVersionInfo( Std_VersionInfoType* VersionInfoPtr )
{
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Gpt_00338] Check VersionInfoPtr is invalid */
    if ( NULL_PTR == VersionInfoPtr ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_GETVERSIONINFO_ID, ( uint8 )GPT_E_PARAM_POINTER );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
 
    VersionInfoPtr->vendorID         = ( uint16 )GPT_VENDOR_ID;           /* Vendor ID */
    VersionInfoPtr->moduleID         = ( uint16 )GPT_MODULE_ID;           /* Module ID */
    VersionInfoPtr->sw_major_version = ( uint8 )GPT_SW_MAJOR_VERSION;     /* Software Major Version */
    VersionInfoPtr->sw_minor_version = ( uint8 )GPT_SW_MINOR_VERSION;     /* Software Minor Version */
    VersionInfoPtr->sw_patch_version = ( uint8 )GPT_SW_PATCH_VERSION;     /* Software Patch Version */
}
#endif /* #if ( GPT_VERSION_INFO_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPT_70_INIT_ID (0x01)                                        */
/* Name        : Gpt_Init                                                     */
/* Param       : (in) ConfigPtr    Pointer to a selected configuration.       */
/* Return      : None                                                         */
/* Contents    : Initializes the GPT driver.                                  */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00280]                                              */
/*----------------------------------------------------------------------------*/
void Gpt_Init( const Gpt_ConfigType* ConfigPtr )
{
    /* work information for a channel. */
    Gpt_70_ChannelInfoType* infoPtr;            /* no initial value for MISRA2012 Rule-2.2 */
    /* configuration for a channel. */
    const Gpt_ChannelConfigurationType* chPtr;  /* no initial value for MISRA2012 Rule-2.2 */
    uint8_least                     lcount;
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    Std_ReturnType ret;                         /* no initial value for MISRA2012 Rule-2.2 */
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* check wrong pointer */
    if ( NULL_PTR == ConfigPtr ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_INIT_ID, ( uint8 )GPT_E_PARAM_POINTER );
        return;
    }
 
    /* check that GPT driver is already initialized. */
    if ( GPT_70_MODE_UNINITIALIZED != s_GptDriverMode ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332],[SWS_Gpt_00307] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_INIT_ID, ( uint8 )GPT_E_ALREADY_INITIALIZED );
        return;
    }
 
    /* check configuration of all channels . */
    for ( lcount=0U; lcount<GPT_70_NUM_OF_GPTCHANNELCONF; lcount++ ) {
        /* get configuration for a channel */
        chPtr = &( ConfigPtr->GptChannelConfigSet.GptChannelConfiguration[lcount] );
        /* check wrong pointer */
        if ( NULL_PTR == chPtr ) {
            /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
            ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                     ( uint8 )GPT_70_INIT_ID, ( uint8 )GPT_E_PARAM_POINTER );
            return;
        }
        /* check wrong channel ID */
        if ( lcount != chPtr->GptChannelId ) {
            /* [SWS_Gpt_00332] */
            ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                     ( uint8 )GPT_70_INIT_ID, ( uint8 )GPT_70_E_WRONG_COFIGURATION );
            return;
        }
    }
 
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
    /* check for predef timer */
    if ( NULL_PTR == ConfigPtr->GptDriverConfiguration.GptPredefTimerConfPtr ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_INIT_ID, ( uint8 )GPT_E_PARAM_POINTER );
        return;
    }
    ret = Gpt_70_HW_Init_CheckConfPredefTimer( ConfigPtr->GptDriverConfiguration.GptPredefTimerConfPtr );
    if ( E_OK != ret ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_INIT_ID, ( uint8 )GPT_E_PARAM_POINTER );
        return;
    }
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    /* init. all channels according to configuration. */
    for ( lcount=0U; lcount<GPT_70_NUM_OF_GPTCHANNELCONF; lcount++ ) {
        /* get configuration for a channel */
        chPtr = &( ConfigPtr->GptChannelConfigSet.GptChannelConfiguration[lcount] );
        /* get work information for a channel */
        infoPtr                     = &( s_GptChInfo[lcount] );
        /* init. work information for a channel */
        infoPtr->confPtr            = chPtr;                        /* save configuration of channel */
        infoPtr->status             = GPT_70_CHANNEL_INITIALIZED;   /* clear status */
        /* [SWS_Gpt_00258] disable wakeup */
        infoPtr->wakeupEnable       = FALSE;
        /* [SWS_Gpt_00107] disable wakeup notification */
        infoPtr->notificationEnable = FALSE;
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Gpt_00352] call H/W dependent initialize. */
        ret = Gpt_70_HW_Init( chPtr->Gpt_70_TimerSettingConfPtr );
        /* check Gpt Initialization failed */
        if ( E_NOT_OK == ret ) {
            /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
            ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                     ( uint8 )GPT_70_INIT_ID, ( uint8 )GPT_E_INIT_FAILED );
            return;
        }
#else
        /* [SWS_Gpt_00352] call H/W dependent initialize. */
        ( void )Gpt_70_HW_Init( chPtr->Gpt_70_TimerSettingConfPtr );
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
    }
 
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
    /* initialize predef timer. */
    Gpt_70_HW_InitPredefTimer( ConfigPtr->GptDriverConfiguration.GptPredefTimerConfPtr );
    /* start predef timer. */
    Gpt_70_HW_StartPredefTimer();
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
    s_GptDriverMode = GPT_MODE_NORMAL;             /* [SWS_Gpt_00339] set mode to GPT_MODE_NORMAL */
}
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPT_70_DEINIT_ID (0x02)                                      */
/* Name        : Gpt_DeInit                                                   */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : Deinitializes the GPT driver.                                */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00309]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_DEINIT_API != FALSE )    /* [SWS_Gpt_00194] */
void Gpt_DeInit( void )
{
    /* work information for a channel. */
    Gpt_70_ChannelInfoType* infoPtr;    /* no initial value for MISRA2012 Rule-2.2 */
    uint8_least             lcount;
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* check that GPT driver is already initialized ? */
    if ( ( GPT_MODE_NORMAL != s_GptDriverMode ) && ( GPT_MODE_SLEEP != s_GptDriverMode ) ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332],[SWS_Gpt_00220] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_DEINIT_ID, ( uint8 )GPT_E_UNINIT );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
    for ( lcount=0U; lcount<GPT_70_NUM_OF_GPTCHANNELCONF; lcount++ ) {
        infoPtr = &( s_GptChInfo[lcount] );
        /* check if a channel is running. */
        if ( GPT_70_CHANNEL_RUNNING == infoPtr->status ) {
            /* [SWS_Gpt_91001],[SWS_Gpt_00234] */
            ( void )Det_ReportRuntimeError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                            ( uint8 )GPT_70_DEINIT_ID, ( uint8 )GPT_E_BUSY );
            return;
        }
    }
 
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
    /* stop predef timer. */
    Gpt_70_HW_StopPredefTimer();
    /* deinitialize 1us predef timer. */
    Gpt_70_HW_DeInitPredefTimer();
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
    /* stop/deinitialize for all channels. */
    for ( lcount=0U; lcount<GPT_70_NUM_OF_GPTCHANNELCONF; lcount++ ) {
        /* get work information for a channel */
        infoPtr                     = &( s_GptChInfo[lcount] );
        /* [SWS_Gpt_00008],[SWS_Gpt_00162] stop timer before deinitalize. */
        Gpt_70_HW_StopTimer( infoPtr->confPtr->Gpt_70_TimerSettingConfPtr );
        /* call H/W dependent deinitialize. */
        Gpt_70_HW_DeInit( infoPtr->confPtr->Gpt_70_TimerSettingConfPtr );
        /* clear work information for a channel. */
        infoPtr->confPtr            = NULL_PTR;
        infoPtr->status             = GPT_70_CHANNEL_UNINITIALIZED;
        infoPtr->wakeupEnable       = FALSE;    /* [SWS_Gpt_00105] */
        infoPtr->notificationEnable = FALSE;    /* [SWS_Gpt_00105] */
    }
 
    s_GptDriverMode = GPT_70_MODE_UNINITIALIZED;   /* [SWS_Gpt_00363] set mode to uninitialized. */
}
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPT_70_GETTIMEELAPSED_ID (0x03)                              */
/* Name        : Gpt_GetTimeElapsed                                           */
/* Param       : (in) Channel    Numeric identifier of the GPT channel.       */
/* Return      : the time already elapsed.                                    */
/* Contents    : Returns the time already elapsed.                            */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00282]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_TIME_ELAPSED_API != FALSE ) /* [SWS_Gpt_00195] */
Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel )
{
    /* work information for a channel. */
    const Gpt_70_ChannelInfoType* infoPtr;    /* no initial value for MISRA2012 Rule-2.2 */
    /* return value. */
    Gpt_ValueType           retElapsedTime = 0U;
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Gpt_00222] check that GPT driver is already initialized ? */
    if ( ( GPT_MODE_NORMAL != s_GptDriverMode ) && ( GPT_MODE_SLEEP != s_GptDriverMode ) ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_GETTIMEELAPSED_ID, ( uint8 )GPT_E_UNINIT );
        return retElapsedTime;
    }
 
    /* [SWS_Gpt_00210] check channel ID is within the range specified in configuration. */
    if ( GPT_70_NUM_OF_GPTCHANNELCONF <= Channel ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_GETTIMEELAPSED_ID, ( uint8 )GPT_E_PARAM_CHANNEL );
        return retElapsedTime;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    /* get work information for a channel. */
    infoPtr = &( s_GptChInfo[Channel] );
 
    /* [SWS_Gpt_00295] check if the specified timer has started? */
    if ( GPT_70_CHANNEL_RUNNING > infoPtr->status ) {
        return retElapsedTime;
    }
 
    /* get elapsed time */
 
    if ( GPT_70_CHANNEL_EXPIRED != infoPtr->status ) {
        /* [SWS_Gpt_00010],[SWS_Gpt_00297] get elapsed time */
        retElapsedTime = Gpt_70_HW_GetTimeElapsed( infoPtr->confPtr->Gpt_70_TimerSettingConfPtr, infoPtr->targetValue );
    } else {
        /* [SWS_Gpt_00299] return target time in state EXPIRED */
        retElapsedTime = infoPtr->targetValue;
    }
 
    return retElapsedTime;
}
#endif /* #if ( GPT_TIME_ELAPSED_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPT_70_GETTIMEREMAINING_ID (0x04)                            */
/* Name        : Gpt_GetTimeRemaining                                         */
/* Param       : (in) Channel    Numeric identifier of the GPT channel.       */
/* Return      : Remaining timer value.                                       */
/* Contents    : Returns the time remaining until the target time is reached. */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00283]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_TIME_REMAINING_API != FALSE ) /* [SWS_Gpt_00196] */
Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel )
{
    /* work information for a channel. */
    const Gpt_70_ChannelInfoType*             infoPtr;    /* no initial value for MISRA2012 Rule-2.2 */
    /* return value. */
    Gpt_ValueType                       retRemainingTime = 0U;
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Gpt_00223] check that GPT driver is already initialized ? */
    if ( ( GPT_MODE_NORMAL != s_GptDriverMode ) && ( GPT_MODE_SLEEP != s_GptDriverMode ) ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_GETTIMEREMAINING_ID, ( uint8 )GPT_E_UNINIT );
        return retRemainingTime;
    }
 
    /* [SWS_Gpt_00211] check channel ID is within the range specified in configuration. */
    if ( GPT_70_NUM_OF_GPTCHANNELCONF <= Channel ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_GETTIMEREMAINING_ID, ( uint8 )GPT_E_PARAM_CHANNEL );
        return retRemainingTime;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    /* get work information for a channel. */
    infoPtr = &( s_GptChInfo[Channel] );
 
    /* [SWS_Gpt_00301] check if the specified timer has started? */
    if ( GPT_70_CHANNEL_RUNNING > infoPtr->status ) {
        return retRemainingTime;
    }
 
    /* get remaining time */
 
    if ( GPT_70_CHANNEL_EXPIRED != infoPtr->status ) {
        /* [SWS_Gpt_00083],[SWS_Gpt_00303] get remaining time */
        retRemainingTime = Gpt_70_HW_GetTimeRemaining( infoPtr->confPtr->Gpt_70_TimerSettingConfPtr, infoPtr->targetValue );
    } else {
        /* [SWS_Gpt_00305] return remaining time '0' in state EXPIRED */
        /* NOTE: state EXPIRED is in ONE-SHOT mode only */
    }
 
    return retRemainingTime;
}
#endif /* #if ( GPT_TIME_REMAINING_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPT_70_STARTTIMER_ID (0x05)                                  */
/* Name        : Gpt_StartTimer                                               */
/* Param       : (in) Channel    Numeric identifier of the GPT channel.       */
/*             : (in) Value      Target time in number of ticks.              */
/* Return      : None                                                         */
/* Contents    : Starts a timer channel.                                      */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00284]                                              */
/*----------------------------------------------------------------------------*/
void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value )
{
    /* work information for a channel. */
    Gpt_70_ChannelInfoType*             infoPtr;    /* no initial value for MISRA2012 Rule-2.2 */
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Gpt_00224] check that GPT driver is already initialized ? */
    if ( ( GPT_MODE_NORMAL != s_GptDriverMode ) && ( GPT_MODE_SLEEP != s_GptDriverMode ) ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_STARTTIMER_ID, ( uint8 )GPT_E_UNINIT );
        return;
    }
 
    /* [SWS_Gpt_00212] check channel ID is within the range specified in configuration. */
    if ( GPT_70_NUM_OF_GPTCHANNELCONF <= Channel ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_STARTTIMER_ID, ( uint8 )GPT_E_PARAM_CHANNEL );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    /* get work information for a channel. */
    infoPtr = &( s_GptChInfo[Channel] );
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* check the parameter is within the range. */
    if ( ( 0U == Value ) || ( infoPtr->confPtr->GptChannelTickValueMax < Value ) ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332],[SWS_Gpt_00218] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_STARTTIMER_ID, ( uint8 )GPT_E_PARAM_VALUE );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
    /* check the channel is already running. */
    if ( GPT_70_CHANNEL_RUNNING == infoPtr->status ) {
        /* [SWS_Gpt_91001],[SWS_Gpt_00084] */
        ( void )Det_ReportRuntimeError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                        ( uint8 )GPT_70_STARTTIMER_ID, ( uint8 )GPT_E_BUSY );
        return;
    }
 
    /* save target value */
    infoPtr->targetValue = Value;
    /* [SWS_Gpt_00274] start a timer */
    Gpt_70_HW_StartTimer( infoPtr->confPtr->Gpt_70_TimerSettingConfPtr, Value );
 
    /* [SWS_Gpt_00364] set status of GPT channel info to GPT_70_CHANNEL_RUNNING */
    infoPtr->status = GPT_70_CHANNEL_RUNNING;
}
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPT_70_STOPTIMER_ID (0x06)                                   */
/* Name        : Gpt_StopTimer                                                */
/* Param       : (in) Channel    Numeric identifier of the GPT channel.       */
/* Return      : None                                                         */
/* Contents    : Stop a timer channel.                                        */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00285]                                              */
/*----------------------------------------------------------------------------*/
void Gpt_StopTimer( Gpt_ChannelType Channel )
{
    /* work information for a channel. */
    Gpt_70_ChannelInfoType*  infoPtr;   /* no initial value for MISRA2012 Rule-2.2 */
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Gpt_00225] check that GPT driver is already initialized ? */
    if ( ( GPT_MODE_NORMAL != s_GptDriverMode ) && ( GPT_MODE_SLEEP != s_GptDriverMode ) ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_STOPTIMER_ID, ( uint8 )GPT_E_UNINIT );
        return;
    }
 
    /* [SWS_Gpt_00213] check channel ID is within the range specified in configuration. */
    if ( GPT_70_NUM_OF_GPTCHANNELCONF <= Channel ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_STOPTIMER_ID, ( uint8 )GPT_E_PARAM_CHANNEL );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    /* get work information for a channel. */
    infoPtr = &( s_GptChInfo[Channel] );
 
    /* [SWS_Gpt_00344] stop the channel when the channel is running. */
    if ( GPT_70_CHANNEL_RUNNING == infoPtr->status ) {
        /* [SWS_Gpt_00013] stop timer */
        Gpt_70_HW_StopTimer( infoPtr->confPtr->Gpt_70_TimerSettingConfPtr );
 
        /* [SWS_Gpt_00343] set status of GPT channel info to GPT_70_CHANNEL_STOPPED */
        infoPtr->status = GPT_70_CHANNEL_STOPPED;
    }
}
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPT_70_ENABLENOTIFICATION_ID (0x07)                          */
/* Name        : Gpt_EnableNotification                                       */
/* Param       : (in) Channel    Numeric identifier of the GPT channel.       */
/* Return      : None                                                         */
/* Contents    : Enable the interrupt notification for a channel.             */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00286]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_ENABLE_DISABLE_NOTIFICATION_API != FALSE ) /* [SWS_Gpt_00199] */
void Gpt_EnableNotification( Gpt_ChannelType Channel )
{
    /* work information for a channel. */
    Gpt_70_ChannelInfoType*               infoPtr;  /* no initial value for MISRA2012 Rule-2.2 */
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Gpt_00226] check that GPT driver is already initialized ? */
    if ( ( GPT_MODE_NORMAL != s_GptDriverMode ) && ( GPT_MODE_SLEEP != s_GptDriverMode ) ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_ENABLENOTIFICATION_ID, ( uint8 )GPT_E_UNINIT );
        return;
    }
 
    /* [SWS_Gpt_00214] check channel ID is within the range specified in configuration. */
    if ( GPT_70_NUM_OF_GPTCHANNELCONF <= Channel ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_ENABLENOTIFICATION_ID, ( uint8 )GPT_E_PARAM_CHANNEL );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    /* get work information for a channel. */
    infoPtr = &( s_GptChInfo[Channel] );
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Gpt_00377] check that notification function is defined in configuration. */
    if ( NULL_PTR == infoPtr->confPtr->GptNotification ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_ENABLENOTIFICATION_ID, ( uint8 )GPT_E_PARAM_CHANNEL );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    /* [SWS_Gpt_00093] set notficationEnable to TRUE. */
    infoPtr->notificationEnable = TRUE;
}
#endif /* #if ( GPT_ENABLE_DISABLE_NOTIFICATION_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPT_70_DISABLENOTIFICATION_ID (0x08)                         */
/* Name        : Gpt_DisableNotification                                      */
/* Param       : (in) Channel    Numeric identifier of the GPT channel.       */
/* Return      : None                                                         */
/* Contents    : Disable the interrupt notification for a channel.            */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00287]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_ENABLE_DISABLE_NOTIFICATION_API != FALSE ) /* [SWS_Gpt_00200] */
void Gpt_DisableNotification( Gpt_ChannelType Channel )
{
    /* work information for a channel. */
    Gpt_70_ChannelInfoType*             infoPtr;    /* no initial value for MISRA2012 Rule-2.2 */
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Gpt_00227] check that GPT driver is already initialized ? */
    if ( ( GPT_MODE_NORMAL != s_GptDriverMode ) && ( GPT_MODE_SLEEP != s_GptDriverMode ) ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_DISABLENOTIFICATION_ID, ( uint8 )GPT_E_UNINIT );
        return;
    }
 
    /* [SWS_Gpt_00217] check channel ID is within the range specified in configuration. */
    if ( GPT_70_NUM_OF_GPTCHANNELCONF <= Channel ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_DISABLENOTIFICATION_ID, ( uint8 )GPT_E_PARAM_CHANNEL );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    /* get work information for a channel. */
    infoPtr = &( s_GptChInfo[Channel] );
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Gpt_00379] check that notification function is defined i nconfiguration. */
    if ( NULL_PTR == infoPtr->confPtr->GptNotification ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_DISABLENOTIFICATION_ID, ( uint8 )GPT_E_PARAM_CHANNEL );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    /* [SWS_Gpt_00015] set notificationEnable of GPT channel info to FALSE. */
    infoPtr->notificationEnable = FALSE;
}
#endif /* #if ( GPT_ENABLE_DISABLE_NOTIFICATION_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPT_70_SETMODE_ID (0x09)                                     */
/* Name        : Gpt_SetMode                                                  */
/* Param       : (in) Mode    Allows the selection of different power modes.  */
/* Return      : None                                                         */
/* Contents    : Sets the operation mode of the GPT.                          */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00288]                                              */
/*----------------------------------------------------------------------------*/
/* [SWS_Gpt_00201],[SWS_Gpt_00202],[SWS_Gpt_00203],[SWS_Gpt_00324],[ECUC_Gpt_00320] */
#if ( ( GPT_WAKEUP_FUNCTIONALITY_API != FALSE ) && ( GPT_REPORT_WAKEUP_SOURCE != FALSE ) )
void Gpt_SetMode( Gpt_ModeType Mode )
{
    /* work information for a channel. */
    Gpt_70_ChannelInfoType* infoPtr;    /* no initial value for MISRA2012 Rule-2.2 */
    uint8_least             lcount;
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Gpt_00228] check that GPT driver is already initialized ? */
    if ( ( GPT_MODE_NORMAL != s_GptDriverMode ) && ( GPT_MODE_SLEEP != s_GptDriverMode ) ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_SETMODE_ID, ( uint8 )GPT_E_UNINIT );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    switch ( Mode ) {
    case GPT_MODE_SLEEP:
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
        /* [SWS_Gpt_00393]
         * If the parameter Mode has the value GPT_MODE_SLEEP:
         * The function Gpt_SetMode shall stop all enabled GPT Predef Timers.(SRS_Gpt_13607)
         */
        /* [SWS_Gpt_00008],[SWS_Gpt_00162] stop predef timer */
        Gpt_70_HW_StopPredefTimer();
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
        /* [SWS_Gpt_00151] set parameter mode to Gpt driver mode */
        for ( lcount=0U; lcount<GPT_70_NUM_OF_GPTCHANNELCONF; lcount++ ) {
            /* wakeupEnable is FALSE and status is GPT_70_CHANNEL_RUNNING */
            /* get work information for a channel. */
            infoPtr             = &( s_GptChInfo[lcount] );
            if ( ( FALSE == infoPtr->wakeupEnable ) &&
                 ( GPT_70_CHANNEL_RUNNING == infoPtr->status ) ) {
                /* stop a timer when the timer is running. */
                Gpt_70_HW_StopTimer( infoPtr->confPtr->Gpt_70_TimerSettingConfPtr );
                /* [SWS_Gpt_00164] change status to STOPPED. */
                infoPtr->status = GPT_70_CHANNEL_STOPPED;
            }
            /* [SWS_Gpt_00341] timer doesn't start again */
        }
        s_GptDriverMode = Mode; /* [SWS_Gpt_00153] */
        break;
    case GPT_MODE_NORMAL:
        /* [SWS_Gpt_00165]
         * If the parameter Mode has the value GPT_MODE_NORMAL,
         * the function Gpt_SetMode shall not restart automatically
         * the timer channels which have been stopped by entering the sleep mode.
         */
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
        /* start Predef Timer */
        /* [SWS_Gpt_00392]
         * If the parameter Mode has the value GPT_MODE_NORMAL:
         * If the driver is in "sleep mode", the function Gpt_SetMode shall restart all enabled
         * GPT Predef Timers at value "0".
         */
        /* start predef timer */
        Gpt_70_HW_StartPredefTimer();
 
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
        s_GptDriverMode = Mode;    /* [SWS_Gpt_00152],[SWS_Gpt_00165] */
        break;
    default:
#if ( GPT_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Gpt_91000],[SWS_Gpt_00332],[SWS_Gpt_00231] */
        /* Call Det_ReportError as errorcode "GPT_E_PARAM_MODE" */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_SETMODE_ID, ( uint8 )GPT_E_PARAM_MODE );
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
        break;
    }
}
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPT_70_DISABLEWAKEUP_ID (0x0A)                               */
/* Name        : Gpt_DisableWakeup                                            */
/* Param       : (in) Channel    Numeric identifier of the GPT channel.       */
/* Return      : None                                                         */
/* Contents    : Disables the wakeup interrupt of a channel.                  */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00289]                                              */
/*----------------------------------------------------------------------------*/
void Gpt_DisableWakeup( Gpt_ChannelType Channel )
{
    /* work information for a channel. */
    Gpt_70_ChannelInfoType*  infoPtr;   /* no initial value for MISRA2012 Rule-2.2 */
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
 
    /* [SWS_Gpt_00229] check that GPT driver is already initialized ? */
    if ( ( GPT_MODE_NORMAL != s_GptDriverMode ) && ( GPT_MODE_SLEEP != s_GptDriverMode ) ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_DISABLEWAKEUP_ID, ( uint8 )GPT_E_UNINIT );
        return;
    }
 
    /* [SWS_Gpt_00215] check channel ID is within the range specified in configuration. */
    if ( GPT_70_NUM_OF_GPTCHANNELCONF <= Channel ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_DISABLEWAKEUP_ID, ( uint8 )GPT_E_PARAM_CHANNEL );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    /* get work information for a channel. */
    infoPtr = &( s_GptChInfo[Channel] );
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* check wakeup capability in configuration. */
    if ( FALSE == infoPtr->confPtr->GptEnableWakeup ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_DISABLEWAKEUP_ID, ( uint8 )GPT_E_PARAM_CHANNEL );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    /* [SWS_Gpt_00159] set wakeupEnable of GPT channel info to FALSE */
    infoPtr->wakeupEnable = FALSE;
}
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPT_70_ENABLEWAKEUP_ID (0x0B)                                */
/* Name        : Gpt_EnableWakeup                                             */
/* Param       : (in) Channel    Numeric identifier of the GPT channel.       */
/* Return      : None                                                         */
/* Contents    : Enables the wakeup interrupt of a channel.                   */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00290]                                              */
/*----------------------------------------------------------------------------*/
void Gpt_EnableWakeup( Gpt_ChannelType Channel )
{
    /* work information for a channel. */
    Gpt_70_ChannelInfoType*  infoPtr;   /* no initial value for MISRA2012 Rule-2.2 */
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Gpt_00230] check that GPT driver is already initialized ? */
    if ( ( GPT_MODE_NORMAL != s_GptDriverMode ) && ( GPT_MODE_SLEEP != s_GptDriverMode ) ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_ENABLEWAKEUP_ID, ( uint8 )GPT_E_UNINIT );
        return;
    }
 
    /* [SWS_Gpt_00216] check channel ID is within the range specified in configuration. */
    if ( GPT_70_NUM_OF_GPTCHANNELCONF <= Channel ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_ENABLEWAKEUP_ID, ( uint8 )GPT_E_PARAM_CHANNEL );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    /* get work information for a channel. */
    infoPtr = &( s_GptChInfo[Channel] );
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Gpt_00321] check wakeup capability in configuration. */
    if ( FALSE == infoPtr->confPtr->GptEnableWakeup ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_ENABLEWAKEUP_ID, ( uint8 )GPT_E_PARAM_CHANNEL );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
    /* [SWS_Gpt_00160] set wakeupEnable of GPT channel info to TRUE */
    infoPtr->wakeupEnable = TRUE;
}
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPTQ__CHECKWAKEUP_ID (0x0C)                                  */
/* Name        : Gpt_CheckWakeup                                              */
/* Param       : (in) WakeupSource    Information on wakeup to be checked.    */
/* Return      : None                                                         */
/* Contents    : Checks if a wakeup capable GPT channel is the source for     */
/*               a wakeup event and calls the ECU  state manager service      */
/*               EcuM_SetWakeupEvent in case of a valid GPT channel wakeup    */
/*               event.                                                       */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00328]                                              */
/*----------------------------------------------------------------------------*/
void Gpt_CheckWakeup( EcuM_WakeupSourceType WakeupSource )
{
/* [SWS_Gpt_00322] */
#if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE )
    /* work information for a channel. */
    const Gpt_70_ChannelInfoType*             infoPtr;    /* no initial value for MISRA2012 Rule-2.2 */
    /* wakeup configuration */
    const Gpt_WakeupConfigurationType*  wakeupConfig;
    uint8_least                         lcount;
#endif /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Gpt_00325] check that GPT driver is already initialized ? */
    if ( ( GPT_MODE_NORMAL != s_GptDriverMode ) && ( GPT_MODE_SLEEP != s_GptDriverMode ) ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_CHECKWAKEUP_ID, ( uint8 )GPT_E_UNINIT );
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
 
#if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE )
    for ( lcount=0U; lcount<GPT_70_NUM_OF_GPTCHANNELCONF; lcount++ ) {
        infoPtr         = &( s_GptChInfo[lcount] );
        wakeupConfig    = infoPtr->confPtr->GptWakeupConfiguration;
        /* check wakeup capabirity and wake up source. */
        if ( ( FALSE != infoPtr->wakeupEnable )
          && ( wakeupConfig->GptWakeupSourceRef == WakeupSource ) ) {
            /* [SWS_Gpt_00321] call EcuM_SetWakeupEvent() Wake-up event of ECU state manager */
            /*          to be effective. */
            EcuM_SetWakeupEvent( WakeupSource );
            break;
        }
    }
#endif /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */
}
#endif /* #if ( ( GPT_WAKEUP_FUNCTIONALITY_API != FALSE ) && ( GPT_REPORT_WAKEUP_SOURCE != FALSE ) ) */
 
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : GPT_70_GETPREDEFTIMERVALUE_ID (0x0D)                         */
/* Name        : Gpt_GetPredefTimerValue                                      */
/* Param       : (in) PredefTimer   GPT Predef Timer.                         */
/*               (out) TimeValuePtr Pointer to time value destination data.   */
/* Return      : E_OK: no error has been detected.                            */
/*             : E_NOT_OK: aborted due to errors.                             */
/* Contents    : Delivers the current value of the desired GPT Predef Timer.  */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00394]                                              */
/*----------------------------------------------------------------------------*/
Std_ReturnType Gpt_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr )
{
    Std_ReturnType           retval = E_NOT_OK;
    uint32                   predefTimerValue;    /* GPT Predef Timer Value */
    uint32                   maskValue = 0UL;           /* mask value */
 
    /* [SWS_Gpt_00398] check that GPT driver is already initialized ? */
    if ( ( GPT_MODE_NORMAL != s_GptDriverMode ) && ( GPT_MODE_SLEEP != s_GptDriverMode ) ) {
        /* [SWS_Gpt_91000],[SWS_Gpt_00332] */
#if ( GPT_DEV_ERROR_DETECT != FALSE )
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_GETPREDEFTIMERVALUE_ID, ( uint8 )GPT_E_UNINIT );
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
        return retval;
    }
 
    /* check if Gpt Driver is in sleep mode */
    if ( GPT_MODE_SLEEP == s_GptDriverMode ) {    /* [SWS_Gpt_00401],[SWS_Gpt_00402],[SWS_Gpt_91001] */
        ( void )Det_ReportRuntimeError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                        ( uint8 )GPT_70_GETPREDEFTIMERVALUE_ID, ( uint8 )GPT_E_MODE );
        return retval;
    }
 
    /* check if TimeValuePtr is not a null pointer */
    if ( NULL_PTR == TimeValuePtr ) {    /* [SWS_Gpt_00403] */
#if ( GPT_DEV_ERROR_DETECT != FALSE )
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_GETPREDEFTIMERVALUE_ID, ( uint8 )GPT_E_PARAM_POINTER );
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
        return retval;
    }
 
    /* check if predeftimer is valid */
    /* [SWS_Gpt_00395],[SWS_Gpt_00396],[SWS_Gpt_00398],[SWS_Gpt_00399],[SWS_Gpt_00400] */
    switch ( ( uint8 )PredefTimer ) {
    case ( uint8 )GPT_PREDEF_TIMER_1US_16BIT:
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED )
        retval = E_OK;
        maskValue = GPT_70_PREDEF_16BITMASK;
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED ) */
        break;
    case ( uint8 )GPT_PREDEF_TIMER_1US_24BIT:
#if ( ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED ) || \
      ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED ) )
        retval = E_OK;
        maskValue = GPT_70_PREDEF_24BITMASK;
#endif /* #if ( ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED ) || \
                ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED ) ) */
        break;
    case ( uint8 )GPT_PREDEF_TIMER_1US_32BIT:
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED )
        retval = E_OK;
        maskValue = GPT_70_PREDEF_32BITMASK;
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE == GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED ) */
        break;
    case ( uint8 )GPT_PREDEF_TIMER_100US_32BIT:
#if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE )
        retval = E_OK;
        maskValue = GPT_70_PREDEF_32BITMASK;
#endif /* #if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) */
        break;
    default:
        /* do nothing */
        break;
    }
    /* check if the GPT Predef Timer passed by the parameter PredefTimer is not enabled */
    if ( E_NOT_OK == retval ) {     /* [SWS_Gpt_00399],[SWS_Gpt_00400] */
#if ( GPT_DEV_ERROR_DETECT != FALSE )
        ( void )Det_ReportError( ( uint16 )GPT_MODULE_ID, ( uint8 )GPT_INSTANCE_ID,
                                 ( uint8 )GPT_70_GETPREDEFTIMERVALUE_ID, ( uint8 )GPT_E_PARAM_PREDEF_TIMER );
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
        return retval;
    }
 
    /* get value from predef timer. */
    predefTimerValue = Gpt_70_HW_GetPredefTimerValue( PredefTimer );
    /* mask 16/24/32 bit */
    *TimeValuePtr = predefTimerValue & maskValue;
 
    return retval;
}
 
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
 
/******************************************************************************/
/* ModuleID    : GPT_MODULE_ID (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_Isr_CHn                                               */
/* Param       : (in) chId            Channel ID.                             */
/* Return      : None                                                         */
/* Contents    : timer channel notification process.                          */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/*----------------------------------------------------------------------------*/
#if ( GPT_70_IRQ_USE != FALSE )
void Gpt_70_Isr_CHn( Gpt_ChannelType chId )
{
    /* work information for a channel. */
    Gpt_70_ChannelInfoType*             infoPtr;    /* no initial value for MISRA2012 Rule-2.2 */
    /* configuration for a channel.*/
    const Gpt_ChannelConfigurationType* chPtr;      /* no initial value for MISRA2012 Rule-2.2 */
    /* wakeup source information. */
#if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE )
    EcuM_WakeupSourceType               srcRef;     /* no initial value for MISRA2012 Rule-2.2 */
#else /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */
    EcuM_WakeupSourceType               srcRef = 0UL;
#endif /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */
 
#if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE )
    const Gpt_WakeupConfigurationType*    wakeupConfigPtr;    /* wakeup configuration. */
#endif /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */
 
#if ( GPT_DEV_ERROR_DETECT != FALSE )
    if ( GPT_70_MODE_UNINITIALIZED == s_GptDriverMode ) {
        return;
    }
#endif /* #if ( GPT_DEV_ERROR_DETECT != FALSE ) */
    /* get work information for a channel. */
    infoPtr = &( s_GptChInfo[chId] );
    /* get channel configuration */
    chPtr   = infoPtr->confPtr;
 
    /* [SWS_Gpt_00185] */
    /* check status is running and mode is oneshot */
    if ( ( GPT_70_CHANNEL_RUNNING == infoPtr->status )
      && ( GPT_CH_MODE_ONESHOT == chPtr->GptChannelMode ) ) {
        /* stop timer */
        Gpt_70_HW_StopTimer( chPtr->Gpt_70_TimerSettingConfPtr );
        /* set status to GPT_70_CHANNEL_EXPIRED */
        infoPtr->status = GPT_70_CHANNEL_EXPIRED;
    }
 
    /* clear interrupt flag */
    Gpt_70_HW_ClrInt( chPtr->Gpt_70_TimerSettingConfPtr );
   
    /* check that GPT is not in the sleep mode  */
    if ( GPT_MODE_SLEEP != s_GptDriverMode ) {
        /* [SWS_Gpt_00093] check notification is enable and function is available. */
        if ( ( FALSE != infoPtr->notificationEnable ) && ( NULL_PTR != chPtr->GptNotification ) ) {
            /* [SWS_Gpt_00292],[SWS_Gpt_00209] call callback fuction */
            chPtr->GptNotification();
        }
    } else {
#if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE )
        /* get wakeup configuration */
        wakeupConfigPtr = chPtr->GptWakeupConfiguration;
        /* get wakeup source reference. */
        srcRef = wakeupConfigPtr->GptWakeupSourceRef;
        /* check wakeup is enable. */
        if ( FALSE != infoPtr->wakeupEnable ) {
            /* check callback function is available. */
            if ( NULL_PTR != wakeupConfigPtr->Gpt_70_WakupNotification ) {
                /* [SWS_Gpt_00327] call callback fuction */
                wakeupConfigPtr->Gpt_70_WakupNotification();
            }
#endif /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */
            /* [SWS_Gpt_00326] call EcuM_CheckWakeup fuction */
            EcuM_CheckWakeup( srcRef );
#if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE )
        }
#endif /* #if ( GPT_70_WAKEUP_CONFIGURATION_ENABLE != FALSE ) */
    }
}
#endif /* #if ( GPT_70_IRQ_USE != FALSE ) */
 
 
#define GPT_STOP_SEC_CODE_LOCAL
#include "Gpt_MemMap.h"
 
/* EOF Gpt.c ******************************************************************/
