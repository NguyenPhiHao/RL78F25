/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Icu_Cfg.c                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : Icu post build time configuration                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ICU Driver
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include header                                                             */
/*----------------------------------------------------------------------------*/
#include "Icu.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ICU_70_VENDOR_ID_CFG_C                   (70U)
#define ICU_70_MODULE_ID_CFG_C                   (122U)

#define ICU_70_AR_RELEASE_MAJOR_VERSION_CFG_C    (22U)
#define ICU_70_AR_RELEASE_MINOR_VERSION_CFG_C    (11U)
#define ICU_70_AR_RELEASE_REVISION_VERSION_CFG_C (0U)

#define ICU_70_SW_MAJOR_VERSION_CFG_C            (1U)
#define ICU_70_SW_MINOR_VERSION_CFG_C            (0U)
#define ICU_70_SW_PATCH_VERSION_CFG_C            (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Icu.h version check start */
#if ( ICU_70_VENDOR_ID_CFG_C != ICU_VENDOR_ID )
    #error "VENDOR ID for Icu_Cfg.c and Icu.h are different"
#endif

#if ( ICU_70_MODULE_ID_CFG_C != ICU_MODULE_ID )
    #error "MODULE ID for Icu_Cfg.c and Icu.h are different"
#endif

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_CFG_C    != ICU_AR_RELEASE_MAJOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_CFG_C    != ICU_AR_RELEASE_MINOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_CFG_C != ICU_AR_RELEASE_REVISION_VERSION ) )
    #error "AUTOSAR Version Numbers of Icu_Cfg.c and Icu.h are different"
#endif

#if ( ( ICU_70_SW_MAJOR_VERSION_CFG_C != ICU_SW_MAJOR_VERSION ) || \
      ( ICU_70_SW_MINOR_VERSION_CFG_C != ICU_SW_MINOR_VERSION ) || \
      ( ICU_70_SW_PATCH_VERSION_CFG_C != ICU_SW_PATCH_VERSION ) )
    #error "Software Version Numbers of Icu_Cfg.c and Icu.h are different"
#endif
/* Icu.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------*/
/* variable                                                               */
/*------------------------------------------------------------------------*/

/* EOF Icu_Cfg.c *********************************************************/
