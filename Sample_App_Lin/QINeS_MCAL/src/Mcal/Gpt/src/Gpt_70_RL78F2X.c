/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Gpt_70_RL78F2X.c                                             */
/* Version     : v1.00.01                                                     */
/* Contents    : GPT Module HW dependent interface                            */
/*               The GPT is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of GPT Driver                                                */
/* Release R22-11                                                             */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Gpt_Cfg.h"
#include "SchM_Gpt.h"
#include "Gpt_70_RL78F2X.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define GPT_70_VENDOR_ID_RL78F2X_C                      ( 70U )
#define GPT_70_MODULE_ID_RL78F2X_C                      ( 100U )
 
#define GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C       ( 22U )
#define GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C       ( 11U )
#define GPT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C    ( 0U )
 
#define GPT_70_SW_MAJOR_VERSION_RL78F2X_C               ( 1U )
#define GPT_70_SW_MINOR_VERSION_RL78F2X_C               ( 0U )
#define GPT_70_SW_PATCH_VERSION_RL78F2X_C               ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
 
/* Gpt_Cfg.h version check start */
 
#if ( GPT_70_VENDOR_ID_RL78F2X_C != GPT_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Gpt_70_RL78F2X.c and Gpt_Cfg.h are different"
#endif
 
#if ( GPT_70_MODULE_ID_RL78F2X_C != GPT_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Gpt_70_RL78F2X.c and Gpt_Cfg.h are different"
#endif
 
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    != GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    != GPT_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != GPT_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Gpt_70_RL78F2X.c and Gpt_Cfg.h are different"
#endif
 
#if ( ( GPT_70_SW_MAJOR_VERSION_RL78F2X_C != GPT_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_MINOR_VERSION_RL78F2X_C != GPT_70_SW_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_PATCH_VERSION_RL78F2X_C != GPT_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Gpt_70_RL78F2X.c and Gpt_Cfg.h are different"
#endif
 
/* Gpt_Cfg.h version check end */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* SchM_Gpt.h version check start */
 
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    != RTE_AR_RELEASE_MAJOR_VERSION ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    != RTE_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Gpt_70_RL78F2X.c and SchM_Gpt.h are different"
#endif
 
/* SchM_Gpt.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
/* Gpt_70_RL78F2X.h version check start */
 
#if ( GPT_70_VENDOR_ID_RL78F2X_C != GPT_70_VENDOR_ID_RL78F2X_H )
    #error "VENDOR ID for Gpt_70_RL78F2X.c and Gpt_70_RL78F2X.h are different"
#endif
 
#if ( GPT_70_MODULE_ID_RL78F2X_C != GPT_70_MODULE_ID_RL78F2X_H )
    #error "MODULE ID for Gpt_70_RL78F2X.c and Gpt_70_RL78F2X.h are different"
#endif
 
#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    != GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    != GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != GPT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) \
    )
    #error "AUTOSAR Version Numbers of Gpt_70_RL78F2X.c and Gpt_70_RL78F2X.h are different"
#endif
 
#if ( ( GPT_70_SW_MAJOR_VERSION_RL78F2X_C != GPT_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( GPT_70_SW_MINOR_VERSION_RL78F2X_C != GPT_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( GPT_70_SW_PATCH_VERSION_RL78F2X_C != GPT_70_SW_PATCH_VERSION_RL78F2X_H ) \
    )
    #error "Software Version Numbers of Gpt_70_RL78F2X.c and Gpt_70_RL78F2X.h are different"
#endif
 
/* Gpt_70_RL78F2X.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
 
/* for TAU */
 
/* for TRJ */
                                                /* TRJCR : Set TSTART bit */
#define GPT_70_TRJ_START                ( MCL_70_RL78F2X_TRJ_TRJCR_TSTART )
                                                /* TRJCR : Reset TSTART bit */
#define GPT_70_TRJ_STOP                 ( ( uint8 )~MCL_70_RL78F2X_TRJ_TRJCR_TSTART )
                                                /* TRJCR :  Check TCSTF bit */
#define GPT_70_TRJ_CHECK_TCSTF          ( MCL_70_RL78F2X_TRJ_TRJCR_TCSTF )
 
/* for TRD */
                                                /* TDRMR : reset TRDMFDi, TRDBFCi bit */
#define GPT_70_TRD_TRDBFCD              ( MCL_70_RL78F2X_TRD_TRDMR_TRDBFCD_MASK )
                                                /* TDRMR : reset TRDSYNC bit */
#define GPT_70_TRD_RESET_TRDSYNC        ( ( uint8 )~MCL_70_RL78F2X_TRD_TRDMR_TRDSYNC_MASK )
 
#define GPT_70_TRD_START                ( MCL_70_RL78F2X_TRD_TRDSTR_TSTART_MASK )
#define GPT_70_TRD_STR_CSEL             ( MCL_70_RL78F2X_TRD_TRDSTR_CSEL_MASK )
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define GPT_START_SEC_CODE_LOCAL
#include "Gpt_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* functions for TAU                                                          */
/*----------------------------------------------------------------------------*/
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TAU_Init                                      */
/* Param       : (in) confPtr configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer for initialization for TAU.                        */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00280]                                              */
/******************************************************************************/
void Gpt_70_RL78F2X_TAU_Init( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr )
{
    Mcl_70_RL78F2X_TAU_ContRegType* tauContPtr;
   
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
    Gpt_70_RL78F2X_TAU_SelectUnit(confPtr->unitNo);
    tauContPtr = confPtr->contPtr;
    /* set TMR */
    /*    CKSmn : 0..3 : select CKmn. */
    /*    CCSmn : 0 : selected clock by CKS bits. */
    /* MASTERmn : 0 : single channel mode. */
    /*  SPLITmn : 0 : 16bit timer mode. */
    /*    STSmn : 0 : software trigger only. */
    /*    CISmn : 0 : rising edge. */
    /*     MDmn : 0 : interval timer mode */
    tauContPtr->regTmr = confPtr->tauTmrData;
    /* clear TDR */
    *( confPtr->tauTdrReg ) = MCL_70_RL78F2X_TAU_TDR_INIT;
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TAU_DeInit                                    */
/* Param       : (in) confPtr configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer for de-initialization for TAU.                     */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00309]                                              */
/******************************************************************************/
#if ( GPT_DEINIT_API != FALSE )
void Gpt_70_RL78F2X_TAU_DeInit( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr )
{
    Mcl_70_RL78F2X_TAU_ContRegType*     tauContPtr;
 
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
    Gpt_70_RL78F2X_TAU_SelectUnit(confPtr->unitNo);
    tauContPtr = confPtr->contPtr;
    /* clear TMR */
    tauContPtr->regTmr = MCL_70_RL78F2X_TAU_TMR_INIT;
    /* clear TDR */
    *( confPtr->tauTdrReg ) = MCL_70_RL78F2X_TAU_TDR_INIT;
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
}
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TAU_StartTimer                                */
/* Param       : (in) confPtr configuration of channel                        */
/*             : (in) value   Target time in number of Ticks.                 */
/* Return      : None                                                         */
/* Contents    : Set Timer to start for TAU with (value-1).                   */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00284]                                              */
/******************************************************************************/
void Gpt_70_RL78F2X_TAU_StartTimer( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr, Gpt_ValueType value)
{
    Mcl_70_RL78F2X_TAU_FixRegType*      tauFixPtr;
 
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
    Gpt_70_RL78F2X_TAU_SelectUnit(confPtr->unitNo);
    tauFixPtr = confPtr->fixPtr;
    /* set value to TDR */
    *( confPtr->tauTdrReg ) = value - ( uint16 )1U;
    /* [SWS_Gpt_00274] Set TSmn bit to start count. */
    tauFixPtr->regTs |= ( uint16 )( MCL_70_RL78F2X_TAU_TS_TS_MASK << confPtr->chNo );
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TAU_StartFreeRun                              */
/* Param       : (in) confPtr configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer to start free running for TAU (start with 0xFFFF). */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00284]                                              */
/******************************************************************************/
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
void Gpt_70_RL78F2X_TAU_StartFreeRun( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr )
{
    Mcl_70_RL78F2X_TAU_FixRegType*      tauFixPtr;
   
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
    Gpt_70_RL78F2X_TAU_SelectUnit(confPtr->unitNo);
    tauFixPtr = confPtr->fixPtr;
    /* set value to TDR */
    *( confPtr->tauTdrReg ) = ( uint16 )GPT_70_TAU_PREDEF_START_VALUE;
    /* [SWS_Gpt_00274] Set TSmn bit to start count. */
    tauFixPtr->regTs |= ( uint16 )( MCL_70_RL78F2X_TAU_TS_TS_MASK << confPtr->chNo );
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
}
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TAU_StopTimer                                 */
/* Param       : (in) confPtr configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer Counter Register to stop for TAU.                  */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00285]                                              */
/******************************************************************************/
void Gpt_70_RL78F2X_TAU_StopTimer( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr )
{
    Mcl_70_RL78F2X_TAU_FixRegType*      tauFixPtr;
   
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
    Gpt_70_RL78F2X_TAU_SelectUnit(confPtr->unitNo);
    tauFixPtr = confPtr->fixPtr;
    /* [SWS_Gpt_00013] Set TTmn bit to stop count. */
    tauFixPtr->regTt |= ( uint16 )( MCL_70_RL78F2X_TAU_TT_TT_MASK << confPtr->chNo );
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TAU_GetTimeElapsed                            */
/* Param       : (in) confPtr configuration of channel                        */
/*               (in) targetValue target value of channel is stared           */
/* Return      : Elapsed Timer Value.                                         */
/* Contents    : Get Elapsed Time for TAU.                                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00282]                                              */
/******************************************************************************/
#if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) )
Gpt_ValueType Gpt_70_RL78F2X_TAU_GetTimeElapsed( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr, Gpt_ValueType targetValue )
{
    const Mcl_70_RL78F2X_TAU_ContRegType*     tauContPtr;
    uint16 elapsedTime;
   
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
    Gpt_70_RL78F2X_TAU_SelectUnit(confPtr->unitNo);
    tauContPtr = confPtr->contPtr;
    /* read elapsed time from TAU (target - TCRmn) */
    elapsedTime =  targetValue - (tauContPtr->regTcr);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
    return elapsedTime;
}
#endif /* #if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TAU_GetTimeRemaining                          */
/* Param       : (in) confPtr configuration of channel                        */
/*               (in) targetValue target value of channel is stared           */
/* Return      : Remaining Timer Value.                                       */
/* Contents    : Get Remaining Time for TAU.                                  */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00283]                                              */
/******************************************************************************/
#if ( GPT_TIME_REMAINING_API != FALSE )
Gpt_ValueType Gpt_70_RL78F2X_TAU_GetTimeRemaining( const Gpt_70_RL78F2X_TAU_SettingConfType* confPtr, Gpt_ValueType targetValue )
{
    const Mcl_70_RL78F2X_TAU_ContRegType*     tauContPtr;
    uint16 remainingTime;
   
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
    Gpt_70_RL78F2X_TAU_SelectUnit(confPtr->unitNo);
    tauContPtr = confPtr->contPtr;
    /* read current time from TCRmn register. */
    remainingTime = tauContPtr->regTcr;
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
    return remainingTime;
}
#endif /* #if ( GPT_TIME_REMAINING_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TAU_SelectUnit                                */
/* Param       : (in) tauUnit   configuration of TAU Unit                     */
/* Return      : void                                                         */
/* Contents    : Select unit for TAU.                                         */
/* Author      : --                                                           */
/* Note        : Function for F25                                             */
/******************************************************************************/
void Gpt_70_RL78F2X_TAU_SelectUnit( uint8 tauUnit )
{
    if( GPT_70_RL78F2X_TAU_UNIT0 == tauUnit ){
        MCL_70_RL78F2X_TAU_UTSEL_ADR &= (uint8)( ~MCL_70_RL78F2X_TAU_UTSEL_TSEL0_1);
    } else if ( GPT_70_RL78F2X_TAU_UNIT1 == tauUnit){
        MCL_70_RL78F2X_TAU_UTSEL_ADR |= ( MCL_70_RL78F2X_TAU_UTSEL_TSEL0_1);
    } else {
        /* do nothing */
    }
}
 
/*----------------------------------------------------------------------------*/
/* functions for TRJ                                                          */
/*----------------------------------------------------------------------------*/
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRJ_Init                                      */
/* Param       : (in) confPtr configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer for initialization for TRJ.                        */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00280]                                              */
/******************************************************************************/
void Gpt_70_RL78F2X_TRJ_Init( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr )
{
    Mcl_70_RL78F2X_TRJ_ContRegType*     trjContPtr;
 
    trjContPtr = confPtr->contPtr;
 
    /* set TRJMRm */
    /*   TCKn : 0, 1, 3, 4, 5, 6 : select clock source */
    /* TEDGPL : 0 : single edge */
    /*  TMODn : 0 : timer mode */
    trjContPtr->regTrjMr = confPtr->trjTrjMrData;
    /* clear TRJCR */
    trjContPtr->regTrjCr = MCL_70_RL78F2X_TRJ_TRJCR_INIT;
    /* clear TRJ */
    *( confPtr->trjPtr ) = MCL_70_RL78F2X_TRJ_TRJ_INIT;
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRJ_DeInit                                    */
/* Param       : (in) confPtr configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer for de-initialization for TRJ.                     */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00309]                                              */
/******************************************************************************/
#if ( GPT_DEINIT_API != FALSE )
void Gpt_70_RL78F2X_TRJ_DeInit( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr )
{
    Mcl_70_RL78F2X_TRJ_ContRegType* trjContPtr;
 
    trjContPtr = confPtr->contPtr;
    /* clear TRJMR */
    trjContPtr->regTrjMr = MCL_70_RL78F2X_TRJ_TRJMR_INIT;
    /* clear TRJCR */
    trjContPtr->regTrjCr = MCL_70_RL78F2X_TRJ_TRJCR_INIT;
    /* clear TRJ */
    *( confPtr->trjPtr ) = MCL_70_RL78F2X_TRJ_TRJ_INIT;
}
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRJ_StartTimer                                */
/* Param       : (in) confPtr configuration of channel                        */
/*             : (in) value   Target time in number of Ticks.                 */
/* Return      : None                                                         */
/* Contents    : Set Timer to start for TRJ with (value-1).                   */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00284]                                              */
/******************************************************************************/
void Gpt_70_RL78F2X_TRJ_StartTimer( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr, Gpt_ValueType value )
{
    Mcl_70_RL78F2X_TRJ_ContRegType*     trjContPtr;
 
    trjContPtr = confPtr->contPtr;
 
    /* TRJ : set target value */
    *( confPtr->trjPtr ) = value - ( uint16 )1U;
    /* Start timer */
    trjContPtr->regTrjCr |= GPT_70_TRJ_START;
 
    /* Exclusive Control Start */
    /* Disable Interrupt (See Section 7.5.1 in Hardware Manual(r01uh0944jj0100-rl78f23-f24.pdf) ) */
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
 
    while( GPT_70_TRJ_CHECK_TCSTF != ( uint8 )( trjContPtr->regTrjCr & GPT_70_TRJ_CHECK_TCSTF ) ) {
        /* Wait until TCSTF bit set to 1 */
    }
 
    /* Exclusive Control End */
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRJ_StartFreeRun                              */
/* Param       : (in) confPtr configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer to start free ruuning for TRJ (start with 0xFFFF). */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00284]                                              */
/******************************************************************************/
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
void Gpt_70_RL78F2X_TRJ_StartFreeRun( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr )
{
    Mcl_70_RL78F2X_TRJ_ContRegType*     trjContPtr;
 
    trjContPtr = confPtr->contPtr;
 
    /* TRJ : set target value */
    *( confPtr->trjPtr ) = ( uint16 )GPT_70_TRJ_PREDEF_START_VALUE;
    /* Start timer */
    trjContPtr->regTrjCr |= GPT_70_TRJ_START;
 
    /* Exclusive Control Start */
    /* Disable Interrupt (See Section 7.5.1 in Hardware Manual(r01uh0944jj0100-rl78f23-f24.pdf) ) */
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
 
    while( GPT_70_TRJ_CHECK_TCSTF != ( uint8 )( trjContPtr->regTrjCr & GPT_70_TRJ_CHECK_TCSTF ) ) {
        /* Wait until TCSTF bit set to 1 */
    }
 
    /* Exclusive Control End */
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
}
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRJ_StopTimer                                 */
/* Param       : (in) confPtr configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer Counter Register to stop for TRJ.                  */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00285]                                              */
/******************************************************************************/
void Gpt_70_RL78F2X_TRJ_StopTimer( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr )
{
    Mcl_70_RL78F2X_TRJ_ContRegType*     trjContPtr;
 
    trjContPtr = confPtr->contPtr;
 
    /* Stop timer */
    trjContPtr->regTrjCr &= GPT_70_TRJ_STOP;
 
    /* Exclusive Control Start */
    /* Disable Interrupt (See Section 7.5.1 in Hardware Manual(r01uh0944jj0100-rl78f23-f24.pdf) ) */
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01();
 
    while( GPT_70_TRJ_CHECK_TCSTF == ( uint8 )( trjContPtr->regTrjCr & GPT_70_TRJ_CHECK_TCSTF ) ) {
        /* Wait until TCSTF bit set to 0 */
    }
 
    /* Exclusive Control End */
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01();
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRJ_GetTimeElapsed                            */
/* Param       : (in) confPtr configuration of channel                        */
/*               (in) targetValue target value of channel is stared           */
/* Return      : Elapsed Timer Value.                                         */
/* Contents    : Get Elapsed Time for TRJ.                                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00282]                                              */
/******************************************************************************/
#if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) )
Gpt_ValueType Gpt_70_RL78F2X_TRJ_GetTimeElapsed( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr, Gpt_ValueType targetValue )
{
    /* read elapsed time from TRJ (target - TRJn) */
    return ( targetValue - *( confPtr->trjPtr ) );
}
#endif /* #if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRJ_GetTimeRemaining                          */
/* Param       : (in) confPtr configuration of channel                        */
/*               (in) targetValue target value of channel is stared           */
/* Return      : Remaining Timer Value.                                       */
/* Contents    : Get Remaining Time for TRJ.                                  */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00283]                                              */
/******************************************************************************/
#if ( GPT_TIME_REMAINING_API != FALSE )
Gpt_ValueType Gpt_70_RL78F2X_TRJ_GetTimeRemaining( const Gpt_70_RL78F2X_TRJ_SettingConfType* confPtr, Gpt_ValueType targetValue )
{
    /* read remaining time from TRJ */
    return *( confPtr->trjPtr );
 
}
#endif /* #if ( GPT_TIME_REMAINING_API != FALSE ) */
 
/*----------------------------------------------------------------------------*/
/* functions for TRD                                                          */
/*----------------------------------------------------------------------------*/
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRD_Init                                      */
/* Param       : (in) confPtr configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer for initialization for TRD.                        */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00280]                                              */
/******************************************************************************/
void Gpt_70_RL78F2X_TRD_Init( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr )
{
    Mcl_70_RL78F2X_TRD_ContRegType*     trdContPtr;
    Mcl_70_RL78F2X_TRD_FixRegType*      trdFixPtr;
 
    trdContPtr = confPtr->contPtr;
    trdFixPtr = confPtr->fixPtr;
 
    /* set TRDFCR */
    /* PWM3 : 1 : timer mode */
    /* STCLK : 0 : disable external clock. */
    /* OLS1 : 0 : no use in timer mode. */
    /* OLS0 : 0 : no use in timer mode. */
    /* CMD : 0 : timer mode. */
    trdFixPtr->regTrdFcr = MCL_70_RL78F2X_TRD_TRDFCR_VAL;
    /* set TRDMR */
    /* TRDBFDn : 0 : general register */
    /* TRDBFCn : 0 : general register */
    trdFixPtr->regTrdMr &= ( uint8 )~( uint8 )( GPT_70_TRD_TRDBFCD << ( confPtr->chNo * 2U ) );
    /* TRDSYNC : 0 : no synchronous */
    trdFixPtr->regTrdMr &= GPT_70_TRD_RESET_TRDSYNC;
    /* set TRDSTR */
    /* CSELn : 1 : continue */
    trdFixPtr->regTrdStr |= ( uint8 )( GPT_70_TRD_STR_CSEL << confPtr->chNo );
    /* set TRDCR */
    trdContPtr->regTrdCr = confPtr->trdTrdCrData;
    /* TSTARTn : 0 : stop count */
    trdFixPtr->regTrdStr &= ( uint8 )~( uint8 )( GPT_70_TRD_START << confPtr->chNo );
    /* clear TRDn */
    trdContPtr->regTrd = MCL_70_RL78F2X_TRD_TRD_INIT;
    /* clear TRDGRAn */
    trdContPtr->regTrdGra = MCL_70_RL78F2X_TRD_TRDGRA_INIT;
    /* clear TRDSR */
    /* IMFA : 0 : disable interrupt by IMFA bit */
    trdContPtr->regTrdSr &= ( uint8 )~MCL_70_RL78F2X_TRD_TRDSR_IMFA_MASK;
    /* set TRDIER */
    /* IMIEA : 1 : enable interrupt by IMFA bit */
    trdContPtr->regTrdIer |= MCL_70_RL78F2X_TRD_TRDIER_IMIEA_MASK;
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRD_DeInit                                    */
 
/* Param       : (in) confPtr configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer for de-initialization for TRD.                     */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00309]                                              */
/******************************************************************************/
#if ( GPT_DEINIT_API != FALSE )
void Gpt_70_RL78F2X_TRD_DeInit( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr )
{
    Mcl_70_RL78F2X_TRD_ContRegType*     trdContPtr;
    Mcl_70_RL78F2X_TRD_FixRegType*      trdFixPtr;
 
    trdContPtr = confPtr->contPtr;
    trdFixPtr = confPtr->fixPtr;
 
    /* clear TRDIER */
    /* IMIEA : 0 : disable interrupt by IMFA bit */
    trdContPtr->regTrdIer &= ( uint8 )~MCL_70_RL78F2X_TRD_TRDIER_IMIEA_MASK;
    /* clear TRDSR */
    /* IMFA : 0 : disable interrupt by IMFA bit */
    trdContPtr->regTrdSr &= ( uint8 )~MCL_70_RL78F2X_TRD_TRDSR_IMFA_MASK;
    /* clear TRDFCR */
    trdFixPtr->regTrdFcr = MCL_70_RL78F2X_TRD_TRDFCR_INIT;
    /* clear TRDMR */
    /* TRDBFDn : 0 : general register */
    /* TRDBFCn : 0 : general register */
    trdFixPtr->regTrdMr &= ( uint8 )~( uint8 )( GPT_70_TRD_TRDBFCD << ( confPtr->chNo * 2U ) );
    /* TRDSYNC : 0 : no synchronous */
    trdFixPtr->regTrdMr &= GPT_70_TRD_RESET_TRDSYNC;
    /* clear TRDSTR */
    /* TSTARTn : 0 : stop count */
    trdFixPtr->regTrdStr &= ( uint8 )~( uint8 )( GPT_70_TRD_START << confPtr->chNo );
    /* CSELn : 1 : continue */
    trdFixPtr->regTrdStr |= ( uint8 )( GPT_70_TRD_STR_CSEL << confPtr->chNo );
    /* clear TRDCR */
    trdContPtr->regTrdCr = MCL_70_RL78F2X_TRD_TRDCR_INIT;
    /* clear TRDn */
    trdContPtr->regTrd = MCL_70_RL78F2X_TRD_TRD_INIT;
    /* clear TRDGRAn */
    trdContPtr->regTrdGra = MCL_70_RL78F2X_TRD_TRDGRA_INIT;
}
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRD_StartTimer                                */
/* Param       : (in) confPtr configuration of channel                        */
/*             : (in) value   Target time in number of Ticks.                 */
/* Return      : None                                                         */
/* Contents    : Set Timer to start for TRD with (value-1).                   */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00284]                                              */
/******************************************************************************/
void Gpt_70_RL78F2X_TRD_StartTimer( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr, Gpt_ValueType value)
{
    Mcl_70_RL78F2X_TRD_ContRegType* trdContPtr;
    Mcl_70_RL78F2X_TRD_FixRegType* trdFixPtr;
 
    trdContPtr = confPtr->contPtr;
    trdFixPtr = confPtr->fixPtr;
    /* clear TRDn */
    trdContPtr->regTrd = MCL_70_RL78F2X_TRD_TRD_INIT;
    /* set target to TRDGRAn */
    trdContPtr->regTrdGra = value - ( uint16 )1U;
    /* set TSTARTn bit to start channel. */
    trdFixPtr->regTrdStr |= ( uint8 )( GPT_70_TRD_START << confPtr->chNo );
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRD_StartFreeRun                              */
/* Param       : (in) confPtr configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer to start free running for TRD (start with 0xFFFF). */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00284]                                              */
/******************************************************************************/
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
void Gpt_70_RL78F2X_TRD_StartFreeRun( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr )
{
    Mcl_70_RL78F2X_TRD_ContRegType* trdContPtr;
    Mcl_70_RL78F2X_TRD_FixRegType* trdFixPtr;
 
    trdContPtr = confPtr->contPtr;
    trdFixPtr = confPtr->fixPtr;
    /* clear TRDn */
    trdContPtr->regTrd = MCL_70_RL78F2X_TRD_TRD_INIT;
    /* set target to TRDGRAn */
    trdContPtr->regTrdGra = ( uint16 )GPT_70_TRD_PREDEF_START_VALUE;
    /* set TSTARTn bit to start channel. */
    trdFixPtr->regTrdStr |= ( uint8 )( GPT_70_TRD_START << confPtr->chNo );
}
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRD_StopTimer                                 */
/* Param       : (in) confPtr configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Set Timer Counter Register to stop for TRD.                  */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00285]                                              */
/******************************************************************************/
void Gpt_70_RL78F2X_TRD_StopTimer( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr )
{
    Mcl_70_RL78F2X_TRD_FixRegType*      trdFixPtr;
 
    trdFixPtr = confPtr->fixPtr;
    /* reset TSTARTn bit to start channel. */
    trdFixPtr->regTrdStr &= ( uint8 )~( uint8 )( GPT_70_TRD_START << confPtr->chNo );
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRD_GetTimeElapsed                            */
/* Param       : (in) confPtr configuration of channel                        */
/*               (in) targetValue target value of channel is stared           */
/* Return      : Elapsed Timer Value.                                         */
/* Contents    : Get Elapsed Time for TRD.                                    */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00282]                                              */
/******************************************************************************/
#if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) )
Gpt_ValueType Gpt_70_RL78F2X_TRD_GetTimeElapsed( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr, Gpt_ValueType targetValue )
{
    const Mcl_70_RL78F2X_TRD_ContRegType*     trdContPtr;
 
    trdContPtr = confPtr->contPtr;
 
    /* read elapsed time is TRD */
    return trdContPtr->regTrd;
}
#endif /* #if ( ( GPT_TIME_ELAPSED_API != FALSE ) || ( GPT_70_PREDEF_TIMER_ENABLE != FALSE) ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRD_GetTimeRemaining                          */
/* Param       : (in) confPtr configuration of channel                        */
/*               (in) targetValue target value of channel is stared           */
/* Return      : Remaining Timer Value.                                       */
/* Contents    : Get Remaining Time for TRD.                                  */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00283]                                              */
/******************************************************************************/
#if ( GPT_TIME_REMAINING_API != FALSE )
Gpt_ValueType Gpt_70_RL78F2X_TRD_GetTimeRemaining( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr, Gpt_ValueType targetValue )
{
    const Mcl_70_RL78F2X_TRD_ContRegType*     trdContPtr;
 
    trdContPtr = confPtr->contPtr;
    /* read remaining time is (target - TRD) */
    return ( targetValue - trdContPtr->regTrd );
}
#endif /* #if ( GPT_TIME_REMAINING_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_TRD_ClrInt                                    */
/* Param       : (in) confPtr configuration of channel                        */
/* Return      : None                                                         */
/* Contents    : Clear Interrupt Flag for TRD.                                */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00206]                                              */
/******************************************************************************/
void Gpt_70_RL78F2X_TRD_ClrInt( const Gpt_70_RL78F2X_TRD_SettingConfType* confPtr )
{
    Mcl_70_RL78F2X_TRD_ContRegType*     trdContPtr;
 
    trdContPtr = confPtr->contPtr;
    /* clear TRDIER */
    /* IMIEA : 0 : disable interrupt by IMFA bit */
    trdContPtr->regTrdIer &= ( uint8 )~MCL_70_RL78F2X_TRD_TRDIER_IMIEA_MASK;
    /* clear TRDSR */
    /* IMFA : 0 : disable interrupt by IMFA bit */
    trdContPtr->regTrdSr &= ( uint8 )~MCL_70_RL78F2X_TRD_TRDSR_IMFA_MASK;
    /* set TRDIER */
    /* IMIEA : 1 : enable interrupt by IMFA bit */
    trdContPtr->regTrdIer |= MCL_70_RL78F2X_TRD_TRDIER_IMIEA_MASK;
}
 
#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_InitPredefTimer                               */
/* Param       : (in) predefConfPtr     Configuration for predef timer.       */
/* Return      : None                                                         */
/* Contents    : Initialize ELC for predef timer.                             */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00280]                                              */
/*               no start timer in this function.                             */
/******************************************************************************/
void Gpt_70_RL78F2X_InitPredefTimer( const Gpt_70_RL78F2X_PredefTimerConfType* predefConfPtr )
{
#if ( ( GPT_70_PREDEF_1US_USE_ELC != FALSE ) || \
      ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) )
    Mcl_70_RL78F2X_ELC_FixRegType* elcRegPtr = ( Mcl_70_RL78F2X_ELC_FixRegType* )MCL_70_RL78F2X_ELC_FIX_ADR;
#endif /* #if ( ( GPT_70_PREDEF_1US_USE_ELC != FALSE ) || \
                ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) ) */
 
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED )
#if ( GPT_70_PREDEF_1US_USE_ELC != FALSE )
    /* set TIS0 register for TAU0* predef timer input */
    MCL_70_RL78F2X_TIS0_REG |= predefConfPtr->tis0Value;
#endif /* #if ( GPT_70_PREDEF_1US_USE_ELC != FALSE ) */
#if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE )
    /* link 1us timer -> lower predef timer */
    elcRegPtr->regElselr[ predefConfPtr->elcElselrIdxLower ] = predefConfPtr->elcElselrValueLower;
#endif /* #if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE ) */
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED )
    /* link lower predef timer -> highwer predef timer */
    elcRegPtr->regElselr[ predefConfPtr->elcElselrIdxHigher ] = predefConfPtr->elcElselrValueHigher;
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED ) */
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED ) */
#if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE )
    /* set TIS0 register for TAU0* predef timer input */
    MCL_70_RL78F2X_TIS0_REG |= predefConfPtr->tis0Value100us;
    /* link 1us timer -> lower predef timer */
    elcRegPtr->regElselr[ predefConfPtr->elcElselrIdxLower100us ] = predefConfPtr->elcElselrValueLower100us;
    /* link lower predef timer -> highwer predef timer */
    elcRegPtr->regElselr[ predefConfPtr->elcElselrIdxHigher100us ] = predefConfPtr->elcElselrValueHigher100us;
#endif /* #if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) */
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_DeInitPredefTimer                             */
/* Param       : (in) predefConfPtr     Configuration for predef timer.       */
/* Return      : None                                                         */
/* Contents    : Deinitialize ELC for predef timer.                           */
/* Author      : --                                                           */
/* Note        : [SWS_Gpt_00309]                                              */
/******************************************************************************/
#if ( GPT_DEINIT_API != FALSE )
void Gpt_70_RL78F2X_DeInitPredefTimer( const Gpt_70_RL78F2X_PredefTimerConfType* predefConfPtr )
{
#if ( ( GPT_70_PREDEF_1US_USE_ELC != FALSE ) || \
      ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) )
    Mcl_70_RL78F2X_ELC_FixRegType* elcRegPtr = ( Mcl_70_RL78F2X_ELC_FixRegType* )MCL_70_RL78F2X_ELC_FIX_ADR;
#endif /* #if ( ( GPT_70_PREDEF_1US_USE_ELC != FALSE ) || \
                ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) ) */
 
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED )
#if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE )
    /* unlink 1us timer -> lower predef timer */
    elcRegPtr->regElselr[ predefConfPtr->elcElselrIdxLower ] = MCL_70_RL78F2X_ELC_ELSELR_NONE;
#endif /* #if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE ) */
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED )
    /* unlink lower predef timer -> highwer predef timer */
    elcRegPtr->regElselr[ predefConfPtr->elcElselrIdxHigher ] = MCL_70_RL78F2X_ELC_ELSELR_NONE;
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED ) */
#if ( GPT_70_PREDEF_1US_USE_ELC != FALSE )
    /* clear TIS0 register for TAU0* predef timer input */
    MCL_70_RL78F2X_TIS0_REG &= ( uint8 )~( predefConfPtr->tis0Value );
#endif /* #if ( GPT_70_PREDEF_1US_USE_ELC != FALSE ) */
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED ) */
#if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE )
    /* unlink 100us timer -> lower predef timer */
    elcRegPtr->regElselr[ predefConfPtr->elcElselrIdxLower100us ] = MCL_70_RL78F2X_ELC_ELSELR_NONE;
    /* unlink lower predef timer -> highwer predef timer */
    elcRegPtr->regElselr[ predefConfPtr->elcElselrIdxHigher100us ] = MCL_70_RL78F2X_ELC_ELSELR_NONE;
    /* clear TIS0 register for TAU0* predef timer input */
    MCL_70_RL78F2X_TIS0_REG &= ( uint8 )~( predefConfPtr->tis0Value100us );
#endif /* #if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) */
}
#endif /* #if ( GPT_DEINIT_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_GPT (100)                                          */
/* ServiceID   : --                                                           */
/* Name        : Gpt_70_RL78F2X_Init_CheckConfPredefTimer                     */
/* Param       : (in)  predefConfPtr    Configuration for predef timer.       */
/* Return      : E_OK       no error in Configuration.                        */
/*               E_NOT_OK   error in  Configuration.                          */
/* Contents    : Check Configuration for predef timer.                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Std_ReturnType Gpt_70_RL78F2X_Init_CheckConfPredefTimer( const Gpt_70_RL78F2X_PredefTimerConfType* predefConfPtr )
{
    Std_ReturnType ret = E_NOT_OK;
 
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED )
    /* check for 1us predef timer ELC */
#if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE )
    if ( NULL_PTR == predefConfPtr->channelConf1us ) {
        return ret;
    }
#endif /* #if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE ) */
    /* check for 1us 16/24/32bit predef timer */
    if ( NULL_PTR == predefConfPtr->channelConfLower ) {
        return ret;
    }
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED )
    /* check for 1us 24/32bit predef timer */
    if ( NULL_PTR == predefConfPtr->channelConfHigher ) {
        return ret;
    }
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED ) */
#endif /* #if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED ) */
#if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE )
    /* check for 1us 100us 32bit predef timer */
    if ( ( NULL_PTR == predefConfPtr->channelConf100us ) || \
         ( NULL_PTR == predefConfPtr->channelConfLower100us ) || \
         ( NULL_PTR == predefConfPtr->channelConfHigher100us ) ) {
        return ret;
    }
#endif /* #if ( GPT_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE ) */
 
    ret = E_OK;
    return ret;
}
 
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */
 
#define GPT_STOP_SEC_CODE_LOCAL
#include "Gpt_MemMap.h"
 
/* EOF Gpt_70_RL78F2X.c *******************************************************/