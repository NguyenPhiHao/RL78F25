/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Gpt_70_RL78F2X_Types.h                                       */
/* Version     : v1.00.01                                                     */
/* Contents    : GPT Module type definition header                            */
/*               The GPT is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of GPT Driver                                                */
/* R22-11                                                                     */
#ifndef GPT_70_RL78F2X_TYPES_H
#define GPT_70_RL78F2X_TYPES_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Gpt_Cfg.h"
#include "Mcl_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define GPT_70_VENDOR_ID_RL78F2X_TYPES_H            ( 70U )
#define GPT_70_MODULE_ID_RL78F2X_TYPES_H            (100U )

#define GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H   ( 22U )
#define GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H   ( 11U )
#define GPT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H(  0U )

#define GPT_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H     (  1U )
#define GPT_70_SW_MINOR_VERSION_RL78F2X_TYPES_H     (  0U )
#define GPT_70_SW_PATCH_VERSION_RL78F2X_TYPES_H     (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Std_Types.h version check start */
#if ( GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
    ( GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H != STD_TYPES_AR_RELEASE_MINOR_VERSION )
    #error "AUTOSAR Version Numbers of Gpt_70_RL78F2X_Types.h and Std_Types.h are different"
#endif
/* Std_Types.h version check end */

/* Gpt_Cfg.h version check start */
#if ( GPT_70_VENDOR_ID_RL78F2X_TYPES_H != GPT_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Gpt_70_RL78F2X_Types.h and Gpt_Cfg.h are different"
#endif

#if ( GPT_70_MODULE_ID_RL78F2X_TYPES_H != GPT_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Gpt_70_RL78F2X_Types.h and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H   != GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_H   ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H   != GPT_70_AR_RELEASE_MINOR_VERSION_CFG_H   ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H!= GPT_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
    #error "AUTOSAR Version Numbers of Gpt_70_RL78F2X_Types.h and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H != GPT_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_MINOR_VERSION_RL78F2X_TYPES_H != GPT_70_SW_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_PATCH_VERSION_RL78F2X_TYPES_H != GPT_70_SW_PATCH_VERSION_CFG_H ) )
    #error "Software Version Numbers of Gpt_70_RL78F2X_Types.h and Gpt_Cfg.h are different"
#endif

/* Gpt_Cfg.h version check end */

/* Mcl_70_RL78F2X.h version check start */

#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H != MCL_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H != MCL_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) )
    #error "AUTOSAR Version Numbers of Gpt_70_RL78F2X_Types.h and Mcl_70_RL78F2X.h are different"
#endif

/* Mcl_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/* timer type */
#define GPT_70_RL78F2X_TIMERTYPE_TAU    ( 0U )    /* TAU */
#define GPT_70_RL78F2X_TIMERTYPE_TRJ    ( 1U )    /* TRJ */
#define GPT_70_RL78F2X_TIMERTYPE_TRD    ( 2U )    /* TRD */
#define GPT_70_RL78F2X_TIMERTYPE_NUM    ( 3U )    /* number of timer types */

#define GPT_70_RL78F2X_TAU_UNIT0        ( 0U )    /* F25 TAU0 */
#define GPT_70_RL78F2X_TAU_UNIT1        ( 1U )    /* F25 TAU1 */

#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )    /* TAU* input from ELC for predef timer */
#define GPT_70_RL78F2X_TAU00_ELC        ( MCL_70_RL78F2X_TI50_TI50A )
#define GPT_70_RL78F2X_TAU01_ELC        ( MCL_70_RL78F2X_TI50_TI50B )
#define GPT_70_RL78F2X_TAU02_ELC        ( MCL_70_RL78F2X_TI50_TI50C )
#define GPT_70_RL78F2X_TAU03_ELC        ( MCL_70_RL78F2X_TI50_TI507 )
#endif /* #if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE ) */

/*----------------------------------------------------------------------------*/
/* type definitions                                               */
/*----------------------------------------------------------------------------*/

/* H/W dependent timer setting register/bit definition for TAU/TRJ/TRD convert type */
typedef struct {
    uint8    timerType;    /* timer unit type */
    uint8    unitNo;       /* timer unit number */
    uint8    chNo;         /* timer channel number in unit */
    void*    contPtr;      /* top address of continuous address registers */
} Gpt_70_HW_RL78F2X_SettingConfType;

/* H/W dependent timer setting register/bit definition type for TAU */
typedef struct {
    uint8                             timerType;   /* timer unit type */
    uint8                             unitNo;      /* timer unit number */
    uint8                             chNo;        /* timer channel number in unit */
    Mcl_70_RL78F2X_TAU_ContRegType*   contPtr;     /* top address of continuous address registers */
    Mcl_70_RL78F2X_TAU_FixRegType*    fixPtr;      /* top address of fixed address registers */
    io16*                             tauTdrReg;   /* address of TDRMn register */
    uint16                            tauTmrData;  /* data for TMRMn register */
} Gpt_70_RL78F2X_TAU_SettingConfType;

/* H/W dependent timer setting register/bit definition type for TRJ */
typedef struct {
    uint8                             timerType;       /* timer unit type */
    uint8                             unitNo;          /* timer unit number */
    uint8                             chNo;            /* timer channel number in unit */
    Mcl_70_RL78F2X_TRJ_ContRegType*   contPtr;         /* top address of continuous address registers */
    io16*                             trjPtr;          /* address of TRJx register */
    uint8                             trjTrjMrData;    /* data for TRJMRx register */
} Gpt_70_RL78F2X_TRJ_SettingConfType;

/* H/W dependent timer setting register/bit definition type for TRD */
typedef struct {
    uint8                             timerType;       /* timer unit type */
    uint8                             unitNo;          /* timer unit number */
    uint8                             chNo;            /* timer channel number in unit */
    Mcl_70_RL78F2X_TRD_ContRegType*   contPtr;         /* top address of continuous address registers */
    Mcl_70_RL78F2X_TRD_FixRegType*    fixPtr;          /* top address of fixed address registers */
    uint8                             trdTrdCrData;    /* data for TRDCRx register */
} Gpt_70_RL78F2X_TRD_SettingConfType;

#if ( GPT_70_PREDEF_TIMER_ENABLE != FALSE )
/* [ECUC_Gpt_00183] Gpt Driver Configuration */
typedef struct {
#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED )
    /* configuration for 1us predef timer */
    /* for 1us 16/24/32bit predef timer */
#if ( GPT_70_PREDEF_1US_ELC_ENABLE != FALSE )
    const Gpt_70_HW_RL78F2X_SettingConfType*  channelConf1us;       /* 1us timer setting */
    uint16                                    timerValue1us;        /* 1us timer cycle value */
    uint8                                     elcEiselIdxLower;     /* pointer of 1us->lower link ELSELR register */
    uint8                                     elcEiselValueLower;   /* value of 1us->lower link ELSELR register */
#endif  /* GPT_70_PREDEF_1US_ELC_ENABLE != FALSE */

    /* lower predef timer setting */
    const Gpt_70_HW_RL78F2X_SettingConfType*  channelConfLower;
#if ( GPT_70_PREDEF_1US_USE_ELC != FALSE )
    uint8                                     tis0Value;            /* value for TIS0 register */
#endif  /* GPT_70_PREDEF_1US_USE_ELC != FALSE */
#endif  /* GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_DISABLED */

#if ( GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED )
    /* for 1us 24/32bit predef timer */
    /* higher predef timer setting */
    const Gpt_70_HW_RL78F2X_SettingConfType*  channelConfHigher;
    uint8                                     elcEiselIdxHigher;    /* pointer of lower->higher link ELSELR register */
    uint8                                     elcEiselValueHigher;  /* value of lower->higher link ELSELR register */
#endif  /* GPT_PREDEF_TIMER_1US_ENABLING_GRADE != GPT_PREDEF_TIMER_1US_16BIT_ENABLED */

#if ( GPT_70_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE )
    /* configuration for 100us 32bit predef timer */
    /* 100us timer setting */
    const Gpt_70_HW_RL78F2X_SettingConfType*  channelConf100us;
    uint16                                    timerValue100us;         /* 100us timer cycle value */
    uint8                                     elcEiselIdxLower100us;   /* pointer of 1us->lower link ELSELR register */
    uint8                                     elcEiselValueLower100us; /* value of 1us->lower link ELSELR register */

    /* 100us lower predef timer setting */
    const Gpt_70_HW_RL78F2X_SettingConfType*  channelConfLower100us;
    uint8                                     tis0Value100us;          /* value for TIS0 register */

    /* 100us higher predef timer setting */
    const Gpt_70_HW_RL78F2X_SettingConfType*  channelConfHigher100us;
    uint8                                     elcEiselIdxHigher100us;  /* pointer of lower->higher link ELSELR register */
    uint8                                     elcEiselValueHigher100us;/* value of lower->higher link ELSELR register */
#endif  /* GPT_70_PREDEF_TIMER_100US_32BIT_ENABLE != FALSE */

} Gpt_70_RL78F2X_PredefTimerConfType;
#endif  /* GPT_70_PREDEF_TIMER_ENABLE != FALSE */

/*----------------------------------------------------------------------------*/
/* external variables                                                         */                                             */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */                                */
/*----------------------------------------------------------------------------*/


#endif /* #ifndef GPT_70_HW_TYPES_H_ */

/* EOF Gpt_70_RL78F2X_Types.h ****************************************/
