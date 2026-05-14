/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Wdg_70_RL78F2X.c                                             */
/* Version     : v1.00.00                                                     */
/* Contents    : WDG Module HW dependent interface                            */
/*               The WDG is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of WDG Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Wdg_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define WDG_70_VENDOR_ID_RL78F2X_C              ( 70U )
#define WDG_70_MODULE_ID_RL78F2X_C              (102U )

#define WDG_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C ( 22U )
#define WDG_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C ( 11U )
#define WDG_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C ( 00U )

#define WDG_70_SW_MAJOR_VERSION_RL78F2X_C       ( 1U )
#define WDG_70_SW_MINOR_VERSION_RL78F2X_C       ( 0U )
#define WDG_70_SW_PATCH_VERSION_RL78F2X_C       ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Wdg_70_RL78F2X.h version check start */
#if ( WDG_70_VENDOR_ID_RL78F2X_C != WDG_70_VENDOR_ID_RL78F2X_H )
  #error "VENDOR ID for Wdg_70_RL78F2X.c and Wdg_70_RL78F2X.h are different"
#endif

#if ( WDG_70_MODULE_ID_RL78F2X_C != WDG_70_MODULE_ID_RL78F2X_H )
  #error "MODULE ID for Wdg_70_RL78F2X.c and Wdg_70_RL78F2X.h are different"
#endif

#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C != WDG_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C != WDG_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) || \
      ( WDG_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != WDG_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) )
  #error "AUTOSAR Version Numbers of Wdg_70_RL78F2X.c and Wdg_70_RL78F2X.h are different"
#endif

#if ( ( WDG_70_SW_MAJOR_VERSION_RL78F2X_C != WDG_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( WDG_70_SW_MINOR_VERSION_RL78F2X_C != WDG_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( WDG_70_SW_PATCH_VERSION_RL78F2X_C != WDG_70_SW_PATCH_VERSION_RL78F2X_H ) )
  #error "Software Version Numbers of Wdg_70_RL78F2X.c and Wdg_70_RL78F2X.h are different"
#endif
/* Wdg_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* functions and function style macros                         */
/*----------------------------------------------------------------------------*/
#define WDG_START_SEC_CODE_LOCAL
#include "Wdg_MemMap.h"

/***************************************************************************/
/* ModuleID    : WDG_MODULE_ID (102)                                       */
/* ServiceID   : --                                                         */
/* Name        : Wdg_70_RL78F2X_Init                                      */
/* Param       : void                                                       */
/* Return      : Std_ReturnType                                             */
/* Contents    : Refresh internal Watchdog                                  */
/* Author      : --                                                           */
/* Note        : [SWS_Wdg_00101] Refresh internal Wdg                       */
/***************************************************************************/
Std_ReturnType Wdg_70_RL78F2X_Init(void)
{
    Std_ReturnType IRetWriteVerify; /* IRetWriteVerify to check write value */

    /* [SWS_Wdg_00101] Refresh internal Wdg */
    MCL_70_RL78F2X_WDTE_REG = WDG_70_RL78F2X_REFRESH_SIGNAL;

    IRetWriteVerify = E_OK;

    return IRetWriteVerify;
}

#define WDG_STOP_SEC_CODE_LOCAL
#include "Wdg_MemMap.h"

/* EOF Wdg_70_RL78F2X.c **********************************************/```
