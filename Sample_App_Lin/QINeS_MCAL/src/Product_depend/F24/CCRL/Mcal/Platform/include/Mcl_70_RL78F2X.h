/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Mcl_70_RL78F2X.h                                             */
/* Version     : v1.00.02                                                     */
/* Contents    : Macros to manipulate RL78F2X I/O controllers                 */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/

#ifndef MCL_70_RL78F2X_H_
#define MCL_70_RL78F2X_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "QINeS_Lite.h"

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define MCL_70_VENDOR_ID_RL78F2X_H (70U)
#define MCL_70_MODULE_ID_RL78F2X_H (0U)

#define MCL_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H (22U)
#define MCL_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H (11U)
#define MCL_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H (0U)

#define MCL_70_SW_MAJOR_VERSION_RL78F2X_H (1U)
#define MCL_70_SW_MINOR_VERSION_RL78F2X_H (0U)
#define MCL_70_SW_PATCH_VERSION_RL78F2X_H (0U)

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define MCL_70_HW_VERSION_RL78F2X_F24 (1U)
#define MCL_70_HW_VERSION_RL78F2X_F25 (2U)
#define MCL_70_HW_VERSION_RL78F2X MCL_70_HW_VERSION_RL78F2X_F25
/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/
/* Check if header file and Std types header file are of the same Autosar version */
#if ((MCL_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_70_AR_RELEASE_MINOR_VERSION_RL78F2X_H != STD_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_70_AR_RELEASE_REVISION_VERSION_RL78F2X_H != STD_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AUTOSAR Version Numbers of Mcl_70_RL78F2X.h and Std_Types.h are different"
#endif

/*----------------------------------------------------------------------------*/
/* common definitions                                                         */
/*----------------------------------------------------------------------------*/

/* types for I/O register */
typedef volatile uint32 QL_70_NEAR io32;
typedef volatile uint16 QL_70_NEAR io16;
typedef volatile uint8 QL_70_NEAR io8;

/* addres definitions for I/O register */
#define IO8(addr) ((io8 *)(addr))
#define IO16(addr) ((io16 *)(addr))
#define IO32(addr) ((io32 *)(addr))

/*----------------------------------------------------------------------------*/
/* for Mcu                                                                    */
/*----------------------------------------------------------------------------*/
#define MCL_70_RL78F2X_OSMC_REG (*(IO8(0x00F3U)))  /* OSMC */
#define MCL_70_RL78F2X_TPS0_REG (*(IO16(0x01B6U))) /* TPS0 */
#define MCL_70_RL78F2X_TPS1_REG (*(IO16(0x01F6U))) /* TPS1 */

#define MCL_70_RL78F2X_ECCIER_REG (*(IO8(0x0202U))) /* ECCIER */
#define MCL_70_RL78F2X_ECCER_REG (*(IO8(0x0203U)))  /* ECCER  */

#define MCL_70_RL78F2X_CANCKSEL_REG (*(IO8(0x02C2U))) /* CANCKSEL */
#define MCL_70_RL78F2X_LINCKSEL_REG (*(IO8(0x02C3U))) /* LINCKSEL */
#define MCL_70_RL78F2X_CKSEL_REG (*(IO8(0x02C4U)))    /* CKSEL */
#define MCL_70_RL78F2X_PLLCTL_REG (*(IO8(0x02C5U)))   /* PLLCTL */
#define MCL_70_RL78F2X_PLLSTS_REG (*(IO8(0x02C6U)))   /* PLLSTS */
#define MCL_70_RL78F2X_MDIV_REG (*(IO8(0x02C7U)))     /* MDIV */

#define MCL_70_RL78F2X_ADCKS_REG (*(IO8(0x00E0U))) /* ADCKS */

#define MCL_70_RL78F2X_PER0_REG (*(IO8(0x00F0U))) /* PER0 */
#define MCL_70_RL78F2X_PER1_REG (*(IO8(0x02C0U))) /* PER1 */
#define MCL_70_RL78F2X_PER2_REG (*(IO8(0x02C1U))) /* PER2 */

#define MCL_70_RL78F2X_CMC_REG (*(IO8(0xFFA0U)))  /* CMC */
#define MCL_70_RL78F2X_CSC_REG (*(IO8(0xFFA1U)))  /* CSC */
#define MCL_70_RL78F2X_OSTC_REG (*(IO8(0xFFA2U))) /* OSTC */
#define MCL_70_RL78F2X_OSTS_REG (*(IO8(0xFFA3U))) /* OSTS */
#define MCL_70_RL78F2X_CKC_REG (*(IO8(0xFFA4U)))  /* CKC */
#define MCL_70_RL78F2X_CKS0_REG (*(IO8(0xFFA5U))) /* CKS0 */
#define MCL_70_RL78F2X_WDTE_REG (*(IO8(0xFFABU))) /* WDTE */

#define MCL_70_RL78F2X_RESF_REG (*(IO8(0xFFA8U)))   /* RESF */
#define MCL_70_RL78F2X_POCRES_REG (*(IO8(0x02C9U))) /* POCRES */

/*----------------------------------------------------------------------------*/
/* for all timers                                                             */
/*----------------------------------------------------------------------------*/
#define MCL_70_CHANNEL_TICK_VALUE_MAX_16 (0xFFFFU) /* MAX Tick Value for 16bit timer (TAU/TRJ/TRD) */

/*----------------------------------------------------------------------------*/
/* for TAU                                                                    */
/*----------------------------------------------------------------------------*/

/* continuous address registers */
typedef struct
{
    volatile uint16 regTcr;    /* 0x0000 : TCRmn   */
    volatile uint16 dummy1[7]; /* 0x0001 - 0x000F  */
    volatile uint16 regTmr;    /* 0x0010 : TMRmn   */
    volatile uint16 dummy2[7]; /* 0x0011 - 0x001F  */
    volatile uint16 regTsr;    /* 0x0020 : TSRmn   */
} Mcl_70_RL78F2X_TAU_ContRegType;

/* fixed address registers */
typedef struct
{
    volatile uint16 regTe;  /* 0x0000 : TEm      */
    volatile uint16 regTs;  /* 0x0002 : TSm      */
    volatile uint16 regTt;  /* 0x0004 : TTm      */
    volatile uint16 dummy;  /* 0x0006 - 0x0007   */
    volatile uint16 regTo;  /* 0x0008 : TOm      */
    volatile uint16 regToe; /* 0x000A : TOEm     */
    volatile uint16 regTol; /* 0x000C : TOLm     */
    volatile uint16 regTom; /* 0x000E : TOMm     */
} Mcl_70_RL78F2X_TAU_FixRegType;

/* top address of TAU continuous address registers */
#define MCL_70_RL78F2X_TAU_TAU00_CONT_ADR (IO16(0x0180U)) /* TAU Unit0 Ch0 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU01_CONT_ADR (IO16(0x0182U)) /* TAU Unit0 Ch1 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU02_CONT_ADR (IO16(0x0184U)) /* TAU Unit0 Ch2 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU03_CONT_ADR (IO16(0x0186U)) /* TAU Unit0 Ch3 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU04_CONT_ADR (IO16(0x0188U)) /* TAU Unit0 Ch4 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU05_CONT_ADR (IO16(0x018AU)) /* TAU Unit0 Ch5 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU06_CONT_ADR (IO16(0x018CU)) /* TAU Unit0 Ch6 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU07_CONT_ADR (IO16(0x018EU)) /* TAU Unit0 Ch7 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU10_CONT_ADR (IO16(0x01c0U)) /* TAU Unit1 Ch0 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU11_CONT_ADR (IO16(0x01c2U)) /* TAU Unit1 Ch1 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU12_CONT_ADR (IO16(0x01c4U)) /* TAU Unit1 Ch2 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU13_CONT_ADR (IO16(0x01c6U)) /* TAU Unit1 Ch3 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU14_CONT_ADR (IO16(0x01c8U)) /* TAU Unit1 Ch4 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU15_CONT_ADR (IO16(0x01cAU)) /* TAU Unit1 Ch5 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU16_CONT_ADR (IO16(0x01cCU)) /* TAU Unit1 Ch6 TCRmn */
#define MCL_70_RL78F2X_TAU_TAU17_CONT_ADR (IO16(0x01cEU)) /* TAU Unit1 Ch7 TCRmn */

/* top address of TAU fixed address registers */
#define MCL_70_RL78F2X_TAU_TAU0_FIX_ADR (IO16(0x01B0U)) /* TAU Unit0 TEm */
#define MCL_70_RL78F2X_TAU_TAU1_FIX_ADR (IO16(0x01F0U)) /* TAU Unit1 TEm */

/* for TAU Unit 0 */
/* address of TDR register */
#define MCL_70_RL78F2X_TAU_TDR00_ADR (IO16(0xFF18U)) /* TAU Unit0 Ch0 TDR */
#define MCL_70_RL78F2X_TAU_TDR01_ADR (IO16(0xFF1aU)) /* TAU Unit0 Ch1 TDR */
#define MCL_70_RL78F2X_TAU_TDR02_ADR (IO16(0xFF74U)) /* TAU Unit0 Ch2 TDR */
#define MCL_70_RL78F2X_TAU_TDR03_ADR (IO16(0xFF76U)) /* TAU Unit0 Ch3 TDR */
#define MCL_70_RL78F2X_TAU_TDR04_ADR (IO16(0xFF78U)) /* TAU Unit0 Ch4 TDR */
#define MCL_70_RL78F2X_TAU_TDR05_ADR (IO16(0xFF7AU)) /* TAU Unit0 Ch5 TDR */
#define MCL_70_RL78F2X_TAU_TDR06_ADR (IO16(0xFF7CU)) /* TAU Unit0 Ch6 TDR */
#define MCL_70_RL78F2X_TAU_TDR07_ADR (IO16(0xFF7EU)) /* TAU Unit0 Ch7 TDR */

#define MCL_70_RL78F2X_TAU_NFEN1_ADR (IO8(0x0071U)) /* TAU0 NFEN1 */

#define MCL_70_RL78F2X_TIS0_REG (*(IO8(0x0074U))) /* TIS0 */

/* for TAU Unit 1 */
/* address of TDR register */
#define MCL_70_RL78F2X_TAU_TDR10_ADR (IO16(0xFF80U)) /* TAU Unit1 Ch0 TDR */
#define MCL_70_RL78F2X_TAU_TDR11_ADR (IO16(0xFF82U)) /* TAU Unit1 Ch1 TDR */
#define MCL_70_RL78F2X_TAU_TDR12_ADR (IO16(0xFF84U)) /* TAU Unit1 Ch2 TDR */
#define MCL_70_RL78F2X_TAU_TDR13_ADR (IO16(0xFF86U)) /* TAU Unit1 Ch3 TDR */
#define MCL_70_RL78F2X_TAU_TDR14_ADR (IO16(0xFF88U)) /* TAU Unit1 Ch4 TDR */
#define MCL_70_RL78F2X_TAU_TDR15_ADR (IO16(0xFF8AU)) /* TAU Unit1 Ch5 TDR */
#define MCL_70_RL78F2X_TAU_TDR16_ADR (IO16(0xFF8CU)) /* TAU Unit1 Ch6 TDR */
#define MCL_70_RL78F2X_TAU_TDR17_ADR (IO16(0xFF8EU)) /* TAU Unit1 Ch7 TDR */

#define MCL_70_RL78F2X_TAU_NFEN2_ADR (IO8(0x0072U)) /* TAU1 NFEN2 */

/* for select TAU Unit with UTSEL */
#define MCL_70_RL78F2X_TAU_UTSEL_ADR (*(IO8(0x01F0U)))  /* UTSEL */
#define MCL_70_RL78F2X_TAU_UTSEL_TSEL0_1 ((uint8)0x01U) /* select Unit1 */

/* for TAU Unit 0/1 */
/* data for TMR register */
#define MCL_70_RL78F2X_TAU_TMR_CK0 ((uint16)0x0000U)  /* select CKm0 */
#define MCL_70_RL78F2X_TAU_TMR_CK1 ((uint16)0x8000U)  /* select CKm1 */
#define MCL_70_RL78F2X_TAU_TMR_CK2 ((uint16)0x4000U)  /* select CKm2 */
#define MCL_70_RL78F2X_TAU_TMR_CK3 ((uint16)0xC000U)  /* select CKm3 */
#define MCL_70_RL78F2X_TAU_TMR_INIT ((uint16)0x0000U) /* default value */

#define MCL_70_RL78F2X_TAU_TMR_CCS0 ((uint16)0x0000U) /* select CCS = 0 */
#define MCL_70_RL78F2X_TAU_TMR_CCS1 ((uint16)0x1000U) /* select CCS = 1 */

#define MCL_70_RL78F2X_TAU_TMR_STS0 ((uint16)0x0000U) /* select STS(STSmn0 = 0,STSmn1=0,STSmn2=0) */
#define MCL_70_RL78F2X_TAU_TMR_STS1 ((uint16)0x0100U) /* select STS(STSmn0 = 1,STSmn1=0,STSmn2=0) */
#define MCL_70_RL78F2X_TAU_TMR_STS2 ((uint16)0x0200U) /* select STS(STSmn0 = 0,STSmn1=1,STSmn2=0) */
#define MCL_70_RL78F2X_TAU_TMR_STS3 ((uint16)0x0400U) /* select STS(STSmn0 = 0,STSmn1=0,STSmn2=1) */

#define MCL_70_RL78F2X_TAU_TMR_CIS0 ((uint16)0x0000U) /* select CIS(CISmn0 = 0,CISmn1=0) */
#define MCL_70_RL78F2X_TAU_TMR_CIS1 ((uint16)0x0040U) /* select CIS(CISmn0 = 0,CISmn1=0) */
#define MCL_70_RL78F2X_TAU_TMR_CIS2 ((uint16)0x0080U) /* select CIS(CISmn0 = 0,CISmn1=0) */
#define MCL_70_RL78F2X_TAU_TMR_CIS3 ((uint16)0x00C0U) /* select CIS(CISmn0 = 0,CISmn1=0) */

#define MCL_70_RL78F2X_TAU_TMR_MD0 ((uint16)0x0001U) /* select MDmn0 */

#define MCL_70_RL78F2X_TAU_TMR_MD1_3_0 ((uint16)0x0000U) /* interval timer mode */
#define MCL_70_RL78F2X_TAU_TMR_MD1_3_1 ((uint16)0x0004U) /* capture mode */
#define MCL_70_RL78F2X_TAU_TMR_MD1_3_2 ((uint16)0x0006U) /* event counter mode */
#define MCL_70_RL78F2X_TAU_TMR_MD1_3_3 ((uint16)0x0008U) /* one count mode */
#define MCL_70_RL78F2X_TAU_TMR_MD1_3_4 ((uint16)0x000CU) /* capture & one count mode */

/* data for TS register */
#define MCL_70_RL78F2X_TAU_TS_TS0 ((uint16)0x0001U)     /* start Ch0 */
#define MCL_70_RL78F2X_TAU_TS_TS1 ((uint16)0x0002U)     /* start Ch1 */
#define MCL_70_RL78F2X_TAU_TS_TS2 ((uint16)0x0004U)     /* start Ch2 */
#define MCL_70_RL78F2X_TAU_TS_TS3 ((uint16)0x0008U)     /* start Ch3 */
#define MCL_70_RL78F2X_TAU_TS_TS4 ((uint16)0x0010U)     /* start Ch4 */
#define MCL_70_RL78F2X_TAU_TS_TS5 ((uint16)0x0020U)     /* start Ch5 */
#define MCL_70_RL78F2X_TAU_TS_TS6 ((uint16)0x0040U)     /* start Ch6 */
#define MCL_70_RL78F2X_TAU_TS_TS7 ((uint16)0x0080U)     /* start Ch7 */
#define MCL_70_RL78F2X_TAU_TS_TS_MASK ((uint16)0x0001U) /* TSm bit mask */

/* data for TT register */
#define MCL_70_RL78F2X_TAU_TT_TT0 ((uint16)0x0001U)     /* stop Ch0 */
#define MCL_70_RL78F2X_TAU_TT_TT1 ((uint16)0x0002U)     /* stop Ch1 */
#define MCL_70_RL78F2X_TAU_TT_TT2 ((uint16)0x0004U)     /* stop Ch2 */
#define MCL_70_RL78F2X_TAU_TT_TT3 ((uint16)0x0008U)     /* stop Ch3 */
#define MCL_70_RL78F2X_TAU_TT_TT4 ((uint16)0x0010U)     /* stop Ch4 */
#define MCL_70_RL78F2X_TAU_TT_TT5 ((uint16)0x0020U)     /* stop Ch5 */
#define MCL_70_RL78F2X_TAU_TT_TT6 ((uint16)0x0040U)     /* stop Ch6 */
#define MCL_70_RL78F2X_TAU_TT_TT7 ((uint16)0x0080U)     /* stop Ch7 */
#define MCL_70_RL78F2X_TAU_TT_TT_MASK ((uint16)0x0001U) /* TTm bit mask */

/* data for TCR register */
#define MCL_70_RL78F2X_TAU_TCR_INIT ((uint16)0xFFFFU) /* default value */

/* data for TDR register */
#define MCL_70_RL78F2X_TAU_TDR_INIT ((uint16)0x0000U) /* default value */

/* data for TIS0 register */
#define MCL_70_RL78F2X_TIS0_TIS07 ((uint8)0x80U)
#define MCL_70_RL78F2X_TIS0_TIS06 ((uint8)0x40U)
#define MCL_70_RL78F2X_TIS0_TIS04 ((uint8)0x10U)
#define MCL_70_RL78F2X_TIS0_TIS02 ((uint8)0x04U)
#define MCL_70_RL78F2X_TIS0_TIS01 ((uint8)0x02U)
#define MCL_70_RL78F2X_TIS0_TIS00 ((uint8)0x01U)
#define MCL_70_RL78F2X_TIS0_INIT ((uint8)0x00U) /* default value */

/*----------------------------------------------------------------------------*/
/* for TRJ                                                                    */
/*----------------------------------------------------------------------------*/

/* continuous address registers */
typedef struct
{
    volatile uint8 regTrjCr;  /* 0x0000 : TRJCRx  */
    volatile uint8 regTrjIoc; /* 0x0001 : TRJIOCx */
    volatile uint8 regTrjMr;  /* 0x0002 : TRJMRx  */
    volatile uint8 regTrjSr;  /* 0x0003 : TRJSRx  */
} Mcl_70_RL78F2X_TRJ_ContRegType;

/* top address of TRJ continuous address registers */
#define MCL_70_RL78F2X_TRJ_TRJ00_CONT_ADR (IO8(0x0240U)) /* TRJ Unit0 Ch0 TRJCR */

/* address of TRJ register */
#define MCL_70_RL78F2X_TRJ_TRJ00_ADR (IO16(0x06F0U)) /* TRJ Unit0 Ch0 TRJ */

/* data for TRJMR register */
#define MCL_70_RL78F2X_TRJ_TRJMR_TCK_FCLK ((uint8)0x00U)  /* TRJ TRJMR select fCLK */
#define MCL_70_RL78F2X_TRJ_TRJMR_TCK_FCLK8 ((uint8)0x10U) /* TRJ TRJMR select fCLK/8 */
#define MCL_70_RL78F2X_TRJ_TRJMR_TCK_FCLK2 ((uint8)0x30U) /* TRJ TRJMR select fCLK/2 */
#define MCL_70_RL78F2X_TRJ_TRJMR_TCK_FIL ((uint8)0x40U)   /* TRJ TRJMR select fIL */
#define MCL_70_RL78F2X_TRJ_TRJMR_TCK_ECL ((uint8)0x50U)   /* TRJ TRJMR select ECL event */
#define MCL_70_RL78F2X_TRJ_TRJMR_TCK_FSL ((uint8)0x60U)   /* TRJ TRJMR select fSL */
#define MCL_70_RL78F2X_TRJ_TRJMR_INIT ((uint8)0x00U)      /* default value */

/* data for TRJCR register */
#define MCL_70_RL78F2X_TRJ_TRJCR_TSTART ((uint8)0x01U) /* Set TSTART bit */
#define MCL_70_RL78F2X_TRJ_TRJCR_TCSTF ((uint8)0x02U)  /* Check TCSTF flag */
#define MCL_70_RL78F2X_TRJ_TRJCR_INIT ((uint8)0x00U)   /* default value */

/* data for TRJ register */
#define MCL_70_RL78F2X_TRJ_TRJ_INIT ((uint16)0xFFFFU) /* default value */

/*----------------------------------------------------------------------------*/
/* for TRD                                                                    */
/*----------------------------------------------------------------------------*/

/* continuous address registers */
typedef struct
{
    volatile uint8 regTrdCr;   /* 0x0000 : TRDCRi */
    volatile uint8 regTrdIora; /* 0x0001 : TRDIORAi (no use) */
    volatile uint8 regTrdIorc; /* 0x0002 : TRDIORCi (no use) */
    volatile uint8 regTrdSr;   /* 0x0003 : TRDSRi (no use) */
    volatile uint8 regTrdIer;  /* 0x0004 : TRDIERi (no use) */
    volatile uint8 regTrdPocr; /* 0x0005 : TRDPOCRi (no use) */
    volatile uint16 regTrd;    /* 0x0006 : TRDi */
    volatile uint16 regTrdGra; /* 0x0008 : TRDGRAi */
    volatile uint16 regTrdGrb; /* 0x000A : TRDGRBi (no use) */
    volatile uint16 regTrdGrc; /* 0x0008 : TRDGRAi */
    volatile uint16 regTrdGrd; /* 0x000A : TRDGRBi (no use) */
} Mcl_70_RL78F2X_TRD_ContRegType;

/* fixed address registers */
typedef struct
{
    volatile uint8 regTrdElc;  /* 0x0000 : TRDELC (no use) */
    volatile uint8 dummy[2];   /* 0x0001 - 0x0002 */
    volatile uint8 regTrdStr;  /* 0x0003 : TRDSTR */
    volatile uint8 regTrdMr;   /* 0x0004 : TRDMR */
    volatile uint8 regTrdPmr;  /* 0x0005 : TRDPMR (no use) */
    volatile uint8 regTrdFcr;  /* 0x0006 : TRDFCR */
    volatile uint8 regTrdOer1; /* 0x0007 : TRDOER1 (no use) */
    volatile uint8 regTrdOer2; /* 0x0008 : TRDOER2 (no use) */
    volatile uint8 regTrdOcr;  /* 0x0009 : TRDOCR (no use) */
} Mcl_70_RL78F2X_TRD_FixRegType;

/* top address of TRD continuous address registers */
#define MCL_70_RL78F2X_TRD_TRD00_CONT_ADR (IO16(0x0260U)) /* TRD Unit0 TRDCR0 */
#define MCL_70_RL78F2X_TRD_TRD01_CONT_ADR (IO16(0x0270U)) /* TRD Unit0 TRDCR1 */

/* top address of TRD fixed address registers */
#define MCL_70_RL78F2X_TRD_TRD0_FIX_ADR (IO16(0x0250U)) /* TRD Unit0 TRDELC */

#define MCL_70_RL78F2X_TRD_TRDDF0_ADR (IO8(0x025AU)) /* TRD0 TRDDF0 */
#define MCL_70_RL78F2X_TRD_TRDDF1_ADR (IO8(0x025BU)) /* TRD1 TRDDF1 */

/* data for TRDFCR register */
#define MCL_70_RL78F2X_TRD_TRDFCR_VAL ((uint8)0x80U)  /* TRD Unit0 TRDFCR PWM3=1, other bits = 0 */
#define MCL_70_RL78F2X_TRD_TRDFCR_INIT ((uint8)0x80U) /* default value */

/* data for TRDMR register */
#define MCL_70_RL78F2X_TRD_TRDMR_TRDBFCD_MASK ((uint8)0x30U) /* TRD Unit0 TRDMR TRDMFDi, TRDBFCi bit */
#define MCL_70_RL78F2X_TRD_TRDMR_TRDSYNC_MASK ((uint8)0x01U) /* TRD Unit0 TRDMR TRDSYNC bit (this bit has no shift) */
#define MCL_70_RL78F2X_TRD_TRDMR_INIT ((uint8)0x00U)         /* default value */

/* data for TRDCR register */
#define MCL_70_RL78F2X_TRD_TRDCR_TCK_FTRD ((uint8)0x20U)   /* TRDCR select fTRD */
#define MCL_70_RL78F2X_TRD_TRDCR_TCK_FTRD2 ((uint8)0x21U)  /* TRDCR select fTRD/2 */
#define MCL_70_RL78F2X_TRD_TRDCR_TCK_FTRD4 ((uint8)0x22U)  /* TRDCR select fTRD/4 */
#define MCL_70_RL78F2X_TRD_TRDCR_TCK_FTRD8 ((uint8)0x23U)  /* TRDCR select fTRD/8 */
#define MCL_70_RL78F2X_TRD_TRDCR_TCK_FTRD32 ((uint8)0x24U) /* TRDCR select fTRD/32 */
#define MCL_70_RL78F2X_TRD_TRDCR_TCK_TRDCLK ((uint8)0x25U) /* TRDCR select TRDCLK */
#define MCL_70_RL78F2X_TRD_TRDCR_INIT ((uint8)0x00U)       /* default value */

/* data for TRDSTR register */
#define MCL_70_RL78F2X_TRD_TRDSTR_CSEL_MASK ((uint8)0x04U)   /* TRD Unit0 TRDSTR CSELi bit mask */
#define MCL_70_RL78F2X_TRD_TRDSTR_TSTART_MASK ((uint8)0x01U) /* TRD Unit0 TRDSTR TSTARTi bit mask */
#define MCL_70_RL78F2X_TRD_TRDSTR_INIT ((uint8)0x0CU)        /* default value */

/* data for TRDSRi register */
#define MCL_70_RL78F2X_TRD_TRDSR_IMFA_MASK ((uint8)0x01U) /* IMFA bit mask */
#define MCL_70_RL78F2X_TRD_TRDSR_INIT ((uint8)0x00U)      /* default value */

/* data for TRDIERi register */
#define MCL_70_RL78F2X_TRD_TRDIER_IMIEA_MASK ((uint8)0x01U) /* IMIEA bit mask */
#define MCL_70_RL78F2X_TRD_TRDIER_INIT ((uint8)0x00U)       /* default value */

/* data for TRDi register */
#define MCL_70_RL78F2X_TRD_TRD_INIT ((uint16)0x0000U) /* default value */

/* data for TRDGRAi register */
#define MCL_70_RL78F2X_TRD_TRDGRA_INIT ((uint16)0xFFFFU) /* default value */

/*----------------------------------------------------------------------------*/
/* for Port                                                                   */
/*----------------------------------------------------------------------------*/
/* Port register address */
#define PORT_70_RL78F2X_P_ADR (0xff00U)
#define PORT_70_RL78F2X_PITHL_ADR (0x0020U)
#define PORT_70_RL78F2X_PU_ADR (0x0030U)
#define PORT_70_RL78F2X_PIM_ADR (0x0040U)
#define PORT_70_RL78F2X_POM_ADR (0x0050U)
#define PORT_70_RL78F2X_PMC_ADR (0x0060U)
#define PORT_70_RL78F2X_PM_ADR (0xff20U)
#define PORT_70_RL78F2X_PMS_ADR (0x0077U)
#define PORT_70_RL78F2X_PSRSEL_ADR (0x0220U)

/* PIORx register address */
#define PORT_70_RL78F2X_PIOR00_ADR (0x0016U)
#define PORT_70_RL78F2X_PIOR01_ADR (0x0017U)
#define PORT_70_RL78F2X_PIOR02_ADR (0x0018U)
#define PORT_70_RL78F2X_PIOR03_ADR (0x0019U)
#define PORT_70_RL78F2X_PIOR04_ADR (0x001AU)
#define PORT_70_RL78F2X_PIOR05_ADR (0x001BU)
#define PORT_70_RL78F2X_PIOR06_ADR (0x001CU)
#define PORT_70_RL78F2X_PIOR07_ADR (0x001DU)
#define PORT_70_RL78F2X_PIOR08_ADR (0x001EU)

/* Port control register address */
#define PORT_70_RL78F2X_Px(i) (PORT_70_RL78F2X_P_ADR + (0x01U * (i)))
#define PORT_70_RL78F2X_PMx(i) (PORT_70_RL78F2X_PM_ADR + (0x01U * (i)))

/* Defined for DIO. Because of using the size of "Dio_PortType" for abstraction */
#define PORT_70_RL78F2X_DIO_Px(i) (PORT_70_RL78F2X_P_ADR + ((uint16)(sizeof(Dio_PortType)) * (i)))

/*----------------------------------------------------------------------------*/
/* for Interrupt                                                              */
/*----------------------------------------------------------------------------*/
#define MCL_70_RL78F2X_INT_INTMSK_ADR (IO8(0x007CU)) /* Interrupt Mask Register */
#define MCL_70_RL78F2X_INT_EGP0_ADR (IO8(0xFF38U))   /* Interrupt EGP0 Register */
#define MCL_70_RL78F2X_INT_EGN0_ADR (IO8(0xFF39U))   /* Interrupt EGN0 Register */
#define MCL_70_RL78F2X_INT_EGP1_ADR (IO8(0xFF3AU))   /* Interrupt EGP1 Register */
#define MCL_70_RL78F2X_INT_EGN1_ADR (IO8(0xFF3BU))   /* Interrupt EGN1 Register */

/*----------------------------------------------------------------------------*/
/* for ELC                                                                    */
/*----------------------------------------------------------------------------*/
typedef struct
{
    volatile uint8 regElselr[26]; /* 0x0000 - 0x0025 */
} Mcl_70_RL78F2X_ELC_FixRegType;

/* top address of ELC fixed address registers */
#define MCL_70_RL78F2X_ELC_FIX_ADR (IO8(0x0780U)) /* ELC ELSELR00 */

/* index of ELC ELSELR** registers */
#define MCL_70_RL78F2X_ELC_ELSELR_INTP0 (0U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTP1 (1U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTP2 (2U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTP3 (3U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTP4 (4U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTP5 (5U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTKR (6U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTRTC (7U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTRD0A (8U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTRD0B (9U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTRD1A (10U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTRD1B (11U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTRDUF (12U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTRJ0 (13U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTM00 (14U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTM01 (15U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTM02 (16U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTM03 (17U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTM04 (18U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTCMP0 (19U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTM05 (20U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTM06 (21U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTM07 (22U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTM10 (23U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTM11 (24U)
#define MCL_70_RL78F2X_ELC_ELSELR_INTTM12 (25U)
/* number of ELC ELSELR** registers */
#define MCL_70_RL78F2X_ELC_ELSELR_NUM (26U)

/* bit field of ELC ELSELR** registers */
#define MCL_70_RL78F2X_ELC_ELSELR_NONE (0x00U)
#define MCL_70_RL78F2X_ELC_ELSELR_ADC (0x01U)
#define MCL_70_RL78F2X_ELC_ELSELR_TAU00 (0x02U)
#define MCL_70_RL78F2X_ELC_ELSELR_TAU01 (0x03U)
#define MCL_70_RL78F2X_ELC_ELSELR_TRJ0 (0x04U)
#define MCL_70_RL78F2X_ELC_ELSELR_TRD0 (0x05U)
#define MCL_70_RL78F2X_ELC_ELSELR_TRD1 (0x06U)
#define MCL_70_RL78F2X_ELC_ELSELR_DA0 (0x07U)
#define MCL_70_RL78F2X_ELC_ELSELR_TAU02 (0x08U)
#define MCL_70_RL78F2X_ELC_ELSELR_TAU03 (0x09U)

/*----------------------------------------------------------------------------*/
/* function prototype declarations for IAR Built-in Function                  */
/*----------------------------------------------------------------------------*/
extern void __halt(void);
extern void __stop(void);
extern void QL_70_NEAR __set1(uint8 QL_70_NEAR *X, uint8 Y);
extern void QL_70_NEAR __clr1(uint8 QL_70_NEAR *X, uint8 Y);
extern void QL_70_NEAR __not1(uint8 QL_70_NEAR *X, uint8 Y);

#endif /* #ifndef MCL_70_RL78F2X_H_ */

/* EOF MCL_70_RL78F2X.h *******************************************************/
