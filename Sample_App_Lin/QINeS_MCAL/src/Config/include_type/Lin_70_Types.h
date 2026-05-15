/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Lin_70_Types.h                                               */
/* Version     : v1.00.00                                                     */
/* Contents    : LIN Module HW dependent header                               */
/*               This file is LIN Driver type Header                          */
/*               The LIN is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of LIN Driver                                                */
/* R22-11                                                                     */
#ifndef LIN_70_TYPES_H
#define LIN_70_TYPES_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Lin_GeneralTypes.h"
#include "EcuM.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define LIN_70_VENDOR_ID_TYPES_H                      ( 70 )
#define LIN_70_MODULE_ID_TYPES_H                      ( 82 )

#define LIN_70_AR_RELEASE_MAJOR_VERSION_TYPES_H       ( 22U )
#define LIN_70_AR_RELEASE_MINOR_VERSION_TYPES_H       ( 11U )
#define LIN_70_AR_RELEASE_REVISION_VERSION_TYPES_H    ( 0U )

#define LIN_70_SW_MAJOR_VERSION_TYPES_H               ( 1U )
#define LIN_70_SW_MINOR_VERSION_TYPES_H               ( 0U )
#define LIN_70_SW_PATCH_VERSION_TYPES_H               ( 0U )

/*-------------------Std_Types.h version check start------------------------------*/
#if ( ( LIN_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( LIN_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != STD_TYPES_AR_RELEASE_MINOR_VERSION ) || \
      ( LIN_70_AR_RELEASE_REVISION_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Lin_70_Types.h and Std_Types.h are different"
#endif

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define LIN_70_MAX_NUMBER_EVENT_ID                    ( 1U )  /*  Dem Error Event ID No.  */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/* [LIN186_Conf] */
typedef struct
{
    uint32 state;   /**< enabling/disabling the DEM error: Active=STD_ON/ Inactive=STD_OFF */
    uint32 id ;     /**< ID of DEM error (0 if STD_OFF)*/
} Lin_70_DemErrorType;
 
typedef struct {
    Lin_70_DemErrorType  LinEventId[LIN_70_MAX_NUMBER_EVENT_ID];
} Lin_DemEventParameterRefsType;
 
/* [ECUC_Lin_00069]] */
typedef struct
{
    uint16  LinChannelBaudRate;             /* [ECUC_Lin_00180] */
    uint16  LinChannelId;                   /* [ECUC_Lin_00181] */
    bool_t  LinChannelWakeupSupport;        /* [ECUC_Lin_00182] */
    EcuM_WakeupSourceType  LinChannelEcuMWakeupSource;    /* [EcuMWakeupSource] [LIN185_Conf] */
    uint32  LinClockRef;                    /* [McuClockReferencePoint] [LIN094_Conf] */
    uint8   LinNodeType;                    /* [ECUC_Lin_00191] */
} Lin_ChannelType;

/* [ECUC_Lin_00184]] */
typedef struct
{
    const Lin_ChannelType*                  LinChannel;
    const Lin_DemEventParameterRefsType*    LinDemEventParameterRefs;
} Lin_GlobalConfigType;

/* [SWS_Lin_00227] */
typedef struct
{
    const Lin_GlobalConfigType* Lin_GlobalConfig;
} Lin_ConfigType;

/* LIN driver status */
typedef enum {
    LIN_UNINIT = 0,
    LIN_INIT   = 1
} Lin_70_DriverStatusType;

/* LIN ordered status */
typedef enum {
    LIN_ORDER_OPERATIONAL = 0,
    LIN_ORDER_SLEEP       = 1,
    LIN_ORDER_NON         = 2
} Lin_70_OrderedStatusType;

/* LIN frame status */
typedef enum {
    LIN_SEND_HEADER   = 0,
    LIN_SEND_RESPONSE = 1,
    LIN_SEND_WAKEUP   = 2
} Lin_70_FrameStatusType;

/* LIN Master channel status */
typedef struct
{
    Lin_StatusType             ChannelStatus;
    Lin_StatusType             ChannelSubStatus;
    Lin_70_OrderedStatusType   ChannelOrderedStatus;
    Lin_70_FrameStatusType     FrameStatus;
    uint8                      ErrorStatus;
    uint8                      WakeupStatus;
} Lin_70_ChannelStatusType;

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

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

#endif /* LIN_70_TYPES_H */
/* EOF Lin_70_Types.h *************************************************/
