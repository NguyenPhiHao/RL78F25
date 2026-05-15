/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Wdg_70_RL78F2X.h                                             */
/* Version     : v1.00.00                                                     */
/* Contents    : WDG Module HW dependent header                               */
/*               The WDG is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of WDG Driver                                                */
/* R22-11                                                                     */
#ifndef WDG_70_RL78F2X_H
#define WDG_70_RL78F2X_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Mcl_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define WDG_70_VENDOR_ID_RL78F2X_H                ( 70U )
#define WDG_70_MODULE_ID_RL78F2X_H                (102U )

#define WDG_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ( 22U )
#define WDG_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ( 11U )
#define WDG_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H (  0U )

#define WDG_70_SW_MAJOR_VERSION_RL78F2X_H         (  1U )
#define WDG_70_SW_MINOR_VERSION_RL78F2X_H         (  0U )
#define WDG_70_SW_PATCH_VERSION_RL78F2X_H         (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */
#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H != STD_TYPES_AR_RELEASE_MINOR_VERSION )   \
    )
  #error "AUTOSAR Version Numbers of Wdg_70_RL78F2X.h and Std_Types.h are different"
#endif
/* Std_Types.h version check end */

/* Mcl_70_RL78F2X.h version check start */
#if ( ( WDG_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H != MCL_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( WDG_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H != MCL_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H )   \
    )
  #error "AUTOSAR Version Numbers of Wdg_70_RL78F2X.h and Mcl_70_RL78F2X.h are different"
#endif
/* Mcl_70_RL78F2X.h version check end */

/* Mcl_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* refresh internal wdg by writing 0xACU to watchdog timer enable register (WDTE) register */
#define WDG_70_RL78F2X_REFRESH_SIGNAL    ( 0xACU )

/*----------------------------------------------------------------------------*/
/* Type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#define WDG_START_SEC_CODE_LOCAL
#include "Wdg_MemMap.h"

extern Std_ReturnType Wdg_70_RL78F2X_Init( void );

#define WDG_STOP_SEC_CODE_LOCAL
#include "Wdg_MemMap.h"

#endif  /* #ifndef WDG_70_RL78F2X_H */

/* EOF Wdg_70_RL78F2X.h *******************************************************/