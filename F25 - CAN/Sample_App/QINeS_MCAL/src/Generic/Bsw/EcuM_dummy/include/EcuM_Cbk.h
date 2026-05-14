/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : EcuM_Cbk.h                                                   */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef ECUM_CBK_H
#define ECUM_CBK_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "EcuM_AR.h"
#include "EcuM_Types.h"
#if ( ECUM_Q_FLEX == FALSE )
#if ( ECUM_Q_MOD_NVM_ENABLED != FALSE )
#include "NvM.h"
#endif /* ECUM_Q_MOD_NVM_ENABLED */
#endif /* ECUM_Q_FLEX */

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ECUM_AR_RELEASE_MAJOR_VERSION_CBK_H     ( 22U )
#define ECUM_AR_RELEASE_MINOR_VERSION_CBK_H     ( 11U )
#define ECUM_AR_RELEASE_REVISION_VERSION_CBK_H  (  0U )

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* ServiceID */
/* Callback Definitions */
/* Callbacks from NVRAM Manager */
#if ( ECUM_Q_FLEX == FALSE )
#if ( ECUM_Q_MOD_NVM_ENABLED != FALSE )
#define ECUM_CB_NVMJOBEND_ID                    (uint8)(0x65U)
#endif /* ECUM_Q_MOD_NVM_ENABLED */
#endif /* ECUM_Q_FLEX */
/* Callbacks from wake up Sources */
#define ECUM_SETWAKEUPEVENT_ID                  (uint8)(0x0CU)
#define ECUM_VALIDATEWAKEUPEVENT_ID             (uint8)(0x14U)
/* Callouts from SLEEP State */
#define ECUM_CHECKWAKEUP_ID                     (uint8)(0x99U)
/* Callbacks from GPT */
#define ECUM_Q_CB_GPTTIMERCOUNT_ID              (uint8)(0xA9U)
#if ( ECUM_Q_FLEX != FALSE )
#if ( ECUM_ALARM_CLOCK_PRESENT != FALSE )
#define ECUM_Q_CB_ALARM_ID                      (uint8)(0xECU)
#endif /* ECUM_ALARM_CLOCK_PRESENT */
#endif /* ECUM_Q_FLEX */

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
/* Callback Definitions */
void EcuM_SetWakeupEvent( EcuM_WakeupSourceType sources );
void EcuM_CheckWakeup( EcuM_WakeupSourceType wakeupSource );

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

#endif /* ECUM_CBK_H */

/* EOF EcuM_Cbk.h *************************************************************/
