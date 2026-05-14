/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : SampleIcu.h                                                  */
/* Version     : v1.00.01                                                     */
/* Contents    : Icu sample application header file.                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
#ifndef SAMPLE_ICU_H_
#define SAMPLE_ICU_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Icu.h"
#include "Sample.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#if ( SAMPLE_ICU_ENABLE != FALSE )
  #define MK0L_ICU_MASK   ( 0xBFU )
  #define MK0H_ICU_MASK   ( 0xE6U )
  #define MK1L_ICU_MASK   ( 0x8FU )
  #define MK1H_ICU_MASK   ( 0x7FU )
  #define MK2L_ICU_MASK   ( 0x89U )
  #define MK2H_ICU_MASK   ( 0xFFU )
  #define MK3L_ICU_MASK   ( 0xFFU )
  #define MK3H_ICU_MASK   ( 0x02U )
#else
  #define MK0L_ICU_MASK   ( 0xFFU )
  #define MK0H_ICU_MASK   ( 0xFFU )
  #define MK1L_ICU_MASK   ( 0xFFU )
  #define MK1H_ICU_MASK   ( 0xFFU )
  #define MK2L_ICU_MASK   ( 0xFFU )
  #define MK2H_ICU_MASK   ( 0xFFU )
  #define MK3L_ICU_MASK   ( 0xFFU )
  #define MK3H_ICU_MASK   ( 0xFFU )
#endif

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
#if ( SAMPLE_ICU_ENABLE != FALSE )
extern bool_t SampleIcu_Wakeup;
#endif

/*----------------------------------------------------------------------------*/
/* static variables                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                             */
/*----------------------------------------------------------------------------*/
#if ( SAMPLE_ICU_ENABLE != FALSE )
void SampleIcu( void );
#endif

#endif /* SAMPLE_ICU_H_ */
