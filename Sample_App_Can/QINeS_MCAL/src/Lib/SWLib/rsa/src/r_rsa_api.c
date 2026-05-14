/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_rsa_api.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for RSA library used in AUTOSAR Basic Software  */
/*               module "Crypto Driver".                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* Includes   <System Includes> , "Project Includes"                          */
/******************************************************************************/
#include "r_rsa.h"
#include "r_mc_lib.h"
#include "r_rsa_internal_header.h"
#include "r_sha.h"
 
/*----------------------------------------------------------------------------*/
/* Macro definitions                                                          */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* Typedef definitions                                                        */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* Exported global variables (to be accessed by other files)                  */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
static volatile uint8 g_rsa_running    = RSA_STOP;    /* RSA Library Runing information */
#define CRYPTO_STOP_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
 
#define CRYPTO_START_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
volatile uint8 g_rsa_cancel_req = RSA_CLEAR;   /* RSA Library Cancel Reqest */
#define CRYPTO_STOP_SEC_VAR_INIT_LOCAL_8
#include "Crypto_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* Private global variables and functions                                     */
/*----------------------------------------------------------------------------*/
static uint8 r_make_rsassa_pkcs(r_rsa_rom_bytedata_t *p_mes, uint8 *p_buff, uint16 modn_len, uint8 hash_type);
static uint8 r_valid_key_check(r_rsa_key_t *key);
static uint8 R_RSA_IfHash(uint8 QL_70_FAR *p_mes, uint8 QL_70_NEAR *p_hash, uint16 mes_len, uint8 hash_type);
static uint8 r_rsa_sigcpy(uint8 * buff1, uint8 * buff2, uint32 len);
static uint8 r_rsa_sigset(uint8 * buff, uint8 data, uint32 len);
static uint8 r_rsa_sigcmp(uint8 * buff1, uint8 * buff2, uint32 len);
 
/* HASH ObjectID */
#define CRYPTO_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"
static const uint8 QL_70_FAR hash_oid_sha256[19] = {
    0x30u, 0x31u, 0x30u, 0x0du, 0x06u, 0x09u, 0x60u, 0x86u, 0x48u, 0x01u,
    0x65u, 0x03u, 0x04u, 0x02u, 0x01u, 0x05u, 0x00u, 0x04u, 0x20u
};
#define CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"
 
#define CRYPTO_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"
static const rsa_hash_info_t QL_70_FAR hash_info[RSA_HASH_TYPE_MAX] = {
        /* HASH ObjectID,                       ObjectID Len,                       hash size */
    {
        (uint8 QL_70_FAR *) hash_oid_sha256,    (uint16)sizeof(hash_oid_sha256),    32u
    }
};
#define CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"
 
/*----------------------------------------------------------------------------*/
 Exported global function
/*----------------------------------------------------------------------------*/

#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
/******************************************************************************/
 * Declaration  : uint8 R_RSA_SignatureGeneratePkcs (r_rsa_ram_bytedata_t *p_mes, r_rsa_ram_bytedata_t *p_sig,
 *                r_rsa_key_t *p_key, uint8 hash_type, r_rsa_work_t *p_wk)
 * Function Name: R_RSA_SignatureGeneratePkcs
 * Description  : Signature Generation (RSASSA-PKCS1-V1_5).
 * Arguments    : p_mes The message information to be signed.
 *              : p_sig Signature text storage destination information.
 *              : p_key Key information.
 *              : hash_type Hash method.
 *              : p_wk Work area.
 * Return Value : RSA_OK Normal end.
 *                RSA_PARAM_ERR  Parameter error end.
 *                RSA_SIG_GEN_NG  Signature generation failed.
 *                RSA_CANCEL_RTN  RSA Process Canceling return.
 *                RSA_RANGE_ERR  Parameter ROM/RAM range error.
/******************************************************************************/
/* Function Name: R_RSA_SignatureGeneratePkcs
/******************************************************************************
/* brief Signature Generation (RSASSA-PKCS1-V1_5).
/* param[in] p_mes The message information to be signed.
/* param[in] p_key Key information.
/* param[in] hash_type Hash method.
/* param[in,out] p_sig Signature text storage destination information.
/* param[in,out] p_wk Work area.
/* retval RSA_OK Normal end.
/* retval RSA_PARAM_ERR Parameter error end.
/* retval RSA_SIG_GEN_NG Signature generation failed.
/* retval RSA_CANCEL_RTN  RSA Process Canceling return.
/* retval RSA_RANGE_ERR  Parameter ROM/RAM range error.
/* details This API generates a signature according to RSASSA-PKCS1-V1_5.
/* note none.
/*/
 
uint8 R_RSA_SignatureGeneratePkcs(r_rsa_rom_bytedata_t *p_mes, r_rsa_ram_bytedata_t *p_sig, r_rsa_key_t *p_key, uint8 hash_type, r_rsa_work_t *p_wk)
{
    rsa_work_internal_t*    p_int_wk;
    uint8                   api_ret = RSA_PARAM_ERR;
 
    /* RSA Library Runing information */
    g_rsa_running = RSA_RUN;    /* RSA Library Runing information */
 
    /* Checking arguments */
    api_ret = r_valid_key_check(p_key);
 
    if (RSA_OK == api_ret)
    {
        if (RSA_HASH_TYPE_MAX <= hash_type)  /* Support 0x00:SHA-256 */
        {
            /* Hash Type error */
            api_ret = RSA_PARAM_ERR;
        }
        else if (p_key->key_n.len
                < (hash_info[hash_type].hash_oid_len + hash_info[hash_type].hash_len + RSA_RSASSA_PKCS_EM_MIN_LEN))
        {
            /* 9.2 EMSA-PKCS1-v1_5
             3. If emLen < tLen + 11, output "intended encoded message length too short" and stop. */
            api_ret = RSA_PARAM_ERR;
        }
        else if (NULL_PTR == p_mes)
        {
            /* Null Pointer */
            api_ret = RSA_PARAM_ERR;
        }
        else if (NULL_PTR == p_sig)
        {
            /* Null Pointer */
            api_ret = RSA_PARAM_ERR;
        }
        else if (p_sig->len < p_key->key_n.len)
        {
            api_ret = RSA_PARAM_ERR;
        }
        else if ((RANGE_NG == r_chk_rom_ram_range_valid(p_mes->p_adr, p_mes->len))    /* check input message range */
        ||  (RANGE_NG == r_chk_ram_range_valid(p_sig->p_adr, p_sig->len))      /* check output signature range */
        ||  (RANGE_NG == r_chk_ram_range_valid((uint8 *) p_wk, (uint16)sizeof(p_wk->work)))) /* check work */
        {
            api_ret = RSA_RANGE_ERR;
        }
        else
        {
            api_ret = RSA_OK;
        }
    }
    else
    {
        /* Do nothing */
    }
 
    if (RSA_OK == api_ret)
    {
        /* Start processing */
        if (RSA_OK != r_rsa_sigset((uint8*) p_wk, 0x00u, (uint32)sizeof(r_rsa_work_t)))
        {
            api_ret = RSA_SIG_GEN_NG;
            /* MOD : Terminate without executing subsequent processing. */
            g_rsa_cancel_req = RSA_CLEAR;   /* RSA Library Cancel Req clear   */
            g_rsa_running    = RSA_STOP;    /* RSA Library Runing information */
            return api_ret;
        }
        else
        {
            p_int_wk = (rsa_work_internal_t *) p_wk;
        }
 
        /* RSASSA-PKCS1-v1_5 format creation */
        api_ret = r_make_rsassa_pkcs(p_mes, p_int_wk->format_buff[0u], p_key->key_n.len, hash_type);
 
        if (RSA_OK != api_ret)
        {
            api_ret = RSA_SIG_GEN_NG;
        }
        else
        {
            p_int_wk->fbuff_bytedata[0u].p_adr = p_int_wk->format_buff[0u];
            p_int_wk->fbuff_bytedata[0u].len = p_key->key_n.len;
 
            api_ret = R_RSA_ModExp(&p_int_wk->fbuff_bytedata[0u], p_sig, p_key, p_wk);
 
            if (RSA_OK != api_ret)
            {
                if (api_ret == RSA_CANCEL_RTN)
                {
                    g_rsa_cancel_req = RSA_CANCEL;
                }
                else
                {
                    api_ret = RSA_SIG_GEN_NG;
                }
            }
            else
            /* End processing */
            /* R_RSA_SignatureGeneratePkcs_finish : */
            {
                if (RSA_OK != r_rsa_sigset((uint8*) p_wk, 0x00u, (uint32)sizeof(r_rsa_work_t)))
                {
                    api_ret = RSA_SIG_GEN_NG;
                }
                else
                {
                    p_int_wk = NULL_PTR;
                }
            }
        }
    }
    else
    {
        /* Do nothing */
    }
 
    /* RSA Library Finish Condition Check */
    if (g_rsa_cancel_req == RSA_CANCEL)
    {
        api_ret = RSA_CANCEL_RTN;   /* RSA Library Cancel Return information */
    }
    else
    {
        /* Do nothing */
    }
    g_rsa_cancel_req = RSA_CLEAR;   /* RSA Library Cancel Req clear   */
    g_rsa_running    = RSA_STOP;    /* RSA Library Runing information */
 
    return api_ret;
 
} /* End of function R_RSA_SignatureGeneratePkcs() */
 
/******************************************************************************/
 * Declaration  : uint8 R_RSA_SignatureVerifyPkcs(r_rsa_ram_bytedata_t *p_sig, r_rsa_ram_bytedata_t *p_mes,
 *                r_rsa_key_t *p_key, uint8 hash_type, r_rsa_work_t *p_wk)
 * Function Name: R_RSA_SignatureVerifyPkcs
 * Description  : Signature Verification (RSASSA-PKCS1-V1_5).
 * Arguments    : p_sig The signature information to be verified.
 *              : p_mes The message information to be verified.
 *              : p_key Key information.
 *              : hash_type Hash method.
 *              : p_wk Work area.
 * Return Value : RSA_OK Normal end.
 *                RSA_PARAM_ERR  Parameter error end.
 *                RSA_SIG_VERIFY_NG  Signature verify failed.
 *                RSA_CANCEL_RTN  RSA Process Canceling return.
 *                RSA_RANGE_ERR  Parameter ROM/RAM range error.
/******************************************************************************/
/******************************************************************************
 * Function Name: R_RSA_SignatureVerifyPkcs
 ******************************************************************************
 * brief Signature Generation (RSASSA-PKCS1-V1_5).
 * param[in] p_sig The signature information to be verified.
 * param[in] p_mes The message information to be verified.
 * param[in] p_key Key information.
 * param[in] hash_type Hash method.
 * param[in,out] p_wk Work area.
 * retval RSA_OK Normal end.
 * retval RSA_PARAM_ERR Parameter error end.
 * retval RSA_SIG_VERIFY_NG Verification failed.
 * retval RSA_CANCEL_RTN  RSA Process Canceling return.
 * retval RSA_RANGE_ERR  Parameter ROM/RAM range error.
 * details This API verifies the signature according to RSASSA-PKCS1-V1_5.
 * note none.
 */
uint8 R_RSA_SignatureVerifyPkcs(r_rsa_ram_bytedata_t *p_sig, r_rsa_rom_bytedata_t *p_mes, r_rsa_key_t *p_key, uint8 hash_type, r_rsa_work_t *p_wk)
{
    rsa_work_internal_t* p_int_wk;
    uint8 api_ret = RSA_PARAM_ERR;
    uint8 signature_cmp = SIGNATURE_VERIFY_TIMES;   /* number of signature verifications */
    uint8 threshold     = SIGNATURE_VERIFY_TIMES / 2u;  /* e.g., 3/2 = 1, 4/2 = 2, 5/2 = 2   */
    uint8 ok_cnt;
 
    /* RSA Library Runing information */
    g_rsa_running = RSA_RUN;    /* RSA Library Runing information */
 
    /* Checking arguments */
    api_ret = r_valid_key_check(p_key);
 
    if (RSA_OK == api_ret)
    {
        if (RSA_HASH_TYPE_MAX <= hash_type)  /* Support 0x00:SHA-256 */
        {
            /* Hash Type error */
            api_ret = RSA_PARAM_ERR;
        }
        else if (p_key->key_n.len
                 < (hash_info[hash_type].hash_oid_len + hash_info[hash_type].hash_len + RSA_RSASSA_PKCS_EM_MIN_LEN))
        {
            /* 9.2 EMSA-PKCS1-v1_5
             3. If emLen < tLen + 11, output "intended encoded message length too short" and stop. */
            api_ret = RSA_PARAM_ERR;
        }
        else if (NULL_PTR == p_sig)
        {
            /* Null Pointer */
            api_ret = RSA_PARAM_ERR;
        }
        else if (p_sig->len != p_key->key_n.len)
        {
            /* 8.2.2 Signature verification operation
             1. Length checking: If the length of the signature S is not k octets,
                output "invalid signature" and stop. */
            api_ret = RSA_PARAM_ERR;
        }
        else if (NULL_PTR == p_mes)
        {
            /* Null Pointer */
            api_ret = RSA_PARAM_ERR;
        }
        else if ((RANGE_NG == r_chk_ram_range_valid(p_sig->p_adr, p_sig->len))  /* check input signature range */
        ||  (RANGE_NG == r_chk_rom_ram_range_valid(p_mes->p_adr, p_mes->len))   /* check input message range */
        ||  (RANGE_NG == r_chk_ram_range_valid((uint8 *) p_wk, (uint16)sizeof(p_wk->work)))) /* check work */
 
        {
            api_ret = RSA_RANGE_ERR;
        }
        else
        {
            api_ret = RSA_OK;
        }
    }
    else
    {
        /* Do nothing */
    }
 
    if (RSA_OK == api_ret)
    {
        /* Start processing */
        if (RSA_OK != r_rsa_sigset((uint8*) p_wk, 0x00u, (uint32)sizeof(r_rsa_work_t)))
        {
            api_ret = RSA_SIG_VERIFY_NG;
            /* MOD : Terminate without executing subsequent processing. */
            g_rsa_cancel_req = RSA_CLEAR;   /* RSA Library Cancel Req clear   */
            g_rsa_running    = RSA_STOP;    /* RSA Library Runing information */
            return api_ret;
        }
        else
        {
            p_int_wk = (rsa_work_internal_t *) p_wk;
        }
       
        p_int_wk->fbuff_bytedata[1u].p_adr = p_int_wk->format_buff[1u];
        p_int_wk->fbuff_bytedata[1u].len = IO_DATA_BYTE_LENGTH;
 
        /* Execution of modular exponentiation */
        api_ret = R_RSA_ModExp(p_sig, &p_int_wk->fbuff_bytedata[1u], p_key, p_wk);
 
        if (RSA_OK != api_ret)
        {
            if (api_ret == RSA_CANCEL_RTN)
            {
                g_rsa_cancel_req = RSA_CANCEL;
            }
            else
            {
                api_ret = RSA_SIG_VERIFY_NG;
            }
        }
        else
        {
            /* Create encoded message for compare */
            if (RSA_OK != r_make_rsassa_pkcs(p_mes, p_int_wk->format_buff[0u], p_key->key_n.len, hash_type))
            {
                api_ret = RSA_SIG_VERIFY_NG;
            }
            else
            {
                /* Message compare with take majority */
                ok_cnt = 0u;
                while (signature_cmp > 0u)
                {
                    if (RSA_OK == r_rsa_sigcmp(p_int_wk->format_buff[0u], p_int_wk->format_buff[1u], (uint32) p_key->key_n.len))
                    {
                        ok_cnt++;
                    }
                    else
                    {
                        /* Do nothing */
                    }
                    signature_cmp--;
                }
                if (ok_cnt > threshold)
                {
                    api_ret = RSA_OK;
                }
                else
                {
                    api_ret = RSA_SIG_VERIFY_NG;
                }
            }
        }
        /* End processing */
        /* R_RSA_SignatureVerifyPkcs_finish : */
        if (RSA_OK != r_rsa_sigset((uint8*) p_wk, 0x00u, (uint32)sizeof(r_rsa_work_t)))
        {
            api_ret = RSA_SIG_VERIFY_NG;
        }
        else
        {
            p_int_wk = NULL_PTR;
        }
    }
    else
    {
        /* Do nothing */
    }
 
    /* RSA Library Finish Condition Check */
    if (g_rsa_cancel_req == RSA_CANCEL)
    {
        api_ret = RSA_CANCEL_RTN;   /* RSA Library Cancel Return information */
    }
    else
    {
        /* Do nothing */
    }
    g_rsa_cancel_req = RSA_CLEAR;   /* RSA Library Cancel Req clear   */
    g_rsa_running    = RSA_STOP;    /* RSA Library Runing information */
 
    return api_ret;
 
} /* End of function R_RSA_SignatureVerifyPkcs() */
 
/******************************************************************************/
 * Declaration  : uint8 R_RSA_ModExp(r_rsa_ram_bytedata_t *p_input, r_rsa_ram_bytedata_t *p_output,
 *                r_rsa_key_t *p_key, r_rsa_work_t *p_wk)
 * Function Name: R_RSA_ModExp
 * Description  : Modular exponentiation.
 * Arguments    : p_input Calculation information.
 *              : p_output Calculated data storage destination information.
 *              : p_key Exponent of modulus exponentiation (e or d) and modulus (n) information.
 *              : p_wk Work area.
 * Return Value : RSA_OK Normal end.
 *                RSA_PARAM_ERR  Parameter error end.
 *                RSA_RSA_MOD_EXP_NG  Modular exponentiation failed.
 *                RSA_CANCEL_RTN  RSA Process Canceling return.
 *                RSA_RANGE_ERR  Parameter ROM/RAM range error.
/******************************************************************************/
/******************************************************************************
 * Function Name: R_RSA_ModExp
 ******************************************************************************
 * brief Modular exponentiation.
 * param[in] p_input Calculation information.
 * param[in] p_key Exponent of modulus exponentiation (e or d) and modulus (n) information.
 * param[in,out] p_output Calculated data storage destination information.
 * param[in,out] p_wk Work area.
 * retval RSA_OK Normal end.
 * retval RSA_PARAM_ERR Parameter error end.
 * retval RSA_MOD_EXP_NG Calculation failed.
 * retval RSA_CANCEL_RTN  RSA Process Canceling return.
 * retval RSA_RANGE_ERR  Parameter ROM/RAM range error.
 * details This API performs Modular exponentiation.
 * note none.
 */
uint8 R_RSA_ModExp(r_rsa_ram_bytedata_t *p_input, r_rsa_ram_bytedata_t *p_output, r_rsa_key_t *p_key, r_rsa_work_t *p_wk)
{
    rsa_exponential_t*  p_expn_wk;
    uint8               api_ret = RSA_PARAM_ERR;
 
    /* RSA Library Runing information */
    g_rsa_running = RSA_RUN;    /* RSA Library Runing information */
 
    /* Checking arguments */
    api_ret = r_valid_key_check(p_key);
 
    if (RSA_OK == api_ret)
    {
        if (NULL_PTR == p_input)
        {
        /* Null Pointer */
            api_ret = RSA_PARAM_ERR;
        }
        else if ((uint16) 0 == p_input->len)
        {
            api_ret = RSA_PARAM_ERR;
        }
        else if (p_key->key_n.len < p_input->len)
        {
            api_ret = RSA_PARAM_ERR;
        }
        else if (NULL_PTR == p_output)
        {
            /* Null Pointer */
            api_ret = RSA_PARAM_ERR;
        }
        else if (p_key->key_n.len > p_output->len)
        {
            api_ret = RSA_PARAM_ERR;
        }
        else if ((RANGE_NG == r_chk_ram_range_valid(p_input->p_adr, p_input->len))   /* check input data range */
        ||  (RANGE_NG == r_chk_ram_range_valid(p_output->p_adr, p_output->len))     /* check output data range */
        ||  (RANGE_NG == r_chk_ram_range_valid((const uint8 *) p_wk, (uint16)sizeof(p_wk->work)))) /* check work */
 
        {
            api_ret = RSA_RANGE_ERR;
        }
        else
        {
            api_ret = RSA_OK;
        }
    }
    else
    {
        /* Do nothing */
    }
 
    if (RSA_OK == api_ret)
    {
        /* Start processing */
        p_expn_wk = &((rsa_work_internal_t *) p_wk)->expn;
 
        if (RSA_OK != r_rsa_sigset((uint8 *) p_expn_wk, 0x00u, (uint32)sizeof(rsa_exponential_t)))
        {
            api_ret = RSA_MOD_EXP_NG;
        }
        else
        {
            p_expn_wk->work2_bytedata.p_adr = p_expn_wk->mc_memory_work.work2;
            p_expn_wk->work2_bytedata.len = IO_DATA_BYTE_LENGTH;
 
 
 
            p_expn_wk->mc_p.len = MC_INT_ARRAY_LENGTH;
            p_expn_wk->mc_p.val = p_expn_wk->sdl_memory[0u];  /* object is holds the even alignment */
 
            p_expn_wk->mc_a.len = MC_INT_ARRAY_LENGTH;
            p_expn_wk->mc_a.val = p_expn_wk->sdl_memory[1u]; /* object is holds the even alignment */
 
            p_expn_wk->mc_b.len = MC_INT_ARRAY_LENGTH;
            p_expn_wk->mc_b.val = p_expn_wk->sdl_memory[2u]; /* object is holds the even alignment */
 
            p_expn_wk->mc_c.len = MC_INT_ARRAY_LENGTH;
            p_expn_wk->mc_c.val = p_expn_wk->sdl_memory[3u]; /* object is holds the even alignment */
        }
 
        /* Storing an array of one byte MC_int variable */
        if (RSA_OK != r_mc_byte2mc(p_key->key_n.p_adr, p_key->key_n.len, &p_expn_wk->mc_p))
        {
            api_ret = RSA_MOD_EXP_NG;
        }
        else if (RSA_OK != r_mc_byte2mc(p_input->p_adr, p_input->len, &p_expn_wk->mc_a))
        {
            api_ret = RSA_MOD_EXP_NG;
        }
        else if (RSA_OK != r_mc_byte2mc(p_key->key_ed.p_adr, p_key->key_ed.len, &p_expn_wk->mc_b))
        {
            api_ret = RSA_MOD_EXP_NG;
        }
        else if (0u == r_mc_cmpl(&p_expn_wk->mc_a, &p_expn_wk->mc_p))
        {
            api_ret = RSA_MOD_EXP_NG;
        }
        else
        {
            /* Modular exponentiation */
            if (RSA_OK != r_mc_powm(&p_expn_wk->mc_a, &p_expn_wk->mc_b, &p_expn_wk->mc_c, &p_expn_wk->mc_p,
                p_expn_wk->mc_memory_work.MC_memory[0u], p_expn_wk->mc_memory_work.MC_memory[1u]))
            {
                api_ret = RSA_MOD_EXP_NG;
            }
 
            /* Output results are temporarily stored in the work */
            else if (RSA_OK != r_rsa_sigset((uint8 *) p_expn_wk->work2_bytedata.p_adr,
                     0x00u, (uint32) p_expn_wk->work2_bytedata.len))
            {
                api_ret = RSA_MOD_EXP_NG;
            }
            else if (RSA_OK != r_mc_mc2byte(&p_expn_wk->mc_c, p_expn_wk->work2_bytedata.p_adr,
                     &p_expn_wk->work2_bytedata.len))
            {
                api_ret = RSA_MOD_EXP_NG;
            }
            else
            {
                /* Output result =>  User memory */
                /* MOD : For the elimination of pointer arithmetic. */
                if (RSA_OK != r_rsa_sigcpy(p_output->p_adr,
                    &p_expn_wk->work2_bytedata.p_adr[IO_DATA_BYTE_LENGTH - p_key->key_n.len], (uint32) p_key->key_n.len))
                {
                    api_ret = RSA_MOD_EXP_NG;
                }
                else
                {
                    p_output->len = p_key->key_n.len;
                }
            }
 
            /* End processing */
            /* R_RSA_ModExp_finish : */
            if (RSA_OK != r_rsa_sigset((uint8 *) p_expn_wk, 0x00u, (uint32)sizeof(rsa_exponential_t)))
            {
                api_ret = RSA_MOD_EXP_NG;
            }
            else
            {
                /* Do nothing */
            }
            p_expn_wk = NULL_PTR;
        }
    }
    else
    {
        /* Do nothing */
    }
 
    /* RSA Library Finish Condition Check */
    if (g_rsa_cancel_req == RSA_CANCEL)
    {
        api_ret = RSA_CANCEL_RTN;   /* RSA Library Cancel Return information */
    }
    else
    {
        /* Do nothing */
    }
 
    g_rsa_cancel_req = RSA_CLEAR;   /* RSA Library Cancel Req clear   */
    g_rsa_running    = RSA_STOP;    /* RSA Library Runing information */
 
    return api_ret;
 
} /* End of function R_RSA_ModExp() */
 
/******************************************************************************/
 * Declaration  : uint8 r_valid_key_check (r_rsa_key_t *key)
 * Function Name: r_valid_key_check
 * Description  : Check if the key information is valid.
 * Arguments    : key Key information.
 * Return Value : RSA_OK Normal end.
 *                RSA_PARAM_ERR  Parameter error end.
 *                RSA_RANGE_ERR  Parameter ROM/RAM range error.
/******************************************************************************/
static uint8 r_valid_key_check(r_rsa_key_t *key)
{
 
    uint8 api_ret = RSA_RUN;
 
    if (NULL_PTR == key)
    {
        /* Null Address */
        api_ret = RSA_PARAM_ERR;
    }
    else if (0u == key->key_n.len)      /* Key N length check */
    {
        /* Key length is invalid */
        api_ret = RSA_PARAM_ERR;
    }
    else if (IO_DATA_BYTE_LENGTH < key->key_n.len)
    {
        /* Key length is invalid */
        api_ret = RSA_PARAM_ERR;
    }
    else if (RANGE_NG == r_chk_rom_ram_range_valid(key->key_n.p_adr, key->key_n.len)) /* key_n range check */
    {
        api_ret = RSA_RANGE_ERR;
        /* Null Address or ROM/RAM range invalid */
    }
    else if (0x00u == (*key->key_n.p_adr))     /* Check the value of the address pointed to by key_n.p_adr */
    {
        /* Value is 0x00 */
        api_ret = RSA_PARAM_ERR;
    }
    else if (0u == key->key_ed.len)             /* Key EorD length check */
    {
        /* Key length is invalid */
        api_ret = RSA_PARAM_ERR;
    }
    else if (IO_DATA_BYTE_LENGTH < key->key_ed.len)
    {
        /* Key length is invalid */
        api_ret = RSA_PARAM_ERR;
    }
    else if (RANGE_NG == r_chk_rom_ram_range_valid(key->key_ed.p_adr, key->key_ed.len)) /* key_ed range check */
    {
        /* Null Address or ROM/RAM range invalid */
        api_ret = RSA_RANGE_ERR;
    }
    else if (0x00u == (*key->key_ed.p_adr))    /* Check the value of the address pointed to by key_ed.p_adr */
    {
        /* value is 0x00 */
        api_ret = RSA_PARAM_ERR;
    }
    else
    {
        api_ret = RSA_OK;
    }
 
    return api_ret;
 
} /* End of function r_valid_key_check() */
 
/******************************************************************************/
 * Declaration  : uint8 r_make_rsassa_pkcs(r_rsa_rom_bytedata_t *p_mes, uint8 *p_buff, uint16 modn_len,
 *                uint8 hash_type)
 * Function Name: r_make_rsassa_pkcs
 * Description  : RSAPSS_PKCS1_V1_5 Signature Generation.
 * Arguments    : p_mes The message information to be signed.
 *              : p_buff Storage location.
 *              : modn_len Effective number of bytes for modulus n (= length of encoded message).
 *              : hash_type Hash method.
 * Return Value : RSA_OK Normal end.
 *                RSA_USER_DEF_FUNC_ERR User definition function error end.
/******************************************************************************/
static uint8 r_make_rsassa_pkcs(r_rsa_rom_bytedata_t *p_mes, uint8 *p_buff, uint16 modn_len, uint8 hash_type)
{
    uint16  len;
    uint8   api_ret = RSA_OK;
    uint32  w_buff_idx = 0u;
 
    /* RSASSA-PKCS1-v1_5 format creation */
 
    /*       (1)   |  (2)   | (3)  |  (4)   | (5) ::      (5-1) | (5-2) */
    /* EM = [0x00] | [0x01] | [PS] | [0x00] | [T] ::  T = [OID] |  [H]  */
 
    /* (1) */
    /* MOD : For the elimination of pointer arithmetic. */
    p_buff[w_buff_idx] = 0x00u;
    w_buff_idx++;
 
    /* (2) */
    /* MOD : For the elimination of pointer arithmetic. */
    p_buff[w_buff_idx] = 0x01u;
    w_buff_idx++;
 
    /* (3) */ /* "3" is (1)+(2)+(4) */
    /* MOD : For the elimination of pointer arithmetic. */
    if (RSA_OK != r_rsa_sigset(&p_buff[w_buff_idx], 0xffu,
       ((uint32)modn_len - ((uint32)3u + (uint32)hash_info[hash_type].hash_oid_len + (uint32)hash_info[hash_type].hash_len))))
    {
        api_ret = RSA_USER_DEF_FUNC_ERR;
    }
    else
    {
        /* Do nothing */
    }
 
    /* MOD : For the elimination of pointer arithmetic. */
    w_buff_idx += (uint32)(modn_len - ((uint32) 3u + hash_info[hash_type].hash_oid_len
           + hash_info[hash_type].hash_len));
 
    /* (4) */
    /* MOD : For the elimination of pointer arithmetic. */
    p_buff[w_buff_idx] = 0x00u;
    w_buff_idx++;
 
    /* (5-1) */
    /* MOD : For the elimination of pointer arithmetic. */
    for (len = (uint16)0; len < hash_info[hash_type].hash_oid_len; len++)
    {
        p_buff[w_buff_idx] = hash_info[hash_type].p_hash_oid[len];
        w_buff_idx++;
    }
 
    /* (5-2) */
    /* MOD : For the elimination of pointer arithmetic. */
    if (0u != R_RSA_IfHash(p_mes->p_adr, &p_buff[w_buff_idx], p_mes->len, hash_type))
    {
        api_ret = RSA_USER_DEF_FUNC_ERR;
    }
    else
    {
        /* Do nothing */
    }
 
    /* Erase data for safety */
    len = 0u;
 
    return api_ret;
 
} /* End of function r_make_rsassa_pkcs() */
 
/******************************************************************************/
 * Function Name: R_RSA_IfHash
 * Description  : Sample program of R_RSA_IfHash().
 * Arguments    : p_mes Start address of message.
 *                p_hash Hash calculation result storage address.
 *                mes_len Valid byte count of message.
 *                hash_type Hash type.
 * Return Value : 0 Hash calculation successful.
 *                Other than 0 Hash calculation failed.
/******************************************************************************/
/******************************************************************************
 * Function Name: R_RSA_IfHash
 ******************************************************************************
 * brief Calculate Hash.
 * param[in] p_mes Start address of message.
 * param[out] p_hash Hash calculation result storage address.
 * param[in] mes_len Valid byte count of message
 * param[in] hash_type Hash type.
 * retval 0 Hash calculation successful.
 * retval Other than 0 Hash calculation failed.
 * details This function must be implemented in order to run
 * R_rsa_signature_generate() and R_rsa_signature_verify(). The hash is
 * calculated for the number of bytes of data specified by the argument mes_len,
 * starting from the address specified by the argument p_mes. The hash method is
 * specified by the argument hash. The calculation result should be stored at
 * the address specified by the argument p_hash. The calculation result and the
 * size of the stored calculation result differ depending on the hash method.
 * note none.
 */
 
static uint8 R_RSA_IfHash(uint8 QL_70_FAR *p_mes, uint8 QL_70_NEAR *p_hash, uint16 mes_len, uint8 hash_type)
{
    uint8               api_ret = RSA_OK;
    r_sha256_handle_t   sha_work;
 
    if (RSA_HASH_SHA256 == hash_type) {
        if ((uint8) 0u != R_SHA_256HashDigest(p_mes, p_hash, mes_len, (R_SHA_INIT | R_SHA_FINISH), &sha_work))
        {
            api_ret = RSA_PARAM_ERR;
        }
        else
        {
            /* Do nothing */
        }
    } else {
        api_ret = RSA_PARAM_ERR;
    }
 
    return api_ret;
 
} /* End of function R_RSA_IfHash() */
 
/******************************************************************************/
 * Declaration  : uint8 R_RSA_CancelReq()
 * Function Name: R_RSA_CancelReq
 * Description  : CANCEL request execution.
 * Arguments    : none
 * Return Value : RSA_OK CANCEL request execution.
 *              : RSA_CANCEL_REJECT CANCEL request reject (RSA API not running).
/******************************************************************************/
uint8 R_RSA_CancelReq(void)
{
 
    uint8 api_ret = RSA_RUN;
 
    if (g_rsa_running == RSA_RUN)
    {
        g_rsa_cancel_req = RSA_CANCEL;   /* RSA Library Cancel Req ON */
        api_ret = RSA_OK;
    }
    else
    {
        api_ret = RSA_CANCEL_REJECT;
    }
 
    return api_ret;
 
} /* End of function R_RSA_CancelReq() */
 
/******************************************************************************/
 * Declaration  : void r_rsa_sigcpy(uint8 * buff1, uint8 * buff2, uint32 len)
 * Function Name: r_rsa_sigcpy
 * Description  : Signature data copy.
 * Arguments    : buff1 Copied storage location.
 *              : buff2 The message information to be copied.
 *              : len  Copy size
 * Return Value : none
/******************************************************************************/
static uint8 r_rsa_sigcpy(uint8 * buff1, uint8 * buff2, uint32 len)
{
    uint32  i;
    uint8   api_ret = RSA_RUN;
   
    for(i = 0u; i < len; i++)
    {
        buff1[i] = buff2[i];
 
        /* RSA Library Cancel Reqest Check */
        if (g_rsa_cancel_req == RSA_CANCEL)
        {
            api_ret = RSA_CANCEL_RTN;   /* RSA Library Cancel Return */
            break;                      /* RSA Library Cancel Break */
        }
        else
        {
            /* Do nothing */
        }
    }
 
    if (api_ret == RSA_RUN)
    {
        api_ret = RSA_OK;
    }
    else
    {
        /* Do nothing */
    }
 
    return api_ret;
 
} /* End of function r_rsa_sigcpy() */
 
/******************************************************************************/
 * Declaration  : uint8 r_rsa_sigset(uint8 * buff, uint8 data, uint32 len)
 * Function Name: r_rsa_sigset
 * Description  : Signature data set.
 * Arguments    : buff The setting strage location
 *              : data Information to be set
 *              : len  Setting size
 * Return Value : RSA_OK
 *                RSA_CANCEL_RTN
/******************************************************************************/
static uint8 r_rsa_sigset(uint8 * buff, uint8 data, uint32 len)
{
    uint32  i;
    uint8   api_ret = RSA_RUN;
   
    for (i = 0u; i < len; i++)
    {
        buff[i] = data;
 
        /* RSA Library Cancel Reqest Check */
        if (g_rsa_cancel_req == RSA_CANCEL)
        {
            api_ret = RSA_CANCEL_RTN;   /* RSA Library Cancel Return */
            break;                      /* RSA Library Cancel Break */
        }
        else
        {
            /* Do nothing */
        }
    }
 
    if (api_ret == RSA_RUN)
    {
        api_ret = RSA_OK;
    }
    else
    {
        /* Do nothing */
    }
 
    return api_ret;
 
} /* End of function r_rsa_rsa_sigset() */
 
/******************************************************************************/
 * Declaration  : uint8 r_rsa_sigcmp(uint8 * buff1, uint8 * buff2, uint32 len)
 * Function Name: r_rsa_sigcmp
 * Description  : Signature data compare.
 * Arguments    : buff1 Data to be compared.
 *              : buff2 Data to compare.
 *              : len  Size to compare.
 * Return Value : RSA_OK Comparison matches.
 *                RSA_PARAM_ERR Comparison failed.
/******************************************************************************/
static uint8 r_rsa_sigcmp(uint8 * buff1, uint8 * buff2, uint32 len)
{
    uint32  i;
    uint8   api_ret = RSA_RUN;
   
    for (i = 0u; i < len; i++)
    {
        /* Perform compare processing to the end by  Riscure WP-3.6 correspondence*/
        if (buff1[i] != buff2[i])
        {
            api_ret = RSA_PARAM_ERR;
        }
        else
        {
            /* Do nothing */
        }
 
        /* RSA Library Cancel Reqest Check */
        if (g_rsa_cancel_req == RSA_CANCEL)
        {
            api_ret = RSA_CANCEL_RTN;   /* RSA Library Cancel Return */
            break;                      /* RSA Library Cancel Break */
        }
        else
        {
            /* Do nothing */
        }
    }
 
    if (api_ret == RSA_RUN)
    {
        api_ret = RSA_OK;
    }
    else
    {
        /* Do nothing */
    }
 
    return api_ret;
 
} /* End of function r_rsa_rsa_sigcmp() */
#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
 
 