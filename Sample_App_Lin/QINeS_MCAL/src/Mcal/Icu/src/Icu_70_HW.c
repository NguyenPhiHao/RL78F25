/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Icu_70_HW.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : ICU Module wrapper                                           */
/*               The ICU is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     :                                                              */
/*----------------------------------------------------------------------------*/
/* Specification of ICU Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Icu.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
 
#define ICU_70_VENDOR_ID_HW_C                      (70U)
#define ICU_70_MODULE_ID_HW_C                      (122U)
 
#define ICU_70_AR_RELEASE_MAJOR_VERSION_HW_C       (22U)
#define ICU_70_AR_RELEASE_MINOR_VERSION_HW_C       (11U)
#define ICU_70_AR_RELEASE_REVISION_VERSION_HW_C    (0U)
 
#define ICU_70_SW_MAJOR_VERSION_HW_C               (1U)
#define ICU_70_SW_MINOR_VERSION_HW_C               (0U)
#define ICU_70_SW_PATCH_VERSION_HW_C               (0U)
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Icu.h version check start */
 
#if ( ICU_70_VENDOR_ID_HW_C != ICU_VENDOR_ID )
    #error "VENDOR ID for Icu_70_HW.c and Icu.h are different"
#endif
 
#if ( ICU_70_MODULE_ID_HW_C != ICU_MODULE_ID )
    #error "MODULE ID for Icu_70_HW.c and Icu.h are different"
#endif
 
#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_HW_C    != ICU_AR_RELEASE_MAJOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_HW_C    != ICU_AR_RELEASE_MINOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_HW_C != ICU_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_HW.c and Icu.h are different"
#endif
 
#if ( ( ICU_70_SW_MAJOR_VERSION_HW_C != ICU_SW_MAJOR_VERSION ) || \
      ( ICU_70_SW_MINOR_VERSION_HW_C != ICU_SW_MINOR_VERSION ) || \
      ( ICU_70_SW_PATCH_VERSION_HW_C != ICU_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Icu_70_HW.c and Icu.h are different"
#endif
 
/* Icu.h version check end */
 
/* Icu_70_HW.h version check start */
 
#if ( ICU_70_VENDOR_ID_HW_C != ICU_70_VENDOR_ID_HW_H )
    #error "VENDOR ID for Icu_70_HW.c and Icu_70_HW.h are different"
#endif
 
#if ( ICU_70_MODULE_ID_HW_C != ICU_70_MODULE_ID_HW_H )
    #error "MODULE ID for Icu_70_HW.c and Icu_70_HW.h are different"
#endif
 
#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_HW_C    != ICU_70_AR_RELEASE_MAJOR_VERSION_HW_H ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_HW_C    != ICU_70_AR_RELEASE_MINOR_VERSION_HW_H ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_HW_C != ICU_70_AR_RELEASE_REVISION_VERSION_HW_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_HW.c and Icu_70_HW.h are different"
#endif
 
#if ( ( ICU_70_SW_MAJOR_VERSION_HW_C != ICU_70_SW_MAJOR_VERSION_HW_H ) || \
      ( ICU_70_SW_MINOR_VERSION_HW_C != ICU_70_SW_MINOR_VERSION_HW_H ) || \
      ( ICU_70_SW_PATCH_VERSION_HW_C != ICU_70_SW_PATCH_VERSION_HW_H ) \
    )
    #error "Software Version Numbers of Icu_70_HW.c and Icu_70_HW.h are different"
#endif
 
/* Icu_70_HW.h version check end */
/* Icu_70_RL78F2X.h version check start */
 
#if ( ICU_70_VENDOR_ID_HW_C != ICU_70_VENDOR_ID_RL78F2X_H )
    #error "VENDOR ID for Icu_70_HW.c and Icu_70_RL78F2X.h are different"
#endif
 
#if ( ICU_70_MODULE_ID_HW_C != ICU_70_MODULE_ID_RL78F2X_H )
    #error "MODULE ID for Icu_70_HW.c and Icu_70_RL78F2X.h are different"
#endif
 
#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_HW_C    != ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_HW_C    != ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_HW_C != ICU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_HW.c and Icu_70_RL78F2X.h are different"
#endif
 
#if ( ( ICU_70_SW_MAJOR_VERSION_HW_C != ICU_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( ICU_70_SW_MINOR_VERSION_HW_C != ICU_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( ICU_70_SW_PATCH_VERSION_HW_C != ICU_70_SW_PATCH_VERSION_RL78F2X_H ) \
    )
    #error "Software Version Numbers of Icu_70_HW.c and Icu_70_RL78F2X.h are different"
#endif
 
/* Icu_70_RL78F2X.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
typedef void ( *Icu_70_HW_InitFuncType )( const Icu_70_HW_SetConfType* confPtr, uint8 actEdge );
#if ( ICU_DE_INIT_API  == TRUE )
typedef void ( *Icu_70_HW_DeInitFuncType )( const Icu_70_HW_SetConfType* confPtr );
#endif /* #if ( ICU_DE_INIT_API  == TRUE ) */
#if ( ICU_70_TIMER_API_ENABLE != FALSE )
typedef void ( *Icu_70_HW_StartTimerFuncType )
             ( const Icu_70_HW_SetConfType* confPtr, uint8 actEdge );
typedef void ( *Icu_70_HW_StopTimerFuncType )( const Icu_70_HW_SetConfType* confPtr );
#endif /* #if ( ICU_70_TIMER_API_ENABLE != FALSE ) */
#if ( ICU_70_EDGE_API_ENABLE != FALSE )
typedef void ( *Icu_70_HW_EnableEdgeType )( const Icu_70_HW_SetConfType* confPtr, uint8 actEdge );
typedef void ( *Icu_70_HW_DisableEdgeType )( const Icu_70_HW_SetConfType* confPtr );
#endif /* #if ( ICU_70_EDGE_API_ENABLE != FALSE ) */
typedef void ( *Icu_70_HW_SetActivationConditionType )
                        ( const Icu_70_HW_SetConfType* confPtr, uint8 actEdge );
#if ( ICU_SET_MODE_API != FALSE )
typedef void ( *Icu_70_HW_EnableIntType )( const Icu_70_HW_SetConfType* confPtr, uint8 actEdge );
typedef void ( *Icu_70_HW_DisableIntType )( const Icu_70_HW_SetConfType* confPtr );
#endif /* #if ( ICU_SET_MODE_API != FALSE) */
/*----------------------------------------------------------------------------*/
/* global variables                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#define ICU_START_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"
 
/* function table for input type */
static const Icu_70_HW_InitFuncType s_IcuHwInitFuncTbl[ICU_70_INPUT_INPUTTYPE_NUM] = {
#if ( ICU_70_ENABLE_TAU_ANY == TRUE )
    ( Icu_70_HW_InitFuncType )Icu_70_RL78F2X_TAU_Init,
#endif/* ( ICU_70_ENABLE_TAU_ANY == TRUE ) */
#if ( ICU_70_ENABLE_TRD_ANY == TRUE )
    ( Icu_70_HW_InitFuncType )Icu_70_RL78F2X_TRD_Init,
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
#if ( ICU_70_ENABLE_INTP_ANY == TRUE )
    ( Icu_70_HW_InitFuncType )Icu_70_RL78F2X_INTP_Init
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
};
#if ( ICU_DE_INIT_API != FALSE )
/* function table for timer type */
static const Icu_70_HW_DeInitFuncType s_IcuHwDeInitFuncTbl[ICU_70_INPUT_INPUTTYPE_NUM] = {
#if ( ICU_70_ENABLE_TAU_ANY == TRUE )
    ( Icu_70_HW_DeInitFuncType )Icu_70_RL78F2X_TAU_DeInit,
#endif/* ( ICU_70_ENABLE_TAU_ANY == TRUE ) */
#if ( ICU_70_ENABLE_TRD_ANY == TRUE )
    ( Icu_70_HW_DeInitFuncType )Icu_70_RL78F2X_TRD_DeInit,
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
#if ( ICU_70_ENABLE_INTP_ANY == TRUE )
    ( Icu_70_HW_DeInitFuncType )Icu_70_RL78F2X_INTP_DeInit
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
};
#endif /* #if ( ICU_DE_INIT_API != FALSE ) */
#if ( ICU_70_TIMER_API_ENABLE != FALSE )
/* function table for timer type */
static const Icu_70_HW_StartTimerFuncType s_IcuHwStartTimerFuncTbl[ICU_70_INPUT_INPUTTYPE_NUM] = {
#if ( ICU_70_ENABLE_TAU_ANY == TRUE )
    ( Icu_70_HW_StartTimerFuncType )Icu_70_RL78F2X_TAU_StartTimer,
#endif/* ( ICU_70_ENABLE_TAU_ANY == TRUE ) */
#if ( ICU_70_ENABLE_TRD_ANY == TRUE )
    ( Icu_70_HW_StartTimerFuncType )Icu_70_RL78F2X_TRD_StartTimer,
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
#if ( ICU_70_ENABLE_INTP_ANY == TRUE )
    ( Icu_70_HW_StartTimerFuncType )NULL_PTR
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
};
/* function table for timer type */
static const Icu_70_HW_StopTimerFuncType s_IcuHwStopTimerFuncTbl[ICU_70_INPUT_INPUTTYPE_NUM] = {
#if ( ICU_70_ENABLE_TAU_ANY == TRUE )
    ( Icu_70_HW_StopTimerFuncType )Icu_70_RL78F2X_TAU_StopTimer,
#endif/* ( ICU_70_ENABLE_TAU_ANY == TRUE ) */
#if ( ICU_70_ENABLE_TRD_ANY == TRUE )
    ( Icu_70_HW_StopTimerFuncType )Icu_70_RL78F2X_TRD_StopTimer,
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
#if ( ICU_70_ENABLE_INTP_ANY == TRUE )
    ( Icu_70_HW_StopTimerFuncType )NULL_PTR
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
};
#endif /* #if ( ICU_70_TIMER_API_ENABLE != FALSE ) */
#if ( ICU_70_EDGE_API_ENABLE != FALSE )
/* function table for timer type */
static const Icu_70_HW_EnableEdgeType s_IcuHwEnableEdgeTbl[ICU_70_INPUT_INPUTTYPE_NUM] = {
#if ( ICU_70_ENABLE_TAU_ANY == TRUE )
    ( Icu_70_HW_EnableEdgeType )Icu_70_RL78F2X_TAU_StartTimer,
#endif/* ( ICU_70_ENABLE_TAU_ANY == TRUE ) */
#if ( ICU_70_ENABLE_TRD_ANY == TRUE )
    ( Icu_70_HW_EnableEdgeType )Icu_70_RL78F2X_TRD_EnableEdge,
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
#if ( ICU_70_ENABLE_INTP_ANY == TRUE )
    ( Icu_70_HW_EnableEdgeType )Icu_70_RL78F2X_INTP_EnableEdge
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
};
/* function table for timer type */
static const Icu_70_HW_DisableEdgeType s_IcuHwDisableEdgeTbl[ICU_70_INPUT_INPUTTYPE_NUM] = {
#if ( ICU_70_ENABLE_TAU_ANY == TRUE )
    ( Icu_70_HW_DisableEdgeType )Icu_70_RL78F2X_TAU_StopTimer,
#endif/* ( ICU_70_ENABLE_TAU_ANY == TRUE ) */
#if ( ICU_70_ENABLE_TRD_ANY == TRUE )
    ( Icu_70_HW_DisableEdgeType )Icu_70_RL78F2X_TRD_DisableEdge,
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
#if ( ICU_70_ENABLE_INTP_ANY == TRUE )
    ( Icu_70_HW_DisableEdgeType )Icu_70_RL78F2X_INTP_DisableEdge
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
};
#endif /* #if ( ICU_70_EDGE_API_ENABLE != FALSE ) */
/* function table for timer type */
static const Icu_70_HW_SetActivationConditionType
                s_IcuHwSetActivationConditionTbl[ICU_70_INPUT_INPUTTYPE_NUM] = {
#if ( ICU_70_ENABLE_TAU_ANY == TRUE )
    ( Icu_70_HW_SetActivationConditionType )Icu_70_RL78F2X_TAU_SetActivationCondition,
#endif/* ( ICU_70_ENABLE_TAU_ANY == TRUE ) */
#if ( ICU_70_ENABLE_TRD_ANY == TRUE )
    ( Icu_70_HW_SetActivationConditionType )Icu_70_RL78F2X_TRD_SetActivationCondition,
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
#if ( ICU_70_ENABLE_INTP_ANY == TRUE )
    ( Icu_70_HW_SetActivationConditionType )Icu_70_RL78F2X_INTP_EnableEdge
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
};
#if ( ICU_SET_MODE_API != FALSE )
/* function table for timer type */
static const Icu_70_HW_EnableIntType s_IcuHwEnableIntTbl[ICU_70_INPUT_INPUTTYPE_NUM] = {
#if ( ICU_70_ENABLE_TAU_ANY == TRUE )
    ( Icu_70_HW_EnableIntType )Icu_70_RL78F2X_TAU_EnableInt,
#endif/* ( ICU_70_ENABLE_TAU_ANY == TRUE ) */
#if ( ICU_70_ENABLE_TRD_ANY == TRUE )
    ( Icu_70_HW_EnableIntType )Icu_70_RL78F2X_TRD_EnableInt,
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
#if ( ICU_70_ENABLE_INTP_ANY == TRUE )
    ( Icu_70_HW_EnableIntType )Icu_70_RL78F2X_INTP_EnableEdge
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
};
/* function table for timer type */
static const Icu_70_HW_DisableIntType s_IcuHwDisableIntTbl[ICU_70_INPUT_INPUTTYPE_NUM] = {
#if ( ICU_70_ENABLE_TAU_ANY == TRUE )
    ( Icu_70_HW_DisableIntType )Icu_70_RL78F2X_TAU_DisableInt,
#endif/* ( ICU_70_ENABLE_TAU_ANY == TRUE ) */
#if ( ICU_70_ENABLE_TRD_ANY == TRUE )
    ( Icu_70_HW_DisableIntType )Icu_70_RL78F2X_TRD_DisableInt,
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
#if ( ICU_70_ENABLE_INTP_ANY == TRUE )
    ( Icu_70_HW_DisableIntType )Icu_70_RL78F2X_INTP_DisableEdge
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
};
#endif /* #if ( ICU_SET_MODE_API != FALSE ) */
 
/* Register setting table of each InputType */
static const uint8 Icu_70_ActEdge[ICU_70_INPUT_INPUTTYPE_NUM][ICU_70_ACT_EDGE_NUM] = {
 
#if ( ICU_70_ENABLE_TAU_ANY == TRUE )
    {
        /* Value of CIS bit of TMR */
        ICU_70_TAU_RISING_EDGE,
        ICU_70_TAU_FALLING_EDGE,
        ICU_70_TAU_BOTH_EDGES
    },
#endif/* ( ICU_70_ENABLE_TAU_ANY == TRUE ) */
#if ( ICU_70_ENABLE_TRD_ANY == TRUE )
    {
        /* Value of IOn bit of TRDIOA */
        ICU_70_TRD_RISING_EDGE,
        ICU_70_TRD_FALLING_EDGE,
        ICU_70_TRD_BOTH_EDGES
    },
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
#if ( ICU_70_ENABLE_INTP_ANY == TRUE )
    {
        /* Valid edge type of INTP */
        ICU_70_INTP_RISING_EDGE,
        ICU_70_INTP_FALLING_EDGE,
        ICU_70_INTP_BOTH_EDGES
    }
#endif/* ( ICU_70_ENABLE_INTP_ANY == TRUE ) */
};
 
#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define ICU_START_SEC_CODE_LOCAL
#include "Icu_MemMap.h"
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_HW_Init                                               */
/* Param       : (in) confPtr Configuration of channel                        */
/*               (in) actType Type of activation                              */
/* Return      : void                                                         */
/* Contents    : Set Timer for initialization.                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_HW_Init( const Icu_70_HW_SetConfType* confPtr, Icu_ActivationType actType )
{
    uint8                  actEdge;
    uint8                  inputType = confPtr->icuInputType;
 
    /* Get value from edge table to set register of edge */
    actEdge = Icu_70_ActEdge[ inputType ][ ( ( uint8 )actType - ( uint8 )1U ) ];
    /* call function for timer type */
    ( s_IcuHwInitFuncTbl[ inputType ] )( confPtr, actEdge );    /* [SWS_Icu_00006][SWS_Icu_00051] */
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_HW_DeInit                                             */
/* Param       : (in) confPtr Configuration of channel                        */
/* Return      : void                                                         */
/* Contents    : Set Timer for de-initialization.                             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_DE_INIT_API != FALSE )  /* [SWS_Icu_00301] */
void Icu_70_HW_DeInit( const Icu_70_HW_SetConfType* confPtr )
{
    /* call function for timer type */
    /* [SWS_Icu_00300][SWS_Icu_00091] */
    ( s_IcuHwDeInitFuncTbl[ confPtr->icuInputType ] )( confPtr );
}
#endif /* #if ( ICU_DE_INIT_API != FALSE ) */
 
/* [SWS_Icu_00321][SWS_Icu_00382][SWS_Icu_00337][SWS_Icu_00323] */
#if ( ICU_70_TIMER_API_ENABLE != FALSE )
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_HW_StartTimer                                         */
/* Param       : (in) confPtr Configuration of channel                        */
/*               (in) actType Type of activation                              */
/* Return      : void                                                         */
/* Contents    : Set Timer to start.                                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_HW_StartTimer( const Icu_70_HW_SetConfType* confPtr, Icu_ActivationType actType )
{
    uint8 actEdge;
 
    /* Get value from edge table to set register of edge */
    actEdge = Icu_70_ActEdge[ confPtr->icuInputType ][ ( ( uint8 )actType - ( uint8 )1U ) ];
    /* call function for timer type */
    /* [SWS_Icu_00317][SWS_Icu_00140] */
    ( s_IcuHwStartTimerFuncTbl[ confPtr->icuInputType ] )( confPtr, actEdge );
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_HW_StopTimer                                          */
/* Param       : (in) confPtr Configuration of channel                        */
/* Return      : void                                                         */
/* Contents    : Set Timer Counter Register to stop                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_HW_StopTimer( const Icu_70_HW_SetConfType* confPtr )
{
    /* call function for timer type */
    /* [SWS_Icu_00067][SWS_Icu_00143] */
    ( s_IcuHwStopTimerFuncTbl[ confPtr->icuInputType ] )( confPtr );
}
#endif /* #if ( ICU_70_TIMER_API_ENABLE != FALSE ) */
 
/* [SWS_Icu_00329][SWS_Icu_00370][SWS_Icu_00375][SWS_Icu_00331] */
#if ( ICU_70_EDGE_API_ENABLE != FALSE )
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_HW_EnableEdge                                         */
/* Param       : (in) confPtr Configuration of channel                        */
/*               (in) actType Type of activation                              */
/* Return      : void                                                         */
/* Contents    : Set Edge Detect Enable                                       */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_HW_EnableEdge( const Icu_70_HW_SetConfType* confPtr, Icu_ActivationType actType )
{
    uint8 actEdge;
 
    /* Get value from edge table to set register of edge */
    actEdge = Icu_70_ActEdge[ confPtr->icuInputType ][ ( ( uint8 )actType - ( uint8 )1U ) ];
    /* call function for timer type */
    /* [SWS_Icu_00078][SWS_Icu_00365] */
    ( s_IcuHwEnableEdgeTbl[ confPtr->icuInputType ] )( confPtr, actEdge );
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_HW_DisableEdge                                        */
/* Param       : (in) confPtr Configuration of channel                        */
/* Return      : void                                                         */
/* Contents    : Set Edge Detect Disable                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_HW_DisableEdge( const Icu_70_HW_SetConfType* confPtr )
{
    /* call function for timer type */
    /* [SWS_Icu_00372][SWS_Icu_00079] */
    ( s_IcuHwDisableEdgeTbl[ confPtr->icuInputType ] )( confPtr );
}
#endif /* #if ( ICU_70_EDGE_API_ENABLE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_HW_SetActivationCondition                             */
/* Param       : (in) confPtr Configuration of channel,actType                */
/*               (in) actType Type of activation                              */
/* Return      : void                                                         */
/* Contents    : Set Activation Condition                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_HW_SetActivationCondition( const Icu_70_HW_SetConfType* confPtr,
                                             Icu_ActivationType actType )
{
    uint8 actEdge;
 
    /* Get value from edge table to set register of edge */
    actEdge = Icu_70_ActEdge[ confPtr->icuInputType ][ ( ( uint8 )actType - ( uint8 )1U ) ];
    /* call function for timer type */
    /* [SWS_Icu_00090] */
    ( s_IcuHwSetActivationConditionTbl[ confPtr->icuInputType ] )( confPtr, actEdge );
}
 
#if ( ICU_SET_MODE_API != FALSE )  /* [SWS_Icu_00260] */
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_HW_EnableNonWakeupChannel                             */
/* Param       : (in) confPtr Configuration of channel,actType                */
/*               (in) actType Type of activation                              */
/* Return      : void                                                         */
/* Contents    : Enable ICU HW interrupt                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_HW_EnableNonWakeupChannel
            ( const Icu_70_HW_SetConfType* confPtr, Icu_ActivationType actType )
{
    uint8 actEdge;
 
    /* Get value from edge table to set register of edge */
    actEdge = Icu_70_ActEdge[ confPtr->icuInputType ][ ( ( uint8 )actType - ( uint8 )1U ) ];
    /* call function for timer type */
    /* [SWS_Icu_00011][SWS_Icu_00259] */
    ( s_IcuHwEnableIntTbl[ confPtr->icuInputType ] )( confPtr, actEdge );
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_HW_DisableNonWakeupChannel                            */
/* Param       : (in) confPtr Configuration of channel                        */
/* Return      : void                                                         */
/* Contents    : Disable ICU HW interrupt and Stop timer channel              */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_HW_DisableNonWakeupChannel( const Icu_70_HW_SetConfType* confPtr )
{
    /* Disable interrupt of HW channel */
    /* call function for timer type */
    ( s_IcuHwDisableIntTbl[ confPtr->icuInputType ] )( confPtr );    /* [SWS_Icu_00260] */
 
#if ( ICU_70_TIMER_API_ENABLE != FALSE )
#if ( ICU_70_ENABLE_INTP_ANY != FALSE )
    /* Stop channel if HW type is timer */
    if ( confPtr->icuInputType != ICU_70_INPUT_INTP )
#endif /* ( ICU_70_ENABLE_INTP_ANY != FALSE ) */
    {
        /* call function for timer type */
        ( s_IcuHwStopTimerFuncTbl[ confPtr->icuInputType ] )( confPtr );    /* [SWS_Icu_00261] */
    }
#endif /* #if ( ICU_70_TIMER_API_ENABLE != FALSE ) */
}
#endif /* #if ( ICU_SET_MODE_API != FALSE ) */
 
#define ICU_STOP_SEC_CODE_LOCAL
#include "Icu_MemMap.h"
 
/* EOF Icu_70_HW.c ************************************************************/