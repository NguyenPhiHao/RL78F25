/*----------------------------------------------------------------------------*/
/* Copyright : 2023 SCSK Corporation                                          */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Fls_70_HW.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : FLS Module wrapper                                           */
/*               The FLS is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* Specification of Flash Driver :                                            */
/* Release     : R22-11                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Fls_70_HW.h"

/*----------------------------------------------------------------------------*/
/* File version information                                                   */
/*----------------------------------------------------------------------------*/
#define FLS_70_VENDOR_ID_HW_C                ( 70U )
#define FLS_70_MODULE_ID_HW_C                ( 92U )

#define FLS_70_AR_RELEASE_MAJOR_VERSION_HW_C ( 22U )
#define FLS_70_AR_RELEASE_MINOR_VERSION_HW_C ( 11U )
#define FLS_70_AR_RELEASE_REVISION_VERSION_HW_C  ( 0U )

#define FLS_70_SW_MAJOR_VERSION_HW_C         ( 1U )
#define FLS_70_SW_MINOR_VERSION_HW_C         ( 0U )
#define FLS_70_SW_PATCH_VERSION_HW_C         ( 0U )

/*----------------------------------------------------------------------------*/
/* File version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Fls_70_HW.h version check start */
#if ( FLS_70_VENDOR_ID_HW_C != FLS_70_VENDOR_ID_HW_H )
#  error "VENDOR ID for Fls_70_HW.c and Fls_70_HW.h are different"
#endif

#if ( FLS_70_MODULE_ID_HW_C != FLS_70_MODULE_ID_HW_H )
#  error "MODULE ID for Fls_70_HW.c and Fls_70_HW.h are different"
#endif

#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_HW_C    != FLS_70_AR_RELEASE_MAJOR_VERSION_HW_H )  ||  \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_HW_C    != FLS_70_AR_RELEASE_MINOR_VERSION_HW_H )  ||  \
      ( FLS_70_AR_RELEASE_REVISION_VERSION_HW_C != FLS_70_AR_RELEASE_REVISION_VERSION_HW_H ) )
#  error "AUTOSAR Version Numbers of Fls_70_HW.c and Fls_70_HW.h are different"
#endif

#if ( ( FLS_70_SW_MAJOR_VERSION_HW_C != FLS_70_SW_MAJOR_VERSION_HW_H ) || \
      ( FLS_70_SW_MINOR_VERSION_HW_C != FLS_70_SW_MINOR_VERSION_HW_H ) || \
      ( FLS_70_SW_PATCH_VERSION_HW_C != FLS_70_SW_PATCH_VERSION_HW_H ) )
#  error "Software Version Numbers of Fls_70_HW.c and Fls_70_HW.h are different"
#endif

/* Fls_70_HW.h version check end */

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local functions                                                            */
/*----------------------------------------------------------------------------*/

/* EOF Fls_70_HW.c ************************************************************/