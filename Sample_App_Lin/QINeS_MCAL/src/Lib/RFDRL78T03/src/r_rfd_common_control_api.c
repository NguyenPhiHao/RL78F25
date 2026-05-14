/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_rfd_common_control_api.c                                   */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for Fls driver used in AUTOSAR Basic Software   */
/*               module "Crypto Driver" and "Fls Driver".                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto/Fls Driver                                         */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* Includes   <System Includes> , "Project Includes"                          */
/*----------------------------------------------------------------------------*/
#include "r_rfd_common_control_api.h"

/**********************************************************************************************************************
 * Function name : R_RFD_CheckCFDFSeqEndStep1
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*********************************************************************************************************************/
/**
 *  Check whether the operation of the activated code/data flash memory sequencer has been completed.
 *  If completed, then clear the control register for code/data flash memory sequencer.
 *  
 *  param[in]      -
 *  return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :   The operation of the code/data flash memory sequencer is completed
 *                  - R_RFD_ENUM_RET_STS_BUSY : The code/data flash memory sequencer is still being processed
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckCFDFSeqEndStep1(void)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8     l_u08_fsasth_value;

    /* Set local variables */
    l_e_ret_value      = R_RFD_ENUM_RET_STS_OK;
    l_u08_fsasth_value = R_RFD_REG_U08_FSASTH;

    /* SQEND bit is valid */
    if (0u != (l_u08_fsasth_value & R_RFD_VALUE_U08_MASK1_FSASTH_SQEND))
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    
        /* Set the value for FSSQ register */
        R_RFD_REG_U08_FSSQ = R_RFD_VALUE_U08_FSSQ_CLEAR;
    }
    /* SQEND bit is invalid */
    else
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_STS_BUSY;
    }

    return (l_e_ret_value);
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function R_RFD_CheckCFDFSeqEndStep1
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function name : R_RFD_CheckCFDFSeqEndStep2
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*********************************************************************************************************************/
/**
 *  Check whether the code/data flash memory sequencer command has been completed
 *  by clearing the control register for the code/data flash memory sequencer.
 *  
 *  param[in]      -
 *  return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :   The command of code/data flash memory sequencer is completed
 *                  - R_RFD_ENUM_RET_STS_BUSY : The command is still being processed
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckCFDFSeqEndStep2(void)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8     l_u08_fsasth_value;

    /* Set local variables */
    l_e_ret_value      = R_RFD_ENUM_RET_STS_OK;
    l_u08_fsasth_value = R_RFD_REG_U08_FSASTH;

    /* SQEND bit is invalid */
    if (0u == (l_u08_fsasth_value & R_RFD_VALUE_U08_MASK1_FSASTH_SQEND))
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    }
    /* SQEND bit is valid */
    else
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_STS_BUSY;
    }

    return (l_e_ret_value);
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function R_RFD_CheckCFDFSeqEndStep2
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function name : R_RFD_GetSeqErrorStatus
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*********************************************************************************************************************/
/**
 *  Get the error information occurred by the code/data flash memory sequencer command or the extra sequencer command.
 *  
 *  param[out]     onp_u08_error_status :
 *                    Pointer to the variable that stores error information
 *  return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void R_RFD_GetSeqErrorStatus(uint8 QL_70_NEAR * onp_u08_error_status)
{
    /* Local variable definitions */
    uint8 l_u08_fsastl_value;

    /* Set local variables */
    l_u08_fsastl_value = R_RFD_REG_U08_FSASTL;

    /* Write to parameter */
    * onp_u08_error_status = l_u08_fsastl_value & R_RFD_VALUE_U08_MASK1_FSASTL_ERROR_FLAG;
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function R_RFD_GetSeqErrorStatus
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_ClearSeqRegister
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*********************************************************************************************************************/
/**
 *  Clear the registers that control the code/data flash memory sequencer and extra sequencer.
 *  
 *  param[in]      -
 *  return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void R_RFD_ClearSeqRegister(void)
{
    /* Local variable definitions */

    /* Set the value for FLRST register */
    R_RFD_REG_U08_FLRST = R_RFD_VALUE_U08_FLRST_ON;

    /* Wait one clock */
    R_RFD_NO_OPERATION();

    /* Set the value for FLRST register */
    R_RFD_REG_U08_FLRST = R_RFD_VALUE_U08_FLRST_OFF;
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function R_RFD_ClearSeqRegister
 *********************************************************************************************************************/
