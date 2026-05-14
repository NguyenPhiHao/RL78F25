/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Dio_70_Hw.h                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : DIO Module wrapper header                                    */
/*               The DIO is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of DIO Module wrapper header                                 */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef DIO_70_HW_H
#define DIO_70_HW_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Dio_70_Types.h"
#include "Port_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define DIO_70_VENDOR_ID_HW_H                    (70U)
#define DIO_70_MODULE_ID_HW_H                    (120U)

#define DIO_70_AR_RELEASE_MAJOR_VERSION_HW_H     (22U)
#define DIO_70_AR_RELEASE_MINOR_VERSION_HW_H     (11U)
#define DIO_70_AR_RELEASE_REVISION_VERSION_HW_H  (0U)

#define DIO_70_SW_MAJOR_VERSION_HW_H             (1U)
#define DIO_70_SW_MINOR_VERSION_HW_H             (0U)
#define DIO_70_SW_PATCH_VERSION_HW_H             (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Dio_70_Types.h version check start */
#if ( DIO_70_VENDOR_ID_HW_H != DIO_70_VENDOR_ID_TYPES_H )
#   error "VENDOR ID for Dio_70_Hw.h and Dio_70_Types.h are different"
#endif

#if ( DIO_70_MODULE_ID_HW_H != DIO_70_MODULE_ID_TYPES_H )
#   error "MODULE ID for Dio_70_Hw.h and Dio_70_Types.h are different"
#endif

#if ( ( DIO_70_AR_RELEASE_MAJOR_VERSION_HW_H    != DIO_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( DIO_70_AR_RELEASE_MINOR_VERSION_HW_H    != DIO_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( DIO_70_AR_RELEASE_REVISION_VERSION_HW_H != DIO_70_AR_RELEASE_REVISION_VERSION_TYPES_H )  \
    )
#   error "AUTOSAR Version Numbers of Dio_70_Hw.h and Dio_70_Types.h are different"
#endif

#if ( ( DIO_70_SW_MAJOR_VERSION_HW_H != DIO_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( DIO_70_SW_MINOR_VERSION_HW_H != DIO_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( DIO_70_SW_PATCH_VERSION_HW_H != DIO_70_SW_PATCH_VERSION_TYPES_H )            \
    )
#   error "Software Version Numbers of Dio_70_Hw.h and Dio_70_Types.h are different"
#endif

/* Port_70_RL78F2X.h version check start */
#if ( ( DIO_70_AR_RELEASE_MAJOR_VERSION_HW_H != PORT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( DIO_70_AR_RELEASE_MINOR_VERSION_HW_H != PORT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H )    \
    )
#   error "AUTOSAR Version Numbers of Dio_70_Hw.h and Port_70_RL78F2X.h are different"
#endif
/* Port_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* macros for calling port processing                                         */
/*----------------------------------------------------------------------------*/
#if ( DIO_DEV_ERROR_DETECT != FALSE )
#   define Dio_70_HW_ChannelCheck        Port_70_RL78F2X_CheckPortSfrXbit
#   define Dio_70_HW_PortCheck           Port_70_RL78F2X_CheckPortSfr
#   define Dio_70_HW_ChannelGroupCheck   Port_70_RL78F2X_CheckPortSfrMask
#endif  /* if ( DIO_DEV_ERROR_DETECT != FALSE ) */

#define Dio_70_HW_ReadChannel( pno, bps ) \
    Port_70_RL78F2X_GetBit( PORT_70_RL78F2X_DIO_Px( pno ), ( bps ) )

#define Dio_70_HW_ReadPort( pno ) \
    Port_70_RL78F2X_GetReg( PORT_70_RL78F2X_DIO_Px( pno ) )

#define Dio_70_HW_WriteChannel( pno, xbt, lvl ) \
    Port_70_RL78F2X_SetBit( PORT_70_RL78F2X_DIO_Px( pno ), ( xbt ), ( lvl ) )

#define Dio_70_HW_WritePort( pno, lvl ) \
    Port_70_RL78F2X_SetReg( PORT_70_RL78F2X_DIO_Px( pno ), ( lvl ) )

#define Dio_70_HW_FlipChannel( pno, xbt ) \
    Port_70_RL78F2X_FlipBit( PORT_70_RL78F2X_DIO_Px( pno ), ( xbt ) )

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/* [SWS_Dio_00137] */
extern Dio_PortLevelType
    Dio_70_HW_ReadChannelGroup( Dio_PortType portId, uint8 offset, Dio_70_PortMaskType mask );

/* [SWS_Dio_00138] */
extern void Dio_70_HW_WriteChannelGroup( Dio_PortLevelType Level, Dio_PortType portId, \
    uint8 offset, Dio_70_PortMaskType mask );

#if ( DIO_MASKED_WRITE_PORT_API != FALSE )
/* [SWS_Dio_00300] */
extern void Dio_70_HW_MaskedWritePort( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask );
#endif /* #if ( DIO_MASKED_WRITE_PORT_API != FALSE ) */

#endif /* #ifndef DIO_70_HW_H */

/* EOF Dio_70_Hw.h ************************************************************/
