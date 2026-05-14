/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : CanIf.c                                                      */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "CanIf.h"
#include "CanIf_Cbk.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
void CanIf_TxConfirmation( PduIdType CanTxPduId ) {
}

void CanIf_RxIndication( const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr ) {
}

void CanIf_ControllerBusOff( uint8 ControllerId ) {
}

void CanIf_ControllerModeIndication( uint8 ControllerId, Can_ControllerStateType ControllerMode ) {
}

void CanIf_CancelTxConfirmation( PduIdType CanTxPduId, const PduInfoType* PduInfoPtr ) {
}

Std_ReturnType CanIf_TriggerTransmit( PduIdType TxPduId, PduInfoType* PduInfoPtr ) {
    return E_NOT_OK;
}

void CanIf_ControllerErrorStatePassive( uint8 ControllerId, uint16 RxErrorCounter, uint16 TxErrorCounter ) {
}

void CanIf_ErrorNotification( uint8 ControllerId, Can_ErrorType Can_ErrorType ) {
}

/* EOF CanIf.c ****************************************************************/
