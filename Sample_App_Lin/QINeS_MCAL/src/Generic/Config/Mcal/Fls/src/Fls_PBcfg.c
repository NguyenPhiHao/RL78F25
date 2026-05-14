/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Fls_PBcfg.c                                                  */
/* Version     : v1.00.01                                                     */
/* Contents    : This document specifies the functionality, API and the       */
/*               configuration of the AUTOSAR Basic Software module Flash     */
/*               Driver.                                                      */
/*               This specification is applicable to drivers for both         */
/*               internal and external flash memory.                          */
/*               The flash driver provides services for reading, writing and  */
/*               erasing flash memory and a configuration interface for       */
/*               setting / resetting the write / erase protection if          */
/*               supported by the underlying hardware.                        */
/*               In application mode of the ECU, the flash driver is only to  */
/*               be used by the Flash EEPROM emulation module for writing     */
/*               data. It is not intended to write program code to flash      */
/*               memory in application mode. This shall be done in boot mode  */
/*               which is out of scope of AUTOSAR.                            */
/*               A driver for an internal flash memory accesses the           */
/*               microcontroller hardware directly and is located in the      */
/*               Microcontroller Abstraction Layer. An external flash memory  */
/*               is usually connected via the microcontroller's data /        */
/*               address busses (memory mapped access), the flash driver then */
/*               uses the handlers / drivers for those busses to access the   */
/*               external flash memory device. The driver for an external     */
/*               flash memory device is located in the ECU Abstraction Layer. */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Flash Driver                                              */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Fls.h"
#include "Fee_Cbk.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define FLS_70_VENDOR_ID_PBCFG_C                       ( 70U )
#define FLS_70_MODULE_ID_PBCFG_C                       ( 92U )

#define FLS_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C        ( 22U )
#define FLS_70_AR_RELEASE_MINOR_VERSION_PBCFG_C        ( 11U )
#define FLS_70_AR_RELEASE_REVISION_VERSION_PBCFG_C     ( 0U )

#define FLS_70_SW_MAJOR_VERSION_PBCFG_C                ( 1U )
#define FLS_70_SW_MINOR_VERSION_PBCFG_C                ( 0U )
#define FLS_70_SW_PATCH_VERSION_PBCFG_C                ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Fls.h version check start */

#if ( FLS_70_VENDOR_ID_PBCFG_C != FLS_VENDOR_ID )
    #error "VENDOR ID for Fls_PBcfg.c and Fls.h are different"
#endif

#if ( FLS_70_MODULE_ID_PBCFG_C != FLS_MODULE_ID )
    #error "MODULE ID for Fls_PBcfg.c and Fls.h are different"
#endif

#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != FLS_AR_RELEASE_MAJOR_VERSION ) || \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_PBCFG_C    != FLS_AR_RELEASE_MINOR_VERSION ) || \
      ( FLS_70_AR_RELEASE_REVISION_VERSION_PBCFG_C != FLS_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif

#if ( ( FLS_70_SW_MAJOR_VERSION_PBCFG_C != FLS_SW_MAJOR_VERSION ) || \
      ( FLS_70_SW_MINOR_VERSION_PBCFG_C != FLS_SW_MINOR_VERSION ) || \
      ( FLS_70_SW_PATCH_VERSION_PBCFG_C != FLS_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif

/* Fls.h version check end */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* Fee_Cbk.h version check start */

#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_PBCFG_C != FEE_AR_RELEASE_MAJOR_VERSION ) || \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_PBCFG_C != FEE_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Fls_PBcfg.c and Fee_Cbk.h are different"
#endif

/* Fee_Cbk.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

/* FlsConfig (1) */
const Fls_ConfigType FlsConfigData = {
    /* FlsConfigSet (1) */
    {
        FLS_AC_ERASE,                          /* FlsAcErase (1) */
        FLS_AC_WRITE,                          /* FlsAcWrite (1) */
        FLS_DEFAULT_MODE,                      /* FlsDefaultMode (1) */
        FLS_JOB_END_NOTIFICATION,              /* FlsJobEndNotification (0..1) */
        FLS_JOB_ERROR_NOTIFICATION,            /* FlsJobErrorNotification (0..1) */
        FLS_MAX_READ_FAST_MODE,                /* FlsMaxReadFastMode (1) */
        FLS_MAX_READ_NORMAL_MODE,              /* FlsMaxReadNormalMode (1) */
        FLS_MAX_WRITE_FAST_MODE,               /* FlsMaxWriteFastMode (1) */
        FLS_MAX_WRITE_NORMAL_MODE,             /* FlsMaxWriteNormalMode (1) */
        FLS_PROTECTION,                        /* FlsProtection (1) */
        /* FlsSectorList */
        {
            /* FlsSector */
            {
                /* FlsSector[0] */
                {
                    0x0008U,                    /* FlsNumberOfSectors */
                    0x0001U,                    /* FlsPageSize */
                    0x0400U,                    /* FlsSectorSize */
                    ( Fls_LengthType )0xF1000U  /* FlsSectorStartaddress */
                }
            }
        }
    }
};

#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/* EOF Fls_PBcfg.c ************************************************************/
