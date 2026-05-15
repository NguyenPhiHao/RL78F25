/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_rfd_common_userown.h                                       */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for Fls driver used in AUTOSAR Basic Software   */
/*               module "Crypto Driver" and "Fls Driver".                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto/Fls Driver                                         */
/* R22-11                                                                     */
#ifndef R_RFD_COMMON_USEROWN_H
#define R_RFD_COMMON_USEROWN_H

#include "r_rfd.h"

/*----------------------------------------------------------------------------*/
/* For Common Flash Control Component                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Prototype declaration                                                      */
/*----------------------------------------------------------------------------*/

extern R_RFD_FAR_FUNC void R_RFD_HOOK_EnterCriticalSection(void);
extern R_RFD_FAR_FUNC void R_RFD_HOOK_ExitCriticalSection(void);

#endif /* end of R_RFD_COMMON_USEROWN_H */