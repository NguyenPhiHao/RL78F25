/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : EcuM_Types.h                                                 */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef ECUM_TYPES_H
#define ECUM_TYPES_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/* [SWS_EcuM_00047] */
typedef uint8  EcuM_StateType;
/* [SWS_EcuM_00048] */
typedef uint16 EcuM_UserType;
/* [SWS_EcuM_00049] */
typedef uint16 EcuM_FlexUserType;
/* [SWS_EcuM_00050] */
typedef uint32 EcuM_WakeupSourceType;
/* [SWS_EcuM_00051] */
typedef uint8  EcuM_WakeupStatusType;
/* [SWS_EcuM_00051] */
typedef uint8  EcuM_WakeupReactionType;
/* [SWS_EcuM_00036] */
typedef uint8  EcuM_BootTargetType;
/* [SWS_EcuM_04044] */
typedef uint8  EcuM_ResetType;
/* [SWS_EcuM_04045] */
typedef uint8  EcuM_ShutdownCauseType;

/* [SWS_EcuM_04136] */
#if ( ECUM_Q_FLEX != FALSE )
typedef uint8  EcuM_ShutdownTargetType;
#endif /* ECUM_Q_FLEX != FALSE */

/* [SWS_EcuM_04102] */
typedef uint32 EcuM_TimeType;

/* type definitions for EcuM_Cfg.h */

/* [ECUC_EcuM_00132] */
typedef uint8                                     EcuM_SleepModeIdType;
/* [ECUC_EcuM_00151] */
typedef uint8                                     EcuM_WakeupSourceIdType;
/* [ECUC_EcuM_00202] */
typedef uint8                                     EcuM_FixedUserType;
/* [SWS_EcuM_04101] */

#if ( ECUM_Q_FLEX != FALSE )
typedef uint8              EcuM_ShutdownModeType;
#endif /* ECUM_Q_FLEX != FALSE */
/* [SWS_EcuM_04120] */
typedef uint8              EcuM_RunStatusType;

typedef enum {
    ECUM_NVMTYPE_READ,
    ECUM_NVMTYPE_WRITE
} EcuM_Q_NvMType;

typedef uint8                                     EcuM_Q_NextPhaseType;

typedef enum {
    ECUM_API_CONFIG_CLASS_1,
    ECUM_API_CONFIG_CLASS_2,
    ECUM_API_CONFIG_CLASS_3
} EcuM_Q_ApiConfigClassType;

/*typedef Rte_ModeType_EcuM_Mode                 EcuM_ModeType;*/
typedef uint8                                    EcuM_ModeType;

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

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

#endif /* ECUM_TYPES_H */

/* EOF EcuM_Types.h ***********************************************************/
