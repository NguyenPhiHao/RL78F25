/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Dio_70_Types.h                                               */
/* Version     : v1.00.00                                                     */
/* Contents    : DIO Module type definition header                            */
/*               The DIO is a basic software module at the service            */
/*               layer of the standardized basic software                     */
/*               architecture of AUTOSAR.                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of DIO Module type definition header                         */
/* R22-11                                                                     */
#ifndef DIO_70_TYPES_H_
#define DIO_70_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define DIO_70_VENDOR_ID_TYPES_H            ( 70U )
#define DIO_70_MODULE_ID_TYPES_H            ( 120U )

#define DIO_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    ( 22U )
#define DIO_70_AR_RELEASE_MINOR_VERSION_TYPES_H    ( 11U )
#define DIO_70_AR_RELEASE_REVISION_VERSION_TYPES_H (  0U )

#define DIO_70_SW_MAJOR_VERSION_TYPES_H      ( 1U )
#define DIO_70_SW_MINOR_VERSION_TYPES_H      ( 0U )
#define DIO_70_SW_PATCH_VERSION_TYPES_H      ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */
#if ( ( DIO_70_AR_RELEASE_MAJOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( DIO_70_AR_RELEASE_MINOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MINOR_VERSION ) )
# error "AUTOSAR Version Numbers of Dio_70_Types.h and Std_Types.h are different"
#endif

/* Std_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef uint8 Dio_70_PortMaskType;    /* Use Dio_ChannelConfigurationType.DioMask */
typedef uint8 Dio_70_PortBitPosType;  /* Return value of DIO_70_PIN_TO_BITPOS(chId) macro */

typedef uint8 Dio_ChannelType;        /* [SWS_Dio_00182] */
typedef uint8 Dio_PortType;           /* [SWS_Dio_00183] */
typedef uint8 Dio_LevelType;          /* [SWS_Dio_00185] */
typedef uint8 Dio_PortLevelType;      /* [SWS_Dio_00184] */

#endif /* #ifndef DIO_70_TYPES_H_ */

/* EOF Dio_70_Types.h */
