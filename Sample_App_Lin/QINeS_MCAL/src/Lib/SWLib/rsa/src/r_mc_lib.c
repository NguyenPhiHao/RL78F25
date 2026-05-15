/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : r_mc_lib.c                                                   */
/* Version     : v1.00.00                                                     */
/* Contents    : This file is for RSA library used in AUTOSAR Basic Software  */
/*               module "Crypto Driver".                                      */
/* Author      : --                                                           */
/* Note        : --                                                           */
/******************************************************************************/
/* Specification of Crypto Driver                                             */
/* R22-11                                                                     */

/*----------------------------------------------------------------------------*/
/* Includes   <System Includes> , "Project Includes"                          */
/*----------------------------------------------------------------------------*/
#include "r_mc_lib.h"
#include "r_rsa_internal_header.h"

/*----------------------------------------------------------------------------*/
/* Prototype declaration                                                      */
/*----------------------------------------------------------------------------*/
static void r_mc_movl (MC_int *x, MC_int *y);
static void r_mc_mull (MC_int *x, MC_int *y, MC_int *z);
static void r_mc_sqrl (MC_int *x, MC_int *z);
static void r_mc_reml(MC_int *x, MC_int *y, MC_int *r);
static MC MC_KWD r_mc_rems(MC x, MC_int *y);
static MCMC r_mc_lshl(MCMC rsa_div, uint16 n);
static MCMC r_mc_lshr(MCMC rsa_div, uint16 n);

/*----------------------------------------------------------------------------*/
/* Macro definitions                                                          */
/*----------------------------------------------------------------------------*/
#define MC_OK       (0x00u)
#define MC_ERR      (0x01u)
#define MC_SMALL    (0x02u)
#define MC_LARGE    (0x03u)

/*----------------------------------------------------------------------------*/
/* Exported global function                                                   */
/*----------------------------------------------------------------------------*/

#define CRYPTO_START_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
/******************************************************************************/
/* Declaration  : uint8 r_mc_byte2mc (uint8 *ip, uint16 len, MC_int *mc_op)
/* Function Name: r_mc_byte2mc
/* Description  : Convert 1-byte array data to MC_int type.
/* Arguments    : ip Array data in 1-byte units.
/*                len Length of array data in 1-byte units.
/*                mc_op MC_int type variable.
/* Return Value : MC_ERR Error end.
/*                MC_OK  Normal end.
/******************************************************************************/
uint8 r_mc_byte2mc(uint8 QL_70_FAR *ip, uint16 len, MC_int *mc_op)
{
    uint16  counter;
    uint16  len_wk = len;
    uint16  zeroLen;
    uint8   mc_ret = MC_ERR;
    uint8   ipr_idx = 0u;
    uint16  valuer_idx;
 
    if ((mc_op->val != NULL_PTR) && (ip != NULL_PTR) && (len_wk <= (uint16) IO_DATA_BYTE_LENGTH) && (len_wk != (uint16) 0))
    {
        /* Skip 0x00 */
        zeroLen = 0u;
        for (counter = 0u; counter< (len_wk - 1u); counter++)
        {
            /* MOD : For the elimination of pointer arithmetic. */
            if (ip[ipr_idx] == (uint8)0x00U)
            {
                /* MOD : For the elimination of pointer arithmetic. */
                zeroLen++;
                ipr_idx++;
            }
            else
            {
                break;
            }

            /* RSA Library Cancel Reqest Check */
            if (RSA_CANCEL == g_rsa_cancel_req)
            {
                break;   /* RSA Library Cancel Return */
            }
            else
            {
                /* Do nothing */
            }
        }
        len_wk -= zeroLen;
        
        mc_op->deg = ((len_wk + (uint16) 1u) >> 1u) - (uint16) 1u;
        
        /* MOD : For the elimination of pointer arithmetic. */
        valuer_idx = mc_op->deg;
        
        mc_op->val[valuer_idx] = 0u;
        for (counter = len_wk; counter > 0u; counter--)
        { /* Use a down counter to process the data from the end. */
            if ((counter % 2u) != 0u)
            {
                /* MOD : For the elimination of pointer arithmetic. */
                mc_op->val[valuer_idx] |= ((MC)ip[ipr_idx]);
                valuer_idx--;
                ipr_idx++;
            }
            else
            {
                /* MOD : For the elimination of pointer arithmetic. */
                mc_op->val[valuer_idx] = ((MC)ip[ipr_idx]) << 8u;
                ipr_idx++;
            }
            
            /* RSA Library Cancel Reqest Check */
            if (g_rsa_cancel_req == RSA_CANCEL)
            {
                break;   /* RSA Library Cancel Return */
            }
            else
            {
                /* Do nothing */
            }
        }
        
    }
    else
    {
        /* Do nothing */
    }
 
    if (g_rsa_cancel_req == RSA_CANCEL)
    {
        mc_ret = MC_ERR;    /* RSA Library Cancel Return */
    }
    else
    {
        mc_ret = MC_OK;
    }
 
    return mc_ret;
 
} /* End of function r_mc_byte2mc() */

/******************************************************************************/
/* Declaration  : uint8 r_mc_mc2byte(MC_int *mc_ip, uint8 *op, uint16 *len)   */
/* Function Name: r_mc_mc2byte                                                */
/* Description  : Convert from MC_int type to 1-byte array data.              */
/* Arguments    : mc_ip MC_int type variable.                                 */
/*                op Array data in 1-byte units.                              */
/*                len Length of array data in 1-byte units.                   */
/* Return Value : MC_ERR Error end.                                           */
/*                MC_OK  Normal end.                                          */
/******************************************************************************/
uint8 r_mc_mc2byte(MC_int *mc_ip, uint8 *op, uint16 *len)
{
    uint8   flag;
    uint16  counter;
    uint16  zeroLen;
    uint8   mc_ret = MC_ERR;
    uint16  opr_idx;
    uint16  valuer_idx;
    
    if ((mc_ip->val != NULL_PTR) && (op != NULL_PTR))
    {
        if (((mc_ip->deg + (uint16) 1) << 1u) <= (uint16) IO_DATA_BYTE_LENGTH)
        {
            /* Register pointer initial value setting */
            /* MOD : For the elimination of pointer arithmetic. */
            valuer_idx = mc_ip->deg;
            zeroLen = IO_DATA_BYTE_LENGTH - ((mc_ip->deg + (uint16) 1) << 1u);
            
            /* MOD : For the elimination of pointer arithmetic. */
            for (counter = 0u; counter < zeroLen; counter++)
            {
                op[counter] = 0x00u;
            }
            
            /* MOD : For the elimination of pointer arithmetic. */
            opr_idx = zeroLen;
            flag = 0u;
            
            while (flag == 0u)
            {
                /* MOD : For the elimination of pointer arithmetic. */
                if ((mc_ip->val[valuer_idx] & 0xffffu) == 0u)
                {
                    if (0u == mc_ip->deg)
                    {
                        flag = 1u;
                    }
                    else
                    {
                        /* MOD : For the elimination of pointer arithmetic. */
                        mc_ip->deg--;
                        valuer_idx--;
                        opr_idx += 2u;
                    }
                }
                else
                {
                    flag = 1u;
                }
                
                /* RSA Library Cancel Reqest Check */
                if (g_rsa_cancel_req == RSA_CANCEL)
                {
                    flag = 1u;   /* RSA Library Cancel Break */
                }
                else
                {
                    /* Do nothing */
                }
            }
            
            /* MOD : For the elimination of pointer arithmetic. */
            if ((mc_ip->val[valuer_idx] & 0xff00u) == 0u)
            {
                /* MOD : For the elimination of pointer arithmetic. */
                *len = (uint16) (((mc_ip->deg + (uint16) 1) << 1u) - (uint16) 1);
                op[opr_idx] = 0x00u;
                opr_idx++;
            }
            else
            {
                *len = ((mc_ip->deg + 1u) << 1u);
            }
            
            for (counter = *len; counter > 0u; counter--)
            { /* Use a down counter to process the data from the end. */
                if ((counter % 2u) == 0u)
                {
                    /* MOD : For the elimination of pointer arithmetic. */
                    op[opr_idx] = (uint8) (mc_ip->val[valuer_idx] >> 8u);
                    opr_idx++;
                }
                else
                {
                    /* MOD : For the elimination of pointer arithmetic. */
                    op[opr_idx] = (uint8) (mc_ip->val[valuer_idx]);
                    opr_idx++;
                    valuer_idx--;
                }
                
                /* RSA Library Cancel Reqest Check */
                if (g_rsa_cancel_req == RSA_CANCEL)
                {
                    break;   /* RSA Library Cancel Return */
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Do nothing */
    }
 
    if (g_rsa_cancel_req == RSA_CANCEL)
    {
        mc_ret = MC_ERR;    /* RSA Library Cancel Return */
    }
    else
    {
        mc_ret = MC_OK;
    }
 
    return mc_ret;
} /* End of function r_mc_mc2byte() */
 
/******************************************************************************/
/* Declaration  : static void r_mc_movl(MC_int *x, MC_int *y)                 */
/* Function Name: r_mc_movl                                                   */
/* Description  : Copy a multiple-precision variable.                         */
/* Arguments    : x Copy source of multiple-precision variable.               */
/*                y Copy destination of multiple-precision variable.          */
/* Return Value : none.                                                       */
/******************************************************************************/
static void r_mc_movl(MC_int *x, MC_int *y)
{
    uint16 counter;
 
    /* Copy process */
    y->deg = x->deg;
    for (counter = 0u; counter <= y->deg; counter++)
    {
        /* MOD : For the elimination of pointer arithmetic. */
        y->val[counter] = x->val[counter];
 
        /* RSA Library Cancel Reqest Check */
        if (g_rsa_cancel_req == RSA_CANCEL)
        {
            break;   /* RSA Library Cancel Return */
        }
        else
        {
            /* Do nothing */
        }
    }
} /* End of function r_mc_movl() */
 
/******************************************************************************/
/* Declaration  : uint8 r_mc_cmpl(MC_int *x, MC_int *y)                       */
/* Function Name: r_mc_cmpl                                                   */
/* Description  : Compare multiple length variables.                          */
/* Arguments    : x Comparison source multiple length variable.               */
/*                y Comparison target multiple length variable.               */
/* Return Value : MC_ERR   (0x01u)  Error end.                                */
/*                MC_OK    (0x00u)  Equivalence.                              */
/*                MC_SMALL (0x02u)  The comparison destination is small.      */
/*                MC_LARGE (0x03u)  The comparison destination is large.      */
/******************************************************************************/
uint8 r_mc_cmpl(MC_int *x, MC_int *y)
{
    uint16  counter;
    uint8   mc_ret = MC_ERR;
 
    /* Most significant digit comparison */
    if (y->deg > x->deg)
    {
        mc_ret = MC_LARGE;
    }
    else if (y->deg < x->deg)
    {
        mc_ret = MC_SMALL;
    }
    else
    {
        /* Comparison of the value */
        for (counter = 0u; counter <= x->deg; counter++)
        {
            /* MOD : For the elimination of pointer arithmetic. */
            if (y->val[counter] > x->val[counter])
            {
                mc_ret = MC_LARGE;
                break;
            }
            else
            {
                /* Do nothing */
            }
 
            /* MOD : For the elimination of pointer arithmetic. */
            if (y->val[counter] < x->val[counter])
            {
                mc_ret = MC_SMALL;
                break;
            }
            else
            {
                /* Do nothing */
            }
 
            mc_ret = MC_OK;
 
            /* RSA Library Cancel Request Check */
            if (g_rsa_cancel_req == RSA_CANCEL)
            {
                mc_ret = MC_ERR;
                break;   /* RSA Library Cancel Return */
            }
            else
            {
                /* Do nothing */
            }
        }
    }
 
    return mc_ret;
} /* End of function r_mc_cmpl() */
 
/******************************************************************************/
/* Declaration  : void r_mc_mull(MC_int *x, MC_int *y, MC_int *z)             */
/* Function Name: r_mc_mull                                                   */
/* Description  : Multiplication of multiple length variables.                */
/* Arguments    : x Variable x for multiplication.                            */
/*                y Variable y for multiplication.                            */
/*                z Multiplication result z.                                  */
/* Return Value : none.                                                       */
/******************************************************************************/
static void r_mc_mull(MC_int *x, MC_int *y, MC_int *z)
{
    MCMC    mul;
    uint16  counterA;
    uint16  counterB;
 
    /* If x or y is 0, the result is 0 and the process ends */
    /* MOD : For the elimination of pointer arithmetic. */
    if ((((uint16)0U == (x->deg)) && ((uint16)0U == (x->val[0])))
    ||  (((uint16)0U == (y->deg)) && ((uint16)0U == (y->val[0]))))
    {
        /* MOD : For the elimination of pointer arithmetic. */
        z->deg = 0u;
        z->val[0] = 0u;
    }
    else
    {
        /* Assign the maximum value of the most significant byte of the multiplication result to deg of variable z
           and clear variable z */
        z->deg = x->deg + y->deg + (uint16) 1;
        /* MOD : For the elimination of pointer arithmetic. */
        for (counterA = 0u; counterA <= z->deg; counterA++)
        {
            /* MOD : For the elimination of pointer arithmetic. */
            z->val[counterA] = 0u;
           
            /* RSA Library Cancel Reqest Check */
            if (g_rsa_cancel_req == RSA_CANCEL)
            {
                break;   /* RSA Library Cancel Return */
            }
            else
            {
                /* Do nothing */
            }
        }
 
        /* Multiplication process */
        /* MOD : For the elimination of pointer arithmetic. */
        for (counterA = 0u; counterA <= x->deg; counterA++)
        {
            mul = 0u;
            /* MOD : For the elimination of pointer arithmetic. */
            for (counterB = 0u; counterB <= y->deg; counterB++)
            {
                /* MOD : For the elimination of pointer arithmetic. */
                mul += ((MCMC) (x->val[counterA]) * (MCMC) (y->val[counterB]));
                mul += (MCMC) (z->val[counterA + counterB]);
                z->val[counterA + counterB] = (MC) (mul & MC_MASK);
                mul >>= MC_BASE;
 
                /* RSA Library Cancel Reqest Check */
                if (g_rsa_cancel_req == RSA_CANCEL)
                {
                    break;   /* RSA Library Cancel Return */
                }
                else
                {
                    /* Do nothing */
                }
            }
            /* MOD : For the elimination of pointer arithmetic. */
            z->val[(counterA + y->deg) + (uint16)1u] = (MC) mul;
           
            /* RSA Library Cancel Reqest Check */
            if (g_rsa_cancel_req == RSA_CANCEL)
            {
                break;   /* RSA Library Cancel Return */
            }
            else
            {
                /* Do nothing */
            }
        }
 
        /* When the most significant carry is 0, the most significant byte is reduced by 1. */
        if (mul == 0u)
        {
            z->deg--;
        }
        else
        {
            /* Do nothing */
        }
    }
} /* End of function r_mc_mull() */
 
/******************************************************************************/
/* Declaration  : void r_mc_sqrl(MC_int *x, MC_int *z)
/* Function Name: r_mc_sqrl
/* Description  : Square of multiple length variables.
/* Arguments    : x Value to be squared.
/*                z Calculation result of squaring x.
/* Return Value : none.
/******************************************************************************/
static void r_mc_sqrl(MC_int *x, MC_int *z)
{
    MCMC    mul;
    MCMC    sum;
    MCMC    carry;
    uint16  counterA;
    uint16  counterB;
 
    /* MOD : For the elimination of pointer arithmetic. */
    if (((uint16)0U == (x->deg)) && ((uint16)0U == x->val[0]))
    {
        /* MOD : For the elimination of pointer arithmetic. */
        z->deg = 0u;
        z->val[0] = 0u;
    }
    else
    {
        z->deg = (uint16) ((x->deg << 1u) + (uint16) 1u);
        /* MOD : For the elimination of pointer arithmetic. */
        for (counterA = 0u; counterA <= z->deg; counterA++)
        {
            /* MOD : For the elimination of pointer arithmetic. */
            z->val[counterA] = 0u;
        }
 
        for (counterA = 0u; counterA <= x->deg; counterA++)
        { /* To calculate from the end of the data, use a down counter. */
            mul = 0u;
            carry = 0u;
            for (counterB = (uint16)0u; counterB < counterA; counterB++)
            {
                /* MOD : For the elimination of pointer arithmetic. */
                sum = (MCMC)(x->val[counterA]) * (MCMC)(x->val[counterB]);
                mul += (MCMC)((sum + (MCMC)(z->val[counterA + counterB])));
                sum += carry;
                mul += sum;
                if (mul < sum)
                {
                    carry = (MCMC)1u << MC_BASE;
                }
                else
                {
                    carry = 0u;
                }
 
                /* MOD : For the elimination of pointer arithmetic. */
                z->val[counterA + counterB] = (MC)(mul & MC_MASK);
                mul >>= MC_BASE;
 
                /* RSA Library Cancel Reqest Check */
                if (g_rsa_cancel_req == RSA_CANCEL)
                {
                    break;   /* RSA Library Cancel Return */
                }
                else
                {
                    /* Do nothing */
                }
            }
 
 
            /* MOD : For the elimination of pointer arithmetic. */
            mul += ((MCMC)(x->val[counterA]) * (MCMC)(x->val[counterB]));
            mul += (MCMC)(carry + (MCMC)(z->val[counterA + counterB]));
            z->val[counterA + counterB] = (MC)(mul & MC_MASK);
            mul >>= MC_BASE;
            z->val[counterA + counterB + (uint16)1u] = (MC)mul;
 
            /* RSA Library Cancel Reqest Check */
            if (g_rsa_cancel_req == RSA_CANCEL)
            {
                break;   /* RSA Library Cancel Return */
            }
            else
            {
                /* Do nothing */
            }
        }
 
        if (mul == 0u)
        {
            z->deg--;
        }
        else
        {
            /* Do nothing */
        }
 
    }
} /* End of function r_mc_sqrl() */
 
/******************************************************************************/
/* Declaration  : void r_mc_reml(MC_int *x, MC_int *y, MC_int *r)
/* Function Name: r_mc_reml
/* Description  : Surplus calculation of multiple length variables.
/* Arguments    : x Variable to divide.
/*                y Variable to be divided.
/*                r Calculation result.
/* Return Value : none.
/******************************************************************************/
static void r_mc_reml(MC_int *x, MC_int *y, MC_int *r)
{
    MCMC    rsa_div;
    MCMC    div_temp;
    MCMC    mul;
    MC      quo;
    uint16  counterA;
    uint16  counterB;
    uint16  sft;
    uint16  deg;
 
    /* The MC unit is smaller than the remainder x */
    if (y->deg < x->deg)
    {
        r_mc_movl(y, r);
    }
    else
    {
        deg = y->deg - x->deg;
 
        /* x is 1MC units remainder calculation */
        if (x->deg == 0u)
        {
            r->deg = 0u;
            /* MOD : For the elimination of pointer arithmetic. */
            r->val[0] = r_mc_rems(x->val[0], y);
        }
        else
        {
            /* Find the most significant bit of x for remainder calculation */
            for (sft = MC_BASE; sft > 0u; sft--)
            {
                if ((x->val[x->deg] & (MC)(1u << (sft - (uint16) 1u))) != 0u)
                {
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }
 
            /* MOD : For the elimination of pointer arithmetic. */
            rsa_div = x->val[x->deg];
            for (counterA = x->deg; counterA > 0u; counterA--)
            { /* To calculate from the end of the data, use a down counter. */
                /* MOD : For the elimination of pointer arithmetic. */
                rsa_div <<= MC_BASE;
                rsa_div ^= x->val[counterA - (uint16)1u];
                /* MOD : Measures for not using runtime libraries. */
                div_temp = r_mc_lshr(rsa_div, sft);
                x->val[counterA] = (MC)(div_temp & MC_MASK);
 
                /* RSA Library Cancel Reqest Check */
                if (g_rsa_cancel_req == RSA_CANCEL)
                {
                    break;   /* RSA Library Cancel Return */
                }
                else
                {
                    /* Do nothing */
                }
            }
            /* MOD : Measures for not using runtime libraries. */
            div_temp = r_mc_lshl(rsa_div, ((uint16)MC_BASE - sft));
            /* MOD : For the elimination of pointer arithmetic. */
            x->val[0] = (MC)(div_temp & MC_MASK);
 
            rsa_div = 0u;
            for (counterA = y->deg + 1u; counterA > 0u; counterA--)
            { /* To calculate from the end of the data, use a down counter. */
                /* MOD : For the elimination of pointer arithmetic. */
                rsa_div ^= (MCMC)y->val[counterA - (uint16)1u];
                /* MOD : Measures for not using runtime libraries. */
                div_temp = r_mc_lshr(rsa_div, sft);
                r->val[counterA] = (MC)(div_temp & MC_MASK);
                rsa_div <<= MC_BASE;
 
                /* RSA Library Cancel Reqest Check */
                if (g_rsa_cancel_req == RSA_CANCEL)
                {
                    break;   /* RSA Library Cancel Return */
                }
                else
                {
                    /* Do nothing */
                }
            }
            /* MOD : Measures for not using runtime libraries. */
            div_temp = r_mc_lshr(rsa_div, sft);
            /* MOD : For the elimination of pointer arithmetic. */
            r->val[0] = (MC)(div_temp & MC_MASK);
           
            for (counterA = deg + 1u; counterA > 0u; counterA--)
            { /* To calculate from the end of the data, use a down counter. */
                /* MOD : For the elimination of pointer arithmetic. */
                rsa_div = (MCMC) r->val[x->deg + counterA];
                if (rsa_div == x->val[x->deg])
                {
                    quo = MC_MASK;
                }
                else
                {
                    /* MOD : For the elimination of pointer arithmetic. */
                    rsa_div <<= MC_BASE;
                    rsa_div ^= (MCMC)r->val[(x->deg + counterA) - (uint16)1u];
                    quo = (MC)(rsa_div / x->val[x->deg]);
                    rsa_div -= ((MCMC)quo * (MCMC)x->val[x->deg]);
                    rsa_div <<= MC_BASE;
                    rsa_div ^= (MCMC)r->val[(x->deg + counterA) - (uint16)2u];
                    mul = (MCMC)quo * (MCMC)x->val[x->deg - (uint16)1u];
                    if (mul > rsa_div)
                    {
                        mul -= rsa_div;
                        quo--;
                        /* MOD : For the elimination of pointer arithmetic. */
                        rsa_div = (MCMC)x->val[x->deg] << MC_BASE;
                        if (mul > (rsa_div + x->val[x->deg - (uint16)1u]))
                        {
                            quo--;
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    }
                    else
                    {
                        /* Do nothing */
                    }
 
                    /* RSA Library Cancel Reqest Check */
                    if (g_rsa_cancel_req == RSA_CANCEL)
                    {
                        break;   /* RSA Library Cancel Return */
                    }
                    else
                    {
                        /* Do nothing */
                    }
                }
               
                rsa_div = 0u;
                mul = 0u;
 
                for (counterB = 0u; counterB < x->deg + 1u; counterB++)
                {
                    /* MOD : For the elimination of pointer arithmetic. */
                    mul += ((MCMC)quo * (MCMC)x->val[counterB]);
                    rsa_div += (MCMC)r->val[(counterA + counterB) - (uint16)1u];
                    rsa_div -= (MCMC)(mul & MC_MASK);
                    r->val[(counterA + counterB) - (uint16)1u] = (MC)(rsa_div & MC_MASK);
                    mul >>= MC_BASE;
                    rsa_div >>= MC_BASE;
                    rsa_div ^= (rsa_div << MC_BASE);  /* OH! MESSIVE */
 
                    /* RSA Library Cancel Reqest Check */
                    if (g_rsa_cancel_req == RSA_CANCEL)
                    {
                        break;   /* RSA Library Cancel Return */
                    }
                    else
                    {
                        /* Do nothing */
                    }
                }
                /* MOD : For the elimination of pointer arithmetic. */
                rsa_div += (MCMC)r->val[(counterA + counterB) - (uint16)1u];
                rsa_div -= (MCMC)(mul & MC_MASK);
                r->val[(counterA + counterB) - (uint16)1u] = (MC)(rsa_div & MC_MASK);
                rsa_div >>= MC_BASE;
 
                if (rsa_div != 0u)
                {
                    rsa_div = 0u;
 
                    for (counterB = 0u; counterB < x->deg + 1u; counterB++)
                    {
                        /* MOD : For the elimination of pointer arithmetic. */
                        rsa_div += (MCMC)r->val[(counterA + counterB) - (uint16)1u];
                        rsa_div += (MCMC)x->val[counterB];
                        r->val[(counterA + counterB) - (uint16)1u] = (MC)(rsa_div & MC_MASK);
                        rsa_div >>= MC_BASE;
 
                        /* RSA Library Cancel Reqest Check */
                        if (g_rsa_cancel_req == RSA_CANCEL)
                        {
                            break;   /* RSA Library Cancel Return */
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    }
                    /* MOD : For the elimination of pointer arithmetic. */
                    r->val[(counterA + counterB) - (uint16)1u] += (MC)rsa_div;
                }
                else
                {
                    /* Do nothing */
                }
            }
 
            /* MOD : For the elimination of pointer arithmetic. */
            rsa_div = x->val[x->deg];
            /* MOD : Measures for not using runtime libraries. */
            div_temp = r_mc_lshr(rsa_div, (MC_BASE - sft));
            x->val[x->deg] = (MC)(div_temp & MC_MASK);
 
            for (counterA = x->deg; counterA > 0u; counterA--)
            { /* To calculate from the end of the data, use a down counter. */
                rsa_div <<= MC_BASE;
                rsa_div ^= (MCMC)x->val[counterA - (uint16)1u];
                /* MOD : Measures for not using runtime libraries. */
                div_temp = r_mc_lshr(rsa_div, (MC_BASE - sft));
                x->val[counterA - (uint16)1u] = (MC)(div_temp & MC_MASK);
 
                /* RSA Library Cancel Reqest Check */
                if (g_rsa_cancel_req == RSA_CANCEL)
                {
                    break;   /* RSA Library Cancel Return */
                }
                else
                {
                    /* Do nothing */
                }
            }
 
            /* MOD : For the elimination of pointer arithmetic. */
            rsa_div = r->val[0];
            for (counterA = 0; counterA < x->deg; counterA++)
            {
                /* MOD : For the elimination of pointer arithmetic. */
                rsa_div ^= ((MCMC)r->val[counterA+1] << MC_BASE);
                /* MOD : Measures for not using runtime libraries. */
                div_temp = r_mc_lshr(rsa_div, (MC_BASE - sft));
                r->val[counterA] = (MC)div_temp;
                rsa_div >>= MC_BASE;
 
                /* RSA Library Cancel Reqest Check */
                if (g_rsa_cancel_req == RSA_CANCEL)
                {
                    break;   /* RSA Library Cancel Return */
                }
                else
                {
                    /* Do nothing */
                }
            }
            /* MOD : Measures for not using runtime libraries. */
            div_temp = r_mc_lshr(rsa_div, (MC_BASE - sft));
            /* MOD : For the elimination of pointer arithmetic. */
            r->val[counterA] = (MC)div_temp;
 
            for (counterA = x->deg; counterA > (uint16)0U; counterA--)
            { /* Find the position of the first non-zero data from the end. */
                /* MOD : For the elimination of pointer arithmetic. */
                if (r->val[counterA] != 0u)
                {
                    break;
                }
                else
                {
                    /* Do nothing */
                }
               
 
                /* RSA Library Cancel Reqest Check */
                if (g_rsa_cancel_req == RSA_CANCEL)
                {
                    break;   /* RSA Library Cancel Return */
                }
                else
                {
                    /* Do nothing */
                }
            }
            r->deg = counterA;
        }
    }
} /* End of function r_mc_reml() */
 
/******************************************************************************/
 * Declaration  : MC MC_KWD r_mc_rems(MC x, MC_int *y)
 * Function Name: r_mc_rems
 * Description  : Surplus calculation of multiple length variables.
 * Arguments    : x the value to divide y.
 *                y The value to be divided.
 * Return Value : MC, Remainder operation result.
/******************************************************************************/
static MC MC_KWD r_mc_rems(MC x, MC_int *y)
{
    MCMC    rem;
    uint16  counter;
    uint16  valuer_idx;
 
    rem = 0u;
 
    for (counter = y->deg + 1u; counter > 0u; counter--)
    { /* To calculate from the end of the data, use a down counter. */
        /* MOD : For the elimination of pointer arithmetic. */
        valuer_idx = counter - 1u;
        rem ^= (MCMC) (y->val[valuer_idx]);
        rem %= (MCMC) x;
        rem <<= MC_BASE;
 
        /* RSA Library Cancel Reqest Check */
        if (g_rsa_cancel_req == RSA_CANCEL)
        {
            break;   /* RSA Library Cancel Return */
        }
        else
        {
            /* Do nothing */
        }
    }
 
    return (MC) (rem >> MC_BASE);
} /* End of function r_mc_rems() */
 
/******************************************************************************/
/* Declaration  : uint8 r_mc_powm(MC_int *x, MC_int *y, MC_int *z, MC_int *m, uint8 *mc_memory0, uint8 *mc_memory1)
/* Function Name: r_mc_powm
/* Description  : Modular exponentiation (z = x^y mod m).
/* Arguments    : x Variable x.
/*                y Variable y.
/*                z Calculation result z.
/*                m Variable m.
/* Return Value : -3 Input value is incorrect
/*                -1 Memory allocation failure
/*                0 Normal end
/******************************************************************************/
uint8 r_mc_powm(MC_int *x, MC_int *y, MC_int *z, MC_int *m, MC *mc_memory0, MC *mc_memory1)
{
    MC_int  rsa_pow;
    MC_int  tmp;
    uint16  c;
    uint16  counterA;
    uint16  counterB;
    uint8   mc_ret = MC_ERR;
 
    rsa_pow.val = mc_memory0; /* object is holds the even alignment */
    rsa_pow.len = MC_INT_ARRAY_LENGTH;
 
    tmp.val = mc_memory1; /* object is holds the even alignment */
    tmp.len = MC_INT_ARRAY_LENGTH;
 
    r_mc_movl(x, &rsa_pow);
 
    z->deg = 0u;
    z->val[0] = 1u;
 
    for (counterA = (uint16)0u; counterA < y->deg; counterA++)
    {
        for (counterB = (uint16)0u; counterB < (uint16)MC_BASE; counterB++)
        {
 
            if ((y->val[counterA] & (MC)(1u << counterB)) != 0u)
            {
                r_mc_mull(z, &rsa_pow, &tmp); /* tmp = z * rsa_pow */
                r_mc_reml(m, &tmp, z); /* z = tmp mod m */
            }
            else
            {
                /* Do nothing */
            }
            r_mc_sqrl(&rsa_pow, &tmp); /* tmp = rsa_pow^2 */
            r_mc_reml(m, &tmp, &rsa_pow); /* rsa_pow = tmp mod m */
 
            /* RSA Library Cancel Reqest Check */
            if (g_rsa_cancel_req == RSA_CANCEL)
            {
                break;   /* RSA Library Cancel Return */
            }
            else
            {
                /* Do nothing */
            }
        }
    }
 
    for (c = y->val[y->deg]; c != (MC) 0u ; c >>= 1u)
    {
 
        if ((c & (MC) 1u) != 0u)
        {
            r_mc_mull(z, &rsa_pow, &tmp); /* tmp = rsa_pow * z */
            r_mc_reml(m, &tmp, z); /* z = tmp mod m */
        }
        else
        {
            /* Do nothing */
        }
        r_mc_sqrl(&rsa_pow, &tmp); /* tmp = rsa_pow^2 */
        r_mc_reml(m, &tmp, &rsa_pow); /* rsa_pow = tmp mod m */
 
        /* RSA Library Cancel Reqest Check */
        if (g_rsa_cancel_req == RSA_CANCEL)
        {
            break;   /* RSA Library Cancel Return */
        }
        else
        {
            /* Do nothing */
        }
    }
 
    if (g_rsa_cancel_req == RSA_CANCEL)
    {
        mc_ret = MC_ERR;    /* RSA Library Cancel Return */
    }
    else
    {
        mc_ret = MC_OK;
    }
 
    return mc_ret;
 
} /* End of function r_mc_powm() */
 
/******************************************************************************/
/* Declaration  : static MCMC r_mc_lshl(MCMC rsa_div, uint16 n)
/* Function Name: r_mc_lshl
/* Description  : Calculate left shift for 32bit variable.
/*                Added as a measure to avoid using runtime libraries.
/* Arguments    : rsa_div 32bit variable
/*                n shift value
/* Return Value : MCMC left shifted variable
/******************************************************************************/
static MCMC r_mc_lshl(MCMC rsa_div, uint16 n)
{
    MCMC   rsa_result;
    uint16 reg_high;
    uint16 reg_low;
 
    if ( (uint16)0U == ( n / (uint16)16U ) ) {
        /* 0 <= n < 16 */
        /* Split the 32bit 'rsa_div' into the 16bit 'reg_high' and 'reg_low' */
        reg_high = (uint16)(rsa_div >> 16U);
        reg_low = (uint16)rsa_div;
 
        /* Perform left shift operations on the upper 16bits and the lower 16bits separately */
        reg_high = (reg_high << n) | (reg_low >> ( (uint16)16U - n ));
        reg_low = reg_low << n;
 
        /* Combine the upper 16bits and the lower 16bits */
        rsa_result = ((uint32)reg_high << 16U) | (uint32)reg_low;
    } else if ( (uint16)1U == ( n / (uint16)16U ) ) {
        /* 16 <= n < 32 */
        reg_low = (uint16)rsa_div;
 
        reg_high = reg_low << ( n % (uint16)16U );
 
        rsa_result = (uint32)reg_high << 16U;
    } else {
        /* n >= 32 */
        rsa_result = 0U;
    }
 
    return rsa_result;
} /* End of function r_mc_lshl() */
 
/******************************************************************************/
/* Declaration  : static MCMC r_mc_lshr(MCMC rsa_div, uint16 n)
/* Function Name: r_mc_lshr
/* Description  : Calculate right shift for 32bit variable.
/*                Added as a measure to avoid using runtime libraries.
/* Arguments    : rsa_div 32bit variable
/*                n shift value
/* Return Value : MCMC right shifted variable
/******************************************************************************/
static MCMC r_mc_lshr(MCMC rsa_div, uint16 n)
{
    MCMC   rsa_result;
    uint16 reg_high;
    uint16 reg_low;
 
    if ( (uint16)0U == ( n / (uint16)16U ) ) {
        /* 0 <= n < 16 */
        /* Split the 32bit 'rsa_div' into the 16bit 'reg_high' and 'reg_low' */
        reg_high = (uint16)(rsa_div >> 16U);
        reg_low = (uint16)rsa_div;
 
        /* Perform right shift operations on the upper 16bits and the lower 16bits separately */
        reg_low = (reg_low >> n) | (reg_high << ((uint16)16U - n));
        reg_high = reg_high >> n;
 
        /* Combine the upper 16bits and the lower 16bits */
        rsa_result = ((uint32)reg_high << 16U) | (uint32)reg_low;
    } else if ( (uint16)1U == ( n / (uint16)16 ) ) {
        /* 16 <= n < 32 */
        reg_high = (uint16)(rsa_div >> 16U);
 
        reg_low = reg_high >> ( n % (uint16)16U );
 
        rsa_result = (uint32)reg_low;
    } else {
        /* n >= 32 */
        rsa_result = 0U;
    }
 
    return rsa_result;
} /* End of function r_mc lshr() */
#define CRYPTO_STOP_SEC_CODE_LOCAL
#include "Crypto_MemMap.h"
 
 