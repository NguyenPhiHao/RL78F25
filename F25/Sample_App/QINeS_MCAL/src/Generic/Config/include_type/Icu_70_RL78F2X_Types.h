/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Icu_70_RL78F2X_Types.h                                       */
/* Version     : v1.00.01                                                     */
/* Contents    : ICU Module type definition header                            */
/*               The ICU is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of ICU Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef ICU_70_RL78F2X_TYPES_H_
#define ICU_70_RL78F2X_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Icu_Cfg.h"
#include "Mcl_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define ICU_70_VENDOR_ID_RL78F2X_TYPES_H                      (70U)
#define ICU_70_MODULE_ID_RL78F2X_TYPES_H                      (122U)

#define ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H       (22U)
#define ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H       (11U)
#define ICU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H    (0U)

#define ICU_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H               (1U)
#define ICU_70_SW_MINOR_VERSION_RL78F2X_TYPES_H               (0U)
#define ICU_70_SW_PATCH_VERSION_RL78F2X_TYPES_H               (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H != STD_TYPES_AR_RELEASE_MINOR_VERSION ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_RL78F2X_Types.h and Std_Types.h are different"
#endif

/* Std_Types.h version check end */

/* Icu_Cfg.h version check start */

#if ( ICU_70_VENDOR_ID_RL78F2X_TYPES_H != ICU_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Icu_70_RL78F2X_Types.h and Icu_Cfg.h are different"
#endif

#if ( ICU_70_MODULE_ID_RL78F2X_TYPES_H != ICU_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Icu_70_RL78F2X_Types.h and Icu_Cfg.h are different"
#endif

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H    != ICU_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H    != ICU_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( ICU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H != ICU_70_AR_RELEASE_REVISION_VERSION_CFG_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_RL78F2X_Types.h and Icu_Cfg.h are different"
#endif

#if ( ( ICU_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H != ICU_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( ICU_70_SW_MINOR_VERSION_RL78F2X_TYPES_H != ICU_70_SW_MINOR_VERSION_CFG_H ) || \
      ( ICU_70_SW_PATCH_VERSION_RL78F2X_TYPES_H != ICU_70_SW_PATCH_VERSION_CFG_H ) \
    )
    #error "Software Version Numbers of Icu_70_RL78F2X_Types.h and Icu_Cfg.h are different"
#endif

/* Icu_Cfg.h version check end */
 
/* Mcl_70_RL78F2X.h version check start */

#if ( ( ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H != MCL_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
      ( ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H != MCL_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) \
    )
    #error "AUTOSAR Version Numbers of Icu_70_RL78F2X_Types.h and Mcl_70_RL78F2X.h are different"
#endif

/* Mcl_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
#define ICU_70_TIMER_TAU0           ( uint8 )( 0U )         /* ICU TIMER UNIT TAU0   */
#define ICU_70_TIMER_TAU1           ( uint8 )( 1U )         /* ICU TIMER UNIT TAU1   */
#define ICU_70_TIMER_TRJ            ( uint8 )( 2U )         /* ICU TIMER UNIT TRJ    */
#define ICU_70_TIMER_TRD            ( uint8 )( 3U )         /* ICU TIMER UNIT TRD    */
#define ICU_70_TIMER_UNIT_NONE      ( uint8 )( 255U )       /* ICU TIMER UNIT NO USE */

#define ICU_70_TIMER_TAU_CH0        ( uint8 )( 0U )         /* ICU TIMER CHANNEL TAU CH0  */
#define ICU_70_TIMER_TAU_CH1        ( uint8 )( 1U )         /* ICU TIMER CHANNEL TAU CH1  */
#define ICU_70_TIMER_TAU_CH2        ( uint8 )( 2U )         /* ICU TIMER CHANNEL TAU CH2  */
#define ICU_70_TIMER_TAU_CH3        ( uint8 )( 3U )         /* ICU TIMER CHANNEL TAU CH3  */
#define ICU_70_TIMER_TAU_CH4        ( uint8 )( 4U )         /* ICU TIMER CHANNEL TAU CH4  */
#define ICU_70_TIMER_TAU_CH5        ( uint8 )( 5U )         /* ICU TIMER CHANNEL TAU CH5  */
#define ICU_70_TIMER_TAU_CH6        ( uint8 )( 6U )         /* ICU TIMER CHANNEL TAU CH6  */
#define ICU_70_TIMER_TAU_CH7        ( uint8 )( 7U )         /* ICU TIMER CHANNEL TAU CH7  */
#define ICU_70_TIMER_CH_NONE        ( uint8 )( 255U )       /* ICU TIMER CHANNEL NO USE   */

#define ICU_70_TIMER_TRD_CH0        ( uint8 )( 0U )         /* ICU TIMER CHANNEL TRD CH0  */
#define ICU_70_TIMER_TRD_CH1        ( uint8 )( 1U )         /* ICU TIMER CHANNEL TRD CH1  */

#define ICU_70_INTP0                ( uint8 )( 0U )         /* ICU INTP0 ID    */
#define ICU_70_INTP1                ( uint8 )( 1U )         /* ICU INTP1 ID    */
#define ICU_70_INTP2                ( uint8 )( 2U )         /* ICU INTP2 ID    */
#define ICU_70_INTP3                ( uint8 )( 3U )         /* ICU INTP3 ID    */
#define ICU_70_INTP4                ( uint8 )( 4U )         /* ICU INTP4 ID    */
#define ICU_70_INTP5                ( uint8 )( 5U )         /* ICU INTP5 ID    */
#define ICU_70_INTP6                ( uint8 )( 6U )         /* ICU INTP6 ID    */
#define ICU_70_INTP7                ( uint8 )( 7U )         /* ICU INTP7 ID    */
#define ICU_70_INTP8                ( uint8 )( 8U )         /* ICU INTP8 ID    */
#define ICU_70_INTP9                ( uint8 )( 9U )         /* ICU INTP9 ID    */
#define ICU_70_INTP10               ( uint8 )( 10U )        /* ICU INTP10 ID   */
#define ICU_70_INTP11               ( uint8 )( 11U )        /* ICU INTP11 ID   */
#define ICU_70_INTP12               ( uint8 )( 12U )        /* ICU INTP12 ID   */
#define ICU_70_INTP13               ( uint8 )( 13U )        /* ICU INTP13 ID   */
#define ICU_70_INTP_NONE            ( uint8 )( 255U )       /* ICU INTP NO USE */

/* For Configuration */
#define ICU_70_TMR_CIS2                   ( uint16 )( 0x0080U )
#define ICU_70_TMR_CIS3                   ( uint16 )( 0x00C0U )
#define ICU_70_TMR_CIS_CLEAR              ( uint16 )( ~( ICU_70_TMR_CIS3 ) )  /* For TAU Valid edge clear */
#define ICU_70_TRDIORA                    ( uint8 )( 0x04U ) /* TRD set as ICU          */
#define ICU_70_TRD_TRDIORA_IO             ( uint8 )( 0x03U ) /* TRD Valid edge clear    */
#define ICU_70_TRDIORA_BOTH_EDGE          ( uint8 )( 0x02U ) /* Valid edge BOTH         */
#define ICU_70_TRDIOA                     ( uint8 )( 0x00U ) /* Input Port TRDIOA       */
#define ICU_70_TRDIOB                     ( uint8 )( 0x01U ) /* Input Port TRDIOB       */

/* Define macros for configuration only for the peripheral to be used. */
#if ( ( ICU_70_ENABLE_TAU_ANY == TRUE ) && ( ICU_70_ENABLE_INTP_ANY == TRUE ) \
   && ( ICU_70_ENABLE_TRD_ANY == TRUE ) )
#define ICU_70_INPUT_INPUTTYPE_NUM       ( uint8 )( 3U )         /* number of timer types */
#define ICU_70_INPUT_TAU                 ( uint8 )( 0U )         /* ICU INPUT TYPE TAU */
#define ICU_70_INPUT_TRD                 ( uint8 )( 1U )         /* ICU INPUT TYPE TRD */
#define ICU_70_INPUT_INTP                ( uint8 )( 2U )         /* ICU INPUT TYPE INTP */
#elif ( ( ICU_70_ENABLE_TAU_ANY != TRUE ) && ( ICU_70_ENABLE_INTP_ANY == TRUE ) \
     && ( ICU_70_ENABLE_TRD_ANY == TRUE ) )
#define ICU_70_INPUT_INPUTTYPE_NUM       ( uint8 )( 2U )         /* number of timer types */
#define ICU_70_INPUT_TRD                 ( uint8 )( 0U )         /* ICU INPUT TYPE TRD */
#define ICU_70_INPUT_INTP                ( uint8 )( 1U )         /* ICU INPUT TYPE INTP */
#elif ( ( ICU_70_ENABLE_TAU_ANY == TRUE ) && ( ICU_70_ENABLE_INTP_ANY != TRUE ) \
     && ( ICU_70_ENABLE_TRD_ANY == TRUE ) )
#define ICU_70_INPUT_INPUTTYPE_NUM       ( uint8 )( 2U )         /* number of timer types */
#define ICU_70_INPUT_TAU                 ( uint8 )( 0U )         /* ICU INPUT TYPE TAU */
#define ICU_70_INPUT_TRD                 ( uint8 )( 1U )         /* ICU INPUT TYPE TRD */
#elif ( ( ICU_70_ENABLE_TAU_ANY == TRUE ) && ( ICU_70_ENABLE_INTP_ANY == TRUE ) \
     && ( ICU_70_ENABLE_TRD_ANY != TRUE ) )
#define ICU_70_INPUT_INPUTTYPE_NUM       ( uint8 )( 2U )         /* number of timer types */
#define ICU_70_INPUT_TAU                 ( uint8 )( 0U )         /* ICU INPUT TYPE TAU */
#define ICU_70_INPUT_INTP                ( uint8 )( 1U )         /* ICU INPUT TYPE INTP */
#elif ( ( ICU_70_ENABLE_TAU_ANY != TRUE ) && ( ICU_70_ENABLE_INTP_ANY != TRUE ) \
     && ( ICU_70_ENABLE_TRD_ANY == TRUE ) )
#define ICU_70_INPUT_INPUTTYPE_NUM       ( uint8 )( 1U )         /* number of timer types */
#define ICU_70_INPUT_TRD                 ( uint8 )( 0U )         /* ICU INPUT TYPE TRD */
#elif ( ( ICU_70_ENABLE_TAU_ANY != TRUE ) && ( ICU_70_ENABLE_INTP_ANY == TRUE ) \
     && ( ICU_70_ENABLE_TRD_ANY != TRUE ) )
#define ICU_70_INPUT_INPUTTYPE_NUM       ( uint8 )( 1U )         /* number of timer types */
#define ICU_70_INPUT_INTP                ( uint8 )( 0U )         /* ICU INPUT TYPE INTP */
#elif ( ( ICU_70_ENABLE_TAU_ANY == TRUE ) && ( ICU_70_ENABLE_INTP_ANY != TRUE ) \
     && ( ICU_70_ENABLE_TRD_ANY != TRUE ) )
#define ICU_70_INPUT_INPUTTYPE_NUM       ( uint8 )( 1U )         /* number of timer types */
#define ICU_70_INPUT_TAU                 ( uint8 )( 0U )         /* ICU INPUT TYPE INTP */
#else
#error "Configuration error. Set parameter ICU_70_ENABLE_***_ANY to TRUE. "
#endif

#define ICU_CHANNEL_0   ( 0U )                 /* ICU CHANNEL 0  */
#define ICU_CHANNEL_1   ( 1U )                 /* ICU CHANNEL 1  */
#define ICU_CHANNEL_2   ( 2U )                 /* ICU CHANNEL 2  */
#define ICU_CHANNEL_3   ( 3U )                 /* ICU CHANNEL 3  */
#define ICU_CHANNEL_4   ( 4U )                 /* ICU CHANNEL 4  */
#define ICU_CHANNEL_5   ( 5U )                 /* ICU CHANNEL 5  */
#define ICU_CHANNEL_6   ( 6U )                 /* ICU CHANNEL 6  */
#define ICU_CHANNEL_7   ( 7U )                 /* ICU CHANNEL 7  */
#define ICU_CHANNEL_8   ( 8U )                 /* ICU CHANNEL 8  */
#define ICU_CHANNEL_9   ( 9U )                 /* ICU CHANNEL 9  */
#define ICU_CHANNEL_10  ( 10U )                /* ICU CHANNEL 10  */
#define ICU_CHANNEL_11  ( 11U )                /* ICU CHANNEL 11  */
#define ICU_CHANNEL_12  ( 12U )                /* ICU CHANNEL 12  */
#define ICU_CHANNEL_13  ( 13U )                /* ICU CHANNEL 13  */
#define ICU_CHANNEL_14  ( 14U )                /* ICU CHANNEL 14  */
#define ICU_CHANNEL_15  ( 15U )                /* ICU CHANNEL 15  */
#define ICU_CHANNEL_16  ( 16U )                /* ICU CHANNEL 16  */
#define ICU_CHANNEL_17  ( 17U )                /* ICU CHANNEL 17  */
#define ICU_CHANNEL_18  ( 18U )                /* ICU CHANNEL 18  */
#define ICU_CHANNEL_19  ( 19U )                /* ICU CHANNEL 19  */
#define ICU_CHANNEL_20  ( 20U )                /* ICU CHANNEL 20  */
#define ICU_CHANNEL_21  ( 21U )                /* ICU CHANNEL 21  */
#define ICU_CHANNEL_22  ( 22U )                /* ICU CHANNEL 22  */
#define ICU_CHANNEL_23  ( 23U )                /* ICU CHANNEL 23  */
#define ICU_CHANNEL_24  ( 24U )                /* ICU CHANNEL 24  */
#define ICU_CHANNEL_25  ( 25U )                /* ICU CHANNEL 25  */
#define ICU_CHANNEL_26  ( 26U )                /* ICU CHANNEL 26  */
#define ICU_CHANNEL_27  ( 27U )                /* ICU CHANNEL 27  */
#define ICU_CHANNEL_28  ( 28U )                /* ICU CHANNEL 28  */
#define ICU_CHANNEL_29  ( 29U )                /* ICU CHANNEL 29  */
#define ICU_CHANNEL_30  ( 30U )                /* ICU CHANNEL 30  */
#define ICU_CHANNEL_31  ( 31U )                /* ICU CHANNEL 31  */
#define ICU_CHANNEL_32  ( 32U )                /* ICU CHANNEL 32  */

/* H/W dependent setting register type for TAU */
#if ( ICU_70_ENABLE_TAU_ANY != FALSE )
typedef struct {
    volatile uint16 regTdr;                             /* For setting TDR     */
} Icu_70_RL78F2X_TAU_TdrRegType;

/* H/W dependent setting register type for TAU */
typedef struct {
    volatile uint8 regNfen;                             /* For setting NFEN    */
} Icu_70_RL78F2X_TAU_NfenRegType;
#endif
#if ( ICU_70_ENABLE_TRD_ANY != FALSE )
/* H/W dependent setting register type for TRD */
typedef struct {
    volatile uint8 regTrddf;                            /* For setting TRDDF   */
} Icu_70_RL78F2X_TRD_TrddfRegType;
#endif
#if ( ICU_70_ENABLE_INTP_ANY != FALSE )
/* H/W dependent setting register type for INTP */
typedef struct {
    volatile uint8 regEgp;                              /* For setting EGP     */
} Icu_70_RL78F2X_INTP_EgpRegType;
/* H/W dependent setting register type for INTP */
typedef struct {
    volatile uint8 regEgn;                              /* For setting EGN     */
} Icu_70_RL78F2X_INTP_EgnRegType;
#endif

/* H/W dependent timer setting register/bit definition for TAU/TRD convert type */
typedef struct {
    uint8                               icuInputType;   /* Input Type(TAU/TRD/Intp)            */
    uint8                               icuHwNo;        /* TAU/TRD Channel Number, INTP Number */
    void*                               contPtr;
} Icu_70_RL78F2X_SettingConfType;

#if ( ICU_70_ENABLE_TAU_ANY != FALSE )
/* H/W dependent setting register/bit definition type for TAU */
typedef struct {
    uint8                               icuInputType;   /* Input Type(TAU/TRD/Intp)            */
    uint8                               icuHwNo;        /* TAU/TRD Channel Number, INTP Number */
    Mcl_70_RL78F2X_TAU_ContRegType*     contPtr;        /* TAU continuous address registers */
    Mcl_70_RL78F2X_TAU_FixRegType*      fixPtr;         /* TAU fixed address registers      */
    Icu_70_RL78F2X_TAU_NfenRegType*     nfenPtr;        /* address of NFENn register        */
    Icu_70_RL78F2X_TAU_TdrRegType*      tdrPtr;         /* address of TDRmn register        */
    uint16                              tauTmrData;     /* setting TMR register data        */
#if ( ICU_SET_MODE_API != FALSE)
    io8*                                tauMKPtr;       /* address of Interrupt mask register  */
    uint8                               tauMKData;      /* value of TAU interrupt source       */
#endif
    uint8                               tauUnit;
} Icu_70_RL78F2X_TAU_SettingConfType;
#endif

#if ( ICU_70_ENABLE_TRD_ANY != FALSE )
/* H/W dependent setting register/bit definition type for TRD */
typedef struct {
    uint8                               icuInputType;   /* Input Type(TAU/TRD/Intp)            */
    uint8                               icuHwNo;        /* TAU/TRD Channel Number, INTP Number */
    Mcl_70_RL78F2X_TRD_ContRegType*     contPtr;        /* TRD continuous address registers */
    Mcl_70_RL78F2X_TRD_FixRegType*      fixPtr;         /* TRD fixed address registers      */
    uint8                               inputPort;      /* Use Input Port                   */
    uint8                               trdTrdCrData;   /* data for TRDCRx register         */
    Icu_70_RL78F2X_TRD_TrddfRegType*    trddfPtr;       /* address of TRDDF register */
#if ( ICU_SET_MODE_API != FALSE)
    io8*                                trdMKPtr;       /* address of Interrupt mask register  */
    uint8                               trdMKData;      /* value of TRD interrupt source       */
#endif
} Icu_70_RL78F2X_TRD_SettingConfType;
#endif

#if ( ICU_70_ENABLE_INTP_ANY != FALSE )
/* H/W dependent setting register/bit definition type for INTP */
typedef struct {
    uint8                               icuInputType;   /* Input Type(TAU/TRD/Intp)            */
    uint8                               icuHwNo;        /* TAU/TRD Channel Number, INTP Number */
    Icu_70_RL78F2X_INTP_EgpRegType*     egpPtr;         /* address of EGP register        */
    Icu_70_RL78F2X_INTP_EgnRegType*     egnPtr;         /* address of EGN register        */
} Icu_70_RL78F2X_INTP_SettingConfType;
#endif
/*----------------------------------------------------------------------------*/
/* External Variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototypes                                                        */
/*----------------------------------------------------------------------------*/

#endif /* #ifndef ICU_70_RL78F2X_TYPES_H_ */

/* EOF Icu_70_RL78F2X_Types.h *************************************************/
