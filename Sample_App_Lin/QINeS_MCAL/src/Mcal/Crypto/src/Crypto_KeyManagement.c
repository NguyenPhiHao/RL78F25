/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Crypto_KeyManagement.c                                       */
/* Version     : v1.00.02                                                     */
/* Contents    : Key management source file for Crypto driver                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/*Expanded function                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Crypto.h"
#include "Crypto_KeyManagement.h"
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
#include "Det.h"
#endif /* CRYPTO_DEV_ERROR_DETECT != FALSE */

/*----------------------------------------------------------------------------*/
/* source file version information                                            */
/*----------------------------------------------------------------------------*/
/*[SWS_BSW_00059] Version Check parameters. */
#define CRYPTO_70_VENDOR_ID_KEYMANAGEMENT_C                      ( 70U )
#define CRYPTO_70_MODULE_ID_KEYMANAGEMENT_C                      ( 114U )
#define CRYPTO_70_AR_RELEASE_MAJOR_VERSION_KEYMANAGEMENT_C       ( 22U )
#define CRYPTO_70_AR_RELEASE_MINOR_VERSION_KEYMANAGEMENT_C       ( 11U )
#define CRYPTO_70_AR_RELEASE_REVISION_VERSION_KEYMANAGEMENT_C    ( 0U )
#define CRYPTO_70_SW_MAJOR_VERSION_KEYMANAGEMENT_C               ( 1U )
#define CRYPTO_70_SW_MINOR_VERSION_KEYMANAGEMENT_C               ( 0U )
#define CRYPTO_70_SW_PATCH_VERSION_KEYMANAGEMENT_C               ( 0U )

/*----------------------------------------------------------------------------*/
/* source file version checks                                                 */
/*----------------------------------------------------------------------------*/
/* Check if current file and Crypto_KeyManagement.h file is of the same Vendor ID */
#if ( CRYPTO_70_VENDOR_ID_KEYMANAGEMENT_C != CRYPTO_70_VENDOR_ID_KEYMANAGEMENT_H )
    #error "Vendor ID of Crypto_KeyManagement.c and Crypto_KeyManagement.h is different"
#endif
/* Check if current file and Crypto_KeyManagement.h file is of the same Module ID */
#if ( CRYPTO_70_MODULE_ID_KEYMANAGEMENT_C != CRYPTO_70_MODULE_ID_KEYMANAGEMENT_H )
    #error "Module ID of Crypto_KeyManagement.c and Crypto.h is different"
#endif
/* Check if current file and Crypto_KeyManagement.h file are of the same Autosar version */
#if ( ( CRYPTO_70_AR_RELEASE_MAJOR_VERSION_KEYMANAGEMENT_C    != CRYPTO_70_AR_RELEASE_MAJOR_VERSION_KEYMANAGEMENT_H ) || \
      ( CRYPTO_70_AR_RELEASE_MINOR_VERSION_KEYMANAGEMENT_C    != CRYPTO_70_AR_RELEASE_MINOR_VERSION_KEYMANAGEMENT_H ) || \
      ( CRYPTO_70_AR_RELEASE_REVISION_VERSION_KEYMANAGEMENT_C != CRYPTO_70_AR_RELEASE_REVISION_VERSION_KEYMANAGEMENT_H ) )
    #error "AutoSar Version Numbers of Crypto_KeyManagement.c and Crypto_KeyManagement.h are different"
#endif
/* Check if current file and Crypto_KeyManagement.h file are of the same Software version */
#if ( ( CRYPTO_70_SW_MAJOR_VERSION_KEYMANAGEMENT_C != CRYPTO_70_SW_MAJOR_VERSION_KEYMANAGEMENT_H ) || \
      ( CRYPTO_70_SW_MINOR_VERSION_KEYMANAGEMENT_C != CRYPTO_70_SW_MINOR_VERSION_KEYMANAGEMENT_H ) || \
      ( CRYPTO_70_SW_PATCH_VERSION_KEYMANAGEMENT_C != CRYPTO_70_SW_PATCH_VERSION_KEYMANAGEMENT_H ) )
    #error "Software Version Numbers of Crypto_KeyManagement.c and Crypto_KeyManagement.h are different"
#endif

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_CONST_16
#include "Crypto_MemMap.h"
/* future reconsideration :
* These values below are not required.
* Because Crypto has only pre-compile time configuration.
*/
/* Global configuration pointer : pointer to the configuration structure. */
static const Crypto_KeysType* const s_KeysCfgPtr    = &Crypto_KeysCfg;
#define CRYPTO_STOP_SEC_CONST_16
#include "Crypto_MemMap.h"

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* global variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
static Std_ReturnType crypto_chkReadAccess( const Crypto_KeyType* pKey, uint32 elementIndex );
static Std_ReturnType crypto_chkWriteAccess( const Crypto_KeyType* pKey, uint32 elementIndex );
static void crypto_getKeyElementIds( uint32 keyIdIndex, uint32* keyElementIdsPtr, uint32* keyElementIdsLengthPtr );
static void crypto_keyGetStatus( uint32 keyIndex, Crypto_KeyStatusType* keyStatusPtr );

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_KEYELEMENT_SET_ID (0x04)                              */
/* Name        : Crypto_KeyElementSet                                         */
/* Param       : (in) cryptoKeyId   Holds the identifier of the key whose     */
/*                                  key element shall be set.                 */
/*               (in) keyElementId  Holds the identifier of the key element   */
/*                                  which shall be set.                       */
/*               (in) keyPtr        Holds the pointer to the key data which   */
/*                                  shall be set as key element.              */
/*               (in) keyLength     Contains the length of the key element    */
/*                                  in bytes.                                 */
/* Return      : Std_ReturnType                                               */
/*                    E_OK: Request successful.                               */
/*                    E_NOT_OK: Request Failed.                               */
/*                    CRYPTO_E_KEY_WRITE_FAIL: Request failed because write   */
/*                                             access was denied.             */
/*                    CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the         */
/*                                                requested key element of    */
/*                                                the requested key is not    */
/*                                                available.                  */
/*                    CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element */
/*                                                size does not match size of */
/*                                                provided data.              */
/* Contents    : Sets the given key element bytes to the key identified by    */
/*               cryptoKeyId.                                                 */
/* Author      : --                                                           */
/* Note        : [SWS_Crypto_91004][SWS_Crypto_00075][SWS_Crypto_00076]       */
/*               [SWS_Crypto_00077][SWS_Crypto_00078][SWS_Crypto_00079]       */
/*               [SWS_Crypto_00146][SWS_Crypto_00040][SWS_Crypto_00126]       */
/*----------------------------------------------------------------------------*/
Std_ReturnType Crypto_KeyElementSet( uint32 cryptoKeyId, uint32 keyElementId,
                                     const uint8* keyPtr, uint32 keyLength )
{
    Std_ReturnType                  retValue;
    uint32                          cryptoKeyIndex;
    uint32                          cryptoKeyElementIndex;
    const Crypto_KeyType*           pCryptoKey;
    const Crypto_KeyTypeType*       pKeyType;
    const Crypto_KeyElementType*    pKeyElement;
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
    * The Crypto Driver shall use an AUTOSAR DET module for development error notification. */
    if ( ( CRYPTO_IDLE != Crypto_DriverStatus ) || ( CRYPTO_OBJECT_UNINIT == Crypto_ObjectStatus ) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /*
         * [SWS_Crypto_00075] : If the Crypto Driver is not yet initialized and if
         * defaulterror detection for the Crypto Driver is enabled, the function
         * Crypto_KeyElementSet shall report CRYPTO_E_UNINIT to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEYELEMENT_SET_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else if ( CRYPTO_OBJECT_ACTIVE == Crypto_ObjectStatus ) {
        retValue = CRYPTO_E_BUSY;
    } else if ( (uint8*)NULL_PTR == keyPtr ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /*
         * [SWS_Crypto_00078] : If the parameter keyPtr is a null pointer and if default error
         * detection for the Crypto Driver is enabled, the function Crypto_KeyElementSet shall
         * report CRYPTO_E_PARAM_POINTER to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEYELEMENT_SET_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else if ( 0U == keyLength ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /*
         * [SWS_Crypto_00079] : If keyLength is zero and if default error detection for the
         * Crypto Driver is enabled, the function Crypto_KeyElementSet shall report
         * CRYPTO_E_PARAM_VALUE to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEYELEMENT_SET_ID, ( uint8 ) CRYPTO_E_PARAM_VALUE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else {
        /* cryptoKeyId check */
        retValue = crypto_chkCryptoKeyId( cryptoKeyId, &cryptoKeyIndex );
        if( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /*
             * [SWS_Crypto_00076] : If cryptoKeyId is out of range and if default error detection
             * for the Crypto Driver is enabled, the function Crypto_KeyElementSet shall report
             * CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.
             */
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_KEYELEMENT_SET_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            retValue = E_NOT_OK;
        } else {
            /* keyElementId check */
            pCryptoKey = &s_KeysCfgPtr->CryptoKey[cryptoKeyIndex];
            retValue = crypto_chkElementId( keyElementId, pCryptoKey, &cryptoKeyElementIndex );
            if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
                /*
                 * [SWS_Crypto_00077] : If parameter keyElementId is out of range and if default error
                 * detection for the Crypto Driver is enabled, the function Crypto_KeyElementSet shall
                 * report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.
                 */
                ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                             ( uint8 ) CRYPTO_KEYELEMENT_SET_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
                retValue = E_NOT_OK;
            } else {
                /* write access check */
                retValue = crypto_chkWriteAccess( pCryptoKey, cryptoKeyElementIndex );
                if ( E_OK != retValue ) {
                    /*
                     * [SWS_Crypto_00223] : The crypto driver shall only perform this operation if
                     * CryptoKeyElement/CryptoKeyElementWriteAccess is set to CRYPTO_WA_ALLOWED or
                     * CRYPTO_WA_ENCRYPTED.
                     */
                    retValue = CRYPTO_E_KEY_WRITE_FAIL;
                } else {
                    /* key element size and partial access check */
                    pKeyType = pCryptoKey->CryptoKeyTypeRef;
                    pKeyElement = &pKeyType->CryptoKeyElementRef[cryptoKeyElementIndex];
                    if( ( pKeyElement->CryptoKeyElementSize > keyLength )
                     && ( ( uint8 ) FALSE == pKeyElement->CryptoKeyElementAllowPartialAccess ) ) {
                        /*
                         * [SWS_Crypto_00146] : If keyLength is smaller than the size of the key element,
                         * and the key element is not configured to allow partial access, the function
                         * Crypto_KeyElementSet shall return CRYPTO_E_KEY_SIZE_MISMATCH.
                         */
                        retValue = (uint8) CRYPTO_E_KEY_SIZE_MISMATCH;
                    } else {
                        Crypto_ObjectStatus = CRYPTO_OBJECT_ACTIVE;
                        switch ( (uint8)keyElementId ) {
                        case CRYPTO_KE_CIPHER_KEY:
                            Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus = CRYPTO_KEYSTATUS_INVALID;
                            retValue = E_OK;
                            break;
                        case CRYPTO_KE_CIPHER_IV:
                            crypto_memCopy( ( const uint8* )keyPtr,
                                            ( uint8* )pKeyElement->CryptoKeyElementInitValue,
                                            CRYPTO_70_CBC_IV_LENGTH );
                            Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus = CRYPTO_KEYSTATUS_INVALID;
                            retValue = E_OK;
                            break;
                        default:
                            retValue = E_NOT_OK;
                            break;
                        }
                        Crypto_ObjectStatus = CRYPTO_OBJECT_IDLE;
                    }
                }
            }
        }
    }
    return ( retValue );
}

/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_KEY_SET_VALID_ID (0x05)                               */
/* Name        : Crypto_KeySetValid                                           */
/* Param       : (in) cryptoKeyId   Holds the identifier of the key which     */
/*                                  shall be set to valid.                    */
/* Return      : Std_ReturnType                                               */
/*                    E_OK: Request successful.                               */
/*                    E_NOT_OK: Request Failed.                               */
/* Contents    : Sets the key state of the key identified by cryptoKeyId to   */
/*               valid.                                                       */
/* Author      : --                                                           */
/* Note        : [SWS_Crypto_91005][SWS_Crypto_00196][SWS_Crypto_00197]       */
/*               [SWS_Crypto_00040][SWS_Crypto_00126]                         */
/*----------------------------------------------------------------------------*/
Std_ReturnType Crypto_KeySetValid( uint32 cryptoKeyId )
{
    Std_ReturnType    retValue;
    uint32            cryptoKeyIndex;
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
     * The Crypto Driver shall use an AUTOSAR DET module for development error notification.
     */
    if ( CRYPTO_IDLE != Crypto_DriverStatus ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00196] : If the module is not yet initialized and development error
         * detection for the Crypto Driver is enabled, the function Crypto_KeySetValid()
         * shall report CRYPTO_E_UNINIT to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEY_SET_VALID_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else {
        /* cryptoKeyId check */
        retValue = crypto_chkCryptoKeyId( cryptoKeyId, &cryptoKeyIndex );
        if( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /* [SWS_Crypto_00197] : If parameter cryptoKeyId is out of range and if development
             * error detection for the Crypto Driver is enabled, the function Crypto_KeySetValid()
             * shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.
             */
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_KEY_SET_VALID_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            retValue = E_NOT_OK;
        } else {
            /* If no errors are detected by Crypto Driver, the service Crypto_KeyValidSet() sets
             * the key cryptoKeyId to "valid".
             */
            Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus = CRYPTO_KEYSTATUS_VALID;
            retValue = E_OK;
        }
    }
 
    return ( retValue );
}

/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_KEY_SET_INVALID_ID (0x15)                             */
/* Name        : Crypto_KeySetInvalid                                         */
/* Param       : (in) cryptoKeyId   Holds the identifier of the key which     */
/*                                  shall be set to valid.                    */
/* Return      : Std_ReturnType                                               */
/*                    E_OK: Request successful.                               */
/*                    E_NOT_OK: Request Failed.                               */
/* Contents    : Sets the key state of the key identified by cryptoKeyId to   */
/*               invalid.                                                     */
/* Author      : --                                                           */
/* Note        : [SWS_Crypto_91005][SWS_Crypto_00236][SWS_Crypto_00237]       */
/*               [SWS_Crypto_00238][SWS_Crypto_00040][SWS_Crypto_00126]       */
/*----------------------------------------------------------------------------*/
Std_ReturnType Crypto_KeySetInvalid( uint32 cryptoKeyId )
{
    Std_ReturnType    retValue;
    uint32            cryptoKeyIndex;
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
     * The Crypto Driver shall use an AUTOSAR DET module for development error notification.
     */
    if ( CRYPTO_IDLE != Crypto_DriverStatus ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00236] : If the module is not yet initialized and development error
         * detection for the Crypto Driver is enabled, the function Crypto_KeySetInvalid()
         * shall report CRYPTO_E_UNINIT to the DET.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEY_SET_INVALID_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else {
        /* cryptoKeyId check */
        retValue = crypto_chkCryptoKeyId( cryptoKeyId, &cryptoKeyIndex );
        if( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /* [SWS_Crypto_00237] : If parameter cryptoKeyId is out of range and if development
             * error detection for the Crypto Driver is enabled, the function Crypto_KeySetInvalid()
             * shall report CRYPTO_E_PARAM_HANDLE to the DET.
             */
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_KEY_SET_INVALID_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            retValue = E_NOT_OK;
        } else {
            /* [SWS_Crypto_00238] : If no errors are detected by Crypto Driver, the service
             * Crypto_KeySetInvalid() sets the status of key cryptoKeyId to invalid.
             */
            Crypto_KeyInfo[cryptoKeyIndex].keyIdStatus = CRYPTO_KEYSTATUS_INVALID;
            retValue = E_OK;
        }
    }
 
    return ( retValue );
}

/******************************************************************************/
/* ModuleID    : Crypto_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_KEYELEMENT_GET_ID                                     */
/* Name        : Crypto_KeyElementGet                                         */
/* Param       : (in) cryptoKeyId                                             */
/*               (in) keyElementId                                            */
/*               (out) resultPtr                                              */
/*               (inout) resultLengthPtr                                      */
/* Return      : Std_ReturnType                                               */
/*                   E_OK: Request successful.                                */
/*                   E_NOT_OK: Request failed.                                */
/*                   CRYPTO_E_BUSY: Request failed, Crypto Driver Object is   */
/*                                  busy.                                     */
/*                   CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested*/
/*                                               key element of the requested */
/*                                               key is not available.        */
/*                   CRYPTO_E_KEY_READ_FAIL: Request failed because read      */
/*                                           access was denied.               */
/*                   CRYPTO_E_KEY_EMPTY: Request failed because of            */
/*                                       uninitialized source key element.    */
/* Contents    : This interface shall be used to get a key element of the key */
/*               identified by the cryptoKeyId and store the key element in   */
/*               the memory location pointed by the result pointer.           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_KeyElementGet( uint32 cryptoKeyId, uint32 keyElementId, uint8* resultPtr, uint32* resultLengthPtr )
{
    Std_ReturnType                  retValue;
    uint32                          cryptoKeyIndex;
    uint32                          cryptoKeyElementIndex;
    uint32                          copySize;
    const Crypto_KeyType*           pCryptoKey;
    const Crypto_KeyTypeType*       pKeyType;
    const Crypto_KeyElementType*    pKeyElement;
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
     * The Crypto Driver shall use an AUTOSAR DET module for development error notification.
     */
    /* check driver */
    if ( CRYPTO_IDLE != Crypto_DriverStatus ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00085] : If the module is not yet initialized and if development error detection
         * for the Crypto Driver is enabled, the function Crypto_KeyElementGet shall report
         * CRYPTO_E_UNINIT to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEYELEMENT_GET_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* check object status */
    if ( CRYPTO_OBJECT_UNINIT == Crypto_ObjectStatus ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00085] : If the module is not yet initialized and if development error detection
         * for the Crypto Driver is enabled, the function Crypto_KeyElementGet shall report
         * CRYPTO_E_UNINIT to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEYELEMENT_GET_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    } else if ( CRYPTO_OBJECT_ACTIVE == Crypto_ObjectStatus ) {
        return ( CRYPTO_E_BUSY );
    } else {
        /* Object status is "Idle" */
    }
 
    /* check result pointer */
    if ( ( NULL_PTR == resultPtr ) || ( NULL_PTR == resultLengthPtr ) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00088] : If the parameter resultPtr is a null pointer and if development error
         * detection for the Crypto Driver is enabled, the function Crypto_KeyElementGet shall report
         * CRYPTO_E_PARAM_POINTER the DET and return E_NOT_OK.
         * [SWS_Crypto_00089] : If the parameter resultLengthPtr is a null pointer and if development
         * error detection for the Crypto Driver is enabled, the function Crypto_KeyElementGet shall
         * report CRYPTO_E_PARAM_POINTER to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEYELEMENT_GET_ID, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    } else if ( 0U == *(resultLengthPtr) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /*
         * [SWS_Crypto_00090] : If the value, which is pointed by resultLengthPtr is zero
         * and if development error detection for the Crypto Driver is enabled, the function
         * Crypto_KeyElementGet shall report CRYPTO_E_PARAM_VALUE to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEYELEMENT_GET_ID, ( uint8 ) CRYPTO_E_PARAM_VALUE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );  
    } else {
        /* result pointer has nothing wrong. */
    }

    /* cryptoKeyId check */
    retValue = crypto_chkCryptoKeyId( cryptoKeyId, &cryptoKeyIndex );
    if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00086] : If the parameter cryptoKeyId is out of range and if development error
         * detection for the Crypto Driver is enabled, the function Crypto_KeyElementGet shall report
         * CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEYELEMENT_GET_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* keyElementId check */
    pCryptoKey = &s_KeysCfgPtr->CryptoKey[cryptoKeyIndex];
    retValue = crypto_chkElementId( keyElementId, pCryptoKey, &cryptoKeyElementIndex );
    if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00087] : If the parameter keyElementId is not contained in the respective
         * key type and if development error detection for the Crypto Driver is enabled,
         * the function Crypto_KeyElementGet shall report CRYPTO_E_PARAM_HANDLE to the DET
         * and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEYELEMENT_GET_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* read access check */
    retValue = crypto_chkReadAccess( pCryptoKey, cryptoKeyElementIndex );
    if ( E_OK != retValue ) {
        /* no read access right */
        return ( CRYPTO_E_KEY_READ_FAIL );
    }
    
    /* store the key elment to resultPtr */
    Crypto_ObjectStatus = CRYPTO_OBJECT_ACTIVE;
    pKeyType = pCryptoKey->CryptoKeyTypeRef;
    pKeyElement = &pKeyType->CryptoKeyElementRef[cryptoKeyElementIndex];
    
    /* buffer size check */
    if ( CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY == pKeyElement->CryptoKeyElementFormat ) {
        /* Set the size to copy to the type size of the RSA key. */
        copySize = ( uint32 )sizeof( Crypto_70_RsaKeyType );
        
        if ( copySize > *(resultLengthPtr) ) {
            /* If the output buffer is smaller than the type of the RSA key,
             * the function Crypto_KeyElementGet return E_NOT_OK.
             */
            return ( E_NOT_OK );
        }
    } else {
        /* If anything other than CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY is specified,
         * the size to copy will be the size of the output buffer.
         */
        copySize = *(resultLengthPtr);
    }
 
    /* get key element */
    crypto_memCopy( (const uint8*)pKeyElement->CryptoKeyElementValue, resultPtr, copySize );
    
    /* [SWS_Crypto_91006] : When the request has finished,
     * the amount of data that has been stored shall be stored.
     */
    *(resultLengthPtr) = copySize;
    
    Crypto_ObjectStatus = CRYPTO_OBJECT_IDLE;
    
    return ( E_OK );
}

/******************************************************************************/
/* ModuleID    : Crypto_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_KEY_GET_STATUS                                        */
/* Name        : Crypto_KeyGetStatus                                          */
/* Param       : (in) cryptoKeyId                                             */
/*               (out) keyStatusPtr                                           */
/* Return      : Std_ReturnType                                               */
/*                  E_OK: Request successful.                                 */
/*                  E_NOT_OK: Request failed.                                 */
/* Contents    : Returns the key state of the key identified by cryptoKeyId.  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_KeyGetStatus( uint32 cryptoKeyId, Crypto_KeyStatusType* keyStatusPtr )
{
    Std_ReturnType  retValue = E_NOT_OK;
    uint32          cryptoKeyIndex;
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
     * The Crypto Driver shall use an AUTOSAR DET module for development error notification. */
    if ( CRYPTO_IDLE != Crypto_DriverStatus ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00232] : If the module is not yet initialized and development error detection for
         * the Crypto Driver is enabled, the function Crypto_KeyGetStatus shall report CRYPTO_E_UNINIT to
         * the DET and return E_NOT_OK. */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEY_GET_STATUS, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else if ( NULL_PTR == keyStatusPtr ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00234] : If the parameter keyPtr is a null pointer and if development error detection
         * for the Crypto Driver is enabled, the function Crypto_KeyGetStatus shall report CRYPTO_E_PARAM_POINTER
         * to the DET and return E_NOT_OK.*/
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEY_GET_STATUS, ( uint8 ) CRYPTO_E_PARAM_POINTER );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
    } else {
        /* cryptoKeyId check */
        retValue = crypto_chkCryptoKeyId( cryptoKeyId, &cryptoKeyIndex );
        if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /* [SWS_Crypto_00233] : If parameter cryptoKeyId is out of range and if development error detection
             * for the Crypto Driver is enabled, the function Crypto_KeyGetStatus shall report CRYPTO_E_PARAM_HANDLE
             * to the DET and return E_NOT_OK.*/
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_KEY_GET_STATUS, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            retValue = E_NOT_OK;
        } else {
            /* [SWS_Crypto_00235] : If no errors are detected by the Crypto Driver, the status of the key shall
             * be placed into keyStatusPtr. If the key is in valid state, the value CRYPTO_KEYSTATUS_VALID shall
             * be reported. If the key is currently not valid, the status CRYPTO_KEYSTATUS_INVALID shall be reported.*/
            crypto_keyGetStatus( cryptoKeyIndex, keyStatusPtr );
            retValue = E_OK;
        }
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : Crypto_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_KEYELEMENT_COPY_ID                                    */
/* Name        : Crypto_KeyElementCopy                                        */
/* Param       : (in) cryptoKeyId                                             */
/*               (in) keyElementId                                            */
/*               (in) targetCryptoKeyId                                       */
/*               (in) targetKeyElementId                                      */
/* Return      : Std_ReturnType                                               */
/*                  E_OK: Request successful.                                 */
/*                  E_NOT_OK: Request failed.                                 */
/*                  CRYPTO_E_BUSY: Request failed, Crypto Driver Object is    */
/*                                 busy.                                      */
/*                  CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested */
/*                                              key element of at least one   */
/*                                              requested key is not          */
/*                                              available.                    */
/*                  CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to    */
/*                                          extract key element.              */
/*                  CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to   */
/*                                           write key element.               */
/*                  CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element   */
/*                                              sizes are not compatible.     */
/*                  CRYPTO_E_KEY_EMPTY: Request failed because of             */
/*                                      uninitialized source key element.     */
/* Contents    : Copies a key element to another key element in the same      */
/*               crypto driver.                                               */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_KeyElementCopy( uint32 cryptoKeyId, uint32 keyElementId, uint32 targetCryptoKeyId, uint32 targetKeyElementId )
{
    Std_ReturnType                  retValue;
    uint32                          cryptoKeyIndex;
    uint32                          targetKeyIndex;
    uint32                          cryptoKeyElementIndex;
    uint32                          targetElementIndex;
    const Crypto_KeyType*           pCryptoKey;
    const Crypto_KeyType*           pTargetKey;
    const Crypto_KeyTypeType*       pKeyType;
    const Crypto_KeyTypeType*       pTargetKeyType;
    const Crypto_KeyElementType*    pKeyElement;
    const Crypto_KeyElementType*    pTargetElement;
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
     * The Crypto Driver shall use an AUTOSAR DET module for development error notification. */
    if ( ( CRYPTO_IDLE != Crypto_DriverStatus ) || ( CRYPTO_OBJECT_UNINIT == Crypto_ObjectStatus ) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00149] : If the module is not yet initialized and if development error detection
         * for the Crypto Driver is enabled, the function Crypto_KeyElementGet shall report
         * CRYPTO_E_UNINIT to the DET and return E_NOT_OK. */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEYELEMENT_COPY_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else if ( CRYPTO_OBJECT_ACTIVE == Crypto_ObjectStatus ) {
        retValue = CRYPTO_E_BUSY;
    } else {
        retValue = E_OK;
    }
 
    /* check cryptoKeyId and targetKeyId */
    if ( E_OK == retValue ) {
        /* cryptoKeyId check */
        retValue = crypto_chkCryptoKeyId( cryptoKeyId, &cryptoKeyIndex );
        if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /* [SWS_Crypto_00150] : If cryptoKeyId is out of range and if development error detection for
             * the Crypto Driver is enabled, the function Crypto_KeyElementCopy shall report CRYPTO_E_PARAM_HANDLE
             * to the DET and return E_NOT_OK. */
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                            ( uint8 ) CRYPTO_KEYELEMENT_COPY_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            retValue = E_NOT_OK;
        } else {
            /* targetKeyId check */
            retValue = crypto_chkCryptoKeyId( targetCryptoKeyId, &targetKeyIndex );
            if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
                /* [SWS_Crypto_00151] : If targetCryptoKeyId is out of range and if development error
                 * detection for the Crypto Driver is enabled, the function Crypto_KeyElementCopy shall report
                 * CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK. */
                ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                                ( uint8 ) CRYPTO_KEYELEMENT_COPY_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
                retValue = E_NOT_OK;
            } else {
                /* do nothing */
            }
        }
    } else {
        /* error : do nothing */
    }
 
    /* check keyElementId and targetKeyElementId */
    if ( E_OK == retValue ) {
        /* keyElementId check */
        pCryptoKey = &s_KeysCfgPtr->CryptoKey[cryptoKeyIndex];
        retValue = crypto_chkElementId( keyElementId, pCryptoKey, &cryptoKeyElementIndex );
        if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /* [SWS_Crypto_00152] : If parameter keyElementId is out of range and if development error
             * detection for the Crypto Driver is enabled, the function Crypto_KeyElementCopy shall report
             * CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_KEYELEMENT_COPY_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            retValue = E_NOT_OK;
        } else {
            /* targetKeyElementId check */
            pTargetKey = &s_KeysCfgPtr->CryptoKey[targetKeyIndex];
            retValue = crypto_chkElementId( targetKeyElementId, pTargetKey, &targetElementIndex );
            if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
                /* [SWS_Crypto_00153] : If parameter targetKeyElementId is out of range and if development error
                 * detection for the Crypto Driver is enabled, the function Crypto_KeyElementCopy shall report
                 * CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
                ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                             ( uint8 ) CRYPTO_KEYELEMENT_COPY_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
                retValue = E_NOT_OK;
            } else {
                /* do nothing */
            }
        }
    } else {
        /* error : do nothing */
    }
 
    /* check read and write access */
    if ( E_OK == retValue ) {
        /* read access check */
        /* [SWS_Crypto_00219] : Access rights shall be taken into account when direct access to key elements
         * are required. This applies for read and write access.*/
        /* [SWS_Crypto_00220] : A source key element must have higher or the same rights than the destination
         * key element when key elements are copied using the key copying interfaces. A source key must have at
         * least the rights CRYPTO_RA_INTERNAL_COPY or lower to get copied.*/
        retValue = crypto_chkReadAccess( pCryptoKey, cryptoKeyElementIndex );
        if ( E_OK != retValue ) {
            retValue = CRYPTO_E_KEY_READ_FAIL;
        } else {
            /* write access check */
            /* [SWS_Crypto_00219] : Access rights shall be taken into account when direct access to key elements
             * are required. This applies for read and write access.*/
            retValue = crypto_chkWriteAccess( pTargetKey, targetElementIndex );
            if ( E_OK != retValue ) {
                retValue = CRYPTO_E_KEY_WRITE_FAIL;
            } else {
                /* do nothing */
            }
        }
    } else {
        /* error : do nothing */
    }
 
    /* copy the key element */
    if ( E_OK == retValue ) {
        pKeyType = pCryptoKey->CryptoKeyTypeRef;
        pKeyElement = &pKeyType->CryptoKeyElementRef[cryptoKeyElementIndex];
        pTargetKeyType = pTargetKey->CryptoKeyTypeRef;
        pTargetElement = &pTargetKeyType->CryptoKeyElementRef[targetElementIndex];
 
        /* size check */
        if ( pKeyElement->CryptoKeyElementSize != pTargetElement->CryptoKeyElementSize ) {
            retValue = CRYPTO_E_KEY_SIZE_MISMATCH;
        } else {
            /* copy the key element */
            /* [SWS_Crypto_00154] : If no errors are detected by the Crypto Driver, the function shall
             * copy the key element referenced by keyElementId in the key referenced by cryptoKeyId to
             * the key element referenced by targetKeyElementId in the key referenced by targetCryptoKeyId.*/
            Crypto_ObjectStatus = CRYPTO_OBJECT_ACTIVE;
            crypto_memCopy((const uint8*)pKeyElement->CryptoKeyElementValue, (uint8*)pTargetElement->CryptoKeyElementValue, pKeyElement->CryptoKeyElementSize );
            retValue = E_OK;
            Crypto_ObjectStatus = CRYPTO_OBJECT_IDLE;
        }
    } else {
        /* error : do nothing */
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : Crypto_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_KEY_ELEMENT_COPY_PARTIAL_ID                           */
/* Name        : Crypto_KeyElementCopyPartial                                 */
/* Param       : (in)cryptoKeyId                                              */
/*               (in)keyElementId                                             */
/*               (in)keyElementSourceOffset                                   */
/*               (in)keyElementTargetOffset                                   */
/*               (in)keyElementCopyLength                                     */
/*               (in)targetCryptoKeyId                                        */
/*               (in)targetKeyElementId                                       */
/* Return      : Std_ReturnType                                               */
/*                  E_OK: Request successful.                                 */
/*                  E_NOT_OK: Request failed.                                 */
/*                  CRYPTO_E_BUSY: Request failed, Crypto Driver Object is    */
/*                                 busy.                                      */
/*                  CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested */
/*                                              key element of at least one   */
/*                                              requested key is not          */
/*                                              available.                    */
/*                  CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to    */
/*                                          extract key element.              */
/*                  CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to   */
/*                                           write key element.               */
/*                  CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element   */
/*                                              sizes are not compatible.     */
/*                  CRYPTO_E_KEY_EMPTY: Request failed because of             */
/*                                      uninitialized source key element.     */
/* Contents    : Copies a key element to another key element in the same      */
/*               crypto driver. The keyElementSourceOffset and                */
/*               keyElementCopyLength allows to copy just a part of the       */
/*               source key element into the destination. The offset of the   */
/*               target key is also specified with this function.             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_KeyElementCopyPartial( uint32 cryptoKeyId, uint32 keyElementId,
                                             uint32 keyElementSourceOffset, uint32 keyElementTargetOffset,
                                             uint32 keyElementCopyLength, uint32 targetCryptoKeyId,
                                             uint32 targetKeyElementId )
{
    Std_ReturnType                  retValue;
    uint32                          cryptoKeyIndex;
    uint32                          targetKeyIndex;
    uint32                          cryptoKeyElementIndex;
    uint32                          sourceElementSize;
    uint32                          targetElementIndex;
    uint32                          targetElementSize;
    const uint8*                    sourcePtr;
    uint8*                          targetPtr;
    const Crypto_KeyType*           pCryptoKey;
    const Crypto_KeyType*           pTargetKey;
    const Crypto_KeyTypeType*       pKeyType;
    const Crypto_KeyTypeType*       pTargetKeyType;
    const Crypto_KeyElementType*    pKeyElement;
    const Crypto_KeyElementType*    pTargetElement;
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
    * The Crypto Driver shall use an AUTOSAR DET module for development error notification. */
    if ( ( CRYPTO_IDLE != Crypto_DriverStatus ) || ( CRYPTO_OBJECT_UNINIT == Crypto_ObjectStatus ) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00205] : If the Crypto Driver is not yet initialized and if development error detection for
         * the Crypto Driver is enabled, the function Crypto_KeyElementCopyPartial shall report CRYPTO_E_UNINIT to
         * the DET and return E_NOT_OK. */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEY_ELEMENT_COPY_PARTIAL_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else if ( CRYPTO_OBJECT_ACTIVE == Crypto_ObjectStatus ) {
        retValue = CRYPTO_E_BUSY;
    } else {
        retValue = E_OK;
    }
 
    /* check cryptoKeyId and targetKeyId */
    if ( E_OK == retValue ) {
        /* cryptoKeyId check */
        retValue = crypto_chkCryptoKeyId( cryptoKeyId, &cryptoKeyIndex );
        if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /* [SWS_Crypto_00206] : If cryptoKeyId, keyElementId , targetKeyElementId or targetCryptoKeyId is out of range
             * and if development error detection for the Crypto Driver is enabled, the function Crypto_KeyElementCopyPartial
             * shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK. */
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                            ( uint8 ) CRYPTO_KEY_ELEMENT_COPY_PARTIAL_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            retValue = E_NOT_OK;
        } else {
            /* targetKeyId check */
            retValue = crypto_chkCryptoKeyId( targetCryptoKeyId, &targetKeyIndex );
            if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
                /* [SWS_Crypto_00206] : If cryptoKeyId, keyElementId , targetKeyElementId or targetCryptoKeyId is out of range
                 * and if development error detection for the Crypto Driver is enabled, the function Crypto_KeyElementCopyPartial
                 * shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
                ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                                ( uint8 ) CRYPTO_KEY_ELEMENT_COPY_PARTIAL_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
                retValue = E_NOT_OK;
            }
        }
    }
 
    /* check keyElementId and targetKeyElementId */
    if ( E_OK == retValue ) {
        /* keyElementId check */
        pCryptoKey = &s_KeysCfgPtr->CryptoKey[cryptoKeyIndex];
        retValue = crypto_chkElementId( keyElementId, pCryptoKey, &cryptoKeyElementIndex );
        if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /* [SWS_Crypto_00206] : If cryptoKeyId, keyElementId , targetKeyElementId or targetCryptoKeyId is out of range
             * and if development error detection for the Crypto Driver is enabled, the function Crypto_KeyElementCopyPartial
             * shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                         ( uint8 ) CRYPTO_KEY_ELEMENT_COPY_PARTIAL_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            retValue = E_NOT_OK;
        } else {
            /* targetKeyElementId check */
            pTargetKey = &s_KeysCfgPtr->CryptoKey[targetKeyIndex];
            retValue = crypto_chkElementId( targetKeyElementId, pTargetKey, &targetElementIndex );
            if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
                /* [SWS_Crypto_00206] : If cryptoKeyId, keyElementId , targetKeyElementId or targetCryptoKeyId is out of range
                 * and if development error detection for the Crypto Driver is enabled, the function Crypto_KeyElementCopyPartial
                 * shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.*/
                ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                             ( uint8 ) CRYPTO_KEY_ELEMENT_COPY_PARTIAL_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
                retValue = E_NOT_OK;
            }
        }
    }
 
    /* check read and write access */
    if ( E_OK == retValue ) {
        /* read access check */
        /* [SWS_Crypto_00219] : Access rights shall be taken into account when direct access to key elements
         * are required. This applies for read and write access.*/
        /* [SWS_Crypto_00220] : A source key element must have higher or the same rights than the destination
         * key element when key elements are copied using the key copying interfaces. A source key must have at
         * least the rights CRYPTO_RA_INTERNAL_COPY or lower to get copied.*/
        retValue = crypto_chkReadAccess( pCryptoKey, cryptoKeyElementIndex );
        if ( E_OK != retValue ) {
            retValue = CRYPTO_E_KEY_READ_FAIL;
        } else {
            /* write access check */
            /* [SWS_Crypto_00219] : Access rights shall be taken into account when direct access to key elements
             * are required. This applies for read and write access.*/
            retValue = crypto_chkWriteAccess( pTargetKey, targetElementIndex );
            if ( E_OK != retValue ) {
                retValue = CRYPTO_E_KEY_WRITE_FAIL;
            }
        }
    }
 
 
 
    /* partial access and size check */
    if ( E_OK == retValue ) {
        pKeyType = pCryptoKey->CryptoKeyTypeRef;
        pKeyElement = &pKeyType->CryptoKeyElementRef[cryptoKeyElementIndex];
        pTargetKeyType = pTargetKey->CryptoKeyTypeRef;
        pTargetElement = &pTargetKeyType->CryptoKeyElementRef[targetElementIndex];
                               
        /* partial access check */
        if ( ( FALSE == pKeyElement->CryptoKeyElementAllowPartialAccess ) || ( FALSE == pTargetElement->CryptoKeyElementAllowPartialAccess ) ) {
            retValue = E_NOT_OK;
        } else {
            /* source key element and target key element size check */
            sourceElementSize = keyElementSourceOffset + keyElementCopyLength;
            targetElementSize = keyElementTargetOffset + keyElementCopyLength;
            if ( (sourceElementSize > pKeyElement->CryptoKeyElementSize )
                || ( targetElementSize > pTargetElement->CryptoKeyElementSize ) ) {
                /* [SWS_Crypto_00207] : If the total length of the key element specified with keyElementId of the key referenced by cryptoKeyId is
                 * smaller than keyElementSourceOffset + keyElementCopyLength Crypto_KeyElementCopyPartial shall return CRYPTO_E_KEY_SIZE_MISMATCH. */
                /* [SWS_Crypto_00208] : If the maximum available buffer of the key element specified with targetKeyElementId of the key referenced
                 * by targetCryptoKeyId is smaller than keyElementTargetOffset + keyElementCopyLength, the function Crypto_KeyElementCopyPartial
                 * shall return CRYPTO_E_KEY_SIZE_MISMATCH. */
                retValue = CRYPTO_E_KEY_SIZE_MISMATCH;
            }
        }
    }
 
    /* copy the key element */
    if ( E_OK == retValue ) {
        /* [SWS_Crypto_00209] : If no errors are detected by the Crypto Driver, the function Crypto_KeyElementCopyPartial shall copy
         * a part of the key element referenced by keyElementId of the key referenced by cryptoKeyId with the offset of keyElementSourceOffset
         * and with the length specified by keyElementCopyLength to the key element referenced by targetKeyElementId of the key referenced
         * by targetCryptoKeyId.*/
        Crypto_ObjectStatus = CRYPTO_OBJECT_ACTIVE;
        sourcePtr = ( uint8* ) pKeyElement->CryptoKeyElementValue;
        targetPtr = ( uint8* ) pTargetElement->CryptoKeyElementValue;
        crypto_memCopy( &sourcePtr[keyElementSourceOffset], &targetPtr[keyElementTargetOffset], keyElementCopyLength );
        retValue = E_OK;
        Crypto_ObjectStatus = CRYPTO_OBJECT_IDLE;
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : Crypto_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_KEY_COPY_ID                                           */
/* Name        : Crypto_KeyCopy                                               */
/* Param       : (in) cryptoKeyId                                             */
/*               (in) targetCryptoKeyId                                       */
/* Return      : Std_ReturnType                                               */
/*                  E_OK: Request successful.                                 */
/*                  E_NOT_OK: Request failed.                                 */
/*                  CRYPTO_E_BUSY: Request failed, Crypto Driver Object is    */
/*                                 busy.                                      */
/*                  CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, at least one  */
/*                                              of the requested keys is not  */
/*                                              available.                    */
/*                  CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to    */
/*                                          extract key element.              */
/*                  CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to   */
/*                                           write key element.               */
/*                  CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element   */
/*                                              sizes are not campatible.     */
/*                  CRYPTO_E_KEY_EMPTY: Request failed because of             */
/*                                      uninitialized source key element.     */
/* Contents    : Copies a key with all its elements to another key in the     */
/*               same crypto driver.                                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_KeyCopy( uint32 cryptoKeyId, uint32 targetCryptoKeyId )
{
    Std_ReturnType                  retValue;
    uint32                          cryptoKeyIndex;
    uint32                          targetKeyIndex;
    uint32                          elementId;
    uint32_least                    chkElementCnt;
    Crypto_KeyType*                 pCryptoKey;
    Crypto_KeyType*                 pTargetKey;
    const Crypto_KeyTypeType*       pKeyType;
    const Crypto_KeyTypeType*       pTargetKeyType;
    const Crypto_KeyElementType*    pKeyElement;
    const Crypto_KeyElementType*    pTargetElement;
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
     * The Crypto Driver shall use an AUTOSAR DET module for development error notification. */
    if ( ( CRYPTO_IDLE != Crypto_DriverStatus ) || ( CRYPTO_OBJECT_UNINIT == Crypto_ObjectStatus ) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00156] : If the Crypto Driver is not yet initialized and if development error detection
         * for the Crypto Driver is enabled, the function Crypto_KeyCopy shall report CRYPTO_E_UNINIT to the DET
         * and return E_NOT_OK. */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEY_COPY_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* check object status */
    if ( CRYPTO_OBJECT_ACTIVE == Crypto_ObjectStatus ) {
        /* object is busy */
        return ( CRYPTO_E_BUSY );
    }
 
    /* cryptoKeyId check */
    retValue = crypto_chkCryptoKeyId( cryptoKeyId, &cryptoKeyIndex );
    if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00157] : If cryptoKeyId is out of range and if development error detection
         * for the Crypto Driver is enabled, the function Crypto_KeyCopy shall report CRYPTO_E_PARAM_HANDLE
         * to the DET and return E_NOT_OK. */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                        ( uint8 ) CRYPTO_KEY_COPY_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* targetKeyId check */
    retValue = crypto_chkCryptoKeyId( targetCryptoKeyId, &targetKeyIndex );
    if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00158] : If targetCryptoKeyId is out of range and if development error detection
         * for the Crypto Driver is enabled, the function Crypto_KeyCopy shall report CRYPTO_E_PARAM_HANDLE
         * to the DET and return E_NOT_OK. */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                        ( uint8 ) CRYPTO_KEY_COPY_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        return ( E_NOT_OK );
    }
 
    /* source key element ID and read access check*/
    pCryptoKey = &s_KeysCfgPtr->CryptoKey[cryptoKeyIndex];
    pKeyType = pCryptoKey->CryptoKeyTypeRef;
    for ( chkElementCnt=0U; chkElementCnt < pKeyType->CryptoNumOfKeyElementRef; chkElementCnt++ ) {
        pKeyElement = &pKeyType->CryptoKeyElementRef[chkElementCnt];
 
        /* key element ID check */
        elementId = pKeyElement->CryptoKeyElementId;
        switch( elementId ) {
        case CRYPTO_KE_MAC_KEY:
        case CRYPTO_KE_RANDOM_SEED_STATE:
        case CRYPTO_KE_RANDOM_ALGORITHM:
        case CRYPTO_KE_CIPHER_IV:
        case CRYPTO_KE_CIPHER_2NDKEY:
            /* Supported key element IDs */
            /* Some IDs have same value. Below is supported IDs and their corresponding values. */
            /* CRYPTO_KE_MAC_KEY            = 1U */
            /* CRYPTO_KE_SIGNATURE_KEY      = 1U */
            /* CRYPTO_KE_CIPHER_KEY         = 1U */
            /* CRYPTO_KE_RANDOM_SEED_STATE  = 3U */
            /* CRYPTO_KE_RANDOM_ALGORITH    = 4U */
            /* CRYPTO_KE_CIPHER_IV          = 5U */
            /* CRYPTO_KE_CIPHER_2NDKEY      = 7U */
            retValue = E_OK;
            break;
        case CRYPTO_KE_MAC_PROOF:
            /* SHE key is not applicable */
            /* Below is SHE key and their corresponding values. */
            /* CRYPTO_KE_MAC_PROOF      = 2U */
            /* CRYPTO_KE_CIPHER_PROOF   = 2U */
            retValue = E_NOT_OK;
            break;
        default:
            /* Unsupported key element IDs */
            retValue = CRYPTO_E_KEY_NOT_AVAILABLE;
            break;
        }
 
        if ( E_OK == retValue ) {
            retValue = crypto_chkReadAccess( pCryptoKey, chkElementCnt );
            if ( E_OK != retValue ) {
                return ( CRYPTO_E_KEY_READ_FAIL );
            }
        } else {
            /* SHE key or unsupported key element ID */
            return ( retValue );
        }
    }
 
    /* target key element ID and write access check */
    pTargetKey = &s_KeysCfgPtr->CryptoKey[targetKeyIndex];
    pTargetKeyType = pTargetKey->CryptoKeyTypeRef;
    for ( chkElementCnt=0U; chkElementCnt < pTargetKeyType->CryptoNumOfKeyElementRef; chkElementCnt++ ) {
        pTargetElement = &pTargetKeyType->CryptoKeyElementRef[chkElementCnt];
 
        /* key element ID check */
        elementId = pTargetElement->CryptoKeyElementId;
        switch( elementId ) {
        case CRYPTO_KE_MAC_KEY:
        case CRYPTO_KE_RANDOM_SEED_STATE:
        case CRYPTO_KE_RANDOM_ALGORITHM:
        case CRYPTO_KE_CIPHER_IV:
        case CRYPTO_KE_CIPHER_2NDKEY:
            /* Supported key element IDs */
            /* Refer to line 1490. */
            retValue = E_OK;
            break;
        case CRYPTO_KE_MAC_PROOF:
            /* SHE key is not applicable */
            /* Refer to line 1502. */
            retValue = E_NOT_OK;
            break;
        default:
            /* Unsupported key element IDs */
            retValue = CRYPTO_E_KEY_NOT_AVAILABLE;
            break;
        }
 
        if ( E_OK == retValue ) {
            retValue = crypto_chkWriteAccess( pTargetKey, chkElementCnt );
            if ( E_OK != retValue ) {
                return ( CRYPTO_E_KEY_WRITE_FAIL );
            }
        } else {
            /* SHE key or unsupported key element ID */
            return ( retValue );
        }
    }
 
    /* size check */
    for ( chkElementCnt=0U; chkElementCnt < pKeyType->CryptoNumOfKeyElementRef; chkElementCnt++ ) {
        pKeyElement = &pKeyType->CryptoKeyElementRef[chkElementCnt];
        pTargetElement = &pTargetKeyType->CryptoKeyElementRef[chkElementCnt];
        if ( pKeyElement->CryptoKeyElementSize != pTargetElement->CryptoKeyElementSize ) {
            return ( CRYPTO_E_KEY_SIZE_MISMATCH );
        }
    }
 
    /* copy the crypto key */
    Crypto_ObjectStatus = CRYPTO_OBJECT_ACTIVE;
    /* [SWS_Crypto_00159] : If no errors are detected by the Crypto Driver, the function shall copy
     * all key elements in the key referenced by cryptoKeyId to the key the key referenced by targetCryptoKeyId.*/
    crypto_memCopy( ( const uint8* ) pCryptoKey, ( uint8* ) pTargetKey, (uint32)sizeof( Crypto_KeyType ) );
    Crypto_ObjectStatus = CRYPTO_OBJECT_IDLE;
 
    return ( E_OK );
}
 
/******************************************************************************/
/* ModuleID    : Crypto_MODULE_ID (114)                                       */
/* ServiceID   : CRYPTO_KEYELEMENT_IDS_GET_ID                                 */
/* Name        : Crypto_KeyElementIdsGet                                      */
/* Param       : (in) cryptoKeyId                                             */
/*               (out) keyElementIdsPtr                                       */
/*               (inout) keyElementIdsLengthPtr                               */
/* Return      : Std_ReturnType                                               */
/*                  E_OK: Request successful.                                 */
/*                  E_NOT_OK: Request failed.                                 */
/*                  CRYPTO_E_BUSY: Request failed, Crypto Driver Object is    */
/*                                 busy.                                      */
/* Contents    : Used to retrieve information which key elements are          */
/*               available in a given key.                                    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Crypto_KeyElementIdsGet( uint32 cryptoKeyId, uint32* keyElementIdsPtr, uint32* keyElementIdsLengthPtr )
{
    Std_ReturnType  retValue;
    uint32          cryptoKeyIndex;
 
    /* [SWS_Crypto_00040][SWS_Crypto_00126] :
    * The Crypto Driver shall use an AUTOSAR DET module for development error notification. */
    if ( ( CRYPTO_IDLE != Crypto_DriverStatus ) || ( CRYPTO_OBJECT_UNINIT == Crypto_ObjectStatus ) ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
        /* [SWS_Crypto_00161] : If the Crypto Driver is not yet initialized and if development error
         * detection for the Crypto Driver is enabled, the function Crypto_KeyElementIdsGet shall
         * report CRYPTO_E_UNINIT to the DET and return E_NOT_OK.
         */
        ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                     ( uint8 ) CRYPTO_KEYELEMENT_IDS_GET_ID, ( uint8 ) CRYPTO_E_UNINIT );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
        retValue = E_NOT_OK;
    } else if ( CRYPTO_OBJECT_ACTIVE == Crypto_ObjectStatus ) {
        retValue = CRYPTO_E_BUSY;
    } else {
        /* cryptoKeyId check */
        retValue = crypto_chkCryptoKeyId( cryptoKeyId, &cryptoKeyIndex );
        if ( E_OK != retValue ) {
#if ( CRYPTO_DEV_ERROR_DETECT != FALSE )
            /* [SWS_Crypto_00162] : If cryptoKeyId is out of range and if development error detection
             * for the Crypto Driver is enabled, the function Crypto_KeyElementIdsGet shall report
             * CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.
             */
            ( void ) Det_ReportError( ( uint16 ) CRYPTO_MODULE_ID, ( uint8 ) CRYPTO_INSTANCE_ID,
                            ( uint8 ) CRYPTO_KEYELEMENT_IDS_GET_ID, ( uint8 ) CRYPTO_E_PARAM_HANDLE );
#endif /* ( CRYPTO_DEV_ERROR_DETECT != FALSE ) */
            retValue = E_NOT_OK;
        } else {
            /* get key element IDs */
            Crypto_ObjectStatus = CRYPTO_OBJECT_ACTIVE;
            crypto_getKeyElementIds( cryptoKeyIndex, keyElementIdsPtr, keyElementIdsLengthPtr );
            Crypto_ObjectStatus = CRYPTO_OBJECT_IDLE;
        }
    }
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_chkReadAccess                                         */
/* Param       : (in) pKey                                                    */
/*               (in) elementIndex                                            */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  CRYPTO_E_KEY_READ_FAIL                                    */
/* Contents    : This function check the read access right of selected        */
/*               key element                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_chkReadAccess( const Crypto_KeyType* pKey, uint32 elementIndex )
{
    Std_ReturnType                  retValue;
    const Crypto_KeyTypeType*       pKeyType;
    const Crypto_KeyElementType*    pKeyElement;
 
    pKeyType = pKey->CryptoKeyTypeRef;
    pKeyElement = &pKeyType->CryptoKeyElementRef[elementIndex];
    if( ( CRYPTO_RA_DENIED == pKeyElement->CryptoKeyElementReadAccess ) ) {
        retValue = CRYPTO_E_KEY_READ_FAIL;
    } else {
        retValue = E_OK;
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_chkWriteAccess                                        */
/* Param       : (in) pKey                                                    */
/*               (in) elementIndex                                            */
/* Return      : Std_ReturnType                                               */
/*                  E_OK                                                      */
/*                  CRYPTO_E_KEY_READ_FAIL                                    */
/* Contents    : This function check the write access right of selected       */
/*               key element                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static Std_ReturnType crypto_chkWriteAccess( const Crypto_KeyType* pKey, uint32 elementIndex )
{
    Std_ReturnType                  retValue;
    const Crypto_KeyTypeType*       pKeyType;
    const Crypto_KeyElementType*    pKeyElement;
 
    pKeyType = pKey->CryptoKeyTypeRef;
    pKeyElement = &pKeyType->CryptoKeyElementRef[elementIndex];
    if( ( CRYPTO_WA_DENIED == pKeyElement->CryptoKeyElementWriteAccess ) ) {
        retValue = CRYPTO_E_KEY_WRITE_FAIL;
    } else {
        retValue = E_OK;
    }
 
    return ( retValue );
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_getKeyElementIds                                      */
/* Param       : (in)       keyIdIndex                                        */
/*               (out)      keyElementIdsPtr                                  */
/*               (inout)    keyElementIdsLengthPtr                            */
/* Return      : void                                                         */
/* Contents    : This function will get all key element IDs from selected key */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void crypto_getKeyElementIds( uint32 keyIdIndex, uint32* keyElementIdsPtr, uint32* keyElementIdsLengthPtr )
{
    uint32_least                    elementCnt;
    uint32                          elementNum;
    const Crypto_KeyType*           pCryptoKey;
    const Crypto_KeyTypeType*       pKeyType;
    const Crypto_KeyElementType*    pKeyElement;
 
    pCryptoKey = &s_KeysCfgPtr->CryptoKey[keyIdIndex];
    pKeyType = pCryptoKey->CryptoKeyTypeRef;
    elementNum = pKeyType->CryptoNumOfKeyElementRef;
 
    /* check the num of duplications */
    if ( elementNum > *keyElementIdsLengthPtr ) {
        elementNum = *keyElementIdsLengthPtr;
    }
 
    /* get element IDs */
    for ( elementCnt=0U; elementCnt<elementNum; elementCnt++ ) {
        pKeyElement = &pKeyType->CryptoKeyElementRef[elementCnt];
        keyElementIdsPtr[elementCnt] = pKeyElement->CryptoKeyElementId;
    }
 
    /* store the num of elements */
    *keyElementIdsLengthPtr = elementNum;
}
 
/******************************************************************************/
/* ModuleID    : CRYPTO_MODULE_ID (114)                                       */
/* ServiceID   : --                                                           */
/* Name        : crypto_keyGetStatus                                          */
/* Param       : (in) keyIndex                                                */
/*               (out) keyStatusPtr                                           */
/* Return      : void                                                         */
/* Contents    : This function will get key status.                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static void crypto_keyGetStatus( uint32 keyIndex, Crypto_KeyStatusType* keyStatusPtr )
{
    *keyStatusPtr = ( Crypto_KeyStatusType )Crypto_KeyInfo[keyIndex].keyIdStatus;
}
 
#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
 
/* EOF Crypto_KeyManagement.c *************************************************/