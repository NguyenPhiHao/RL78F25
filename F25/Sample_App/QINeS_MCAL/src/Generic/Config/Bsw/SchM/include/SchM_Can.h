/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Can.h                                                   */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef SCHM_CAN_H
#define SCHM_CAN_H
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

extern FUNC(void, RTE_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) );

extern FUNC(void, RTE_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) );

#endif /* SCHM_CAN_H */

/* EOF SchM_Can.h *************************************************************/
