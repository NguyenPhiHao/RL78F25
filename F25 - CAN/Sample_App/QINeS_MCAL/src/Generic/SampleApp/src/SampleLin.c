/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : SampleLin.c                                                  */
/* Version     : v1.00.01                                                     */
/* Contents    : Lin sample application.                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Lin.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define SAMPLE_LIN_NUM_OF_PDU                  ( ( uint8 )4 )
#define LIN_SAMPLE_MASTER_SLAVE_BUILD          ( LIN_70_MASTER )

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
uint8   SampleLin_PduDataBuff[SAMPLE_LIN_NUM_OF_PDU][8] = {
        {0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
        {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08},
        {0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,0x2A,0x2B},
        {0x5A,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};

const Lin_PduType SampleLin_PduData[SAMPLE_LIN_NUM_OF_PDU] = {
#if ( LIN_SAMPLE_MASTER_SLAVE_BUILD == LIN_70_MASTER )  /* Master config */
    {/* MasterResponse */
        0xC1,   /* ID : 0x01 */
        LIN_ENHANCED_CS,  /* LIN_CLASSIC_CS LIN_ENHANCED_CS */
        LIN_FRAMERESPONSE_TX,
        1,
        SampleLin_PduDataBuff[0]
    },
    {/* SlaveResponse */
        0x42,   /* ID : 0x02 */
        LIN_ENHANCED_CS,  /* LIN_CLASSIC_CS LIN_ENHANCED_CS */
        LIN_FRAMERESPONSE_RX,
        4,
        SampleLin_PduDataBuff[1]
    },
    {/* MasterResponse */
        0x03, /* ID : 0x03 */
        LIN_ENHANCED_CS,  /* LIN_CLASSIC_CS LIN_ENHANCED_CS */
        LIN_FRAMERESPONSE_TX,
        8,  
        SampleLin_PduDataBuff[2]
    },
    {/* SlaveToSlave */
        0xC4,   /* ID : 0x04 */
        LIN_ENHANCED_CS,  /* LIN_CLASSIC_CS LIN_ENHANCED_CS */
        LIN_FRAMERESPONSE_RX,
        8,
        SampleLin_PduDataBuff[3]
    }
#else  /* Slave config */
    {/* MasterResponse */
        0xC1,   /* ID : 0x01 */
        LIN_ENHANCED_CS,  /* LIN_CLASSIC_CS LIN_ENHANCED_CS */
        LIN_FRAMERESPONSE_RX,
        1,
        SampleLin_PduDataBuff[0]
    },
    {/* SlaveResponse */
        0x42,   /* ID : 0x02 */
        LIN_ENHANCED_CS,  /* LIN_CLASSIC_CS LIN_ENHANCED_CS */
        LIN_FRAMERESPONSE_TX,
        4,
        SampleLin_PduDataBuff[1]
    },
    {/* MasterResponse */
        0x03, /* ID : 0x03 */
        LIN_ENHANCED_CS,  /* LIN_CLASSIC_CS LIN_ENHANCED_CS */
        LIN_FRAMERESPONSE_RX,
        8,  
        SampleLin_PduDataBuff[2]
    },
    {/* SlaveToSlave */
        0xC4,   /* ID : 0x04 */
        LIN_ENHANCED_CS,  /* LIN_CLASSIC_CS LIN_ENHANCED_CS */
        LIN_FRAMERESPONSE_TX,
        8,
        SampleLin_PduDataBuff[3]
    }
#endif /* Master / Slave config */
};

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
void SampleLin_Init( void ) {
    Lin_Init( &Lin_Config );
    Lin_WakeupInternal( LIN_CHANNEL_ID0 );
}

void SampleLin( void ) {

#if ( LIN_SAMPLE_MASTER_SLAVE_BUILD == LIN_70_MASTER )  /* Master node */
    Lin_StatusType ercd;
    Lin_PduType pduData;
    uint8* rcvData;
    uint32 local_lin_counter = 0;

    /* Wait time for next frame */
    while ( local_lin_counter < 2500000 )
    {
        local_lin_counter++;
    }
    local_lin_counter = 0;

    while( TRUE ) {
        /* PID 0x01 */
        pduData.Pid    = SampleLin_PduData[0].Pid;
        pduData.Cs     = SampleLin_PduData[0].Cs;
        pduData.Drc    = SampleLin_PduData[0].Drc;
        pduData.Dl     = SampleLin_PduData[0].Dl;
        pduData.SduPtr = SampleLin_PduData[0].SduPtr;
        Lin_SendFrame( LIN_CHANNEL_ID0, &pduData );

        ercd = LIN_TX_BUSY;
        while ( LIN_TX_BUSY == ercd ) {
            ercd = Lin_GetStatus( LIN_CHANNEL_ID0, &rcvData );
        }

        /* Wait time for next frame */
        while ( local_lin_counter < 2500000 )
        {
            local_lin_counter++;
        }
        local_lin_counter = 0;

        /* PID 0x02 */
        pduData.Pid    = SampleLin_PduData[1].Pid;
        pduData.Cs     = SampleLin_PduData[1].Cs;
        pduData.Drc    = SampleLin_PduData[1].Drc;
        pduData.Dl     = SampleLin_PduData[1].Dl;
        pduData.SduPtr = SampleLin_PduData[1].SduPtr;
        Lin_SendFrame( LIN_CHANNEL_ID0, &pduData );

        ercd = LIN_RX_BUSY;
        while ( LIN_RX_BUSY == ercd ) {
            ercd = Lin_GetStatus( LIN_CHANNEL_ID0, &rcvData );
        }

        /* Wait time for next frame */
        while ( local_lin_counter < 2500000 )
        {
            local_lin_counter++;
        }
        local_lin_counter = 0;

        /* PID 0x02 */
        pduData.Pid    = SampleLin_PduData[2].Pid;
        pduData.Cs     = SampleLin_PduData[2].Cs;
        pduData.Drc    = SampleLin_PduData[2].Drc;
        pduData.Dl     = SampleLin_PduData[2].Dl;
        pduData.SduPtr = SampleLin_PduData[2].SduPtr;
        Lin_SendFrame( LIN_CHANNEL_ID0, &pduData );

        ercd = LIN_TX_BUSY;
        while ( LIN_TX_BUSY == ercd ) {
            ercd = Lin_GetStatus( LIN_CHANNEL_ID0, &rcvData );
        }

        /* Wait time for next frame */
        while ( local_lin_counter < 2500000 )
        {
            local_lin_counter++;
        }
        local_lin_counter = 0;

        /* PID 0x03 */
        pduData.Pid    = SampleLin_PduData[3].Pid;
        pduData.Cs     = SampleLin_PduData[3].Cs;
        pduData.Drc    = SampleLin_PduData[3].Drc;
        pduData.Dl     = SampleLin_PduData[3].Dl;
        pduData.SduPtr = SampleLin_PduData[3].SduPtr;
        Lin_SendFrame( LIN_CHANNEL_ID0, &pduData );

        ercd = LIN_RX_BUSY;
        while ( LIN_RX_BUSY == ercd ) {
            ercd = Lin_GetStatus( LIN_CHANNEL_ID0, &rcvData );
        }

        /* Wait time for next frame */
        while ( local_lin_counter < 2500000 )
        {
            local_lin_counter++;
        }
        local_lin_counter = 0;

    }
#endif
}

/* EOF SampleLin.c ************************************************************/
