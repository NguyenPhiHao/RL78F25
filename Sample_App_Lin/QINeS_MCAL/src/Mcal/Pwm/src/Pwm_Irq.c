/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Pwm_Irq.c                                                    */
/* Version     : v1.00.01                                                     */
/* Contents    : PWM Driver Ram State IRQ implementation                      */
/*               The MCU is a basic software module at the service layer of   */
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
#include "Pwm.h"                    /* [SWS_Pwm_70075] */
#include "Pwm_Irq.h"
 
/*----------------------------------------------------------------------------*/
/* Source File Version Information                                            */
/*----------------------------------------------------------------------------*/
#define PWM_70_VENDOR_ID_IRQ_C                      (70U)
#define PWM_70_MODULE_ID_IRQ_C                      (121U)
 
#define PWM_70_AR_RELEASE_MAJOR_VERSION_IRQ_C       (22U)
#define PWM_70_AR_RELEASE_MINOR_VERSION_IRQ_C       (11U)
#define PWM_70_AR_RELEASE_REVISION_VERSION_IRQ_C    (0U)
 
#define PWM_70_SW_MAJOR_VERSION_IRQ_C               (1U)
#define PWM_70_SW_MINOR_VERSION_IRQ_C               (0U)
#define PWM_70_SW_PATCH_VERSION_IRQ_C               (0U)
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Pwm.h version check start */
#if ( PWM_70_VENDOR_ID_IRQ_C != PWM_VENDOR_ID )
    #error "VENDOR ID for Pwm_Irq.c and Pwm.h is different"
#endif
 
#if ( PWM_70_MODULE_ID_IRQ_C != PWM_MODULE_ID )
    #error "MODULE ID for Pwm_Irq.c and Pwm.h is different"
#endif
 
#if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_IRQ_C    != PWM_AR_RELEASE_MAJOR_VERSION )  || \
      ( PWM_70_AR_RELEASE_MINOR_VERSION_IRQ_C    != PWM_AR_RELEASE_MINOR_VERSION )  || \
      ( PWM_70_AR_RELEASE_REVISION_VERSION_IRQ_C != PWM_AR_RELEASE_REVISION_VERSION ) )
    #error "AUTOSAR Version Numbers of Pwm_Irq.c and Pwm.h are different"
#endif
 
#if ( ( PWM_70_SW_MAJOR_VERSION_IRQ_C != PWM_SW_MAJOR_VERSION ) || \
      ( PWM_70_SW_MINOR_VERSION_IRQ_C != PWM_SW_MINOR_VERSION ) || \
      ( PWM_70_SW_PATCH_VERSION_IRQ_C != PWM_SW_PATCH_VERSION ) )
    #error "Software Version Numbers of Pwm_Irq.c and Pwm.h are different"
#endif
/* Pwm.h version check end */
 
/* Pwm_Irq.h version check start */
#if ( PWM_70_VENDOR_ID_IRQ_C != PWM_70_VENDOR_ID_IRQ_H )
    #error "VENDOR ID for Pwm_Irq.c and Pwm_Irq.h is different"
#endif
 
#if ( PWM_70_MODULE_ID_IRQ_C != PWM_70_MODULE_ID_IRQ_H )
    #error "MODULE ID for Pwm_Irq.c and Pwm_Irq.h is different"
#endif
 
#if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_IRQ_C    != PWM_70_AR_RELEASE_MAJOR_VERSION_IRQ_H )  || \
      ( PWM_70_AR_RELEASE_MINOR_VERSION_IRQ_C    != PWM_70_AR_RELEASE_MINOR_VERSION_IRQ_H )  || \
      ( PWM_70_AR_RELEASE_REVISION_VERSION_IRQ_C != PWM_70_AR_RELEASE_REVISION_VERSION_IRQ_H ) )
    #error "AUTOSAR Version Numbers of Pwm_Irq.c and Pwm_Irq.h are different"
#endif
 
#if ( ( PWM_70_SW_MAJOR_VERSION_IRQ_C != PWM_70_SW_MAJOR_VERSION_IRQ_H ) || \
      ( PWM_70_SW_MINOR_VERSION_IRQ_C != PWM_70_SW_MINOR_VERSION_IRQ_H ) || \
      ( PWM_70_SW_PATCH_VERSION_IRQ_C != PWM_70_SW_PATCH_VERSION_IRQ_H ) )
    #error "Software Version Numbers of Pwm_Irq.c and Pwm_Irq.h are different"
#endif
/* Pwm_Irq.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef Pwm_OutputStateType ( *Pwm_70_HW_IsrCheckEdgeFuncType )
                ( const Pwm_70_ChannelInfoType* chInfoPtr, uint8 timerMode );
 
/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"
 
static const Pwm_70_HW_IsrCheckEdgeFuncType
s_Pwm_HwIsrCheckEdgeFuncTbl[ PWM_70_HW_TIMERTYPE_NUM ] = {
    ( Pwm_70_HW_IsrCheckEdgeFuncType ) &Pwm_70_RL78F2X_TAU_IsrCheckEdge,
    ( Pwm_70_HW_IsrCheckEdgeFuncType ) &Pwm_70_RL78F2X_TRD_IsrCheckEdge
};
 
#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
 
#define PWM_START_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU00                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 00 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_A0_USE != FALSE )
void Pwm_70_Isr_TAU00( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_A0, PWM_70_RL78F2X_TIMERMODE_MASTER );
}
#endif  /* #if ( PWM_70_CHANNEL_A0_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU01                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 01 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_A0_USE != FALSE )
void Pwm_70_Isr_TAU01( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_A0, PWM_70_RL78F2X_TIMERMODE_SLAVE );
}
#endif  /* #if ( PWM_70_CHANNEL_A0_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU02                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 02 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_A1_USE != FALSE )
void Pwm_70_Isr_TAU02( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_A1, PWM_70_RL78F2X_TIMERMODE_MASTER );
}
#endif  /* #if ( PWM_70_CHANNEL_A1_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU03                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 03 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_A1_USE != FALSE )
void Pwm_70_Isr_TAU03( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_A1, PWM_70_RL78F2X_TIMERMODE_SLAVE );
}
#endif  /* #if ( PWM_70_CHANNEL_A1_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU04                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 04 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_A2_USE != FALSE )
void Pwm_70_Isr_TAU04( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_A2, PWM_70_RL78F2X_TIMERMODE_MASTER );
}
#endif  /* #if ( PWM_70_CHANNEL_A2_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU05                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 05 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_A2_USE != FALSE )
void Pwm_70_Isr_TAU05( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_A2, PWM_70_RL78F2X_TIMERMODE_SLAVE );
}
#endif  /* #if ( PWM_70_CHANNEL_A2_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU06                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 06 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_A3_USE != FALSE )
void Pwm_70_Isr_TAU06( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_A3, PWM_70_RL78F2X_TIMERMODE_MASTER );
}
#endif  /* #if ( PWM_70_CHANNEL_A3_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU07                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 07 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_A3_USE != FALSE )
void Pwm_70_Isr_TAU07( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_A3, PWM_70_RL78F2X_TIMERMODE_SLAVE );
}
#endif  /* #if ( PWM_70_CHANNEL_A3_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU10                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 10 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_B0_USE != FALSE )
void Pwm_70_Isr_TAU10( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_B0, PWM_70_RL78F2X_TIMERMODE_MASTER );
}
#endif  /* #if ( PWM_70_CHANNEL_B0_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU11                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 11 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_B0_USE != FALSE )
void Pwm_70_Isr_TAU11( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_B0, PWM_70_RL78F2X_TIMERMODE_SLAVE );
}
#endif  /* #if ( PWM_70_CHANNEL_B0_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU12                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 12 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_B1_USE != FALSE )
void Pwm_70_Isr_TAU12( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_B1, PWM_70_RL78F2X_TIMERMODE_MASTER );
}
#endif  /* #if ( PWM_70_CHANNEL_B1_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU13                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 13 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_B1_USE != FALSE )
void Pwm_70_Isr_TAU13( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_B1, PWM_70_RL78F2X_TIMERMODE_SLAVE );
}
#endif  /* #if ( PWM_70_CHANNEL_B1_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU14                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 14 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_B2_USE != FALSE )
void Pwm_70_Isr_TAU14( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_B2, PWM_70_RL78F2X_TIMERMODE_MASTER );
}
#endif  /* #if ( PWM_70_CHANNEL_B2_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU15                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 15 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_B2_USE != FALSE )
void Pwm_70_Isr_TAU15( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_B2, PWM_70_RL78F2X_TIMERMODE_SLAVE );
}
#endif  /* #if ( PWM_70_CHANNEL_B2_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU16                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 16 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_B3_USE != FALSE )
void Pwm_70_Isr_TAU16( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_B3, PWM_70_RL78F2X_TIMERMODE_MASTER );
}
#endif  /* #if ( PWM_70_CHANNEL_B3_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TAU17                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TAU 17 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_B3_USE != FALSE )
void Pwm_70_Isr_TAU17( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TAU_B3, PWM_70_RL78F2X_TIMERMODE_SLAVE );
}
#endif  /* #if ( PWM_70_CHANNEL_B3_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TRD00                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TRD 00 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_TRD00_USE != FALSE )
void Pwm_70_Isr_TRD00( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TRD_00, PWM_70_RL78F2X_TIMERMODE_MASTER );
}
#endif  /* #if ( PWM_70_CHANNEL_TRD0_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_TRD01                                             */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : PWM TRD 01 interrupt handler                                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( PWM_70_CHANNEL_TRD01_USE != FALSE )
void Pwm_70_Isr_TRD01( void )
{
    Pwm_70_Isr_Common( PWM_70_IDX_TRD_01, PWM_70_RL78F2X_TIMERMODE_MASTER );
}
#endif  /* #if ( PWM_70_CHANNEL_TRD01_USE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_Isr_Common                                            */
/* Param       : (in) channelNumber     PWM channel                           */
/*               (in) timerMode         how to use the timer(master or slave) */
/* Return      : None                                                         */
/* Contents    : Perform interrupt common control                             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Pwm_70_Isr_Common( Pwm_ChannelType channelNumber, uint8 timerMode )
{
    Pwm_70_ChannelInfoType*               chInfoPtr;
    Pwm_OutputStateType                   WaveformStat;
   
    chInfoPtr = &( Pwm_ChInfo[ channelNumber ] );
    /* [SWS_Pwm_00026] Set TRD Timer Counter Register to stop */
    Pwm_70_HW_ClrInt( chInfoPtr );
 
    /* [QINES_SWS_PWM_00003] Interrupts when uninitialized are not accepted */
    if ( PWM_STATE_UNINIT == Pwm_ModuleState ) {
        /* DO NOTHING */
    } else {
        /* [SWS_Pwm_00025] Confirm notification necessity */
        WaveformStat = Pwm_70_HW_IsrCheckEdge( chInfoPtr, timerMode );
        if ( chInfoPtr->notifEnable != ( bool_t ) FALSE ) {
            if ( NULL_PTR != chInfoPtr->ChannelConfigPtr->Pwm_Notification ) {
                if (     ( PWM_BOTH_EDGES == chInfoPtr->notifSwitch )
                    || ( ( PWM_FALLING_EDGE == chInfoPtr->notifSwitch )
                    && (   PWM_LOW == WaveformStat ) )
                    || ( ( PWM_RISING_EDGE == chInfoPtr->notifSwitch )
                    && (   PWM_HIGH == WaveformStat ) )){
                    /* Execute callback function */
                    chInfoPtr->ChannelConfigPtr->Pwm_Notification();
                } else {
                    /* When notifSwitch is not configrated, do nothing */
                }
            } else {
                /* When notification is not configrated, do nothing. */
            }
        } else {
            /* When edge notification is invalid, do nothing. */
        }
    }
}
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_HW_IsrCheckEdge                                       */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/*               (in) timerMode  Timer application                            */
/* Return      : (out) Current state of PWM waveform(PWM_HIGH or PWM_LOW)     */
/* Contents    : Call immediate switching processing                          */
/*               of the unit corresponding to the channel given as argument   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Pwm_OutputStateType Pwm_70_HW_IsrCheckEdge
( const Pwm_70_ChannelInfoType* chInfoPtr, uint8 timerMode )
{
    Pwm_70_HW_IsrCheckEdgeFuncType  isrCheckEdgeFuncPtr;
 
    isrCheckEdgeFuncPtr =
        s_Pwm_HwIsrCheckEdgeFuncTbl[ chInfoPtr->ChannelConfigPtr->PwmSettingConfigPtr->timerType ];
    return ( isrCheckEdgeFuncPtr )( chInfoPtr, timerMode );
}
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_RL78F2X_TAU_IsrCheckEdge                              */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/*               (in) timerMode  how to use the timer(master or slave)        */
/* Return      : (out) Current state of PWM waveform(high or low)             */
/* Contents    : Perform immediate switching processing of TAU                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Pwm_OutputStateType Pwm_70_RL78F2X_TAU_IsrCheckEdge
( const Pwm_70_ChannelInfoType* chInfoPtr, uint8 timerMode )
{
    Pwm_OutputStateType         retStat;         /* PWM_LOW or PWM_HIGH */
 
    /* When timer mode is slave */
    if ( ( uint8 ) PWM_70_RL78F2X_TIMERMODE_SLAVE == timerMode ) {
        if ( chInfoPtr->activeLevel == PWM_HIGH ) {
            /* flip the active level because the interrupt of slave channel occurs */
            /* when output waveform is switched.                                   */
            retStat = PWM_LOW;
        } else {
            retStat = PWM_HIGH;
        }
    } else {    /* When timer mode is master */
        retStat = chInfoPtr->activeLevel;   /* return configrated active level */
    }
    return retStat;
}
 
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_RL78F2X_TRD_IsrCheckEdge                              */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/*               (in) timerMode  how to use the timer(master or slave)        */
/* Return      : (out) Current state of PWM waveform(high or low)             */
/* Contents    : Perform immediate switching processing of TRD                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Pwm_OutputStateType Pwm_70_RL78F2X_TRD_IsrCheckEdge
( const Pwm_70_ChannelInfoType* chInfoPtr, uint8 timerMode )
{
    const Pwm_70_RL78F2X_TRD_ConfType*      SettingConfPtr;     /* TRD register information */
    const Pwm_70_RL78F2X_TRD_RegInfoType*   MasterRegInfoPtr;   /* TRD register information for master channel */
    uint16                                  regTRD;             /* TRDx counter value */
    uint16                                  regTRDGRA;          /* TRDGRA value */
    uint16                                  regTRDGRB;          /* TRDGRB value */
    Pwm_OutputStateType                     retStat;            /* return value */
 
    /* Get TRD register information */    
    SettingConfPtr   = ( const Pwm_70_RL78F2X_TRD_ConfType* )( chInfoPtr->setChInfoPtr );
    MasterRegInfoPtr = SettingConfPtr->mastarRegInfoPtr;
   
    /* Get present value of TRD and TRDGRA and TRDGRB */
    regTRD    = MasterRegInfoPtr->contPtr->regTrd;
    regTRDGRA = MasterRegInfoPtr->contPtr->regTrdGra;
    regTRDGRB = MasterRegInfoPtr->contPtr->regTrdGrb;
   
    /* If TRDGRA value equals TRDGRB value, return  inverse of active level. */
    /* ( because duty cycle is 0% )                                          */
    /* If TRD value larger than TRDGRB value, flip the active level          */
    if ( ( regTRDGRB == 0U ) || ( regTRDGRB >= regTRDGRA )  ) {    /* When IDLE State Waveform */
        if ( PWM_RISING_EDGE == chInfoPtr->notifSwitch ) {
            retStat = PWM_LOW;
        } else {
            retStat = PWM_HIGH;
        }
    } else if ( regTRD > regTRDGRB ) {
        /* Flip the active level. */
        if ( chInfoPtr->activeLevel == PWM_HIGH ) {
            retStat = PWM_LOW;
        } else {
            retStat = PWM_HIGH;
        }
    } else {     /* When the Waveform state is active */
        retStat = chInfoPtr->activeLevel;   /* return configrated active level */
    }
    return retStat;
}
 
#define PWM_STOP_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"
 
/* EOF Pwm_Irq.c **************************************************************/
 