/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Dio_PBcfg.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : Dio post build time configuration                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of DIO Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Dio.h"

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define DIO_70_VENDOR_ID_PBCFG_C              ( 70U )
#define DIO_70_MODULE_ID_PBCFG_C              ( 120U )

#define DIO_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C   ( 22U )
#define DIO_70_AR_RELEASE_MINOR_VERSION_PBCFG_C   ( 11U )
#define DIO_70_AR_RELEASE_REVISION_VERSION_PBCFG_C(  0U )

#define DIO_70_SW_MAJOR_VERSION_PBCFG_C           ( 1U )
#define DIO_70_SW_MINOR_VERSION_PBCFG_C           ( 0U )
#define DIO_70_SW_PATCH_VERSION_PBCFG_C           ( 0U )

/*----------------------------------------------------------------------------*/
/* FILE VERSION CHECKS                                                        */
/*----------------------------------------------------------------------------*/
/* Dio.h version check start */
#if ( DIO_70_VENDOR_ID_PBCFG_C != DIO_VENDOR_ID )
  #error "VENDOR ID for Dio_PBcfg.c and Dio.h are different"
#endif

#if ( DIO_70_MODULE_ID_PBCFG_C != DIO_MODULE_ID )
  #error "MODULE ID for Dio_PBcfg.c and Dio.h are different"
#endif

#if ( ( DIO_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C   != DIO_AR_RELEASE_MAJOR_VERSION   ) || \
      ( DIO_70_AR_RELEASE_MINOR_VERSION_PBCFG_C   != DIO_AR_RELEASE_MINOR_VERSION   ) || \
      ( DIO_70_AR_RELEASE_REVISION_VERSION_PBCFG_C!= DIO_AR_RELEASE_REVISION_VERSION) )
  #error "AUTOSAR Version Numbers of Dio_PBcfg.c and Dio.h are different"
#endif

#if ( ( DIO_70_SW_MAJOR_VERSION_PBCFG_C != DIO_SW_MAJOR_VERSION ) || \
      ( DIO_70_SW_MINOR_VERSION_PBCFG_C != DIO_SW_MINOR_VERSION ) || \
      ( DIO_70_SW_PATCH_VERSION_PBCFG_C != DIO_SW_PATCH_VERSION )   \
    )
  #error "Software Version Numbers of Dio_PBcfg.c and Dio.h are different"
#endif

#if ( ( DIO_70_SW_MAJOR_VERSION_PBCFG_C != DIO_SW_MAJOR_VERSION ) || \
      ( DIO_70_SW_MINOR_VERSION_PBCFG_C != DIO_SW_MINOR_VERSION ) || \
      ( DIO_70_SW_PATCH_VERSION_PBCFG_C != DIO_SW_PATCH_VERSION )   \
    )
  #error "Software Version Numbers of Dio_PBcfg.c and Dio.h are different"
#endif

/* Dio.h version check end */

/* Dio_Cfg.h version check start */

#if ( DIO_70_VENDOR_ID_PBCFG_C != DIO_70_VENDOR_ID_CFG_H )
  #error "VENDOR_ID for Dio_PBcfg.c and Dio_Cfg.h are different"
#endif

#if ( DIO_70_MODULE_ID_PBCFG_C != DIO_70_MODULE_ID_CFG_H )
  #error "MODULE ID for Dio_PBcfg.c and Dio_Cfg.h are different"
#endif

#if ( ( DIO_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != DIO_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( DIO_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != DIO_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( DIO_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != DIO_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
  #error "AUTOSAR Version Numbers of Dio_PBcfg.c and Dio_Cfg.h are different"
#endif

#if ( ( DIO_70_SW_MAJOR_VERSION_PBCFG_C != DIO_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( DIO_70_SW_MINOR_VERSION_PBCFG_C != DIO_70_SW_MINOR_VERSION_CFG_H ) || \
      ( DIO_70_SW_PATCH_VERSION_PBCFG_C != DIO_70_SW_PATCH_VERSION_CFG_H )   \
    )
  #error "Software Version Numbers of Dio_PBcfg.c and Dio_Cfg.h are different"
#endif

/* Dio_Cfg.h version check end */

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"

#if ( 0U != DIO_70_NUM_OF_DIOCHANNELGROUP )
const Dio_ChannelGroupType DioChannelGroupData[ DIO_70_NUM_OF_DIOCHANNELGROUP ] = {
    {
        DIO_70_PORT_P08,    /* DioChannelGroupIdentification */
        0x0cU,              /* MASK */
        2U                  /* OFFSET */
    }
};
#endif

#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"

/* EOF Dio_PBcfg.c ************************************************************/
