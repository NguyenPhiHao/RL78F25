/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Can_70_RL78F2X_HwReg_Dep.h                                   */
/* Version     : v1.00.00                                                     */
/* Contents    : This module provides services for initiating                 */
/*               transmissions and calls the callback functions of            */
/*               the CanIf module for notifying events,                       */
/*               independently from the hardware. Also it provides            */
/*               services to control the behavior and state of the            */
/*               CAN controllers that belong to the same CAN                  */
/*               Hardware Unit.                                               */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of CAN Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef CAN_70_RL78F2X_HWREG_DEP_H
#define CAN_70_RL78F2X_HWREG_DEP_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define CAN_70_VENDOR_ID_RL78F2X_HWREG_DEP_H             ( 70U )
#define CAN_70_MODULE_ID_RL78F2X_HWREG_DEP_H             ( 80U )

#define CAN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_HWREG_DEP_H  ( 22U )
#define CAN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_HWREG_DEP_H  ( 11U )
#define CAN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_HWREG_DEP_H (  0U )

#define CAN_70_SW_MAJOR_VERSION_RL78F2X_HWREG_DEP_H      (  1U )
#define CAN_70_SW_MINOR_VERSION_RL78F2X_HWREG_DEP_H      (  0U )
#define CAN_70_SW_PATCH_VERSION_RL78F2X_HWREG_DEP_H      (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/* See chapter F24(21.3.1) / F25(22.3.1) of the hardware manual. */
/* See chapter F24(21.3.2) / F25(22.3.2) of the hardware manual. */
#define CAN_70_RL78F2X_INDEX_0L    ( (uint8)0U ) /* IF/MK0L */
#define CAN_70_RL78F2X_INDEX_0H    ( (uint8)1U ) /* IF/MK0H */
#define CAN_70_RL78F2X_INDEX_1L    ( (uint8)2U ) /* IF/MK1L */
#define CAN_70_RL78F2X_INDEX_1H    ( (uint8)3U ) /* IF/MK1H */
#define CAN_70_RL78F2X_INDEX_2L    ( (uint8)4U ) /* IF/MK2L */
#define CAN_70_RL78F2X_INDEX_2H    ( (uint8)5U ) /* IF/MK2H */
#define CAN_70_RL78F2X_INDEX_3L    ( (uint8)6U ) /* IF/MK3L */
#define CAN_70_RL78F2X_INDEX_3H    ( (uint8)7U ) /* IF/MK3H */

/*---< CAN0 >---*/
/* index */
#define CAN_70_RL78F2X_INDEX_RCAN0GRVC  CAN_70_RL78F2X_INDEX_2H /* IF/MK2H */
#define CAN_70_RL78F2X_INDEX_RCAN0ERR   CAN_70_RL78F2X_INDEX_2H /* IF/MK2H */
#define CAN_70_RL78F2X_INDEX_RCAN0WUP   CAN_70_RL78F2X_INDEX_2H /* IF/MK2H */
#define CAN_70_RL78F2X_INDEX_RCAN0CFR   CAN_70_RL78F2X_INDEX_3L /* IF/MK3L */
#define CAN_70_RL78F2X_INDEX_RCAN0TRM   CAN_70_RL78F2X_INDEX_3L /* IF/MK3L */
#define CAN_70_RL78F2X_INDEX_RCAN0GRFR  CAN_70_RL78F2X_INDEX_3L /* IF/MK3L */
#define CAN_70_RL78F2X_INDEX_RCAN0GERR  CAN_70_RL78F2X_INDEX_3L /* IF/MK3L */

/* bit */
#define CAN_70_RL78F2X_MASK_RCAN0GRVC  ( (uint8)0x1U  ) /* IF/MK2H bit4 */
#define CAN_70_RL78F2X_MASK_RCAN0ERR   ( (uint8)0x2U  ) /* IF/MK2H bit5 */
#define CAN_70_RL78F2X_MASK_RCAN0WUP   ( (uint8)0x40U ) /* IF/MK2H bit6 */
#define CAN_70_RL78F2X_MASK_RCAN0CFR   ( (uint8)0x1U  ) /* IF/MK3L bit0 */
#define CAN_70_RL78F2X_MASK_RCAN0TRM   ( (uint8)0x2U  ) /* IF/MK3L bit1 */
#define CAN_70_RL78F2X_MASK_RCAN0GRFR  ( (uint8)0x4U  ) /* IF/MK3L bit2 */
#define CAN_70_RL78F2X_MASK_RCAN0GERR  ( (uint8)0x8U  ) /* IF/MK3L bit3 */

/*---< CAN1 >---*/
/* index */
#define CAN_70_RL78F2X_INDEX_RCAN1GRVC  CAN_70_RL78F2X_INDEX_3H /* IF/MK3H */
#define CAN_70_RL78F2X_INDEX_RCAN1ERR   CAN_70_RL78F2X_INDEX_3H /* IF/MK3H */
#define CAN_70_RL78F2X_INDEX_RCAN1WUP   CAN_70_RL78F2X_INDEX_3H /* IF/MK3H */
#define CAN_70_RL78F2X_INDEX_RCAN1CFR   CAN_70_RL78F2X_INDEX_3H /* IF/MK3H */
#define CAN_70_RL78F2X_INDEX_RCAN1TRM   CAN_70_RL78F2X_INDEX_3L /* IF/MK3L */
#define CAN_70_RL78F2X_INDEX_RCAN1GRFR  CAN_70_RL78F2X_INDEX_3L /* IF/MK3L */
#define CAN_70_RL78F2X_INDEX_RCAN1GERR  CAN_70_RL78F2X_INDEX_3L /* IF/MK3L */

/* bit */
#define CAN_70_RL78F2X_MASK_RCAN1GRVC  ( (uint8)0x1U  ) /* IF/MK3H bit0 */
#define CAN_70_RL78F2X_MASK_RCAN1ERR   ( (uint8)0x2U  ) /* IF/MK3H bit1 */
#define CAN_70_RL78F2X_MASK_RCAN1WUP   ( (uint8)0x80U ) /* IF/MK3H bit7 */
#define CAN_70_RL78F2X_MASK_RCAN1CFR   ( (uint8)0x4U  ) /* IF/MK3H bit2 */
#define CAN_70_RL78F2X_MASK_RCAN1TRM   ( (uint8)0x20U ) /* IF/MK3H bit5 */
#define CAN_70_RL78F2X_MASK_RCAN1GRFR  ( (uint8)0x40U ) /* IF/MK3H bit6 */
#define CAN_70_RL78F2X_MASK_RCAN1GERR  ( (uint8)0x80U ) /* IF/MK3H bit7 */

/*---< CAN-RAM ECC >---*/
/* index */
#define CAN_70_RL78F2X_INDEX_CRAM      CAN_70_RL78F2X_INDEX_3H /* IF/MK3H */
/* bit */
#define CAN_70_RL78F2X_MASK_CRAM       ( (uint8)0x10U ) /* IF/MK3H bit4 */

/* See chapter F24(---) / F25(19.3.68) of the hardware manual. */
#define CAN_70_RL78F2X_REG_CFDWINR     (*(volatile uint8 QL_70_NEAR *)0x01F7U)
#define CAN_70_RL78F2X_MASK_CFDWINR_CSELO  ( (uint8)0x1U )

/******************************************************************************/
/* ModuleID    : --                                                      */
/* ServiceID   : --                                                      */
/* Name        : CAN_70_CONTROLLER_SELECT_WITH_EXCLUSIVE                 */
/* Param       : (in) canChannel    CAN Channel of RL78F2x (CAN0/CAN1)    */
/* Return      : void                                                     */
/* Contents    : select CAN Channel (CAN0/CAN1)                           */
/* Author      : --                                                           */
/* Note        : --                                                           */                                                       */
/******************************************************************************/
#define CAN_70_CONTROLLER_SELECT_WITH_EXCLUSIVE(canChannel)               \
do {                                                                     \
    /* Disable interrupts while CAN channel is selected. */              \
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_00();                              \
    /* Channel Select */                                                 \
    if ( CAN_70_CAN_CHANNEL_CAN0 == (canChannel) ) {                     \
        CAN_70_RL78F2X_REG_CFDWINR = CAN_70_RL78F2X_BIT_CFDWINR_CSELO_CAN0; \
    } else {                                                             \
        CAN_70_RL78F2X_REG_CFDWINR = CAN_70_RL78F2X_BIT_CFDWINR_CSELO_CAN1; \
    }                                                                    \
} while (0)

/******************************************************************************/
/* ModuleID    : --                                                      */
/* ServiceID   : --                                                      */
/* Name        : CAN_70_CONTROLLER_SELECT_NO_EXCLUSIVE                   */
/* Param       : (in) canChannel    CAN Channel of RL78F2x (CAN0/CAN1)    */
/* Return      : void                                                     */
/* Contents    : select CAN Channel (CAN0/CAN1)                           */
/* Author      : --                                                           */
/* Note        : --                                                           */                                                       */
/******************************************************************************/
#define CAN_70_CONTROLLER_SELECT_NO_EXCLUSIVE(canChannel)                \
do {                                                                     \
    /* Channel Select */                                                 \
    if ( CAN_70_CAN_CHANNEL_CAN0 == (canChannel) ) {                     \
        CAN_70_RL78F2X_REG_CFDWINR = CAN_70_RL78F2X_BIT_CFDWINR_CSELO_CAN0; \
    } else {                                                             \
        CAN_70_RL78F2X_REG_CFDWINR = CAN_70_RL78F2X_BIT_CFDWINR_CSELO_CAN1; \
    }                                                                    \
} while (0)

/******************************************************************************/
/* ModuleID    : --                                                      */
/* ServiceID   : --                                                      */
/* Name        : CAN_70_CONTROLLER_RELEASE_WITH_EXCLUSIVE                */
/* Param       : void                                                     */
/* Return      : void                                                     */
/* Contents    : release exclusive access after channel selection        */
/* Author      : --                                                           */
/* Note        : --                                                           */                                                       */
/******************************************************************************/
#define CAN_70_CONTROLLER_RELEASE_WITH_EXCLUSIVE()                       \
do {                                                                     \
    /* Interrupts are enabled. */                                        \
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00();                                \
} while (0)

/******************************************************************************/
/* ModuleID    : --                                                      */
/* ServiceID   : --                                                      */
/* Name        : CAN_70_CONTROLLER_RELEASE_NO_EXCLUSIVE                 */
/* Param       : void                                                    */
/* Return      : void                                                    */
/* Contents    : select CAN Channel(CAN0/CAN1)                           */
/* Author      : --                                                           */
/* Note        : --                                                           */                                                      */
#define CAN_70_CONTROLLER_RELEASE_NO_EXCLUSIVE()                        \
do {                                                                     \
    /* do nothing. */                                                    \
} while (0)

/*----------------------------------------------------------------------------*/
/* type definitions */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables */
/*----------------------------------------------------------------------------*/

#endif /* #ifndef CAN_70_RL78F2X_HWREG_DEP_H */
/* EOF Can_70_RL78F2X_HwReg_Dep.h ********************************************/
