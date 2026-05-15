/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto_70_RL78F2X.h                                          */
/* Version     : v1.00.01                                                     */
/* Contents    : Crypto Module HW dependent interface                         */
/*               This file covers Hw dependent functionality for Crypto module*/
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */

#ifndef CRYPTO_70_RL78F2X_H
#define CRYPTO_70_RL78F2X_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Crypto_70_Types.h"

/*----------------------------------------------------------------------------*/
/* source file version information                                            */
/*----------------------------------------------------------------------------*/
/*[SWS_BSW_00059] Version Check parameters. */
#define CRYPTO_70_VENDOR_ID_RL78F2X_H                   (70U)
#define CRYPTO_70_MODULE_ID_RL78F2X_H                   (114U)

#define CRYPTO_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H    (22U)
#define CRYPTO_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H    (11U)
#define CRYPTO_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H (0U)

#define CRYPTO_70_SW_MAJOR_VERSION_RL78F2X_H            (1U)
#define CRYPTO_70_SW_MINOR_VERSION_RL78F2X_H            (0U)
#define CRYPTO_70_SW_PATCH_VERSION_RL78F2X_H            (0U)

/*----------------------------------------------------------------------------*/
/* source file version checks                                                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define CRYPTO_70_RL78F2X_SECER    (*(volatile uint16 QL_70_NEAR *)0xB4)
#define CRYPTO_70_RL78F2X_SECST    (*(volatile uint8  QL_70_NEAR *)0xB6)

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#if ( TRUE == CRYPTO_70_AESEA_ENABLE )
extern uint8  Crypto_70_RL78F2X_ClearProcessStatus( const uint8 clearStatus );
extern uint16 Crypto_70_RL78F2X_GetErrorStatus(     void                   );
#endif  /* if( TRUE == CRYPTO_70_AESEA_ENABLE ) */

/*----------------------------------------------------------------------------*/
/* end of functions and function style macros declaration                     */
/*----------------------------------------------------------------------------*/

#endif  /* CRYPTO_70_RL78F2X_H */

/* EOF Crypto_70_RL78F2X.h ****************************************************/