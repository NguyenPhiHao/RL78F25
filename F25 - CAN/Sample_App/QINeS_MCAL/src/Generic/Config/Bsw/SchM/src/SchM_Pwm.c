/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Pwm.c                                                   */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "SchM_Pwm.h"
#include "Os.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define PWM_START_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00                       */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt disable function.               */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
FUNC(void, RTE_CODE) SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) )
{
    DisableAllInterrupts();
}

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00                        */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt enable function.                */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
FUNC(void, RTE_CODE) SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) )
{
    EnableAllInterrupts();
}

#define PWM_STOP_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"

/* EOF SchM_Pwm.c *************************************************************/
