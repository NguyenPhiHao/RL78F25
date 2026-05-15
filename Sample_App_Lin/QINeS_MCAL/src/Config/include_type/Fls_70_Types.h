/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Fls_70_Types.h                                               */
/* Version     : v1.00.00                                                     */
/* Contents    : Fls Module type definition header                            */
/*               The Fls is a basic software module at the service            */
/*               layer of the standardized basic software                     */
/*               architecture of AUTOSAR.                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */
#ifndef FLS_70_TYPES_H_
#define FLS_70_TYPES_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Fls_Cfg.h"
#include "Fls_70_RL78F2X_Types.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define FLS_70_VENDOR_ID_TYPES_H                       ( 70U )
#define FLS_70_MODULE_ID_TYPES_H                       ( 92U )

#define FLS_70_AR_RELEASE_MAJOR_VERSION_TYPES_H        ( 22U )
#define FLS_70_AR_RELEASE_MINOR_VERSION_TYPES_H        ( 11U )
#define FLS_70_AR_RELEASE_REVISION_VERSION_TYPES_H     (  0U )

#define FLS_70_SW_MAJOR_VERSION_TYPES_H                ( 1U )
#define FLS_70_SW_MINOR_VERSION_TYPES_H                ( 0U )
#define FLS_70_SW_PATCH_VERSION_TYPES_H                ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Fls_Cfg.h version check start */
#if ( FLS_70_VENDOR_ID_TYPES_H != FLS_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Fls_70_Types.h and Fls_Cfg.h are different"
#endif

#if ( FLS_70_MODULE_ID_TYPES_H != FLS_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Fls_70_Types.h and Fls_Cfg.h are different"
#endif
/* Fls_Cfg.h version check end */

/* Fls_70_RL78F2X_Types.h version check start */
#if ( FLS_70_VENDOR_ID_TYPES_H    != FLS_70_VENDOR_ID_RL78F2X_TYPES_H )
    #error "VENDOR ID for Fls_70_Types.h and Fls_70_RL78F2X_Types.h are different"
#endif

#if ( FLS_70_MODULE_ID_TYPES_H    != FLS_70_MODULE_ID_RL78F2X_TYPES_H )
    #error "MODULE ID for Fls_70_Types.h and Fls_70_RL78F2X_Types.h are different"
#endif

#if ( ( FLS_70_AR_RELEASE_MAJOR_VERSION_TYPES_H    != FLS_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_TYPES_H    ) || \
      ( FLS_70_AR_RELEASE_MINOR_VERSION_TYPES_H    != FLS_70_AR_RELEASE_MINOR_VERSION_RL78F2X_TYPES_H    ) || \
      ( FLS_70_AR_RELEASE_REVISION_VERSION_TYPES_H != FLS_70_AR_RELEASE_REVISION_VERSION_RL78F2X_TYPES_H )    \
    )
    #error "AUTOSAR Version Numbers of Fls_70_Types.h and Fls_70_RL78F2X_Types.h are different"
#endif

#if ( ( FLS_70_SW_MAJOR_VERSION_TYPES_H   != FLS_70_SW_MAJOR_VERSION_RL78F2X_TYPES_H ) || \
      ( FLS_70_SW_MINOR_VERSION_TYPES_H   != FLS_70_SW_MINOR_VERSION_RL78F2X_TYPES_H ) || \
      ( FLS_70_SW_PATCH_VERSION_TYPES_H   != FLS_70_SW_PATCH_VERSION_RL78F2X_TYPES_H )    \
    )
    #error "Software Version Numbers of Fls_70_Types.h and Fls_70_RL78F2X_Types.h are different"
#endif
/* Fls_70_RL78F2X_Types.h version check end */

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/* [SWS_Fls_00369] Fls_AddressType (enumeration) */

typedef uint32 Fls_AddressType;

/* [SWS_Fls_00370] Fls_LengthType (enumeration) */
typedef uint32 Fls_LengthType;

/* job parameter */
typedef struct {
    uint8            FlsJobType;       /* (0..3) */
    uint8            FlsBlockNumber;   /* (0..15) */
    uint8*           DataAddress;      /* (0x0..0xFFFFFFFF) */
    bool_t           FlsExecuteFlg;    /* (0..1) */
    bool_t           FlsForceStop;     /* (0..1) */
    Fls_AddressType  FlsAddress;       /* (0x0..0xFFFFFFFF) */
    Fls_LengthType   FlsLength;        /* (0x0..0xFFFFFFFF) */
} Fls_70_ControlType;

/* [ECUC_Fls_00202] FlsSector */
typedef struct {
    uint16           FlsNumberOfSectors;     /* [ECUC_Fls_00280] (1)(0..65535) */
    Fls_LengthType   FlsPageSize;            /* [ECUC_Fls_00281] (1)(0..4294967295) */
    Fls_LengthType   FlsSectorSize;          /* [ECUC_Fls_00282] (1)(0..4294967295) */
    Fls_AddressType  FlsSectorStartaddress;  /* [ECUC_Fls_00283] (1)(0..4294967295) */
} Fls_SectorType;

/* [ECUC_Fls_00201] FlsSectorList */
typedef struct {
    Fls_SectorType   FlsSector[FLS_70_MAX_NUMBER_SECTOR]; /* (1..*) */
} Fls_SectorListType;

/* [ECUC_Fls_00307] FlsJobEndNotification (callback function) */
typedef void (*Fls_JobEndNotificationType)(void);

/* [ECUC_Fls_00274] FlsJobErrorNotification (callback function) */
typedef void (*Fls_JobErrorNotificationType)(void);

/* [ECUC_Fls_00174] FlsConfigSet */
typedef struct {
    Fls_AddressType             FlsAcErase;               /* [ECUC_Fls_00370] (1)(0..4294967295) */
    Fls_AddressType             FlsAcWrite;               /* [ECUC_Fls_00305] (1)(0..4294967295) */
    MemIf_ModeType              FlsDefaultMode;           /* [ECUC_Fls_00318] (1)(0..1) */
    Fls_JobEndNotificationType  FlsJobEndNotification;    /* [ECUC_Fls_00307] (0..1) */
    Fls_JobErrorNotificationType FlsJobErrorNotification; /* [ECUC_Fls_00274] (0..1) */
    Fls_LengthType              FlsMaxReadFastMode;       /* [ECUC_Fls_00275] (1)(0..4294967295) */
    Fls_LengthType              FlsMaxReadNormalMode;     /* [ECUC_Fls_00276] (1)(0..4294967295) */
    Fls_LengthType              FlsMaxWriteFastMode;      /* [ECUC_Fls_00277] (1)(0..4294967295) */
    Fls_LengthType              FlsMaxWriteNormalMode;    /* [ECUC_Fls_00278] (1)(0..4294967295) */
    uint32                      FlsProtection;            /* [ECUC_Fls_00279] (1)(0..4294967295) */
    Fls_SectorListType          FlsSectorList;            /* [ECUC_Fls_00201] (1..*) */
} Fls_ConfigSetType;

/* [SWS_Fls_00368] FlsConfig */
typedef struct {
    Fls_ConfigSetType   FlsConfigSet;    /* (1) */
} Fls_ConfigType;

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* Job types */
#define FLS_70_JOB_NONE       ( uint8 )0
#define FLS_70_JOB_ERASE      ( uint8 )1
#define FLS_70_JOB_WRITE      ( uint8 )2
#define FLS_70_JOB_READ       ( uint8 )3
#define FLS_70_JOB_COMPARE    ( uint8 )4
#define FLS_70_JOB_BLANKCHECK ( uint8 )5

#define FLS_70_E_OK           ( uint8 )0x00U    /* success */
#define FLS_70_E_NOT_OK       ( uint8 )0xFFU    /* fail */

/* Macro Number */
#define FLS_70_ZERO           ( uint8  )0
#define FLS_70_ONE            ( uint8  )1
#define FLS_70_BLOCK_SIZE     ( uint16 )0x3FFU

#endif /* #ifndef FLS_70_TYPES_H_ */

/* EOF Fls_70_Types.h ****************************************/
