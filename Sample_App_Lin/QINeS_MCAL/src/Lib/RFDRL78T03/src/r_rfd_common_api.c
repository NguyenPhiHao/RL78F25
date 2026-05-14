/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_rfd_common_api.c                                           */
/* Version     : v1.00.01                                                     */
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
#include "r_rfd_common_api.h"
#include "r_rfd_common_userown.h"

/**********************************************************************************************************************
 Exported global variables
 *********************************************************************************************************************/
#define  FLS_START_SEC_VAR_INIT_LOCAL_8
#include "Fls_MemMap.h"
/* CPU Frequency configuration for r_rfd_wait_count */
uint8 g_u08_cpu_frequency = R_RFD_VALUE_U08_INIT_VARIABLE;
/* CPU Frequency configuration for FSET */
static uint8 g_u08_fset_cpu_frequency = R_RFD_VALUE_U08_INIT_VARIABLE;
static RFD_InternalStatusType s_InternalStatus = RFD_ST_NON_INIT;
#define  FLS_STOP_SEC_VAR_INIT_LOCAL_8
#include "Fls_MemMap.h"

static R_RFD_FAR_FUNC void        r_rfd_wait_count(uint8 i_u08_count);

/**********************************************************************************************************************
 * Function name : R_RFD_Init
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*********************************************************************************************************************/
/**
 *  Initialize the RFD.
 *  
 *  param[in]      i_u08_cpu_frequency :
 *                    CPU operating frequency
 *  return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :        Successful completion
 *                  - R_RFD_ENUM_RET_ERR_PARAMETER : Out of parameter range
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_Init(uint8 i_u08_cpu_frequency)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;

    /* Local variables initialization */
    l_e_ret_value = R_RFD_ENUM_RET_STS_OK;

    /* MOD : Added processing to prevent multiple calls. */
    if ( RFD_ST_NON_INIT == s_InternalStatus ) {
        if ((R_RFD_VALUE_U08_FREQUENCY_LOWER_LIMIT <= i_u08_cpu_frequency)
           && (R_RFD_VALUE_U08_FREQUENCY_UPPER_LIMIT >= i_u08_cpu_frequency))
        {
            /* Adjust the CPU frequency variable for r_rfd_wait_count */
            g_u08_cpu_frequency = i_u08_cpu_frequency - R_RFD_VALUE_U08_FREQUENCY_ADJUST;

            if (R_RFD_VALUE_U08_FREQUENCY_CALC_THRESHOLD >= i_u08_cpu_frequency)
            {
                /* Adjust the sequencer frequency variable */
                g_u08_fset_cpu_frequency = g_u08_cpu_frequency;
            }
            else /* (R_RFD_VALUE_U08_FREQUENCY_CALC_THRESHOLD < i_u08_cpu_frequency) */
            {
                /* Adjust the sequencer frequency variable */
                g_u08_fset_cpu_frequency = ((i_u08_cpu_frequency + R_RFD_VALUE_U08_FREQUENCY_CALC_THRESHOLD)
                                           >> R_RFD_VALUE_U08_FREQUENCY_SHIFT_ADJUST);
            }

            s_InternalStatus = RFD_ST_INIT;
        }
        else
        {
            /* Set return value */
            l_e_ret_value = R_RFD_ENUM_RET_ERR_PARAMETER;
        }
    }
    else
    {
        /* Do nothing */
    }

    return (l_e_ret_value);
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function R_RFD_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_SetDataFlashAccessMode
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*********************************************************************************************************************/
/**
 *  Enable or disable to access the data flash.
 *  
 *  param[in]      i_e_df_access :
 *                    Data flash access enable or disable
 *  return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void R_RFD_SetDataFlashAccessMode(e_rfd_df_access_t i_e_df_access)
{
    /* Local variable definitions */

    /* Parameter is Data Flash Access Enable Request */
    if (R_RFD_ENUM_DF_ACCESS_ENABLE == i_e_df_access)
    {
        /* Set the value for DFLCTL register DFLEN bit */
        R_RFD_REG_U01_DFLCTL_DFLEN = R_RFD_VALUE_U01_DFLEN_DATA_FLASH_ACCESS_ENABLE;

        /* Wait for the setup time of DFLCTL register */
        R_RFD_NO_OPERATION();
        R_RFD_NO_OPERATION();
        R_RFD_NO_OPERATION();
        R_RFD_NO_OPERATION();
    }
    /* Parameter is Data Flash Access Disable Request */
    else
    {
        /* Set the value for DFLCTL register DFLEN bit */
        R_RFD_REG_U01_DFLCTL_DFLEN = R_RFD_VALUE_U01_DFLEN_DATA_FLASH_ACCESS_DISABLE;
    }
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function R_RFD_SetDataFlashAccessMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_SetFlashMemoryMode
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*********************************************************************************************************************/
/**
 *  Set the flash memory mode to the specified mode and set the flash operating frequency.
 *  
 *  param[in]      i_e_flash_mode :
 *                    Flash memory mode
 *  return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :              Successful completion
 *                  - R_RFD_ENUM_RET_ERR_MODE_MISMATCHED : Failed to change flash memory mode
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_SetFlashMemoryMode(e_rfd_flash_memory_mode_t i_e_flash_mode)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8     l_u08_fsset_value;
    uint8     l_u08_set_flpmc_value;
    uint8     l_u08_pfs_value;

    /* Local variables initialization */
    l_e_ret_value = R_RFD_ENUM_RET_STS_OK;

    /* Set code flash programming mode */
    if (R_RFD_ENUM_FLASH_MODE_CODE_PROGRAMMING == i_e_flash_mode)
    {
        /* Code flash programming mode */
        l_u08_set_flpmc_value = R_RFD_VALUE_U08_FLPMC_MODE_CODE_FLASH_PROGRAMMING;
    }
    /* Set data flash programming mode */
    else if (R_RFD_ENUM_FLASH_MODE_DATA_PROGRAMMING == i_e_flash_mode)
    {
        /* Data flash programming mode */
        l_u08_set_flpmc_value = R_RFD_VALUE_U08_FLPMC_MODE_DATA_FLASH_PROGRAMMING;
    }
    /* Set non-programmable mode */
    else
    {
        /* Non-programmable mode */
        l_u08_set_flpmc_value = R_RFD_VALUE_U08_FLPMC_MODE_NONPROGRAMMABLE;
    }

    R_RFD_HOOK_EnterCriticalSection();

    /* Start specific sequence for writing */
    R_RFD_REG_U08_PFCMD = R_RFD_VALUE_U08_PFCMD_SPECIFIC_SEQUENCE_WRITE;

    /* Set mode */
    R_RFD_REG_U08_FLPMC = l_u08_set_flpmc_value;
    R_RFD_REG_U08_FLPMC = ~l_u08_set_flpmc_value;
    R_RFD_REG_U08_FLPMC = l_u08_set_flpmc_value;

    /* Read PFS register */
    l_u08_pfs_value = R_RFD_REG_U08_PFS;

    R_RFD_HOOK_ExitCriticalSection();

    r_rfd_wait_count(15u);

    /* Check specific sequence writing error */
    if (0u != (l_u08_pfs_value & R_RFD_VALUE_U08_MASK1_PFS_FPRERR))
    {
        l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    else
    {
        /* Check mode */
        l_e_ret_value = R_RFD_CheckFlashMemoryMode(i_e_flash_mode);
       
        if (R_RFD_ENUM_RET_STS_OK == l_e_ret_value)
        {
            if ((R_RFD_ENUM_FLASH_MODE_CODE_PROGRAMMING == i_e_flash_mode)
               || (R_RFD_ENUM_FLASH_MODE_DATA_PROGRAMMING == i_e_flash_mode))
            {
                /* Read FSSET register */
                l_u08_fsset_value = R_RFD_REG_U08_FSSET;
               
                /* Set frequency */
                R_RFD_REG_U08_FSSET = (l_u08_fsset_value & R_RFD_VALUE_U08_MASK1_FSSET_TMSPMD_AND_TMBTSEL)
                                      | g_u08_fset_cpu_frequency;
            }
            else
            {
                /* No operation */
            }
        }
        else
        {
            l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
        }
    }

    return (l_e_ret_value);
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function R_RFD_SetFlashMemoryMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_CheckFlashMemoryMode
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/*********************************************************************************************************************/
/**
 *  Check whether the current flash memory mode is same as specified mode.
 *  
 *  param[in]      i_e_flash_mode :
 *                    Flash memory mode
 *  return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :              Successful completion
 *                  - R_RFD_ENUM_RET_ERR_MODE_MISMATCHED : Mode mismatch error (Not same)
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckFlashMemoryMode(e_rfd_flash_memory_mode_t i_e_flash_mode)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8     l_u08_flpmc_value;
    uint8     l_u08_flpmc_expected_value;

    /* Local variables initialization */
    l_e_ret_value = R_RFD_ENUM_RET_STS_OK;

    /* Acquire the value of FLPMC register */
    l_u08_flpmc_value  = R_RFD_REG_U08_FLPMC;

    if (R_RFD_ENUM_FLASH_MODE_DATA_PROGRAMMING == i_e_flash_mode)
    {
        l_u08_flpmc_expected_value = R_RFD_VALUE_U08_FLPMC_MODE_DATA_FLASH_PROGRAMMING;
    }
    else if (R_RFD_ENUM_FLASH_MODE_CODE_PROGRAMMING == i_e_flash_mode)
    {
        l_u08_flpmc_expected_value = R_RFD_VALUE_U08_FLPMC_MODE_CODE_FLASH_PROGRAMMING;
    }
    else /* (R_RFD_ENUM_FLASH_MODE_NONPROGRAMMABLE == i_e_flash_mode) */
    {
        l_u08_flpmc_expected_value = R_RFD_VALUE_U08_FLPMC_MODE_NONPROGRAMMABLE;
    }

    if (l_u08_flpmc_expected_value == l_u08_flpmc_value)
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    }
    else
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
    }

    return (l_e_ret_value);
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function R_RFD_CheckFlashMemoryMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Internal functions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function name : r_rfd_wait_count
 *********************************************************************************************************************/
#define  FLS_START_SEC_CODE_LOCAL
#include "Fls_MemMap.h"

#if (COMPILER_CC == COMPILER)
#pragma inline_asm r_rfd_wait_count
#endif
/*********************************************************************************************************************/
/**
 *  Wait until the target count value (microsecond) is reached.
 *  
 *  param[in]      i_u08_count :
 *                    Target count value (us)
 *  return         ---
 */
/*********************************************************************************************************************/
static R_RFD_FAR_FUNC void r_rfd_wait_count(uint8 i_u08_count)
{
    /* CC-RL compiler uses the register A as this function argument */
    PUSH  AX

    /* Calculate the counter of the waiting loop */
    MOV   X, !_g_u08_cpu_frequency
    INC   X
    MULU  X
    SHRW  AX, 3
    INCW  AX

    /* Start the waiting loop that has 8 clocks (1+1+1+1+4) */
    .LOCAL _WAIT_LOOP
    _WAIT_LOOP:
    NOP
    NOP
    DECW  AX
    CMPW  AX, #0
    BNZ   $_WAIT_LOOP
    POP   AX
}

#define  FLS_STOP_SEC_CODE_LOCAL
#include "Fls_MemMap.h"
/**********************************************************************************************************************
 End of function r_rfd_wait_count
 *********************************************************************************************************************/

/**********************************************************************************************************************
 End of internal functions
 *********************************************************************************************************************/
