/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Lin_70_HW.h                                                  */
/* Version     : v1.00.02                                                     */
/* Contents    : LIN Module wrapper header                                    */
/*               The LIN is a basic software module at                        */
/*               the service layer of                                         */
/*               the standardized basic software archi-                       */
/*               tecture of AUTOSAR.                                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of LIN Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef LIN_70_HW_H
#define LIN_70_HW_H

/*---------------------------------------------------------------*/
/* include headers                                               */
/*---------------------------------------------------------------*/
#include "ComStack_Types.h"        /* [SWS_Lin_00226] */
#include "Lin_GeneralTypes.h"      /* [SWS_Lin_00245] */
#include "Lin_70_Types.h"
#include "Lin_70_RL78F2X.h"
#include "Lin_Slave_70_RL78F2X.h"
#include "Lin_Cfg.h"

/*---------------------------------------------------------------*/
/* file version information                                      */
/*---------------------------------------------------------------*/
#define LIN_70_VENDOR_ID_HW_H                ( 70U )
#define LIN_70_MODULE_ID_HW_H                ( 82U )

#define LIN_70_AR_RELEASE_MAJOR_VERSION_HW_H ( 22U )
#define LIN_70_AR_RELEASE_MINOR_VERSION_HW_H ( 11U )
#define LIN_70_AR_RELEASE_REVISION_VERSION_HW_H ( 0U )

#define LIN_70_SW_MAJOR_VERSION_HW_H         ( 1U )
#define LIN_70_SW_MINOR_VERSION_HW_H         ( 0U )
#define LIN_70_SW_PATCH_VERSION_HW_H         ( 0U )

/*---------------------------------------------------------------*/
/* file version checks                                           */
/*---------------------------------------------------------------*/
/* ------------- no file -------------- */

/*---------------------------------------------------------------*/
/* extern variable                                               */
/*---------------------------------------------------------------*/
/* Config data pointer */
extern Lin_70_ChannelStatusType   s_Lin_Status[LIN_70_NUM_OF_CHANNEL];

/*---------------------------------------------------------------*/
/* macros                                                        */
/*---------------------------------------------------------------*/
#define Lin_70_HW_ReadModeStatusReg()                 Lin_70_RL78F2X_ReadModeStatusReg()
#define Lin_70_HW_SetFrameId( PduInfoPtr )            Lin_70_RL78F2X_SetFrameId( ( PduInfoPtr ) )
#define Lin_70_HW_SetFrameType( frameType )           Lin_70_RL78F2X_SetFrameType( ( frameType ) )
#define Lin_70_HW_GoToSleep()                         Lin_70_RL78F2X_GoToSleep()
#define Lin_70_HW_SetWakeupTransMode()                Lin_70_RL78F2X_SetWakeupTransMode()
#define Lin_70_HW_ClrInt_ChkErr( mode )               Lin_70_RL78F2X_ClrInt_ChkErr( ( mode ) )
#define Lin_70_HW_CheckTransFlags()                   Lin_70_RL78F2X_CheckTransFlags()
#define Lin_70_HW_TimeoutErrCheck()                   Lin_70_RL78F2X_TimeoutErrCheck()
#define Lin_70_HW_ReadReceivedData( LinFrameBufPtr )  Lin_70_RL78F2X_ReadReceivedData( ( LinFrameBufPtr ) )
#define Lin_70_HW_StartCommunication()                Lin_70_RL78F2X_StartCommunication()
#define Lin_70_HW_StartResponse()                     Lin_70_RL78F2X_StartResponse()
#define Lin_70_HW_DisableInterrupts( channelId )      Lin_70_RL78F2X_DisableInterrupts( ( channelId ) )
#define Lin_70_HW_EnableInterrupts( channelId )       Lin_70_RL78F2X_EnableInterrupts( ( channelId ) )
#define Lin_70_HW_ClearInterrupts( channelId )        Lin_70_RL78F2X_ClearInterrupts( ( channelId ) )
#define Lin_70_HW_ModeChange( modeChange, timeout )   Lin_70_RL78F2X_ModeChange( ( modeChange ), ( timeout ) )

/*---------------------------------------------------------------*/
/* function prototype declarations                               */
/*---------------------------------------------------------------*/
void Lin_70_HW_Init( const uint8 chIndex );
void Lin_70_HW_InitParameter( const uint8 chIndex );
void Lin_70_HW_SetConfigPtr( const Lin_ConfigType* config );

void Lin_70_HW_ErrorIndication( uint8 chIndex, Lin_SlaveErrorType errId );
void Lin_70_HW_ChangeChannel( const uint8 chIndex );

#endif /* #ifndef LIN_70_HW_H */
/* End Of File */