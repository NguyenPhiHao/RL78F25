/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_rfd_common_api.h                                           */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for Fls driver used in AUTOSAR Basic Software   */
/*               module "Crypto Driver" and "Fls Driver".                     */
/* Author      : m.ishikawa                                                   */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto/Fls Driver                                         */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef R_RFD_COMMON_API_H
#define R_RFD_COMMON_API_H

#include "r_rfd.h"

/*----------------------------------------------------------------------------*/
/* For Common Flash Control Component                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Prototype declaration                                                      */
/*----------------------------------------------------------------------------*/
extern uint8 g_u08_cpu_frequency;

extern R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_Init(uint8 i_u08_cpu_frequency);
extern R_RFD_FAR_FUNC void        R_RFD_SetDataFlashAccessMode(e_rfd_df_access_t i_e_df_access);
extern R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_SetFlashMemoryMode(e_rfd_flash_memory_mode_t i_e_flash_mode);
extern R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckFlashMemoryMode(e_rfd_flash_memory_mode_t i_e_flash_mode);

#endif /* end of R_RFD_COMMON_API_H */