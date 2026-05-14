/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : Lin_70_RL78F2X_HwReg.h                                       */
/* Version     : v1.00.02                                                     */
/* Contents    : LIN Module HW dependent header                               */
/*               The File contains HW register address used by LIN module     */
/*               The LIN is a basic software module at the service layer of   */
/*               the standardized basic software architecture of AUTOSAR.     */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/
/* Specification of LIN Driver                                                */
/* R22-11                                                                     */
/******************************************************************************/

#ifndef LIN_70_RL78F2X_HWREG_H
#define LIN_70_RL78F2X_HWREG_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
/*----------------------------------------------------------------------------*/
/* file version information                                                   */
/*----------------------------------------------------------------------------*/
#define LIN_70_VENDOR_ID_RL78F2X_HWREG_H                      ( 70U )
#define LIN_70_MODULE_ID_RL78F2X_HWREG_H                      ( 82U )

#define LIN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_HWREG_H       ( 22U )
#define LIN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_HWREG_H       ( 11U )
#define LIN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_HWREG_H    ( 0U )

#define LIN_70_SW_MAJOR_VERSION_RL78F2X_HWREG_H               ( 1U )
#define LIN_70_SW_MINOR_VERSION_RL78F2X_HWREG_H               ( 0U )
#define LIN_70_SW_PATCH_VERSION_RL78F2X_HWREG_H               ( 0U )

/*----------------------------------------------------------------------------*/
/* file version checks                                                        */
/*----------------------------------------------------------------------------*/

/* Check if header file and Std types header file are of the same Autosar version */
/*--------------------Std_Types.h version ------------------------------------*/
#if ( ( LIN_70_AR_RELEASE_MAJOR_VERSION_RL78F2X_HWREG_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
      ( LIN_70_AR_RELEASE_MINOR_VERSION_RL78F2X_HWREG_H != STD_TYPES_AR_RELEASE_MINOR_VERSION ) || \
      ( LIN_70_AR_RELEASE_REVISION_VERSION_RL78F2X_HWREG_H != \
        STD_TYPES_AR_RELEASE_REVISION_VERSION ) )
    #error "AUTOSAR Version Numbers of Lin_70_RL78F2X_Types.h and Std_Types.h are different"
#endif

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/* H/W Register setting */
typedef struct {
    uint8  LWBR_REG;       /* LIN Wake-up Baud Rate Select Register             (0xF06C1) */
    uint8  LBRP0_REG;      /* LIN Baud Rate Prescaler 0 Register                (0xF06C2) */
    uint8  LBRP1_REG;      /* LIN Baud Rate Prescaler 1 Register                (0xF06C3) */
    uint8  LSTC_REG;       /* LIN Self-Test Control Register                    (0xF06C4) */
    uint8  reserve1[3];    /* reserve                                   (0xF06C5-0xF06C7) */
    uint8  LMD_REG;        /* LIN Mode Register                                 (0xF06C8) */
    uint8  LBFC_REG;       /* LIN Break Field Configuration Register            (0xF06C9) */
    uint8  LSC_REG;        /* LIN Space Configuration Register                  (0xF06CA) */
    uint8  LWUP_REG;       /* LIN Wake-up Configuration Register                (0xF06CB) */
    uint8  LIE_REG;        /* LIN Interrupt Enable Register                     (0xF06CC) */
    uint8  LEDE_REG;       /* LIN Error Detection Enable Register               (0xF06CD) */
    uint8  LCUC_REG;       /* LIN Control Register                              (0xF06CE) */
    uint8  reserve2[1];    /* reserve                                           (0xF06CF) */
    uint8  LTRC_REG;       /* LIN Transmission Control Register                 (0xF06D0) */
    uint8  LMST_REG;       /* LIN Mode Status Register                          (0xF06D1) */
    uint8  LST_REG;        /* LIN Status Register                               (0xF06D2) */
    uint8  LEST_REG;       /* LIN Error Status Register                         (0xF06D3) */
    uint8  LDFC_REG;       /* LIN Data Field Configuration Register             (0xF06D4) */
    uint8  LIDB_REG;       /* LIN ID Buffer Register                            (0xF06D5) */
    uint8  LCBR_REG;       /* LIN Checksum Buffer Register                      (0xF06D6) */
    uint8  reserve3[1];    /* reserve                                           (0xF06D7) */
    uint8  LDB_REG[8];     /* LIN Data Buffer Register                  (0xF06D8-0xF06DF) */
    uint8  reserve4[13];   /* reserve                                   (0xF06E0-0xF06EB) */
    uint8  LBSS_REG;       /* LIN break/sink field detection status register    (0xF06EC) */
    uint8  reserve5[1];    /* reserve                                           (0xF06ED) */
    uint8  LRSS_REG;       /* LIN Response Space Dominant Detection Status Reg  (0xF06EE) */
} LIN_70_RL78Type;

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/* address definitions for I/O register */
#define LIN_IO8(addr) ((volatile uint8 QL_70_NEAR *)(addr))

/* PER2 register : Enable/Disable supplying the clock to the peripheral hardware. */
#define LIN_70_RL78F2X_PER2_REG     ( * ( LIN_IO8  ( 0x2C1U  ) ) )

/* LIN Clock Select Register */
#define LIN_70_RL78F2X_LINCKSEL     ( * ( LIN_IO8  ( 0x2C3U  ) ) )

#define LIN_70_RL78F2X_MK0H         ( * ( LIN_IO8  ( 0xFFE5U  ) ) )


#define LIN_70_RL78F2X_MK1L         ( * ( LIN_IO8  ( 0xFFE6U  ) ) )


#define LIN_70_RL78F2X_MK2L         ( * ( LIN_IO8  ( 0xFFD4U  ) ) )


#define LIN_70_RL78F2X_MK3L         ( * ( LIN_IO8  ( 0xFFD6U  ) ) )


#define LIN_70_RL78F2X_IF1L         ( * ( LIN_IO8  ( 0xFFE2U  ) ) )


#define LIN_70_RL78F2X_IF0H         ( * ( LIN_IO8  ( 0xFFE1U  ) ) )

#define LIN_70_RL78F2X_IF3L         ( * ( LIN_IO8  ( 0xFFD2U  ) ) )

/* LIN Channel Select Register */
#define LIN_70_RL78F2X_LCHSEL       ( * ( LIN_IO8  ( 0x07BU    ) ) )

/* Base address defined for LIN registers used */
#define LIN_70_RL78F2X_REG_ADDR     (volatile LIN_70_RL78Type QL_70_NEAR *)( 0x06C1U )

/* Q-Lite Phase1 Lin */
#define LIN_70_RL78F2X_ISC          ( * ( LIN_IO8  ( 0x0073U    ) ) )


#endif  /* #ifndef LIN_70_RL78F2X_HWREG_H */
/* EOF Lin_70_RL78F2X_HwReg.h *************************************************/
