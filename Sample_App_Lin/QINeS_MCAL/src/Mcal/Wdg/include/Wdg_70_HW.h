/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Wdg_70_HW.h                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : WDG Module wrapper header                                    */
/*               The WDG is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of WDG Driver                                                */
/* R22-11                                                                     */
#ifndef WDG_70_HW_H
#define WDG_70_HW_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Wdg_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define WDG_70_VENDOR_ID_HW_H                ( 70U )
#define WDG_70_MODULE_ID_HW_H                (102U )

#define WDG_70_AR_RELEASE_MAJOR_VERSION_HW_H ( 22U )
#define WDG_70_AR_RELEASE_MINOR_VERSION_HW_H ( 11U )
#define WDG_70_AR_RELEASE_REVISION_VERSION_HW_H ( 00U )

#define WDG_70_SW_MAJOR_VERSION_HW_H         ( 1U )
#define WDG_70_SW_MINOR_VERSION_HW_H         ( 0U )
#define WDG_70_SW_PATCH_VERSION_HW_H         ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */
#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_HW_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_HW_H != STD_TYPES_AR_RELEASE_MINOR_VERSION )   \
    )
  #error "AUTOSAR Version Numbers of Wdg_70_HW.h and Std_Types.h are different"
#endif
/* Std_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* Wdg_70_RL78F2X.h version check start                         */
/*----------------------------------------------------------------------------*/
#if ( WDG_70_VENDOR_ID_HW_H    != WDG_70_VENDOR_ID_RL78F2X_H )
  #error "VENDOR ID for Wdg_70_HW.h and Wdg_70_RL78F2X.h are different"
#endif

#if ( WDG_70_MODULE_ID_HW_H    != WDG_70_MODULE_ID_RL78F2X_H )
  #error "MODULE ID for Wdg_70_HW.h and Wdg_70_RL78F2X.h are different"
#endif

#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_HW_H != WDG_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_HW_H != WDG_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) || \
      ( WDG_70_AR_RELEASE_REVISION_VERSION_HW_H != WDG_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) )
  #error "AUTOSAR Version Numbers of Wdg_70_HW.h and Wdg_70_RL78F2X.h are different"
#endif

#if ( ( WDG_70_SW_MAJOR_VERSION_HW_H != WDG_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( WDG_70_SW_MINOR_VERSION_HW_H != WDG_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( WDG_70_SW_PATCH_VERSION_HW_H != WDG_70_SW_PATCH_VERSION_RL78F2X_H ) )
  #error "Software Version Numbers of Wdg_70_HW.h and Wdg_70_RL78F2X.h are different"
#endif
/*----------------------------------------------------------------------------*/
/* Wdg_70_RL78F2X.h version check end                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define Wdg_70_HW_Init()                   Wdg_70_RL78F2X_Init()

/*----------------------------------------------------------------------------*/
/* Type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

#endif  /* #ifndef WDG_70_HW_H */

/* EOF Wdg_70_HW.h ************************************************************/