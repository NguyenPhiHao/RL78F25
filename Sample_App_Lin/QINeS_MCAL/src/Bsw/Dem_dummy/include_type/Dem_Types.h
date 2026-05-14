/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Dem_Types.h                                                  */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/
#ifndef DEM_TYPES_H
#define DEM_TYPES_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef uint16 Dem_EventIdType;

typedef uint8 Dem_EventStatusType;
#define DEM_EVENT_STATUS_PASSED                    (0x00U)     /* Passed      */
#define DEM_EVENT_STATUS_FAILED                    (0x01U)     /* Failed      */
#define DEM_EVENT_STATUS_PREPASSED                 (0x02U)     /* Pre-passed  */
#define DEM_EVENT_STATUS_PREFAILED                 (0x03U)     /* Pre-failed  */

/* Extended Production Errors */
enum {
    /* CanSM (CAN State Manager) */
    CANSM_E_BUS_OFF,
    /* Eep (EEPROM Driver) */
    EEP_E_ERASE_FAILED,
    EEP_E_WRITE_FAILED,
    EEP_E_READ_FAILED,
    EEP_E_COMPARE_FAILED,
    /* Fls (Flash Driver) */
    FLS_E_ERASE_FAILED,
    FLS_E_WRITE_FAILED,
    FLS_E_READ_FAILED,
    FLS_E_COMPARE_FAILED,
    FLS_E_UNEXPECTED_FLASH_ID,
};

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

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

#endif /* DEM_TYPES_H */

/* EOF Dem_Types.h ************************************************************/
