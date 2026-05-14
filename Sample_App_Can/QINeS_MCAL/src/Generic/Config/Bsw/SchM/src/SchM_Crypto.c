/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Crypto.c                                                */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "SchM_Crypto.h"
#include "Os.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Enter_Crypto_QueueOperation                           */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt disable function.               */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
void SchM_Enter_Crypto_QueueOperation( void )
{
    DisableAllInterrupts();
}

/******************************************************************************/
/* ModuleID      : MODULE_ID_SCHM (130)                                       */
/* ServiceID     : --                                                         */
/* Name          : SchM_Exit_Crypto_QueueOperation                            */
/* Param         : void                                                       */
/* Return        : void                                                       */
/* Contents      : Wrap function of interrupt enable function.                */
/* Author        : --                                                         */
/* Note          : --                                                         */
/******************************************************************************/
void SchM_Exit_Crypto_QueueOperation( void )
{
    EnableAllInterrupts();
}

#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"

/* EOF SchM_Crypto.c **********************************************************/
