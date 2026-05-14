/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Port_70_RL78F2X.h                                            */
/* Version     : v1.00.00                                                     */
/* Contents    : PORT Module HW dependent header                              */
/*               The PORT is a basic software module at the service layer of  */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of PORT Driver                                               */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef PORT_70_RL78F2X_H_
#define PORT_70_RL78F2X_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Port_70_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define PORT_70_VENDOR_ID_RL78F2X_H                   ( 70U )
#define PORT_70_MODULE_ID_RL78F2X_H                   ( 124U )

#define PORT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H    ( 22U )
#define PORT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H    ( 11U )
#define PORT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ( 0U )

#define PORT_70_SW_MAJOR_VERSION_RL78F2X_H            ( 1U )
#define PORT_70_SW_MINOR_VERSION_RL78F2X_H            ( 0U )
#define PORT_70_SW_PATCH_VERSION_RL78F2X_H            ( 0U )

/*----------------------------------------------------------------------------*/
/* version check                                                              */
/*----------------------------------------------------------------------------*/
/* Port_70_Types.h version check start */

#if ( PORT_70_VENDOR_ID_RL78F2X_H != PORT_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Port_70_RL78F2X_Types.h and Port_70_Types.h are different"
#endif

#if ( PORT_70_MODULE_ID_RL78F2X_H != PORT_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Port_70_RL78F2X_Types.h and Port_70_Types.h are different"
#endif

#if ( ( PORT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H \
        != PORT_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( PORT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H \
        != PORT_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( PORT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H \
        != PORT_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Port_70_RL78F2X_Types.h and Port_70_Types.h are different"
#endif

#if ( ( PORT_70_SW_MAJOR_VERSION_RL78F2X_H != PORT_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( PORT_70_SW_MINOR_VERSION_RL78F2X_H != PORT_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( PORT_70_SW_PATCH_VERSION_RL78F2X_H != PORT_70_SW_PATCH_VERSION_TYPES_H ) \
    )
    #error "Software Version Numbers of Port_70_RL78F2X_Types.h and Port_70_Types.h are different"
#endif

/* Port_70_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
/* Used in Port module */
extern void Port_70_RL78F2X_CommonInit ( const Port_ConfigType* ConfigPtr );
extern void Port_70_RL78F2X_PortInit ( const Port_PortPinType* portPtr );
extern void Port_70_RL78F2X_SetPinDirection( Port_PinType pin, Port_PinDirectionType direction );

#if ( PORT_SET_PIN_MODE_API != FALSE )
extern void Port_70_RL78F2X_SetPinMode( Port_PinType pin, Port_PinModeType mode );
#endif /* #if ( PORT_SET_PIN_MODE_API != FALSE ) */

/* Used in Port, Dio, Spi module */
extern void Port_70_RL78F2X_SetBit( uint16 address, uint8 xbit, uint8 value );

/* Used in Dio module */
extern void Port_70_RL78F2X_SetReg( uint16 address, uint8 value );
extern uint8 Port_70_RL78F2X_FlipBit( uint16 address, uint8 xbit );
extern uint8 Port_70_RL78F2X_GetReg( uint16 address );
extern uint8 Port_70_RL78F2X_GetBit( uint16 address, uint8 xbit );

extern uint8 Port_70_RL78F2X_CheckPortSfr( uint8 portno );
extern uint8 Port_70_RL78F2X_CheckPortSfrXbit( uint8 portno, uint8 xbit );
extern uint8 Port_70_RL78F2X_CheckPortSfrMask( uint8 portno, uint8 mask );

#endif /* #ifndef PORT_70_RL78F2X_H_ */

/* EOF Port_70_RL78F2X.h *****************************************************/
