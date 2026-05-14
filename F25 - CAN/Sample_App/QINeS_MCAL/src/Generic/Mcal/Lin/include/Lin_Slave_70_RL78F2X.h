/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : LinSlave_70_RL78F2X.h                                        */
/* Version     : v1.00.02                                                     */
/* Contents    : LIN Slave Module HW dependent header                         */
/*               The LIN is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of LIN Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef LIN_SLAVE_70_RL78F2X_H
#define LIN_SLAVE_70_RL78F2X_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Lin.h"
#include "Lin_70_RL78F2X_HwReg.h"
#include "Lin_70_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define LIN_SLAVE_70_VENDOR_ID_RL78F2X_H                ( 70U )
#define LIN_SLAVE_70_MODULE_ID_RL78F2X_H                ( 82U )

#define LIN_SLAVE_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ( 22U )
#define LIN_SLAVE_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ( 11U )
#define LIN_SLAVE_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ( 00U )

#define LIN_SLAVE_70_SW_MAJOR_VERSION_RL78F2X_H         ( 1U )
#define LIN_SLAVE_70_SW_MINOR_VERSION_RL78F2X_H         ( 0U )
#define LIN_SLAVE_70_SW_PATCH_VERSION_RL78F2X_H         ( 2U )

/*----------------------------------------------------------------------------*/
/* file version checks                                        */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* file version checks                                        */
/*----------------------------------------------------------------------------*/
/*------------------- Lin_70_RL78F2X_HwReg.h version check start --*/
#if ( LIN_SLAVE_70_VENDOR_ID_RL78F2X_H != LIN_70_VENDOR_ID_RL78F2X_HWREG_H )
  #error "VENDOR ID for Lin_70_RL78F2X.h and Lin_70_RL78F2X_HwReg.h are different"
#endif

#if ( LIN_SLAVE_70_MODULE_ID_RL78F2X_H != LIN_70_MODULE_ID_RL78F2X_HWREG_H )
  #error "MODULE ID for Lin_70_RL78F2X.h and Lin_70_RL78F2X_HwReg.h are different"
#endif

#if ( ( LIN_SLAVE_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H != LIN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_HWREG_H ) || \
      ( LIN_SLAVE_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H != LIN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_HWREG_H ) || \
      ( LIN_SLAVE_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != LIN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_HWREG_H ) )
  #error "AUTOSAR Version Numbers of Lin_70_RL78F2X.h and Lin_70_RL78F2X_HwReg.h are different"
#endif

#if ( ( LIN_SLAVE_70_SW_MAJOR_VERSION_RL78F2X_H != LIN_70_SW_MAJOR_VERSION_RL78F2X_HWREG_H ) || \
      ( LIN_SLAVE_70_SW_MINOR_VERSION_RL78F2X_H != LIN_70_SW_MINOR_VERSION_RL78F2X_HWREG_H ) || \
      ( LIN_SLAVE_70_SW_PATCH_VERSION_RL78F2X_H != LIN_70_SW_PATCH_VERSION_RL78F2X_HWREG_H ) )
  #error "Software Version Numbers of Lin_70_RL78F2X.h and Lin_70_RL78F2X_HwReg.h are different"
#endif

/*------------------- Lin_70_Types.h version check start -------------------*/
#if ( LIN_SLAVE_70_VENDOR_ID_RL78F2X_H  != LIN_70_VENDOR_ID_TYPES_H )
  #error "VENDOR ID for Lin_70_RL78F2X.h and Lin_70_Types.h are different"
#endif

#if ( LIN_SLAVE_70_MODULE_ID_RL78F2X_H != LIN_70_MODULE_ID_TYPES_H )
  #error "MODULE ID for Lin_70_RL78F2X.h and Lin_70_Types.h are different"
#endif

#if ( ( LIN_SLAVE_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H != LIN_70_AR_RELEASE_MAJOR_VERSION_TYPES_H ) || \
      ( LIN_SLAVE_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H != LIN_70_AR_RELEASE_MINOR_VERSION_TYPES_H ) || \
      ( LIN_SLAVE_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != LIN_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) )
  #error "AUTOSAR Version Numbers of Lin_70_RL78F2X.h and Lin_70_Types.h are different"
#endif

#if ( ( LIN_SLAVE_70_SW_MAJOR_VERSION_RL78F2X_H != LIN_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( LIN_SLAVE_70_SW_MINOR_VERSION_RL78F2X_H != LIN_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( LIN_SLAVE_70_SW_PATCH_VERSION_RL78F2X_H != LIN_70_SW_PATCH_VERSION_TYPES_H ) )
  #error "Software Version Numbers of Lin_70_RL78F2X.h and Lin_70_Types.h are different"
#endif

/*----------------------------------------------------------------------------*/
/* type definitions                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                     */
/*----------------------------------------------------------------------------*/

/* Macros for setting bits of Hw registers */

/* bit mask settings for enabling interrupt services for LIN */

/*----------------------------------------------------------------------------*/
/* function prototype declarations                             */
/*----------------------------------------------------------------------------*/
void Lin_70_RL78F2X_SlvInit( uint8 chIndex );
void Lin_70_RL78F2X_SlaveIsrTx( uint8 chIndex );
void Lin_70_RL78F2X_SlaveIsrRx( uint8 chIndex );
void Lin_70_RL78F2X_SlaveIsrError( uint8 chIndex );

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                             */
/*----------------------------------------------------------------------------*/

#endif /* LIN_SLAVE_70_RL78F2X_H */
/* EOF Lin_70_RL78F2X.h *******************************************/
