/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Fls_70_HW.h                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : FLS Module wrapper header                                    */
/*               The FLS is a basic software module at the service            */
/*               layer of the standardized basic software                     */
/*               architecture of AUTOSAR.                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */-                                                          */
/******************************************************************************/
/* Specification of Flash Driver                                              */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef FLS_70_HW_H
#define FLS_70_HW_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Fls_70_RL78F2X.h"
#include "Fls_70_HW_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/

#define FLS_70_VENDOR_ID_HW_H                (70U)
#define FLS_70_MODULE_ID_HW_H                (92U)

#define FLS_70_AR_RELEASE_MAJOR_VERSION_HW_H (22U)
#define FLS_70_AR_RELEASE_MINOR_VERSION_HW_H (11U)
#define FLS_70_AR_RELEASE_REVISION_VERSION_HW_H (0U)

#define FLS_70_SW_MAJOR_VERSION_HW_H         (1U)
#define FLS_70_SW_MINOR_VERSION_HW_H         (0U)
#define FLS_70_SW_PATCH_VERSION_HW_H         (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Fls_70_RL78F2X.h version check start */
#if ( FLS_70_VENDOR_ID_HW_H != FLS_70_VENDOR_ID_RL78F2X_H )
 #error "VENDOR ID for Fls_70_HW.h and Fls_70_RL78F2X.h are different"
#endif

#if ( FLS_70_MODULE_ID_HW_H != FLS_70_MODULE_ID_RL78F2X_H )
 #error "MODULE ID for Fls_70_HW.h and Fls_70_RL78F2X.h are different"
#endif

#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_HW_H    != FLS_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H    )  ||  \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_HW_H    != FLS_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H    )  ||  \
      ( FLS_70_AR_RELEASE_REVISION_VERSION_HW_H != FLS_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H )      \
    )
  #error "AUTOSAR Version Numbers of Fls_70_HW.h and Fls_70_RL78F2X.h are different"
#endif

#if ( ( FLS_70_SW_MAJOR_VERSION_HW_H   != FLS_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( FLS_70_SW_MINOR_VERSION_HW_H   != FLS_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( FLS_70_SW_PATCH_VERSION_HW_H   != FLS_70_SW_PATCH_VERSION_RL78F2X_H )   \
    )
  #error "Software Version Numbers of Fls_70_HW.h and Fls_70_RL78F2X.h are different"
#endif

/* Fls_70_RL78F2X.h version check end */

/* Fls_70_HW_Types.h version check start */

#if ( FLS_70_VENDOR_ID_HW_H  != FLS_70_VENDOR_ID_RL78F2X_H )
  #error "VENDOR ID for Fls_70_HW.h and Fls_70_HW_Types.h are different"
#endif

#if ( FLS_70_MODULE_ID_HW_H  != FLS_70_MODULE_ID_RL78F2X_H )
  #error "MODULE ID for Fls_70_HW.h and Fls_70_HW_Types.h are different"
#endif

#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_HW_H    != FLS_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H    )  ||  \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_HW_H    != FLS_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H    )  ||  \
      ( FLS_70_AR_RELEASE_REVISION_VERSION_HW_H != FLS_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H )      \
    )
  #error "AUTOSAR Version Numbers of Fls_70_HW.h and Fls_70_HW_Types.h are different"
#endif

#if ( ( FLS_70_SW_MAJOR_VERSION_HW_H   != FLS_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( FLS_70_SW_MINOR_VERSION_HW_H   != FLS_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( FLS_70_SW_PATCH_VERSION_HW_H   != FLS_70_SW_PATCH_VERSION_RL78F2X_H )    \
    )
  #error "Software Version Numbers of Fls_70_HW.h and Fls_70_HW_Types.h are different"
#endif

/* Fls_70_HW_Types.h version check end */

/* macro function definitions */
#define Fls_70_HW_Init()                        Fls_70_RL78F2X_Init()
#define Fls_70_HW_Execute( pFlsJobControl )     Fls_70_RL78F2X_Execute( pFlsJobControl )
#endif /* FLS_70_HW_H */
/* EOF Fls_70_HW.h ************************************************************/
