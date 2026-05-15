/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_memory_config.h                                            */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for SHA Hash library used in AUTOSAR Basic      */
/*               Software module "Crypto Driver".                             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */ 
#ifndef R_MEMORY_CONFIG_H
#define R_MEMORY_CONFIG_H

/* Set the start address and end address of the ROM area to be used */
#define ROM_START                   ((uint8 QL_70_FAR *) 0x04000U)
#define ROM_END                     ((uint8 QL_70_FAR *) 0x3FFFFU)

/* Set the start address and end address of the RAM area to be used */
#define RAM_START                   ((uint8 QL_70_FAR *) 0xF5F00U)
#define RAM_END                     ((uint8 QL_70_FAR *) 0xFFEDFU)

#endif /* R_MEMORY_CONFIG_H */