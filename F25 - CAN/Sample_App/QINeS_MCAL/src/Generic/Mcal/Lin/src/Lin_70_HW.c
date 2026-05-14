/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Lin_70_HW.c                                                  */
/* Version     : v1.00.02                                                     */
/* Contents    : LIN Module wrapper                                           */
/*               The LIN is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of LIN Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "ComStack_Types.h"     /* [SWS_Lin_00226] */
#include "Lin_GeneralTypes.h"   /* [SWS_Lin_00245] */
#include "Lin_70_RL78F2X.h"
#include "Lin_Slave_70_RL78F2X.h"
#include "Lin_70_HW.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define LIN_70_VENDOR_ID_HW_C                      ( 70U )
#define LIN_70_MODULE_ID_HW_C                      ( 82U )
 
#define LIN_70_AR_RELEASE_MAJOR_VERSION_HW_C       ( 22U )
#define LIN_70_AR_RELEASE_MINOR_VERSION_HW_C       ( 11U )
#define LIN_70_AR_RELEASE_REVISION_VERSION_HW_C    ( 0U )
 
#define LIN_70_SW_MAJOR_VERSION_HW_C               ( 1U )
#define LIN_70_SW_MINOR_VERSION_HW_C               ( 0U )
#define LIN_70_SW_PATCH_VERSION_HW_C               ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Lin_70_Hw.h version check start */
 
/* Check if current file and Lin_70_Hw.h header file are of the same Vendor ID */
#if (LIN_70_VENDOR_ID_HW_C    != LIN_70_VENDOR_ID_HW_H)
    #error "VENDOR ID for Lin_70_Hw.c and Lin_70_Hw.h are different"
#endif      /* End of Vendor Id Version check */
 
#if (LIN_70_MODULE_ID_HW_C    != LIN_70_MODULE_ID_HW_H)
    #error "MODULE ID for Lin_70_Hw.c and Lin_70_Hw.h are different"
#endif      /* End of Module Id Version check */
 
/* Check if current file and Lin_70_Hw.h header file are of the same Software version */
#if ((LIN_70_SW_MAJOR_VERSION_HW_C    != LIN_70_SW_MAJOR_VERSION_HW_H) ||\
     (LIN_70_SW_MINOR_VERSION_HW_C    != LIN_70_SW_MINOR_VERSION_HW_H) ||\
     (LIN_70_SW_PATCH_VERSION_HW_C    != LIN_70_SW_PATCH_VERSION_HW_H))
    #error "Software Version Numbers of Lin_70_Hw.c and Lin_70_Hw.h are different"
#endif      /* End of S/W Version check */
 
/* Check if current file and Lin_70_Hw.h header file are of the same Autosar version */
#if ((LIN_70_AR_RELEASE_MAJOR_VERSION_HW_C    != LIN_70_AR_RELEASE_MAJOR_VERSION_HW_H)   ||\
     (LIN_70_AR_RELEASE_MINOR_VERSION_HW_C    != LIN_70_AR_RELEASE_MINOR_VERSION_HW_H)   ||\
     (LIN_70_AR_RELEASE_REVISION_VERSION_HW_C != LIN_70_AR_RELEASE_REVISION_VERSION_HW_H))
    #error "AUTOSAR Version Numbers of Lin_70_Hw.c and Lin_70_Hw.h are different"
#endif      /* End of Autosar Version check */
 
/* Lin_70_Hw.c version check end */
 
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* global variables                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
/*  Config data pointer */
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
/* Function to calculate the baud rate prescalar from the configured baud rate */
static uint16 lin_calcBaudRatePrescaler( const uint8 chIndex );
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
/* used for configuring baud rate prescaler register */
#define LIN_70_BIT_SAMPLING              ( 16 )
 
#define LIN_START_SEC_CODE_LOCAL
#include "Lin_MemMap.h"
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : --                                                           */
/* Name        : Lin_70_HW_ChangeChannel                                      */
/* Param       : void                                                         */
/* Return      : void                                                         */
/* Contents    : This function shall change channel2.                         */
/* Author      : --                                                           */
/* Note        : -                                                            */
/*----------------------------------------------------------------------------*/
void Lin_70_HW_ChangeChannel( const uint8 chIndex )
{
    Lin_70_RL78F2X_ChangeChannel( chIndex );
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : LIN_INIT_ID (0x00)                                           */
/* Name        : Lin_70_HW_SetConfigPtr                                       */
/* Param       : (in) chIndex    Lin channel index.                           */
/* Return      : void                                                         */
/* Contents    : Initializes the LIN channel mode parameters                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Lin_70_HW_SetConfigPtr( const Lin_ConfigType* config )
{
    /* save config data pointer */
    s_Lin_Config = config;
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : LIN_INIT_ID (0x00)                                           */
/* Name        : Lin_70_HW_InitParameter                                      */
/* Param       : (in) chIndex    Lin channel index.                           */
/* Return      : void                                                         */
/* Contents    : Initializes the LIN channel mode parameters                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Lin_70_HW_InitParameter( const uint8 chIndex )
{
    if ( s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex].LinNodeType == LIN_70_MASTER )  {/* Master node */
        /* [SWS_Lin_00171] Set Lin Channel status to operational */
        s_Lin_Status[chIndex].ChannelOrderedStatus = LIN_ORDER_NON;
 
        /* [SWS_Lin_00171]  */
        s_Lin_Status[chIndex].ChannelStatus        = LIN_CH_SLEEP;
        s_Lin_Status[chIndex].ChannelSubStatus     = LIN_CH_SLEEP;
        s_Lin_Status[chIndex].ErrorStatus          = (uint8)LIN_ERR_NONE;
        s_Lin_Status[chIndex].WakeupStatus         = FALSE;
    } else
    { /* Slave node */
        /* [SWS_Lin_00171]  */
        s_Lin_Status[chIndex].ChannelStatus    = LIN_CH_SLEEP;
        s_Lin_Status[chIndex].FrameStatus      = LIN_SEND_HEADER;
        s_Lin_Status[chIndex].ErrorStatus      = (uint8)LIN_ERR_NONE;
        s_Lin_Status[chIndex].WakeupStatus     = (uint8)FALSE;
    }
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : none                                                         */
/* Name        : lin_calcBaudRatePrescalar                                    */
/* Param       : (in) chIndex    Lin channel index.                           */
/* Return      : uint16          baud rate prescalar value                    */
/* Contents    : calculate the baud rate prescalar from the config parameters */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
static uint16 lin_calcBaudRatePrescaler( const uint8 chIndex )
{
    uint16 baudRatePresacalar = ( uint16 )0;
    uint16 baudRate;
    uint32 calcPrescalar;
 
    /* Read the baud rate from the configuration */
    baudRate = s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex].LinChannelBaudRate;
    /* Read the configured clock value for Lin channel */
    calcPrescalar = s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex].LinClockRef;
    /* Calculate the prescalar by dividing the clock by sampling time (16) and baudrate */
    if ( baudRate != (uint16)0 ) {
        calcPrescalar = calcPrescalar / ( ( uint32 )LIN_70_BIT_SAMPLING * ( uint32 )baudRate );
        /* assign the value to the baudRatePresacalar */
        baudRatePresacalar = ( uint16 )( calcPrescalar );
    }
 
    return baudRatePresacalar;
}
 
/******************************************************************************/
/* ModuleID    : LIN_MODULE_ID (082)                                          */
/* ServiceID   : LIN_INIT_ID (0x00)                                           */
/* Name        : Lin_70_HW_Init                                               */
/* Param       : (in) chIndex    Lin channel index.                           */
/* Return      : void                                                         */
/* Contents    : Initializes the LIN module.                                  */
/* Author      : --                                                           */
/* Note        : [SWS_Lin_00006]                                              */
/*----------------------------------------------------------------------------*/
void Lin_70_HW_Init( const uint8 chIndex )
{
    /* [SWS_Lin_00084] */
    /* Initialize static variables, flags, Lin Hw unit settings */
    uint16          baudRatePrescaler;
 
    /* calculate the value of baud rate prescalar */
    baudRatePrescaler = lin_calcBaudRatePrescaler( chIndex );
 
    /* [SWS_Lin_00084] [SWS_Lin_00008] [SWS_Lin_00190] */
    /* Initialize lin hardware registers */
    if ( s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex].LinNodeType == LIN_70_MASTER )  {/* Master node */
        Lin_70_RL78F2X_MstInit( (uint8)s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex].LinChannelId, baudRatePrescaler );
    } else
    { /* Slave node */
    /* [SWS_Lin_00084] [SWS_Lin_00008] [SWS_Lin_00190] */
    /* Initialize lin hardware registers */
        Lin_70_RL78F2X_SlvInit( (uint8)s_Lin_Config->Lin_GlobalConfig->LinChannel[chIndex].LinChannelId );
    }
}
 
#define LIN_STOP_SEC_CODE_LOCAL
#include "Lin_MemMap.h"
 
/* EOF Lin_70_HW.c ************************************************************/
 