/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Pwm_70_Types.h                                               */
/* Version     : v1.00.00                                                     */
/* Contents    : PWM Module type definition header                            */
/*               The PWM is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of PWM Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef PWM_70_TYPES_H_
#define PWM_70_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Pwm_70_HW_Types.h"
#include "Pwm_Cfg.h"
#include "Mcu_70_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define PWM_70_VENDOR_ID_TYPES_H                   ( 70U )
#define PWM_70_MODULE_ID_TYPES_H                   (121U)

#define PWM_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    ( 22U )
#define PWM_70_AR_RELEASE_MINOR_VERSION_TYPES_H    ( 11U )
#define PWM_70_AR_RELEASE_REVISION_VERSION_TYPES_H (  0U )

#define PWM_70_SW_MAJOR_VERSION_TYPES_H            (  1U )
#define PWM_70_SW_MINOR_VERSION_TYPES_H            (  0U )
#define PWM_70_SW_PATCH_VERSION_TYPES_H            (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
  /* Std_Types.h version check start */
  #if ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
        ( PWM_70_AR_RELEASE_MINOR_VERSION_TYPES_H != STD_TYPES_AR_RELEASE_MINOR_VERSION )   )
    #error "AUTOSAR Version Numbers of Pwm_70_Types.h and Std_Types.h are different"
  #endif
#endif /* QINES_MCAL_VERSION_NO_CHECK != TRUE */

/* Pwm_70_HW_Types.h version check start */
#if   ( PWM_70_VENDOR_ID_TYPES_H    != PWM_70_VENDOR_ID_HW_TYPES_H )
#   error "VENDOR ID for Pwm_70_Types.h and Pwm_70_HW_Types.h is different"
#endif

#if   ( PWM_70_MODULE_ID_TYPES_H    != PWM_70_MODULE_ID_HW_TYPES_H )
#   error "MODULE ID for Pwm_70_Types.h and Pwm_70_HW_Types.h is different"
#endif

#if   ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != PWM_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H ) || \
        ( PWM_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != PWM_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H ) || \
        ( PWM_70_AR_RELEASE_REVISION_VERSION_TYPES_H != PWM_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H )   )
#   error "AUTOSAR Version Numbers of Pwm_70_Types.h and Pwm_70_HW_Types.h are different"
#endif

#if   ( ( PWM_70_SW_MAJOR_VERSION_TYPES_H != PWM_70_SW_MAJOR_VERSION_HW_TYPES_H ) || \
        ( PWM_70_SW_MINOR_VERSION_TYPES_H != PWM_70_SW_MINOR_VERSION_HW_TYPES_H ) || \
        ( PWM_70_SW_PATCH_VERSION_TYPES_H != PWM_70_SW_PATCH_VERSION_HW_TYPES_H )     )
#   error "Software Version Numbers of Pwm_70_Types.h and Pwm_70_HW_Types.h are different"
#endif
/* Pwm_70_HW_Types.h version check end */

/* Pwm_Cfg.h version check start */
#if   ( PWM_70_VENDOR_ID_TYPES_H    != PWM_70_VENDOR_ID_CFG_H )
#   error "VENDOR ID for Pwm_70_Types.h and Pwm_Cfg.h is different"
#endif

#if   ( PWM_70_MODULE_ID_TYPES_H    != PWM_70_MODULE_ID_CFG_H )
#   error "MODULE ID for Pwm_70_Types.h and Pwm_Cfg.h is different"
#endif

#if   ( ( PWM_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != PWM_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
        ( PWM_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != PWM_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
        ( PWM_70_AR_RELEASE_REVISION_VERSION_TYPES_H != PWM_70_AR_RELEASE_REVISION_VERSION_CFG_H )   )
#   error "AUTOSAR Version Numbers of Pwm_70_Types.h and Pwm_Cfg.h are different"
#endif

#if   ( ( PWM_70_SW_MAJOR_VERSION_TYPES_H != PWM_70_SW_MAJOR_VERSION_CFG_H ) || \
        ( PWM_70_SW_MINOR_VERSION_TYPES_H != PWM_70_SW_MINOR_VERSION_CFG_H ) || \
        ( PWM_70_SW_PATCH_VERSION_TYPES_H != PWM_70_SW_PATCH_VERSION_CFG_H )     )
#   error "Software Version Numbers of Pwm_70_Types.h and Pwm_Cfg.h are different"
#endif
/* Pwm_Cfg.h version check end */

/* [SWS_Pwm_00110] */
/* Defines the class of a PWM channel */
typedef enum {
    PWM_VARIABLE_PERIOD,
    PWM_FIXED_PERIOD,
    PWM_FIXED_PERIOD_SHIFTED
} Pwm_ChannelClassType;

/* [SWS_Pwm_00108] */
/* Output state of a PWM channel */
typedef enum {
    PWM_LOW,
    PWM_HIGH
} Pwm_OutputStateType;

/* [SWS_Pwm_00109] */
/* Definition of the type of edge notification of a PWM channel */
typedef enum {
    PWM_RISING_EDGE,
    PWM_FALLING_EDGE,
    PWM_BOTH_EDGES
} Pwm_EdgeNotificationType;

/* [QINeS_SWS_PWM_00004] */
/* Type for PWM module state */
typedef enum {
    PWM_STATE_UNINIT,
    PWM_STATE_INIT
} Pwm_70_ModuleStateType;

/* [SWS_Pwm_00106] */
/* Numeric identifier of a PWM channel */
typedef uint16 Pwm_ChannelType;

/* [SWS_Pwm_00107] */
/* Definition of the period of a PWM channel */
typedef uint16 Pwm_PeriodType;

/* [ECUC_Pwm_00027] Configuration of an individual PWM channel */
typedef struct {
    /* [ECUC_Pwm_00136] PWM channel class */
    Pwm_ChannelClassType                 PwmChannelClass;
    /* [ECUC_Pwm_00137] PWM ID channel */
    Pwm_ChannelType                      PwmChannelId;
    /* [ECUC_Pwm_00138] PWM default cycle channel duty */
    uint32                               PwmDutycycleDefault;
    /* [ECUC_Pwm_00122] PWM idle channel output state */
    Pwm_OutputStateType                  PwmIdleState;
    /* [ECUC_Pwm_00123] The callback function pointer for PWM notification channel */
    void (*Pwm_Notification)( void );
    /* [ECUC_Pwm_00124] PWM default cycle channel */
    Pwm_PeriodType                       PwmPeriodDefault;
    /* [ECUC_Pwm_00125] PWM channel output polarity */
    Pwm_OutputStateType                  PwmPolarity;
    /* [ECUC_Pwm_00147] reference to the McuClockReferencePoint */
    const Mcu_ClockReferencePointType*   PwmMcuClockReferencePoint;
    /* [QINeS_SWS_PWM_00004] Pwm_SettingConfigType */
    const Pwm_70_HW_ConfigType*          PwmSettingConfigPtr;
} Pwm_ChannelConfigType;

/* [ECUC_Pwm_00140] Multiple Configuration Set Container */
typedef struct {
    const Pwm_ChannelConfigType*         PwmChannel;            /* [ECUC_Pwm_00027] */
} Pwm_ChannelConfigSetType;

/* [SWS_Pwm_00111] */
/* This is the type of data structure containing the initialization data for the PWM driver. */
typedef struct {
    const Pwm_ChannelConfigSetType*      PwmChannelConfigSet;   /* [ECUC_Pwm_00140] */
} Pwm_ConfigType;

/* The callback function pointer for PWM notification channel */
typedef struct {
    const Pwm_ChannelConfigType*         ChannelConfigPtr;      /* ChannelConfiguration pointer */
    const Pwm_70_HW_ConfigType*          setChInfoPtr;
    Pwm_PeriodType                       period;                /* period */
    uint32                               duty;                  /* duty cycle */
    Pwm_OutputStateType                  idleState;             /* idle status */
    Pwm_OutputStateType                  activeLevel;           /* polarity */
    Pwm_EdgeNotificationType             notifSwitch;           /* Notify the specified edge trigger */
    bool_t                               notifEnable;           /* The Notify flag of PWM channel */
} Pwm_70_ChannelInfoType;

#endif /* !defined PWM_70_TYPES_H */

/* EOF Pwm_70_Types.h **********************************************/ 
