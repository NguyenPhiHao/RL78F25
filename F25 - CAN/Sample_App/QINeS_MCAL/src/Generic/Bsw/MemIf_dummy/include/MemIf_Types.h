/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : MemIf_Types.h                                                */
/* Version     :                                                              */
/* Note        : Dummy                                                        */
/******************************************************************************/

#ifndef MEMIF_TYPES_H
#define MEMIF_TYPES_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/* [SWS_MemIf_00064] */
typedef enum {
    /* The underlying abstraction module or device driver has not been initialized (yet). */
    MEMIF_UNINIT,
    /* The underlying abstraction module or device driver is currently idle.  */
    MEMIF_IDLE,
    /* The underlying abstraction module or device driver is currently busy.  */
    MEMIF_BUSY,
    /* The underlying abstraction module is busy with internal management operations. The underlying device driver can be busy or idle.          */
    MEMIF_BUSY_INTERNAL
} MemIf_StatusType;

/* [SWS_MemIf_00065] */
typedef enum {
    /* The job has been finished successfully.                                */
    MEMIF_JOB_OK,
    /* The job has not been finished successfully.                            */
    MEMIF_JOB_FAILED,
    /* The job has not yet been finished.                                     */
    MEMIF_JOB_PENDING,
    /* The job has been canceled.                                             */
    MEMIF_JOB_CANCELED,
    /* The requested block is inconsistent, it may contain corrupted data.    */
    MEMIF_BLOCK_INCONSISTENT,
    /* The requested block has been marked as invalid, the requested operation cannot be performed. */
    MEMIF_BLOCK_INVALID
} MemIf_JobResultType;

/* [SWS_MemIf_00066] */
typedef enum {
    /* The underlying memory abstraction modules and drivers are working in slow mode. */
    MEMIF_MODE_SLOW,
    /* The underlying memory abstraction modules and drivers are working in fast mode. */
    MEMIF_MODE_FAST
} MemIf_ModeType;

/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* const data declarations                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* external variables                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* static variables                                                           */
/*----------------------------------------------------------------------------*/

#endif /* MEMIF_TYPES_H */

/* EOF MemIf_Types.h **********************************************************/
