/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Gpt.h                                                   */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef SCHM_GPT_H_
#define SCHM_GPT_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte.h"

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00()    SchM_Enter_Gpt_AllGlobalVariable()
#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01()    SchM_Enter_Gpt_AllGlobalVariable()

#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00()     SchM_Exit_Gpt_AllGlobalVariable()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01()     SchM_Exit_Gpt_AllGlobalVariable()

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern void SchM_Enter_Gpt_AllGlobalVariable( void );
extern void SchM_Exit_Gpt_AllGlobalVariable( void );

#endif /* SCHM_GPT_H_ */

/* EOF SchM_Gpt.h *************************************************************/
