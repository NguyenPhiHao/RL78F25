/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Adc_70_Group.c                                               */
/* Version     : v1.00.00                                                     */
/* Contents    : ADC Module start/stop for group                              */
/*               The ADC is a basic software module at the service            */
/*               layer of the standardized basic software                     */
/*               architecture of AUTOSAR.                                     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of ADC Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Adc_70_Group.h"
#include "Adc_70_HW.h"
#include "SchM_Adc.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define ADC_70_VENDOR_ID_GROUP_C                   (70U)
#define ADC_70_MODULE_ID_GROUP_C                   (123U)

#define ADC_70_AR_RELEASE_MAJOR_VERSION_GROUP_C    (22U)
#define ADC_70_AR_RELEASE_MINOR_VERSION_GROUP_C    (11U)
#define ADC_70_AR_RELEASE_REVISION_VERSION_GROUP_C (0U)

#define ADC_70_SW_MAJOR_VERSION_GROUP_C            (1U)
#define ADC_70_SW_MINOR_VERSION_GROUP_C            (0U)
#define ADC_70_SW_PATCH_VERSION_GROUP_C            (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Adc_70_Group.h version check start */
#if ( ADC_70_VENDOR_ID_GROUP_C != ADC_70_VENDOR_ID_GROUP_H )
  #error "VENDOR ID for Adc_70_Group.c and Adc_70_Group.h are different"
#endif

#if ( ADC_70_MODULE_ID_GROUP_C != ADC_70_MODULE_ID_GROUP_H )
  #error "MODULE ID for Adc_70_Group.c and Adc_70_Group.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_GROUP_C    != ADC_70_AR_RELEASE_MAJOR_VERSION_GROUP_H    ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_GROUP_C    != ADC_70_AR_RELEASE_MINOR_VERSION_GROUP_H    ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_GROUP_C != ADC_70_AR_RELEASE_REVISION_VERSION_GROUP_H )    \
    )
  #error "AUTOSAR Version Numbers of Adc_70_Group.c and Adc_70_Group.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_GROUP_C != ADC_70_SW_MAJOR_VERSION_GROUP_H ) || \
      ( ADC_70_SW_MINOR_VERSION_GROUP_C != ADC_70_SW_MINOR_VERSION_GROUP_H ) || \
      ( ADC_70_SW_PATCH_VERSION_GROUP_C != ADC_70_SW_PATCH_VERSION_GROUP_H )    \
    )
  #error "Software Version Numbers of Adc_70_Group.c and Adc_70_Group.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_GROUP_C != ADC_70_SW_MAJOR_VERSION_GROUP_H ) || \
      ( ADC_70_SW_MINOR_VERSION_GROUP_C != ADC_70_SW_MINOR_VERSION_GROUP_H ) || \
      ( ADC_70_SW_PATCH_VERSION_GROUP_C != ADC_70_SW_PATCH_VERSION_GROUP_H )    \
    )
  #error "Software Version Numbers of Adc_70_Group.c and Adc_70_Group.h are different"
#endif
/* Adc_70_Group.h version check end */

/* Adc_70_Hw.h version check start */
#if ( ADC_70_VENDOR_ID_GROUP_C != ADC_70_VENDOR_ID_HW_H )
  #error "VENDOR ID for Adc_70_Group.c and Adc_70_Hw.h are different"
#endif

#if ( ADC_70_MODULE_ID_GROUP_C != ADC_70_MODULE_ID_HW_H )
  #error "MODULE ID for Adc_70_Group.c and Adc_70_Hw.h are different"
#endif

#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_GROUP_C    != ADC_70_AR_RELEASE_MAJOR_VERSION_HW_H    ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_GROUP_C    != ADC_70_AR_RELEASE_MINOR_VERSION_HW_H    ) || \
      ( ADC_70_AR_RELEASE_REVISION_VERSION_GROUP_C != ADC_70_AR_RELEASE_REVISION_VERSION_HW_H )    \
    )
  #error "AUTOSAR Version Numbers of Adc_70_Group.c and Adc_70_Hw.h are different"
#endif

#if ( ( ADC_70_SW_MAJOR_VERSION_GROUP_C != ADC_70_SW_MAJOR_VERSION_HW_H ) || \
      ( ADC_70_SW_MINOR_VERSION_GROUP_C != ADC_70_SW_MINOR_VERSION_HW_H ) || \
      ( ADC_70_SW_PATCH_VERSION_GROUP_C != ADC_70_SW_PATCH_VERSION_HW_H )    \
    )
  #error "Software Version Numbers of Adc_70_Group.c and Adc_70_Hw.h are different"
#endif
/* Adc_70_Hw.h version check end */

#if ( QINES_MCAL_VERSION_NO_CHECK != TRUE )
/* SchM_Adc.h version check start */
#if ( ( ADC_70_AR_RELEASE_MAJOR_VERSION_GROUP_C != RTE_AR_RELEASE_MAJOR_VERSION ) || \
      ( ADC_70_AR_RELEASE_MINOR_VERSION_GROUP_C != RTE_AR_RELEASE_MINOR_VERSION )    \
    )
  #error "AUTOSAR Version Numbers of Adc_70_Group.c and SchM_Adc.h are different"
#endif
/* SchM_Adc.h version check end */
#endif /* if ( QINES_MCAL_VERSION_NO_CHECK != TRUE ) */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

#define ADC_START_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

/******************************************************************************/
/* ModuleID   : ADC_MODULE_ID(123)                                            */
/* ServiceID  : --                                                            */
/* Name       : Adc_70_Group_StartConversion                                  */
/* Param      : (in) hwInfoPtr: pointer to HW unit information                */
/*            : (in) gpPtr     : pointer to group information                 */
/*            : (in) status    : status for setting to group                  */
/* Return     : None                                                          */
/* Contents    : start ADC conversion                                          */
/* Author     : k.sawada TamNA4                                               */
/* Note        : [SWS_Adc_00367]                                               */
/******************************************************************************/
void Adc_70_Group_StartConversion( Adc_70_HwInfoType*    hwInfoPtr,
                                   Adc_70_GroupInfoType* gpPtr,
                                   Adc_StatusType        status )
{
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_01();  /* disable interrupt */
    /* start ADC convert */
    hwInfoPtr->execGroup = gpPtr;            /* set running group */
    gpPtr->status       = status;            /* set group status */
    /* [SWS_Adc_00431][SWS_Adc_00432] When called from Adc_StartGroupConversion,
         it clears the information on the buffer pointer of the conversion result. */
    if ( ADC_BUSY == status ) {
        gpPtr->validSamples = 0U;            /* reset valid samples to zero */
        gpPtr->curSample    = 0U;            /* clear current index for sample */
        gpPtr->lastPtr      = NULL_PTR;      /* last pointer of group buffer */
    }
    /* [SWS_Adc_00061][SWS_Adc_00114] start ADC conversion */
    Adc_70_HW_StartConvert( gpPtr, gpPtr->groupDef );
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_01();   /* enable interrupt */
}

/******************************************************************************/
/* ModuleID   : ADC_MODULE_ID(123)                                            */
/* ServiceID  : --                                                            */
/* Name       : Adc_70_Group_StopConversion                                   */
/* Param      : (in) hwInfoPtr: pointer to HW unit information                */
/*            : (in) gpPtr     : pointer to group information                 */
/*            : (in) status    : status for setting to group                  */
/* Return     : None                                                          */
/* Contents    : stop ADC conversion                                           */
/* Author     : k.sawada TamNA4                                               */
/* Note        : [SWS_Adc_00368]                                               */
/******************************************************************************/
void Adc_70_Group_StopConversion( Adc_70_HwInfoType*    hwInfoPtr,
                                  Adc_70_GroupInfoType* gpPtr,
                                  Adc_StatusType        status )
{
    if ( gpPtr == hwInfoPtr->execGroup ) {
        /* stop ADC conversion when group is ongoing */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03();  /* disable interrupt */
        hwInfoPtr->execGroup = NULL_PTR;        /* clear running group */
        if ( ADC_TRIGG_SRC_HW == gpPtr->groupDef->AdcGroupTriggSrc ) {
            /* [SWS_Adc_00116] The function Adc_DisableHardwareTrigger shall disable
               the hardware trigger for the requested ADC Channel group. */
            Adc_70_HW_HwStopConvert( gpPtr, gpPtr->groupDef );  /* disable HW trigger */
        }
        else {
            /* [SWS_Adc_00385] Stop group conversion during conversion
               that is set in ONESHOT conversion mode and SW trigger mode.
               [SWS_Adc_00386] Stop group conversion during conversion
               set for CONTINUOUS conversion mode and SW trigger mode. */
            Adc_70_HW_StopConvert( gpPtr, gpPtr->groupDef );     /* Disable SW trigger */
        }
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03();   /* enable interrupt */
    }
    gpPtr->status = status;  /* [SWS_Adc_00360] set the group status to state ADC_IDLE. */
}

#define ADC_STOP_SEC_CODE_LOCAL
#include "Adc_MemMap.h"

/* EOF Adc_70_Group.c *********************************************************/
