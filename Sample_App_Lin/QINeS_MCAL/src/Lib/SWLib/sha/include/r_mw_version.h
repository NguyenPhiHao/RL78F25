/******************************************************************************/
/* Copyright    : 2023 SCSK Corporation                                       */
/* System Name   : QINeS-Lite MCAL                                            */
/* File Name     : r_mw_version.h                                             */
/* Version       : v1.00.00                                                   */
/* Contents      : This file is for SHA Hash library used in AUTOSAR Basic    */
/*                 Software module "Crypto Driver".                           */
/* Author        : m.ishikawa                                                 */
/* Note          : --                                                         */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */

#ifndef _R_MW_VERSION_H_
#define _R_MW_VERSION_H_

/*----------------------------------------------------------------------------*/
/* Macro definitions                                                          */
/*----------------------------------------------------------------------------*/
/* Middleware version character size */
#define __VER_STRING_MAX__    128

/*----------------------------------------------------------------------------*/
/* Typedef definitions                                                        */
/*----------------------------------------------------------------------------*/
/* Middleware version information structure */
typedef struct
{
    uint32 compiler;                     /* Compiler version number */
    uint8  library[__VER_STRING_MAX__];  /* Library version string */
} mw_version_t;

/*----------------------------------------------------------------------------*/
/* Exported global variables                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private (static) variables and functions                                   */
/*----------------------------------------------------------------------------*/

#endif  /* _R_MW_VERSION_H_ */
