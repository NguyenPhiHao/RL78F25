/*----------------------------------------------------------------------------*/
/* Copyright  : 2023 SCSK Corporation                                         */
/* System Name: QINeS-Lite MCAL                                               */
/* File Name  : r_memory_operation.c                                          */
/* Version    : v1.00.00                                                      */
/* Contents   : This file is for SHA Hash library used in AUTOSAR Basic       */
/*              Software module "Crypto Driver".                              */
/* Author     : m.ishikawa                                                    */
/* Note       : --                                                            */
/*----------------------------------------------------------------------------*/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */
/*----------------------------------------------------------------------------*/

#include "Platform_Types.h"
#include "Std_Types.h"
#include "r_memory_config.h"
#include "r_memory_operation.h"

#define U32_NEAR_START_ADDRESS  (uint32)(0xF0000U)

#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
/*----------------------------------------------------------------------------*/
/* Function Name : r_clear_work_area_32bit_unit                               */
/* Description   : Clear the input WORK area in 32-bit units.                 */
/* Arguments     : data_address, len                                          */
/* Return Value  : None                                                       */
/*----------------------------------------------------------------------------*/
void r_clear_work_area_32bit_unit(uint32 * work, uint8 len)
{
    uint8 i;

    for (i = 0u; i < len; i++)
    {
        work[i] = 0x00000000U;
    }
}
/*----------------------------------------------------------------------------*/
/* End of function r_clear_work_area_32bit_unit                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Name : r_ram_cpy_32bit_unit                                       */
/* Description   : Copy data from buf2 to buf1.                               */
/* Arguments     : buf1, buf2, len                                            */
/* Return Value  : None                                                       */
/*----------------------------------------------------------------------------*/
void r_ram_cpy_32bit_unit(uint32 * buf1, const uint32 * buf2, uint8 len)
{
    uint8 i;

    for (i = 0u; i < len; i++)
    {
        buf1[i] = buf2[i];
    }
}
/*----------------------------------------------------------------------------*/
/* End of function r_ram_cpy_32bit_unit                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Name : r_chk_ram_range_valid                                      */
/* Description   : Make sure the range of data fits in the RAM area.          */
/* Arguments     : start_address, len                                         */
/* Return Value  : RANGE_OK                                                   */
/*                RANGE_NG                                                    */
/*----------------------------------------------------------------------------*/
uint8 r_chk_ram_range_valid(const uint8 *start_address, uint16 len)
{
    uint8  ret         = RANGE_NG;
    uint32 u32_address = (uint32)start_address & (uint32)(0xFFFFFFU);

    /* MOD : For the elimination of pointer arithmetic. */
    if ( ((const uint8 *)NULL_PTR != start_address)
      && ((uint32)RAM_START    <= u32_address)
      && ((uint32)RAM_END      >= (u32_address + ((uint32)len - 1u))) )
    {
        /* Returns RANGE_OK if the input data fits in the RAM area */
        ret = RANGE_OK;
    }

    return (ret);
}

/*----------------------------------------------------------------------------*/
/* End of function r_chk_ram_range_valid                                      */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Function Name : r_chk_rom_ram_range_valid                                  */
/* Description   : Make sure the range of data fits in the ROM/RAM area.      */
/* Arguments     : start_address, len                                         */
/* Return Value  : RANGE_OK                                                   */
/*                RANGE_NG                                                    */
/*----------------------------------------------------------------------------*/
uint8 r_chk_rom_ram_range_valid(const uint8 QL_70_FAR *start_address, uint16 len)
{
    uint8  ret         = RANGE_NG;
    uint32 u32_address = (uint32)start_address & (uint32)(0xFFFFFFU);

    if (((const uint8 QL_70_FAR *)NULL_PTR != start_address)
      && ((uint32)ROM_START <= u32_address)
      && ((uint32)ROM_END   >= (u32_address + ((uint32)len - 1u)))
      )
    {
        /* Returns RANGE_OK if the input data is fits in the ROM area */
        ret = RANGE_OK;
    }
    else
    {
        if (U32_NEAR_START_ADDRESS <= u32_address)
        {
            /* Perform RAM check if input data fits in __near area */
            ret = r_chk_ram_range_valid((const uint8 QL_70_NEAR *)start_address, len);
        }
    }
    return (ret);
}

/*----------------------------------------------------------------------------*/
/* End of function r_chk_ram_range_valid                                      */
/*----------------------------------------------------------------------------*/

#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
