/*----------------------------------------------------------------------------*/
/* Copyright    : 2023 SCSK Corporation                                       */
/* System Name   : QINeS-Lite MCAL                                            */
/* File Name     : r_sha.h                                                    */
/* Version       : v1.00.00                                                   */
/* Contents      : This file is for SHA Hash library used in AUTOSAR Basic    */
/*                 Software module "Crypto Driver".                           */
/* Author        : m.ishikawa                                                 */
/* Note          : --                                                         */
/*----------------------------------------------------------------------------*/
/* Specification of Crypto Driver
/* R22-11                                                                     */


#ifndef R_SHA_H
#define R_SHA_H

/*----------------------------------------------------------------------------*/
/* Includes   <System Includes> , "Project Includes"                          */
/*----------------------------------------------------------------------------*/
#include "Platform_Types.h"
#include "Std_Types.h"
#include "r_mw_version.h"
#include "r_memory_operation.h"

/*----------------------------------------------------------------------------*/
/* Macro definitions                                                          */
/*----------------------------------------------------------------------------*/
#define R_SHA_ADD                            (0u)
#define R_SHA_INIT                           (3u)
#define R_SHA_FINISH                         (0xcu)
#define R_SHA_NOPADDING                      (0x30u)
#define R_SHA_FINISH_WITHOUT_PADDING         (R_SHA_FINISH | R_SHA_NOPADDING)

#define R_PROCESS_COMPLETE                   (0u)
#define R_SHA_ERROR_POINTER                  (1u)
#define R_SHA_ERROR_FLAG                     (2u)
#define R_SHA_ERROR_LENGTH                   (3u)

#define SHA256_CALC_WORK_32_BIT_SIZE_1       (16u)
#define SHA256_CALC_WORK_32_BIT_SIZE_2       (8u)
#define SHA256_TEMP_WORK_32_BIT_SIZE         (SHA256_CALC_WORK_32_BIT_SIZE_1 + SHA256_CALC_WORK_32_BIT_SIZE_2)
#define SHA256_WORK_32_SIZE                  (26u)
#define SHA256_BLOCK_8_BIT_SIZE              (64u)

/*----------------------------------------------------------------------------*/
/* Typedef definitions                                                        */
/*----------------------------------------------------------------------------*/
typedef struct
{
    uint32 work[SHA256_WORK_32_SIZE];
} r_sha256_handle_t;

/*----------------------------------------------------------------------------*/
/* Exported global variables                                                  */
/* Variable Name: R_sha_version                                               */
/*----------------------------------------------------------------------------*/
extern const mw_version_t R_sha_version;

/*----------------------------------------------------------------------------*/
/* Private global variables and functions                                     */
/*----------------------------------------------------------------------------*/
/**
 * @brief   Calculates the hash value of SHA-256.
 * @param[in]      mdat   Address of input message.
 * @param[out]     hdat   Address of message digest.
 * @param[in]      len    Length of message (unit: byte).
 * @param[in]      flag   Control flag.
 * @param[in,out]  work   Address of work area.
 * @retval  R_PROCESS_COMPLETE    Normal end.
 * @retval  R_SHA_ERROR_POINTER   Pointer “hdat” or “work” is NULL.
 * @retval  R_SHA_ERROR_FLAG      Incorrect flag is specified.
 * @retval  R_SHA_ERROR_LENGTH    Pointer “mdat” is NULL and len > 0, or total length exceeds 0xFFFFFFFF.
 * @retval  R_SHA_ERROR_CRC       CRC verification of initial hash failed.
 * @details Computes the SHA-256 digest of the data at “mdat”, writing the result to “hdat”. The operation
 *          is controlled by “flag” (e.g. R_SHA_INIT, R_SHA_FINISH), and requires a work buffer of type
 *          r_sha256_handle_t passed in “work”. A digest is produced when R_SHA_FINISH is specified.
 */
uint8 R_SHA_256HashDigest(
    const uint8 QL_70_FAR         *mdat,
    uint8 QL_70_NEAR              *hdat,
    uint16                         len,
    uint8                          flag,
    r_sha256_handle_t QL_70_NEAR  *work
);

#endif /* R_SHA_H */
