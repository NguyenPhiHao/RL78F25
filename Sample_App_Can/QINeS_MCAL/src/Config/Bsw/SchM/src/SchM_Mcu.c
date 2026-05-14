/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Mcu.c                                                   */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "SchM_Mcu.h"
#include "Os.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_00                       */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt disable function.               */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
FUNC(void, MCU_CODE) SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) )
{
    /* disable interrupts */
}

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_00                        */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt enable function.                */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
FUNC(void, MCU_CODE) SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) )
{
    /* enable interrupts */
}

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01                       */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt disable function.               */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
FUNC(void, MCU_CODE) SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01( VAR(void, AUTOMATIC) )
{
    /* disable interrupts */
}

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01                        */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt enable function.                */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
FUNC(void, MCU_CODE) SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01( VAR(void, AUTOMATIC) )
{
    /* enable interrupts */
}

#define MCU_STOP_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"

/* EOF SchM_Mcu.c *************************************************************/
