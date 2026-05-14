/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : QINeS-Lite MCAL                                              */
/* File Name   : r_memory_operation.h                                         */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for SHA Hash library used in AUTOSAR Basic      */
/*               Software module "Crypto Driver".                             */
/* Author      : m.ishikawa                                                   */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver
/* R22-11                                                                     */
/******************************************************************************/

#ifndef R_MEMORY_OPERATION_H
#define R_MEMORY_OPERATION_H

/*----------------------------------------------------------------------------*/
/* Includes   <System Includes> , "Project Includes"                          */
/*----------------------------------------------------------------------------*/
#include "QINeS_Lite.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* Macro definitions                                                          */
/*----------------------------------------------------------------------------*/
#define RANGE_OK    (0u)
#define RANGE_NG    (1u)

/*----------------------------------------------------------------------------*/
/* Exported function prototypes                                               */
/*----------------------------------------------------------------------------*/
extern void  r_clear_work_area_32bit_unit(uint32 * work, uint8 len);
extern void  r_ram_copy_32bit_unit(uint32 * buf1, const uint32 * buf2, uint8 len);
extern uint8 r_chk_ram_range_valid(const uint8 * start_address, uint16 len);
extern uint8 r_chk_rom_range_valid(const uint8 QL_70_FAR * start_address, uint16 len);

#endif /* R_MEMORY_OPERATION_H */
