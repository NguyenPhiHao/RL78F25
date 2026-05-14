/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Pwm_70_RL78F2X.c                                             */
/* Version     : v1.00.01                                                     */
/* Contents    : PWM Module HW dependent interface                            */
/*               The PWM is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of PWM Driver                                                */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Pwm_70_RL78F2X.h"
#include "SchM_Pwm.h"

/*----------------------------------------------------------------------------*/
/* source file version information                                            */
/*----------------------------------------------------------------------------*/
#define PWM_70_VENDOR_ID_RL78F2X_C                      (70U)
#define PWM_70_MODULE_ID_RL78F2X_C                      (121U)

#define PWM_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C       (22U)
#define PWM_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C       (11U)
#define PWM_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C    (0U)

#define PWM_70_SW_MAJOR_VERSION_RL78F2X_C               (1U)
#define PWM_70_SW_MINOR_VERSION_RL78F2X_C               (0U)
#define PWM_70_SW_PATCH_VERSION_RL78F2X_C               (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Pwm_70_RL78F2X.h version check start */
#if ( PWM_70_VENDOR_ID_RL78F2X_C != PWM_70_VENDOR_ID_RL78F2X_H )
    #error "VENDOR ID for Pwm_70_RL78F2X.c and Pwm_70_RL78F2X.h is different"
#endif

#if ( PWM_70_MODULE_ID_RL78F2X_C != PWM_70_MODULE_ID_RL78F2X_H )
    #error "MODULE ID for Pwm_70_RL78F2X.c and Pwm_70_RL78F2X.h is different"
#endif

#if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C !=        \
            PWM_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) ||  \
      ( PWM_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C !=        \
            PWM_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) ||  \
      ( PWM_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C !=     \
            PWM_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H ) )
    #error "AUTOSAR Version Numbers of Pwm_70_RL78F2X.c and Pwm_70_RL78F2X.h are different"
#endif

#if ( ( PWM_70_SW_MAJOR_VERSION_RL78F2X_C != PWM_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
      ( PWM_70_SW_MINOR_VERSION_RL78F2X_C != PWM_70_SW_MINOR_VERSION_RL78F2X_H ) || \
      ( PWM_70_SW_PATCH_VERSION_RL78F2X_C != PWM_70_SW_PATCH_VERSION_RL78F2X_H ) )
    #error "Software Version Numbers of Pwm_70_RL78F2X.c and Pwm_70_RL78F2X.h are different"
#endif
/* Pwm_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

#define PWM_START_SEC_CONST_16
#include "Pwm_MemMap.h"

static const uint16 s_setCks[ 4U ] = {
        MCL_70_RL78F2X_TAU_TMR_CK0,
        MCL_70_RL78F2X_TAU_TMR_CK1,
        MCL_70_RL78F2X_TAU_TMR_CK2,
        MCL_70_RL78F2X_TAU_TMR_CK3
};  /* Convert Prescaler bit */

#define PWM_STOP_SEC_CONST_16
#include "Pwm_MemMap.h"

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* global variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* global functions                                                           */
/*----------------------------------------------------------------------------*/
#define PWM_START_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"

/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_RL78F2X_TAU_StartChannel                              */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : None                                                         */
/* Contents    : Perform initialization processing of RL78F2X peculiar part   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Pwm_70_RL78F2X_TAU_StartChannel( const Pwm_70_ChannelInfoType* chInfoPtr, Pwm_OutputStateType setActiveLevel )
{
    const Pwm_70_RL78F2X_TAU_ConfType*          SettingConfPtr;     /* TAU register information */
    const Pwm_70_RL78F2X_TAU_RegInfoType*       MasterRegInfoPtr;   /* TAU register information for master channel */
    const Pwm_70_RL78F2X_TAU_RegInfoType*       SlaveRegInfoPtr;    /* TAU register information for slave channel */
    uint16                                      masterSetBit;       /* setting bit of master channel register */
    uint16                                      slaveSetBit;        /* setting bit of slave channel register */
    uint16                                      prescale;           /* value of CKS selector */
    uint16                                      setPeriod;          /* value of period set to register */
    uint16                                      setDuty;            /* value of duty set to register */
    uint16                                      setRegTo;           /* temporary variable of To register */
    uint16                                      setRegTol;          /* temporary variable of Tol register */

    /* Get TAU register information */
    SettingConfPtr   = ( const Pwm_70_RL78F2X_TAU_ConfType* )( chInfoPtr->setChInfoPtr );
    MasterRegInfoPtr = SettingConfPtr->mastarRegInfoPtr;
    SlaveRegInfoPtr  = SettingConfPtr->slaveRegInfoPtr;
    masterSetBit     = ( uint16 )1U << ( SettingConfPtr->masterChId );  /* Get setting bit of master channel register */
    slaveSetBit      = masterSetBit << 1U;                              /* Get setting bit of slave channel register */

    /* Get period and calculated duty cycle */
    if ( ( Pwm_PeriodType ) 0U == chInfoPtr->period ) {
        /* When the period is 0, set the duty cycle to 0. */
        /* For details, please refer to chapter 6.8.2 of the RL78HW manual */        
        setPeriod = 0U;
        setDuty   = 0U;
    } else {
        /* -1 consideration of HW specification of RL78F2X microcomputer */
        /* For details, please refer to chapter 6.8.2 of the RL78HW manual */
        setPeriod = chInfoPtr->period - ( Pwm_PeriodType ) 1U;
        setDuty   = ( uint16 )chInfoPtr->duty;
    }

    /* Calculate operation clock, cycle, duty from config */
    prescale = s_setCks[ ( ( chInfoPtr->setChInfoPtr->pwmPrescale ) & ( uint8 ) PWM_70_PRESCALE_MASK ) ];

    /* TAU register setting start */
    /* According to HW Manual 6.8.2 Operation as PWM function, */
    /* Figure 6-76 the operation procedure at PWM function register setting is started. */
    /* <1> Set TMR register to initialize master channel. */
    MasterRegInfoPtr->contPtr->regTmr  = PWM_70_TMR_INIT;

    /* <2> Set TMR register to set channel for PWM function and select CKmn register value. */
    /* MASTERmn : 1 : Select master channel   */
    /* MDmn0-3 : 0000b : Setting for use as a master channel. */
    /* The operation mode is Interval-Timer-Mode */
    MasterRegInfoPtr->contPtr->regTmr |= ( ( prescale | ( uint16 ) PWM_70_MASTER_SET ) & ~( uint16 ) PWM_70_MD_INTERVAL );

    /* <3> Set TMR register to initialize slave channel. */
    SlaveRegInfoPtr->contPtr->regTmr   = PWM_70_TMR_INIT;

    /* <4> Set TMR register to set channel for PWM function and select CKmn register value. */
    /* STSmn0-2 : 100b : slave channel triggered   */
    /* MDmn0-3 : 1001b : Setting for use as a slave channel. */
    /* The operation mode is Onecount-Mode */
    SlaveRegInfoPtr->contPtr->regTmr  |= ( prescale | ( uint16 ) PWM_70_STS_MASTER | ( uint16 ) PWM_70_MD_ONECOUNT );

    /* <5> Set TDR register as period and duty cycle. */
    /* Master channel sets period */
    /* Slave channel sets dutycycle */
    *( MasterRegInfoPtr->regTdr ) = setPeriod;
    *( SlaveRegInfoPtr->regTdr )  = setDuty;

    /* <6> Set TOM register to set the output mode. */
    /* TOMmn : 1 : Output mode is slave channel    */
    SlaveRegInfoPtr->fixPtr->regTom  |= slaveSetBit;

    /* Get TOL register value */
    setRegTol = SlaveRegInfoPtr->fixPtr->regTol;

    if ( PWM_HIGH == setActiveLevel ) {
        /* Slave channel sets active level LOW */
        setRegTol &= ~slaveSetBit;
    } else {
        /* Slave channel sets active level HIGH */
        setRegTol |= slaveSetBit;
    }

    /* <7> Set TOL register to determine active level of slave channel. */
    SlaveRegInfoPtr->fixPtr->regTol = setRegTol;

    /* <8> Set TO register to set initial level of master channel to output register. */
    /* TOmn : 0 : Master channel sets an idle value to LOW */
    MasterRegInfoPtr->fixPtr->regTo &= ~masterSetBit;

    /* Get value of TO register */
    setRegTo = SlaveRegInfoPtr->fixPtr->regTo;

    /* Slave channel sets an idle value to its own bit */
    if ( PWM_HIGH == chInfoPtr->idleState ) {
        /* TOmn : 1 : Slave channel sets an idle value to PWM_HIGH */
        setRegTo |= slaveSetBit;
    } else {
        /* TOmn : 0 : Slave channel sets an idle value to PWM_LOW */
       setRegTo  &= ~slaveSetBit;
    }

    /* <9> Set TO register to set initial level of slave channel to output register. */
    SlaveRegInfoPtr->fixPtr->regTo = setRegTo;

    /* Start timer */
    /* <10> Set TOE register to allow output of own channel. */
    /* TOEmn : 1 : Allow output of own channel */
    SlaveRegInfoPtr->fixPtr->regToe  |= slaveSetBit;

    /* <11> Set TS register to start timer. */
    /* TSmn : 1 : Set the start bit of own channel */
    SlaveRegInfoPtr->fixPtr->regTs   |= ( masterSetBit | slaveSetBit );
    /* TAU regester setting end */
}

/* [SWS_Pwm_10080] */
#if ( PWM_DE_INIT_API != FALSE )
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_RL78F2X_TAU_StopChannel                               */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : None                                                         */
/* Contents    : Perform de-initialization processing of the                  */
/*               RL78F2X peculiar part                                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Pwm_70_RL78F2X_TAU_StopChannel( const Pwm_70_ChannelInfoType* chInfoPtr )
{
    const Pwm_70_RL78F2X_TAU_ConfType*          SettingConfPtr;     /* TAU register information */
    const Pwm_70_RL78F2X_TAU_RegInfoType*       MasterRegInfoPtr;   /* TAU register information for master channel */
    const Pwm_70_RL78F2X_TAU_RegInfoType*       SlaveRegInfoPtr;    /* TAU register information for slave channel */
    uint16                                      masterSetBit;       /* setting bit of master channel register */
    uint16                                      slaveSetBit;        /* setting bit of slave channel register */
    uint16                                      setRegTo;           /* temporary variable of TO register */

    /* Get TAU register information */
    SettingConfPtr   = ( const Pwm_70_RL78F2X_TAU_ConfType* )( chInfoPtr->setChInfoPtr );
    MasterRegInfoPtr = SettingConfPtr->mastarRegInfoPtr;
    SlaveRegInfoPtr  = SettingConfPtr->slaveRegInfoPtr;
    masterSetBit     = ( uint16 )1U << ( SettingConfPtr->masterChId );  /* Get setting bit of master channel register */
    slaveSetBit      = masterSetBit << 1U;                              /* Get setting bit of slave channel register */

    /* TAU setting start */
    /* Initialize cycle and duty */

    /* Stop timer */
    /* TTmn : 1 : Set the stop bit of own channel */
    MasterRegInfoPtr->fixPtr->regTt  |= ( masterSetBit | slaveSetBit );

    /* TOEmn : 0 : Prohibit output of own channel */
    MasterRegInfoPtr->fixPtr->regToe &= ~slaveSetBit;

    /* Set initial level to output register */
    /* Slave channel sets an idle value to its own bit */

    setRegTo = SlaveRegInfoPtr->fixPtr->regTo;

    if ( PWM_HIGH == chInfoPtr->idleState ) {
        /* TOmn : 1 : Slave channel sets an idle value to PWM_HIGH */
        setRegTo |= slaveSetBit;
    } else {
        /* TOmn : 0 : Slave channel sets an idle value to PWM_LOW */
        setRegTo &= ~slaveSetBit;
    }

    /* Set TO register */
    SlaveRegInfoPtr->fixPtr->regTo = setRegTo;
    /* TAU setting end */
}
#endif  /* #if ( PWM_DE_INIT_API != FALSE ) */

/* [SWS_Pwm_10082][SWS_Pwm_10083][SWS_Pwm_10084] */
#if ( ( PWM_SET_PERIOD_AND_DUTY_API != FALSE ) || \
      ( PWM_SET_DUTY_CYCLE_API != FALSE )      || \
      ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) )
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_RL78F2X_TAU_SetPeriodAndDuty                          */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : None                                                         */
/* Contents    : Pwm Set Duty Cycle and Period                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Pwm_70_RL78F2X_TAU_SetPeriodAndDuty( const Pwm_70_ChannelInfoType* chInfoPtr )
{
    const Pwm_70_RL78F2X_TAU_ConfType*          SettingConfPtr;         /* TAU register information */
    const Pwm_70_RL78F2X_TAU_RegInfoType*       MasterRegInfoPtr;       /* TAU register information for master channel */
    const Pwm_70_RL78F2X_TAU_RegInfoType*       SlaveRegInfoPtr;        /* TAU register information for slave channel */
    uint16                                      setDuty;                /* duty set value   */
    uint16                                      setPeriod;              /* Period set value */

    /* Get TAU register information */
    SettingConfPtr   = ( const Pwm_70_RL78F2X_TAU_ConfType* )( chInfoPtr->setChInfoPtr );
    MasterRegInfoPtr = SettingConfPtr->mastarRegInfoPtr;
    SlaveRegInfoPtr  = SettingConfPtr->slaveRegInfoPtr;

    /* Get period and calculated duty cycle */
    if ( ( Pwm_PeriodType ) 0U == chInfoPtr->period ) {
        /* When the period is 0, set the duty cycle to 0. */
        /* For details, please refer to chapter 6.8.2 of the RL78HW manual */        
        setPeriod = 0U;
        setDuty   = 0U;
    } else {
        /* -1 consideration of HW specification of RL78F2X microcomputer */
        /* For details, please refer to chapter 6.8.2 of the RL78HW manual */
        setPeriod = chInfoPtr->period - ( Pwm_PeriodType ) 1U;
        setDuty   = ( uint16 )chInfoPtr->duty;
    }

    /* TAU setting start */
    /* Exclusive Control Start */
    /* Atomically change duty cycle and period. */
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00();

    /* Master channel sets period */
    /* Slave channel sets dutycycle */
    *( MasterRegInfoPtr->regTdr ) = setPeriod;
    *( SlaveRegInfoPtr->regTdr )  = setDuty;

    /* Exclusive Control End */
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00();

    /* TAU setting end */
}
#endif  /* #if ( ( PWM_SET_PERIOD_AND_DUTY_API != FALSE ) || */
        /*       ( PWM_SET_DUTY_CYCLE_API != FALSE )      || */
        /*       ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) )   */

/* [SWS_Pwm_10085] */
#if ( PWM_GET_OUTPUT_STATE_API != FALSE )
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_RL78F2X_TAU_GetOutputState                            */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : Current state of PWM waveform(PWM_HIGH or PWM_LOW)           */
/* Contents    : Pwm Get Output State                                         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Pwm_OutputStateType Pwm_70_RL78F2X_TAU_GetOutputState( const Pwm_70_ChannelInfoType* chInfoPtr )
{
    const Pwm_70_RL78F2X_TAU_ConfType*          SettingConfPtr; /* TAU register information */
    uint8                                       SlaveChId;      /* slave channel ID */
    uint8                                       tmpRegTo;       /* temporary value of TO register */
    Pwm_OutputStateType                         retStat;        /* return value */

    /* Get TAU register information */
    SettingConfPtr   = ( const Pwm_70_RL78F2X_TAU_ConfType* )( chInfoPtr->setChInfoPtr );

    /* Get Slave Channel ID */
    SlaveChId = ( SettingConfPtr->masterChId ) + ( uint8 ) 1U;
    /* check the timer output value */
    tmpRegTo = ( uint8 )( SettingConfPtr->slaveRegInfoPtr->fixPtr->regTo ) & ( 1U << SlaveChId );

    /* Confirm whether the bit value of the TO register matches the timer output of the channel */
    if ( ( uint8 ) 0U != tmpRegTo ) {        
        /* The output waveform is HIGH */
        retStat = PWM_HIGH;
    } else {
        /* The output waveform is LOW */
        retStat = PWM_LOW;
    }
    return retStat;
}
#endif  /* #if ( PWM_GET_OUTPUT_STATE_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_RL78F2X_TRD_StartChannel                              */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/*             : (in) setActiveLevel  Pwm output activelevel                  */
/* Return      : None                                                         */
/* Contents    : Perform initialization processing of RL78F2X peculiar part   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Pwm_70_RL78F2X_TRD_StartChannel( const Pwm_70_ChannelInfoType* chInfoPtr, Pwm_OutputStateType setActiveLevel )
{
    const Pwm_70_RL78F2X_TRD_ConfType*      SettingConfPtr;     /* TRD register information */
    const Pwm_70_RL78F2X_TRD_RegInfoType*   MasterRegInfoPtr;   /* TRD register information for master channel */
    const Pwm_70_RL78F2X_TRD_RegInfoType*   SlaveRegInfoPtr;    /* TRD register information for slave channel */
    uint8                                   ch;                 /* TRD channel ID */
    uint8                                   masterSetBit;
    uint8                                   slaveSetBit;
    uint16                                  setDuty;            /* value of duty set to register */
    uint16                                  setPeriod;          /* Period set value */
    uint8                                   setRegTrdPocr;      /* temporary value of TRDPOCR register */

    /* Get TRD register information */
    SettingConfPtr   = ( const Pwm_70_RL78F2X_TRD_ConfType* )( chInfoPtr->setChInfoPtr );
    MasterRegInfoPtr = SettingConfPtr->mastarRegInfoPtr;
    SlaveRegInfoPtr  = SettingConfPtr->slaveRegInfoPtr;
    ch               = SettingConfPtr->masterChId;
    masterSetBit     = 1U << ch;                /* Get setting bit of master channel register */
    slaveSetBit      = masterSetBit << 2U;      /* Get setting bit of slave channel register */

    /* Get period and calculated duty cycle */
    if ( ( Pwm_PeriodType ) 0U == chInfoPtr->period ) {
        /* When the period is 0, set the period to 0 and the duty cycle to 0. */
        setPeriod = 0U;
        setDuty   = 0U;
    } else if ( ( uint16 ) 0U == ( uint16 ) chInfoPtr->duty ) {
        /* When the duty is 0, set the duty cycle to period. */
        /* For details, please refer to chapter 8.3.4 of the RL78HW manual */
        setPeriod = chInfoPtr->period - ( Pwm_PeriodType ) 1U;
        setDuty   = setPeriod;
    } else if ( chInfoPtr->period == chInfoPtr->duty ) {
        /* -1 consideration of HW specification of RL78F2X microcomputer */
        /* When the duty is 100, set the duty cycle to period +1. */
        /* For details, please refer to chapter 8.3.4 of the RL78HW manual */
        setPeriod = chInfoPtr->period - ( Pwm_PeriodType ) 1U;
        setDuty   = setPeriod + ( uint16 ) 1U;
    } else {
        /* -1 consideration of HW specification of RL78F2X microcomputer */
        /* For details, please refer to chapter 8.3.4 of the RL78HW manual */
        setPeriod = chInfoPtr->period - ( Pwm_PeriodType ) 1U;
        setDuty   = ( uint16 )chInfoPtr->duty - ( uint16 ) 1U;
    }

    /* The TRD register setting starts according to the HW manual 8.5.5 and */
    /* the automatically generated code by CS+. */
    /* For details, refer to detailed design document 2.2.1.1.2. "Processing outline". */

    /* <1> Clear period and duty cycle to 0 to privent spike noise. */
    /* This process is not performed by the HW manual and the automatically generated code by CS+. */
    MasterRegInfoPtr->contPtr->regTrdGra = 0U;
    MasterRegInfoPtr->contPtr->regTrdGrb = 0U;

#if ( PWM_DUTY_PERIOD_UPDATED_ENDPERIOD != FALSE )
    MasterRegInfoPtr->contPtr->regTrdGrc = 0U;
#endif /* #if ( PWM_DUTY_PERIOD_UPDATED_ENDPERIOD != FALSE ) */

#if ( PWM_DUTYCYCLE_UPDATED_ENDPERIOD != FALSE )
    MasterRegInfoPtr->contPtr->regTrdGrd = 0U;
#endif /* #if ( PWM_DUTYCYCLE_UPDATED_ENDPERIOD != FALSE ) */

    /* <2> Set TRDMR not to use TRDGRC, TRDGRD register as buffer register of TRDGRA, TRDGRB. */
    /* TRDBFD1 : 0 : TRDGRD1 is general register   */
    /* TRDBFC1 : 0 : TRDGRC1 is general register   */
    /* TRDBFD0 : 0 : TRDGRD0 is general register   */
    /* TRDBFC0 : 0 : TRDGRC0 is general register   */
    /* TRDSYNC : 0 : Each TRD moves independently  */
    SlaveRegInfoPtr->fixPtr->regTrdMr &= ~( ( uint8 ) PWM_70_TRDMR_TRDBF << ( ch * ( uint8 ) 2U ) );

#if ( PWM_DUTY_PERIOD_UPDATED_ENDPERIOD != FALSE )
    SlaveRegInfoPtr->fixPtr->regTrdMr |= ( ( uint8 ) PWM_70_TRDMR_TRDBFC << ( ch * ( uint8 ) 2U ) );
#endif /* #if ( PWM_DUTY_PERIOD_UPDATED_ENDPERIOD != FALSE ) */

#if ( PWM_DUTYCYCLE_UPDATED_ENDPERIOD != FALSE )
    SlaveRegInfoPtr->fixPtr->regTrdMr |= ( ( uint8 ) PWM_70_TRDMR_TRDBFD << ( ch * ( uint8 ) 2U ) );
#endif /* #if ( PWM_DUTYCYCLE_UPDATED_ENDPERIOD != FALSE ) */

    /* <3> Set TRDPMR to enable pwm function. */
    /* TRDPWMD1 : 1 : Select Pwm function          */
    /* TRDPWMC1 : 1 : Select Pwm function          */
    /* TRDPWMB1 : 1 : Select Pwm function          */
    /* TRDPWMD0 : 1 : Select Pwm function          */
    /* TRDPWMC0 : 1 : Select Pwm function          */
    /* TRDPWMB0 : 1 : Select Pwm function          */
    SlaveRegInfoPtr->fixPtr->regTrdPmr |= ( ( uint8 ) PWM_70_TRDPMR_TRDPWM << ( ch * ( uint8 ) 4U ) );

    /* <4> Set TRDCR to control TRD counter. */
    /* CCRL2 : 0 : Set CCRL0-CCRL2 register to 001b     */
    /* CCRL1 : 0 : because clear TRD register at        */
    /* CCRL0 : 1 : compare match with TRDGRA register   */
    /* CKEG1 : 0 : Count on rising edge                 */
    /* CKEG0 : 0 : Count on rising edge                 */
    /* TCK2  : 0 : Set CCRL0-CCRL2 register to 010b     */
    /* TCK1  : 1 : because select count source          */
    /* TCK0  : 0 : as Fclk/4                            */
    MasterRegInfoPtr->contPtr->regTrdCr |= ( uint8 ) PWM_70_TRDCR_INIT;

    /* <5> Set TRDFCR to control pwm function. */
    /* PWM3  : 1 : For timer mode                  */
    /* STCLK : 0 : External clock input disabled   */
    /* OLS1  : 0 : Invalid in timer mode           */
    /* OLS0  : 0 : Invalid in timer mode           */
    /* CMD1  : 0 : When timer mode, set 0          */
    /* CMD0  : 0 : When timer mode, set 0          */
    SlaveRegInfoPtr->fixPtr->regTrdFcr = PWM_70_TRDFCR_INIT;

    /* <6> Clear TRDSR to enable interrupts. */
    /* clear TRDSR */
    /* IMFA : 0 : Compare match flag by TRD and TRDGRA register */
    /* IMFB : 0 : Compare match flag by TRD and TRDGRB register */
    SlaveRegInfoPtr->contPtr->regTrdSr &= ~PWM_70_TRD_TRDSR_MASK;

    /* <7> Set TRDIER to enable interrupts. */
    /* IMIEA : 1 : enable interrupt by IMFA bit */
    /* IMIEB : 1 : enable interrupt by IMFB bit */
    SlaveRegInfoPtr->contPtr->regTrdIer |= ( uint8 ) PWM_70_TRDIER_MASK;

     /* Get TRDPOCR register value for <8> */
    setRegTrdPocr = SlaveRegInfoPtr->contPtr->regTrdPocr;

    if ( PWM_HIGH == setActiveLevel ) {
        /* Set active level LOW */
        setRegTrdPocr &= ~PWM_70_TRDPOCR_MASK;
    } else {
        /* Set active level HIGH */
        setRegTrdPocr |= ( uint8 ) PWM_70_TRDPOCR_MASK;
    }

    /* <8> Set TRDPOCR to determine the active polarity. */
    SlaveRegInfoPtr->contPtr->regTrdPocr = setRegTrdPocr;

    /* <9> Set TRDOCR to determine the init output level to inactive state */
    SlaveRegInfoPtr->fixPtr->regTrdOcr = 0U;

    /* <10> Set the period and duty cycle to TRDGRA and TRDGRB registers. */
    /* This process is violated to the processing sequenve of the automatically generated code by CS+. */
    MasterRegInfoPtr->contPtr->regTrdGra = setPeriod;
    MasterRegInfoPtr->contPtr->regTrdGrb = setDuty;

#if ( PWM_DUTY_PERIOD_UPDATED_ENDPERIOD != FALSE )
    MasterRegInfoPtr->contPtr->regTrdGrc = setPeriod;
#endif /* #if ( PWM_DUTY_PERIOD_UPDATED_ENDPERIOD != FALSE ) */

#if ( PWM_DUTYCYCLE_UPDATED_ENDPERIOD != FALSE )
    MasterRegInfoPtr->contPtr->regTrdGrd = setDuty;
#endif /* #if ( PWM_DUTYCYCLE_UPDATED_ENDPERIOD != FALSE ) */

    /* <11> Set TRDOER1 to allow output of TRDIO terminal. */
    /* This process is violated to the processing sequenve of the automatically generated code by CS+. */
    /* ED1 : 0 : Allow output of TRDIOD1            */
    /* EC1 : 0 : Allow output of TRDIOC1            */
    /* EB1 : 1 : Prohibit output of TRDIOB1         */
    /* EA1 : 1 : Prohibit output of TRDIOA1         */
    /* ED0 : 0 : Allow output of TRDIOD0            */
    /* EC0 : 0 : Allow output of TRDIOC0            */
    /* EB0 : 1 : Prohibit output of TRDIOB0         */
    /* EA0 : 1 : Prohibit output of TRDIOA0         */
    SlaveRegInfoPtr->fixPtr->regTrdOer1 &= ~( PWM_70_TRDOER1_EA << ( ch * ( uint8 ) 4U ) );

    /* <12> Set TRDSTR to start timer. */
    /* For reasons why register access is divided into two, */
    /* refer to Chapter 8.5 "Notes on using timer RD" in HW manual (1) Refer to TRDSTR register */
    /* CSEL1   : 1 : Continue to count even after compare match with TRDGRA register   */
    /* CSEL0   : 1 : Continue to count even after compare match with TRDGRA register   */
    /* TSTART1 : 1 : TRD1 count start                                                  */
    /* TSTART0 : 1 : TRD0 count start                                                  */
    SlaveRegInfoPtr->fixPtr->regTrdStr |= ( slaveSetBit );
    SlaveRegInfoPtr->fixPtr->regTrdStr |= ( masterSetBit );

    /* TRD setting end */
}

/* [SWS_Pwm_10080] */
#if ( PWM_DE_INIT_API != FALSE )
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_RL78F2X_TRD_StopChannel                               */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : None                                                         */
/* Contents    : Perform de-initialization processing of the                  */
/*               RL78F2X peculiar part                                        */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/

void Pwm_70_RL78F2X_TRD_StopChannel( const Pwm_70_ChannelInfoType* chInfoPtr )
{
    const Pwm_70_RL78F2X_TRD_ConfType*      SettingConfPtr;     /* TRD register information */
    const Pwm_70_RL78F2X_TRD_RegInfoType*   MasterRegInfoPtr;   /* TRD register information for master channel */
    const Pwm_70_RL78F2X_TRD_RegInfoType*   SlaveRegInfoPtr;    /* TRD register information for slave channel */
    uint8                                   masterSetBit;
    uint8                                   slaveSetBit;
    uint8                                   ch;                 /* TRD channel ID */

    /* Get TRD register information */
    SettingConfPtr   = ( const Pwm_70_RL78F2X_TRD_ConfType* )( chInfoPtr->setChInfoPtr );
    MasterRegInfoPtr = SettingConfPtr->mastarRegInfoPtr;
    SlaveRegInfoPtr  = SettingConfPtr->slaveRegInfoPtr;
    ch               = SettingConfPtr->masterChId;
    masterSetBit     = 1U << ch;
    slaveSetBit      = masterSetBit << 2U;

    /* For details, please refer to chapter 8.3.4 of the RL78HW manual */
    /* To prevent unnecessary waveform extension when the timer is stopped, */
    /* set TRDGRA and TRDGRB to 0U. */
    MasterRegInfoPtr->contPtr->regTrdGra = 0U;
    MasterRegInfoPtr->contPtr->regTrdGrb = 0U;

    /* clear counter */
    MasterRegInfoPtr->contPtr->regTrd = 0U;

    /* Stop timer */
    /* set TRDSTR */
    /* CSEL1   : 0 : Stop to count even after compare match with TRDGRA register                */
    /* CSEL0   : 0 : stop to count even after compare match with TRDGRA register                */
    /* TSTART1 : 0 : TRD1 count stop                                                            */
    /* TSTART0 : 0 : TRD0 count stop                                                            */
    /* For reasons why register access is divided into two,                                     */
    /* refer to Chapter 8.5 "Notes on using timer RD" in HW manual (1) Refer to TRDSTR register */
    SlaveRegInfoPtr->fixPtr->regTrdStr &= ~( slaveSetBit );

}
#endif  /* #if ( PWM_DE_INIT_API != FALSE ) */

/* [SWS_Pwm_10082][SWS_Pwm_10083][SWS_Pwm_10084] */
#if ( ( PWM_SET_PERIOD_AND_DUTY_API != FALSE ) || \
      ( PWM_SET_DUTY_CYCLE_API != FALSE )      || \
      ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) )
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_RL78F2X_TRD_SetPeriodAndDuty                          */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : None                                                         */
/* Contents    : Pwm Set Duty Cycle and Period                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Pwm_70_RL78F2X_TRD_SetPeriodAndDuty( const Pwm_70_ChannelInfoType* chInfoPtr )
{
    const Pwm_70_RL78F2X_TRD_ConfType*      SettingConfPtr;         /* TRD register information */
    const Pwm_70_RL78F2X_TRD_RegInfoType*   MasterRegInfoPtr;       /* TRD register information for master channel */
    uint16                                  setDuty;                /* duty set value   */
    uint16                                  setPeriod;              /* Period set value */

    /* Get TRD register information */
    SettingConfPtr   = ( const Pwm_70_RL78F2X_TRD_ConfType* )( chInfoPtr->setChInfoPtr );
    MasterRegInfoPtr = SettingConfPtr->mastarRegInfoPtr;

    /* Get period and calculated duty cycle */
    if ( ( Pwm_PeriodType ) 0U == chInfoPtr->period ) {
        /* When the period is 0, set the period to 0xFFFF and the duty cycle to 0xFFFF. */
        /* To prevent execution of large amount of HW interrupts.  */
        setPeriod = 0xFFFFU;
        setDuty   = 0xFFFFU;
    } else if ( ( uint16 ) 0U == ( uint16 ) chInfoPtr->duty ) {
        /* When the duty is 0, set the duty cycle to 0U. */
        /* For details, please refer to chapter 8.3.4 of the RL78HW manual */
        /* To generate a compare match between TRD and TRDGRB when the count value of TRD is 0U */
        /* and always output the active state. */
        setPeriod = chInfoPtr->period - ( Pwm_PeriodType ) 1U;
        setDuty   = 0U;
    } else if ( chInfoPtr->period == chInfoPtr->duty ) {
        /* When the duty is 100, set the duty cycle to period +1. */
        /* For details, please refer to chapter 8.3.4 of the RL78HW manual */
        /* To always output the inactive state without causing a compare match between TRD and TRDGRB */
        setPeriod = chInfoPtr->period - ( Pwm_PeriodType ) 1U;
        setDuty   = setPeriod + ( uint16 ) 1U;
    } else {
        /* -1 consideration of HW specification of RL78F2X microcomputer */
        /* For details, please refer to chapter 8.3.4 of the RL78HW manual */
        setPeriod = chInfoPtr->period - ( Pwm_PeriodType ) 1U;
        setDuty   = ( uint16 )chInfoPtr->duty - ( uint16 ) 1U;
    }

    /* Set the period and duty cycle */
#if ( PWM_DUTY_PERIOD_UPDATED_ENDPERIOD != TRUE )
    MasterRegInfoPtr->contPtr->regTrdGra = setPeriod;
#else
    MasterRegInfoPtr->contPtr->regTrdGrc = setPeriod;
#endif /* #if ( PWM_DUTY_PERIOD_UPDATED_ENDPERIOD != FALSE ) */

#if ( PWM_DUTYCYCLE_UPDATED_ENDPERIOD != TRUE )
    MasterRegInfoPtr->contPtr->regTrdGrb = setDuty;
#else
    MasterRegInfoPtr->contPtr->regTrdGrd = setDuty;

    /* If the duty cycle is set to period +1, a compare match between TRD and TRDGRB will not occur. */
    /* In that case, it is not possible to write the duty cycle from TRDGRD to TRDGRB, */
    /* so write the duty cycle directly to TRDGRB. */
    if ( ( MasterRegInfoPtr->contPtr->regTrdGrb > MasterRegInfoPtr->contPtr->regTrdGra )
        || ( ( MasterRegInfoPtr->contPtr->regTrd > MasterRegInfoPtr->contPtr->regTrdGrb )
            && ( MasterRegInfoPtr->contPtr->regTrdGrb > MasterRegInfoPtr->contPtr->regTrdGrc ) ) ) {
        MasterRegInfoPtr->contPtr->regTrdGrb = setDuty;
    } else {
        /* do nothing */
    }
#endif /* #if ( PWM_DUTYCYCLE_UPDATED_ENDPERIOD != FALSE ) */

    /* clear counter */
#if ( ( PWM_DUTY_PERIOD_UPDATED_ENDPERIOD != TRUE ) || \
      ( PWM_DUTYCYCLE_UPDATED_ENDPERIOD != TRUE ) )
    MasterRegInfoPtr->contPtr->regTrd = 0U;
#endif /* #if ( ( PWM_DUTY_PERIOD_UPDATED_ENDPERIOD != TRUE ) || \ */
       /*       ( PWM_DUTYCYCLE_UPDATED_ENDPERIOD != TRUE ) ) */

}
#endif  /* #if ( ( PWM_SET_PERIOD_AND_DUTY_API != FALSE ) || */
        /*       ( PWM_SET_DUTY_CYCLE_API != FALSE )      || */
        /*       ( PWM_SET_OUTPUT_TO_IDLE_API != FALSE ) )   */

/* [SWS_Pwm_10085] */

#if ( PWM_GET_OUTPUT_STATE_API != FALSE )
/******************************************************************************/
/* ModuleID    : PWM_MODULE_ID (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_RL78F2X_TRD_GetOutputState                            */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : (out) Current state of PWM waveform(PWM_HIGH or PWM_LOW)     */
/* Contents    : Pwm Get Output State                                         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
Pwm_OutputStateType Pwm_70_RL78F2X_TRD_GetOutputState( const Pwm_70_ChannelInfoType* chInfoPtr )
{
    const Pwm_70_RL78F2X_TRD_ConfType*      SettingConfPtr;     /* TRD register information */
    const Pwm_70_RL78F2X_TRD_RegInfoType*   MasterRegInfoPtr;   /* TRD register information for master channel */
    uint16                                  regTRD;             /* TRDx counter value                  */
    uint16                                  regTRDGRA;          /* TRDGRA value                        */
    uint16                                  regTRDGRB;          /* TRDGRB value                        */
    Pwm_OutputStateType                     retStat;            /* return value              */

    /* Get TRD register information */    
    SettingConfPtr   = ( const Pwm_70_RL78F2X_TRD_ConfType* )( chInfoPtr->setChInfoPtr );
    MasterRegInfoPtr = SettingConfPtr->mastarRegInfoPtr;

    /* Get present value of TRD and TRDGRA and TRDGRB */
    regTRD    = MasterRegInfoPtr->contPtr->regTrd;
    regTRDGRA = MasterRegInfoPtr->contPtr->regTrdGra;
    regTRDGRB = MasterRegInfoPtr->contPtr->regTrdGrb;

    /* If TRDGRA value equals TRDGRB value, return  inverse of active level. */
    /* ( because duty cycle is 0% )                                          */
    /* If TRD value larger than TRDGRB value, flip the active level          */
    if( ( regTRDGRA == regTRDGRB ) || ( regTRD > regTRDGRB ) ) {
        /* Flip the active level. */
        if ( chInfoPtr->activeLevel == PWM_HIGH ) {
            retStat = PWM_LOW;
        } else {
            retStat = PWM_HIGH;
        }
    } else {    /* When the Waveform state is active */
        retStat = chInfoPtr->activeLevel;   /* return configrated active level */
    }
    return retStat;
}

#endif  /* #if ( PWM_GET_OUTPUT_STATE_API != FALSE ) */

/******************************************************************************/
/* ModuleID    : MODULE_ID_PWM (121)                                          */
/* ServiceID   : --                                                           */
/* Name        : Pwm_70_RL78F2X_TRD_ClrInt                                    */
/* Param       : (in) chInfoPtr  Pwm channel information                      */
/* Return      : None                                                         */
/* Contents    : Clear Interrupt Flag for TRD.                                */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
void Pwm_70_RL78F2X_TRD_ClrInt( const Pwm_70_ChannelInfoType* chInfoPtr )
{
    const Pwm_70_RL78F2X_TRD_ConfType*      SettingConfPtr;
    const Pwm_70_RL78F2X_TRD_RegInfoType*   MasterRegInfoPtr;
    Mcl_70_RL78F2X_TRD_ContRegType*         trdContPtr;

    /* Get TRD register information */    
    SettingConfPtr   = ( const Pwm_70_RL78F2X_TRD_ConfType* )( chInfoPtr->setChInfoPtr );
    MasterRegInfoPtr = SettingConfPtr->mastarRegInfoPtr;

    trdContPtr = ( Mcl_70_RL78F2X_TRD_ContRegType* )( MasterRegInfoPtr->contPtr );

    /* clear TRDIER */
    /* IMIEA : 0 : disable interrupt by IMFA bit */
    trdContPtr->regTrdIer &= ( uint8 )~PWM_70_TRDIER_MASK;
    /* clear TRDSR */
    /* IMFA : 0 : disable interrupt by IMFA bit */
    trdContPtr->regTrdSr &= ~PWM_70_TRD_TRDSR_MASK;
    /* set TRDIER */
    /* IMIEA : 1 : enable interrupt by IMFA bit */
    trdContPtr->regTrdIer |= ( uint8 ) PWM_70_TRDIER_MASK;
}

#define PWM_STOP_SEC_CODE_LOCAL
#include "Pwm_MemMap.h"

/* EOF Pwm_70_RL78F2X.c *******************************************************/
 
