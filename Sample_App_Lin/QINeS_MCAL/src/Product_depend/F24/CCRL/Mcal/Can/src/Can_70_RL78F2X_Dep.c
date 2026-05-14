/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Can_70_RL78F2X_Dep.c                                         */
/* Version     : v1.00.00                                                     */
/* Contents    : This module provides services for initiating transmissions   */
/*               and calls the callback functions of the CanIf module for     */
/*               notifying events, independently from the hardware. Also it   */
/*               provides services to control the behavior and state of the   */
/*               CAN controllers that belong to the same CAN Hardware Unit.   */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of CAN Driver                                                */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Can.h"
#include "Can_70_RL78F2X.h"
#include "Can_70_RL78F2X_HwReg.h"
#include "CanIf_Cbk.h"
#include "SchM_Can.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define CAN_70_VENDOR_ID_RL78F2X_DEP_C                             ( 70U )
#define CAN_70_MODULE_ID_RL78F2X_DEP_C                             ( 80U )

#define CAN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_DEP_C              ( 22U )
#define CAN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_DEP_C              ( 11U )
#define CAN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_DEP_C           (  0U )

#define CAN_70_SW_MAJOR_VERSION_RL78F2X_DEP_C                      (  1U )
#define CAN_70_SW_MINOR_VERSION_RL78F2X_DEP_C                      (  0U )
#define CAN_70_SW_PATCH_VERSION_RL78F2X_DEP_C                      (  0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Check if current file and Can.h header file are of the same Vendor ID */
#if (CAN_70_VENDOR_ID_RL78F2X_DEP_C    != CAN_VENDOR_ID)
    #error "VENDOR ID for Can_70_RL78F2X_Dep.c and Can.h are different"
#endif      /* End of Vendor Id Version check */

#if (CAN_70_MODULE_ID_RL78F2X_DEP_C    != CAN_MODULE_ID)
    #error "MODULE ID for Can_70_RL78F2X_Dep.c and Can.h are different"
#endif      /* End of Module Id Version check */

/* Check if current file and Can.h header file are of the same Software version */
#if ((CAN_70_SW_MAJOR_VERSION_RL78F2X_DEP_C    != CAN_SW_MAJOR_VERSION) ||\
     (CAN_70_SW_MINOR_VERSION_RL78F2X_DEP_C    != CAN_SW_MINOR_VERSION) ||\
     (CAN_70_SW_PATCH_VERSION_RL78F2X_DEP_C    != CAN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Can_70_RL78F2X_Dep.c and Can.h are different"
#endif      /* End of S/W Version check */

/* Check if current file and Can.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_DEP_C    != CAN_AR_RELEASE_MAJOR_VERSION) ||\
     (CAN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_DEP_C    != CAN_AR_RELEASE_MINOR_VERSION) ||\
     (CAN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_DEP_C != CAN_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Can_70_RL78F2X_Dep.c and Can.h are different"
#endif      /* End of Autosar Version check */

/*---------------Can_70_RL78F2X.h--------------------------------------------------*/

/* Check if current file and Can_70_RL78F2X.h header file are of the same Vendor ID */
#if (CAN_70_VENDOR_ID_RL78F2X_DEP_C    != CAN_70_VENDOR_ID_RL78F2X_H)
    #error "VENDOR ID for Can_70_RL78F2X_Dep.c and Can_70_RL78F2X.h are different"
#endif      /* End of Vendor Id Version check */

#if (CAN_70_MODULE_ID_RL78F2X_DEP_C    != CAN_70_MODULE_ID_RL78F2X_H)
    #error "MODULE ID for Can_70_RL78F2X_Dep.c and Can_70_RL78F2X.h are different"
#endif      /* End of Module Id Version check */

/* Check if current file and Can_70_RL78F2X.h header file are of the same Software version */
#if ((CAN_70_SW_MAJOR_VERSION_RL78F2X_DEP_C    != CAN_70_SW_MAJOR_VERSION_RL78F2X_H) ||\
     (CAN_70_SW_MINOR_VERSION_RL78F2X_DEP_C    != CAN_70_SW_MINOR_VERSION_RL78F2X_H) ||\
     (CAN_70_SW_PATCH_VERSION_RL78F2X_DEP_C    != CAN_70_SW_PATCH_VERSION_RL78F2X_H))
    #error "Software Version Numbers of Can_70_RL78F2X_Dep.c and Can_70_RL78F2X.h are different"
#endif      /* End of S/W Version check */

/* Check if current file and Can_70_RL78F2X.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_DEP_C    != CAN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H) ||\
     (CAN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_DEP_C    != CAN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H) ||\
     (CAN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_DEP_C != CAN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H))
    #error "AUTOSAR Version Numbers of Can_70_RL78F2X_Dep.c and Can_70_RL78F2X.h are different"
#endif      /* End of Autosar Version check */

/*---------------Can_70_RL78F2X_HwReg.h--------------------------------------------------*/

/* Check if current file and Can_70_RL78F2X_HwReg.h header file are of the same Vendor ID */
#if (CAN_70_VENDOR_ID_RL78F2X_DEP_C    != CAN_70_VENDOR_ID_RL78F2X_HWREG_H)
    #error "VENDOR ID for Can_70_RL78F2X_Dep.c and Can_70_RL78F2X_HwReg.h are different"
#endif      /* End of Vendor Id Version check */

#if (CAN_70_MODULE_ID_RL78F2X_DEP_C    != CAN_70_MODULE_ID_RL78F2X_HWREG_H)
    #error "MODULE ID for Can_70_RL78F2X_Dep.c and Can_70_RL78F2X_HwReg.h are different"
#endif      /* End of Module Id Version check */

/* Check if current file and Can_70_RL78F2X_HwReg.h header file are of the same Software version */
#if ((CAN_70_SW_MAJOR_VERSION_RL78F2X_DEP_C    != CAN_70_SW_MAJOR_VERSION_RL78F2X_HWREG_H) ||\
     (CAN_70_SW_MINOR_VERSION_RL78F2X_DEP_C    != CAN_70_SW_MINOR_VERSION_RL78F2X_HWREG_H) ||\
     (CAN_70_SW_PATCH_VERSION_RL78F2X_DEP_C    != CAN_70_SW_PATCH_VERSION_RL78F2X_HWREG_H))
    #error "Software Version Numbers of Can_70_RL78F2X_Dep.c and Can_70_RL78F2X_HwReg.h are different"
#endif      /* End of S/W Version check */

/* Check if current file and Can_70_RL78F2X_HwReg.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_DEP_C         != \
      CAN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_HWREG_H)  || \
     (CAN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_DEP_C         != \
      CAN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_HWREG_H)  || \
     (CAN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_DEP_C      != \
      CAN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_HWREG_H))
    #error "AUTOSAR Version Numbers of Can_70_RL78F2X_Dep.c and Can_70_RL78F2X_HwReg.h are different"
#endif      /* End of Autosar Version check */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/*---------------CanIf_Cbk.h--------------------------------------------------*/

/* Check if current file and CanIf_Cbk.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_DEP_C    != CANIF_70_AR_RELEASE_MAJOR_VERSION_CBK_H) ||\
     (CAN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_DEP_C    != CANIF_70_AR_RELEASE_MINOR_VERSION_CBK_H))
    #error "AUTOSAR Version Numbers of Can.c and CanIf_Cbk.h are different"
#endif      /* End of Autosar Version check */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/*---------------SchM_Can.h--------------------------------------------------*/

/* Check if current file and SchM_Can.h header file are of the same Autosar version */
#if ((CAN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_DEP_C    != RTE_AR_RELEASE_MAJOR_VERSION)   ||\
     (CAN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_DEP_C    != RTE_AR_RELEASE_MINOR_VERSION))
    #error "AUTOSAR Version Numbers of Can.c and SchM_Can.h are different"
#endif      /* End of Autosar Version check */
#endif /* #if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static functions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

#define CAN_START_SEC_CONST_8
#include "Can_MemMap.h"

const Can_70_InterruptBitAssignType Can_70_InterruptBitAssign[ CAN_70_NUM_OF_CAN_CHANNEL ] = {
    {
        { CAN_70_RL78F2X_INDEX_RCAN0GRVC,   CAN_70_RL78F2X_MASK_RCAN0GRVC },
        { CAN_70_RL78F2X_INDEX_RCAN0ERR ,   CAN_70_RL78F2X_MASK_RCAN0ERR  },
        { CAN_70_RL78F2X_INDEX_RCAN0WUP ,   CAN_70_RL78F2X_MASK_RCAN0WUP  },
        { CAN_70_RL78F2X_INDEX_RCAN0CFR ,   CAN_70_RL78F2X_MASK_RCAN0CFR  },
        { CAN_70_RL78F2X_INDEX_RCAN0TRM ,   CAN_70_RL78F2X_MASK_RCAN0TRM  },
        { CAN_70_RL78F2X_INDEX_RCAN0GRFR,   CAN_70_RL78F2X_MASK_RCAN0GRFR },
        { CAN_70_RL78F2X_INDEX_RCAN0GERR,   CAN_70_RL78F2X_MASK_RCAN0GERR },
        { CAN_70_RL78F2X_INDEX_CRAM     ,   CAN_70_RL78F2X_MASK_CRAM      }
    },
    {
        { CAN_70_RL78F2X_INDEX_RCAN1GRVC,   CAN_70_RL78F2X_MASK_RCAN1GRVC },
        { CAN_70_RL78F2X_INDEX_RCAN1ERR ,   CAN_70_RL78F2X_MASK_RCAN1ERR  },
        { CAN_70_RL78F2X_INDEX_RCAN1WUP ,   CAN_70_RL78F2X_MASK_RCAN1WUP  },
        { CAN_70_RL78F2X_INDEX_RCAN1CFR ,   CAN_70_RL78F2X_MASK_RCAN1CFR  },
        { CAN_70_RL78F2X_INDEX_RCAN1TRM ,   CAN_70_RL78F2X_MASK_RCAN1TRM  },
        { CAN_70_RL78F2X_INDEX_RCAN1GRFR,   CAN_70_RL78F2X_MASK_RCAN1GRFR },
        { CAN_70_RL78F2X_INDEX_RCAN1GERR,   CAN_70_RL78F2X_MASK_RCAN1GERR },
        { CAN_70_RL78F2X_INDEX_CRAM     ,   CAN_70_RL78F2X_MASK_CRAM      }
    }
};

#define CAN_STOP_SEC_CONST_8
#include "Can_MemMap.h"

#define CAN_START_SEC_CONST_UNSPECIFIED
#include "Can_MemMap.h"

/* Type:Array[pointer] / Alignment:UNSPECIFIED */
volatile const Can_70_RL78F2X_CanControllerRegInfoType Can_70_CanControllerRegInfo[ CAN_70_NUM_OF_CAN_CHANNEL ] = {
    {
        {
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFE0U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFE1U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFE2U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFE3U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFD0U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFD1U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFD2U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFD3U
        },
        {
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFE4U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFE5U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFE6U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFE7U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFD4U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFD5U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFD6U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFD7U
        },
        ( Can_70_RL78F2X_RegCommonBType QL_70_NEAR * )0x0310U,
        {
            ( Can_70_RL78F2X_RegCommonCType QL_70_NEAR * )0x033CU,
            ( Can_70_RL78F2X_RegCommonCType QL_70_NEAR * )0x0340U
        },
        ( Can_70_RL78F2X_RegCommonDType QL_70_NEAR * )0x0360U,
        ( Can_70_RL78F2X_RegCommonHType QL_70_NEAR * )0x03B0U,
        ( Can_70_RL78F2X_RegCommonIType QL_70_NEAR * )0x03D8U,
        {
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0420U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0430U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0440U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0450U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0460U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0470U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0480U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0490U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x04A0U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x04B0U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x04C0U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x04D0U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x04E0U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x04F0U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0500U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0510U
        },
        {
            ( Can_70_RL78F2X_RegPage1AType QL_70_NEAR  * )0x0420U,
            ( Can_70_RL78F2X_RegPage1AType QL_70_NEAR  * )0x046CU
        },
        {
            ( Can_70_RL78F2X_RegPage1BType QL_70_NEAR  * )0x042CU,
            ( Can_70_RL78F2X_RegPage1BType QL_70_NEAR  * )0x0478U
        },
        ( Can_70_RL78F2X_RegCfdecctlType QL_70_NEAR * )0x07C0U,
        {
            {
                ( Can_70_RL78F2X_RegCommonAType QL_70_NEAR * )0x0300U,
                ( Can_70_RL78F2X_RegCommonEType QL_70_NEAR * )0x0370U,
                ( Can_70_RL78F2X_RegCommonFType QL_70_NEAR * )0x0378U,
                ( Can_70_RL78F2X_RegCommonGType QL_70_NEAR * )0x0398U,
                ( Can_70_RL78F2X_RegCommonJType QL_70_NEAR * )0x0400U,
                {
                    ( Can_70_RL78F2X_RegPage1CType QL_70_NEAR * )0x0504U,
                    ( Can_70_RL78F2X_RegPage1CType QL_70_NEAR * )0x0550U,
                    ( Can_70_RL78F2X_RegPage1CType QL_70_NEAR * )0x059CU,
                    ( Can_70_RL78F2X_RegPage1CType QL_70_NEAR * )0x05E8U
                },
                {
                    ( Can_70_RL78F2X_RegPage1DType QL_70_NEAR * )0x0510U,
                    ( Can_70_RL78F2X_RegPage1DType QL_70_NEAR * )0x055CU,
                    ( Can_70_RL78F2X_RegPage1DType QL_70_NEAR * )0x05A8U,
                    ( Can_70_RL78F2X_RegPage1DType QL_70_NEAR * )0x05F4U
                },
                ( Can_70_RL78F2X_RegPage1EType QL_70_NEAR * )0x0640U
            }
        }
    },
    {
        {
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFE0U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFE1U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFE2U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFE3U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFD0U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFD1U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFD2U,
            ( Can_70_RL78F2X_RegIfxType QL_70_NEAR     * )0xFFD3U
        },
        {
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFE4U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFE5U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFE6U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFE7U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFD4U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFD5U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFD6U,
            ( Can_70_RL78F2X_RegMkxType QL_70_NEAR     * )0xFFD7U
        },
        ( Can_70_RL78F2X_RegCommonBType QL_70_NEAR * )0x0310U,
        {
            ( Can_70_RL78F2X_RegCommonCType QL_70_NEAR * )0x033CU,
            ( Can_70_RL78F2X_RegCommonCType QL_70_NEAR * )0x0340U
        },
        ( Can_70_RL78F2X_RegCommonDType QL_70_NEAR * )0x0360U,
        ( Can_70_RL78F2X_RegCommonHType QL_70_NEAR * )0x03B0U,
        ( Can_70_RL78F2X_RegCommonIType QL_70_NEAR * )0x03D8U,
        {
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0420U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0430U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0440U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0450U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0460U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0470U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0480U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0490U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x04A0U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x04B0U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x04C0U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x04D0U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x04E0U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x04F0U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0500U,
            ( Can_70_RL78F2X_RegPage0AType QL_70_NEAR  * )0x0510U
        },
        {
            ( Can_70_RL78F2X_RegPage1AType QL_70_NEAR  * )0x0420U,
            ( Can_70_RL78F2X_RegPage1AType QL_70_NEAR  * )0x046CU
        },
        {
            ( Can_70_RL78F2X_RegPage1BType QL_70_NEAR  * )0x042CU,
            ( Can_70_RL78F2X_RegPage1BType QL_70_NEAR  * )0x0478U
        },
        ( Can_70_RL78F2X_RegCfdecctlType QL_70_NEAR * )0x07C0U,
        {
            {
                ( Can_70_RL78F2X_RegCommonAType QL_70_NEAR * )0x0300U,
                ( Can_70_RL78F2X_RegCommonEType QL_70_NEAR * )0x0370U,
                ( Can_70_RL78F2X_RegCommonFType QL_70_NEAR * )0x0378U,
                ( Can_70_RL78F2X_RegCommonGType QL_70_NEAR * )0x0398U,
                ( Can_70_RL78F2X_RegCommonJType QL_70_NEAR * )0x0400U,
                {
                    ( Can_70_RL78F2X_RegPage1CType QL_70_NEAR * )0x0504U,
                    ( Can_70_RL78F2X_RegPage1CType QL_70_NEAR * )0x0550U,
                    ( Can_70_RL78F2X_RegPage1CType QL_70_NEAR * )0x059CU,
                    ( Can_70_RL78F2X_RegPage1CType QL_70_NEAR * )0x05E8U
                },
                {
                    ( Can_70_RL78F2X_RegPage1DType QL_70_NEAR * )0x0510U,
                    ( Can_70_RL78F2X_RegPage1DType QL_70_NEAR * )0x055CU,
                    ( Can_70_RL78F2X_RegPage1DType QL_70_NEAR * )0x05A8U,
                    ( Can_70_RL78F2X_RegPage1DType QL_70_NEAR * )0x05F4U
                },
                ( Can_70_RL78F2X_RegPage1EType QL_70_NEAR * )0x0640U
            }
        }
    }
};

#define CAN_STOP_SEC_CONST_UNSPECIFIED
#include "Can_MemMap.h"

/*----------------------------------------------------------------------------*/
/* function definitions and function style macros                             */
/*----------------------------------------------------------------------------*/

/* EOF Can_70_RL78F2X_Dep.c ***************************************************/