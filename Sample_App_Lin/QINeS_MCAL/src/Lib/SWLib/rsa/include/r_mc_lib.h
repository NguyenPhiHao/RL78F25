/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : QINeS-Lite MCAL                                              */
/* File Name   : r_mc_lib.h                                                   */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for RSA library used in AUTOSAR Basic Software  */
/*               module "Crypto Driver".                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef R_MC_LIB_H
#define R_MC_LIB_H

/*----------------------------------------------------------------------------*/
/* Includes   <System Includes> , "Project Includes"                          */
/*----------------------------------------------------------------------------*/
#include "Platform_Types.h"
#include "Std_Types.h"
#include "QINeS_Lite.h"
#include "Compiler.h"

/*----------------------------------------------------------------------------*/
/* Macro definitions                                                          */
/*----------------------------------------------------------------------------*/
#define MC_BASE                (16u)
#define MC_KND
#define MC_MASK                ((uint16)0xffffu)

/* BIT length of data to be input and output */
#define KEY_LENGTH             (2048u)

#if !defined(IO_DATA_BIT_LENGTH)
#define IO_DATA_BIT_LENGTH     (KEY_LENGTH)    /* default value for RX & RL78 */
#endif

#define IO_DATA_BYTE_LENGTH    (IO_DATA_BIT_LENGTH/8u)

#define MC_MEMORY_NUM          (2u)
#define MC_MEMORY_SIZE         ((IO_DATA_BYTE_LENGTH*2u)+2u)   /* 514 Bytes */
#define MC_INT_ARRAY_LENGTH    (MC_MEMORY_SIZE/2u)            /* Length of array of val member of MC_int */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef uint16  MC;
typedef sint16  mc;
typedef uint32  MCMC;

/* Structure of the multiple-precision */
typedef struct
{
    uint16 deg;
    MC     *val;
    uint16 len;
} MC_int;

/*----------------------------------------------------------------------------*/
/* Exported global functions (to be accessed by other files)                  */
/*----------------------------------------------------------------------------*/
/*
 * @brief   Convert from 1-byte array data to MC_int type.
 * @warning none.
 * @retval  0  Normal end.
 * @retval –1  Error end.
 */
uint8 r_mc_byte2mc( uint8 QL_70_FAR *ip, uint16 len, MC_int *mc_op );

/*
 * @brief   Convert from MC_int type to 1-byte array data.
 * @warning none.
 * @retval  0  Normal end.
 * @retval –1  Error end.
 */
uint8 r_mc_mc2byte( MC_int *mc_ip, uint8 *op, uint16 *len );

/*
 * @brief   Compare multiple-length variables.
 * @warning none.
 * @retval  1   The comparison destination is large
 * @retval  0   Equivalence
 * @retval –1   The comparison destination is small
 */
uint8 r_mc_cmpl( MC_int *x, MC_int *y );

/*
 * @brief   Modular exponentiation (z = x^y mod m)
 * @warning none.
 * @retval –3  Input value is incorrect
 * @retval –1  Memory allocation failure
 * @retval  0  Normal end
 */
uint8 r_mc_powm( MC_int *x,
                 MC_int *y,
                 MC_int *z,
                 MC_int *m,
                 MC     *mc_memory0,
                 MC     *mc_memory1 );

#endif /* R_MC_LIB_H */
