/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Fls.c                                                   */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "SchM_Fls.h"
#include "Os.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00                       */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt disable function.               */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
FUNC(void, AUTOMATIC) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) )
{
}

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00                        */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt enable function.                */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
FUNC(void, AUTOMATIC) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00( VAR(void, AUTOMATIC) )
{
}

/*----------------------------------------------------------------------------*/
/* ModuleID   : MODULE_ID_SCHM (130)                                          */
/* ServiceID  : --                                                            */
/* Name       : SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_01                          */
/* Param      : void                                                          */
/* Return     : void                                                          */
/* Contents   : Wrap function of interrupt disable function.                  */
/* Author     : --                                                            */
/* Note       : --                                                            */
/*----------------------------------------------------------------------------*/
FUNC(void, AUTOMATIC) SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_01( VAR(void, AUTOMATIC) )
{
}

/*----------------------------------------------------------------------------*/
/* ModuleID   : MODULE_ID_SCHM (130)                                          */
/* ServiceID  : --                                                            */
/* Name       : SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_01                           */
/* Param      : void                                                          */
/* Return     : void                                                          */
/* Contents    : Wrap function of interrupt enable function.                   */
/* Author     : --                                                            */
/* Note       : --                                                            */
/*----------------------------------------------------------------------------*/
FUNC(void, AUTOMATIC) SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_01( VAR(void, AUTOMATIC) )
{
}

#define FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"

/* EOF SchM_Fls.c *************************************************************/
