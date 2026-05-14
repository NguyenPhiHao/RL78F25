/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : SampleSpi.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : Spi sample application.                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "SampleSpi.h"
#include "Spi.h"
#if ( COMPILER == COMPILER_IAR )
#include "intrinsics.h"
#endif
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define EEP_Q_OPCODE_WREN           ( 0x06 )    /* opcode:Enable Write Operations */
#define EEP_Q_OPCODE_WRITE          ( 0x02 )    /* opcode:Write Data to Memory    */
#define EEP_Q_OPCODE_READ           ( 0x03 )    /* opcode:Read Data from Memory   */

/* use channel id  */
#define EEP_Q_CHANNEL_ID_WREN_IB  ( (Spi_ChannelType)6U ) /* channel id:Enable Write Operations */
#define EEP_Q_CHANNEL_ID_WRITE_IB ( (Spi_ChannelType)9U ) /* channel id:Write Data to Memory */
#define EEP_Q_CHANNEL_ID_READ_IB  ( (Spi_ChannelType)7U ) /* channel id:Read Data from Memory */

/* use sequence id  */
#define EEP_Q_SEQ_ID_WREN_IB        ( 6U )      /* sequence id:Enable Write Operations */
#define EEP_Q_SEQ_ID_WRITE_IB       ( 9U )      /* sequence id:Write Data to Memory */
#define EEP_Q_SEQ_ID_READ_IB        ( 7U )      /* sequence id:Read Data from Memory */

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
#if ( SAMPLE_SPI_ENABLE != FALSE )
Spi_DataBufferType SampleSpi_SendData[14];
Spi_DataBufferType SampleSpi_ReceiveData[14];
Std_ReturnType SampleSpi_Ret;
#endif

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#if ( SAMPLE_SPI_ENABLE != FALSE )
void SampleSpi_Init( void ) {
    Spi_Init( &Spi_ConfigData );
}

void SampleSpi( void ){
    volatile uint32 i;
   
    /* WREN instruction */
    SampleSpi_SendData[0] = EEP_Q_OPCODE_WREN;
    SampleSpi_SendData[1] = 0x00U;
    SampleSpi_Ret = Spi_WriteIB( EEP_Q_CHANNEL_ID_WREN_IB, &SampleSpi_SendData[0] );
    SampleSpi_Ret = Spi_SyncTransmit( EEP_Q_SEQ_ID_WREN_IB );

    /* WRITE instruction */
    SampleSpi_SendData[0] = EEP_Q_OPCODE_WRITE; /* Opecode */
    SampleSpi_SendData[1] = 0x00U;
    SampleSpi_SendData[2] = 0x00U;  /* Address */
    SampleSpi_SendData[3] = 0x00U;
    SampleSpi_SendData[4] = 0x01U;  /* 1st byte, address 0x00 */
    SampleSpi_SendData[5] = 0x00U;
    SampleSpi_SendData[6] = 0x02U;  /* 2nd byte, address 0x01 */
    SampleSpi_SendData[7] = 0x00U;
    SampleSpi_SendData[8] = 0x03U;  /* 3rd byte, address 0x02 */
    SampleSpi_SendData[9] = 0x00U;
    SampleSpi_SendData[10] = 0x04U; /* 4th byte, address 0x03 */
    SampleSpi_SendData[11] = 0x00U;
    SampleSpi_SendData[12] = 0x05U; /* 5th byte, address 0x04 */
    SampleSpi_SendData[13] = 0x00U;
    SampleSpi_Ret = Spi_WriteIB( EEP_Q_CHANNEL_ID_WRITE_IB, &SampleSpi_SendData[0] );
    SampleSpi_Ret = Spi_SyncTransmit( EEP_Q_SEQ_ID_WRITE_IB );

    /* Waiting for writing (more than 5ms)    */
    /* for EEPROM ON Semiconductor CAT25040   */
    for ( i = 0U; i < 10000U; i++ );

    /* READ instruction */
    SampleSpi_SendData[0] = EEP_Q_OPCODE_READ; /* Opecode */
    SampleSpi_SendData[1] = 0x00U;
    SampleSpi_SendData[2] = 0x00U;  /* Address */
    SampleSpi_SendData[3] = 0x00U;
    SampleSpi_SendData[4] = 0x00U;
    SampleSpi_SendData[5] = 0x00U;
    SampleSpi_SendData[6] = 0x00U;
    SampleSpi_SendData[7] = 0x00U;
    SampleSpi_SendData[8] = 0x00U;
    SampleSpi_SendData[9] = 0x00U;
    SampleSpi_SendData[10] = 0x00U;
    SampleSpi_SendData[11] = 0x00U;
    SampleSpi_SendData[12] = 0x00U;
    SampleSpi_SendData[13] = 0x00U;
    SampleSpi_Ret = Spi_WriteIB( EEP_Q_CHANNEL_ID_READ_IB, &SampleSpi_SendData[0] );
    SampleSpi_Ret = Spi_SyncTransmit( EEP_Q_SEQ_ID_READ_IB );
    SampleSpi_Ret = Spi_ReadIB( EEP_Q_SEQ_ID_READ_IB , &SampleSpi_ReceiveData[0] );
}
#endif

/* Notification functions */
void Spi_SeqEndNotification_0( void ){}
void Spi_SeqEndNotification_1( void ){}
void Spi_SeqEndNotification_2( void ){}
void Spi_SeqEndNotification_3( void ){}
void Spi_SeqEndNotification_4( void ){}
void Spi_SeqEndNotification_5( void ){}
void Spi_SeqEndNotification_6( void ){}
void Spi_SeqEndNotification_7( void ){}
void Spi_SeqEndNotification_8( void ){}
void Spi_SeqEndNotification_9( void ){}
void Spi_SeqEndNotification_10( void ){}
void Spi_JobEndNotification_0( void ){}
void Spi_JobEndNotification_1( void ){}
void Spi_JobEndNotification_2( void ){}
void Spi_JobEndNotification_3( void ){}
void Spi_JobEndNotification_4( void ){}
void Spi_JobEndNotification_5( void ){}
void Spi_JobEndNotification_6( void ){}
void Spi_JobEndNotification_7( void ){}
void Spi_JobEndNotification_8( void ){}
void Spi_JobEndNotification_9( void ){}
