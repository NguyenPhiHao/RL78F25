/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Lin.h                                                   */
/* Version     : v1.3.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/

#ifndef SCHM_LIN_H
#define SCHM_LIN_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(void, LIN_CODE) SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) );

extern FUNC(void, LIN_CODE) SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) );

extern FUNC(void, LIN_CODE) SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_01( VAR(void, AUTOMATIC) );

extern FUNC(void, LIN_CODE) SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_01( VAR(void, AUTOMATIC) );

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* SCHM_LIN_H */

/* End of SchM_Lin.h */