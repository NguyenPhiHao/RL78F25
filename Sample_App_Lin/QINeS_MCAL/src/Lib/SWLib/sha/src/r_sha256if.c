/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_sha256if.c                                                 */
/* Version     : v1.00.01                                                     */
/* Contents    : This file is for SHA Hash library used in AUTOSAR Basic      */
/*               Software module "Crypto Driver".                             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */

#include "r_shaif.h"
 
/*----------------------------------------------------------------------------*/
/* Macro definitions                                                          */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* Private global variables and functions                                     */
/*----------------------------------------------------------------------------*/
/* For SHA-256, the initial hash value, H(0), shall consist of the following eight 32-bit words, in hex: */
#define CRYPTO_START_SEC_CONST_8
#include "Crypto_MemMap.h"
static const r_hash_t initialHahValues =
{
    {
        0x6au, 0x09u, 0xe6u, 0x67u, /* H0 = 6a09e667 */
        0xbbu, 0x67u, 0xaeu, 0x85u, /* H1 = bb67ae85 */
        0x3cu, 0x6eu, 0xf3u, 0x72u, /* H2 = 3c6ef372 */
        0xa5u, 0x4fu, 0xf5u, 0x3au, /* H3 = a54ff53a */
        0x51u, 0x0eu, 0x52u, 0x7fu, /* H4 = 510e527f */
        0x9bu, 0x05u, 0x68u, 0x8cu, /* H5 = 9b05688c */
        0x1fu, 0x83u, 0xd9u, 0xabu, /* H6 = 1f83d9ab */
        0x5bu, 0xe0u, 0xcdu, 0x19u  /* H7 = 5be0cd19 */
    }
};
#define CRYPTO_STOP_SEC_CONST_8
#include "Crypto_MemMap.h"
 
#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
/*----------------------------------------------------------------------------*/
/* Declaration  : R_SHA_256HashDigest(uint8 QL_70_FAR *mdat, uint8 QL_70_NEAR *hdat, uint16 len, uint8 flag,
/* void QL_70_NEAR *work)
/* Function Name: R_SHA_256HashDigest
/* Description  : Secure hash algorithms based on SHA-256 specification to computing a condensed representation of
/* electronic data (message).
/* Arguments    : mdat Address of a input message.
/*                hdat Address of message digest.
/*                len Length of message (unit : byte).
/*                flag Control flag.
/*                work Address of work area.
/* Return Value : R_PROCESS_COMPLETE Normal end.
/*                R_SHA_ERROR_POINTER Pointer "hdat" or "work" is NULL.
/*                R_SHA_ERROR_FLAG Incorrect flag is specified.
/*                R_SHA_ERROR_LENGTH Pointer "mdat" is NULL, and len > 0, or 0x1FFFFFFF < (d->length + len).
/*                R_SHA_ERROR_CRC CRC verification of Initial Hash failed.
/*----------------------------------------------------------------------------*/
uint8 R_SHA_256HashDigest(const uint8 QL_70_FAR *mdat, uint8 QL_70_NEAR *hdat, uint16 len,
                    uint8 flag, r_sha256_handle_t QL_70_NEAR *work)
{
    uint16 i;
    uint16 n;
    r_sha_domain_t QL_70_NEAR * d = (r_sha_domain_t QL_70_NEAR *)work;
    uint16 local_len = len;
    uint8  sha_ret = R_PROCESS_RUNNING;
 
    /* check input work and hdat address */
    if ((RANGE_NG == r_chk_ram_range_valid((uint8 *) work, (uint16)sizeof(r_sha_domain_t)))
    ||  (RANGE_NG == r_chk_ram_range_valid((uint8 *) hdat, SHA_MD_8_BIT_SIZE)))
    {
        sha_ret = R_SHA_ERROR_POINTER;
    }
 
    if (R_PROCESS_RUNNING == sha_ret)
    {
        /* check input flag parameter */
        if ((flag != R_SHA_ADD) && (flag != R_SHA_INIT) && (flag != R_SHA_FINISH)
         && (flag != (R_SHA_INIT | R_SHA_FINISH)) && (flag != (R_SHA_FINISH | R_SHA_NOPADDING))
         && (flag != (R_SHA_INIT | R_SHA_FINISH | R_SHA_NOPADDING)))
        {
            sha_ret = R_SHA_ERROR_FLAG;
        }
    }
 
    if (R_PROCESS_RUNNING == sha_ret)
    {
        /* check input len parameter and mdat address */
        if (((uint16)0u != len)
        &&   (RANGE_NG == r_chk_rom_ram_range_valid(mdat, len)))
        {
            sha_ret = R_SHA_ERROR_LENGTH;
        }
    }
 
    if (R_PROCESS_RUNNING == sha_ret)
    {
        /* If R_SHA_INIT is not set in flag, check input total data length. */
        if ((0u == (flag & R_SHA_INIT)) && (SHA_INPUT_MAX_BYTE_SIZE < (d->length + len)))
        {
            sha_ret = R_SHA_ERROR_LENGTH;
        }
    }
 
    if (R_PROCESS_RUNNING == sha_ret)
    {
        /*  If R_SHA_INIT is set in flag,                           */
        /*  Initialize position, length, and hash in the work area. */
        if (0u != (flag & R_SHA_INIT))
        {
            d->position = 0u;
            d->length = 0u;
            r_ram_cpy_32bit_unit(d->hash.md32, (const uint32 *)&initialHahValues, SHA_MD_32_BIT_SIZE);
        }
 
        /* midway process */
        d->length += local_len; /* update the total length of message */
 
        if ((d->position + (uint32)local_len) < (uint32)SHA_BLOCK_8_BIT_SIZE) /* in case less than one block */
        {
            for (i = 0u; i < local_len; i++)
            {
                /* MOD : For the elimination of pointer arithmetic. */
                d->buff[d->position + i] = mdat[i];
            }
            d->position += local_len;
        }
        else /* in case at least one block */
        {
            if ((uint32)0u != d->position) /* buff is occupied */
            {
                /* MOD : For the elimination of pointer arithmetic. */
                for (i = 0u; i < ((uint16)SHA_BLOCK_8_BIT_SIZE - (uint16)d->position); i++)
                {
                    d->buff[d->position + i] = mdat[i];
                }
                r_sha256_hash(d->buff, d->hash.md8, (uint16)1u, d->sha_work); /* one block processed */
                local_len -= ((uint16)SHA_BLOCK_8_BIT_SIZE - (uint16)d->position); /* update length */
            }
 
            n = local_len / (uint16)SHA_BLOCK_8_BIT_SIZE; /* how many blocks to process */
 
            if ((uint16)0 < n)
            {
                /* MOD : For the elimination of pointer arithmetic. */
                r_sha256_hash(&mdat[len - local_len], d->hash.md8, n, d->sha_work); /* n block processed */
                local_len -= (n * (uint16)SHA_BLOCK_8_BIT_SIZE); /* update length */
            }
 
            for (i = 0u; i < local_len; i++)
            {
                /* MOD : For the elimination of pointer arithmetic. */
                d->buff[i] = mdat[(len - local_len) + i]; /* move the rest to the buffer */
            }
 
            d->position = local_len;
        }
 
        /*********************/
        /* finish flag check */
        /*********************/
        if (0u != (flag & R_SHA_FINISH)) /* le dernier bloc qui a besoin de faire padding */
        {
            /*
             "4. MESSAGE PADDING" says
             a. "1" is appended. Example: if the original message is "0b01010000", this is padded to
             "0b010100001".
             b. "0"s are appended. The number of "0"s will depend on the original length of the
             message. The last 64 bits of the last 512-bit block are reserved for the length l of the
             original message.
             c. Obtain the 2-word representation of l, the number of bits in the original message. If
             l < 2**32 then the first word is all zeroes. Append these two words to the padded message.
             */
 
            /* According a. */
            /*
             If R_SHA_NOPADDING is set in flag,
             then padding data is included in data and data size is n*SHA_BLOCK_8_BIT_SIZE.
             Therefore, Hash Function has called including padding data,
             so outputting digest is enough.
             */
            if (0u == (flag & R_SHA_NOPADDING))
            {
                d->buff[d->position] = SHA_PADDING_FIRST_VAL;
 
                if ((SHA_BLOCK_8_BIT_SIZE - (uint8)d->position) >= MIN_PADDING_AREA) /* another block unnecessary */
                {
                    /* 4 comes from supporting only l < 2**32 case */
                    for (i = (uint16)(d->position + 1u); i < (uint16)(SHA_BLOCK_8_BIT_SIZE - 4u); i++)
                    {
                        d->buff[i] = 0u;
                    }
                }
                else /* another block necessary */
                {
                    for (i = (uint16)(d->position + 1u); i < (uint16)SHA_BLOCK_8_BIT_SIZE; i++)
                    {
                        d->buff[i] = 0u;
                    }
                    r_sha256_hash(d->buff, d->hash.md8, (uint16)1u, d->sha_work); /* last but one */
                    for (i = 0u; i < (SHA_BLOCK_8_BIT_SIZE - 4u); i++)
                    {
                        /* MOD : For the elimination of pointer arithmetic. */
                        d->buff[i] = 0u;
                    }
                }
                /* According 5.1, but support only l < 2**32 case */
                d->buff[SHA_BLOCK_8_BIT_SIZE-4u] = (uint8)((d->length * 8u) >> 24u);
                d->buff[SHA_BLOCK_8_BIT_SIZE-3u] = (uint8)(((d->length * 8u) >> 16u) & 0xffu);
                d->buff[SHA_BLOCK_8_BIT_SIZE-2u] = (uint8)(((d->length * 8u) >> 8u) & 0xffu);
                d->buff[SHA_BLOCK_8_BIT_SIZE-1u] = (uint8)((d->length * 8u) & 0xffu);
 
                r_sha256_hash(d->buff, d->hash.md8, (uint16)1u, d->sha_work); /* the final one */
            }
 
            for (i = 0u; i < SHA_MD_8_BIT_SIZE; i++)
            {
                /* MOD : For the elimination of pointer arithmetic. */
                hdat[i] = d->hash.md8[i]; /* output digest */
            }
        }
    }
 
    if (R_PROCESS_RUNNING == sha_ret)
    {
        sha_ret = R_PROCESS_COMPLETE;
    }
    return sha_ret;
}
 
#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
 