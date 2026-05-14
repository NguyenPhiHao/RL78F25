/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Dem_IntErrId.h                                               */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef DEM_INTERRID_H
#define DEM_INTERRID_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define DemConf_DemEventParameter_DEM_EVENT_ID_NULL                         ( (Dem_EventIdType)  0U)

#define DemConf_DemEventParameter_BSWM_E_ACTION_FAILED                      ( (Dem_EventIdType)  1U)    /* BswM */
#define DemConf_DemEventParameter_CANSM_E_BUS_OFF                           ( (Dem_EventIdType)  2U)    /* CanSM */
#define DemConf_DemEventParameter_ECUM_E_RAM_CHECK_FAILED                   ( (Dem_EventIdType)  3U)    /* EcuM */
#define DemConf_DemEventParameter_ECUM_E_CONFIGURATION_DATA_INCONSISTENT    ( (Dem_EventIdType)  4U)    /* EcuM */
#define DemConf_DemEventParameter_ECUM_E_ALL_RUN_REQUESTS_KILLED            ( (Dem_EventIdType)  5U)    /* EcuM */
#define DemConf_DemEventParameter_ECUM_E_IMPROPER_CALLER                    ( (Dem_EventIdType)  6U)    /* EcuM */
#define DemConf_DemEventParameter_IOHWAB_Q_E_ADC_GETMCAL                    ( (Dem_EventIdType)  7U)    /* IoHwAb */
#define DemConf_DemEventParameter_IOHWAB_Q_E_ADC_INCORRECT_SCH              ( (Dem_EventIdType)  8U)    /* IoHwAb */
#define DemConf_DemEventParameter_NVM_E_INTEGRITY_FAILED                    ( (Dem_EventIdType)  9U)    /* NvM */
#define DemConf_DemEventParameter_NVM_E_REQ_FAILED                          ( (Dem_EventIdType) 10U)    /* EcuM, NvM */
#define DemConf_DemEventParameter_NVM_E_WRONG_BLOCK_ID                      ( (Dem_EventIdType) 11U)    /* NvM */
#define DemConf_DemEventParameter_NVM_E_QUEUE_OVERFLOW                      ( (Dem_EventIdType) 12U)    /* NvM */
#define DemConf_DemEventParameter_NVM_E_WRITE_PROTECTED                     ( (Dem_EventIdType) 13U)    /* NvM */
#define DemConf_DemEventParameter_WDGM_E_SUPERVISION                        ( (Dem_EventIdType) 14U)    /* WdgM */
#define DemConf_DemEventParameter_WDGM_E_SET_MODE                           ( (Dem_EventIdType) 15U)    /* WdgM */
#define DemConf_DemEventParameter_WDGM_E_IMPROPER_CALLER                    ( (Dem_EventIdType) 16U)    /* WdgM */
#define DemConf_DemEventParameter_EEP_E_ERASE_FAILED                        ( (Dem_EventIdType) 17U)    /* Eep */
#define DemConf_DemEventParameter_EEP_E_WRITE_FAILED                        ( (Dem_EventIdType) 18U)    /* Eep */
#define DemConf_DemEventParameter_EEP_E_READ_FAILED                         ( (Dem_EventIdType) 19U)    /* Eep */
#define DemConf_DemEventParameter_EEP_E_COMPARE_FAILED                      ( (Dem_EventIdType) 20U)    /* Eep */
#define DemConf_DemEventParameter_FLS_E_ERASE_FAILED                        ( (Dem_EventIdType) 21U)    /* Fls */
#define DemConf_DemEventParameter_FLS_E_WRITE_FAILED                        ( (Dem_EventIdType) 22U)    /* Fls */
#define DemConf_DemEventParameter_FLS_E_READ_FAILED                         ( (Dem_EventIdType) 23U)    /* Fls */
#define DemConf_DemEventParameter_FLS_E_COMPARE_FAILED                      ( (Dem_EventIdType) 24U)    /* Fls */
#define DemConf_DemEventParameter_LIN_E_TIMEOUT                             ( (Dem_EventIdType) 25U)    /* Lin */
#define DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE                       ( (Dem_EventIdType) 26U)    /* Mcu */
#define DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR                      ( (Dem_EventIdType) 27U)    /* Spi */
#define DemConf_DemEventParameter_WDG_E_MODE_FAILED                         ( (Dem_EventIdType) 28U)    /* Wdg */
#define DemConf_DemEventParameter_WDG_E_DISABLE_REJECTED                    ( (Dem_EventIdType) 29U)    /* Wdg */
#define DemConf_DemEventParameter_ADC_E_TIMEOUT                             ( (Dem_EventIdType) 30U)    /* Adc */
#define DemConf_DemEventParameter_MCU_E_LOCK_FAILURE                        ( (Dem_EventIdType) 31U)    /* Mcu */
#define DemConf_DemEventParameter_MCU_E_QUARTZ_FAILURE                      ( (Dem_EventIdType) 32U)    /* Mcu */
#define DemConf_DemEventParameter_MCU_E_TIMEOUT_TRANSITION                  ( (Dem_EventIdType) 33U)    /* Mcu */
#define DemConf_DemEventParameter_PWM_E_UNEXPECTED_IRQ                      ( (Dem_EventIdType) 34U)    /* Pwm */
#define DemConf_DemEventParameter_WDG_E_MISS_TRIGGER                        ( (Dem_EventIdType) 35U)    /* Wdg */
#define DemConf_DemEventParameter_DEM_E_GENERAL_FAILURE                     ( (Dem_EventIdType) 36U)
#define DemConf_DemEventParameter_FLS_E_UNEXPECTED_FLASH_ID                 ( (Dem_EventIdType) 37U)    /* Fls */

#define DEM_EVENT_ID_LAST_FOR_BSW                                           ( (Dem_EventIdType) 38U)    /* define the number of DemEventIds of BSW modules */

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

#endif /* DEM_INTERRID_H */

/* EOF Dem_IntErrId.h *********************************************************/