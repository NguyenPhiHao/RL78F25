/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_rsa.h                                                      */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for RSA library used in AUTOSAR Basic Software  */
/*               module "Crypto Driver".                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */
#ifndef R_RSA_H
#define R_RSA_H

/*----------------------------------------------------------------------------*/
/* Includes   <System Includes> , "Project Includes"                          */
/*----------------------------------------------------------------------------*/
#include "Platform_Types.h"
#include "Std_Types.h"
#include "r_mw_version.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* Macro definitions
/*----------------------------------------------------------------------------*/

/* Return Value */
#define RSA_OK                  (0u)        /* Sucessful                     */
#define RSA_PARAM_ERR           (1u)        /* Paramter Error                */
#define RSA_USER_DEF_FUNC_ERR   (2u)        /* User definiton function Error */
#define RSA_MOD_EXP_NG          (3u)        /* modulo exponnention API NG    */
#define RSA_SIG_GEN_NG          (4u)        /* Signature genearate API NG    */
#define RSA_SIG_VERIFY_NG       (5u)        /* Signature verify API NG       */
#define RSA_CANCEL_RTN          (6u)        /* RSA Process Canceleing return */
#define RSA_CANCEL_REJECT       (7u)        /* RSA Process Canceleing return */
#define RSA_RANGE_ERR           (8u)        /* ROM RAM Range Error           */

/* Hash type */
#define RSA_HASH_SHA256   ((uint8)0x00u)  /* SHA-256           */

/*----------------------------------------------------------------------------*/
/* Typedef definitions                                                        */
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint8 QL_70_FAR *p_adr;
    uint16 len;
} r_rsa_rom_bytedata_t;

typedef struct
{
    uint8 *p_adr;
    uint16 len;
} r_rsa_ram_bytedata_t;

#define RSA_WORK_BYTE (3680u)

typedef struct
{
    uint32 work[(RSA_WORK_BYTE / sizeof(uint32))];
} r_rsa_work_t;

typedef struct
{
    r_rsa_rom_bytedata_t key_n;
    r_rsa_rom_bytedata_t key_ed;
} r_rsa_key_t;

#define SIGNATURE_VERIFY_TIMES (3u) /* number of signature verifications */

/*----------------------------------------------------------------------------*/
/* Exported global variables                                                  */
/*----------------------------------------------------------------------------*/
extern const mw_version_t R_rsa_version;

/*----------------------------------------------------------------------------*/
/*Exported global functions (to be accessed by other files)                   */
/*----------------------------------------------------------------------------*/
/* API */
/* Function Name: R_RSA_ModExp */
/*----------------------------------------------------------------------------*/
/* brief         Modular exponentiation.
/* warning       none.
/* retval        RSA_OK Normal end.
/* retval        RSA_PARAM_ERR Parameter error end.
/* retval        RSA_MOD_EXP_NG Calculation failed.
/*----------------------------------------------------------------------------*/
uint8 R_RSA_ModExp (r_rsa_ram_bytedata_t *p_input, r_rsa_ram_bytedata_t *p_output, r_rsa_key_t *p_key, r_rsa_work_t *p_wk);

/* Function Name: R_RSA_SignatureGeneratePkcs */
/*----------------------------------------------------------------------------*/
/* brief         Signature Generation (RSASSA-PKCS1-V1_5).
/* warning       none.
/* retval        RSA_OK Normal end.
/* retval        RSA_PARAM_ERR Parameter error end.
/* retval        RSA_SIG_GEN_NG Signature generation failed.
/* retval        RSA_CANCEL_RTN  RSA Process Canceleing return.
/* retval        RSA_RANGE_ERR  Parameter ROM/RAM range error.
/*----------------------------------------------------------------------------*/
uint8 R_RSA_SignatureGeneratePkcs (r_rsa_rom_bytedata_t *p_mes, r_rsa_ram_bytedata_t *p_sig, r_rsa_key_t *p_key,
        uint8 hash_type, r_rsa_work_t *p_wk);

/* Function Name: R_RSA_SignatureVerifyPkcs */
/*----------------------------------------------------------------------------*/
/* brief         Signature Verification (RSASSA-PKCS1-V1_5).
/* warning       none.
/* retval        RSA_OK Normal end.
/* retval        RSA_PARAM_ERR Parameter error end.
/* retval        RSA_SIG_VERIFY_NG Verification failed.
/* retval        RSA_CANCEL_RTN  RSA Process Canceleing return.
/* retval        RSA_RANGE_ERR  Parameter ROM/RAM range error.
/*----------------------------------------------------------------------------*/
uint8 R_RSA_SignatureVerifyPkcs (r_rsa_ram_bytedata_t *p_sig, r_rsa_rom_bytedata_t *p_mes, r_rsa_key_t *p_key,
        uint8 hash_type, r_rsa_work_t *p_wk);

/*----------------------------------------------------------------------------*/
/* Declaration  : uint8 R_RSA_CancelReq()                                     */
/* Function Name: R_RSA_CancelReq                                             */
/* Description  : CANCEL request execution.                                   */
/* Arguments    : none                                                        */
/* Return Value : RSA_OK CANCEL request execution.                            */
/*              : RSA_CANCEL_REJECT CANCEL request reject.                    */
/*----------------------------------------------------------------------------*/
uint8 R_RSA_CancelReq(void);

#endif /* define R_RSA_H */
