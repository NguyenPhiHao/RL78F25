/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Pwm_70_RL78F2X_Types.h                                       */
/* Version     : v1.00.00                                                     */
/* Contents    : PWM Module type definition header                            */
/*               The PWM is a basic software module at the service layer      */
/*               of the standardized basic software architecture of AUTOSAR.  */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of PWM Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef PWM_70_RL78F2X_TYPES_H_
#define PWM_70_RL78F2X_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Mcl_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define PWM_70_VENDOR_ID_RL78F2X_TYPES_H             ( 70U )
#define PWM_70_MODULE_ID_RL78F2X_TYPES_H             (121U)

#define PWM_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H    ( 22U )
#define PWM_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H    ( 11U )
#define PWM_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H (  0U )

#define PWM_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H      ( 1U )
#define PWM_70_SW_MINOR_VERSION_RL78F2X_TYPES_H      ( 0U )
#define PWM_70_SW_PATCH_VERSION_RL78F2X_TYPES_H      ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
    /* Std_Types.h version check start */
    #if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
          ( PWM_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H != STD_TYPES_AR_RELEASE_MINOR_VERSION )   )
    #   error "AUTOSAR Version Numbers of Pwm_70_RL78F2X_Types.h and Std_Types.h are different"
    #endif
    /* Mcl_70_RL78F2X.h version check start */
    #if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H != MCL_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
          ( PWM_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H != MCL_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H )   )
    #   error "AUTOSAR Version Numbers of Pwm_70_RL78F2X_Types.h and Mcl_70_RL78F2X.h are different"
    #endif
#endif /* QINES_MCAL_VERSION_NO_CHECK != TRUE */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* Mcl_70_RL78F2X.h version check start */
#if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H    != MCL_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H   ) || \
      ( PWM_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H    != MCL_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H   ) || \
      ( PWM_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H != MCL_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H )   )
#   error "AUTOSAR Version Numbers of Pwm_70_RL78F2X_Types.h and Mcl_70_RL78F2X.h are different"
#endif
/* Mcl_70_RL78F2X.h version check end */
#endif /* QINES_MCAL_VERSION_NO_CHECK != TRUE */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define PWM_70_RL78F2X_TIMERMODE_MASTER      ( 0U )
#define PWM_70_RL78F2X_TIMERMODE_SLAVE       ( 1U )

#define PWM_70_RL78F2X_TAU_MASTER_CHANNEL_NUM  ( 8U )
#define PWM_70_RL78F2X_TRD_MASTER_CHANNEL_NUM  ( 2U )
#define PWM_70_RL78F2X_MASTER_CHANNEL_MAX      ( PWM_70_RL78F2X_TAU_MASTER_CHANNEL_NUM \
                                               + PWM_70_RL78F2X_TRD_MASTER_CHANNEL_NUM )

/* TAU unit ID */
#define PWM_70_RL78F2X_TAU_UNIT_0    ( 0U )
#define PWM_70_RL78F2X_TAU_UNIT_1    ( 1U )
#define PWM_70_RL78F2X_TAU_UNIT_NUM  ( 2U )

/* TAU physical channel ID */
#define PWM_70_RL78F2X_TAU_PHCH_ID_0 ( 0U )
#define PWM_70_RL78F2X_TAU_PHCH_ID_1 ( 1U )
#define PWM_70_RL78F2X_TAU_PHCH_ID_2 ( 2U )
#define PWM_70_RL78F2X_TAU_PHCH_ID_3 ( 3U )
#define PWM_70_RL78F2X_TAU_PHCH_ID_4 ( 4U )
#define PWM_70_RL78F2X_TAU_PHCH_ID_5 ( 5U )
#define PWM_70_RL78F2X_TAU_PHCH_ID_6 ( 6U )
#define PWM_70_RL78F2X_TAU_PHCH_ID_7 ( 7U )

/* TRD unit ID */
#define PWM_70_RL78F2X_TRD_UNIT_0    ( 0U )
#define PWM_70_RL78F2X_TRD_UNIT_NUM  ( 1U )

/* TRD physical channel ID */
#define PWM_70_RL78F2X_TRD_PHCH_ID_0 ( 0U )
#define PWM_70_RL78F2X_TRD_PHCH_ID_1 ( 1U )

/* timer type */
#define PWM_70_RL78F2X_TIMERTYPE_TAU ( 0U )
#define PWM_70_RL78F2X_TIMERTYPE_TRD ( 1U )
#define PWM_70_RL78F2X_TIMERTYPE_NUM ( 2U )

/* register value */
#define PWM_70_MASTER_SET            (0x0800U)  /* Master bit of TMR register */
#define PWM_70_STS_MASTER            (0x0400U)  /* TST bit of TMR register */
#define PWM_70_MD_INTERVAL           (0x000FU)  /* MD bit of TMR register (Interval Mode 2) */
#define PWM_70_MD_ONECOUNT           (0x0009U)  /* MD bit of TMR register (OneCount Mode 2) */
#define PWM_70_TMR_INIT              (0x0000U)  /* TMR register initial value */
#define PWM_70_TRDMR_TRDBF           (0x30U)    /* TRDMR register TRDBF bit value */
#define PWM_70_TRDMR_TRDBFC          (0x10U)    /* TRDMR register TRDBFC bit value */
#define PWM_70_TRDMR_TRDBFD          (0x20U)    /* TRDMR register TRDBFD bit value */
#define PWM_70_TRDMR_TRDPWM          (0x07U)    /* TRDMR register TRDPWM bit value */
#define PWM_70_TRDOER1_EA            (0x0EU)    /* TRDOER1 register EA bit value */
#define PWM_70_TRDFCR_INIT           (0x80U)    /* TRDFCR register initial value */
#define PWM_70_TRDCR_INIT            (0x20U)    /* TRDCR register initial value */
#define PWM_70_TRDPOCR_MASK          (0x07U)    /* TRDPOCR register initial value */
#define PWM_70_TRDTRSR_MASK          (0x03U)    /* TRDSR register initial value */
#define PWM_70_TRDIER_MASK           (0x03U)    /* TRDIER register initial value */

#define PWM_70_PRESCALE_MASK         (0x03U)

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/* TAU channel register info */
typedef struct {
    Mcl_70_RL78F2X_TAU_ContRegType* contPtr;
    Mcl_70_RL78F2X_TAU_FixRegType*  fixPtr;
    io16*                           regTdr;       /* address of TDRmn register */
} Pwm_70_RL78F2X_TAU_RegInfoType;

/* TAU channel configuration */
typedef struct {
    uint8                                pwmPrescale;
    uint8                                timerType;
    uint8                                unitId;
    uint8                                masterChId;
    const Pwm_70_RL78F2X_TAU_RegInfoType* mastarRegInfoPtr;
    const Pwm_70_RL78F2X_TAU_RegInfoType* slaveRegInfoPtr;
} Pwm_70_RL78F2X_TAU_ConfType;

/* TRD channel register info */
typedef struct {
    Mcl_70_RL78F2X_TRD_ContRegType* contPtr;
    Mcl_70_RL78F2X_TRD_FixRegType*  fixPtr;
    io16*                           regTrdStr;    /* address of Tsr register */
} Pwm_70_RL78F2X_TRD_RegInfoType;

/* TRD channel configuration */
typedef struct {
    uint8                                pwmPrescale;
    uint8                                timerType;
    uint8                                unitId;
    uint8                                masterChId;
    const Pwm_70_RL78F2X_TRD_RegInfoType* mastarRegInfoPtr;
    const Pwm_70_RL78F2X_TRD_RegInfoType* slaveRegInfoPtr;
} Pwm_70_RL78F2X_TRD_ConfType;

#endif /* PWM_70_RL78F2X_TYPES_H_ */

/* EOF Pwm_70_RL78F2X_Types.h ****************************************************/

