/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Can_70_RL78F2X_Dep.h                                         */
/* Version     : v1.00.00                                                     */
/* Contents    : This module provides services for initiating                 */
/*               transmissions and calls the callback functions of            */
/*               the CanIf module for notifying events,                       */
/*               independently from the hardware. Also it provides            */
/*               services to control the behavior and state of the            */
/*               CAN controllers that belong to the same CAN                  */
/*               Hardware Unit.                                               */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of CAN Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef CAN_70_RL78F2X_DEP_H
#define CAN_70_RL78F2X_DEP_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Can_70_RL78F2X_Types.h"    /* [CAN034] */
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define CAN_70_VENDOR_ID_RL78F2X_DEP_H              ( 70U )
#define CAN_70_MODULE_ID_RL78F2X_DEP_H              ( 80U )

#define CAN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_DEP_H ( 22U )
#define CAN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_DEP_H ( 11U )
#define CAN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_DEP_H ( 00U )

#define CAN_70_SW_MAJOR_VERSION_RL78F2X_DEP_H       (  1U )
#define CAN_70_SW_MINOR_VERSION_RL78F2X_DEP_H       (  0U )
#define CAN_70_SW_PATCH_VERSION_RL78F2X_DEP_H       (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Can_70_Types.h version check start */
#if ( CAN_70_VENDOR_ID_RL78F2X_DEP_H != CAN_70_VENDOR_ID_RL78F2X_TYPES_H )
  #error "VENDOR ID for Can_70_RL78F2X_Dep.h and Can_70_RL78F2X_Types.h are different"
#endif /* End of Vendor Id Version check */
#if ( CAN_70_MODULE_ID_RL78F2X_DEP_H != CAN_70_MODULE_ID_RL78F2X_TYPES_H )
  #error "MODULE ID for Can_70_RL78F2X_Dep.h and Can_70_RL78F2X_Types.h are different"
#endif /* End of Module Id Version check */

#if ( ( CAN_70_SW_MAJOR_VERSION_RL78F2X_DEP_H != CAN_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( CAN_70_SW_MINOR_VERSION_RL78F2X_DEP_H != CAN_70_SW_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( CAN_70_SW_PATCH_VERSION_RL78F2X_DEP_H != CAN_70_SW_PATCH_VERSION_RL78F2X_TYPES_H ) )
  #error "Software Version Numbers of Can_70_RL78F2X_Dep.h and Can_70_RL78F2X_Types.h are different"
#endif  /* End of S/W Version check */

#if ( ( CAN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_DEP_H != CAN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( CAN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_DEP_H != CAN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( CAN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_DEP_H != CAN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H ) )
  #error "AUTOSAR Version Numbers of Can_70_RL78F2X_Dep.h and Can_70_RL78F2X_Types.h are different"
#endif  /* End of Autosar Version check */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/* Macros to set the filter registers                          */
/* CAN Channels                                                */
/*----------------------------------------------------------------------------*/
#define CAN_70_CAN_CHANNEL_CAN0         ( (uint8)0U )
#define CAN_70_CAN_CHANNEL_CAN1         ( (uint8)1U )
#define CAN_70_NUM_OF_CAN_CHANNEL       ( (uint8)2U )

/*----------------------------------------------------------------------------*/
/* Type definitions                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

#endif  /* #ifndef CAN_70_RL78F2X_DEP_H */
/* EOF Can_70_RL78F2X_Dep.h **********************************************/
