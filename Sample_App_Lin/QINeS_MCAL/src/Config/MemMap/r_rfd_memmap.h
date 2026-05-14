/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_rfd_memmap.h                                               */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for Fls driver used in AUTOSAR Basic Software   */
/*               module "Crypto Driver" and "Fls Driver".                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto/Fls Driver                                         */
/* R22-11                                                                     */

#include "r_rfd_compiler.h"

/* Section definition for Common Component */
#if defined (R_RFD_START_SECTION_RFD_CMN)
    #undef  R_RFD_START_SECTION_RFD_CMN
    #pragma section text .qines_mcal_fls_text
#elif defined (R_RFD_END_SECTION_RFD_CMN)
    #undef  R_RFD_END_SECTION_RFD_CMN
    #pragma section
/* Section definition for Code Flash Component */
#elif defined (R_RFD_START_SECTION_RFD_CF)
    #undef  R_RFD_START_SECTION_RFD_CF
    #pragma section text .qines_mcal_fls_text
#elif defined (R_RFD_END_SECTION_RFD_CF)
    #undef  R_RFD_END_SECTION_RFD_CF
    #pragma section
/* Section definition for Data Flash Component */
#elif defined (R_RFD_START_SECTION_RFD_DF)
    #undef  R_RFD_START_SECTION_RFD_DF
    #pragma section text .qines_mcal_fls_text
#elif defined (R_RFD_END_SECTION_RFD_DF)
    #undef  R_RFD_END_SECTION_RFD_DF
    #pragma section
/* Section definition for Extra Area Component */
#elif defined (R_RFD_START_SECTION_RFD_EX)
    #undef  R_RFD_START_SECTION_RFD_EX
    #pragma section text .qines_mcal_fls_text
#elif defined (R_RFD_END_SECTION_RFD_EX)
    #undef  R_RFD_END_SECTION_RFD_EX
    #pragma section
/* Section definition for Global Data for Common Component */
#elif defined (R_RFD_START_SECTION_RFD_DATA)
    #undef  R_RFD_START_SECTION_RFD_DATA
    #pragma section data .qines_mcal_fls_data
#elif defined (R_RFD_END_SECTION_RFD_DATA)
    #undef  R_RFD_END_SECTION_RFD_DATA
    #pragma section
#endif  /* Section definition for CCRL */