/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Pwm.c                                                        */
/* Version     : v1.00.00                                                     */
/* Contents    : This specification specifies the functionality,              */
/*               API and the configuration of the AUTOSAR                     */
/*               Basic Software module PWM driver.                            */
/*               Each PWM channel is linked to a hardware PWM                 */
/*               which belongs to the microcontroller.                        */
/*               The type of the PWM signal (for example center Align,        */
/*               left Align, Etc.. ) is not defined within this               */
/*               specification and is left up to the implementation.          */
/*               The driver provides functions for initialization             */
/*               and control of the microcontroller internal PWM stage        */
/*               (pulse width modulation).                                    */
/*               The PWM module generates pulses with variable pulse width.   */
/*               It allows the selection of the duty cycle                    */
/*               and the signal period time.                                  */
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
#include "Pwm.h"            /* [SWS_Pwm_50075] */
#include "SchM_Pwm.h"
#if ( PWM_DEV_ERROR_DETECT != FALSE )
#include "Det.h"            /* [SWS_Pwm_50075] */
#endif  /* #if ( PWM_DEV_ERROR_DETECT != FALSE ) */
 
/*----------------------------------------------------------------------------*/
/* Source File Version Information                                            */
/*----------------------------------------------------------------------------*/
#define PWM_70_VENDOR_ID_C                      (70U)
#define PWM_70_MODULE_ID_C                      (121U)
 
#define PWM_70_AR_RELEASE_MAJOR_VERSION_C       (22U)
#define PWM_70_AR_RELEASE_MINOR_VERSION_C       (11U)
#define PWM_70_AR_RELEASE_REVISION_VERSION_C    (0U)
 
#define PWM_70_SW_MAJOR_VERSION_C               (1U)
#define PWM_70_SW_MINOR_VERSION_C               (0U)
#define PWM_70_SW_PATCH_VERSION_C               (0U)
 
/*----------------------------------------------------------------------------*/
/* File version check                                                         */
/*----------------------------------------------------------------------------*/
/* Pwm.h version check start */
#if ( PWM_70_VENDOR_ID_C != PWM_VENDOR_ID )
    #error "VENDOR ID for Pwm.c and Pwm.h is different"
#endif
 
#if ( PWM_70_MODULE_ID_C != PWM_MODULE_ID )
    #error "MODULE ID for Pwm.c and Pwm.h is different"
#endif
 
#if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_C    != PWM_AR_RELEASE_MAJOR_VERSION )  || \
      ( PWM_70_AR_RELEASE_MINOR_VERSION_C    != PWM_AR_RELEASE_MINOR_VERSION )  || \
      ( PWM_70_AR_RELEASE_REVISION_VERSION_C != PWM_AR_RELEASE_REVISION_VERSION ) )
    #error "AUTOSAR Version Numbers of Pwm.c and Pwm.h are different"
#endif
 
#if ( ( PWM_70_SW_MAJOR_VERSION_C != PWM_SW_MAJOR_VERSION ) || \
      ( PWM_70_SW_MINOR_VERSION_C != PWM_SW_MINOR_VERSION ) || \
      ( PWM_70_SW_PATCH_VERSION_C != PWM_SW_PATCH_VERSION ) )
    #error "Software Version Numbers of Pwm.c and Pwm.h are different"
#endif
/* Pwm.h version check end */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* SchM_Pwm.h version check start */
#if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_C != RTE_AR_RELEASE_MAJOR_VERSION ) || \
      ( PWM_70_AR_RELEASE_MINOR_VERSION_C != RTE_AR_RELEASE_MINOR_VERSION ) )
#error "AutoSar Version Numbers of Pwm.c and SchM_Pwm.h are different"
#endif
/* SchM_Pwm.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* Det.h version check start */
#if ( PWM_DEV_ERROR_DETECT != FALSE )
#if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_C    != DET_AR_RELEASE_MAJOR_VERSION )  || \
      ( PWM_70_AR_RELEASE_MINOR_VERSION_C    != DET_AR_RELEASE_MINOR_VERSION ) )
    #error "AUTOSAR Version Numbers of Pwm.c and Det.h are different"
#endif
#endif  /* #if ( PWM_DEV_ERROR_DETECT != FALSE ) */
/* Det.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
 
/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* global variables                                                           */
/*----------------------------------------------------------------------------*/
#define PWM_START_SEC_VAR_NO_INIT_LOCAL_UNSPECIFIED
#include "Pwm_MemMap.h"
 
Pwm_70_ChannelInfoType Pwm_ChInfo[ PWM_70_NUM_OF_PWMCHANNEL ];
 
#define PWM_STOP_SEC_VAR_NO_INIT_LOCAL_UNSPECIFIED
#include "Pwm_MemMap.h"
 
#define PWM_START_SEC_VAR_INIT_LOCAL_32
#include "Pwm_MemMap.h"
 
Pwm_70_ModuleStateType Pwm_ModuleState = PWM_STATE_UNINIT;   /* Pwm module state */
 
#define PWM_STOP_SEC_VAR_INIT_LOCAL_32
#include "Pwm_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* global functions                                                           */
/*----------------------------------------------------------------------------*/
static void  Pwm_70_CalculateDuty( Pwm_70_ChannelInfoType* chInfoPtr );
 
#define PWM_START_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : PWM_INIT_ID (0x00)                                           */
/* Name        : Pwm_Init                                                     */
/* Param       : (in) ConfigPtr     Pwm ConfigType Pointer                    */
/* Return      : None                                                         */
/* Contents    : Service for PWM initialization.                              */
/* Author      : --                                                           */
/* Note        : [SWS_Pwm_00095]                                              */
/*----------------------------------------------------------------------------*/
void Pwm_Init( const Pwm_ConfigType* ConfigPtr )
{
    uint8_least                         lcount;   /* Loop counter */
    const Pwm_ChannelConfigType*        chPtr;    /* Reference pointer of channel config */
    Pwm_70_ChannelInfoType*             chInfoPtr;
 
#if ( PWM_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Pwm_00201] If ConfigPtr is NULL */
    if ( NULL_PTR == ConfigPtr ) {
        /* [SWS_Pwm_00104][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_INIT_ID,
                                 ( uint8 ) PWM_E_INIT_FAILED );
        /* [SWS_Pwm_00093][SWS_Pwm_00118][SWS_Pwm_00121][SWS_Pwm_00201][SWS_Pwm_50002] If Pwm module has been initialized  */
    } else if ( PWM_STATE_INIT == Pwm_ModuleState ) {
        /* [SWS_Pwm_00104][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_INIT_ID,
                                 ( uint8 ) PWM_E_ALREADY_INITIALIZED );
    } else
#endif  /* #if ( PWM_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Setting lcount-th Pwm channel info using config values */
        for ( lcount = 0U; lcount < ( uint8_least ) PWM_70_NUM_OF_PWMCHANNEL; lcount++ ) {
            /* [SWS_Pwm_00007][SWS_PWM_00052][SWS_Pwm_00062][SWS_Pwm_10009] Initialize parameter */
            chPtr     = &( ConfigPtr->PwmChannelConfigSet->PwmChannel[ lcount ] );
            chInfoPtr = &( Pwm_ChInfo[ lcount ] );
 
            /* [QINeS_SWS_PWM_00002] set Notify Switch of channel PWM_RISING_EDGE */
            chInfoPtr->notifSwitch  = PWM_RISING_EDGE;
            /* [SWS_Pwm_00052] Disable Notification function */
            chInfoPtr->notifEnable  = FALSE;
 
            /* Period, duty cycle, polarity, and idle state are copied to work structure */
            /* for reference in Pwm_SetDutyCycle / Pwm_SetPeriodAndDuty function.        */
            chInfoPtr->period       = chPtr->PwmPeriodDefault;    /* Set configured period       */
            chInfoPtr->duty         = chPtr->PwmDutycycleDefault; /* Set calculated duty cycle   */
            chInfoPtr->idleState    = chPtr->PwmIdleState;        /* Set configuredIdle State    */
            chInfoPtr->activeLevel  = chPtr->PwmPolarity;         /* Set configured polarity     */
 
            /* Copy the address of the configuration structure */
            /* and the address of the structure for HW access. */
            chInfoPtr->ChannelConfigPtr = chPtr;
            chInfoPtr->setChInfoPtr = chPtr->PwmSettingConfigPtr;
 
            /* [QINES_SWS_PWM_00001] Calculate duty cycle */
            Pwm_70_CalculateDuty( chInfoPtr );
            /* Set channel resister and start timer */
            Pwm_70_HW_Init( chInfoPtr, chInfoPtr->activeLevel );
        }
        /* [QINES_SWS_PWM_00004] Set Module state to initialized */
        Pwm_ModuleState = PWM_STATE_INIT;
    }
}
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : PWM_DEINIT_ID (0x01)                                         */
/* Name        : Pwm_DeInit                                                   */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : Service for PWM De-Initialization.                           */
/* Author      : --                                                           */
/* Note        : [SWS_Pwm_00096]                                              */
/*----------------------------------------------------------------------------*/
#if ( PWM_DE_INIT_API != FALSE )    /* [SWS_Pwm_10080][SWS_Pwm_20080] */
void Pwm_DeInit( void )
{
    uint8_least lcount;  /* Loop counter */
 
#if ( PWM_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Pwm_20002][SWS_Pwm_00116] If Pwm module has not been initialized */
    if ( PWM_STATE_UNINIT == Pwm_ModuleState ) {
        /* [SWS_Pwm_00104][SWS_Pwm_10051][SWS_Pwm_20051][SWS_Pwm_00117] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_DEINIT_ID,
                                 ( uint8 ) PWM_E_UNINIT );
    } else
#endif  /* #if ( PWM_DEV_ERROR_DETECT != FALSE ) */
    {
        /* Stop all configured Pwm channels */
        for ( lcount = 0U; lcount < ( uint8_least ) PWM_70_NUM_OF_PWMCHANNEL; lcount++ ) {
            /* [SWS_Pwm_00012] Disable Notification function */
            Pwm_ChInfo[ lcount ].notifEnable  = FALSE;
            /* [SWS_Pwm_00011] Reset channel resister and stop timer */
            Pwm_70_HW_DeInit( &( Pwm_ChInfo[ lcount ] ) );
        }
        /* [SWS_Pwm_00010] Set Module state to uninitialized */
        Pwm_ModuleState = PWM_STATE_UNINIT;
    }
}
#endif  /* #if ( PWM_DE_INIT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : PWM_SETDUTYCYCLE_ID (0x02)                                   */
/* Name        : Pwm_SetDutyCycle                                             */
/* Param       : (in) ChannelNumber     Numeric identifier of the PWM         */
/*             : (in) DutyCycle         duty cycle(0x0000U:0% 0x8000U:100%)   */
/* Return      : None                                                         */
/* Contents    : Service sets the duty cycle of the PWM channel.              */
/* Author      : --                                                           */
/* Note        : [SWS_Pwm_91000]                                              */
/*----------------------------------------------------------------------------*/
#if ( PWM_SET_DUTY_CYCLE_API != FALSE )    /* [SWS_Pwm_10082][SWS_Pwm_20082] */
void Pwm_SetDutyCycle( Pwm_ChannelType ChannelNumber, uint16 DutyCycle ) /* [SWS_Pwm_00119][SWS_Pwm_20086] */
{
    Pwm_70_ChannelInfoType* chInfoPtr;
 
#if ( PWM_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Pwm_20002][SWS_Pwm_00116] If Pwm module has not been initialized */
    if ( PWM_STATE_UNINIT == Pwm_ModuleState ) {
        /* [SWS_Pwm_00104][SWS_Pwm_00117][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_SETDUTYCYCLE_ID,
                                 ( uint8 ) PWM_E_UNINIT );
        /* [SWS_Pwm_00088][SWS_Pwm_30002] If channel number is invalid */
    } else if ( ( Pwm_ChannelType ) PWM_70_NUM_OF_PWMCHANNEL <= ChannelNumber ) {
        /* [SWS_Pwm_00047][SWS_Pwm_00104][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_SETDUTYCYCLE_ID,
                                 ( uint8 ) PWM_E_PARAM_CHANNEL );
    } else
#endif  /* #if ( PWM_DEV_ERROR_DETECT != FALSE ) */
    {
        chInfoPtr = &( Pwm_ChInfo[ChannelNumber] ); /* Get channel Infomation */
 
        chInfoPtr->duty = DutyCycle;                /* Set duty cycle */
 
        Pwm_70_CalculateDuty( chInfoPtr );          /* Calculate duty cycle */
        /* [SWS_Pwm_00013][SWS_Pwm_00018] Set duty cycle to register */
        Pwm_70_HW_SetDutyCycle( chInfoPtr );
    }
}
#endif  /* #if ( PWM_SET_DUTY_CYCLE_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : PWM_SETPERIODANDDUTY_ID (0x03)                               */
/* Name        : Pwm_SetPeriodAndDuty                                         */
/* Param       : (in) ChannelNumber     Numeric identifier of the PWM         */
/*             : (in) Period            Period of the PWM signal              */
/*             : (in) DutyCycle         duty cycle(0x0000U:0% 0x8000U:100%)   */
/* Return      : None                                                         */
/* Contents    : Service sets the period and the duty cycle of a PWM channel  */
/* Author      : --                                                           */
/* Note        : [SWS_Pwm_91001]                                              */
/*----------------------------------------------------------------------------*/
#if ( PWM_SET_PERIOD_AND_DUTY_API != FALSE )    /* [SWS_Pwm_10083][SWS_Pwm_20083] */
void Pwm_SetPeriodAndDuty( Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle )   /* [SWS_Pwm_10086] */
{
    Pwm_70_ChannelInfoType*             chInfoPtr;
 
#if ( PWM_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Pwm_00116][SWS_Pwm_20002] If Pwm module has not been initialized */
    if ( PWM_STATE_UNINIT == Pwm_ModuleState ) {
        /* [SWS_Pwm_00104][SWS_Pwm_00117][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_SETPERIODANDDUTY_ID,
                                 ( uint8 ) PWM_E_UNINIT );
    /* [SWS_Pwm_00088][SWS_Pwm_30002] If channel number is invalid */
    } else if ( ( Pwm_ChannelType ) PWM_70_NUM_OF_PWMCHANNEL <= ChannelNumber ) {
        /* [SWS_Pwm_00047][SWS_Pwm_00104][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_SETPERIODANDDUTY_ID,
                                 ( uint8 ) PWM_E_PARAM_CHANNEL );
    } else
#endif  /* #if ( PWM_DEV_ERROR_DETECT != FALSE ) */
    {
        chInfoPtr = &( Pwm_ChInfo[ChannelNumber] ); /* Get channel Infomation */
 
#if ( PWM_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Pwm_00041][SWS_Pwm_40002] If there is unauthorized use */
        if ( PWM_VARIABLE_PERIOD != chInfoPtr->ChannelConfigPtr->PwmChannelClass ) {
            /* [SWS_Pwm_00045][SWS_Pwm_00104][SWS_Pwm_10051][SWS_Pwm_20051] */
            ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                     ( uint8 ) PWM_70_INSTANCE_ID,
                                     ( uint8 ) PWM_70_SETPERIODANDDUTY_ID,
                                     ( uint8 ) PWM_E_PERIOD_UNCHANGEABLE );
        } else
#endif  /* #if ( PWM_DEV_ERROR_DETECT != FALSE ) */
        {
            chInfoPtr->period = Period;         /* Set period           */
            chInfoPtr->duty   = DutyCycle;      /* Set duty cycle       */
            Pwm_70_CalculateDuty( chInfoPtr );  /* Calculate duty cycle */
 
            /* [SWS_Pwm_00019][SWS_Pwm_00020] Set duty cycle and period to register */
            Pwm_70_HW_SetPeriodAndDuty( chInfoPtr );
        }
    }
}
#endif  /* #if ( PWM_SET_PERIOD_AND_DUTY_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : PWM_SETOUTPUTTOIDLE_ID (0x04)                                */
/* Name        : Pwm_SetOutputToIdle                                          */
/* Param       : (in) ChannelNumber     Numeric identifier of the PWM         */
/* Return      : None                                                         */
/* Contents    : Service sets the PWM output to the configured Idle state.    */
/* Author      : --                                                           */
/* Note        : [SWS_Pwm_91002]                                              */
/*----------------------------------------------------------------------------*/
#if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE )    /* [SWS_Pwm_10084][SWS_Pwm_20084] */
void Pwm_SetOutputToIdle( Pwm_ChannelType ChannelNumber )
{
    Pwm_70_ChannelInfoType*             chInfoPtr;
 
#if ( PWM_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Pwm_00116][SWS_Pwm_20002] If Pwm module has not been initialized */
    if ( PWM_STATE_UNINIT == Pwm_ModuleState ) {
        /* [SWS_Pwm_00104][SWS_Pwm_00117][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_SETOUTPUTTOIDLE_ID,
                                 ( uint8 ) PWM_E_UNINIT );
    /* [SWS_Pwm_00088][SWS_Pwm_30002] If channel number is invalid */
    } else if ( ( Pwm_ChannelType ) PWM_70_NUM_OF_PWMCHANNEL <= ChannelNumber ) {
        /* [SWS_Pwm_00047][SWS_Pwm_00104][SWS_Pwm_10051][SWS_Pwm_20051] */
        /* Report error code PWM_E_PARAM_CHANNEL */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_SETOUTPUTTOIDLE_ID,
                                 ( uint8 ) PWM_E_PARAM_CHANNEL );
    } else
#endif  /* #if ( PWM_DEV_ERROR_DETECT != FALSE ) */
    {
        chInfoPtr = &( Pwm_ChInfo[ChannelNumber] ); /* Get channel Infomation */
        /* [SWS_Pwm_00021] Pwm output to the configured idle state. */
        Pwm_70_HW_SetOutputToIdle( chInfoPtr );
    }
}
#endif  /* #if ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : PWM_GETOUTPUTSTATE_ID (0x05)                                 */
/* Name        : Pwm_GetOutputState                                           */
/* Param       : (in)  ChannelNumber     Numeric identifier of the PWM        */
/* Return      : (out) Current state of PWM waveform(PWM_HIGH or PWM_LOW)     */
/* Contents    : Service to read the internal state of the PWM output signal. */
/* Author      : --                                                           */
/* Note        : [SWS_Pwm_00100]                                              */
/*----------------------------------------------------------------------------*/
#if ( PWM_GET_OUTPUT_STATE_API != FALSE )    /* [SWS_Pwm_10085][SWS_Pwm_20085] */
Pwm_OutputStateType Pwm_GetOutputState( Pwm_ChannelType ChannelNumber )
{
    Pwm_OutputStateType     retStat = PWM_LOW;      /* [SWS_Pwm_30051] Return value */
 
#if ( PWM_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Pwm_00116][SWS_Pwm_20002] If Pwm module has not been initialized */
    if ( PWM_STATE_UNINIT == Pwm_ModuleState ) {
        /* [SWS_Pwm_00104][SWS_Pwm_00117][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_GETOUTPUTSTATE_ID,
                                 ( uint8 ) PWM_E_UNINIT );
        /* [SWS_Pwm_00088][SWS_Pwm_30002] If channel number is invalid */
    } else if ( ( Pwm_ChannelType ) PWM_70_NUM_OF_PWMCHANNEL <= ChannelNumber ) {
        /* [SWS_Pwm_00047][SWS_Pwm_00104][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_GETOUTPUTSTATE_ID,
                                 ( uint8 ) PWM_E_PARAM_CHANNEL );
    } else
#endif  /* #if ( PWM_DEV_ERROR_DETECT != FALSE ) */
    {
        /* [SWS_Pwm_00022] Get waveform state */
        retStat = Pwm_70_HW_GetOutputState( &( Pwm_ChInfo[ ChannelNumber ] ) );
    }
    return retStat;
}
#endif  /* #if ( PWM_GET_OUTPUT_STATE_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : PWM_DISABLENOTIFICATION_ID (0x06)                            */
/* Name        : Pwm_DisableNotification                                      */
/* Param       : (in) ChannelNumber     Numeric identifier of the PWM         */
/* Return      : None                                                         */
/* Contents    : Service to disable the PWM signal edge notification.         */
/* Author      : --                                                           */
/* Note        : [SWS_Pwm_91003]                                              */
/*----------------------------------------------------------------------------*/
#if ( PWM_NOTIFICATION_SUPPORTED != FALSE )    /* [SWS_Pwm_10112][SWS_Pwm_20112][SWS_Pwm_20115] */
void Pwm_DisableNotification( Pwm_ChannelType ChannelNumber )
{
#if ( PWM_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Pwm_00116][SWS_Pwm_20002] If Pwm module has not been initialized */
    if ( PWM_STATE_UNINIT == Pwm_ModuleState ) {
        /* [SWS_Pwm_00104][SWS_Pwm_00117][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_DISABLENOTIFICATION_ID,
                                 ( uint8 ) PWM_E_UNINIT );
        /* [SWS_Pwm_00088][SWS_Pwm_30002] If channel number is invalid */
    } else if ( ( Pwm_ChannelType ) PWM_70_NUM_OF_PWMCHANNEL <= ChannelNumber ) {
        /* [SWS_Pwm_00047][SWS_Pwm_00104][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_DISABLENOTIFICATION_ID,
                                 ( uint8 ) PWM_E_PARAM_CHANNEL );
    } else
#endif  /* #if ( PWM_DEV_ERROR_DETECT != FALSE ) */
    {
        /* [SWS_Pwm_00023] Invalidate notification edge */
        Pwm_ChInfo[ChannelNumber].notifEnable = FALSE;
        /* [QINeS_SWS_PWM_00002] Initialize notification switch */
        Pwm_ChInfo[ChannelNumber].notifSwitch = PWM_RISING_EDGE;
    }
}
#endif  /* #if ( PWM_NOTIFICATION_SUPPORTED != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : PWM_ENABLENOTIFICATION_ID (0x07)                             */
/* Name        : Pwm_EnableNotification                                       */
/* Param       : (in) ChannelNumber     Numeric identifier of the PWM         */
/*             : (in) Notification      Type of notification                  */
/* Return      : None                                                         */
/* Contents    : Service to enable the PWM signal edge notification according */
/*               to notification parameter.                                   */
/* Author      : --                                                           */
/* Note        : [SWS_Pwm_91004]                                              */
/*----------------------------------------------------------------------------*/
#if ( PWM_NOTIFICATION_SUPPORTED != FALSE )    /* [SWS_Pwm_10113][SWS_Pwm_20113][SWS_Pwm_0115] */
void Pwm_EnableNotification( Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification )
{
#if ( PWM_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Pwm_00116][SWS_Pwm_20002] If Pwm module has not been initialized */
    if ( PWM_STATE_UNINIT == Pwm_ModuleState ) {
        /* [SWS_Pwm_00104][SWS_Pwm_00117][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_ENABLENOTIFICATION_ID,
                                 ( uint8 ) PWM_E_UNINIT );
        /* [SWS_Pwm_00088][SWS_Pwm_30002] If channel number is invalid */
    } else if ( ( Pwm_ChannelType ) PWM_70_NUM_OF_PWMCHANNEL <= ChannelNumber ) {
        /* [SWS_Pwm_00047][SWS_Pwm_00104][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_ENABLENOTIFICATION_ID,
                                 ( uint8 ) PWM_E_PARAM_CHANNEL );
    } else
#endif  /* #if ( PWM_DEV_ERROR_DETECT != FALSE ) */
    {
        /* [SWS_Pwm_00024] */
        Pwm_ChInfo[ChannelNumber].notifSwitch = Notification;
        /* set Notify flag of channel TRUE */
        Pwm_ChInfo[ChannelNumber].notifEnable = TRUE;
    }
}
#endif   /* #if ( PWM_NOTIFICATION_SUPPORTED != FALSE ) */
 
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : PWM_GET_VERSION_INFO_ID (0x08)                               */
/* Name        : Pwm_GetVersionInfo                                           */
/* Param       : (out) versioninfo       Pointer to where to store the        */
/*                                       version information of this module.  */
/* Return      : None                                                         */
/* Contents    : Service returns the version information of this module.      */
/* Author      : --                                                           */
/* Note        : [SWS_Pwm_00103]                                              */
/*----------------------------------------------------------------------------*/
#if ( PWM_VERSION_INFO_API != FALSE )    /* [ECUC_Pwm_00135] */
void Pwm_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
#if ( PWM_DEV_ERROR_DETECT != FALSE )
    /* [SWS_Pwm_00201] If versioninfo is NULL */
    if ( NULL_PTR == versioninfo ) {
        /* [SWS_Pwm_00104][SWS_Pwm_10051][SWS_Pwm_20051] */
        ( void )Det_ReportError( ( uint16 )PWM_MODULE_ID,
                                 ( uint8 ) PWM_70_INSTANCE_ID,
                                 ( uint8 ) PWM_70_GET_VERSION_INFO_ID,
                                 ( uint8 ) PWM_E_PARAM_POINTER );
    } else
#endif  /* #if ( PWM_DEV_ERROR_DETECT != FALSE ) */
    {
        /* [SWS_Pwm_00052] Get Pwm version infomation */
        versioninfo->vendorID         = ( uint16 )PWM_VENDOR_ID;         /* Vendor ID */
        versioninfo->moduleID         = ( uint16 )PWM_MODULE_ID;         /* Module ID */
        versioninfo->sw_major_version = ( uint8 ) PWM_SW_MAJOR_VERSION;  /* Software Major Version */
        versioninfo->sw_minor_version = ( uint8 ) PWM_SW_MINOR_VERSION;  /* Software Minor Version */
        versioninfo->sw_patch_version = ( uint8 ) PWM_SW_PATCH_VERSION;  /* Software Patch Version */
    }
}
#endif  /* #if ( PWM_VERSION_INFO_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_CalculateDuty                                         */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : None                                                         */
/* Contents    : Service calculates duty cycle value.                         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void  Pwm_70_CalculateDuty( Pwm_70_ChannelInfoType* chInfoPtr )
{
    Pwm_PeriodType setPeriod;        /* value of period */
    uint32         calculateDuty;    /* value of duty cycle */
    uint16         setDuty;          /* value of duty cycle set to register */
 
    /* [QINeS_SWS_PWM_00001] Check if the duty cycle is greater than 100% */
    if ( PWM_70_100PER < chInfoPtr->duty ) {
        calculateDuty = PWM_70_100PER;
    } else {
        calculateDuty = chInfoPtr->duty;
    }
 
    if ( 0U != calculateDuty ) {
        setPeriod = chInfoPtr->period;
        /* [SWS_Pwm_00059] Calculation of duty cycle for Pwm period */
        setDuty   = ( uint16 )( ( calculateDuty * ( uint32 )setPeriod ) >> 15U );
    } else {
        setDuty   = 0U;
    }
 
    chInfoPtr->duty = setDuty;  /* set duty cycle */
}
 
#define PWM_STOP_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"
 
/* EOF Pwm.c ******************************************************************/
 