/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Port.h                                                  */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/
#ifndef SCHM_PORT_H_
#define SCHM_PORT_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte.h"

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00()  SchM_Enter_Port_AllGlobalVariable()
#define SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01()  SchM_Enter_Port_AllGlobalVariable()
#define SchM_Enter_Port_PORT_EXCLUSIVE_AREA_02()  SchM_Enter_Port_AllGlobalVariable()

#define SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00()   SchM_Exit_Port_AllGlobalVariable()
#define SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01()   SchM_Exit_Port_AllGlobalVariable()
#define SchM_Exit_Port_PORT_EXCLUSIVE_AREA_02()   SchM_Exit_Port_AllGlobalVariable()

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern void SchM_Enter_Port_AllGlobalVariable( void );
extern void SchM_Exit_Port_AllGlobalVariable( void );

#endif /* SCHM_PORT_H_ */

/* EOF SchM_Port.h ************************************************************/
