/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Port_70_HW_Types.h                                           */
/* Version     : v1.00.00                                                     */
/* Contents    : PORT Module type definition header                           */
/*               The PORT is a basic software module at the service layer of  */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of PORT Driver                                               */
/******************************************************************************/

#ifndef PORT_70_HW_TYPES_H_
#define PORT_70_HW_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Port_70_RL78F2X_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define PORT_70_VENDOR_ID_HW_TYPES_H                   ( 70U )
#define PORT_70_MODULE_ID_HW_TYPES_H                   ( 124U )

#define PORT_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H    ( 22U )
#define PORT_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H    ( 11U )
#define PORT_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H ( 0U )

#define PORT_70_SW_MAJOR_VERSION_HW_TYPES_H            ( 1U )
#define PORT_70_SW_MINOR_VERSION_HW_TYPES_H            ( 0U )
#define PORT_70_SW_PATCH_VERSION_HW_TYPES_H            ( 0U )

/*----------------------------------------------------------------------------*/
/* version check                                                              */
/*----------------------------------------------------------------------------*/
/* Port_70_RL78F2X_Types.h version check start */

#if ( PORT_70_VENDOR_ID_HW_TYPES_H != PORT_70_VENDOR_ID_RL78F2X_TYPES_H )
    #error "VENDOR ID for Port_70_HW_Types.h and Port_70_RL78F2X_Types.h are different"
#endif

#if ( PORT_70_MODULE_ID_HW_TYPES_H != PORT_70_MODULE_ID_RL78F2X_TYPES_H )
    #error "MODULE ID for Port_70_HW_Types.h and Port_70_RL78F2X_Types.h are different"
#endif

#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H \
        != PORT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H \
        != PORT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( PORT_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H \
        != PORT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Port_70_HW_Types.h and Port_70_RL78F2X_Types.h are different"
#endif

#if ( ( PORT_70_SW_MAJOR_VERSION_HW_TYPES_H != PORT_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( PORT_70_SW_MINOR_VERSION_HW_TYPES_H != PORT_70_SW_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( PORT_70_SW_PATCH_VERSION_HW_TYPES_H != PORT_70_SW_PATCH_VERSION_RL78F2X_TYPES_H ) \
    )
    #error "Software Version Numbers of Port_70_HW_Types.h and Port_70_RL78F2X_Types.h are different"
#endif

/* Port_70_RL78F2X_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef Port_70_RL78F2X_PinSetConfType    Port_70_HW_PinSetConfType;
typedef Port_70_RL78F2X_PinPiorSetType    Port_70_HW_PinPiorSetType;
typedef Port_70_RL78F2X_PinChangeType     Port_70_HW_PinChangeType;

typedef struct {
    const Port_70_HW_PinSetConfType*    Port_70_PinSetConfPtr;
    const Port_70_HW_PinPiorSetType*    Port_70_PinPiorSetPtr;
    const Port_70_HW_PinChangeType*     Port_70_PinChangePtr;
} Port_70_HW_PortPinType;


#endif /* #ifndef PORT_70_HW_TYPES_H_ */

/* EOF Port_70_HW_Types.h ****************************************************/
