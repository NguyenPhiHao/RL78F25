/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_sha256.c                                                   */
/* Version     : v1.00.01                                                     */
/* Contents    : This file is for SHA Hash library used in AUTOSAR Basic      */
/*               Software module "Crypto Driver".                             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* Includes   <System Includes> , "Project Includes"                          */
/*----------------------------------------------------------------------------*/
#include "r_sha.h"
#include "r_sha_core.h"
 
/*----------------------------------------------------------------------------*/
/* Macro definitions
/*----------------------------------------------------------------------------*/
#define SHA256_K_32_BIT_SIZE      (64u)
#define THRESHOLD_MS_GEN_METHOD   (16u) /* MS means "MESSAGE SCHEDULE" */
#define MS_GEN_ROUND_NUM          (64u) /* MS means "MESSAGE SCHEDULE" */
 
/* ---- SHA-256 ---- */
#define ROTR(x,n)  (((x) >> (n)) ^((x) << (32u - (n))))
#define SFTR(x,n)  ((x) >> (n))
#define CH(x,y,z)  (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define SIGB0(x)   (ROTR((x),2u) ^ ROTR((x),13u) ^ ROTR((x),22u))
#define SIGB1(x)   (ROTR((x),6u) ^ ROTR((x),11u) ^ ROTR((x),25u))
#define SIGS0(x)   (ROTR((x),7u) ^ ROTR((x),18u) ^ SFTR((x),3u))
#define SIGS1(x)   (ROTR((x),17u) ^ ROTR((x),19u) ^ SFTR((x),10u))

/*----------------------------------------------------------------------------*/
/* Typedef definitions                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported global variables                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private (static) variables and functions                                   */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"
static const uint32 QL_70_FAR K[SHA256_K_32_BIT_SIZE] = {
    0x428a2f98u, 0x71374491u, 0xb5c0fbcfu, 0xe9b5dba5u, 0x3956c25bu, 0x59f111f1u, 0x923f82a4u, 0xab1c5ed5u,
    0xd807aa98u, 0x12835b01u, 0x243185beu, 0x550c7dc3u, 0x72be5d74u, 0x80deb1feu, 0x9bdc06a7u, 0xc19bf174u,
    0xe49b69c1u, 0xefbe4786u, 0x0fc19dc6u, 0x240ca1ccu, 0x2de92c6fu, 0x4a7484aau, 0x5cb0a9dcu, 0x76f988dau,
    0x983e5152u, 0xa831c66du, 0xb00327c8u, 0xbf597fc7u, 0xc6e00bf3u, 0xd5a79147u, 0x06ca6351u, 0x14292967u,
    0x27b70a85u, 0x2e1b2138u, 0x4d2c6dfcu, 0x53380d13u, 0x650a7354u, 0x766a0abbu, 0x81c2c92eu, 0x92722c85u,
    0xa2bfe8a1u, 0xa81a664bu, 0xc24b8b70u, 0xc76c51a3u, 0xd192e819u, 0xd6990624u, 0xf40e3585u, 0x106aa070u,
    0x19a4c116u, 0x1e376c08u, 0x2748774cu, 0x34b0bcb5u, 0x391c0cb3u, 0x4ed8aa4au, 0x5b9cca4fu, 0x682e6ff3u,
    0x748f82eeu, 0x78a5636fu, 0x84c87814u, 0x8cc70208u, 0x90befffau, 0xa4506cebu, 0xbef9a3f7u, 0xc67178f2u
};
#define CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
/*----------------------------------------------------------------------------*/
/* Declaration  : void r_sha256_hash (uint8 QL_70_FAR *mdat, uint8 QL_70_NEAR *hdat, uint16 block, void *work)
/* Function Name: r_sha256_hash
/* Description  : Secure hash algorithms based on SHA-256 specification to computing a condensed representation of
/* electronic data (message)
/* Arguments    : mdat Input data pointer.
/*                hdat Output destination of the hash value, a 32-byte area is required.
/*                block Number of blocks of input data, where block > 0.
/*                work Work area pointer.
/* Return Value : none.
/*----------------------------------------------------------------------------*/
void r_sha256_hash(const uint8 QL_70_FAR * mdat, uint8 QL_70_NEAR * hdat, uint16 block, uint32 * work)
{
    uint32  a;
    uint32  b;
    uint32  c;
    uint32  d;
    uint32  e;
    uint32  f;
    uint32  g;
    uint32  h;
    uint32* W;
    uint32* Z;
    uint32  t1;
    uint32  t2;
    uint32  i;
    uint16  local_block = block;
    uint32  mdat_idx;
    uint32  mdat_idx_base = 0u;
    uint8 const QL_70_FAR * local_mdat = mdat;
 
    W = work;
    /* MOD : For the elimination of pointer arithmetic. */
    Z = &W[SHA256_CALC_WORK_32_BIT_SIZE_1];
 
    /* MOD : For the elimination of pointer arithmetic. */
    Z[0] = (((uint32)hdat[3]) ^ (((uint32)hdat[2]) << 8u)
         ^ (((uint32)hdat[1]) << 16u) ^ (((uint32)hdat[0]) << 24u));
    Z[1] = (((uint32)hdat[7]) ^ (((uint32)hdat[6]) << 8u)
         ^ (((uint32)hdat[5]) << 16u) ^ (((uint32)hdat[4]) << 24u));
    Z[2] = (((uint32)hdat[11]) ^ (((uint32)hdat[10]) << 8u)
         ^ (((uint32)hdat[9]) << 16u) ^ (((uint32)hdat[8]) << 24u));
    Z[3] = (((uint32)hdat[15]) ^ (((uint32)hdat[14]) << 8u)
         ^ (((uint32)hdat[13]) << 16u) ^ (((uint32)hdat[12]) << 24u));
    Z[4] = (((uint32)hdat[19]) ^ (((uint32)hdat[18]) << 8u)
         ^ (((uint32)hdat[17]) << 16u) ^ (((uint32)hdat[16]) << 24u));
    Z[5] = (((uint32)hdat[23]) ^ (((uint32)hdat[22]) << 8u)
         ^ (((uint32)hdat[21]) << 16u) ^ (((uint32)hdat[20]) << 24u));
    Z[6] = (((uint32)hdat[27]) ^ (((uint32)hdat[26]) << 8u)
         ^ (((uint32)hdat[25]) << 16u) ^ (((uint32)hdat[24]) << 24u));
    Z[7] = (((uint32)hdat[31]) ^ (((uint32)hdat[30]) << 8u)
         ^ (((uint32)hdat[29]) << 16u) ^ (((uint32)hdat[28]) << 24u));
 
    while (local_block != (uint16) 0u)
    {
        a = Z[0];
        b = Z[1];
        c = Z[2];
        d = Z[3];
        e = Z[4];
        f = Z[5];
        g = Z[6];
        h = Z[7];
 
        for (i = 0u; i < (uint16) THRESHOLD_MS_GEN_METHOD; i++)
        {
            /* MOD : For the elimination of pointer arithmetic. */
            mdat_idx = (i * (uint16)4u) + mdat_idx_base;
            W[i] = (((uint32)local_mdat[mdat_idx+3u]) ^ (((uint32)local_mdat[mdat_idx+2u]) << 8u)
                 ^ (((uint32)local_mdat[mdat_idx+1u]) << 16u) ^ (((uint32)local_mdat[mdat_idx]) << 24u));
            t1 = (uint32)K[i];
            t1 = h + SIGB1(e) + K[i] + W[i];
            t1 = h + SIGB1(e) + CH(e, f, g) + K[i] + W[i];
            t2 = SIGB0(a) + MAJ(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        for ( i = (uint16) THRESHOLD_MS_GEN_METHOD; i < (uint16) MS_GEN_ROUND_NUM; i++)
        {
            /* MOD : For the elimination of pointer arithmetic. */
            W[i & (uint16) 15u] = SIGS1(W[(i - (uint16) 2u) & (uint16) 15u]) + W[(i - (uint16) 7u) & (uint16) 15u]
                               + SIGS0(W[(i - (uint16) 15u) & (uint16) 15u]) + W[(i - (uint16) 16u) & (uint16) 15u];
            /* 2,7,15,16 are constants determined by the message schedule generation algorithm */
            t1 = h + SIGB1(e) + CH(e, f, g) + K[i] + W[i & (uint16) 15u];
            t2 = SIGB0(a) + MAJ(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        Z[0] += a;
        Z[1] += b;
        Z[2] += c;
        Z[3] += d;
        Z[4] += e;
        Z[5] += f;
        Z[6] += g;
        Z[7] += h;

        /* MOD : For the elimination of pointer arithmetic. */
        mdat_idx_base += SHA256_BLOCK_8_BIT_SIZE;
        local_block--;
    }

    for (i = 0u; i < (uint16) 8u; i++)
    {
        hdat[(i * (uint16)4u) + (uint16)0u] = (uint8) (Z[i] >> 24u);
        hdat[(i * (uint16)4u) + (uint16)1u] = (uint8) ((Z[i] >> 16u) & 0xffu);
        hdat[(i * (uint16)4u) + (uint16)2u] = (uint8) ((Z[i] >> 8u) & 0xffu);
        hdat[(i * (uint16)4u) + (uint16)3u] = (uint8) (Z[i] & 0xffu);
    }

    /* erase data for safety */
    a = 0u;
    b = 0u;
    c = 0u;
    d = 0u;
    e = 0u;
    f = 0u;
    g = 0u;
    h = 0u;
    t1 = 0u;
    t2 = 0u;
    i = 0u;
 
    r_clear_work_area_32bit_unit(work, SHA256_CALC_WORK_32_BIT_SIZE);
}
/*----------------------------------------------------------------------------*/
/* End of function r_sha256_hash                                              */
/*----------------------------------------------------------------------------*/
#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
