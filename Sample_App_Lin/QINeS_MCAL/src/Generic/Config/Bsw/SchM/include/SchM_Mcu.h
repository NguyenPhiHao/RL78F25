/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Mcu.h                                                   */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef SCHM_LIN_H
#define SCHM_LIN_H
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(void, MCU_CODE) SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) );
extern FUNC(void, MCU_CODE) SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01( VAR(void, AUTOMATIC) );

extern FUNC(void, MCU_CODE) SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) );
extern FUNC(void, MCU_CODE) SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01( VAR(void, AUTOMATIC) );

#endif /* SCHM_LIN_H */

/* EOF SchM_Lin.h *************************************************************/
