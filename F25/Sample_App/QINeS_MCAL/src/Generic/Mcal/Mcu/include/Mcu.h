/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Mcu.h                                                        */
/* Version     : v1.00.00                                                     */
/* Contents    : Mcu Module header                                            */
/*               The MCU is a basic software module at the service            */
/*               layer of the standardized basic software architecture        */
/*               of AUTOSAR.                                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of MCU Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef MCU_H
#define MCU_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Mcu_Cfg.h"

#include "Mcu_70_HW.h"

#if ( MCU_GET_RAM_STATE_API != FALSE )
#include "Mcu_70_Irq.h"
#endif /* #if ( MCU_GET_RAM_STATE_API != FALSE ) */

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define MCU_MODULE_ID                       ( 101U )
#define MCU_VENDOR_ID                       (  70U )

#define MCU_AR_RELEASE_MAJOR_VERSION        ( 22U )
#define MCU_AR_RELEASE_MINOR_VERSION        ( 11U )
#define MCU_AR_RELEASE_REVISION_VERSION     ( 00U )

#define MCU_SW_MAJOR_VERSION                (  1U )
#define MCU_SW_MINOR_VERSION                (  0U )
#define MCU_SW_PATCH_VERSION                (  0U )

/*----------------------------------------------------------------------------*/
/* version check                                               */
/*----------------------------------------------------------------------------*/
/* Check if source file and Mcu_70_HW.h header file are of the same vendor */
#if ( MCU_VENDOR_ID != MCU_70_VENDOR_ID_HW_H )
  #error "Mcu.h and Mcu_70_HW.h have different vendor ids"
#endif

/* Check if source file and Mcu_70_HW.h header file are of the same module */
#if ( MCU_MODULE_ID != MCU_70_MODULE_ID_HW_H )
  #error "Mcu.h and Mcu_70_HW.h have different module ids"
#endif

/* Check if source file and Mcu_Cfg header file are of the same Autosar version */
#if ( ( MCU_AR_RELEASE_MAJOR_VERSION      != MCU_70_AR_RELEASE_MAJOR_VERSION_HW_H    ) || \
      ( MCU_AR_RELEASE_MINOR_VERSION      != MCU_70_AR_RELEASE_MINOR_VERSION_HW_H    ) || \
      ( MCU_AR_RELEASE_REVISION_VERSION   != MCU_70_AR_RELEASE_REVISION_VERSION_HW_H ) )
  #error "AUTOSAR Version Numbers of Mcu.h and Mcu_70_HW.h are different"
#endif

/* Check if source file and Mcu_Cfg header file are of the same Software version */
#if ( ( MCU_SW_MAJOR_VERSION != MCU_70_SW_MAJOR_VERSION_HW_H ) || \
      ( MCU_SW_MINOR_VERSION != MCU_70_SW_MINOR_VERSION_HW_H ) || \
      ( MCU_SW_PATCH_VERSION != MCU_70_SW_PATCH_VERSION_HW_H ) )
  #error "Software Version Numbers of Mcu.h and Mcu_70_HW.h are different"
#endif

/* Check if source file and Mcu_Cfg header file are of the same vendor */
#if ( MCU_VENDOR_ID != MCU_70_VENDOR_ID_CFG_H )
  #error "Mcu.h and Mcu_Cfg.h have different vendor ids"
#endif

/* Check if source file and Mcu_Cfg header file are of the same module */
#if ( MCU_MODULE_ID != MCU_70_MODULE_ID_CFG_H )
  #error "Mcu.h and Mcu_Cfg.h have different module ids"
#endif

/* Check if source file and Mcu_Cfg header file are of the same Autosar version */
#if ( ( MCU_AR_RELEASE_MAJOR_VERSION    != MCU_70_AR_RELEASE_MAJOR_VERSION_CFG_H    ) || \
      ( MCU_AR_RELEASE_MINOR_VERSION    != MCU_70_AR_RELEASE_MINOR_VERSION_CFG_H    ) || \
      ( MCU_AR_RELEASE_REVISION_VERSION != MCU_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
  #error "AUTOSAR Version Numbers of Mcu.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and Mcu_Cfg header file are of the same Software version */
#if ( ( MCU_SW_MAJOR_VERSION != MCU_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( MCU_SW_MINOR_VERSION != MCU_70_SW_MINOR_VERSION_CFG_H ) || \
      ( MCU_SW_PATCH_VERSION != MCU_70_SW_PATCH_VERSION_CFG_H ) )
  #error "Software Version Numbers of Mcu.h and Mcu_Cfg.h are different"
#endif

#if ( MCU_GET_RAM_STATE_API != FALSE )
  /* Check if source file and Mcu_70_Irq header file are of the same vendor */
  #if ( MCU_VENDOR_ID != MCU_70_VENDOR_ID_IRQ_H )
    #error "Mcu.h and Mcu_70_Irq.h have different vendor ids"
  #endif

  /* Check if source file and Mcu_70_Irq header file are of the same module */
  #if ( MCU_MODULE_ID != MCU_70_MODULE_ID_IRQ_H )
    #error "Mcu.h and Mcu_70_Irq.h have different module ids"
  #endif

/* Check if source file and Mcu_Cfg header file are of the same Autosar version */
#if ( ( MCU_AR_RELEASE_MAJOR_VERSION    != MCU_70_AR_RELEASE_MAJOR_VERSION_IRQ_H ) || \
      ( MCU_AR_RELEASE_MINOR_VERSION    != MCU_70_AR_RELEASE_MINOR_VERSION_IRQ_H ) || \
      ( MCU_AR_RELEASE_REVISION_VERSION != MCU_70_AR_RELEASE_REVISION_VERSION_IRQ_H ) )
  #error "AUTOSAR Version Numbers of Mcu.h and Mcu_70_Irq.h are different"
#endif

/* Check if source file and Mcu_Cfg header file are of the same Software version */
#if ( ( MCU_SW_MAJOR_VERSION != MCU_70_SW_MAJOR_VERSION_IRQ_H ) || \
      ( MCU_SW_MINOR_VERSION != MCU_70_SW_MINOR_VERSION_IRQ_H ) || \
      ( MCU_SW_PATCH_VERSION != MCU_70_SW_PATCH_VERSION_IRQ_H ) )
  #error "Software Version Numbers of Mcu.h and Mcu_70_Irq.h are different"
#endif
#endif  /* #if ( MCU_GET_RAM_STATE_API != FALSE ) */

/*----------------------------------------------------------------------------*/
/* macros                                                     */
/*----------------------------------------------------------------------------*/
#define MCU_70_INSTANCE_ID                ( 0U )

/* API service ID */
/* [SWS_Mcu_00153] */
#define MCU_INIT_ID                       ( 0x00U )
/* [SWS_Mcu_00154] */
#define MCU_INITRAMSECTION_ID             ( 0x01U )
/* [SWS_Mcu_00155] */
#define MCU_INITCLOCK_ID                  ( 0x02U )
/* [SWS_Mcu_00156] */
#define MCU_DISTRIBUTEPLLCLK_ID           ( 0x03U )
/* [SWS_Mcu_00157] */
#define MCU_GETPLLSTATUS_ID               ( 0x04U )
/* [SWS_Mcu_00158] */
#define MCU_GETRESETREASON_ID             ( 0x05U )
/* [SWS_Mcu_00159] */
#define MCU_GETRESETRAWVALUE_ID           ( 0x06U )
/* [SWS_Mcu_00161] */
#define MCU_SETMODE_ID                    ( 0x08U )
/* [SWS_Mcu_00162] */
#define MCU_GETVERSIONINFO_ID             ( 0x09U )
/* [SWS_Mcu_00207] */
#define MCU_GETRAMSTATE_ID                ( 0x0AU )

/* The following errors and exceptions shall be detectable by the MCU module. */
/* [SWS_Mcu_00012] */
#define MCU_E_PARAM_CONFIG             ( 0x0AU )
/* [SWS_Mcu_00012] */
#define MCU_E_PARAM_CLOCK              ( 0x0BU )
/* [SWS_Mcu_00012] */
#define MCU_E_PARAM_MODE               ( 0x0CU )
/* [SWS_Mcu_00012] */
#define MCU_E_PARAM_RAMSECTION         ( 0x0DU )
/* [SWS_Mcu_00012] */
#define MCU_E_PLL_NOT_LOCKED           ( 0x0EU )
/* [SWS_Mcu_00012] */
#define MCU_E_UNINIT                   ( 0x0FU )
/* [SWS_Mcu_00012] */
#define MCU_E_PARAM_POINTER            ( 0x10U )
/* [SWS_Mcu_00012] */
#define MCU_E_INIT_FAILED              ( 0x11U )

/* ADD RL78 specific error code */
#define MCU_E_70_PLL_FAIL              ( 0x20U )   /* PLLSELS is not change */

/* Reset define */
#define MCU_70_RESF_WDCLRF             ( 0x10U )   /* for RESET WDCLRF (1:WDT or clock monitor.) */
#define MCU_70_RESF_SWRESF             ( 0x08U )   /* S/W reset */
#define MCU_70_POCRES_POCRES0          ( 0x01U )   /* for POCRES POCRES0 (0:power-on reset) */

/* Mcu Ram Section Write Size */
#define MCU_8BIT_SIZE                  ( 0x00U )
#define MCU_16BIT_SIZE                 ( 0x01U )

/*----------------------------------------------------------------------------*/
/* type definitions                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                        */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/* configuration data in Mcu_PBcfg.c */
extern const Mcu_ConfigType Mcu_Config;
extern Mcu_ClockReferencePointType McuClockReferencePointRef[ MCU_70_NUM_OF_REFERENCE_POINT ];

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                           */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"

/* [SWS_Mcu_00153] */
extern void Mcu_Init( const Mcu_ConfigType* ConfigPtr );

/* [SWS_Mcu_00154] */
extern Std_ReturnType Mcu_InitRamSection( Mcu_RamSectionType RamSection );

/* [SWS_Mcu_00155] */
#if ( MCU_INIT_CLOCK != FALSE )
extern Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting );
#endif /* #if ( MCU_INIT_CLOCK != FALSE ) */

/* [SWS_Mcu_00156] */
#if ( MCU_NO_PLL == FALSE )
extern Std_ReturnType Mcu_DistributePllClock( void );
#endif /* #if ( MCU_NO_PLL == FALSE ) */

/* [SWS_Mcu_00157] */
extern Mcu_PllStatusType Mcu_GetPllStatus( void );

/* [SWS_Mcu_00158] */
extern Mcu_ResetType Mcu_GetResetReason( void );

/* [SWS_Mcu_00159] */
extern Mcu_RawResetType Mcu_GetResetRawValue( void );

/* [SWS_Mcu_00160] */
#if ( MCU_PERFORM_RESET_API != FALSE )
extern void Mcu_PerformReset( void );
#endif /* #if ( MCU_PERFORM_RESET_API != FALSE ) */

/* [SWS_Mcu_00161] */
extern void Mcu_SetMode( Mcu_ModeType McuMode );

/* [SWS_Mcu_00162] */
#if ( MCU_VERSION_INFO_API != FALSE )
extern void Mcu_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif /* #if ( MCU_VERSION_INFO_API != FALSE ) */

/* [SWS_Mcu_00207] */
#if ( MCU_GET_RAM_STATE_API != FALSE )
extern Mcu_RamStateType Mcu_GetRamState( void );
#endif /* #if ( MCU_GET_RAM_STATE_API != FALSE ) */

#define MCU_STOP_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"

#endif /* #ifndef MCU_H */

/* EOF Mcu.h ***********************************************/
