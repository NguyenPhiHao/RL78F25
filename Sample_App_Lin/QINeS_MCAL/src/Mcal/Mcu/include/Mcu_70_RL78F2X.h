/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Mcu_70_RL78F2X.h                                             */
/* Version     : v1.00.01                                                     */
/* Contents    : MCU Module HW dependent header                               */
/*               The MCU is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : -                                                            */
/******************************************************************************/
/* Specification of MCU Driver                                                */
/* Release R22-11                                                             */
 
#ifndef MCU_70_RL78F2X_H_
#define MCU_70_RL78F2X_H_
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Mcu_70_Types.h"
#include "Mcu_70_RL78F2X_Types.h"
 
/*----------------------------------------------------------------------------*/
/* Source File Version Information                                            */
/*----------------------------------------------------------------------------*/
#define MCU_70_MODULE_ID_RL78F2X_H                     ( 101U )
#define MCU_70_VENDOR_ID_RL78F2X_H                     ( 70U )
 
#define MCU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H      ( 22U )
#define MCU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H      ( 11U )
#define MCU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H   ( 0U )
 
#define MCU_70_SW_MAJOR_VERSION_RL78F2X_H              ( 1U )
#define MCU_70_SW_MINOR_VERSION_RL78F2X_H              ( 0U )
#define MCU_70_SW_PATCH_VERSION_RL78F2X_H              ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Mcu_70_Types.h version check start */
#if ( MCU_70_VENDOR_ID_RL78F2X_H != MCU_70_VENDOR_ID_TYPES_H )
    #error "VENDOR ID for Mcu_70_RL78F2X.h and Mcu_70_Types.h is different"
#endif
 
#if ( MCU_70_MODULE_ID_RL78F2X_H != MCU_70_MODULE_ID_TYPES_H )
    #error "MODULE ID for Mcu_70_RL78F2X.h and Mcu_70_Types.h is different"
#endif
 
#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H    != MCU_70_AR_RELEASE_MAJOR_VERSION_TYPES_H )  ||   \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H    != MCU_70_AR_RELEASE_MINOR_VERSION_TYPES_H )  ||   \
      ( MCU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != MCU_70_AR_RELEASE_REVISION_VERSION_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Mcu_70_RL78F2X.h and Mcu_70_Types.h are different"
#endif
 
#if ( ( MCU_70_SW_MAJOR_VERSION_RL78F2X_H != MCU_70_SW_MAJOR_VERSION_TYPES_H ) || \
      ( MCU_70_SW_MINOR_VERSION_RL78F2X_H != MCU_70_SW_MINOR_VERSION_TYPES_H ) || \
      ( MCU_70_SW_PATCH_VERSION_RL78F2X_H != MCU_70_SW_PATCH_VERSION_TYPES_H )    \
    )
    #error "Software Version Numbers of Mcu_70_RL78F2X.h and Mcu_70_Types.h are different"
#endif
/* Mcu_70_Types.h version check end */
 
/* Mcu_70_RL78F2X_Types.h version check start */
#if ( MCU_70_VENDOR_ID_RL78F2X_H != MCU_70_VENDOR_ID_RL78F2X_TYPES_H )
    #error "VENDOR ID for Mcu_70_RL78F2X.h and Mcu_70_RL78F2X_Types.h is different"
#endif
 
#if ( MCU_70_MODULE_ID_RL78F2X_H != MCU_70_MODULE_ID_RL78F2X_TYPES_H )
    #error "MODULE ID for Mcu_70_RL78F2X.h and Mcu_70_RL78F2X_Types.h is different"
#endif
 
#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H    != MCU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H )  ||   \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H    != MCU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H )  ||   \
      ( MCU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != MCU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H ) \
    )
    #error "AUTOSAR Version Numbers of Mcu_70_RL78F2X.h and Mcu_70_RL78F2X_Types.h are different"
#endif
 
#if ( ( MCU_70_SW_MAJOR_VERSION_RL78F2X_H != MCU_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( MCU_70_SW_MINOR_VERSION_RL78F2X_H != MCU_70_SW_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( MCU_70_SW_PATCH_VERSION_RL78F2X_H != MCU_70_SW_PATCH_VERSION_RL78F2X_TYPES_H )    \
    )
    #error "Software Version Numbers of Mcu_70_RL78F2X.h and Mcu_70_RL78F2X_Types.h are different"
#endif
/* Mcu_70_RL78F2X_Types.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* RL78/F2X  ECC-EAM */
#define MCU_70_ECCER_DBERR           ( (uint8)0x01U )     /* ECC-RAM ECCER register 1 bit error flag. */
#define MCU_70_ECCIER_IEN            ( (uint8)0x01U )     /* ECC-RAM error detection interrupt enable register flag. */
 
/* RL78F2X PLLCTL register set bit */
#define MCU_70_PLLCTL_LCKSEL0_MASK   ( (uint8)0xBFU )     /* PLLCTL.LCKSEL0 mask. */
#define MCU_70_PLLCTL_LCKSEL1_MASK   ( (uint8)0x7FU )     /* PLLCTL.LCKSEL1 mask. */
#define MCU_70_PLLCTL_PLLDIV0_MASK   ( (uint8)0xEFU )     /* PLLCTL.PLLDEV0 mask. */
#define MCU_70_PLLCTL_PLLDIV1_MASK   ( (uint8)0xDFU )     /* PLLCTL.PLLDEV1 mask. */
#define MCU_70_PLLCTL_SELPLL_MASK    ( (uint8)0xFBU )     /* PLLCTL.SELPLL mask. */
#define MCU_70_PLLCTL_PLLMULA_MASK   ( (uint8)0xF7U )     /* PLLCTL.PLLMULA mask. */
#define MCU_70_PLLCTL_PLLMUL_MASK    ( (uint8)0xFDU )     /* PLLCTL.PLLMUL mask. */
#define MCU_70_PLLCTL_PLLON_MASK     ( (uint8)0xFEU )     /* PLLCTL.PLLON mask. */
#define MCU_70_PLLCTL_PLLON          ( (uint8)0x01U )     /* PLLCTL.PLLON bit. */
#define MCU_70_PLLCTL_SELPLL         ( (uint8)0x04U )     /* PLLCTL.SELPLL bit. */
#define MCU_70_PLLSTS_SELPLLS        ( (uint8)0x08U )     /* PLLSTS.SELPLLS bit. */
#define MCU_70_PLLSTS_LOCK           ( (uint8)0x80U )     /* PLLSTS.LOCK bit. */
#define MCU_70_CKC_MCM0              ( (uint8)0x10U )     /* CKC.MCM0 bit . */
 
/* wait loop count */
#define MCU_70_WAIT_SELPLLS          ( 10U )       /* for wait PLLSTS.SELPLLS loop count */
#define MCU_70_WAIT_PLLMUL           ( 3U )        /* for wait PLLMUL loop count */
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"
 
/* [SWS_Mcu_00153] */
extern Std_ReturnType Mcu_70_RL78F2X_Init( const Mcu_ConfigType* ConfigPtr );
 
/* not used in RL78F2X */
extern void Mcu_70_RL78F2X_InitRamSection( const Mcu_RamSectorSettingConfType* RamSectCfgPtr );
 
#if ( MCU_INIT_CLOCK != FALSE )
/* [SWS_Mcu_00155] */
extern Std_ReturnType Mcu_70_RL78F2X_InitClock( const Mcu_ClockSettingConfigType* ClockSetCfgPtr );
#endif /* #if ( MCU_INIT_CLOCK != FALSE ) */
 
#if ( MCU_NO_PLL == FALSE )
/* [SWS_Mcu_00156] */
extern Std_ReturnType Mcu_70_RL78F2X_DistributePllClock( void );
#endif /* #if ( MCU_NO_PLL == FALSE ) */
 
/* [SWS_Mcu_00157] */
extern Mcu_PllStatusType Mcu_70_RL78F2X_GetPllStatus( void );
 
/* [SWS_Mcu_00158] */
extern Mcu_ResetType Mcu_70_RL78F2X_GetResetReason( void );
 
/* [SWS_Mcu_00159] */
extern Mcu_RawResetType Mcu_70_RL78F2X_GetResetRawValue( void );
 
/* [SWS_Mcu_00161] */
extern void Mcu_70_RL78F2X_SetMode( Mcu_ModeType McuMode );
 
#if ( MCU_GET_RAM_STATE_API!= FALSE )
/* [SWS_Mcu_00207] */
extern Std_ReturnType Mcu_70_RL78F2X_GetRamState( void );
 
/* [SWS_Mcu_00207] */
extern void Mcu_70_RL78F2X_RamStateIsr( void );
#endif /* #if ( MCU_GET_RAM_STATE_API != FALSE ) */
 
#define MCU_STOP_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"
 
#endif /* #ifndef MCU_70RL78F2X_H_ */
 
/* EOF Mcu_70_RL78F2X.h *****************************************************************/