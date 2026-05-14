/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Dio_Cfg.c                                                    */
/* Version     : v1.00.00                                                     */
/* Contents    : Dio precompile time configuration                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Dio Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Dio.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define DIO_70_VENDOR_ID_CFG_C                (70U)
#define DIO_70_MODULE_ID_CFG_C                (120U)

#define DIO_70_AR_RELEASE_MAJOR_VERSION_CFG_C (22U)
#define DIO_70_AR_RELEASE_MINOR_VERSION_CFG_C (11U)
#define DIO_70_AR_RELEASE_REVISION_VERSION_CFG_C (0U)

#define DIO_70_SW_MAJOR_VERSION_CFG_C         (1U)
#define DIO_70_SW_MINOR_VERSION_CFG_C         (0U)
#define DIO_70_SW_PATCH_VERSION_CFG_C         (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Dio.h version check start */
#if ( DIO_70_VENDOR_ID_CFG_C != DIO_VENDOR_ID )
  #error "VENDOR ID for Dio_Cfg.c and Dio.h are different"
#endif

#if ( DIO_70_MODULE_ID_CFG_C != DIO_MODULE_ID )
  #error "MODULE ID for Dio_Cfg.c and Dio.h are different"
#endif

#if ( ( DIO_70_AR_RELEASE_MAJOR_VERSION_CFG_C    != DIO_AR_RELEASE_MAJOR_VERSION )   || \
      ( DIO_70_AR_RELEASE_MINOR_VERSION_CFG_C    != DIO_AR_RELEASE_MINOR_VERSION )   || \
      ( DIO_70_AR_RELEASE_REVISION_VERSION_CFG_C != DIO_AR_RELEASE_REVISION_VERSION ) )
  #error "AUTOSAR Version Numbers of Dio_Cfg.c and Dio.h are different"
#endif

#if ( ( DIO_70_SW_MAJOR_VERSION_CFG_C != DIO_SW_MAJOR_VERSION ) || \
      ( DIO_70_SW_MINOR_VERSION_CFG_C != DIO_SW_MINOR_VERSION ) || \
      ( DIO_70_SW_PATCH_VERSION_CFG_C != DIO_SW_PATCH_VERSION )   \
    )
  #error "Software Version Numbers of Dio_Cfg.c and Dio.h are different"
#endif

/* Dio.h version check end */

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/* End Of File */
