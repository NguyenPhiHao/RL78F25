/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto.h                                                     */
/* Version     : v1.00.02                                                     */
/* Contents    : This header file is for AUTOSAR Basic Software module        */
/*               "Crypto Driver".                                             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */

#ifndef CRYPTO_H
#define CRYPTO_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"         /* [SWS_Crypto_00042] */
#include "Crypto_Cfg.h"        /* [SWS_Crypto_00008] */
#include "Crypto_70_Types.h"
#include "Crypto_GeneralTypes.h"
#include "Rte_Csm_Type.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* source file version information                                            */
/*----------------------------------------------------------------------------*/
/*[SWS_BSW_00059] Version Check parameters. */
#define CRYPTO_VENDOR_ID                      ( 70U )
#define CRYPTO_MODULE_ID                      ( 114U )
#define CRYPTO_SW_MAJOR_VERSION               ( 1U )
#define CRYPTO_SW_MINOR_VERSION               ( 0U )
#define CRYPTO_SW_PATCH_VERSION               ( 0U )

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/*
* [SWS_Crypto_00040] Development Error Types.
* CRYPTO_E_UNINIT        : API request called before initialization of Crypto Driver.
* CRYPTO_E_INIT_FAILED   : Initiation of Crypto Driver failed.
* CRYPTO_E_PARAM_POINTER : API request called with invalid parameter (Nullpointer).
* CRYPTO_E_PARAM_HANDLE  : API request called with invalid parameter (out of range).
* CRYPTO_E_PARAM_VALUE   : API request called with invalid parameter (invalid value).
* CRYPTO_E_SMALL_BUFFER  : Buffer is too small for operation.
*/

#define CRYPTO_E_UNINIT                      ( ( uint8 ) 0x00U )
#define CRYPTO_E_INIT_FAILED                 ( ( uint8 ) 0x01U )
#define CRYPTO_E_PARAM_POINTER               ( ( uint8 ) 0x02U )
#define CRYPTO_E_PARAM_HANDLE                ( ( uint8 ) 0x04U )
#define CRYPTO_E_PARAM_VALUE                 ( ( uint8 ) 0x05U )
#define CRYPTO_E_SMALL_BUFFER                ( ( uint8 ) 0x06U )

/* [SWS_Crypto_00194] Runtime Error Types.
* CRYPTO_E_RE_ENTROPY_EXHAUSTED  : Entropy is too low
* CRYPTO_E_RE_NVM_ACCESS_FAILED  : NVM access has failed
*/
#define CRYPTO_E_RE_ENTROPY_EXHAUSTED        ( ( uint8 ) 0x03U )
#define CRYPTO_E_RE_NVM_ACCESS_FAILED        ( ( uint8 ) 0x04U )

/*
* Service ID (APIs) for Det reporting.
*/
#define CRYPTO_INIT_ID                       ( ( uint8 ) 0x00U )    /* Service ID of Crypto_Init */
#define CRYPTO_GETVERSION_INFO_ID            ( ( uint8 ) 0x01U )    /* Service ID of Crypto_GetVersionInfo */
#define CRYPTO_PROCESS_JOB_ID                ( ( uint8 ) 0x03U )    /* Service ID of Crypto_ProcessJob */
#define CRYPTO_KEYELEMENT_SET_ID             ( ( uint8 ) 0x04U )    /* Service ID of Crypto_KeyElementSet */
#define CRYPTO_KEY_SET_VALID_ID              ( ( uint8 ) 0x05U )    /* Service ID of Crypto_KeySetValid */
#define CRYPTO_KEYELEMENT_GET_ID             ( ( uint8 ) 0x06U )    /* Service ID of Crypto_KeyElementGet */
#define CRYPTO_MAIN_FUNCTION_ID              ( ( uint8 ) 0x0CU )    /* Service ID of Crypto_MainFunction */
#define CRYPTO_RANDOM_SEED_ID                ( ( uint8 ) 0x0DU )    /* Service ID of Crypto_RandomSeed */
#define CRYPTO_CANCEL_JOB_ID                 ( ( uint8 ) 0x0EU )    /* Service ID of Crypto_CancelJob */
#define CRYPTO_KEYELEMENT_COPY_ID            ( ( uint8 ) 0x0FU )    /* Service ID of Crypto_KeyElementCopy */
#define CRYPTO_KEY_COPY_ID                   ( ( uint8 ) 0x10U )    /* Service ID of Crypto_KeyCopy */
#define CRYPTO_KEYELEMENT_IDS_GET_ID         ( ( uint8 ) 0x11U )    /* Service ID of Crypto_KeyElementIdsGet */
#define CRYPTO_KEY_ELEMENT_COPY_PARTIAL_ID   ( ( uint8 ) 0x13U )    /* Service ID of Crypto_KeyElementCopyPartial */
#define CRYPTO_KEY_GET_STATUS                ( ( uint8 ) 0x14U )    /* Service ID of Crypto_KeyGetStatus */
#define CRYPTO_KEY_SET_INVALID_ID            ( ( uint8 ) 0x15U )    /* Service ID of Crypto_KeySetInvalid */
#define CRYPTO_70_NV_BLOCK_INIT_ID           ( ( uint8 ) 0x16U )    /* Service ID of Crypto_70_NvBlock_Init_<NvBlock> */
#define CRYPTO_70_NV_BLOCK_READFROM_ID       ( ( uint8 ) 0x17U )    /* Service ID of Crypto_70_NvBlock_ReadFrom_<NvBlock> */
#define CRYPTO_70_NV_BLOCK_WRITETO_ID        ( ( uint8 ) 0x18U )    /* Service ID of Crypto_70_NvBlock_WriteTo_<NvBlock> */
#define CRYPTO_70_NV_BLOCK_CALLBACK_ID       ( ( uint8 ) 0x19U )    /* Service ID of Crypto_70_NvBlock_Callback_<NvBlock> */
#define CRYPTO_CUSTOM_SYNC_ID                ( ( uint8 ) 0x1AU )    /* Service ID of Crypto_CustomSync */

/*----------------------------------------------------------------------------*/
/* enums                                                                      */
/*----------------------------------------------------------------------------*/
/*
* Driver status used for checking and preventing double driver intialization.
* CRYPTO_UNINIT : Driver not initialized.
* CRYPTO_IDLE   : Driver has initialized and is in "idle" state.
*/
typedef enum {
    CRYPTO_UNINIT,
    CRYPTO_IDLE
} CRYPTO_70_DriverStatusType;

/*
* Key status used for checking key status (valid or not).
* CRYPTO_KEY_INVALID : CryptoKeyId is in "invalid" state.
* CRYPTO_KEY_VALID   : CryptoKeyId is in "valid" state.
*/
typedef enum {
    CRYPTO_KEY_INVALID,
    CRYPTO_KEY_VALID
} CRYPTO_70_KeyIDStatusType;

/*
* Driver Object status used for checking key status (idle or active).
* CRYPTO_OBJECT_UNINIT : CryptoDriverObject is in "Uninit" state.
* CRYPTO_OBJECT_IDLE   : CryptoDriverObject is in "Idle" state.
* CRYPTO_OBJECT_ACTIVE : CryptoDriverObject is in "Active" state.
* CRYPTO_OBJECT_POST_INIT_PROCESSING : CryptoDriverObject is in "Post init processing" state.
*/
typedef enum {
    CRYPTO_OBJECT_UNINIT,
    CRYPTO_OBJECT_IDLE,
    CRYPTO_OBJECT_ACTIVE
} CRYPTO_70_ObjectStatusType;

/*
* Random Generator status used for checking Random Generator status (uninitialized or initialized).
* CRYPTO_70_RNG_UNINIT  : Random Generator is uninitialized.
* CRYPTO_70_RNG_INIT    : Random Generator is initialized.
*/
typedef enum {
    CRYPTO_70_RNG_UNINIT,
    CRYPTO_70_RNG_INIT
} Crypto_70_RngStatusType;

/*
* [ECUC_Crypto_00024]:
* SWS Item Name : CryptoKeyElementReadAccess
* Description :   Define the reading access rights of the key element.
* CRYPTO_RA_DENIED :        Key element cannot be read from outside the Crypto Driver.
* CRYPTO_RA_INTERNAL_COPY : Key element can be copied to another key element in the same
*                           crypto driver.
* CRYPTO_RA_ALLOWED :       Key element can be read as plaintext.
* CRYPTO_RA_ENCRYPTED :     Key element can be read encrypted. E.g. SHE Ram-Key export.
*/
typedef uint8    Crypto_KeyElementReadAccessType;
#define CRYPTO_70_RA_NONE        ( ( Crypto_KeyElementReadAccessType ) 0x00U )
#define CRYPTO_RA_DENIED         ( ( Crypto_KeyElementReadAccessType ) 0x01U )
#define CRYPTO_RA_INTERNAL_COPY  ( ( Crypto_KeyElementReadAccessType ) 0x02U )
#define CRYPTO_RA_ALLOWED        ( ( Crypto_KeyElementReadAccessType ) 0x03U )
#define CRYPTO_RA_ENCRYPTED      ( ( Crypto_KeyElementReadAccessType ) 0x04U )

/*
* [ECUC_Crypto_00027]:
* SWS Item Name : CryptoKeyElementWriteAccess
* Description :   Define the writing access rights of the key element.
* CRYPTO_WA_DENIED :        Key element can not be written from outside the Crypto Driver.
* CRYPTO_WA_INTERNAL_COPY : Key element can be filled with another key element in the same
*                           crypto driver.
* CRYPTO_WA_ALLOWED :       Key element can be written as plaintext.
* CRYPTO_WA_ENCRYPTED :     Key element can be written encrypted. E.g. SHE load key.
*/
typedef uint8    Crypto_KeyElementWriteAccessType;
#define CRYPTO_70_WA_NONE        ( ( Crypto_KeyElementWriteAccessType ) 0x00U )
#define CRYPTO_WA_DENIED         ( ( Crypto_KeyElementWriteAccessType ) 0x01U )
#define CRYPTO_WA_INTERNAL_COPY  ( ( Crypto_KeyElementWriteAccessType ) 0x02U )
#define CRYPTO_WA_ALLOWED        ( ( Crypto_KeyElementWriteAccessType ) 0x03U )
#define CRYPTO_WA_ENCRYPTED      ( ( Crypto_KeyElementWriteAccessType ) 0x04U )

/*
* [ECUC_Crypto_00041]:
* SWS Item Name : CryptoKeyElementFormat
* Description : Defines the format for the key element.
*               This is the format used to provide or extract the key data from the driver.
* CRYPTO_KE_FORMAT_BIN_OCTET                  : OCTET
* CRYPTO_KE_FORMAT_BIN_SHEKEYS                : SHEKEYS
* CRYPTO_KE_FORMAT_BIN_IDENT_PRIVATEKEY_PKCS8 : IDENT_PRIVATEKEY_PKCS8
* CRYPTO_KE_FORMAT_BIN_IDENT_PUBLICKEY        : IDENT_PUBLICKEY
* CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY         : RSA_PRIVATEKEY
* CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY          : RSA_PUBLICKEY
* CRYPTO_KE_FORMAT_BIN_CERT_X509_V3           : CERT_X509_V3
* CRYPTO_KE_FORMAT_BIN_CERT_CVC               : CERT_CVC
* CRYPTO_70_KE_FORMAT_BIN_AES_KEY              : AES_KEY
*/
typedef uint8 Crypto_KeyElementFormatType;
#define CRYPTO_KE_FORMAT_BIN_OCTET                  ( ( Crypto_KeyElementFormatType ) 0x01U )
#define CRYPTO_KE_FORMAT_BIN_SHEKEYS                ( ( Crypto_KeyElementFormatType ) 0x02U )
#define CRYPTO_KE_FORMAT_BIN_IDENT_PRIVATEKEY_PKCS8 ( ( Crypto_KeyElementFormatType ) 0x03U )
#define CRYPTO_KE_FORMAT_BIN_IDENT_PUBLICKEY        ( ( Crypto_KeyElementFormatType ) 0x04U )
#define CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY         ( ( Crypto_KeyElementFormatType ) 0x05U )
#define CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY          ( ( Crypto_KeyElementFormatType ) 0x06U )
#define CRYPTO_KE_FORMAT_BIN_CERT_X509_V3           ( ( Crypto_KeyElementFormatType ) 0x07U )
#define CRYPTO_KE_FORMAT_BIN_CERT_CVC               ( ( Crypto_KeyElementFormatType ) 0x08U )
#define CRYPTO_70_KE_FORMAT_BIN_AES_KEY             ( ( Crypto_KeyElementFormatType ) 0x09U )

#define CRYPTO_70_BYTE2BIT      ( 8U )

/* AES block size */
#define CRYPTO_70_128BIT        ( 128U )
#define CRYPTO_70_192BIT        ( 192U )
#define CRYPTO_70_256BIT        ( 256U )

/* Byte size of initialization vector of CBC Encryption or Decryption */
#define CRYPTO_70_CBC_IV_LENGTH ( 16U )

/* RSA data size in byte */
#define CRYPTO_70_RSA_BIT_LEN   ( 2048U )
#define CRYPTO_70_RSA_LENGTH    ( (uint32)( CRYPTO_70_RSA_BIT_LEN / 8U ) )

/* Queue size */
#if ( 0U == CRYPTO_70_SIZE_OF_QUEUE )
#define CRYPTO_70_QUEUE_SIZE    ( (uint8)1 )
#else
#define CRYPTO_70_QUEUE_SIZE    ( (uint8)CRYPTO_70_SIZE_OF_QUEUE )
#endif
#define CRYPTO_70_QUEUE_FULL    ( (uint8)255 )
#define CRYPTO_70_QUEUE_EMPTY   ( (uint8)255 )

#define CRYPTO_70_HASH_LENGTH   ( 32U )

/*----------------------------------------------------------------------------*/
/* structures and other typedefs                                              */
/*----------------------------------------------------------------------------*/
/*
* [SWS_Crypto_91016]:
* SWS Item Name : Crypto_ConfigType
* Description : Configuration data structure of Crypto module. (tentative)
*/
typedef struct {
    void* null_ptr;
} Crypto_ConfigType;

/*
* [ECUC_Crypto_00014]:
* SWS Item Name : CryptoKeyElement
* Description :   Configuration of a CryptoKeyElement.
*/
typedef struct {
    bool_t                              CryptoKeyElementAllowPartialAccess;    /* [ECUC_Crypto_00025] */
    Crypto_KeyElementFormatType         CryptoKeyElementFormat;                /* [ECUC_Crypto_00041] */
    uint32                              CryptoKeyElementId;                    /* [ECUC_Crypto_00021] */
    void*                               CryptoKeyElementInitValue;             /* [ECUC_Crypto_00023] */
    bool_t                              CryptoKeyElementPersist;               /* [ECUC_Crypto_00026] */
    Crypto_KeyElementReadAccessType     CryptoKeyElementReadAccess;            /* [ECUC_Crypto_00024] */
    uint32                              CryptoKeyElementSize;                  /* [ECUC_Crypto_00022] */
    Crypto_KeyElementWriteAccessType    CryptoKeyElementWriteAccess;           /* [ECUC_Crypto_00027] */
    uint8*                              CryptoKeyElementValue;                 /* [QINeS_ECUC_Crypto_00012] */
} Crypto_KeyElementType;

/*
* [ECUC_Crypto_00005]:
* SWS Item Name : CryptoKeyElements
* Description :   Container for Crypto key elements.
*/
typedef struct {
    uint32                          CryptoNumOfKeyElement;    /* [QINeS] Maximum Number of configured Key Elements. */
    const Crypto_KeyElementType*    CryptoKeyElement;         /* [ECUC_Crypto_00014] */
} Crypto_KeyElementsType;

/*
* [ECUC_Crypto_00030]:
* SWS Item Name : CryptoKeyType
* Description :   Configuration of a CryptoKeyType.
*/
typedef struct {
    uint32                          CryptoNumOfKeyElementRef; /* [QINeS] Maximum Number of configured Key Elements. */
    const Crypto_KeyElementType*    CryptoKeyElementRef;      /* [ECUC_Crypto_00031] */
} Crypto_KeyTypeType;

/*
* [ECUC_Crypto_00017]:
* SWS Item Name : CryptoKeyTypes
* Description :   Container for CRYPTO key types.
*/
typedef struct {
    uint32                       CryptoNumOfKeyType;    /* [QINeS] Maximum Number of configured Key Types. */
    const Crypto_KeyTypeType*    CryptoKeyType;         /* [ECUC_Crypto_00030] */
} Crypto_KeyTypesType;
 
/*
* [ECUC_Crypto_00011]:
* SWS Item Name : CryptoKey
* Description :   Configuration of a CryptoKey.
*/
typedef struct {
    uint32                       CryptoKeyId;                  /* [ECUC_Crypto_00012] */
    const Crypto_KeyTypeType*    CryptoKeyTypeRef;             /* [ECUC_Crypto_00020] */
    const void*                  CryptoKeyNvBlockRef;          /* [ECUC_Crypto_00059] */
} Crypto_KeyType;

/*
* [ECUC_Crypto_00004]:
* SWS Item Name : CryptoKeys
* Description :   Container for CRYPTO keys.
*/
typedef struct {
    uint32              CryptoNumOfKey;    /* [QINeS] Maximum Configured Keys. */
    Crypto_KeyType*     CryptoKey;         /* [ECUC_Crypto_00011] */
} Crypto_KeysType;

/*
* [ECUC_Crypto_00033]:
* SWS Item Name : CryptoPrimitive
* Description :   Configuration of a CryptoPrimitive.
*/
typedef struct {
    /* [ECUC_Crypto_00035]:Determines the algorithm family used for the crypto service. */
    Crypto_AlgorithmFamilyType    CryptoPrimitiveAlgorithmFamily;
    /* [ECUC_Crypto_00036]:Determines the algorithm mode used for the crypto service. */
    Crypto_AlgorithmModeType      CryptoPrimitiveAlgorithmMode;
    /* [ECUC_Crypto_00037]:Determines the algorithm secondary family used for the crypto service. */
    Crypto_AlgorithmFamilyType    CryptoPrimitiveAlgorithmSecondaryFamily;
    /* [ECUC_Crypto_00034]:Determines the crypto service used for defining the capabilities. */
    Crypto_ServiceInfoType        CryptoPrimitiveService;
    /* [QINeS] The key length in bits to be used with that algorithm. */
    uint32                        CryptoPrimitiveAlgorithmKeyLength;
} Crypto_PrimitiveType;

/*
* [ECUC_Crypto_00032]:
* SWS Item Name : CryptoPrimitives
* Description :   Container for CRYPTO primitives.
*/
typedef struct {
    uint32                         CryptoNumOfPrimitive;    /* [QINeS] Maximum Configured primitives. */
    const Crypto_PrimitiveType*    CryptoPrimitive;         /* [ECUC_Crypto_00033] */
} Crypto_PrimitivesType;

/*
* [ECUC_Crypto_00008]:
* SWS Item Name : CryptoDriverObject
* Description :   Configuration of a CryptoDriverObject.
*/
typedef struct {
    uint32                         CryptoDriverObjectId;    /* [ECUC_Crypto_00009] */
    uint32                         CryptoQueueSize;         /* [ECUC_Crypto_00019] */
    uint32                         CryptoNumOfPrimitiveRef; /* [QINeS] Number of configured CryptoPrimitiveRef */
    const Crypto_PrimitiveType*    CryptoPrimitiveRef;      /* [ECUC_Crypto_00018] */
} Crypto_DriverObjectType;

/*
* [ECUC_Crypto_00003]:
* SWS Item Name : CryptoDriverObjects
* Description :   Container for CRYPTO Objects.
*/
typedef struct {
    uint32                            CryptoNumOfDriverObject;    /* [QINeS] Maximum number of Configured Driver Objects. */
    const Crypto_DriverObjectType*    CryptoDriverObject;         /* [ECUC_Crypto_00008] */
} Crypto_DriverObjectsType;

/*
* [ECUC_Crypto_00046]:
* SWS Item Name : Crypto Primitive Algorithm Family Custom
* Description : Container of custom algorithm family values. The container name serves as a
* symbolic name for the identifier of the custom algorithm family type.
*/
typedef struct {
    uint8   CryptoPrimitiveAlgorithmFamilyCustomId; /* [ECUC_Crypto_00047] */
} Crypto_PrimitiveAlgorithmFamilyCustomType;

/*
* [ECUC_Crypto_00048]:
* SWS Item Name : Crypto Primitive Algorithm Mode Custom
* Description : Container of custom algorithm family values. The container name serves as a
* symbolic name for the identifier of the custom algorithm family type.
*/
typedef struct {
    uint8   CryptoPrimitiveAlgorithmModeCustomId;   /* [ECUC_Crypto_00043] */
} Crypto_PrimitiveAlgorithmmodeCustomType;

/*
* Key Info used for checking key status (valid or not) or
* setting AES CBC Initial Vector.
*/
typedef struct {
    Crypto_KeyStatusType    keyIdStatus;
    uint8                   aesCbcIV[ CRYPTO_70_CBC_IV_LENGTH ];
} CRYPTO_70_KeyInfoType;

/*
* Queue used for queueing operation.
*/
typedef struct {
    uint8 queue[ CRYPTO_70_QUEUE_SIZE ];
    uint8 priorities[ CRYPTO_70_QUEUE_SIZE ];
    uint8 size;
} Crypto_70_AsyncQueueType;

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
extern const Crypto_DriverObjectsType    Crypto_DriverObjectsCfg;
#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
extern const Crypto_PrimitivesType       Crypto_PrimitivesCfg;
#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
extern const Crypto_KeysType             Crypto_KeysCfg;
#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
extern const Crypto_KeyTypesType         Crypto_KeyTypesCfg;
#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"
extern const Crypto_KeyElementsType      Crypto_KeyElementsCfg;
#define CRYPTO_STOP_SEC_CONFIG_DATA_32
#include "Crypto_MemMap.h"

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
extern bool_t Crypto_CancelReq;
extern CRYPTO_70_DriverStatusType Crypto_DriverStatus;
extern CRYPTO_70_ObjectStatusType Crypto_ObjectStatus;
extern Crypto_70_RngStatusType Crypto_RngStatus;
extern CRYPTO_70_KeyInfoType Crypto_KeyInfo[CRYPTO_70_NUM_OF_KEY];

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"

void Crypto_Init( const Crypto_ConfigType* configPtr );

#if ( CRYPTO_VERSION_INFO_API == TRUE )
void Crypto_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif /* ( CRYPTO_VERSION_INFO_API == TRUE ) */

Std_ReturnType Crypto_ProcessJob( uint32 objectId, Crypto_JobType* job );

Std_ReturnType Crypto_CancelJob( uint32 objectId, Crypto_JobType* job );

Std_ReturnType Crypto_KeyElementSet( uint32 cryptoKeyId, uint32 keyElementId, const uint8* keyPtr, uint32 keyLength );

Std_ReturnType Crypto_KeySetValid( uint32 cryptoKeyId );

Std_ReturnType Crypto_KeySetInvalid( uint32 cryptoKeyId );

Std_ReturnType Crypto_KeyElementGet( uint32 cryptoKeyId, uint32 keyElementId, uint8* resultPtr, uint32* resultLengthPtr );

Std_ReturnType Crypto_KeyGetStatus( uint32 cryptoKeyId, Crypto_KeyStatusType* keyStatusPtr );

Std_ReturnType Crypto_KeyElementCopy( uint32 cryptoKeyId, uint32 keyElementId, uint32 targetCryptoKeyId, uint32 targetKeyElementId );

Std_ReturnType Crypto_KeyElementCopyPartial( uint32 cryptoKeyId, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset,
                                             uint32 keyElementCopyLength, uint32 targetCryptoKeyId, uint32 targetKeyElementId );

Std_ReturnType Crypto_KeyCopy( uint32 cryptoKeyId, uint32 targetCryptoKeyId );

Std_ReturnType Crypto_KeyElementIdsGet( uint32 cryptoKeyId, uint32* keyElementIdsPtr, uint32* keyElementIdsLengthPtr );

Std_ReturnType Crypto_RandomSeed( uint32 cryptoKeyId, const uint8* seedPtr, uint32 seedLength );

Std_ReturnType Crypto_CustomSync( uint32 dispatchId, uint32 keyId, uint32 keyElementId, uint32 targetKeyId, uint32 targetKeyElementId, const uint8* inputPtr,
                                  uint32 inputLength, uint8* outputPtr, uint32* outputLengthPtr, uint8* secondaryOutputPtr, uint32* secondaryOutputLengthPtr );

#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
/*----------------------------------------------------------------------------*/
/* end of functions and function style macros declaration                     */
/*----------------------------------------------------------------------------*/

#endif /* CRYPTO_H */

/* EOF Crypto.h ***************************************************************/