/*----------------------------------------------------------------------------*/
/* Copyright    : 2023 SCSK Corporation                                       */
/* System Name   : QINeS-Lite MCAL                                            */
/* File Name     : r_sha_core.h                                               */
/* Version       : v1.00.00                                                   */
/* Contents      : This file is for SHA Hash library used in AUTOSAR Basic    */
/*                 Software module "Crypto Driver".                           */
/* Author        : m.ishikawa                                                 */
/* Note          : --                                                         */
/*----------------------------------------------------------------------------*/
/* Specification of Crypto Driver
/* R22-11                                                                     */
/******************************************************************************/

#ifndef R_SHA_CORE_H
#define R_SHA_CORE_H

/*----------------------------------------------------------------------------*/
/* Includes   <System Includes> , "Project Includes"                          */
/*----------------------------------------------------------------------------*/
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
 * Exported global functions
/*----------------------------------------------------------------------------*/
extern void r_sha256_hash(const uint8 QL_70_FAR *mdat,
                          uint8 QL_70_NEAR  *hdat,
                          uint16           block,
                          uint32           *work);

#endif /* R_SHA_CORE_H */
