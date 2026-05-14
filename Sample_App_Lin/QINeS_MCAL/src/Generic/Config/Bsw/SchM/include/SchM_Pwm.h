/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Pwm.h                                                   */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/
#ifndef SCHM_PWM_H_
#define SCHM_PWM_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(void, RTE_CODE) SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) );

extern FUNC(void, RTE_CODE) SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) );

#endif /* SCHM_PWM_H_ */

/* EOF SchM_Pwm.h *************************************************************/
