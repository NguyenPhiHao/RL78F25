/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Csm.h                                                        */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef CSM_H
#define CSM_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Std_Types.h"         /* [SWS_Crypto_00042] */
#include "Crypto_Cfg.h"        /* [SWS_Crypto_00008] */
#include "Crypto_70_Types.h"
#include "Crypto_GeneralTypes.h"
#include "Rte_Csm_Type.h"

/*----------------------------------------------------------------------------*/
/* source file version information                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* enums                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* structures and other typedefs                                              */
/*----------------------------------------------------------------------------*/
/* [SWS_Csm_01085]:
 * SWS Item Name : Csm_ConfigType
 * Description : Configuration data structure of Csm module.
 */
typedef struct {
    void*   null_ptr;
} Csm_ConfigType;

typedef uint8   Csm_70_ProcessingType;
#define CSM_70_ASYNCHRONOUS                 ( ( Csm_70_ProcessingType )0x00U )
#define CSM_70_SYNCHRONOUS                  ( ( Csm_70_ProcessingType )0x01U )

/* 10.2.10 CsmHash */
/* [ECUC_Csm_00021] */
typedef struct {
    Crypto_AlgorithmFamilyType              CsmHashAlgorithmFamiliy;                       /* [ECUC_Csm_00038] */
    Crypto_AlgorithmModeType                CsmHashAlgorithmMode;                          /* [ECUC_Csm_00131] */
    Crypto_AlgorithmFamilyType              CsmHashAlgorithmSecondaryFamily;               /* [ECUC_Csm_00181] */
    uint32                                  CsmHashDataMaxLength;                          /* [ECUC_Csm_00040] */
    Csm_70_ProcessingType                   CsmHashProcessing;                             /* [ECUC_Csm_00039] */
    uint32                                  CsmHashResultLength;                           /* [ECUC_Csm_00130] */
} Csm_HashType;

/* 10.2.12 CsmMacGenerate */
/* [ECUC_Csm_00022] */
typedef struct {
    Crypto_AlgorithmFamilyType              CsmMacGenerateAlgorithmFamiliy;                /* [ECUC_Csm_00188] */
    uint32                                  CsmMacGenerateAlgorithmKeyLength;              /* [ECUC_Csm_00044] */
    Crypto_AlgorithmModeType                CsmMacGenerateAlgorithmMode;                   /* [ECUC_Csm_00189] */
    Crypto_AlgorithmFamilyType              CsmMacGenerateAlgorithmSecondaryFamily;        /* [ECUC_Csm_00134] */
    uint32                                  CsmMacGenerateDataMaxLength;                   /* [ECUC_Csm_00137] */
    Csm_70_ProcessingType                   CsmMacGenerateProcessing;                      /* [ECUC_Csm_00046] */
    uint32                                  CsmMacGenerateResultLength;                    /* [ECUC_Csm_00138] */
} Csm_MacGenerateType;

/* 10.2.14 CsmMacVerify */
/* [ECUC_Csm_00023] */
typedef struct {
    Crypto_AlgorithmFamilyType              CsmMacVerifyAlgorithmFamiliy;                 /* [ECUC_Csm_00051] */
    Crypto_AlgorithmFamilyType              CsmMacVerifyAlgorithmSecondaryFamily;         /* [ECUC_Csm_00140] */
    uint32                                  CsmMacVerifyCompareLength;                    /* [ECUC_Csm_00142] */
    uint32                                  CsmMacVerifyDataMaxLength;                    /* [ECUC_Csm_00056] */
    Csm_70_ProcessingType                   CsmMacVerifyProcessing;                       /* [ECUC_Csm_00054] */
    uint32                                  CsmMacVerifyAlgorithmKeyLength;               /* AUTOSAR4.3.1 [ECUC_Csm_00193] */
} Csm_MacVerifyType;

/* 10.2.16 CsmEncrypt */
/* [ECUC_Csm_00024] */
typedef struct {
    Crypto_AlgorithmFamilyType              CsmEncryptAlgorithmFamiliy;                   /* [ECUC_Csm_00182] */
    Crypto_AlgorithmModeType                CsmEncryptAlgorithmMode;                      /* [ECUC_Csm_00060] */
    Crypto_AlgorithmFamilyType              CsmEncryptAlgorithmSecondaryFamily;           /* [ECUC_Csm_00144] */
    uint32                                  CsmEncryptDataMaxLength;                      /* [ECUC_Csm_00146] */
    Csm_70_ProcessingType                   CsmEncryptProcessing;                         /* [ECUC_Csm_00061] */
    uint32                                  CsmEncryptResultMaxLength;                    /* [ECUC_Csm_00147] */
    uint32                                  CsmEncryptAlgorithmKeyLength;                 /* AUTOSAR4.3.1 [ECUC_Csm_00191] */
} Csm_EncryptType;

/* 10.2.18 CsmDecrypt */
/* [ECUC_Csm_00025] */
typedef struct {
    Crypto_AlgorithmFamilyType              CsmDecryptAlgorithmFamiliy;                   /* [ECUC_Csm_00066] */
    uint32                                  CsmDecryptAlgorithmKeyLength;                 /* [ECUC_Csm_00067] */
    Crypto_AlgorithmModeType                CsmDecryptAlgorithmMode;                      /* [ECUC_Csm_00068] */
    Crypto_AlgorithmFamilyType              CsmDecryptAlgorithmSecondaryFamily;           /* [ECUC_Csm_00149] */
    uint32                                  CsmDecryptDataMaxLength;                      /* [ECUC_Csm_00154] */
    Csm_70_ProcessingType                   CsmDecryptProcessing;                         /* [ECUC_Csm_00069] */
    uint32                                  CsmDecryptResultMaxLength;                    /* [ECUC_Csm_00155] */
} Csm_DecryptType;

/* 10.2.28 CsmSignatureGenerate */
/* [ECUC_Csm_00028] */
typedef struct {
    Crypto_AlgorithmFamilyType              CsmSignatureGenerateAlgorithmFamily;          /* [ECUC_Csm_00089] */
    Crypto_AlgorithmModeType                CsmSignatureGenerateAlgorithmMode;            /* [ECUC_Csm_00091] */
    Crypto_AlgorithmFamilyType              CsmSignatureGenerateAlgorithmSecondaryFamily; /* [ECUC_Csm_00183] */
    uint32                                  CsmSignatureGenerateDatamaxLength;            /* [ECUC_Csm_00169] */
    uint32                                  CsmSignatureGenerateKeyLength;                /* [ECUC_Csm_00090] */
    uint32                                  CsmSignatureGenerateResultLength;             /* [ECUC_Csm_00170] */
} Csm_SignatureGenerateType;

/* 10.2.30 CsmSignatureVerify */
/* [ECUC_Csm_00029] */
typedef struct {
    Crypto_AlgorithmFamilyType              CsmSignatureVerifyAlgorithmFamiliy;           /* [ECUC_Csm_00096] */
    Crypto_AlgorithmModeType                CsmSignatureVerifyAlgorithmMode;              /* [ECUC_Csm_00098] */
    Crypto_AlgorithmFamilyType              CsmSignatureVerifyAlgorithmSecondaryFamily;   /* [ECUC_Csm_00172] */
    uint32                                  CsmSignatureVerifyCompareLength;              /* [ECUC_Csm_00176] */
    uint32                                  CsmSignatureVerifyDataMaxLength;              /* [ECUC_Csm_00175] */
    Csm_70_ProcessingType                   CsmSignatureVerifyProcessing;                 /* [ECUC_Csm_00099] */
    uint32                                  CsmSignatureVerifyKeyLength;                  /* AUTOSAR4.3.1 [ECUC_Csm_00192] */
} Csm_SignatureVerifyType;

/* 10.2.32 CsmRandomGenerate */
/* [ECUC_Csm_00031] */
typedef struct {
    Crypto_AlgorithmFamilyType              CsmRandomGenerateAlgorithmFamiliy;           /* [ECUC_Csm_00105] */
    Crypto_AlgorithmModeType                CsmRandomGenerateAlgorithmMode;              /* [ECUC_Csm_00107] */
    Crypto_AlgorithmFamilyType              CsmRandomGenerateAlgorithmSecondaryFamily;   /* [ECUC_Csm_00178] */
    Csm_70_ProcessingType                   CsmRandomGenerateProcessing;                 /* [ECUC_Csm_00108] */
    uint32                                  CsmRandomGenerateResultLength;               /* [ECUC_Csm_00106] */
} Csm_RandomGenerateType;

/* 10.2.34 CsmCustom */
/* [ECUC_Csm_00343] */
typedef struct {
    Crypto_AlgorithmFamilyType                  CsmCustomAlgorithmFamily;                   /* [ECUC_Csm_00344] */
    Crypto_AlgorithmModeType                    CsmCustomAlgorithmMode;                     /* [ECUC_Csm_00346] */
    Crypto_AlgorithmFamilyType                  CsmCustomAlgorithmSecondaryFamily;          /* [ECUC_Csm_00348] */
    uint32                                      CsmCustomInputMaxLength;                    /* [ECUC_Csm_00350] */
    uint32                                      CsmCustomOutputMaxLength;                   /* [ECUC_Csm_00353] */
    uint32                                      CsmCustomSecondaryInputMaxLength;           /* [ECUC_Csm_00351] */
    uint32                                      CsmCustomSecondaryOutputMaxLength;          /* [ECUC_Csm_00354] */
    uint32                                      CsmCustomTargetKeyMaxLength;                /* [ECUC_Csm_00355] */
    uint32                                      CsmCustomTertiaryInputMaxLength;            /* [ECUC_Csm_00352] */
    Crypto_PrimitiveAlgorithmFamilyCustomType*  CsmCustomAlgorithmFamilyCustomRef;          /* [ECUC_Csm_00345] */
    Crypto_PrimitiveAlgorithmmodeCustomType*    CsmCustomAlgorithmModeCustomRef;            /* [ECUC_Csm_00347] */
    Crypto_PrimitiveAlgorithmFamilyCustomType*  CsmCustomAlgorithmSecondaryFamilyCustomRef; /* [ECUC_Csm_00349] */
} Csm_CustomType;

/* 10.2.36 CsmJobKeySetValid */
/* [ECUC_Csm_00204] */
typedef struct {
    Crypto_AlgorithmFamilyType                  CsmJobKeySetValidAlgorithmFamily;                   /* [ECUC_Csm_00328] */
    Crypto_AlgorithmModeType                    CsmJobKeySetValidAlgorithmMode;                     /* [ECUC_Csm_00329] */
    Crypto_AlgorithmFamilyType                  CsmJobKeySetValidAlgorithmSecondaryFamily;          /* [ECUC_Csm_00340] */
    Crypto_PrimitiveAlgorithmFamilyCustomType*  CsmJobKeySetValidAlgorithmFamilyCustomRef;          /* [ECUC_Csm_00330] */
    Crypto_PrimitiveAlgorithmmodeCustomType*    CsmJobKeySetValidAlgorithmModeCustomRef;            /* [ECUC_Csm_00331] */
    Crypto_PrimitiveAlgorithmFamilyCustomType*  CsmJobKeySetvalidAlgorithmSecondaryFamilyCustomRef; /* [ECUC_Csm_00332] */
} Csm_JobKeySetValidType;

/* 10.2.38 CsmJobKeySetInvalid */
/* [ECUC_Csm_00334] */
typedef struct {
    Crypto_AlgorithmFamilyType                  CsmJobKeySetInvalidAlgorithmFamily;                     /* [ECUC_Csm_00335] */
    Crypto_AlgorithmModeType                    CsmJobKeySetInvalidAlgorithmMode;                       /* [ECUC_Csm_00336] */
    Crypto_AlgorithmFamilyType                  CsmJobKeySetInvalidAlgorithmSecondaryFamily;            /* [ECUC_Csm_00341] */
    Crypto_PrimitiveAlgorithmFamilyCustomType*  CsmJobKeySetInvalidAlgorithmFamilyCustomRef;            /* [ECUC_Csm_00337] */
    Crypto_PrimitiveAlgorithmmodeCustomType*    CsmJobKeySetInvaildAlgorithmModeCustomRef;              /* [ECUC_Csm_00339] */
    Crypto_PrimitiveAlgorithmFamilyCustomType*  CsmJobKeySetInvalidAlgorithmSecondaryFamilyCustomRef;   /* [ECUC_Csm_00338] */
} Csm_JobKeySetInvalidType;

/* 10.2.40 CsmJobRandomSeed */
/* [ECUC_Csm_00261] */
typedef struct {
    Crypto_AlgorithmFamilyType                  CsmJobRandomSeedAlgorithmFamily;                    /* [ECUC_Csm_00206] */
    Crypto_AlgorithmModeType                    CsmJobRandomSeedAlgorithmMode;                      /* [ECUC_Csm_00208] */
    Crypto_AlgorithmFamilyType                  CsmJobRandomSeedAlgorithmSecondaryFamily;           /* [ECUC_Csm_00210] */
    Crypto_PrimitiveAlgorithmFamilyCustomType*  CsmJobRandomSeedAlgorithmFamilyCustomRef;           /* [ECUC_Csm_00312] */
    Crypto_PrimitiveAlgorithmModeCustomType*    CsmJobRandomSeedAlgorithmModeCustomRef;             /* [ECUC_Csm_00313] */
    Crypto_PrimitiveAlgorithmFamilyCustomType*  CsmJobRandomSeedAlgorithmSecondaryFamilyCustomRef;  /* [ECUC_Csm_00314] */
} Csm_JobRandomSeedType;

/* 10.2.9 CsmQueue */
/* [ECUC_Csm_00032] */
typedef struct {
    uint32                                  CsmChannelRef;                              /* [ECUC_Csm_00033] */
    uint32                                  CsmQueueSize;                               /* [ECUC_Csm_00034] */
} Csm_QueueType;

/* 10.2.8 CsmQueues */
/* [ECUC_Csm_00007] */
typedef struct {
    uint32                                  CsmNumOfQueue;                              /* [QINeS] */
    CSM_70_CONST Csm_QueueType*             CsmQueue;                                   /* [ECUC_Csm_00054] */
} Csm_QueuesType;

/* 10.2.12 CsmPrimitives */
/* [ECUC_Csm_00006] */
typedef struct {
    CSM_70_CONST Csm_HashType*               CsmHash;                                    /* [ECUC_Csm_00021] */
    CSM_70_CONST Csm_MacGenerateType*        CsmMacGenerate;                             /* [ECUC_Csm_00022] */
    CSM_70_CONST Csm_MacVerifyType*          CsmMacVerify;                               /* [ECUC_Csm_00023] */
    CSM_70_CONST Csm_EncryptType*            CsmEncrypt;                                 /* [ECUC_Csm_00024] */
    CSM_70_CONST Csm_DecryptType*            CsmDecrypt;                                 /* [ECUC_Csm_00025] */
    CSM_70_CONST Csm_SignatureVerifyType*    CsmSignatureVerify;                         /* [ECUC_Csm_00029] */
    CSM_70_CONST Csm_RandomGenerateType*     CsmRandomGenerate;                          /* [ECUC_Csm_00031] */
    CSM_70_CONST Csm_SignatureGenerateType*  CsmSignatureGenerate;                       /* [ECUC_Csm_00028] */
    CSM_70_CONST Csm_CustomType*             CsmCustom;                                  /* [ECUC_Csm_00343] */
    CSM_70_CONST Csm_JobKeySetValidType*     CsmJobKeySetValid;                          /* [ECUC_Csm_00204] */
    CSM_70_CONST Csm_JobKeySetInvalidType*   CsmJobKeySetInvalid;                        /* [ECUC_Csm_00334] */
    CSM_70_CONST Csm_JobRandomSeedType*      CsmRandomSeed;                              /* [ECUC_Csm_00261] */
} Csm_PrimitivesType;

/* 10.2.7 CsmKey */
/* [ECUC_Csm_00014] */
typedef struct {
    uint32                                  CsmKeyId;                                   /* [ECUC_Csm_00015] */
    bool_t                                  CsmKeyUsePort;                              /* [ECUC_Csm_00127] */
    uint32*                                 CsmKeyRef;                                  /* [ECUC_Csm_00016] */
} Csm_KeyType;

/* 10.2.6 CsmKeys */
/* [ECUC_Csm_00005] */
typedef struct {
    uint32                                  CsmNumOfKey;                                /* [QINeS] */
    CSM_70_CONST Csm_KeyType*               CsmKey;                                     /* [ECUC_Csm_00014] */
} Csm_KeysType;

/* 10.2.5 CsmJob */
/* [ECUC_Csm_00118] */
typedef struct {
    uint32                                  CsmJobId;                                   /* [ECUC_Csm_00119] */
    uint8                                   CsmJobInterfaceUsePort;                     /* [ECUC_Csm_00275] */
    uint32                                  CsmJobPriority;                             /* [ECUC_Csm_00120] */
    bool_t                                  CsmJobServiceInterfaceContextUsePort;       /* [ECUC_Csm_00327] */
    Crypto_ProcessingType                   CsmProcessingMode;                          /* [ECUC_Csm_00276] */
    CSM_70_CONST CsmInOutRedirectionType*   CsmInOutRedirectionRef;                     /* [ECUC_Csm_00263] */
    CSM_70_CONST Csm_KeyType*               CsmJobKeyRef;                               /* [ECUC_Csm_00126] */
    CSM_70_CONST Csm_PrimitivesType*        CsmJobPrimitiveRef;                         /* [ECUC_Csm_00122] */
    CSM_70_CONST Csm_QueueType*             CsmJobQueueRef;                             /* [ECUC_Csm_00125] */
} Csm_JobType;

/* 10.2.4 CsmJobs */
/* [ECUC_Csm_00112] */
typedef struct {
    uint32                                  CsmNumOfJob;                                /* [QINeS] */
    CSM_70_CONST Csm_JobType*                CsmJob;                                    /* [ECUC_Csm_00118] */
} Csm_JobsType;

/* 10.2.11 CsmInOutRedirection */
/* [ECUC_Csm_00264] */
typedef struct {
    uint32                      CsmInputKeyElementId;               /* [ECUC_Csm_00266] */
    uint32                      CsmOutputKeyElementId;              /* [ECUC_Csm_00272] */
    uint32                      CsmSecondaryInputKeyElementId;      /* [ECUC_Csm_00269] */
    uint32                      CsmSecondaryOutputKeyElementId;     /* [ECUC_Csm_00274] */
    uint32                      CsmTertiaryInputKeyElementId;       /* [ECUC_Csm_00270] */
    CSM_70_CONST CsmKeyType*    CsmInputKeyRef;                     /* [ECUC_Csm_00265] */
    CSM_70_CONST CsmKeyType*    CsmOutputKeyRef;                    /* [ECUC_Csm_00271] */
    CSM_70_CONST CsmKeyType*    CsmSecondaryInputKeyRef;            /* [ECUC_Csm_00267] */
    CSM_70_CONST CsmKeyType*    CsmSecondaryOutputKeyRef;           /* [ECUC_Csm_00273] */
    CSM_70_CONST CsmKeyType*    CsmTertiaryInputKeyRef;             /* [ECUC_Csm_00268] */
} Csm_InOutRedirectionType;

/* 10.2.10 CsmInOutRedirections */
/* [ECUC_Csm_00262] */
typedef struct {
    uint32                                  CsmNumOfRedirection;
    CSM_70_CONST Csm_InOutRedirectionType*  CsmInOutRedirections;
} Csm_InOutRedirectionsType;

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
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

#endif  /* CSM_H */

/* EOF Csm.h ******************************************************************/
