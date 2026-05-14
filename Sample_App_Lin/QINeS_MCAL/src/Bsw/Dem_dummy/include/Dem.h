/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Dem.h                                                        */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/
#ifndef DEM_H
#define DEM_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Dem_AR.h"
#include "Dem_Types.h"
#include "Dem_IntErrId.h"

/*----------------------------------------------------------------------------*/
/* type definitions ( callback functions )                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/* [SWS_Dem_00924] Dem_ConfigType */
/* details are not hangs in the specifications */
typedef struct {
    const uint32                        data;      /* dummy data */
} Dem_ConfigType;

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define DEM_MODULE_ID                   (uint16)MODULE_ID_DEM
#define DEM_VENDOR_ID                   VENDOR_ID_SCSK

/* Dem_GetVersionInfo */
#define DET_VENDOR_ID                   VENDOR_ID_SCSK

/* version ID */
#define DEM_SW_MAJOR_VERSION            ( 1U )
#define DEM_SW_MINOR_VERSION            ( 0U )
#define DEM_SW_PATCH_VERSION            ( 3U )

/* InstanceId */
#define DEM_INSTANCE_ID                 (uint8)0

/* ServiceID */
#define DEM_INIT_ID                     (uint8)0x02
#define DEM_SHUTDOWN_ID                 (uint8)0x03
#define DEM_REPORTERRORSTATUS_ID        (uint8)0x0f
#define DEM_SETEVENTSTATUS_ID           (uint8)0x04

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/
extern const Dem_ConfigType DemConfigData;

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
void Dem_Init( void );
void Dem_Shutdown( void );
void Dem_ReportErrorStatus( Dem_EventIdType EventId, Dem_EventStatusType EventStatus );
Std_ReturnType Dem_SetEventStatus( Dem_EventIdType EventId, Dem_EventStatusType EventStatus );

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

#endif /* DEM_H */

/* Dem.h **********************************************************************/
