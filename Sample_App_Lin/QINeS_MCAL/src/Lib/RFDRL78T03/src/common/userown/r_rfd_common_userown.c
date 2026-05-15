/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_rfd_common_userown.c                                       */
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
#include "r_rfd_common_userown.h"

/**********************************************************************************************************************
 Static global variables
 *********************************************************************************************************************/
#define  FLS_START_SEC_VAR_INIT_LOCAL_8
#include "Fls_MemMap.h"
    /* State enabled/disabled interrupts in PSW */
    static uint8 sg_u08_psw_ie_state = R_RFD_VALUE_U08_INIT_VARIABLE;
#define  FLS_STOP_SEC_VAR_INIT_LOCAL_8
#include "Fls_MemMap.h"

/**********************************************************************************************************************
 * Function name : R_RFD_HOOK_EnterCriticalSection
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*********************************************************************************************************************/
/**
 *  Perform processing to enter critical section.
 *  Store the current state enabled/disabled interrupts and disable interrupts.
 *  
 *  param[in]      -
 *  return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void R_RFD_HOOK_EnterCriticalSection(void)
{
    sg_u08_psw_ie_state = R_RFD_GET_PSW_IE_STATE();

    /* Disable interrupts */
    R_RFD_DISABLE_INTERRUPT();
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function R_RFD_HOOK_EnterCriticalSection
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_HOOK_ExitCriticalSection
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*********************************************************************************************************************/
/**
 *  Perform processing to exit critical section.
 *  Restore the state enabled/disabled interrupts.
 *  
 *  param[in]      -
 *  return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void R_RFD_HOOK_ExitCriticalSection(void)
{
    if (R_RFD_IS_PSW_IE_ENABLE(sg_u08_psw_ie_state))
    {
        /* Enable interrupts */
        R_RFD_ENABLE_INTERRUPT();
    }
    else
    {
        /* Keep state disabled interrupts */
        /* No operation */
    }
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function R_RFD_HOOK_ExitCriticalSection
 *********************************************************************************************************************/
