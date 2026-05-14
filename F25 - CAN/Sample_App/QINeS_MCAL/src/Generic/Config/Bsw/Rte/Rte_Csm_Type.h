/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_Csm_Type.h                                               */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef RTE_CSM_TYPE_H
#define RTE_CSM_TYPE_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"

/*----------------------------------------------------------------------------*/
/* Crypt type definitions (Service Interface)                                 */
/*----------------------------------------------------------------------------*/
/* operation shall be performed */
typedef uint8 Crypto_OperationModeType;

/* BitField |FINISH|UPDATE|START */
#define CRYPTO_OPERATIONMODE_START            ( ( Crypto_OperationModeType )0x01U )
#define CRYPTO_OPERATIONMODE_UPDATE           ( ( Crypto_OperationModeType )0x02U )
#define CRYPTO_OPERATIONMODE_FINISH           ( ( Crypto_OperationModeType )0x04U )
#define CRYPTO_OPERATIONMODE_SINGLECALL       ( \
    ( Crypto_OperationModeType )( CRYPTO_OPERATIONMODE_START   \
                                | CRYPTO_OPERATIONMODE_UPDATE  \
                                | CRYPTO_OPERATIONMODE_FINISH ) )
#define CRYPTO_OPERATIONMODE_SAVE_CONTEXT     ( ( Crypto_OperationModeType )0x08U )
#define CRYPTO_OPERATIONMODE_RESTORE_CONTEXT  ( ( Crypto_OperationModeType )0x10U )

/*----------------------------------------------------------------------------*/
/* the result type of verification operations                                 */
/*----------------------------------------------------------------------------*/
typedef uint8 Crypto_VerifyResultType;
#define CRYPTO_E_VER_OK       ( ( Crypto_VerifyResultType )0x00U )
#define CRYPTO_E_VER_NOT_OK   ( ( Crypto_VerifyResultType )0x01U )

/*----------------------------------------------------------------------------*/
/* Return for Std_ReturnType for Cryptostack.                                 */
/*----------------------------------------------------------------------------*/
typedef Std_ReturnType Crypto_ResultType;

/*----------------------------------------------------------------------------*/
/* enums                                                                      */
/*----------------------------------------------------------------------------*/
/* Enumeration for key status. */
typedef enum {
    CRYPTO_KEYSTATUS_INVALID           = 0U,
    CRYPTO_KEYSTATUS_VALID,
    CRYPTO_KEYSTATUS_UPDATE_IN_PROGRESS
} Crypto_KeyStatusType;

#endif /* RTE_CSM_TYPE_H */

/* EOF Rte_Csm_Type.h *********************************************************/
