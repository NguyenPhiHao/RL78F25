/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : SchM_Crypto.h                                                */
/* Version     :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef SCHM_CRYPTO_H
#define SCHM_CRYPTO_H
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte.h"
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(void, RTE_CODE) SchM_Enter_Crypto_QueueOperation( VAR(void, AUTOMATIC) );

extern FUNC(void, RTE_CODE) SchM_Exit_Crypto_QueueOperation( VAR(void, AUTOMATIC) );

extern void Crypto_MainFunction( void );

#endif /* SCHM_CRYPTO_H */

/* EOF SchM_Crypto.h **********************************************************/
