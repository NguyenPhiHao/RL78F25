/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Spi_70_RL78F2X_HwReg.h                                       */
/* Version     : v1.00.01                                                     */
/* Contents    : SPI module Hardware register definition header file          */
/*               The SPI Handler/Driver provides services for reading         */
/*               from and writing to devices connected via SPI busses         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of SPI Handler/Driver                                        */
/* R22-11                                                                     */
/******************************************************************************/
#ifndef SPI_70_RL78F2X_HWREG_H_
#define SPI_70_RL78F2X_HWREG_H_

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* hardware information                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define SPI_70_VENDOR_ID_RL78F2X_HWREG_H           (70U)
#define SPI_70_MODULE_ID_RL78F2X_HWREG_H           (83U)

#define SPI_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_HWREG_H    (22U)
#define SPI_70_AR_RELEASE_MINOR_VERSION_RL78F2X_HWREG_H    (11U)
#define SPI_70_AR_RELEASE_REVISION_VERSION_RL78F2X_HWREG_H (0U)

#define SPI_70_SW_MAJOR_VERSION_RL78F2X_HWREG_H    (1U)
#define SPI_70_SW_MINOR_VERSION_RL78F2X_HWREG_H    (0U)
#define SPI_70_SW_PATCH_VERSION_RL78F2X_HWREG_H    (0U)

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* SPSm */
#define SPI_70_RL78F2X_SPS_PRS_MASK    ( 0x00FU )
#define SPI_70_RL78F2X_SPS_PRS_BITPOS  ( 0U )
#define SPI_70_RL78F2X_SPS_PRS_SIZE    ( 4U )
#define SPI_70_RL78F2X_SPS_PRS         ( SPI_70_RL78F2X_SPS_PRS_MASK << SPI_70_RL78F2X_SPS_PRS_BITPOS )

/* SCRmn */
#define SPI_70_RL78F2X_SCR_CKP_MASK    ( (uint16)0x0001U )
#define SPI_70_RL78F2X_SCR_DAP_MASK    ( (uint16)0x0001U )
#define SPI_70_RL78F2X_SCR_DIR_MASK    ( (uint16)0x0001U )
#define SPI_70_RL78F2X_SCR_DLS_MASK    ( (uint16)0x000FU )

#define SPI_70_RL78F2X_SCR_CKP_BITPOS  ( 12U )
#define SPI_70_RL78F2X_SCR_DAP_BITPOS  ( 13U )
#define SPI_70_RL78F2X_SCR_DIR_BITPOS  (  7U )
#define SPI_70_RL78F2X_SCR_DLS_BITPOS  (  0U )

#define SPI_70_RL78F2X_SCR_CKP        ( SPI_70_RL78F2X_SCR_CKP_MASK << SPI_70_RL78F2X_SCR_CKP_BITPOS )
#define SPI_70_RL78F2X_SCR_DAP        ( SPI_70_RL78F2X_SCR_DAP_MASK << SPI_70_RL78F2X_SCR_DAP_BITPOS )
#define SPI_70_RL78F2X_SCR_DIR        ( SPI_70_RL78F2X_SCR_DIR_MASK << SPI_70_RL78F2X_SCR_DIR_BITPOS )
#define SPI_70_RL78F2X_SCR_DLS        ( SPI_70_RL78F2X_SCR_DLS_MASK << SPI_70_RL78F2X_SCR_DLS_BITPOS )

/* SIRmn */
#define SPI_70_RL78F2X_SIR_OVCT_MASK   ( 0x0001U )
#define SPI_70_RL78F2X_SIR_OVCT_BITPOS ( 0U )
#define SPI_70_RL78F2X_SIR_OVCT        ( SPI_70_RL78F2X_SIR_OVCT_MASK << SPI_70_RL78F2X_SIR_OVCT_BITPOS )

/* SSRmn */
#define SPI_70_RL78F2X_SSR_TSF_MASK    ( 0x0001U )
#define SPI_70_RL78F2X_SSR_BFF_MASK    ( 0x0001U )
#define SPI_70_RL78F2X_SSR_OVF_MASK    ( 0x0001U )

#define SPI_70_RL78F2X_SSR_TSF_BITPOS  ( 6U )
#define SPI_70_RL78F2X_SSR_BFF_BITPOS  ( 5U )
#define SPI_70_RL78F2X_SSR_OVF_BITPOS  ( 0U )

#define SPI_70_RL78F2X_SSR_TSF        ( SPI_70_RL78F2X_SSR_TSF_MASK << SPI_70_RL78F2X_SSR_TSF_BITPOS )
#define SPI_70_RL78F2X_SSR_BFF        ( SPI_70_RL78F2X_SSR_BFF_MASK << SPI_70_RL78F2X_SSR_BFF_BITPOS )
#define SPI_70_RL78F2X_SSR_OVF        ( SPI_70_RL78F2X_SSR_OVF_MASK << SPI_70_RL78F2X_SSR_OVF_BITPOS )

/* SSm */
#define SPI_70_RL78F2X_SS_SS_MASK      ( 0x0001U )
#define SPI_70_RL78F2X_SS_SS_POS       ( 0U )
#define SPI_70_RL78F2X_SS_SS           ( SPI_70_RL78F2X_SS_SS_MASK << SPI_70_RL78F2X_SS_SS_POS )

/* STm */
#define SPI_70_RL78F2X_ST_ST_MASK      ( 0x0001U )
#define SPI_70_RL78F2X_ST_ST_POS       ( 0U )
#define SPI_70_RL78F2X_ST_ST           ( SPI_70_RL78F2X_ST_ST_MASK << SPI_70_RL78F2X_ST_ST_POS )

/* SEm */
#define SPI_70_RL78F2X_SE_SE_MASK       ( 0x0001U )
#define SPI_70_RL78F2X_SE_SE_BITPOS     ( 0U )
#define SPI_70_RL78F2X_SE_SE            ( SPI_70_RL78F2X_SE_SE_MASK << SPI_70_RL78F2X_SE_SE_BITPOS )

/* SOEm */
#define SPI_70_RL78F2X_SOE_SOE_MASK     ( 0x0001U )
#define SPI_70_RL78F2X_SOE_SOE_POS      ( 0U )
#define SPI_70_RL78F2X_SOE_SOE          ( SPI_70_RL78F2X_SOE_SOE_MASK << SPI_70_RL78F2X_SOE_SOE_POS )

/* SOm */
#define SPI_70_RL78F2X_SO_SO_MASK       ( (uint16)0x0001U )
#define SPI_70_RL78F2X_SO_CKO_MASK      ( (uint16)0x0001U )

#define SPI_70_RL78F2X_SO_SO_BITPOS     ( 0U )
#define SPI_70_RL78F2X_SO_CKO_BITPOS    ( 8U )

#define SPI_70_RL78F2X_SO_SO            ( SPI_70_RL78F2X_SO_SO_MASK << SPI_70_RL78F2X_SO_SO_BITPOS )
#define SPI_70_RL78F2X_SO_CKO           ( SPI_70_RL78F2X_SO_CKO_MASK << SPI_70_RL78F2X_SO_CKO_BITPOS )

/* MKmn */
#define SPI_70_RL78F2X_MKx_CSIMKmn_MASK ( 0x0001U )
#define SPI_70_RL78F2X_MKx_CSIMKmn      ( SPI_70_RL78F2X_MKx_CSIMKmn_MASK )

/* UTSEL (Unit Select Register) */
#define SPI_70_RL78F2X_UTSEL_SAU1       ( (uint8)1U )

#endif    /* #ifndef SPI_70_RL78F2X_HWREG_H_ */

/****************** End Of File Spi_70_RL78F2X_HwReg.h ******************/
