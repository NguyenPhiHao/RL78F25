/******************************************************************************/
/* Copyright   : 2023 SCSK Corporation                                        */
/* System Name : AUTOSAR QINeS-Lite MCAL                                      */
/* File Name   : Mcu_70_RL78F2X.c                                             */
/* Version     : v1.00.01                                                     */
/* Contents    : MCU Module HW dependent interface                            */
/*               The MCU is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : h.kiryu k.izumi DucHT2                                       */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of MCU Driver                                                */
/* Release R22-11                                                             */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
 
#include "Mcu.h"
#include "SchM_Mcu.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define MCU_70_VENDOR_ID_RL78F2X_C                      ( 70U )
#define MCU_70_MODULE_ID_RL78F2X_C                      ( 101U )
 
#define MCU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C       ( 22U )
#define MCU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C       ( 11U )
#define MCU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C    ( 0U )
 
#define MCU_70_SW_MAJOR_VERSION_RL78F2X_C               ( 1U )
#define MCU_70_SW_MINOR_VERSION_RL78F2X_C               ( 0U )
#define MCU_70_SW_PATCH_VERSION_RL78F2X_C               ( 0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Mcu.h version check start */
#if ( MCU_70_VENDOR_ID_RL78F2X_C != MCU_VENDOR_ID )
    #error "VENDOR ID for Mcu_70_RL78F2X.c and Mcu.h is different"
#endif
 
#if ( MCU_70_MODULE_ID_RL78F2X_C != MCU_MODULE_ID )
    #error "MODULE ID for Mcu_70_RL78F2X.c and Mcu.h is different"
#endif
 
#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C    != MCU_AR_RELEASE_MAJOR_VERSION )  ||   \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C    != MCU_AR_RELEASE_MINOR_VERSION )  ||   \
      ( MCU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_C != MCU_AR_RELEASE_REVISION_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Mcu_70_RL78F2X.c and Mcu.h are different"
#endif
 
#if ( ( MCU_70_SW_MAJOR_VERSION_RL78F2X_C != MCU_SW_MAJOR_VERSION ) || \
      ( MCU_70_SW_MINOR_VERSION_RL78F2X_C != MCU_SW_MINOR_VERSION ) || \
      ( MCU_70_SW_PATCH_VERSION_RL78F2X_C != MCU_SW_PATCH_VERSION )    \
    )
    #error "Software Version Numbers of Mcu_70_RL78F2X.c and Mcu.h are different"
#endif
/* Mcu.h version check end */
 
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* SchM_Mcu.h version check Start */
#if ( ( MCU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_C != RTE_AR_RELEASE_MAJOR_VERSION ) || \
      ( MCU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_C != RTE_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Mcu_70_RL78F2X.c and SchM_Mcu.h are different"
#endif
/* ScHM_Mcu.h version check end */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */
 
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_VAR_NO_INIT_LOCAL_8
#include "Mcu_MemMap.h"
 
static uint8 Mcu_70_ResfCause;        /* reset cause value */
static uint8 Mcu_70_PocresCause;      /* POCRES register save value */
 
#define MCU_STOP_SEC_VAR_NO_INIT_LOCAL_8
#include "Mcu_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Mcu_MemMap.h"
 
static const Mcu_ConfigType* s_McuConfigPtr = NULL_PTR;
static const Mcu_70_RL78F2X_ClockSettingDataType* s_ClockSettingData = NULL_PTR;
 
#define MCU_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "Mcu_MemMap.h"
 
#if ( MCU_GET_RAM_STATE_API !=  FALSE )
#define MCU_START_SEC_VAR_INIT_LOCAL_8
#include "Mcu_MemMap.h"
 
/*  ECC-RAM Check Status  */
static Mcu_RamStateType s_McuRamState = MCU_RAMSTATE_VALID;
 
static Std_ReturnType s_McuResetFlag = E_NOT_OK;
 
#define MCU_STOP_SEC_VAR_INIT_LOCAL_8
#include "Mcu_MemMap.h"
#endif /* #if ( MCU_GET_RAM_STATE_API !=  FALSE ) */
 
/*----------------------------------------------------------------------------*/
/* inline function prototype declarations                                     */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"
LOCAL_INLINE void mcu_70_RL78F2X_PllSetting( const Mcu_70_RL78F2X_ClockSettingDataType* ClockSettingDataPtr );
 
#define MCU_STOP_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* Local Function                                                             */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : --                                                           */
/* Name        : Mcu_70_RL78F2X_PllSetting                                    */
/* Param       : (in) ClockSettingDataPtr   Clock Setting Data struct Pointer */
/* Return      : E_OK       PLL lock.                                         */
/*               E_NOT_OK   PLL unlock.                                       */
/* Contents    : PLL Setting                                                  */
/* Author      : h.kiryu DucHT2                                               */
/* Note        : [SWS_Mcu_00137]                                              */
/******************************************************************************/
#if ( MCU_INIT_CLOCK != FALSE )
LOCAL_INLINE void mcu_70_RL78F2X_PllSetting( const Mcu_70_RL78F2X_ClockSettingDataType* ClockSettingDataPtr )
{
    volatile uint16_least i;         /* loop counter for wait time.  */
 
    /* setting User's Manual Hardware : 5.6.4.Examples of Setting PLL Circuit.  */
    /*(1)  Example of procedure for setting oscillation of PLL clock  */
    /* <1> Select the frequency of the PLL output clock with the PLLDIV1 bit of the PLLCTL register.  */
    if ( 0U != ClockSettingDataPtr->McuPllCtlPllDiv1 ) {
        MCL_70_RL78F2X_PLLCTL_REG |= ( uint8 )(~( MCU_70_PLLCTL_PLLDIV1_MASK ));    /* PLLCTL.PLLDIV1 = 1 */
    } else {
        MCL_70_RL78F2X_PLLCTL_REG &= ( MCU_70_PLLCTL_PLLDIV1_MASK );    /* PLLCTL.PLLDIV1 = 0 */
    }
 
    /* <2> Set the PLL lock-up wait counter with the LCKSEL1 and LCKSEL0 bits of the PLLCTL register. */
    /* set PLLCTL.LCKSEL1 and LCKSEL0 */
    MCL_70_RL78F2X_PLLCTL_REG &= ( MCU_70_PLLCTL_LCKSEL0_MASK & MCU_70_PLLCTL_LCKSEL1_MASK );
    MCL_70_RL78F2X_PLLCTL_REG |= ( uint8 )( ClockSettingDataPtr->McuPllCtlLckSel << 6U );
 
    /* <3> Select the frequency division of the PLL clock with the PLLDIV0 bit of the PLLCTL register.  */
    if ( 0U != ClockSettingDataPtr->McuPllCtlPllDiv0 ) {
        MCL_70_RL78F2X_PLLCTL_REG |= ( uint8 )(~( MCU_70_PLLCTL_PLLDIV0_MASK ));   /* PLLCTL.PLLDIV0 = 1 */
    } else {
        MCL_70_RL78F2X_PLLCTL_REG &= ( MCU_70_PLLCTL_PLLDIV0_MASK );    /* PLLCTL.PLLDIV0 = 0 */
    }
 
    /* <4> Select the multiplication value of the PLL clock with the PLLMUL and PLLMULA bit of the PLLCTL register. */
    if ( 0U != ClockSettingDataPtr->McuPllCtlPllMul ) {
        MCL_70_RL78F2X_PLLCTL_REG |= ( uint8 )(~( MCU_70_PLLCTL_PLLMUL_MASK ));    /* PLLCTL.PLLMUL = 1 */
    } else {
        MCL_70_RL78F2X_PLLCTL_REG &= ( MCU_70_PLLCTL_PLLMUL_MASK );    /* PLLCTL.PLLMUL = 0 */
    }
 
    if ( 0U != ClockSettingDataPtr->McuPllCtlPllMula ) {
        MCL_70_RL78F2X_PLLCTL_REG |= ( uint8 )(~( MCU_70_PLLCTL_PLLMULA_MASK ));    /* PLLCTL.PLLMULA = 1 */
    } else {
        MCL_70_RL78F2X_PLLCTL_REG &= ( MCU_70_PLLCTL_PLLMULA_MASK );    /* PLLCTL.PLLMULA = 0 */
    }
 
    /* wait over 1us after PLLMUL and PLLMULA
     * <5> Wait for the selection of the PLL multiplication value to become effective.
     *     After setting the PLLMUL and PLLMULA bit, wait for at least 1 micro sec
     */
    for ( i = 0U; i < MCU_70_WAIT_PLLMUL; i++ ) {
        /* wait for PLL output stable */
    }
 
    /* <6> Set the PLLON bit of the PLLCTL register to 1 to start oscillation of the PLL clock.  */
    if ( 0U != ClockSettingDataPtr->McuPllCtlPllOn ) {
        MCL_70_RL78F2X_PLLCTL_REG |= ( uint8 )(~( MCU_70_PLLCTL_PLLON_MASK ));    /* PLLCTL.PLLON = 1 */
    } else {
        MCL_70_RL78F2X_PLLCTL_REG &= ( MCU_70_PLLCTL_PLLON_MASK );    /* PLLCTL.PLLON = 0 */
    }
 
    /* <7> Confirm that the PLL circuit is locked (LOCK = 1) with the LOCK bit of the PLLSTS register. */
    /* [SWS_Mcu_00138] not supported */
    /* Writing to the SELPLL bit is disabled when the PLL output is not stable */
    /* This process moved to Mcu_70_RL78F2X_GetPllStatus function. */
}
#endif /* #if ( MCU_INIT_CLOCK != FALSE ) */
 
#define MCU_STOP_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"
 
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
#define MCU_START_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : --                                                           */
/* Name        : Mcu_70_RL78F2X_Init                                          */
/* Param       : (in) ConfigPtr     Pointer to the configuration set in       */
/*                                  VARIANT-POST-BUILD.                       */
/* Return      : E_OK                  Initializes this module normal.        */
/* Contents    : Initializes a Config pointer & ECC-RAM Check Start Bit Set.  */
/* Author      : h.kiryu DucHT2                                               */
/* Note        : [SWS_Mcu_00153]                                              */
/*               Interrupt setting is also required to start ECC-RAM check.   */
/******************************************************************************/
Std_ReturnType Mcu_70_RL78F2X_Init( const Mcu_ConfigType* ConfigPtr )
{
    Std_ReturnType rtn;
 
    s_McuConfigPtr = ConfigPtr;  /* save MCU configuration data */
 
#if ( MCU_GET_RAM_STATE_API != FALSE )
    /* Get Ram State Start Bit Set. */
    MCL_70_RL78F2X_ECCIER_REG = MCU_70_ECCIER_IEN;
#endif /* #if ( MCU_GET_RAM_STATE_API != FALSE ) */
 
    rtn = E_OK;
    return ( rtn );
}
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : --                                                           */
/* Name        : Mcu_70_RL78F2X_InitClock                                     */
/* Param       : (in) ClockSetCfgPtr   Clock Set Config struct pointer.       */
/* Return      : E_OK                  Initializes Clock normal.              */
/*               E_NOT_OK              Initializes Clock abort.               */
/* Contents    : Initializes the PLL and other MCU specific clock options.    */
/* Author      : h.kiryu DucHT2                                               */
/* Note        : [SWS_Mcu_00155]                                              */
/******************************************************************************/
#if ( MCU_INIT_CLOCK != FALSE )
Std_ReturnType  Mcu_70_RL78F2X_InitClock( const Mcu_ClockSettingConfigType* ClockSetCfgPtr )
{
    Std_ReturnType rtn = E_OK;
    uint8 ostcCount;
    uint8 mcm0_0;                   /* current CKC.MCM0 */
    uint8 mcm0_1;                   /* new CKC.MCM0 */
    uint8 pllStsSelPlls;           /* for PLLSTS.SELPLLS */
    uint8 pllWaitCnt;               /* for wait PLLSTS.SELPLLS */
 
    s_ClockSettingData = ( const Mcu_70_RL78F2X_ClockSettingDataType* )ClockSetCfgPtr->McuClockSettingDataPtr;
    /* Don't change CKC.MCM0 when PLLCTL.PLLON = 1
     * clear PLLCTL.PLLON before change CKC.MCM0
     */
    /* PLLCTL.PLLON is 1? */
    if ( MCU_70_PLLCTL_PLLON == ( MCL_70_RL78F2X_PLLCTL_REG & MCU_70_PLLCTL_PLLON ) ) {
        /* Setting User's Manual Hardware : 5.6.4.Examples of Setting PLL Circuit.  */
        /* (2)  Examples of procedure for stopping PLL clock */
        mcm0_0 = MCL_70_RL78F2X_CKC_REG & MCU_70_CKC_MCM0;
        mcm0_1 = s_ClockSettingData->McuClockSettingCkc & MCU_70_CKC_MCM0;
        /* Want to change CKC.MCM0? */
        if ( mcm0_0 != mcm0_1 ) {
            /* <1> Select the PLL clock mode with the SELPLL bit of the PLLCTL register.  */
            MCL_70_RL78F2X_PLLCTL_REG &= MCU_70_PLLCTL_SELPLL_MASK;    /* PLLCTL.SELPLL=0 */
            pllWaitCnt = 0x00U; /* for wait PLLSTS.SELPLLS */
            do {
                /* <2> Confirm that the clock through mode is selected (SELPLLS = 0) with the SELPLLS */
                /*     bit of the PLLSTS register. */
                /* -- get PLLSTS.SELPLLS -- */
                pllStsSelPlls = ( uint8 )( MCL_70_RL78F2X_PLLSTS_REG & MCU_70_PLLSTS_SELPLLS );
                pllWaitCnt++;
            } while ( ( 0x00U != pllStsSelPlls ) && (  MCU_70_WAIT_SELPLLS > pllWaitCnt ) );
 
            if ( MCU_70_WAIT_SELPLLS <= pllWaitCnt ) {
                rtn = E_NOT_OK;
                return ( rtn ); /*  Wait error  */
            }
            /* <3> Clear the PLLON bit of the PLLCTL register to 0 to stop oscillation of the PLL clock. */
            MCL_70_RL78F2X_PLLCTL_REG &= MCU_70_PLLCTL_PLLON_MASK;    /* PLLCTL.PLLON = 0 */
        }
    }
 
    /* set CMC register */
    MCL_70_RL78F2X_CMC_REG = s_ClockSettingData->McuClockSettingCmc;
 
    /* set OSTS register */
    MCL_70_RL78F2X_OSTS_REG = s_ClockSettingData->McuClockSettingOsts;
 
    /* set CSC register */
    MCL_70_RL78F2X_CSC_REG = s_ClockSettingData->McuClockSettingCsc;
 
    /* set OSMC register */
    MCL_70_RL78F2X_OSMC_REG = s_ClockSettingData->McuClockSettingOsmc;
 
    /* set CKSEL register (before setting CKC register) */
    MCL_70_RL78F2X_CKSEL_REG = s_ClockSettingData->McuClockSettingCksel;
 
    /* Check OSTC when X1 clock is enable
     * Note: b7:MSTOP:0...X1 run  1...X1 stop
     */
    if ( 0x00U == ( MCL_70_RL78F2X_CSC_REG & 0x80U ) ) {/* X1 Clock Enable Check   */
        do {
            /* OSTC: Oscillation Stabilization time count status register
             * get OSTC value
             */
            ostcCount = MCL_70_RL78F2X_OSTC_REG;
        } while( ostcCount < s_ClockSettingData->McuClockSettingOstc );
    }
 
    /* control system clock */
    MCL_70_RL78F2X_CKC_REG = s_ClockSettingData->McuClockSettingCkc;
 
    /* PLL Seetting  */
    mcu_70_RL78F2X_PllSetting( s_ClockSettingData );
 
    return ( rtn );
}
#endif /* #if ( MCU_INIT_CLOCK != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : --                                                           */
/* Name        : Mcu_70_RL78F2X_DistributePllClock                            */
/* Param       : None                                                         */
/* Return      : E_NOT_OK             Clock distribution could not be done.   */
/*               E_OK                 Provide Pll clock normal.               */
/* Contents    : Provide PLL clock.                                           */
/* Author      : h.kiryu DucHT2                                               */
/* Note        : [SWS_Mcu_00156]                                              */
/******************************************************************************/
#if ( MCU_NO_PLL == FALSE )
Std_ReturnType Mcu_70_RL78F2X_DistributePllClock( void )
{
    Std_ReturnType rtn       = E_OK;
    uint8 pllStsSelPlls;     /* for PLLSTS.SELPLLS */
    uint16 pllWaitCnt;       /* for wait PLLSTS.SELPLLS */
    /* [SRS_Mcu_12336] */
    /* [SWS_Mcu_00122] */
    /* Return E_NOT_OK when PLL is not locked */
    /* Register PLLSTS
     * bit7  : LOCK
     */
 
    /* setting User's Manual Hardware : 5.6.4.Examples of Setting PLL Circuit.  */
    /* <8> Set the PLL clock between 1 MHz and 32 MHz with the MDIV bits of the MDIV register. */
    /* set MDIV register */
    MCL_70_RL78F2X_MDIV_REG = s_ClockSettingData->McuMDiv;
 
    /* <9> Select the PLL clock mode with the SELPLL bit of the PLLCTL register.   */
    /* select PLL */
    MCL_70_RL78F2X_PLLCTL_REG |= MCU_70_PLLCTL_SELPLL;    /* PLLCTL.SELPLL = 1U */
    pllWaitCnt = 0x00U; /* for wait PLLSTS.SELPLLS */
    do {
        pllStsSelPlls = MCL_70_RL78F2X_PLLSTS_REG & MCU_70_PLLSTS_SELPLLS;  /* get PLLSTS.SELPLLS */
        /* <10> Confirm that the PLL-clock-selected mode is selected (SELPLLS = 1) with the SELPLLS bit */
        /*      of the PLLSTS register. */
        pllWaitCnt++;
    } while (( 0x00U == pllStsSelPlls ) && ( MCU_70_WAIT_SELPLLS >= pllWaitCnt ));
 
    if ( MCU_70_WAIT_SELPLLS < pllWaitCnt ) {
        rtn = E_NOT_OK;
    }
 
    return ( rtn );
}
#endif /* #if ( MCU_NO_PLL == FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : --                                                           */
/* Name        : Mcu_70_RL78F2X_GetPllStatus                                  */
/* Param       : None                                                         */
/* Return      : MCU_PLL_LOCKED            PLL locked                         */
/*               MCU_PLL_UNLOCKED          PLL unlocked                       */
/*               MCU_PLL_STATUS_UNDEFINED  PLL status undefined (unused)      */
/* Contents    : Provide the lock status of the PLL                           */
/* Author      : h.kiryu DucHT2                                               */
/* Note        : [SWS_Mcu_00157]                                              */
/******************************************************************************/
#if ( MCU_NO_PLL == FALSE )
Mcu_PllStatusType Mcu_70_RL78F2X_GetPllStatus( void )
{
    Mcu_PllStatusType pllstatus;    /* no initial value for MISRA2012 Rule-2.2 */
    uint8             pllStsLock;
    uint8             pllCtlPllOn;
 
    /* Register PLLCTL
     * bit0  : PLLON
     */
    pllCtlPllOn = ( MCL_70_RL78F2X_PLLCTL_REG & MCU_70_PLLCTL_PLLON );    /* get PLLCTL.PLLON */
    /* Register PLLSTS
     * bit7  : LOCK
     */
    pllStsLock = ( MCL_70_RL78F2X_PLLSTS_REG & MCU_70_PLLSTS_LOCK );    /* get PLLSTS.LOCK */
    if ( 0x00U != pllCtlPllOn ) {    /* judge PLL using */
        if ( 0x00U != pllStsLock ) {    /* judge PLL status */
            pllstatus = MCU_PLL_LOCKED;    /* PLL locked */
        } else {
            pllstatus = MCU_PLL_UNLOCKED;    /* PLL unlocked */
        }
    } else {
        pllstatus = MCU_PLL_UNLOCKED;    /* PLL unlocked */
    }
 
    return ( pllstatus );
}
#endif /* #if ( MCU_NO_PLL == FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : --                                                           */
/* Name        : Mcu_70_RL78F2X_GetResetReason                                */
/* Param       : None                                                         */
/* Return      : MCU_POWER_ON_RESET    Power On Reset                         */
/*               MCU_WATCHDOG_RESET    Watchdog Timer underflows              */
/*               MCU_SW_RESET          Software Reset                         */
/*               MCU_RESET_UNDEFINED   Reset is undefined                     */
/* Contents    : Read the reset type from the hardware                        */
/* Author      : h.kiryu DucHT2                                               */
/* Note        : [SWS_Mcu_00158]                                              */
/******************************************************************************/
Mcu_ResetType Mcu_70_RL78F2X_GetResetReason ( void )
{
    /* Return reset type value */
    Mcu_ResetType resetType;    /* No initial value for MISRA2012 Rule-2.2 */
    /* Reset control flag register RESF
     * bit0: LVIRF
     * bit1: IAWRF
     * bit3: S/W reset
     * bit4: WDCLRF
     * bit7: TRAP
     * others: reserve
     */
    uint8 resfWdclrf;    /* Reset cause temporary storage variable */
    uint8 pocresPocres0; /* Reset check register by power on reset  */
 
    if ( s_McuResetFlag == E_NOT_OK ) {
        s_McuResetFlag = E_OK;
        Mcu_70_ResfCause = MCL_70_RL78F2X_RESF_REG;
        Mcu_70_PocresCause = MCL_70_RL78F2X_POCRES_REG;
    }
 
    resfWdclrf = Mcu_70_ResfCause; /* Get reset cause. */
    /* POR/CLM reset confirmation register POCRES
     * bit0: POCRES0
     * bit4: CLKRF
     * others: reserve
     */
    pocresPocres0 = ( uint8 )( Mcu_70_PocresCause & MCU_70_POCRES_POCRES0 );    /* get check power on reset bit */
 
    if ( MCU_70_RESF_WDCLRF == resfWdclrf ) {
        resetType = MCU_WATCHDOG_RESET;    /* Watchdog reset */
    } else {
        /* POCRES.POCRES0 = 0 when power on reset. */
        if ( MCU_70_POCRES_POCRES0 != pocresPocres0 ) {
            resetType = MCU_POWER_ON_RESET;    /* Power on reset */
        } else {
            if ( MCU_70_RESF_SWRESF == resfWdclrf ) {
                resetType = MCU_SW_RESET;            /* Software reset. */
            } else {
                resetType = MCU_RESET_UNDEFINED;    /* Reset undefined */
            }
        }
    }
 
    return( resetType );
}
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : --                                                           */
/* Name        : Mcu_70_RL78F2X_GetResetRawValue                              */
/* Param       : None                                                         */
/* Return      : Reset raw value.                                             */
/* Contents    : Read the reset type from the hardware register.              */
/* Author      : h.kiryu DucHT2                                               */
/* Note        : [SWS_Mcu_00159]                                              */
/******************************************************************************/
Mcu_RawResetType Mcu_70_RL78F2X_GetResetRawValue( void )
{
    /* Return value
     * bit15: Internal reset request by execution of illegal instruction
     * bit12: Internal reset request by watchdog timer (WDT) or clock monitor
     * bit11: S/W reset
     * bit9 : Internal reset request by illegal-memory access
     * bit8 : Internal reset request by voltage detector (LVD)
     * bit4 : Internal reset request by POR reset
     * bit0 : Internal reset request by clock monitor
     */
    Mcu_RawResetType rawReset;/* Return raw reset value */
    /* Reset control flag register RESF
     * bit0: LVIRF
     * bit1: IAWRF
     * bit3: S/W reset
     * bit4: WDCLRF
     * bit7: TRAP
     * others: reserve
     */
 
    if ( s_McuResetFlag == E_NOT_OK ) {
        s_McuResetFlag = E_OK;
        Mcu_70_ResfCause = MCL_70_RL78F2X_RESF_REG;
        Mcu_70_PocresCause = MCL_70_RL78F2X_POCRES_REG;
    }
 
    rawReset = Mcu_70_ResfCause;    /* Get RESF value. */
    rawReset = rawReset << 8U;
     /* POR/CLM reset confirmation register POCRES
      * bit0: POCRES0
      * bit4: CLKRF
      * others: reserve
      */
    rawReset = rawReset | ( ( uint32 )Mcu_70_PocresCause & 0x00000011UL );
 
    return( rawReset );
}
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : --                                                           */
/* Name        : Mcu_70_RL78F2X_SetMode                                       */
/* Param       : (in) McuMode       CPU Set Mode code                         */
/* Return      : void                                                         */
/* Contents    : Activate the MCU power modes                                 */
/* Author      : h.kiryu DucHT2                                               */
/* Note        : [SWS_Mcu_00161]                                              */
/******************************************************************************/
void Mcu_70_RL78F2X_SetMode( Mcu_ModeType McuMode )
{
    const Mcu_ModeSettingConfType*            modeSettingconfigPtr;
    const Mcu_70_RL78F2X_ModeSettingDataType* modesettingdata;
    /* [SWS_Mcu_00165] */
    modeSettingconfigPtr = &( s_McuConfigPtr->McuModuleConfiguration.McuModeSettingConfPtr[McuMode] );
    modesettingdata = ( const Mcu_70_RL78F2X_ModeSettingDataType *)( modeSettingconfigPtr->McuModeSettingDataPtr );
 
    /* SFR setting by configuration */
    MCL_70_RL78F2X_PER0_REG     = modesettingdata->McuPer0;
    MCL_70_RL78F2X_PER1_REG     = modesettingdata->McuPer1;
    MCL_70_RL78F2X_PER2_REG     = modesettingdata->McuPer2;
    MCL_70_RL78F2X_CANCKSEL_REG = modesettingdata->McuCancksel;
    MCL_70_RL78F2X_LINCKSEL_REG = modesettingdata->McuLincksel;
 
    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_00( );
    /* TAU0 */
    MCL_70_RL78F2X_TAU_UTSEL_ADR &= ( uint8 )( ~MCL_70_RL78F2X_TAU_UTSEL_TSEL0_1 );
    MCL_70_RL78F2X_TPS0_REG     = modesettingdata->McuTps0;
    /* TAU1 */
    MCL_70_RL78F2X_TAU_UTSEL_ADR |= ( uint8 )( MCL_70_RL78F2X_TAU_UTSEL_TSEL0_1 );
    MCL_70_RL78F2X_TPS1_REG     = modesettingdata->McuTps1;
    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_00( );
 
    /* [SWS_Mcu_00147] */
    /* [SRS_Mcu_12268] */
    /* [SWS_Mcu_00164] */
    /* Note:  *1 No need suspend/resume interrupt, because disable interrupt by EcuM before call Mcu_SetMode() */
    switch( McuMode ) {    /* Judge MCU mode */
    case MCU_70_MODE_HALT:
        __halt(); /*  CC-RL Halt Internal function */
        break;
    case MCU_70_MODE_STOP:    /* STOP mode */
        __stop(); /*  CC-RL stop Internal function */
        break;
    default:
        /* Other mode */
        break;
    }
}
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : --                                                           */
/* Name        : Mcu_70_RL78F2X_GetRamState                                   */
/* Param       : None                                                         */
/* Return      : E_OK     MCU_RAMSTATE_VALID   RAM state normal.              */
/*               E_NOT_OK MCU_RAMSTATE_INVALID Ram state bit error.           */
/* Contents    : Provide the actual status of the microcontroller RAM         */
/* Author      : h.kiryu DucHT2                                               */
/* Note        : [SWS_Mcu_00207]                                              */
/******************************************************************************/
#if ( MCU_GET_RAM_STATE_API != FALSE )
Std_ReturnType Mcu_70_RL78F2X_GetRamState( void )
{
    Std_ReturnType   rtn = E_OK;
    if ( MCU_RAMSTATE_INVALID == s_McuRamState ) {
        rtn = E_NOT_OK;
    }
    s_McuRamState = MCU_RAMSTATE_VALID;
 
    return ( rtn );
}
#endif /* #if ( MCU_GET_RAM_STATE_API != FALSE ) */
 
/******************************************************************************/
/* ModuleID    : MCU_MODULE_ID (101)                                          */
/* ServiceID   : --                                                           */
/* Name        : Mcu_70_RL78F2X_RamStateIsr                                   */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : ECC-RAM bit error detection interrupt.                       */
/* Author      : h.kiryu DucHT2                                               */
/* Note        : [SWS_Mcu_00207]                                              */
/******************************************************************************/
#if ( MCU_GET_RAM_STATE_API != FALSE )
void Mcu_70_RL78F2X_RamStateIsr( void )
{
    uint8  eccErReg;
 
    eccErReg = MCL_70_RL78F2X_ECCER_REG ; /* SFR ECCER Register  */
    if ( 0x00U == ( eccErReg & MCU_70_ECCER_DBERR ) ) { /* RAM Status Error Check */
        s_McuRamState = MCU_RAMSTATE_INVALID;
    }
}
#endif /* #if ( MCU_GET_RAM_STATE_API != FALSE ) */
 
#define MCU_STOP_SEC_CODE_LOCAL
#include "Mcu_MemMap.h"
 
/* EOF Mcu_70_RL78F2X.c **********************************************************/