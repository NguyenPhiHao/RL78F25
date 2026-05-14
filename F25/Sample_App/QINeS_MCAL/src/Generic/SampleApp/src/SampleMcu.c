/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : SampleMcu.c                                                  */
/* Version     : v1.00.02                                                     */
/* Contents    : Mcu sample application.                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "SampleMcu.h"
#include "Mcu.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

#define IT101_MCU_s024_001_001        (0U)
#define IT101_MCU_s024_001_002        (1U)
#define IT101_MCU_s024_001_003        (2U)
#define IT101_MCU_s024_001_004        (3U)
#define IT101_MCU_s024_001_005        (4U)
#define IT101_MCU_s024_001_006        (5U)
#define IT101_MCU_s024_001_007        (6U)
#define IT101_MCU_s024_001_008        (7U)
#define IT101_MCU_s024_001_009        (8U)
#define IT101_MCU_s024_001_010        (9U)
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
#if ( SAMPLE_MCU_ENABLE != FALSE )
Mcu_PllStatusType   SampleMcu_PllSts;
Mcu_ResetType       SampleMcu_ResetReason;
Mcu_RawResetType    SampleMcu_ResetReasonRaw;
Mcu_RamStateType    SampleMcu_RamState;
uint8               SampleMcu_Ret[11];
#endif

uint8 SampleMcu_Buf[30];

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#if ( SAMPLE_MCU_ENABLE != FALSE )
void SampleMcu( void ) {

    uint16         i;
    /*
     * 3.2.3 Mcu module sample function
     */
    for ( i = 0; i < IT101_MCU_s024_001_010 + 2; i++) {
        SampleMcu_Ret[i] = 0xffU;
    }

    /* Initialize the Mcu module */
    Mcu_Init( &Mcu_Config );

    SampleMcu_Ret[ IT101_MCU_s024_001_001 ] = E_OK;

    /* Initialize the clock */
    SampleMcu_Ret[ IT101_MCU_s024_001_002 ] = Mcu_InitClock( MCU_70_CLOCK_NORMAL );

    do {
        /* Get PLL state */
        SampleMcu_PllSts = Mcu_GetPllStatus();
    } while ( MCU_PLL_UNLOCKED == SampleMcu_PllSts );
    SampleMcu_Ret[ IT101_MCU_s024_001_003 ] = E_OK;

    /* Enable PLL clock */
    SampleMcu_Ret[ IT101_MCU_s024_001_004 ] = Mcu_DistributePllClock();

    /* Initialize the RAM section */
    SampleMcu_Ret[ IT101_MCU_s024_001_005 ] = Mcu_InitRamSection( MCU_70_RAM_SECTOR_0 );

    /* Get RAM state */
    SampleMcu_Ret[ IT101_MCU_s024_001_006 ] = Mcu_GetRamState();

    /* Set operation mode */
    Mcu_SetMode( McuConf_McuModeSettingConf_MCUMODE_NORMAL );

    SampleMcu_Ret[ IT101_MCU_s024_001_007 ] = E_OK;
    /* End of program */
    while ( TRUE ) {
        FUNC_NO_OPERATION;
    }
}
#endif
