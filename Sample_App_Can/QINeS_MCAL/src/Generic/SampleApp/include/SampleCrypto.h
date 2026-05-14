/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                              */
/* File Name   : SampleCrypto.h
/* Version     : v1.00.01
/* Contents    : Crypto sample application header file.
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/

#ifndef SAMPLE_CRYPTO_H
#define SAMPLE_CRYPTO_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Crypto_GeneralTypes.h"
#include "Crypto_70_HW_Types.h"
#include "Crypto_Cfg.h"
#include "Crypto.h"
#include "Sample.h"

/*----------------------------------------------------------------------------*/
* RSA Key Data
/*----------------------------------------------------------------------------*/
#if ( TRUE == CRYPTO_70_RSA_ENABLE )
extern uint8 SampleCrypto_RsaKeyN[ CRYPTO_70_NUM_OF_RSAKEY ][ CRYPTO_70_RSA_LENGTH ];
extern uint8 SampleCrypto_RsaKeyED[ CRYPTO_70_NUM_OF_RSAKEY ][ CRYPTO_70_RSA_LENGTH ];
#endif  /* TRUE == CRYPTO_70_RSA_ENABLE */

extern uint8 SampleCrypto_AesCbcIV[ CRYPTO_70_NUM_OF_IV ][ CRYPTO_70_CBC_IV_LENGTH ];

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
void SampleCrypto(void);

#endif  /* #ifndef SAMPLE_CRYPTO_H */
