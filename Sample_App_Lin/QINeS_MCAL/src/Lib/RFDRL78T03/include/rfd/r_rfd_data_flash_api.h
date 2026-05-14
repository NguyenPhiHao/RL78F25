/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_rfd_data_flash_api.h                                       */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for Fls driver used in AUTOSAR Basic Software   */
/*               module "Crypto Driver" and "Fls Driver".                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto/Fls Driver                                         */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef R_RFD_DATA_FLASH_API_H
#define R_RFD_DATA_FLASH_API_H

#include "r_rfd.h"

/*----------------------------------------------------------------------------*/
/* For Common Flash Control Component                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Prototype declaration                                                      */
/*----------------------------------------------------------------------------*/

extern R_RFD_FAR_FUNC void R_RFD_EraseDataFlashReq(uint8 i_u08_block_number);
extern R_RFD_FAR_FUNC void R_RFD_WriteDataFlashReq(uint32 i_u32_start_addr,
                                                   uint8 QL_70_NEAR * inp_u08_write_data);
extern R_RFD_FAR_FUNC void R_RFD_BlankCheckDataFlashReq(uint32 i_u32_start_addr,
                                                        uint16 i_u16_blankcheck_length);

#endif /* end of R_RFD_DATA_FLASH_API_H */