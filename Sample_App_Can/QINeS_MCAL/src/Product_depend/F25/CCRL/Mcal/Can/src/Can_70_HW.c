/******************************************************************************/
/* Copyright   : 2023 SCSK Corporation                                        */
/* System Name : QINeS-Lite MCAL                                              */
/* File Name   : Can_70_HW.c                                                  */
/* Version     : v1.00.00                                                     */
/* Contents    : This module provides services for initiating transmissions   */
/*               and calls the callback functions of the CanIf module for     */
/*               notifying events, independently from the hardware. Also it   */
/*               provides services to control the behavior and state of the   */
/*               CAN controllers that belong to the same CAN Hardware Unit.   */
/* Author      : r.sharma, r.itoh, h.shishido                                 */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of CAN Driver                                                */
/* R22-11                                                                     */
 
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
 
#include "Can_70_HW.h"
 
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define CAN_70_VENDOR_ID_HW_C                      ( 70U )
#define CAN_70_MODULE_ID_HW_C                      ( 80U )
 
#define CAN_70_AR_RELEASE_MAJOR_VERSION_HW_C       ( 22U )
#define CAN_70_AR_RELEASE_MINOR_VERSION_HW_C       ( 11U )
#define CAN_70_AR_RELEASE_REVISION_VERSION_HW_C    (  0U )
 
#define CAN_70_SW_MAJOR_VERSION_HW_C               (  1U )
#define CAN_70_SW_MINOR_VERSION_HW_C               (  0U )
#define CAN_70_SW_PATCH_VERSION_HW_C               (  0U )
 
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Can_70_HW.h version check start */
 
/* Check if current file and Can_70_HW.h header file are of the same Vendor ID */
#if (CAN_70_VENDOR_ID_HW_C    != CAN_70_VENDOR_ID_HW_H)
    #error "VENDOR ID for Can_70_HW.c and Can_70_HW.h are different"
#endif      /* End of Vendor Id Version check */
 
#if (CAN_70_MODULE_ID_HW_C    != CAN_70_MODULE_ID_HW_H)
    #error "MODULE ID for Can_70_HW.c and Can_70_HW.h are different"
#endif      /* End of Module Id Version check */
 
/* Check if current file and Can_70_HW.h header file are of the same Software version */
#if ((CAN_70_SW_MAJOR_VERSION_HW_C    != CAN_70_SW_MAJOR_VERSION_HW_H) ||\
     (CAN_70_SW_MINOR_VERSION_HW_C    != CAN_70_SW_MINOR_VERSION_HW_H) ||\
     (CAN_70_SW_PATCH_VERSION_HW_C    != CAN_70_SW_PATCH_VERSION_HW_H))
    #error "Software Version Numbers of Can_70_HW.c and Can_70_HW.h are different"
#endif      /* End of S/W Version check */
 
/* Check if current file and Can_70_HW.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_HW_C    != CAN_70_AR_RELEASE_MAJOR_VERSION_HW_H)   ||\
     (CAN_70_AR_RELEASE_MINOR_VERSION_HW_C    != CAN_70_AR_RELEASE_MINOR_VERSION_HW_H)   ||\
     (CAN_70_AR_RELEASE_REVISION_VERSION_HW_C != CAN_70_AR_RELEASE_REVISION_VERSION_HW_H))
    #error "AUTOSAR Version Numbers of Can_70_HW.c and Can_70_HW.h are different"
#endif      /* End of Autosar Version check */
 
/* Can_70_HW.c version check end */
 
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
 
/* EOF Can_70_HW.c ****************************************************************/