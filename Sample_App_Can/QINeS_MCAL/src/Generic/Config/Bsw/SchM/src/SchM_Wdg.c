/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Wdg.c                                                   */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "SchM_Wdg.h"
#include "Os.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define WDG_START_SEC_CODE_LOCAL
#include "Wdg_MemMap.h"

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Enter_Wdg_AllGlobalVariable                           */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt disable function.               */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
FUNC(void, AUTOMATIC) SchM_Enter_Wdg_AllGlobalVariable( VAR(void, AUTOMATIC) )
{
}

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Exit_Wdg_AllGlobalVariable                            */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt enable function.                */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
FUNC(void, AUTOMATIC) SchM_Exit_Wdg_AllGlobalVariable( VAR(void, AUTOMATIC) )
{
}

#define WDG_STOP_SEC_CODE_LOCAL
#include "Wdg_MemMap.h"

/* EOF SchM_Wdg.c *************************************************************/
