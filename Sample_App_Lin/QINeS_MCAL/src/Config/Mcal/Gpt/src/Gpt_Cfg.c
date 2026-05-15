/*----------------------------------------------------------------------------*/
/* Copyright    : 2023 SCSK Corporation                                       */
/* System Name   : AUTOSAR QInEs-Lite MCAL                                    */
/* File Name     : Gpt_Cfg.c                                                  */
/* Version       : v1.00.00                                                   */
/* Contents      : Gpt precompile time configuration                          */
/* Author        : k.sawada TranNP1                                           */
/* Note          : --                                                         */
/*----------------------------------------------------------------------------*/
/* Specification of GPT Driver                                                */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Gpt_Cfg.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define GPT_70_VENDOR_ID_CFG_C                     (70U)
#define GPT_70_MODULE_ID_CFG_C                     (100U)

#define GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_C      (22U)
#define GPT_70_AR_RELEASE_MINOR_VERSION_CFG_C      (11U)
#define GPT_70_AR_RELEASE_REVISION_VERSION_CFG_C   (0U)

#define GPT_70_SW_MAJOR_VERSION_CFG_C              (1U)
#define GPT_70_SW_MINOR_VERSION_CFG_C              (0U)
#define GPT_70_SW_PATCH_VERSION_CFG_C              (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Gpt_Cfg.h version check start */
#if ( GPT_70_VENDOR_ID_CFG_C != GPT_70_VENDOR_ID_CFG_H )
    #error "VENDOR ID for Gpt_Cfg.c and Gpt_Cfg.h are different"
#endif

#if ( GPT_70_MODULE_ID_CFG_C != GPT_70_MODULE_ID_CFG_H )
    #error "MODULE ID for Gpt_Cfg.c and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_C    != GPT_70_AR_RELEASE_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_AR_RELEASE_MINOR_VERSION_CFG_C    != GPT_70_AR_RELEASE_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_AR_RELEASE_REVISION_VERSION_CFG_C != GPT_70_AR_RELEASE_REVISION_VERSION_CFG_H ) )
    #error "AUTOSAR Version Numbers of Gpt_Cfg.c and Gpt_Cfg.h are different"
#endif

#if ( ( GPT_70_SW_MAJOR_VERSION_CFG_C != GPT_70_SW_MAJOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_MINOR_VERSION_CFG_C != GPT_70_SW_MINOR_VERSION_CFG_H ) || \
      ( GPT_70_SW_PATCH_VERSION_CFG_C != GPT_70_SW_PATCH_VERSION_CFG_H ) )
    #error "Software Version Numbers of Gpt_Cfg.c and Gpt_Cfg.h are different"
#endif

/* Gpt_Cfg.h version check end */

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------*/
/* variable                                                               */
/*------------------------------------------------------------------------*/

/* EOF Gpt_Cfg.c *********************************************************/
