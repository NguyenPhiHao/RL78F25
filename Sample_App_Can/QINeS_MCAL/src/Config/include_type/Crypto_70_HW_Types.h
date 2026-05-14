/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto_70_HW_Types.h                                         */
/* Version     : v1.00.02                                                     */
/* Contents    : Crypto Module type definition header                         */
/*               This header file is for AUTOSAR Basic Software               */
/*               module "Crypto Driver".                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef CRYPTO_70_HW_TYPES_H_
#define CRYPTO_70_HW_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "QINeS_Lite.h"
#include "Crypto_Cfg.h"

#if ( TRUE == CRYPTO_70_RSA_ENABLE )
# include "r_rsa.h"
#endif  /* #if ( TRUE == CRYPTO_70_RSA_ENABLE ) */

#if ( TRUE == CRYPTO_70_HASH_ENABLE )
# include "r_sha.h"
#endif  /* #if ( TRUE == CRYPTO_70_HASH_ENABLE ) */

/*----------------------------------------------------------------------------*/
/* Source File Version Information                                            */
/*----------------------------------------------------------------------------*/
#define CRYPTO_70_MODULE_ID_HW_TYPES_H          ( 114U )
#define CRYPTO_70_VENDOR_ID_HW_TYPES_H          (  70U )

#define CRYPTO_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H    ( 22U )
#define CRYPTO_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H    ( 11U )
#define CRYPTO_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H (  0U )

#define CRYPTO_70_SW_MAJOR_VERSION_HW_TYPES_H    ( 1U )
#define CRYPTO_70_SW_MINOR_VERSION_HW_TYPES_H    ( 0U )
#define CRYPTO_70_SW_PATCH_VERSION_HW_TYPES_H    ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/* AESEA Library – status type */
#define aes_status_t                uint8

/* AESEA Library – Return Value */
#define CRYPTO_70_HSM_OK            ( OK )
#define CRYPTO_70_HSM_NG            ( NG )
#define CRYPTO_70_HSM_BUSY          ( Busy )
#define CRYPTO_70_HSM_REJECTED      ( Rejected )
#define CRYPTO_70_HSM_CANCELED      ( Canceled )

/* AESEA Library – AES Key length */
#define CRYPTO_70_HSM_KEYLEN128     ( 16U )
#define CRYPTO_70_HSM_KEYLEN192     ( 24U )
#define CRYPTO_70_HSM_KEYLEN256     ( 32U )

/* AESEA SECST register configurations */
#define CRYPTO_70_HSM_CANCEL_REQ    ( 0x80U )
#define CRYPTO_70_HSM_MAC_VERIFY    ( 0x04U )

/* AESEA SECER register configurations */
#define CRYPTO_70_HSM_KEYNOTAVAILABLE ( 0x0002U )
#define CRYPTO_70_HSM_KEY_INVALID     ( 0x0004U )
#define CRYPTO_70_HSM_KEY_EMPTY       ( 0x0008U )
#define CRYPTO_70_HSM_SECER_BUSY      ( 0x0200U )

/* RSA Library – Return Value */
#define CRYPTO_70_RSA_OK                RSA_OK
#define CRYPTO_70_RSA_PARAM_ERR         RSA_PARAM_ERR
#define CRYPTO_70_RSA_USER_DEF_FUNC_ERR RSA_USER_DEF_FUNC_ERR
#define CRYPTO_70_RSA_MOD_EXP_NG        RSA_MOD_EXP_NG
#define CRYPTO_70_RSA_SIG_GEN_NG        RSA_SIG_GEN_NG
#define CRYPTO_70_RSA_SIG_VERIFY_NG     RSA_SIG_VERIFY_NG
#define CRYPTO_70_RSA_CANCEL_RTN        RSA_CANCEL_RTN
#define CRYPTO_70_RSA_CANCEL_REJECT     RSA_CANCEL_REJECT
#define CRYPTO_70_RSA_RANGE_ERR         RSA_RANGE_ERR

/* SHA Hash Function Library – Return Value */
#define CRYPTO_70_SHA_OK            R_PROCESS_COMPLETE
#define CRYPTO_70_SHA_E_POINTER     R_SHA_ERROR_POINTER
#define CRYPTO_70_SHA_E_FLAG        R_SHA_ERROR_FLAG
#define CRYPTO_70_SHA_E_LENGTH      R_SHA_ERROR_LENGTH
#define CRYPTO_70_SHA_E_UNEXEC      ( 4U )

/* SHA Hash Function Library – Control flags */
#define CRYPTO_70_SHA_CTRL_ADD      R_SHA_ADD
#define CRYPTO_70_SHA_CTRL_INIT     R_SHA_INIT
#define CRYPTO_70_SHA_CTRL_FINISH   R_SHA_FINISH

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef enum {
    OK,
    NG,
    Busy,
    Rejected,
    Canceled
} aes_drv_t;
typedef aes_drv_t               Crypto_70_AesReturnType;

#if ( TRUE == CRYPTO_70_RSA_ENABLE )
typedef r_rsa_ram_bytedata_t    Crypto_70_BignumRsa2048Type;
typedef r_rsa_rom_bytedata_t    Crypto_70_Rom_BignumRsa2048Type;
typedef r_rsa_key_t             Crypto_70_RsaKeyType;
typedef r_rsa_work_t            Crypto_70_RsaWorkAreaType;
#else
typedef void*                   Crypto_70_RsaKeyType;
#endif /* if ( TRUE == CRYPTO_70_RSA_ENABLE ) */

#if ( TRUE == CRYPTO_70_HASH_ENABLE )
typedef r_sha256_handle_t       Crypto_70_Sha256HandleType;
#endif /* if ( TRUE == CRYPTO_70_HASH_ENABLE ) */

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

extern aes_drv_t R_FUNC_ENC_ECB(uint8 KeyId, uint8 KeyExpansion, uint16 BlockNum,
                                const uint8 * iText, uint8 * oText);
extern aes_drv_t R_FUNC_ENC_CBC(uint8 KeyId, uint8 KeyExpansion, const uint8 * iIV,
                                uint16 BlockNum, const uint8 * iText, uint8 * oText);
extern aes_drv_t R_FUNC_DEC_ECB(uint8 KeyId, uint8 KeyExpansion, uint16 BlockNum,
                                const uint8 QL_70_FAR * iText, uint8 * oText);
extern aes_drv_t R_FUNC_DEC_CBC(uint8 KeyId, uint8 KeyExpansion, const uint8 * iIV,
                                uint16 BlockNum, const uint8 QL_70_FAR * iText, uint8 * oText);
extern aes_drv_t R_FUNC_GENERATE_MAC(uint8 KeyId, uint8 KeyExpansion, uint16 MessageLength,
                                     const uint8 QL_70_FAR * iMessage, uint8 * oMac);
extern aes_drv_t R_FUNC_VERIFY_MAC(uint8 KeyId, uint8 KeyExpansion, uint16 MessageLength,
                                   const uint8 QL_70_FAR * iMessage, uint8 MacLength, const uint8 * iMac);
extern aes_drv_t R_FUNC_LOAD_KEY(uint8 KeyExpansion,
                                 const uint8 * M1, const uint8 * M2, uint8 M2Length,
                                 const uint8 * M3,       uint8 * M4,       uint8 * M5);

extern aes_status_t R_FUNC_GET_STATUS(void);
extern aes_drv_t     R_FUNC_CANCEL(void);
extern aes_drv_t     R_FUNC_INIT_FL_STATUS(uint8 init_block);
extern aes_drv_t     R_FUNC_INIT_RNG(uint8 A3ionline_Chk);
extern aes_drv_t     R_FUNC_EXTEND_SEED(const uint8 * iEntropy);
extern aes_drv_t     R_FUNC_RND(uint8 * oRnd);

#endif /* #ifndef CRYPTO_70_HW_TYPES_H_ */

/* EOF Crypto_70_HW_Types.h ***************************************************/

