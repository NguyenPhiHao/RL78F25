/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_shaif.c                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for SHA Hash library used in AUTOSAR Basic      */
/*               Software module “Crypto Driver”.                             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */

#ifndef R_SHAIF_H
#define R_SHAIF_H

/*----------------------------------------------------------------------------*/
/* Includes     <System Includes>   “Project Includes”                        */
/*----------------------------------------------------------------------------*
#include "r_sha.h"
#include "r_sha_core.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* Macro definitions                                                          */
/*----------------------------------------------------------------------------*/
#define R_PROCESS_RUNNING           (uint8)(0x5Au)

/* SHA256: Block Size=512, Word Size=32, MD Size=256 [bit] */
#define SHA256_MD_8_BIT_SIZE        (32u)
#define SHA256_MD_32_BIT_SIZE       (8u)

#define SHA_MD_8_BIT_SIZE           SHA256_MD_8_BIT_SIZE
#define SHA_MD_32_BIT_SIZE          SHA256_MD_32_BIT_SIZE
#define SHA_BLOCK_8_BIT_SIZE        SHA256_BLOCK_8_BIT_SIZE

#define MIN_PADDING_AREA            (8u + 1u)   /* 64-bit for the number l and 8-bit for the end of message */

#define SHA_PADDING_FIRST_VAL       (0x80u)

#define SHA_INPUT_MAX_BYTE_SIZE     (uint32)(0x1FFFFFFFu)

typedef struct
{
    uint32 length;
    union
    {
        uint8  md8[SHA256_MD_8_BIT_SIZE];
        uint32 md32[SHA256_MD_32_BIT_SIZE];
    } hash;
    uint8  buff[SHA256_BLOCK_8_BIT_SIZE];
    uint32 position;
    uint32 sha_work[SHA256_CALC_WORK_32_BIT_SIZE]; /* support SHA256 */
} r_sha_domain_t;

typedef union
{
    uint8  initValue[SHA_MD_8_BIT_SIZE];
    uint64 dummy;
} r_hash_t;

#endif /* define R_SHAIF_H */
