/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_rsa_version.c                                              */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for RSA library used in AUTOSAR Basic Software  */
/*               module "Crypto Driver".                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* Includes   <System Includes> , "Project Includes"                          */
/*----------------------------------------------------------------------------*/
#include "r_rsa.h"
#include "r_mw_version.h"
 
/*----------------------------------------------------------------------------*/
/* Macro definitions                                                          */
/*----------------------------------------------------------------------------*/
#define __COMPLIER_VER_UNDEFINED__ (0xFFFFFFFF)
#define __RSA_VERSION__ "2.01"
 
#if defined (__CCRL__)
#if defined (__RL78_SMALL__)
    #define __MEMORY_MODEL__ "SMALL"
#elif defined (__RL78_MEDIUM__)
    #define __MEMORY_MODEL__ "MEDIUM"
#else
    #error "Undefined memory model."
#endif /* defined __RL78_SMALL__ */
 
#if defined (__RL78_S1__)
    #define __CORE_NAME__ "S1" /* RL78/G10 */
#elif defined (__RL78_S2__)
    #define __CORE_NAME__ "S2" /* RL78/G12 RL78/G13 */
#elif defined (__RL78_S3__)
    #define __CORE_NAME__ "S3" /* RL78/G14 */
#else
    #error "Undefined CPU Core."
#endif /* defined __RL78_S1__ */
 
#define __TARGET_CPU__ "RL78 (CCRL, "__CORE_NAME__", "__MEMORY_MODEL__")"
#define __COMPILER_VER__   (__RENESAS_VERSION__)
#elif defined (__ICCRL78__)
    #if __CORE__==__RL78_0__
        #define __CORE_NAME__ "S1" /* RL78/G10 */
    #elif __CORE__==__RL78_1__
        #define __CORE_NAME__ "S2" /* RL78/G12 RL78/G13 */
    #elif __CORE__==__RL78_2__
        #define __CORE_NAME__ "S3" /* RL78/G14 */
    #else
        #error "Undefined CPU Core."
    #endif /* __CORE__==__RL78_0__ */
    #if __CODE_MODEL__==__CODE_MODEL_NEAR__
        #define __CODE_MODEL_NAME__ "code_model=near"
    #else
        #define __CODE_MODEL_NAME__ "code_model=far"
    #endif /* __CODE_MODEL__==__CODE_MODEL_NEAR__ */
    #if __DATA_MODEL__==__DATA_MODEL_NEAR__
        #define __DATA_MODEL_NAME__ "data_model=near"
    #else
        #define __DATA_MODEL_NAME__ "data_model=far"
    #endif /* __DATA_MODEL__==__DATA_MODEL_NEAR__ */
    #define __TARGET_CPU__ "RL78 (IAR, "__CORE_NAME__", "__CODE_MODEL_NAME__", "__DATA_MODEL_NAME__")"
    #define __COMPILER_VER__   (__VER__)
#else
    #error "None-support combination of CPU and endian"
#endif
 
/******************************************************************************/
 Global variables
/******************************************************************************/
#define CRYPTO_START_SEC_CONST_32
#include "Crypto_MemMap.h"
const mw_version_t R_rsa_version =
{
__COMPILER_VER__, "RSA Library version "__RSA_VERSION__" for "__TARGET_CPU__")\n" };
#define CRYPTO_STOP_SEC_CONST_32
#include "Crypto_MemMap.h"
 
 