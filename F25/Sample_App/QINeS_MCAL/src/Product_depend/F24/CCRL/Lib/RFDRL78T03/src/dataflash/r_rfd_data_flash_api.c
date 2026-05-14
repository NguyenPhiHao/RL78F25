/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_rfd_data_flash_api.c                                       */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for Fls driver used in AUTOSAR Basic Software   */
/*               module "Crypto Driver" and "Fls Driver".                     */
/* Author      : m.ishikawa                                                   */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto/Fls Driver                                         */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* Includes   <System Includes> , "Project Includes"                          */
/*----------------------------------------------------------------------------*/
#include "r_rfd_data_flash_api.h"

/**********************************************************************************************************************
 * Function name : R_RFD_EraseDataFlashReq
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*********************************************************************************************************************/
/**
 *  This command starts the code/data flash memory sequencer.
 *  Start the code/data flash memory sequencer and erase the specified block in the data flash memory.
 *  
 *  param[in]      i_u08_block_number :
 *                    Erase block number
 *  return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void R_RFD_EraseDataFlashReq(uint8 i_u08_block_number)
{
    /* Local variable definitions */
    uint16 l_u16_low_addr;
    uint8  l_u08_high_addr;

    /* Calculate and set local variables */
    /* This expression (actual 16-bit address) never exceeds the range of casting uint16 */
    l_u16_low_addr  = R_RFD_VALUE_U16_DATA_FLASH_ADDR_LOW
                      + (((uint16)i_u08_block_number & (uint16)R_RFD_VALUE_U08_DATA_FLASH_BLOCK_ADDR_LOW)
                      << R_RFD_VALUE_U08_DATA_FLASH_SHIFT_LOW_ADDR);
    l_u08_high_addr = R_RFD_VALUE_U08_DATA_FLASH_ADDR_HIGH;

    /* Set the value for FLARS register */
    R_RFD_REG_U08_FLARS = R_RFD_VALUE_U08_FLARS_USER_AREA;

    /* Set the value for FLAPH/L register */
    R_RFD_REG_U16_FLAPL = l_u16_low_addr;
    R_RFD_REG_U08_FLAPH = l_u08_high_addr;

    /* Set the value for FLSEDH/L register */
    R_RFD_REG_U16_FLSEDL = l_u16_low_addr | R_RFD_VALUE_U16_DATA_FLASH_BLOCK_ADDR_END;
    R_RFD_REG_U08_FLSEDH = l_u08_high_addr;

    /* Set the value for FSSQ register */
    R_RFD_REG_U08_FSSQ = R_RFD_VALUE_U08_FSSQ_ERASE;
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function R_RFD_EraseDataFlashReq
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_WriteDataFlashReq
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*********************************************************************************************************************/
/**
 *  This command starts the code/data flash memory sequencer.
 *  Start the code/data flash memory sequencer and write the data (1 byte) to the specified address
 *  in the data flash memory.
 *  
 *  param[in]      i_u32_start_addr :
 *                    Write start address
 *  param[in]      inp_u08_write_data :
 *                    Write data pointer
 *  return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void R_RFD_WriteDataFlashReq(uint32 i_u32_start_addr,
                                            uint8 QL_70_NEAR * inp_u08_write_data)
{
    /* Local variable definitions */

    /* Set the value for FLARS register */
    R_RFD_REG_U08_FLARS = R_RFD_VALUE_U08_FLARS_USER_AREA;

    /* Set the value for FLAPH/L register */
    R_RFD_REG_U16_FLAPL = (uint16)(i_u32_start_addr & R_RFD_VALUE_U16_MASK1_16BIT);
    R_RFD_REG_U08_FLAPH = (uint8)((i_u32_start_addr >> R_RFD_VALUE_U08_SHIFT_16BIT) & R_RFD_VALUE_U08_MASK1_8BIT);

    /* Set the value for FLWL register */
    R_RFD_REG_U16_FLWL = (uint16)(* inp_u08_write_data);

    /* Set the value for FSSQ register */
    R_RFD_REG_U08_FSSQ = R_RFD_VALUE_U08_FSSQ_WRITE;
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function R_RFD_WriteDataFlashReq
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_BlankCheckDataFlashReq
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*********************************************************************************************************************/
/**
 *  This command starts the code/data flash memory sequencer.
 *  Start the code/data flash memory sequencer and start blankcheck the specified address and length
 *  in the data flash memory.
 *  
 *  param[in]      i_u32_start_addr :
 *                    Blankcheck start address
 *  param[in]      i_u16_blankcheck_length :
 *                    Blankcheck length (greater than zero)
 *  return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void R_RFD_BlankCheckDataFlashReq(uint32 i_u32_start_addr,
                                                 uint16 i_u16_blankcheck_length)
{
    /* Local variable definitions */
    uint32 l_u32_end_addr;

    /* Calculate and set local variables */
    l_u32_end_addr = (i_u32_start_addr + (uint32)i_u16_blankcheck_length) - 1u;

    /* Set the value for FLARS register */
    R_RFD_REG_U08_FLARS = R_RFD_VALUE_U08_FLARS_USER_AREA;

    /* Set the value for FLAPH/L register */
    R_RFD_REG_U16_FLAPL = (uint16)(i_u32_start_addr & R_RFD_VALUE_U16_MASK1_16BIT);
    R_RFD_REG_U08_FLAPH = (uint8)((i_u32_start_addr >> R_RFD_VALUE_U08_SHIFT_16BIT) & R_RFD_VALUE_U08_MASK1_8BIT);

    /* Set the value for FLSEDH/L register */
    R_RFD_REG_U16_FLSEDL = (uint16)(l_u32_end_addr & R_RFD_VALUE_U16_MASK1_16BIT);
    R_RFD_REG_U08_FLSEDH = (uint8)((l_u32_end_addr >> R_RFD_VALUE_U08_SHIFT_16BIT) & R_RFD_VALUE_U08_MASK1_8BIT);

    /* Set the value for FSSQ register */
    R_RFD_REG_U08_FSSQ = R_RFD_VALUE_U08_FSSQ_BLANKCHECK_DF;
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function R_RFD_BlankCheckDataFlashReq
 *********************************************************************************************************************/
