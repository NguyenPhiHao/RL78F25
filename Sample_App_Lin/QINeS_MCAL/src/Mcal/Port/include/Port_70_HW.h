/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Port_70_HW.h                                                 */
/* Version     : v1.00.00                                                     */
/* Contents    : PORT Module wrapper header                                   */
/*               The PORT is a basic software module at the service           */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of PORT Driver                                               */
/* R22-11                                                                     */
#ifndef PORT_70_HW_H
#define PORT_70_HW_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Port_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define PORT_70_VENDOR_ID_HW_H                ( 70U )
#define PORT_70_MODULE_ID_HW_H                (124U )

#define PORT_70_AR_RELEASE_MAJOR_VERSION_HW_H ( 22U )
#define PORT_70_AR_RELEASE_MINOR_VERSION_HW_H ( 11U )
#define PORT_70_AR_RELEASE_REVISION_VERSION_HW_H ( 00U )

#define PORT_70_SW_MAJOR_VERSION_HW_H         (  1U )
#define PORT_70_SW_MINOR_VERSION_HW_H         (  0U )
#define PORT_70_SW_PATCH_VERSION_HW_H         (  0U )

/*----------------------------------------------------------------------------*/
/* version check                                                              */
/*----------------------------------------------------------------------------*/
/* Port_70_RL78F2X.h version check start */
#if ( PORT_70_VENDOR_ID_HW_H != PORT_70_VENDOR_ID_RL78F2X_H )
  #error "VENDOR ID for Port_70_HW.h and Port_70_RL78F2X.h are different"
#endif

#if ( PORT_70_MODULE_ID_HW_H != PORT_70_MODULE_ID_RL78F2X_H )
  #error "MODULE ID for Port_70_HW.h and Port_70_RL78F2X.h are different"
#endif

#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_HW_H != PORT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_HW_H != PORT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) || \
      ( PORT_70_AR_RELEASE_REVISION_VERSION_HW_H != PORT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) )
  #error "AUTOSAR Version Numbers of Port_70_HW.h and Port_70_RL78F2X.h are different"
#endif

#if ( ( PORT_70_SW_MAJOR_VERSION_HW_H != PORT_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( PORT_70_SW_MINOR_VERSION_HW_H != PORT_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( PORT_70_SW_PATCH_VERSION_HW_H != PORT_70_SW_PATCH_VERSION_RL78F2X_H ) )
  #error "Software Version Numbers of Port_70_HW.h and Port_70_RL78F2X.h are different"
#endif
/* Port_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* macro function definitions                                  */
/*----------------------------------------------------------------------------*/
#define Port_70_Hw_CommonInit( ConfigPtr )  \
    Port_70_RL78F2X_CommonInit( ( ConfigPtr ) )

#define Port_70_Hw_PortInit( portPtr )      \
    Port_70_RL78F2X_PortInit( ( portPtr ) )

#define Port_70_Hw_SetPinDirection( pin, direction )             \
    Port_70_RL78F2X_SetPinDirection( ( pin ), ( direction ) )

#define Port_70_Hw_RefreshPortDirection( pin, direction )       \
    Port_70_RL78F2X_SetPinDirection( ( pin ), ( direction ) )

#if ( PORT_SET_PIN_MODE_API != FALSE )
#define Port_70_Hw_SetPinMode( pin, mode )                       \
    Port_70_RL78F2X_SetPinMode( ( pin ), ( mode ) )
#endif /* #if ( PORT_SET_PIN_MODE_API != FALSE ) */

#define Port_70_Hw_SetPortBit( portno, xbit, level )            \
    Port_70_RL78F2X_SetBit( PORT_70_RL78F2X_Px( portno ),        \
                           ( xbit ),                            \
                           ( level ) )

#endif  /* #ifndef PORT_70_HW_H */

/* EOF Port_70_HW.h ***********************************************************/