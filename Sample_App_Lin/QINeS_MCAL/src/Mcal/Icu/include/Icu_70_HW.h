/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Icu_70_HW.h                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : ICU Module wrapper header                                    */
/*               The ICU is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ICU Driver                                                */
/* R22-11                                                                     */
#ifndef ICU_70_HW_H
#define ICU_70_HW_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Icu_70_HW_Types.h"
#include "Icu_70_RL78F2X.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ICU_70_VENDOR_ID_HW_H                     ( 70U )
#define ICU_70_MODULE_ID_HW_H                     (122U )

#define ICU_70_AR_RELEASE_MAJOR_VERSION_HW_H      ( 22U )
#define ICU_70_AR_RELEASE_MINOR_VERSION_HW_H      ( 11U )
#define ICU_70_AR_RELEASE_REVISION_VERSION_HW_H   (  0U )

#define ICU_70_SW_MAJOR_VERSION_HW_H              (  1U )
#define ICU_70_SW_MINOR_VERSION_HW_H              (  0U )
#define ICU_70_SW_PATCH_VERSION_HW_H              (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Std_Types.h version check start */
#if ( ICU_70_AR_RELEASE_MAJOR_VERSION_HW_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
    ( ICU_70_AR_RELEASE_MINOR_VERSION_HW_H != STD_TYPES_AR_RELEASE_MINOR_VERSION )
  #error "AUTOSAR Version Numbers of Icu_70_HW.h and Std_Types.h are different"
#endif
/* Std_Types.h version check end */

/* Icu_70_HW_Types.h version check start */
#if ( ICU_70_VENDOR_ID_HW_H != ICU_70_VENDOR_ID_HW_TYPES_H )
  #error "VENDOR ID for Icu_70_HW.h and Icu_70_HW_Types.h are different"
#endif

#if ( ICU_70_MODULE_ID_HW_H != ICU_70_MODULE_ID_HW_TYPES_H )
  #error "MODULE ID for Icu_70_HW.h and Icu_70_HW_Types.h are different"
#endif

#if ( ICU_70_AR_RELEASE_MAJOR_VERSION_HW_H != ICU_70_AR_RELEASE_MAJOR_VERSION_HW_TYPES_H ) || \
    ( ICU_70_AR_RELEASE_MINOR_VERSION_HW_H != ICU_70_AR_RELEASE_MINOR_VERSION_HW_TYPES_H ) || \
    ( ICU_70_AR_RELEASE_REVISION_VERSION_HW_H != ICU_70_AR_RELEASE_REVISION_VERSION_HW_TYPES_H )
  #error "AUTOSAR Version Numbers of Icu_70_HW.h and Icu_70_HW_Types.h are different"
#endif

#if ( ICU_70_SW_MAJOR_VERSION_HW_H != ICU_70_SW_MAJOR_VERSION_HW_TYPES_H ) || \
    ( ICU_70_SW_MINOR_VERSION_HW_H != ICU_70_SW_MINOR_VERSION_HW_TYPES_H ) || \
    ( ICU_70_SW_PATCH_VERSION_HW_H != ICU_70_SW_PATCH_VERSION_HW_TYPES_H )
  #error "Software Version Numbers of Icu_70_HW.h and Icu_70_HW_Types.h are different"
#endif
/* Icu_70_HW_Types.h version check end */

/* Icu_70_RL78F2X.h version check start */
#if ( ICU_70_VENDOR_ID_HW_H    != ICU_70_VENDOR_ID_RL78F2X_H )
  #error "VENDOR ID for Icu_70_HW.h and Icu_70_RL78F2X.h are different"
#endif

#if ( ICU_70_MODULE_ID_HW_H    != ICU_70_MODULE_ID_RL78F2X_H )
  #error "MODULE ID for Icu_70_HW.h and Icu_70_RL78F2X.h are different"
#endif

#if ( ICU_70_AR_RELEASE_MAJOR_VERSION_HW_H != ICU_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H ) || \
    ( ICU_70_AR_RELEASE_MINOR_VERSION_HW_H != ICU_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H ) || \
    ( ICU_70_AR_RELEASE_REVISION_VERSION_HW_H != ICU_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H )
  #error "AUTOSAR Version Numbers of Icu_70_HW.h and Icu_70_RL78F2X.h are different"
#endif

#if ( ICU_70_SW_MAJOR_VERSION_HW_H != ICU_70_SW_MAJOR_VERSION_RL78F2X_H ) || \
    ( ICU_70_SW_MINOR_VERSION_HW_H != ICU_70_SW_MINOR_VERSION_RL78F2X_H ) || \
    ( ICU_70_SW_PATCH_VERSION_HW_H != ICU_70_SW_PATCH_VERSION_RL78F2X_H )
  #error "Software Version Numbers of Icu_70_HW.h and Icu_70_RL78F2X.h are different"
#endif
/* Icu_70_RL78F2X.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                       */
/*----------------------------------------------------------------------------*/
#define ICU_70_TAU_RISING_EDGE             (uint8)(0x01U)   /* Rising edge for TAU TMRreg CISbit      */
#define ICU_70_TAU_FALLING_EDGE            (uint8)(0x00U)   /* Falling edge for TAU TMRreg CISbit     */
#define ICU_70_TAU_BOTH_EDGES              (uint8)(0x02U)   /* Both edges for TAU TMRreg CISbit       */
#define ICU_70_TRD_RISING_EDGE             (uint8)(0x01U)   /* Rising edge for TRD TRDI0RAreg IOnbit  */
#define ICU_70_TRD_FALLING_EDGE            (uint8)(0x00U)   /* Falling edge for TRD TRDI0RAreg IOnbit */
#define ICU_70_TRD_BOTH_EDGES              (uint8)(0x02U)   /* Both edges for TRD TRDI0RAreg IOnbit   */
#define ICU_70_INTP_RISING_EDGE            (uint8)(0x02U)   /* Rising edge for INTP                     */
#define ICU_70_INTP_FALLING_EDGE           (uint8)(0x03U)   /* Falling edge for INTP                    */
#define ICU_70_INTP_BOTH_EDGES             (uint8)(0x03U)   /* Both edges for INTP                      */
#define ICU_70_ACT_EDGE_NUM                (3U)             /* number of EdgeType                       */

#if ( ICU_70_TIMER_API_ENABLE != FALSE )
  #define Icu_70_HW_StartTimestamp        Icu_70_HW_StartTimer
  #define Icu_70_HW_StopTimestamp         Icu_70_HW_StopTimer
  #define Icu_70_HW_StartSignalMeasurement Icu_70_HW_StartTimer
  #define Icu_70_HW_StopSignalMeasurement  Icu_70_HW_StopTimer
#endif

#if ( ICU_70_EDGE_API_ENABLE != FALSE )
  #define Icu_70_HW_EnableEdgeCount       Icu_70_HW_EnableEdge
  #define Icu_70_HW_EnableEdgeDetection   Icu_70_HW_EnableEdge
  #define Icu_70_HW_DisableEdgeDetection  Icu_70_HW_DisableEdge
  #define Icu_70_HW_DisableEdgeCount      Icu_70_HW_DisableEdge
#endif

#define Icu_70_HW_ClrInt                  Icu_70_RL78F2X_TRD_ClrInt

/*----------------------------------------------------------------------------*/
/* Type definitions                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

extern void Icu_70_HW_Init( const Icu_70_HW_SetConfType* confPtr,
                            Icu_ActivationType         actType );
#if ( ICU_DE_INIT_API != FALSE )
extern void Icu_70_HW_DeInit( const Icu_70_HW_SetConfType* confPtr );
#endif

#if ( ICU_70_TIMER_API_ENABLE != FALSE )
extern void Icu_70_HW_StartTimer( const Icu_70_HW_SetConfType* confPtr,
                                  Icu_ActivationType         actType );
extern void Icu_70_HW_StopTimer( const Icu_70_HW_SetConfType* confPtr );
#endif

#if ( ICU_70_EDGE_API_ENABLE != FALSE )
extern void Icu_70_HW_EnableEdge( const Icu_70_HW_SetConfType* confPtr,
                                  Icu_ActivationType         actType );
extern void Icu_70_HW_DisableEdge( const Icu_70_HW_SetConfType* confPtr );
#endif

extern void Icu_70_HW_SetActivationCondition( const Icu_70_HW_SetConfType* confPtr,
                                              Icu_ActivationType         actType );
#if ( ICU_SET_MODE_API != FALSE )
extern void Icu_70_HW_EnableNonWakeupChannel( const Icu_70_HW_SetConfType* confPtr,
                                              Icu_ActivationType         actType );
extern void Icu_70_HW_DisableNonWakeupChannel(const Icu_70_HW_SetConfType* confPtr,
                                              Icu_ActivationType         actType );
#endif

#endif /* ICU_70_HW_H */

/* EOF Icu_70_HW.h ************************************************************/