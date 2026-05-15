/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Wdg_Lcfg.c                                                   */
/* Version     : v1.00.00                                                     */
/* Contents    : WDG Configuration at Linked time                             */
/*                The WDG is a basic software module at the service layer of  */
/*                the standardized basic software architecture of AUTOSAR.    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of WDG Driver
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include header                                                             */
/*----------------------------------------------------------------------------*/
#include "Wdg.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define WDG_70_VENDOR_ID_LCFG_C                   (70U)
#define WDG_70_MODULE_ID_LCFG_C                   (102U)

#define WDG_70_AR_RELEASE_MAJOR_VERSION_LCFG_C    (22U)
#define WDG_70_AR_RELEASE_MINOR_VERSION_LCFG_C    (11U)
#define WDG_70_AR_RELEASE_REVISION_VERSION_LCFG_C (0U)

#define WDG_70_SW_MAJOR_VERSION_LCFG_C            (1U)
#define WDG_70_SW_MINOR_VERSION_LCFG_C            (0U)
#define WDG_70_SW_PATCH_VERSION_LCFG_C            (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Wdg.h version check start */
#if ( WDG_70_VENDOR_ID_LCFG_C != WDG_VENDOR_ID )
    #error "VENDOR ID for Wdg_Lcfg.c and Wdg.h are different"
#endif

#if ( WDG_70_MODULE_ID_LCFG_C != WDG_MODULE_ID )
    #error "MODULE ID for Wdg_Lcfg.c and Wdg.h are different"
#endif

#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_LCFG_C    != WDG_AR_RELEASE_MAJOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_LCFG_C    != WDG_AR_RELEASE_MINOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_REVISION_VERSION_LCFG_C != WDG_AR_RELEASE_REVISION_VERSION ) )
    #error "AUTOSAR Version Numbers of Wdg_Lcfg.c and Wdg.h are different"
#endif

#if ( ( WDG_70_SW_MAJOR_VERSION_LCFG_C != WDG_SW_MAJOR_VERSION ) || \
      ( WDG_70_SW_MINOR_VERSION_LCFG_C != WDG_SW_MINOR_VERSION ) || \
      ( WDG_70_SW_PATCH_VERSION_LCFG_C != WDG_SW_PATCH_VERSION ) )
    #error "Software Version Numbers of Wdg_Lcfg.c and Wdg.h are different"
#endif
/* Wdg.h version check end */

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/* EOF Wdg_Lcfg.c ********************************************************/
