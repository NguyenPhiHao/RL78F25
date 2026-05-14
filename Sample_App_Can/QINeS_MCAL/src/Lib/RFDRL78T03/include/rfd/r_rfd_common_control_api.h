/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_rfd_common_control_api.h                                   */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for Fls driver used in AUTOSAR Basic Software   */
/*               module "Crypto Driver" and "Fls Driver".                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto/Fls Driver                                         */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef R_RFD_COMMON_CONTROL_API_H
#define R_RFD_COMMON_CONTROL_API_H

#include "r_rfd.h"

/*----------------------------------------------------------------------------*/
/* For Common Flash Control Component                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Prototype declaration                                                      */
/*----------------------------------------------------------------------------*/

extern R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckCFDFSeqEndStep1(void);
extern R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckCFDFSeqEndStep2(void);
extern R_RFD_FAR_FUNC void        R_RFD_GetSeqErrorStatus(uint8 QL_70_NEAR * onp_u08_error_status);
extern R_RFD_FAR_FUNC void        R_RFD_ClearSeqRegister(void);

#endif /* end of R_RFD_COMMON_CONTROL_API_H */