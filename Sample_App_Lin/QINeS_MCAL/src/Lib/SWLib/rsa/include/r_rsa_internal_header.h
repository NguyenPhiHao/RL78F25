/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : QINeS-Lite MCAL                                              */
/* File Name   : r_rsa_internal_header.h                                      */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for RSA library used in AUTOSAR Basic Software  */
/*                module "Crypto Driver".                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */


/* Include mc_lib.h before including this file */
#ifndef R_RSA_INTERNAL_HEADER_H
#define R_RSA_INTERNAL_HEADER_H

/*----------------------------------------------------------------------------*/
/* Includes   <System Includes>, "Project Includes"
/*----------------------------------------------------------------------------*/
#include "r_rsa.h"

/*----------------------------------------------------------------------------*/
/* Macro definitions
/*----------------------------------------------------------------------------*/
/* Define the maximum value of RSA_HASH_XXXXX in r_rsa.h + 1 */
#define RSA_HASH_TYPE_MAX              ((uint8)0x01u)   /* MAX */

/* RSA encryption/decryption Minimum key size of RSAES-PKCS1_V1_5 */
#define RSA_RSAES_PKCS_MIN_KEY_N_LEN   ((uint16)11)

/* RSA signature generation/verification Minimum size of RSASSA-PKCS1_V1_5 encoded message excluding [T] */
#define RSA_RSASSA_PKCS_EM_MIN_LEN     ((uint16)11)

#define SDL_MEMORY_SIZE   ((IO_DATA_BYTE_LENGTH*2u) + 2u)  /* 514 Bytes */
#define SDL_MEMORY_NUM    (4u)
#define MC_WORK_BYTE      (IO_DATA_BYTE_LENGTH*2u)

/*----------------------------------------------------------------------------*/
/* type definitions
/*----------------------------------------------------------------------------*/
typedef struct
{
    MC        sdl_memory[SDL_MEMORY_NUM][SDL_MEMORY_SIZE/2];
    MC_int    mc_p;               /* Prime p */
    MC_int    mc_a;               /* Base a */
    MC_int    mc_b;               /* Exponent b */
    MC_int    mc_c;               /* Calculation result c */
    r_rsa_ram_bytedata_t work2_bytedata;
    union {
        uint8   work2[MC_WORK_BYTE];                           /* For PKCS padding */
        MC      MC_memory[MC_MEMORY_NUM][SDL_MEMORY_SIZE/2];
    } mc_memory_work;
} rsa_exponential_t;

#define FORMAT_BUFF_NUM    (2u)

typedef struct
{
    uint8                       format_buff[FORMAT_BUFF_NUM][IO_DATA_BYTE_LENGTH];   /* PKCS format data creation part */
    r_rsa_ram_bytedata_t        r_buff_bytedata[FORMAT_BUFF_NUM];                    /* R_RSA_BYTEDATA_T of format_buff */
    rsa_exponential_t           expn;                                                /* Area used for modular exponentiation */
} rsa_work_internal_t;

typedef struct
{
    uint8  QL_70_FAR           *p_hash_oid;   /* Start address of DER encoded object ID (HashDigest) */
    uint16                      hash_oid_len; /* HashDigest byte length */
    uint16                      hash_len;     /* Hash value byte length */
} rsa_hash_info_t;

/* Condition */
#define RSA_RUN    ((uint8)0xA5U)  /* RSA Library Run     */
#define RSA_STOP   ((uint8)0x5AU)  /* RSA Library Stop    */
#define RSA_CLEAR  ((uint8)0x03U)  /* RSA Library Cancel Clear */
#define RSA_CANCEL ((uint8)0xC0U)  /* RSA Library Cancel Set   */

/*----------------------------------------------------------------------------*/
/* Exported global variables                                                  */
/*----------------------------------------------------------------------------*/
extern volatile uint8 g_rsa_cancel_req;  /* RSA Library Cancel Request */

/*----------------------------------------------------------------------------*/
/* Exported global functions (to be accessed by other files)                  */
/*----------------------------------------------------------------------------*/

#endif  /* define R_RSA_INTERNAL_HEADER_H */
