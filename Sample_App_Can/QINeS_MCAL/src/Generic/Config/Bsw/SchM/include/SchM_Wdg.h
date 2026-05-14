/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Wdg.h                                                   */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/
#ifndef SCHM_WDG_H
#define SCHM_WDG_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
/* Wdg Instance0 */
#define SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_00()  SchM_Enter_Wdg_AllGlobalVariable()
#define SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_01()  SchM_Enter_Wdg_AllGlobalVariable()
#define SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_02()  SchM_Enter_Wdg_AllGlobalVariable()

#define SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_00()   SchM_Exit_Wdg_AllGlobalVariable()
#define SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_01()   SchM_Exit_Wdg_AllGlobalVariable()
#define SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_02()   SchM_Exit_Wdg_AllGlobalVariable()

extern FUNC( void, AUTOMATIC ) SchM_Enter_Wdg_AllGlobalVariable( VAR( void, AUTOMATIC ) );
extern FUNC( void, AUTOMATIC ) SchM_Exit_Wdg_AllGlobalVariable( VAR( void, AUTOMATIC ) );

#endif /* SCHM_WDG_H */
