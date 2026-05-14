/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Mcu_Cfg.h                                                    */
/* Version     : v2.0.1                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of MCU Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef MCU_CFG_H
#define MCU_CFG_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define MCU_70_VENDOR_ID_CFG_H                   ( 70U )

#define MCU_70_MODULE_ID_CFG_H                   ( 101U )

#define MCU_70_AR_RELEASE_MAJOR_VERSION_CFG_H    ( 22U )
#define MCU_70_AR_RELEASE_MINOR_VERSION_CFG_H    ( 11U )
#define MCU_70_AR_RELEASE_REVISION_VERSION_CFG_H ( 0U )

#define MCU_70_SW_MAJOR_VERSION_CFG_H            ( 1U )
#define MCU_70_SW_MINOR_VERSION_CFG_H            ( 0U )
#define MCU_70_SW_PATCH_VERSION_CFG_H            ( 0U )
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* Feature List */
/* [ECUC_Mcu_00166] */
/* Pre-processor switch for enabling the development error detection and reporting. */
#define MCU_DEV_ERROR_DETECT                     ( TRUE ) /* error detect */
#define MCU_70_DEM_SET_EVENT_STATUS              ( TRUE ) /* Enable/Disable the API for reporting the Dem Error. */
#define MCU_E_CLOCK_FAILURE                      ( DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE)

/* Define what API functions to enable */
/* [ECUC_Mcu_00167] */
#define MCU_PERFORM_RESET_API                    ( FALSE )
/* [ECUC_Mcu_00168] */
#define MCU_VERSION_INFO_API                     ( TRUE )
/* [ECUC_Mcu_00181] */
#define MCU_GET_RAM_STATE_API                    ( TRUE )
/* [ECUC_Mcu_00180] */
#define MCU_NO_PLL                               ( FALSE )
/* [ECUC_Mcu_00182] */
#define MCU_INIT_CLOCK                           ( TRUE )

/* -- Data struct size define                    -- */
#define MCU_70_NUM_OF_CLOCK_SETTING_DATA         ( 1U )
#define MCU_70_NUM_OF_RAM_SECTOR_SETTING_CONF    ( 1U )
#define MCU_70_NUM_OF_CLOCK_SETTING              ( 1U )
#define MCU_70_NUM_OF_MODE_SETTING_CONF          ( 3U )
#define MCU_70_NUM_OF_REFERENCE_POINT            ( 1U )

/* [SWS_Mcu_00251] (AUTOSAR 4.0.3 no requirement) 0..<number of clock setting>-1 */
#define MCU_70_CLOCK_NORMAL                      ( 0U ) /* Clock Normal */
#define McuConf_McuClockSettingConfig_0          ( 0U )
#define MCU_70_CLOCK_TYPE_NUM                    ( 1U ) /* number of clock settings */
/* [SWS_Mcu_00255] (AUTOSAR 4.0.3 no requirement) 0..<number of RAM section>-1 */
#define MCU_70_RAM_SECTOR_0                      ( 0U ) /* RAM sector-01 */
#define MCU_70_RAM_SECTOR_NUM                    ( 1U ) /* number of RAM sectors */

/* Additional for EcuM use */
#define McuConf_McuModeSettingConf_MCUMODE_NORMAL ( MCU_70_MODE_NORMAL )
#define McuConf_McuModeSettingConf_MCUMODE_HALT  ( MCU_70_MODE_HALT )
#define McuConf_McuModeSettingConf_MCUMODE_STOP  ( MCU_70_MODE_STOP )
#define McuConf_McuResetReasonConf_McuResetReasonConf ( MCU_POWER_ON_RESET )
/* Peripheral Enable Register */
#define MCU_Q_PER_USE_RTCEN                      ( FALSE )
#define MCU_Q_PER_USE_ADCEN                      ( TRUE )
#define MCU_Q_PER_USE_IICA0EN                    ( FALSE )
#define MCU_Q_PER_USE_SAU1EN                     ( TRUE )
#define MCU_Q_PER_USE_SAU0EN                     ( TRUE )
#define MCU_Q_PER_USE_TAU1EN                     ( TRUE )
#define MCU_Q_PER_USE_TAU0EN                     ( TRUE )
#define MCU_Q_PER_USE_DACEN                      ( FALSE )
#define MCU_Q_PER_USE_CTSUEN                     ( FALSE )
#define MCU_Q_PER_USE_CMPEN                      ( FALSE )
#define MCU_Q_PER_USE_TRD0EN                     ( TRUE )
#define MCU_Q_PER_USE_DTCEN                      ( FALSE )
#define MCU_Q_PER_USE_PWMOPEN                    ( FALSE )
#define MCU_Q_PER_USE_TRJ0EN                     ( TRUE )
#define MCU_Q_PER_USE_AAUEN                      ( FALSE )
#define MCU_Q_PER_USE_CAN1EN                     ( TRUE )
#define MCU_Q_PER_USE_LIN2EN                     ( TRUE )
#define MCU_Q_PER_USE_LIN1EN                     ( TRUE )
#define MCU_Q_PER_USE_LIN0EN                     ( TRUE )
#define MCU_Q_PER_USE_CAN0EN                     ( TRUE )
#define MCU_Q_LIN0MCKE_FMX                       ( TRUE )
#define MCU_Q_LIN1MCKE_FMX                       ( TRUE )
#define MCU_Q_LIN2MCKE_FMX                       ( TRUE )

/* PER0 */
#if MCU_Q_PER_USE_RTCEN == TRUE
#define MCU_Q_PER0_07                            ( 128U )
#else
#define MCU_Q_PER0_07                            ( 0U )
#endif
#define MCU_Q_PER0_06                            ( 0U )

#if MCU_Q_PER_USE_ADCEN == TRUE
#define MCU_Q_PER0_05                            ( 32U )
#else
#define MCU_Q_PER0_05                            ( 0U )
#endif

#if MCU_Q_PER_USE_IICA0EN == TRUE
#define MCU_Q_PER0_04                            ( 16U )
#else
#define MCU_Q_PER0_04                            ( 0U )
#endif

#if MCU_Q_PER_USE_SAU1EN == TRUE
#define MCU_Q_PER0_03                            ( 8U )
#else
#define MCU_Q_PER0_03                            ( 0U )
#endif

#if MCU_Q_PER_USE_SAU0EN == TRUE
#define MCU_Q_PER0_02                            ( 4U )
#else                
#define MCU_Q_PER0_02                            ( 0U )
#endif

#if MCU_Q_PER_USE_TAU1EN == TRUE
#define MCU_Q_PER0_01                            ( 2U )
#else
#define MCU_Q_PER0_01                            ( 0U )
#endif

#if MCU_Q_PER_USE_TAU0EN == TRUE
#define MCU_Q_PER0_00                            ( 1U )
#else
#define MCU_Q_PER0_00                            ( 0U )
#endif

#define MCU_Q_PER0_VALUE_HALT                    ( 0x00U )
#define MCU_Q_PER0_VALUE_STOP                    ( 0x00U )
#define MCU_Q_PER0_VALUE_NORMAL                  ( MCU_Q_PER0_07 | MCU_Q_PER0_06 | MCU_Q_PER0_05 | MCU_Q_PER0_04 | MCU_Q_PER0_03 | MCU_Q_PER0_02 | MCU_Q_PER0_01 | MCU_Q_PER0_00 )

/* PER1 */
#if MCU_Q_PER_USE_DACEN == TRUE
#define MCU_Q_PER1_07                            ( 128U )
#else
#define MCU_Q_PER1_07                            ( 0U )
#endif

#if MCU_Q_PER_USE_CTSUEN == TRUE
#define MCU_Q_PER1_06                            ( 64U )
#else
#define MCU_Q_PER1_06                            ( 0U )
#endif

#if MCU_Q_PER_USE_CMPEN == TRUE
#define MCU_Q_PER1_05                            ( 32U )
#else
#define MCU_Q_PER1_05                            ( 0U )
#endif

#if MCU_Q_PER_USE_TRD0EN == TRUE
#define MCU_Q_PER1_04                            ( 16U )
#else
#define MCU_Q_PER1_04                            ( 0U )
#endif

#if MCU_Q_PER_USE_DTCEN == TRUE
#define MCU_Q_PER1_03                            ( 8U )
#else                
#define MCU_Q_PER1_03                            ( 0U )
#endif

#if MCU_Q_PER_USE_PWMOPEN == TRUE
#define MCU_Q_PER1_02                            ( 4U )
#else                
#define MCU_Q_PER1_02                            ( 0U )
#endif

#define MCU_Q_PER1_01                            ( 0U )

#if MCU_Q_PER_USE_TRJ0EN == TRUE
#define MCU_Q_PER1_00                            ( 1U )
#else                
#define MCU_Q_PER1_00                            ( 0U )
#endif

#define MCU_Q_PER1_VALUE_HALT                    ( 0x00U )
#define MCU_Q_PER1_VALUE_STOP                    ( MCU_Q_PER1_00 )
#define MCU_Q_PER1_VALUE_NORMAL                  ( MCU_Q_PER1_07 | MCU_Q_PER1_06 | MCU_Q_PER1_05 | MCU_Q_PER1_04 | MCU_Q_PER1_03 | MCU_Q_PER1_02 | MCU_Q_PER1_01 | MCU_Q_PER1_00 )

/* PER2 */
#define MCU_Q_PER2_07                            ( 0U )

#if MCU_Q_PER_USE_AAUEN == TRUE
#define MCU_Q_PER2_06                            ( 64U )
#else
#define MCU_Q_PER2_06                            ( 0U )
#endif

#if MCU_Q_PER_USE_CAN1EN == TRUE
#define MCU_Q_PER2_05                            ( 32U )
#define MCU_Q_CANCKSEL_01                        ( 2U )
#else
#define MCU_Q_PER2_05                            ( 0U )
#define MCU_Q_CANCKSEL_01                        ( 0U )
#endif

#if MCU_Q_PER_USE_LIN2EN == TRUE
#define MCU_Q_PER2_04                            ( 16U )
#define MCU_Q_LINCKSEL_06                        ( 64U )

#if MCU_Q_LIN1MCKE_FMX == TRUE
#define MCU_Q_LINCKSEL_02                        ( 16U )
#else
#define MCU_Q_LINCKSEL_02                        ( 0U )
#endif

#else
#define MCU_Q_PER2_04                            ( 0U )
#define MCU_Q_LINCKSEL_02                        ( 0U )
#define MCU_Q_LINCKSEL_06                        ( 0U )
#endif

#if MCU_Q_PER_USE_LIN1EN == TRUE
#define MCU_Q_PER2_03                            ( 8U )
#define MCU_Q_LINCKSEL_05                        ( 32U )

#if MCU_Q_LIN1MCKE_FMX == TRUE
#define MCU_Q_LINCKSEL_01                        ( 2U )
#else
#define MCU_Q_LINCKSEL_01                        ( 0U )
#endif

#else
#define MCU_Q_PER2_03                            ( 0U )
#define MCU_Q_LINCKSEL_01                        ( 0U )
#define MCU_Q_LINCKSEL_05                        ( 0U )
#endif

#if MCU_Q_PER_USE_LIN0EN == TRUE
#define MCU_Q_PER2_02                            ( 4U )
#define MCU_Q_LINCKSEL_04                        ( 16U )

#if MCU_Q_LIN0MCKE_FMX == TRUE
#define MCU_Q_LINCKSEL_00                        ( 1U )
#else
#define MCU_Q_LINCKSEL_00                        ( 0U )
#endif

#else
#define MCU_Q_PER2_02                            ( 0U )
#define MCU_Q_LINCKSEL_00                        ( 0U )
#define MCU_Q_LINCKSEL_04                        ( 0U )
#endif

#define MCU_Q_PER2_01                            ( 0U )

#if MCU_Q_PER_USE_CAN0EN == TRUE
#define MCU_Q_PER2_00                            ( 1U )
#define MCU_Q_CANCKSEL_00                        ( 1U )
#else
#define MCU_Q_PER2_00                            ( 0U )
#define MCU_Q_CANCKSEL_00                        ( 0U )
#endif
#define MCU_Q_PER2_VALUE_HALT                    ( 0x00U )
#define MCU_Q_PER2_VALUE_STOP                    ( 0x00U )
#define MCU_Q_PER2_VALUE_NORMAL                  ( MCU_Q_PER2_07 | MCU_Q_PER2_06 | MCU_Q_PER2_05 | MCU_Q_PER2_04 | MCU_Q_PER2_03 | MCU_Q_PER2_02 | MCU_Q_PER2_01 | MCU_Q_PER2_00 )

#define MCU_Q_CANCKSEL_HALT                      ( 0x00U )
#define MCU_Q_CANCKSEL_STOP                      ( 0x00U )
#define MCU_Q_CANCKSEL_NORMAL                    ( MCU_Q_CANCKSEL_01 | MCU_Q_CANCKSEL_00 )

#define MCU_Q_LINCKSEL_HALT                      ( 0x00U )
#define MCU_Q_LINCKSEL_STOP                      ( 0x00U )
#define MCU_Q_LINCKSEL_NORMAL                    ( MCU_Q_LINCKSEL_06 | MCU_Q_LINCKSEL_05 | MCU_Q_LINCKSEL_04 | MCU_Q_LINCKSEL_02 | MCU_Q_LINCKSEL_01 | MCU_Q_LINCKSEL_00 )
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

#endif /* MCU_CFG_H */

/* End of Mcu_Cfg.h */
