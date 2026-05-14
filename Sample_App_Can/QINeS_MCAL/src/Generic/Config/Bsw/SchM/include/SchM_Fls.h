/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Fls.h                                                   */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef SCHM_FLS_H
#define SCHM_FLS_H
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(void, AUTOMATIC) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) );

extern FUNC(void, AUTOMATIC) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) );

extern FUNC(void, AUTOMATIC) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_01( VAR(void, AUTOMATIC) );

extern FUNC(void, AUTOMATIC) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_01( VAR(void, AUTOMATIC) );

extern FUNC(void, FLS_CODE) Fls_MainFunction( VAR(void, AUTOMATIC) );

#endif /* SCHM_FLS_H */

/* EOF SchM_Fls.h *************************************************************/
