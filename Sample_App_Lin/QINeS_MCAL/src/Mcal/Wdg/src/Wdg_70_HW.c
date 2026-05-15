/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Wdg_70_HW.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : WDG Module wrapper                                           */
/*               The WDG is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of WDG Driver                                                */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Wdg_70_HW.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define WDG_70_VENDOR_ID_HW_C                ( 70U )
#define WDG_70_MODULE_ID_HW_C                (102U )

#define WDG_70_AR_RELEASE_MAJOR_VERSION_HW_C ( 22U )
#define WDG_70_AR_RELEASE_MINOR_VERSION_HW_C ( 11U )
#define WDG_70_AR_RELEASE_REVISION_VERSION_HW_C ( 00U )

#define WDG_70_SW_MAJOR_VERSION_HW_C         (  1U )
#define WDG_70_SW_MINOR_VERSION_HW_C         (  0U )
#define WDG_70_SW_PATCH_VERSION_HW_C         (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Wdg_70_HW.h version check start */
#if   ( WDG_70_VENDOR_ID_HW_C            != WDG_70_VENDOR_ID_HW_H )
  #error "VENDOR ID for Wdg_70_HW.c and Wdg_70_HW.h are different"
#endif

#if   ( WDG_70_MODULE_ID_HW_C            != WDG_70_MODULE_ID_HW_H )
  #error "MODULE ID for Wdg_70_HW.c and Wdg_70_HW.h are different"
#endif

#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_HW_C != WDG_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_HW_C != WDG_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( WDG_70_AR_RELEASE_REVISION_VERSION_HW_C != WDG_70_AR_RELEASE_REVISION_VERSION_HW_H ) )
  #error "AUTOSAR Version Numbers of Wdg_70_HW.c and Wdg_70_HW.h are different"
#endif

#if ( ( WDG_70_SW_MAJOR_VERSION_HW_C != WDG_70_SW_MAJOR_VERSION_HW_H ) || \
      ( WDG_70_SW_MINOR_VERSION_HW_C != WDG_70_SW_MINOR_VERSION_HW_H ) || \
      ( WDG_70_SW_PATCH_VERSION_HW_C != WDG_70_SW_PATCH_VERSION_HW_H ) )
  #error "Software Version Numbers of Wdg_70_HW.c and Wdg_70_HW.h are different"
#endif
/* Wdg_70_HW.h version check end */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* global variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/* EOF Wdg_70_HW.c ************************************************************/