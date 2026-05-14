/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : CanIf_Cbk.h                                                  */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef CANIF_CBK_H
#define CANIF_CBK_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "CanIf.h"

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define CANIF_70_AR_RELEASE_MAJOR_VERSION_CBK_H     ( 22U )
#define CANIF_70_AR_RELEASE_MINOR_VERSION_CBK_H     ( 11U )

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern void CanIf_TxConfirmation( PduIdType CanTxPduId );
extern void CanIf_RxIndication( const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr );
extern void CanIf_ControllerBusOff( uint8 ControllerId );
extern void CanIf_ControllerModeIndication( uint8 ControllerId, Can_ControllerStateType ControllerMode );
extern void CanIf_CancelTxConfirmation( PduIdType CanTxPduId, const PduInfoType* PduInfoPtr );
extern Std_ReturnType CanIf_TriggerTransmit( PduIdType TxPduId, PduInfoType* PduInfoPtr );
extern void CanIf_ControllerErrorStatePassive( uint8 ControllerId, uint16 RxErrorCounter, uint16 TxErrorCounter );
extern void CanIf_ErrorNotification( uint8 ControllerId, Can_ErrorType Can_ErrorType );

#endif /* CANIF_CBK_H */

/* EOF CanIf_Cbk.h ************************************************************/
