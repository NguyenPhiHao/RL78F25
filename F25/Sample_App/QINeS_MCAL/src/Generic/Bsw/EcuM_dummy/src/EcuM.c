/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : EcuM.c                                                       */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "EcuM.h"
#include "SampleIcu.h"
#include "Gpt.h"
#include "SampleGpt.h"

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
void EcuM_CheckWakeup( EcuM_WakeupSourceType wakeupSource ) {
#if ( SAMPLE_ICU_ENABLE != FALSE )
    SampleIcu_Wakeup = TRUE;
#endif
#if ( SAMPLE_GPT_ENABLE != FALSE )
    Gpt_CheckWakeup( wakeupSource );
    SampleGpt_Wakeup = TRUE;
#endif
}

void EcuM_SetWakeupEvent( EcuM_WakeupSourceType sources ) {
}

/* EOF EcuM.c *****************************************************************/
