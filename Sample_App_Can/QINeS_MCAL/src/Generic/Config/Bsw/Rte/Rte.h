/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte.h                                                        */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef RTE_H
#define RTE_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Rte_AR.h"

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
/* phân tách các nhóm lỗi trong thông báo trạng thái */
#define Rte_IsInfrastructureError(status)   (((status) & 128U) != 0)  
#define Rte_HasOverlayedError(status)      (((status) &  64U) != 0)  
#define Rte_ApplicationError(status)       ((status) &  63U)         

/* các mã lỗi ứng dụng RTE */
#define RTE_E_OK                   (  0U )
#define RTE_E_INVALID              (  1U )
#define RTE_E_COM_STOPPED          (128U )
#define RTE_E_TIMEOUT              (129U )
#define RTE_E_LIMIT                (130U )
#define RTE_E_NO_DATA              (131U )
#define RTE_E_TRANSMIT_ACK         (132U )
#define RTE_E_NEVER_RECEIVED       (133U )
#define RTE_E_UNCONNECTED          (134U )
#define RTE_E_IN_EXCLUSIVE_AREA    (135U )
#define RTE_E_SEG_FAULT            (136U )
#define RTE_E_OUT_OF_RANGE         (137U )
#define RTE_E_SERIALIZATION_ERR    (138U )
#define RTE_E_HARD_TRANSFORMER_ERR (139U )
#define RTE_E_SERIALIZATION_LIMIT  (140U )
#define RTE_E_TRANSFORMER_LIMIT    (141U )
#define RTE_E_SOFT_TRANSFORMER_ERR (142U )
#define RTE_E_COM_BUSY             (143U )
#define RTE_E_NG                   ( 64U )  /* general “not good” */
#define RTE_E_LOST_DATA            ( 64U )
#define RTE_E_MAX_AGE_EXCEEDED     ( 64U )

#define SCHM_E_OK                   (  0U )
#define SCHM_E_LIMIT                (130U )
#define SCHM_E_NO_DATA              (131U )
#define SCHM_E_TRANSMIT_ACK         (132U )
#define SCHM_E_IN_EXCLUSIVE_AREA    (135U )
#define SCHM_E_TIMEOUT              (129U )
#define SCHM_E_NG                   (191U )

#endif /* RTE_H */

/* End of Rte.h */
