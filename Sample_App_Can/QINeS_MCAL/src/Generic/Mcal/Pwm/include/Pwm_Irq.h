/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Pwm_Irq.h                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : PWM Driver Ram State IRQ header                              */
/*               The PWM is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of PWM Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef PWM_IRQ_H
#define PWM_IRQ_H

/*----------------------------------------------------------------------------*/
/* Source File Version Information                             */
/*----------------------------------------------------------------------------*/
#define PWM_70_VENDOR_ID_IRQ_H                ( 70U )
#define PWM_70_MODULE_ID_IRQ_H                (121U )

#define PWM_70_AR_RELEASE_MAJOR_VERSION_IRQ_H ( 22U )
#define PWM_70_AR_RELEASE_MINOR_VERSION_IRQ_H ( 11U )
#define PWM_70_AR_RELEASE_REVISION_VERSION_IRQ_H ( 00U )

#define PWM_70_SW_MAJOR_VERSION_IRQ_H         (  1U )
#define PWM_70_SW_MINOR_VERSION_IRQ_H         (  0U )
#define PWM_70_SW_PATCH_VERSION_IRQ_H         (  0U )

/*----------------------------------------------------------------------------*/
/* type definitions                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#define PWM_START_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"

#if ( PWM_70_CHANNEL_A0_USE != FALSE )
extern void Pwm_70_Isr_TAU00( void );
extern void Pwm_70_Isr_TAU01( void );
#endif /* #if ( PWM_70_CHANNEL_A0_USE != FALSE ) */

#if ( PWM_70_CHANNEL_A1_USE != FALSE )
extern void Pwm_70_Isr_TAU02( void );
extern void Pwm_70_Isr_TAU03( void );
#endif /* #if ( PWM_70_CHANNEL_A1_USE != FALSE ) */

#define PWM_STOP_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"

#if ( PWM_70_CHANNEL_A2_USE != FALSE )
extern void Pwm_70_Isr_TAU04( void );
extern void Pwm_70_Isr_TAU05( void );
#endif  /* if ( PWM_70_CHANNEL_A2_USE != FALSE ) */

#if ( PWM_70_CHANNEL_A3_USE != FALSE )
extern void Pwm_70_Isr_TAU06( void );
extern void Pwm_70_Isr_TAU07( void );
#endif  /* if ( PWM_70_CHANNEL_A3_USE != FALSE ) */

#if ( PWM_70_CHANNEL_B0_USE != FALSE )
extern void Pwm_70_Isr_TAU10( void );
extern void Pwm_70_Isr_TAU11( void );
#endif  /* if ( PWM_70_CHANNEL_B0_USE != FALSE ) */

#if ( PWM_70_CHANNEL_B1_USE != FALSE )
extern void Pwm_70_Isr_TAU12( void );
extern void Pwm_70_Isr_TAU13( void );
#endif  /* if ( PWM_70_CHANNEL_B1_USE != FALSE ) */

#if ( PWM_70_CHANNEL_B2_USE != FALSE )
extern void Pwm_70_Isr_TAU14( void );
extern void Pwm_70_Isr_TAU15( void );
#endif  /* if ( PWM_70_CHANNEL_B2_USE != FALSE ) */

#if ( PWM_70_CHANNEL_B3_USE != FALSE )
extern void Pwm_70_Isr_TAU16( void );
extern void Pwm_70_Isr_TAU17( void );
#endif  /* if ( PWM_70_CHANNEL_B3_USE != FALSE ) */

#if ( PWM_70_CHANNEL_TRD00_USE != FALSE )
extern void Pwm_70_Isr_TRD00( void );
#endif  /* if ( PWM_70_CHANNEL_TRD00_USE != FALSE ) */

#if ( PWM_70_CHANNEL_TRD01_USE != FALSE )
extern void Pwm_70_Isr_TRD01( void );
#endif  /* if ( PWM_70_CHANNEL_TRD01_USE != FALSE ) */

/* common interrupt handler for all timer channels */
void Pwm_70_Isr_Common( Pwm_ChannelType channelNumber, uint8 timerMode );

/* helper to determine edge for a given channel */
Pwm_OutputStateType Pwm_70_HW_IsrCheckEdge(
    const Pwm_70_ChannelInfoType* chInfoPtr,
    uint8                         timerMode
);

Pwm_OutputStateType Pwm_70_RL78F2X_TAU_IsrCheckEdge(
    const Pwm_70_ChannelInfoType* chInfoPtr,
    uint8                         timerMode
);

Pwm_OutputStateType Pwm_70_RL78F2X_TRD_IsrCheckEdge(
    const Pwm_70_ChannelInfoType* chInfoPtr,
    uint8                         timerMode
);

#define PWM_STOP_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"

#endif  /* PWM_IRQ_H */

/* EOF Pwm_Irq.h ****************************************************/
