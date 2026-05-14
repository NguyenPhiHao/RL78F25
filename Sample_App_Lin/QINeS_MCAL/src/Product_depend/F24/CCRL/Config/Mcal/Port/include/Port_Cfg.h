/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Port_Cfg.h                                                   */
/* Version     : v1.00.00                                                     */
/* Contents    : Port configuration header                                    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of PORT Driver                                               */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define PORT_70_VENDOR_ID_CFG_H                ( 70U )
#define PORT_70_MODULE_ID_CFG_H                (124U )

#define PORT_70_AR_RELEASE_MAJOR_VERSION_CFG_H ( 22U )
#define PORT_70_AR_RELEASE_MINOR_VERSION_CFG_H ( 11U )
#define PORT_70_AR_RELEASE_REVISION_VERSION_CFG_H ( 00U )

#define PORT_70_SW_MAJOR_VERSION_CFG_H         ( 1U )
#define PORT_70_SW_MINOR_VERSION_CFG_H         ( 0U )
#define PORT_70_SW_PATCH_VERSION_CFG_H         ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */
#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_CFG_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_CFG_H != STD_TYPES_AR_RELEASE_MINOR_VERSION )   \
    )
  #error "AUTOSAR Version Numbers of Port_70_Cfg.h and Std_Types.h are different"
#endif
/* Std_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                     */
/*----------------------------------------------------------------------------*/
/* Switches the Development Error Detection and Notification */
#define PORT_DEV_ERROR_DETECT            ( TRUE )
/* Adds / removes the service Port_VersionInfo() from the code */
#define PORT_VERSION_INFO_API            ( TRUE )
/* Adds / removes the service Port_SetPinDirection() from the code */
#define PORT_SET_PIN_DIRECTION_API       ( TRUE )
/* Adds / removes the service Port_SetPinMode() from the code */
#define PORT_SET_PIN_MODE_API            ( TRUE )
/* Adds / removes the service Port_RefreshPortDirection() from the code */
#define PORT_REFRESH_PORT_DIRECTION_API  ( TRUE )

#define PORT_70_MAX_NUMBER               ( 16U )  /* Max Port Number */
#define PORT_70_NUM_OF_PORT_CONTAINER    ( 10U )  /* Port Container count */
#define PORT_70_NUM_OF_PORT_PIN          (128U )  /* Port Pin count */
#define PORT_70_NUM_OF_PIN_CHANGE_MODE   ( 0U  )  /* Port Pin Change mode count */
#define PORT_70_NUM_OF_CHANGED_MODE      ( 0U  )  /* Change mode count */
#define PORT_70_NUM_OF_PIOR_SET          ( 8U  )  /* Pin Set count */
#define PORT_70_NUM_OF_REG_SET           (14U  )  /* Register Set count */
#define PORT_70_NUM_OF_CONF_MODE         ( 3U  )  /* Configuration Mode count */

/* Port Mode Select register */
#define PORT_70_PMSVAL                   ( 0x00U )
/* Port Slew Rate Select register */
#define PORT_70_PSREVAL                  ( 0x00U )

/* Switch whether to use CC-RL Built-in functions (__clr1, __set1, __not1) */
#define PORT_70_RL78F2X_FUNCTIONS        ( TRUE )

#endif /* PORT_CFG_H_ */
/* EOF Port_Cfg.h ****************************************************/
