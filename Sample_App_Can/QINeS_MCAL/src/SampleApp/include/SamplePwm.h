/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : SamplePwm.h                                                  */
/* Version     : v1.00.01                                                     */
/* Contents    : Pwm sample application header file.                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
#ifndef SAMPLE_PWM_H_
#define SAMPLE_PWM_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Sample.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define SAMPLE_PWM_INTERRUPT_ENABLE    FALSE

#if ( ( SAMPLE_PWM_ENABLE != FALSE ) && ( SAMPLE_PWM_INTERRUPT_ENABLE != FALSE ) )
#define MK0H_PWM_MASK   ( 0xE7U )
#define MK1L_PWM_MASK   ( 0x8FU )
#define MK2L_PWM_MASK   ( 0x7FU )
#define MK2H_PWM_MASK   ( 0x8DU )
#define MK3L_PWM_MASK   ( 0xFFU )
#define MK3H_PWM_MASK   ( 0xFAU )
#else
#define MK0H_PWM_MASK   ( 0xFFU )
#define MK1L_PWM_MASK   ( 0xFFU )
#define MK2L_PWM_MASK   ( 0xFFU )
#define MK2H_PWM_MASK   ( 0xFFU )
#define MK3L_PWM_MASK   ( 0xFFU )
#define MK3H_PWM_MASK   ( 0xFFU )
#endif

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

#if ( SAMPLE_PWM_ENABLE != FALSE )
void SamplePwm( void );
#endif

#endif  /* SAMPLE_PWM_H_ */
