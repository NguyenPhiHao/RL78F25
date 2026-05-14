/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Gpt.c                                                   */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "SchM_Gpt.h"
#include "Os.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define GPT_START_SEC_CODE_LOCAL
#include "Gpt_MemMap.h"

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Enter_Gpt_AllGlobalVariable                           */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt disable function.               */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
FUNC( void, AUTOMATIC ) SchM_Enter_Gpt_AllGlobalVariable( VAR( void, AUTOMATIC ) )
{
    DisableAllInterrupts();
}

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Exit_Gpt_AllGlobalVariable                            */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt enable function.                */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
FUNC( void, AUTOMATIC ) SchM_Exit_Gpt_AllGlobalVariable( VAR( void, AUTOMATIC ) )
{
    EnableAllInterrupts();
}

#define GPT_STOP_SEC_CODE_LOCAL
#include "Gpt_MemMap.h"

/* EOF SchM_Fls.c *************************************************************/
