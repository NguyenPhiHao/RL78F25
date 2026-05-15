/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Icu_70_RL78F2X.c                                             */
/* Version     : v1.00.01                                                     */
/* Contents    : ICU Module HW dependent interface                            */
/*               The ICU is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     :                                                              */
/******************************************************************************/
/* Specification of ICU Driver                                                */
/* Release R22-11                                                             */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Icu.h"
#include "SchM_Icu.h"
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ICU_70_VENDOR_ID_RL78F2X_C                      (70U)
#define ICU_70_MODULE_ID_RL78F2X_C                      (122U)
 
#define ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C       (22U)
#define ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C       (11U)
#define ICU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C    (0U)
 
#define ICU_70_SW_MAJOR_VERSION_RL78F2X_C               (1U)
#define ICU_70_SW_MINOR_VERSION_RL78F2X_C               (0U)
#define ICU_70_SW_PATCH_VERSION_RL78F2X_C               (0U)
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Icu.h version check start */
 
#if ( ICU_70_VENDOR_ID_RL78F2X_C != ICU_VENDOR_ID )
    #error "VENDOR ID for Icu_70_RL78F2X.c and Icu.h are different"
#endif
 
#if ( ICU_70_MODULE_ID_RL78F2X_C != ICU_MODULE_ID )
    #error "MODULE ID for Icu_70_RL78F2X.c and Icu.h are different"
#endif
 
#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    != ICU_AR_RELEASE_MAJOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    != ICU_AR_RELEASE_MINOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != ICU_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_RL78F2X.c and Icu.h are different"
#endif
 
#if ( ( ICU_70_SW_MAJOR_VERSION_RL78F2X_C != ICU_SW_MAJOR_VERSION ) || \
      ( ICU_70_SW_MINOR_VERSION_RL78F2X_C != ICU_SW_MINOR_VERSION ) || \
      ( ICU_70_SW_PATCH_VERSION_RL78F2X_C != ICU_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Icu_70_RL78F2X.c and Icu.h are different"
#endif
 
/* Icu.h version check end */
 
/* Icu_70_RL78F2X.h version check start */
 
#if ( ICU_70_VENDOR_ID_RL78F2X_C != ICU_70_VENDOR_ID_RL78F2X_H )
    #error "VENDOR ID for Icu_70_RL78F2X.c and Icu_70_RL78F2X.h are different"
#endif
 
#if ( ICU_70_MODULE_ID_RL78F2X_C != ICU_70_MODULE_ID_RL78F2X_H )
    #error "MODULE ID for Icu_70_RL78F2X.c and Icu_70_RL78F2X.h are different"
#endif
 
#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    != ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    != ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != ICU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_RL78F2X.c and Icu_70_RL78F2X.h are different"
#endif
 
#if ( ( ICU_70_SW_MAJOR_VERSION_RL78F2X_C != ICU_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( ICU_70_SW_MINOR_VERSION_RL78F2X_C != ICU_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( ICU_70_SW_PATCH_VERSION_RL78F2X_C != ICU_70_SW_PATCH_VERSION_RL78F2X_H ) \
    )
    #error "Software Version Numbers of Icu_70_RL78F2X.c and Icu_70_RL78F2X.h are different"
#endif
 
/* Icu_70_RL78F2X.h version check end */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* global variables                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define ICU_START_SEC_CODE_LOCAL
#include "Icu_MemMap.h"
 
#if ( ICU_70_ENABLE_TAU_ANY != FALSE )
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TAU_Init                                      */
/* Param       : (in) chInfo    Configuration of channnel                     */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : Timer Module(TAU) initialization                             */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TAU_Init( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo, uint8 actEdge )
{
    uint8 tmrCh = chInfo->icuHwNo;
 
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00();
    Icu_70_RL78F2X_TAU_SelectUnit( chInfo->tauUnit );
    /* TDR register clear       *//* [SWS_Icu_00006][SWS_Icu_00051] */
    chInfo->tdrPtr->regTdr   = 0U;
    /* set TMR register         *//* [SWS_Icu_00006][SWS_Icu_00051] */
    chInfo->contPtr->regTmr  = ( chInfo->tauTmrData | ICU_70_TMR_CCS0_STS1_MD4
                             | ( uint16 )( ( uint16 )actEdge << ICU_70_TMR_CIS_SHIFT ) );
    /* set timer output disable *//* [SWS_Icu_00006][SWS_Icu_00051] */
    chInfo->fixPtr->regToe  &= ( uint16 )( ~( uint16 )( ICU_70_SET_U2BIT << tmrCh ) );
    /* NULL check */
    if ( NULL_PTR != chInfo->nfenPtr ) {
        /* Set noise filter TAU channel     */
        chInfo->nfenPtr->regNfen |= ( uint8 )( ICU_70_SET_U1BIT << tmrCh );
    }
   
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00();
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TAU_DeInit                                    */
/* Param       : (in) chInfo    Configuration of channnel                     */
/* Return      : void                                                         */
/* Contents    : Icu Deinitialization                                         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_DE_INIT_API  == TRUE )    /* [SWS_Icu_00301] */
void Icu_70_RL78F2X_TAU_DeInit( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo )
{
    uint8 tmrCh = chInfo->icuHwNo;
 
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00();
    Icu_70_RL78F2X_TAU_SelectUnit( chInfo->tauUnit );
    /* NULL check */
    if ( NULL_PTR != chInfo->nfenPtr ) {
        /* reset filter TAU channel    */
        chInfo->nfenPtr->regNfen &= ( uint8 )( ~( uint8 )( ICU_70_SET_U1BIT << tmrCh ) );
    }
    /* set timer output disable *//* [SWS_Icu_00300][SWS_Icu_00091] */
    chInfo->fixPtr->regToe &= ( uint16 )( ~( uint16 )( ICU_70_SET_U2BIT << tmrCh ) );
    /* set TMR register         *//* [SWS_Icu_00300][SWS_Icu_00091] */
    chInfo->contPtr->regTmr = MCL_70_RL78F2X_TAU_TMR_INIT;
    /* TDR register clear       *//* [SWS_Icu_00300][SWS_Icu_00091] */
    chInfo->tdrPtr->regTdr  = MCL_70_RL78F2X_TAU_TDR_INIT;
 
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00();
}
#endif /* #if ( ICU_DE_INIT_API != FALSE ) */
 
/* [SWS_Icu_00321][SWS_Icu_00335][SWS_Icu_00329][SWS_Icu_00370][SWS_Icu_00377][SWS_Icu_00323][SWS_Icu_00375][SWS_Icu_00331] */
#if ( ICU_70_USING_TAU_API_ENABLE != FALSE )
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TAU_StartTimer                                */
/* Param       : (in) chInfo    Configuration of channnel                     */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : start timer array unit(TAU)                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TAU_StartTimer( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo,
                                    uint8 actEdge )
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00();
    Icu_70_RL78F2X_TAU_SelectUnit( chInfo->tauUnit );
    /* Clear CIS                    */
    chInfo->contPtr->regTmr  &= ICU_70_TMR_CIS_CLEAR;
    /* Set CIS                      */
    chInfo->contPtr->regTmr  |= ( uint16 )( ( uint16 )actEdge << ICU_70_TMR_CIS_SHIFT );
    /* set timer start TAU0 channel */
    /* [SWS_Icu_00317][SWS_Icu_00078][SWS_Icu_00365][SWS_Icu_00140] */
    chInfo->fixPtr->regTs    |= ( uint16 )( ICU_70_SET_U2BIT << chInfo->icuHwNo );
 
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00();
 
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TAU_StopTimer                                 */
/* Param       : (in) chInfo    Configuration of channnel                     */
/* Return      : void                                                         */
/* Contents    : stop timer array unit(TAU)                                   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TAU_StopTimer( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo )
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00();
    Icu_70_RL78F2X_TAU_SelectUnit( chInfo->tauUnit );
    /* set timer stop TAU0 channel */
    /* [SWS_Icu_00067][SWS_Icu_00372][SWS_Icu_00079][SWS_Icu_00143] */
    chInfo->fixPtr->regTt |= ( uint16 )( ICU_70_SET_U2BIT << chInfo->icuHwNo );
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00();
}
#endif /* #if ( ICU_70_USING_TAU_API_ENABLE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TAU_SetActivationCondition                    */
/* Param       : (in) chInfo    Configuration of channnel                     */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : Set the activation-edge for a TAU channel                    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TAU_SetActivationCondition( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo,
                                                uint8 actEdge )
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00();
    Icu_70_RL78F2X_TAU_SelectUnit( chInfo->tauUnit );
    chInfo->contPtr->regTmr &= ICU_70_TMR_CIS_CLEAR;
    /* set TMR register *//* [SWS_Icu_00090] */
    chInfo->contPtr->regTmr |= ( uint16 )( ( uint16 )actEdge << ICU_70_TMR_CIS_SHIFT );
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00();
}
 
#if ( ICU_SET_MODE_API != FALSE )
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TAU_EnableInt                                 */
/* Param       : (in) chInfo    Configuration of channnel                     */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : Enable TAU timer interrupt                                   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TAU_EnableInt( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo, uint8 actEdge )
{
    io8* regMKxPtr = chInfo->tauMKPtr;
    *regMKxPtr &= ( uint8 )( ~( chInfo->tauMKData ) );
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TAU_DisableInt                                */
/* Param       : (in) chInfo    Configuration of channnel                     */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : Disable TAU timer interrupt                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TAU_DisableInt( const Icu_70_RL78F2X_TAU_SettingConfType* chInfo )
{
    io8* regMKxPtr = chInfo->tauMKPtr;
    *regMKxPtr |= chInfo->tauMKData;
}
#endif /* #if ( ICU_SET_MODE_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TAU_SelectUnit                                */
/* Param       : (in) tauUnit    Configuration of TAU Unit                    */
/*                                                                            */
/* Return      : void                                                         */
/* Contents    : Select unit for TAU                                          */
/* Author      : y.ishii                                                      */
/* Note        : Function for F25                                             */
/******************************************************************************/
void Icu_70_RL78F2X_TAU_SelectUnit( uint8 tauUnit )
{
    if ( ICU_70_TIMER_TAU0 == tauUnit ){
        MCL_70_RL78F2X_TAU_UTSEL_ADR &= ( uint8 )( ~MCL_70_RL78F2X_TAU_UTSEL_TSEL0_1 );
    } else if (ICU_70_TIMER_TAU1 == tauUnit ){
        MCL_70_RL78F2X_TAU_UTSEL_ADR |= MCL_70_RL78F2X_TAU_UTSEL_TSEL0_1;
    } else {
        /* do nothing */
    }
}
#endif /* #if ( ICU_70_ENABLE_TAU_ANY != FALSE ) */
 
#if ( ICU_70_ENABLE_TRD_ANY != FALSE )
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TRD_Init                                      */
/* Param       : (in) chInfo    Configuration of channnel                     */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : TRD Initialization                                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TRD_Init( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo, uint8 actEdge )
{
    Mcl_70_RL78F2X_TRD_ContRegType*     trdContPtr;
    Mcl_70_RL78F2X_TRD_FixRegType*      trdFixPtr;
    uint8 tmrCh    = chInfo->icuHwNo;
    uint8 inptPort = chInfo->inputPort;
 
    trdContPtr = chInfo->contPtr;
    trdFixPtr  = chInfo->fixPtr;
 
    /* set TRDSTR *//* [SWS_Icu_00006][SWS_Icu_00051] */
    /* CSELn : 1 : continue */
    trdFixPtr->regTrdStr |= ( uint8 )( ICU_70_TRDSTR_CSEL_MASK << tmrCh );
    /* TSTARTn : 0 : stop count */
    trdFixPtr->regTrdStr &= ( uint8 )( ~( uint8 )( ICU_70_TRD_START << tmrCh ) );
    /* set TRDMR  *//* [SWS_Icu_00006][SWS_Icu_00051] */
    /* TRDBFmn : 0 : Buffer register */
    trdFixPtr->regTrdMr |= ( uint8 )( ( uint8 )( ICU_70_TRDMR_TRDBF
                        << ( uint8 )( tmrCh << ICU_70_TRDMR_SHIFT ) ) << inptPort );
    /* TRDSYNC : 0 : no synchronous */
    trdFixPtr->regTrdMr &= ICU_70_TRDMR_TRDSYNC_MASK;
    /* set TRDFCR *//* [SWS_Icu_00006][SWS_Icu_00051] */
    /* PWM3 : 1 : timer mode */
    /* STCLK : 0 : disable external clock. */
    /* OLS1 : 0 : no use in timer mode. */
    /* OLS0 : 0 : no use in timer mode. */
    /* CMD : 0 : timer mode. */
    trdFixPtr->regTrdFcr = MCL_70_RL78F2X_TRD_TRDFCR_VAL;
    /* set TRDCR *//* [SWS_Icu_00006][SWS_Icu_00051] */
    trdContPtr->regTrdCr |= ( ( uint8 )( ICU_70_TRDCR_CCLR_MASK << inptPort )
                         |  chInfo->trdTrdCrData );
    /* NULL check */
    if ( NULL_PTR != chInfo->trddfPtr ) {
        /* Setting digital filter */
        chInfo->trddfPtr->regTrddf |= ( ICU_70_TRDDF_DFCK3
                                   | ( uint8 )( ICU_70_SET_U1BIT << chInfo->inputPort ) );
    }
    /* Set TRDIORA for setting Activation Condition*//* [SWS_Icu_00006][SWS_Icu_00051] */
    trdContPtr->regTrdIora |= ( uint8 )( actEdge << ( uint8 )( inptPort << ICU_70_TRDIOR_SHIFT ) );
    /* Set TRDIORC as Buffer register of TRDIORA   *//* [SWS_Icu_00006][SWS_Icu_00051] */
    trdContPtr->regTrdIorc |= ( uint8 )( ICU_70_TRDIORC
                           << ( uint8 )( inptPort << ICU_70_TRDIOR_SHIFT ) );
    /* clear TRDn    *//* [SWS_Icu_00006][SWS_Icu_00051] */
    trdContPtr->regTrd = ICU_70_TRD_TRD_INIT;
    /* clear TRDGRmn *//* [SWS_Icu_00006][SWS_Icu_00051] */
    if ( ICU_70_TRDIOA == chInfo->inputPort ) {
        trdContPtr->regTrdGra = ICU_70_TRD_TRDGRX_INIT;
        trdContPtr->regTrdGrc = ICU_70_TRD_TRDGRX_INIT;
    } else {
        trdContPtr->regTrdGrb = ICU_70_TRD_TRDGRX_INIT;
        trdContPtr->regTrdGrd = ICU_70_TRD_TRDGRX_INIT;
    }
    /* clear TRDSR *//* [SWS_Icu_00006][SWS_Icu_00051] */
    /* IMFn : 0 : disable interrupt by IMFn bit */
    trdContPtr->regTrdSr &= ( uint8 )( ~( uint8 )( ICU_70_TRDSR_INIT << inptPort ) );
    /* set TRDIER  *//* [SWS_Icu_00006][SWS_Icu_00051] */
    /* IMIEn : 1 : enable interrupt by IMFn bit */
    trdContPtr->regTrdIer |= ( uint8 )( ICU_70_TRDIER_IMIE << inptPort );
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TRD_DeInit                                    */
/* Param       : (in) chInfo    Configuration of channnel                     */
/* Return      : void                                                         */
/* Contents    : TRD Deinitialization                                         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_DE_INIT_API  == TRUE )    /* [SWS_Icu_00301] */
void Icu_70_RL78F2X_TRD_DeInit( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo )
{
    Mcl_70_RL78F2X_TRD_ContRegType*     trdContPtr;
    Mcl_70_RL78F2X_TRD_FixRegType*      trdFixPtr;
    uint8 tmrCh    = chInfo->icuHwNo;
    uint8 inptPort = chInfo->inputPort;
 
    trdContPtr = chInfo->contPtr;
    trdFixPtr  = chInfo->fixPtr;
 
    /* clear TRDIER  *//* [SWS_Icu_00300][SWS_Icu_00091] */
    /* IMIEA : 0 : disable interrupt by IMFn bit */
    trdContPtr->regTrdIer &= ( uint8 )( ~( uint8 )( ICU_70_TRDIER_IMIE << inptPort ) );
    /* clear TRDSR   *//* [SWS_Icu_00300][SWS_Icu_00091] */
    /* IMFA : 0 : disable interrupt by IMFn bit */
    trdContPtr->regTrdSr &= ( uint8 )( ~( uint8 )( ICU_70_TRDSR_INIT << inptPort ) );
    /* clear TRDGRAn *//* [SWS_Icu_00300][SWS_Icu_00091] */
    if ( ICU_70_TRDIOA == chInfo->inputPort ) {
        trdContPtr->regTrdGra = ICU_70_TRD_TRDGRX_INIT;
        trdContPtr->regTrdGrc = ICU_70_TRD_TRDGRX_INIT;
    } else {
        trdContPtr->regTrdGrb = ICU_70_TRD_TRDGRX_INIT;
        trdContPtr->regTrdGrd = ICU_70_TRD_TRDGRX_INIT;
    }
    /* clear TRDn    *//* [SWS_Icu_00300][SWS_Icu_00091] */
    trdContPtr->regTrd = MCL_70_RL78F2X_TRD_TRD_INIT;
    /* Clear TRDIORC *//* [SWS_Icu_00300][SWS_Icu_00091] */
    trdContPtr->regTrdIorc &= ( uint8 )( ~( uint8 )( ICU_70_TRDIORC
                           << ( uint8 )( inptPort << ICU_70_TRDIOR_SHIFT ) ) );
    /* Clear TRDIORA *//* [SWS_Icu_00300][SWS_Icu_00091] */
    trdContPtr->regTrdIora &= ( uint8 )( ~( uint8 )( ICU_70_TRDIORA_INIT
                           << ( uint8 )( inptPort << ICU_70_TRDIOR_SHIFT ) ) );
    /* clear TRDCR   *//* [SWS_Icu_00300][SWS_Icu_00091] */
    /* NULL check */
    if ( NULL_PTR != chInfo->trddfPtr ) {
        /* Setting digital filter */
        chInfo->trddfPtr->regTrddf &= ( uint8 )( ~( uint8 )( ICU_70_TRDDF_DFCK3
                                    | ( uint8 )( ICU_70_SET_U1BIT << chInfo->inputPort ) ) );
    }
    trdContPtr->regTrdCr = MCL_70_RL78F2X_TRD_TRDCR_INIT;
    /* clear TRDFCR  *//* [SWS_Icu_00300][SWS_Icu_00091] */
    trdFixPtr->regTrdFcr = MCL_70_RL78F2X_TRD_TRDFCR_INIT;
    /* clear TRDMR   *//* [SWS_Icu_00300][SWS_Icu_00091] */
    /* TRDBFmn : 0 : general register */
    trdFixPtr->regTrdMr &= ( uint8 )( ~( uint8 )( ( uint8 )( ICU_70_TRDMR_TRDBF
                        << ( uint8 )( tmrCh << ICU_70_TRDMR_SHIFT ) ) << chInfo->inputPort ) );
    /* TRDSYNC : 0 : no synchronous   */
    trdFixPtr->regTrdMr &= ICU_70_TRDMR_TRDSYNC_MASK;
    /* clear TRDSTR  *//* [SWS_Icu_00300][SWS_Icu_00091] */
    /* TSTARTn : 0 : stop count *//* [SWS_Icu_00300][SWS_Icu_00091] */
    trdFixPtr->regTrdStr &= ( uint8 )( ~( uint8 )( ICU_70_TRD_START << tmrCh ) );
    /* CSELn : 1 : continue     *//* [SWS_Icu_00300][SWS_Icu_00091] */
    trdFixPtr->regTrdStr |= ( uint8 )( ICU_70_TRDSTR_CSEL_MASK << tmrCh );
}
#endif /* #if ( ICU_DE_INIT_API  == TRUE ) */
 
/* [SWS_Icu_00321][SWS_Icu_00335][SWS_Icu_00337][SWS_Icu_00323] */
#if ( ICU_70_TIMER_API_ENABLE != FALSE )
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TAU_StartTimer                                */
/* Param       : (in) chInfo    Configuration of channel                      */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : start timer RD(TRD)                                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TRD_StartTimer( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo,
                                    uint8 actEdge )
{
    Mcl_70_RL78F2X_TRD_ContRegType* trdContPtr;
 
    trdContPtr = chInfo->contPtr;
 
    /* Clear edge */
    trdContPtr->regTrdIora &= ( uint8 )( ~( uint8 )( ICU_70_TRD_TRDIORA_IO
                           << ( uint8 )( chInfo->inputPort << ICU_70_TRDIOR_SHIFT ) ) );
    /* Set TRDIORA */
    trdContPtr->regTrdIora |= ( uint8 )( ( actEdge | ICU_70_TRDIORA )
                           << ( uint8 )( chInfo->inputPort << ICU_70_TRDIOR_SHIFT ) );
    /* clear TRDn */
    trdContPtr->regTrd      = MCL_70_RL78F2X_TRD_TRD_INIT;
    /* set TSTARTn bit to start channel. *//* [SWS_Icu_00317][SWS_Icu_00140] */
    chInfo->fixPtr->regTrdStr |= ( uint8 )( ICU_70_TRD_START << chInfo->icuHwNo );
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TAU_StopTimer                                 */
/* Param       : (in) chInfo  Configration of channel                         */
/* Return      : void                                                         */
/* Contents    : stop timer RD(TRD)                                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TRD_StopTimer( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo )
{
    /* reset TSTARTn bit to start channel. *//* [SWS_Icu_00067][SWS_Icu_00143] */
    chInfo->fixPtr->regTrdStr &= ( uint8 )( ~( uint8 )( ICU_70_TRD_START << chInfo->icuHwNo ) );
    /* Set TRDIORA */
    chInfo->contPtr->regTrdIora &= ( uint8 )( ~( uint8 )( ICU_70_TRDIORA
                                << ( uint8 )( chInfo->inputPort << ICU_70_TRDIOR_SHIFT ) ) );
}
#endif /*#if ( ICU_70_TIMER_API_ENABLE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TRD_ClrInt                                    */
/* Param       : (in) chInfo    Configuration of channel                      */
/* Return      : void                                                         */
/* Contents    : Clear Interrupt Flag for TRD.                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TRD_ClrInt( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo )
{
    Mcl_70_RL78F2X_TRD_ContRegType*     trdContPtr;
    uint8 inptPort = chInfo->inputPort;
 
    trdContPtr = chInfo->contPtr;
    /* clear TRDIER *//* [SWS_Icu_00229] */
    /* IMIEn : 0 : disable interrupt by IMFn bit */
    trdContPtr->regTrdIer &= ( uint8 )( ~( uint8 )( ICU_70_SET_U1BIT << inptPort ) );
    /* clear TRDSR  *//* [SWS_Icu_00229] */
    /* IMFn : 0 : disable interrupt by IMFn bit */
    trdContPtr->regTrdSr  &= ( uint8 )( ~( ( uint8 )( ICU_70_SET_U1BIT << inptPort )
                                                    | ICU_70_TRDSR_OVF_BIT ) );
    /* set TRDIER   *//* [SWS_Icu_00229] */
    /* IMIEn : 1 : enable interrupt by IMFn bit */
    trdContPtr->regTrdIer |= ( uint8 )( ICU_70_SET_U1BIT << inptPort );
}
 
/* [SWS_Icu_00329][SWS_Icu_00370][SWS_Icu_00375][SWS_Icu_00331] */
#if ( ICU_70_EDGE_API_ENABLE != FALSE )
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TRD_EnableEdge                                */
/* Param       : (in) chInfo    Configuration of channnel                     */
/* Return      : void                                                         */
/* Contents    : Enable input edge on a TRD channel                           */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TRD_EnableEdge( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo,
                                    uint8 actEdge )
{
    Mcl_70_RL78F2X_TRD_ContRegType*     trdContPtr;
    uint8 inptPort = chInfo->inputPort;
 
    trdContPtr = chInfo->contPtr;
 
    /* Clear IOmn  */
    trdContPtr->regTrdIora &= ( uint8 )( ~( uint8 )( ICU_70_TRD_TRDIORA_IO
                           << ( uint8 )( chInfo->inputPort << ICU_70_TRDIOR_SHIFT ) ) );
    /* Set TRDIORA *//* [SWS_Icu_00078][SWS_Icu_00365] */
    trdContPtr->regTrdIora |= ( uint8 )( ( actEdge | ICU_70_TRDIORA )
                           << ( uint8 )( inptPort << ICU_70_TRDIOR_SHIFT ) );
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TRD_DisableEdge                               */
/* Param       : (in) chInfo    Configuration of channnel                     */
/* Return      : void                                                         */
/* Contents    : Disable input edge on a TRD channel                          */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TRD_DisableEdge( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo )
{
    /* Set TRDIORA *//* [SWS_Icu_00372][SWS_Icu_00079] */
    chInfo->contPtr->regTrdIora &= ( uint8 )( ~( uint8 )( ICU_70_TRDIORA
                                << ( uint8 )( chInfo->inputPort << ICU_70_TRDIOR_SHIFT ) ) );
}
#endif /* #if ( ICU_70_EDGE_API_ENABLE != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TRD_SetActivationCondition                    */
/* Param       : (in) chInfo    Configuration of channnel                     */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : Set the activation-edge for a TRD channel                    */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TRD_SetActivationCondition( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo,
                                                uint8 actEdge )
{
    Mcl_70_RL78F2X_TRD_ContRegType*     trdContPtr;
    uint8 inptPort = chInfo->inputPort;
 
    trdContPtr = chInfo->contPtr;

    /* Clear TRDIORA for setting Activation Condition */
    trdContPtr->regTrdIora &= ( uint8 )( ~( uint8 )( ICU_70_TRD_TRDIORA_IO
                           << ( uint8 )( chInfo->inputPort << ICU_70_TRDIOR_SHIFT ) ) );
    /* Set TRDIORA for setting Activation Condition   *//* [SWS_Icu_00090] */
    trdContPtr->regTrdIora |= ( uint8 )( actEdge << ( uint8 )( inptPort << ICU_70_TRDIOR_SHIFT ) );
}
 
#if ( ICU_SET_MODE_API != FALSE )
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TRD_EnableInt                                 */
/* Param       : (in) chInfo    Configuration of channnel                     */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : Enable TRD Timer interrupt                                   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TRD_EnableInt( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo, uint8 actEdge )
{
    io8* regMKxPtr = chInfo->trdMKPtr;
    *regMKxPtr &= ( uint8 )( ~( chInfo->trdMKData ) );
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_TRD_DisableInt                                */
/* Param       : (in) chInfo    Configuration of channnel                     */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : Disable TRD Timer interrupt                                  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_TRD_DisableInt( const Icu_70_RL78F2X_TRD_SettingConfType* chInfo )
{
    io8* regMKxPtr = chInfo->trdMKPtr;
    *regMKxPtr |= chInfo->trdMKData;
}
#endif /* #if ( ICU_SET_MODE_API != FALSE ) */
#endif/* ( ICU_70_ENABLE_TRD_ANY != FALSE ) */
 
#if ( ICU_70_ENABLE_INTP_ANY != FALSE )
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_INTP_Init                                     */
/* Param       : (in) chInfo    Configuration of channnel                     */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : Set interrupt port initialization                            */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_INTP_Init( const Icu_70_RL78F2X_INTP_SettingConfType* chInfo, uint8 actEdge )
{
    uint8 intp_id;
    uint8 intpNo = chInfo->icuHwNo;
 
    if ( ( intpNo == ICU_70_INTP4 ) || ( intpNo == ICU_70_INTP5 ) || ( intpNo == ICU_70_INTP6 ) ) {
        intp_id = intpNo - ICU_70_INTP4;
        /* [SWS_Icu_00006][SWS_Icu_00051] */
        ICU_70_RL78F2X_INT_INTMSK_ADR &= ( uint8 )( ~( uint8 )( ICU_70_SET_U1BIT << intp_id ) );
    }
}
 
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_INTP_DeInit                                   */
/* Param       : (in) chInfo    Configuration of channnel                     */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : Deintialize interrupt port                                   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
#if ( ICU_DE_INIT_API  == TRUE )    /* [SWS_Icu_00301] */
void Icu_70_RL78F2X_INTP_DeInit( const Icu_70_RL78F2X_INTP_SettingConfType* chInfo )
{
    uint8 intpCh = chInfo->icuHwNo;
 
    if ( ICU_70_INTP8 <= intpCh ) {
        intpCh = intpCh - ICU_70_INTP8;
    }
    /* Set Default Value to Timer Input Select register *//* [SWS_Icu_00300][SWS_Icu_00091] */
    chInfo->egpPtr->regEgp        &= ( uint8 )( ~( uint8 )( ICU_70_SET_U1BIT << intpCh ) );
    chInfo->egnPtr->regEgn        &= ( uint8 )( ~( uint8 )( ICU_70_SET_U1BIT << intpCh ) );
    ICU_70_RL78F2X_INT_INTMSK_ADR  = ICU_70_RL78F2X_INTMSK_INIT;
}
#endif /* #if ( ICU_DE_INIT_API  == TRUE ) */
 
/* [SWS_Icu_00329][SWS_Icu_00370][SWS_Icu_00375][SWS_Icu_00079] */
#if ( ICU_70_EDGE_API_ENABLE != FALSE )
/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_INTP_EnableEdge                               */
/* Param       : (in) chInfo    Configuration of channnel                     */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : Enable interrupt port                                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_INTP_EnableEdge( const Icu_70_RL78F2X_INTP_SettingConfType* chInfo,
                                     uint8 actEdge )
{
    uint8 intpCh = chInfo->icuHwNo;
    Icu_70_RL78F2X_INTP_EgpRegType* intpEgpPtr = chInfo->egpPtr;
    Icu_70_RL78F2X_INTP_EgnRegType* intpEgnPtr = chInfo->egnPtr;
 
    if ( ICU_70_INTP8 <= intpCh ) {
        intpCh = intpCh - ICU_70_INTP8;
    }
    /* Clear EGP,EGN register */
    intpEgpPtr->regEgp &= ( uint8 )( ~( uint8 )( ICU_70_SET_U1BIT << intpCh ) );
    intpEgnPtr->regEgn &= ( uint8 )( ~( uint8 )( ICU_70_SET_U1BIT << intpCh ) );
 
    /* Set EGP,EGN register */
    if ( 0U < ( actEdge & ICU_70_RL78F2X_ACT_RISING ) ) {
        /* [SWS_Icu_00078][SWS_Icu_00365] */
        intpEgpPtr->regEgp |= ( uint8 )( ICU_70_SET_U1BIT << intpCh );
    }
    if ( 0U < ( actEdge & ICU_70_RL78F2X_ACT_FALLING ) ) {
        /* [SWS_Icu_00078][SWS_Icu_00365] */
        intpEgnPtr->regEgn |= ( uint8 )( ICU_70_SET_U1BIT << intpCh );
    }
}

/******************************************************************************/
/* ModuleID    : MODULE_ID_ICU (122)                                          */
/* ServiceID   : --                                                           */
/* Name        : Icu_70_RL78F2X_INTP_DisableEdge                              */
/* Param       : (in) chInfo    Configuration of channnel                     */
/*               (in) actEdge   Activation edge                               */
/* Return      : void                                                         */
/* Contents    : Disable interrupt port                                       */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Icu_70_RL78F2X_INTP_DisableEdge( const Icu_70_RL78F2X_INTP_SettingConfType* chInfo )
{
    uint8 intpCh = chInfo->icuHwNo;
 
    if ( ICU_70_INTP8 <= intpCh ) {
        intpCh = intpCh - ICU_70_INTP8;
    }
    /* Clear EGP register *//* [SWS_Icu_00079] */
    chInfo->egpPtr->regEgp &= ( uint8 )( ~( uint8 )( ICU_70_SET_U1BIT << intpCh ) );
    /* Clear EGN register *//* [SWS_Icu_00372][SWS_Icu_00079] */
    chInfo->egnPtr->regEgn &= ( uint8 )( ~( uint8 )( ICU_70_SET_U1BIT << intpCh ) );
}
#endif /* #if ( ICU_70_EDGE_API_ENABLE != FALSE ) */
#endif /* ( ICU_70_ENABLE_INTP_ANY != FALSE) */

#define ICU_STOP_SEC_CODE_LOCAL
#include "Icu_MemMap.h"
 
/* EOF Icu_70_RL78F2X.c *******************************************************/