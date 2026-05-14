/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Adc.h                                                   */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef SCHM_ADC_H_
#define SCHM_ADC_H_
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Rte.h"
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00()    SchM_Enter_Adc_AllGlobalVariable()
#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_01()    SchM_Enter_Adc_AllGlobalVariable()
#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03()    SchM_Enter_Adc_AllGlobalVariable()
#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_09()    SchM_Enter_Adc_AllGlobalVariable()

#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00()     SchM_Exit_Adc_AllGlobalVariable()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_01()     SchM_Exit_Adc_AllGlobalVariable()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03()     SchM_Exit_Adc_AllGlobalVariable()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09()     SchM_Exit_Adc_AllGlobalVariable()

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

extern void SchM_Enter_Adc_AllGlobalVariable( void );
extern void SchM_Exit_Adc_AllGlobalVariable( void );

#endif /* SCHM_ADC_H_ */

/* EOF SchM_Adc.h *************************************************************/
