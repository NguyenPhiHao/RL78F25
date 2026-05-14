/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : LinIf.c                                                      */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/*   Include Files                                                            */
/*----------------------------------------------------------------------------*/
#include "LinIf.h"
#include "Lin.h"

extern uint8             SampleLin_PduDataBuff[8][8];
extern const Lin_PduType SampleLin_PduData[4];

/* Slave node config data */
#define SAMPLE_LIN_NUM_OF_PDU                  ( ( uint8 )4 )
#define LIN_IF_MASTER_SLAVE_BUILD              ( LIN_70_SLAVE)

extern const Lin_ConfigType  Lin_Config;
extern const Lin_PduType     SampleLin_PduData[SAMPLE_LIN_NUM_OF_PDU];

#if ( LIN_IF_MASTER_SLAVE_BUILD == LIN_70_SLAVE ) 
static const Lin_PduType * lin_getpdu(uint8 id);

static const Lin_PduType * lin_getpdu(uint8 id)
{
    uint8_least i;
 
    for (i = 0; i < SAMPLE_LIN_NUM_OF_PDU; i++) {
        if (id == SampleLin_PduData[i].Pid) {
            return &SampleLin_PduData[i];
        }
    }
    return NULL_PTR;
}
#endif /* ( LIN_IF_MASTER_SLAVE_BUILD == LIN_70_SLAVE ) */

void LinIf_WakeupConfirmation( EcuM_WakeupSourceType WakeupSource ) {
}

/* [SWS_LinIf_91007] */
void LinIf_LinErrorIndication ( NetworkHandleType Channel, Lin_SlaveErrorType ErrorStatus ) {
}

Std_ReturnType LinIf_HeaderIndication ( NetworkHandleType Channel, Lin_PduType* PduPtr ) {
#if ( LIN_IF_MASTER_SLAVE_BUILD == LIN_70_SLAVE )
    const Lin_PduType*    pdu;
    Std_ReturnType  retCode;
    uint32          i;
    pdu = lin_getpdu( PduPtr->Pid );
 
    if ( pdu == NULL_PTR ) {
        retCode = E_NOT_OK;
    } else {
        PduPtr->Cs  = pdu->Cs;
        PduPtr->Drc = pdu->Drc;
        PduPtr->Dl  = pdu->Dl;
 
        /* response Tx */
        if ( LIN_FRAMERESPONSE_TX == pdu->Drc ) {
            /* copy Tx data */
            for( i=0; i< pdu->Dl; i++ ) {
                PduPtr->SduPtr[i] = pdu->SduPtr[i];
            }
        }
        retCode = E_OK;
    }
 
    return retCode;
#else  /* ( LIN_IF_MASTER_SLAVE_BUILD == LIN_70_SLAVE ) */
    return E_OK;
#endif /* ( LIN_IF_MASTER_SLAVE_BUILD == LIN_70_SLAVE ) */
}

/* SWS_LinIf_91005] */
void LinIf_RxIndication ( NetworkHandleType Channel, uint8* Lin_SduPtr ) {
}

/* [SWS_LinIf_91006] */
void LinIf_TxConfirmation ( NetworkHandleType Channel ) {
}

/* EOF LinIf.c ****************************************************************/