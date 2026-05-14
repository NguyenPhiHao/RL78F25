/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR MCAL                                                 */
/* File Name   : intvect.c                                                    */
/* Version     : v1.00.02                                                     */
/* Contents    : Sample vector table.                                         */
/* Author      : --                                                           */
/* Note        : --                                                           */
/* History     : --                                                           */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "SampleAdc.h"
#include "SampleGpt.h"
#include "SampleWdg.h"
#include "SamplePwm.h"
#include "SampleIcu.h"
#include "SampleLin.h"
#include "SampleSpi.h"
#include "SampleCan.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* macros                                                                     */
/*----------------------------------------------------------------------------*/
#define INT0004                         0x0004  /* INTWDTI */
#define INT0006                         0x0006  /* INTLVI */
#define INT0008                         0x0008  /* INTP0 */
#define INT000A                         0x000A  /* INTP1 */
#define INT000C                         0x000C  /* INTP2 */
#define INT000E                         0x000E  /* INTP3 */
#define INT0010                         0x0010  /* INTP4, INTSPM */
#define INT0012                         0x0012  /* INTP5, INTCMP0 */
#define INT0014                         0x0014  /* INTP13, INTCLM */
#define INT0016                         0x0016  /* INTST0/INTCSI00/INTIIC00 */
#define INT0018                         0x0018  /* INTSR0/INTCSI01/INTIIC01 */
#define INT001A                         0x001A  /* INTTRD0 */
#define INT001C                         0x001C  /* INTTRD1 */
#define INT001E                         0x001E  /* INTTRJ0 */
#define INT0020                         0x0020  /* INTRAM */
#define INT0022                         0x0022  /* INTCTSUWR */
#define INT0024                         0x0024  /* INTCTSURD */
#define INT0026                         0x0026  /* INTCTSUFN */
#define INT0028                         0x0028  /* INTIICA0 */
#define INT002A                         0x002A  /* INTP8, INTRTC */
#define INT002C                         0x002C  /* INTTM00 */
#define INT002E                         0x002E  /* INTTM01, INTLIN2TRM */
#define INT0030                         0x0030  /* INTTM02, INTLIN2RVC */
#define INT0032                         0x0032  /* INTTM03, INTLIN2STA/INTLIN2 */
#define INT0034                         0x0034  /* INTAD */
#define INT0036                         0x0036  /* INTP6, INTLIN2WUP, INTTM11H */
#define INT0038                         0x0038  /* INTP7, INTTM13H */
#define INT003A                         0x003A  /* INTP9, INTTM01H */
#define INT003C                         0x003C  /* INTP10, INTTM03H */
#define INT003E                         0x003E  /* INTST1/INTCSI10/INTIIC10 */
#define INT0040                         0x0040  /* INTSR1/INTCSI11/INTIIC11 */
#define INT0042                         0x0042  /* INTTM04 */
#define INT0044                         0x0044  /* INTTM05, INTLIN0TRM */
#define INT0046                         0x0046  /* INTTM06, INTLIN0RVC */
#define INT0048                         0x0048  /* INTTM07, INTLIN0STA/INTLIN0 */
#define INT004A                         0x004A  /* INTP11, INTLIN0WUP */
#define INT004C                         0x004C  /* INTTM10  */
#define INT004E                         0x004E  /* INTTM11, INTLIN1TRM */
#define INT0050                         0x0050  /* INTTM12, INTLIN1RVC  */
#define INT0052                         0x0052  /* INTTM13, INTLIN1STA/INTLIN1 */
#define INT0058                         0x0058  /* INTADGB  */
#define INT005A                         0x005A  /* INTROM  */
#define INT005C                         0x005C  /* INTKR, INTRCAN0GRVC  */
#define INT005E                         0x005E  /* INTRCAN0ERR  */
#define INT0060                         0x0060  /* INTRCAN0WUP */
#define INT0064                         0x0064  /* INTRCAN0CFR */
#define INT0066                         0x0066  /* INTRCAN0TRM */
#define INT0068                         0x0068  /* INTRCAN0GRFR */
#define INT006A                         0x006A  /* INTRCAN0GERR */
#define INT006C                         0x006C  /* INTP12, INTLIN1WUP  */
#define INT006E                         0x006E  /* INTRCAN1GRFR */
#define INT0070                         0x0070  /* INTRCAN1GERR */
#define INT0072                         0x0072  /* INTRCAN1WUP */
#define INT0074                         0x0074  /* INTTM14, INTRCAN1GRVC */
#define INT0076                         0x0076  /* INTTM15, INTRCAN1ERR */
#define INT0078                         0x0078  /* INTTM16, INTRCAN1CFR */
#define INT007A                         0x007A  /* INTTM17, INTRCAN1TRM */
#define INT007C                         0x007C  /* INTCRAM  */

/* Interrupt source determination flag registers */
#define INTFLG0     (*(volatile uint8 QL_70_NEAR *)0x0079)
#define INTFLG1     (*(volatile uint8 QL_70_NEAR *)0x007D)
#define INTFLG2     (*(volatile uint8 QL_70_NEAR *)0x01F2)
#define INTFLG3     (*(volatile uint8 QL_70_NEAR *)0x01F3)

/* Interrupt source determination flag bits */
#define INTFLG00    (0x01)  /* INTP4 interrupt at vector table address 0x0010 */
#define INTFLG01    (0x02)  /* INTP5 interrupt at vector table address 0x0012 */
#define INTFLG02    (0x04)  /* INTP8 interrupt at vector table address 0x002A */
#define INTFLG06    (0x40)  /* INTCMP0 interrupt at vector table address 0x0012 */
#define INTFLG07    (0x80)  /* INTP13 interrupt at vector table address 0x0014 */
#define INTFLG11    (0x02)  /* INTTM01 interrupt at vector table address 0x002E */
#define INTFLG12    (0x04)  /* INTTM02 interrupt at vector table address 0x0030 */
#define INTFLG13    (0x08)  /* INTTM03 interrupt at vector table address 0x0032 */
#define INTFLG15    (0x20)  /* INTTM05 interrupt at vector table address 0x0044 */
#define INTFLG16    (0x40)  /* INTTM06 interrupt at vector table address 0x0046 */
#define INTFLG17    (0x80)  /* INTTM07 interrupt at vector table address 0x0048 */
#define INTFLG21    (0x02)  /* INTTM11 interrupt at vector table address 0x004E */
#define INTFLG22    (0x04)  /* INTTM12 interrupt at vector table address 0x0050 */
#define INTFLG23    (0x08)  /* INTTM13 interrupt at vector table address 0x0052 */
#define INTFLG24    (0x10)  /* INTTM14 interrupt at vector table address 0x0074 */
#define INTFLG25    (0x20)  /* INTTM15 interrupt at vector table address 0x0076 */
#define INTFLG26    (0x40)  /* INTTM16 interrupt at vector table address 0x0078 */
#define INTFLG27    (0x80)  /* INTTM17 interrupt at vector table address 0x007A */
#define INTFLG32    (0x04)  /* INTRCAN1GRVC interrupt at vector table address 0x0074 */
#define INTFLG33    (0x08)  /* INTRCAN1ERR interrupt at vector table address 0x0076 */
#define INTFLG34    (0x10)  /* INTRCAN1CFR interrupt at vector table address 0x0078 */
#define INTFLG35    (0x20)  /* INTRCAN1TRM interrupt at vector table address 0x007A */

/* Input switch control register */
#define ISC         (*(volatile uint8 QL_70_NEAR *)0x0073)

/* Input switch control bit */
#define ISC0        (0x01)  /* ISC0 */
#define ISC2        (0x04)  /* ISC2 */
#define ISC3        (0x08)  /* ISC3 */
#define ISC4        (0x10)  /* ISC4 */

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern void Adc_70_Isr_INTAD( void );
extern void Adc_70_Isr_INTADGB( void );
extern void Icu_70_Isr_INTP4( void );
extern void Icu_70_Isr_INTP13( void );
extern void Icu_70_Isr_TRD0( void );
extern void Icu_70_Isr_TRD1( void );
extern void Icu_70_Isr_TAU07( void );
extern void Icu_70_Isr_TAU17( void );
extern void Spi_70_Isr_HW00_SndRcvIntr( void );
extern void Spi_70_Isr_HW01_SndRcvIntr( void );
extern void Spi_70_Isr_HW10_SndRcvIntr( void );
extern void Spi_70_Isr_HW11_SndRcvIntr( void );
extern void Pwm_70_Isr_TRD00( void );
extern void Pwm_70_Isr_TAU00( void );
extern void Pwm_70_Isr_TAU01( void );
extern void Pwm_70_Isr_TAU10( void );
extern void Pwm_70_Isr_TAU11( void );
extern void Gpt_70_Isr_TRD_0_CH1( void );
extern void Gpt_70_Isr_TRJ_0_CH0( void );
extern void Gpt_70_Isr_TAU_0_CH0( void );
extern void Gpt_70_Isr_TAU_0_CH1( void );
extern void Gpt_70_Isr_TAU_1_CH4( void );
extern void Mcu_70_RamStateIsr( void );
extern void Lin_70_Isr_TxCh0( void );
extern void Lin_70_Isr_RxCh0( void );
extern void Lin_70_Isr_ErrCh0( void );
extern void Lin_70_Isr_WakeupCh0( void );
extern void Lin_70_Isr_WakeupCh1( void );
extern void Lin_70_Isr_TxCh1( void );
extern void Lin_70_Isr_RxCh1( void );
extern void Lin_70_Isr_ErrCh1( void );
extern void Lin_70_Isr_WakeupCh2( void );
extern void Lin_70_Isr_TxCh2( void );
extern void Lin_70_Isr_RxCh2( void );
extern void Lin_70_Isr_ErrCh2( void );
extern void Wdg_70_TimerIsr( void );

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
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
/* INT0004 */
#pragma interrupt Sample_Isr_INT0004( vect=INT0004 )
void Sample_Isr_INT0004( void ) {
#if ( SAMPLE_WDG_ENABLE != FALSE )
    Wdg_70_TimerIsr();
#endif


}


/* INT0006 */
#pragma interrupt Sample_Isr_INT0006( vect=INT0006 )
void Sample_Isr_INT0006( void ) {


}


/* INT0008 */
#pragma interrupt Sample_Isr_INT0008( vect=INT0008 )
void Sample_Isr_INT0008( void ) {


}


/* INT000A */
#pragma interrupt Sample_Isr_INT000A( vect=INT000A )
void Sample_Isr_INT000A( void ) {


}


/* INT000C */
#pragma interrupt Sample_Isr_INT000C( vect=INT000C )
void Sample_Isr_INT000C( void ) {


}


/* INT000E */
#pragma interrupt Sample_Isr_INT000E( vect=INT000E )
void Sample_Isr_INT000E( void ) {


}


/* INT0010 */
#pragma interrupt Sample_Isr_INT0010( vect=INT0010 )
void Sample_Isr_INT0010( void ) {
    uint8   intFlg0;

    /* Get interrupt source determination flag. */
    intFlg0 = INTFLG0;

    if ( INTFLG00 == ( intFlg0 & INTFLG00 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG0 = (uint8)(~INTFLG00);

        /* INTP4 interrupt process */
#if ( SAMPLE_ICU_ENABLE != FALSE )
        Icu_70_Isr_INTP4();
#endif
    } else {
        /* INTSPM interrupt process */
    }
}


/* INT0012 */
#pragma interrupt Sample_Isr_INT0012( vect=INT0012 )
void Sample_Isr_INT0012( void ) {
    uint8   intFlg0;

    /* Get interrupt source determination flag. */
    intFlg0 = INTFLG0;

    if ( INTFLG01 == ( intFlg0 & INTFLG01 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG0 = (uint8)(~INTFLG01);
 
        /* INTP5 interrupt process */
    } else if ( INTFLG06 == ( intFlg0 & INTFLG06 ) ) {
        INTFLG0 = (uint8)(~INTFLG06);   /* Clear interrupt */

        /* INTCMP0 interrupt process */
    }
}


/* INT0014 */
#pragma interrupt Sample_Isr_INT0014( vect=INT0014 )
void Sample_Isr_INT0014( void ) {
    uint8   intFlg0;

    /* Get interrupt source determination flag. */
    intFlg0 = INTFLG0;

    if ( INTFLG07 == ( intFlg0 & INTFLG07 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG0 = (uint8)(~INTFLG07);

        /* INTP13 interrupt process */
#if ( SAMPLE_ICU_ENABLE != FALSE )
        Icu_70_Isr_INTP13();
#endif
    } else {
        /* INTCLM interrupt process */
    }
}


/* INT0016 */
#pragma interrupt Sample_Isr_INT0016( vect=INT0016 )
void Sample_Isr_INT0016( void ) {
#if ( SAMPLE_SPI_ENABLE != FALSE )
    Spi_70_Isr_HW00_SndRcvIntr();
#endif


}


/* INT0018 */
#pragma interrupt Sample_Isr_INT0018( vect=INT0018 )
void Sample_Isr_INT0018( void ) {
#if ( SAMPLE_SPI_ENABLE != FALSE )
    Spi_70_Isr_HW01_SndRcvIntr();
#endif


}


/* INT001A */
#pragma interrupt Sample_Isr_INT001A( vect=INT001A )
void Sample_Isr_INT001A( void ) {
#if ( ( SAMPLE_PWM_ENABLE != FALSE ) && \
      ( SAMPLE_PWM_INTERRUPT_ENABLE != FALSE ) )
    Pwm_70_Isr_TRD00();
#endif

#if ( SAMPLE_PWM_ENABLE == FALSE )
#if ( SAMPLE_ICU_ENABLE != FALSE )
    Icu_70_Isr_TRD0();
#endif
#endif

}


/* INT001C */
#pragma interrupt Sample_Isr_INT001C( vect=INT001C )
void Sample_Isr_INT001C( void ) {
#if ( SAMPLE_GPT_ENABLE != FALSE )
    Gpt_70_Isr_TRD_0_CH1();
#endif

#if ( SAMPLE_GPT_ENABLE == FALSE )
#if ( SAMPLE_ICU_ENABLE != FALSE )
    Icu_70_Isr_TRD1();
#endif
#endif


}


/* INT001E */
#pragma interrupt Sample_Isr_INT001E( vect=INT001E )
void Sample_Isr_INT001E( void ) {
#if ( SAMPLE_GPT_ENABLE != FALSE )
    Gpt_70_Isr_TRJ_0_CH0();
#endif

#if ( SAMPLE_ADC_ENABLE != FALSE )
    Gpt_70_Isr_TRJ_0_CH0();
#endif

}


/* INT0020 */
#pragma interrupt Sample_Isr_INT0020( vect=INT0020 )
void Sample_Isr_INT0020( void ) {
#if ( SAMPLE_MCU_ENABLE != FALSE )
    Mcu_70_RamStateIsr();
#endif


}


/* INT0022 */
#pragma interrupt Sample_Isr_INT0022( vect=INT0022 )
void Sample_Isr_INT0022( void ) {


}


/* INT0024 */
#pragma interrupt Sample_Isr_INT0024( vect=INT0024 )
void Sample_Isr_INT0024( void ) {


}


/* INT0026 */
#pragma interrupt Sample_Isr_INT0026( vect=INT0026 )
void Sample_Isr_INT0026( void ) {


}


/* INT0028 */
#pragma interrupt Sample_Isr_INT0028( vect=INT0028 )
void Sample_Isr_INT0028( void ) {


}


/* INT002A */
#pragma interrupt Sample_Isr_INT002A( vect=INT002A )
void Sample_Isr_INT002A( void ) {
    uint8   intFlg0;

    /* Get interrupt source determination flag. */
    intFlg0 = INTFLG0;

    if ( INTFLG02 == ( intFlg0 & INTFLG02 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG0 = (uint8)(~INTFLG02);

        /* INTP8 interrupt process */
    } else {
        /* INTRTC interrupt process */
    }
}


/* INT002C */
#pragma interrupt Sample_Isr_INT002C( vect=INT002C )
void Sample_Isr_INT002C( void ) {
#if ( SAMPLE_GPT_ENABLE != FALSE )
    Gpt_70_Isr_TAU_0_CH0();
#endif

#if ( ( ( SAMPLE_PWM_ENABLE != FALSE ) && \
      ( SAMPLE_PWM_INTERRUPT_ENABLE != FALSE ) ) || \
      ( SAMPLE_ICU_ENABLE != FALSE ) )
    Pwm_70_Isr_TAU00();
#endif


}


/* INT002E */
#pragma interrupt Sample_Isr_INT002E( vect=INT002E )
void Sample_Isr_INT002E( void ) {
    uint8   intFlg1;

    /* Get interrupt source determination flag. */
    intFlg1 = INTFLG1;

    if ( INTFLG11 == ( intFlg1 & INTFLG11 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG1 = (uint8)(~INTFLG11);

        /* INTTM01 interrupt process */
#if ( SAMPLE_GPT_ENABLE != FALSE )
        Gpt_70_Isr_TAU_0_CH1();
#endif

#if ( ( ( SAMPLE_PWM_ENABLE != FALSE ) && \
      ( SAMPLE_PWM_INTERRUPT_ENABLE != FALSE ) ) || \
      ( SAMPLE_ICU_ENABLE != FALSE ) )
        Pwm_70_Isr_TAU01();
#endif
    } else {
        /* INTLIN2TRM interrupt process */
#if ( SAMPLE_LIN_ENABLE != FALSE )
        Lin_70_Isr_TxCh2();
#endif
    }
}


/* INT0030 */
#pragma interrupt Sample_Isr_INT0030( vect=INT0030 )
void Sample_Isr_INT0030( void ) {
    uint8   intFlg1;

    /* Get interrupt source determination flag. */
    intFlg1 = INTFLG1;

    if ( INTFLG12 == ( intFlg1 & INTFLG12 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG1 = (uint8)(~INTFLG12);

        /* INTTM02 interrupt process */
    } else {
        /* INTLIN2RVC interrupt process */
#if ( SAMPLE_LIN_ENABLE != FALSE )
        Lin_70_Isr_RxCh2();
#endif
    }
}


/* INT0032 */
#pragma interrupt Sample_Isr_INT0032( vect=INT0032 )
void Sample_Isr_INT0032( void ) {
    uint8   intFlg1;

    /* Get interrupt source determination flag. */
    intFlg1 = INTFLG1;

    if ( INTFLG13 == ( intFlg1 & INTFLG13 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG1 = (uint8)(~INTFLG13);

        /* INTTM03 interrupt process */
    } else {
        /* INTLIN2STA/INTLIN2 interrupt process */
#if ( SAMPLE_LIN_ENABLE != FALSE )
        Lin_70_Isr_ErrCh2();
#endif
    }
}






/* INT0034 */
#pragma interrupt Sample_Isr_INT0034( vect=INT0034 )
void Sample_Isr_INT0034( void ) {
#if ( SAMPLE_ADC_ENABLE != FALSE )
    Adc_70_Isr_INTAD();
#endif


}


/* INT0036 */
#pragma interrupt Sample_Isr_INT0036( vect=INT0036 )
void Sample_Isr_INT0036( void ) {
    uint8   iscReg;
 
    /* Get input switch control register value. */
    iscReg = ISC;

    if ( ISC4 == ( iscReg & ISC4 ) ) {
        /* INTLIN2WUP interrupt process */
#if ( SAMPLE_LIN_ENABLE != FALSE )
        Lin_70_Isr_WakeupCh2();
#endif
    } else {
        /* INTP6 interrupt process */
    }
}


/* INT0038 */
#pragma interrupt Sample_Isr_INT0038( vect=INT0038 )
void Sample_Isr_INT0038( void ) {


}


/* INT003A */
#pragma interrupt Sample_Isr_INT003A( vect=INT003A )
void Sample_Isr_INT003A( void ) {


}


/* INT003C */
#pragma interrupt Sample_Isr_INT003C( vect=INT003C )
void Sample_Isr_INT003C( void ) {


}


/* INT003E */
#pragma interrupt Sample_Isr_INT003E( vect=INT003E )
void Sample_Isr_INT003E( void ) {
#if ( SAMPLE_SPI_ENABLE != FALSE )
    Spi_70_Isr_HW10_SndRcvIntr();
#endif


}


/* INT0040 */
#pragma interrupt Sample_Isr_INT0040( vect=INT0040 )
void Sample_Isr_INT0040( void ) {
#if ( SAMPLE_SPI_ENABLE != FALSE )
    Spi_70_Isr_HW11_SndRcvIntr();
#endif


}


/* INT0042 */
#pragma interrupt Sample_Isr_INT0042( vect=INT0042 )
void Sample_Isr_INT0042( void ) {


}


/* INT0044 */
#pragma interrupt Sample_Isr_INT0044( vect=INT0044 )
void Sample_Isr_INT0044( void ) {
    uint8   intFlg1;

    /* Get interrupt source determination flag. */
    intFlg1 = INTFLG1;

    if ( INTFLG15 == ( intFlg1 & INTFLG15 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG1 = (uint8)(~INTFLG15);

        /* INTTM05 interrupt process */
    } else {
        /* INTLIN0TRM interrupt process */
#if ( SAMPLE_LIN_ENABLE != FALSE )
        Lin_70_Isr_TxCh0();
#endif
    }
}


/* INT0046 */
#pragma interrupt Sample_Isr_INT0046( vect=INT0046 )
void Sample_Isr_INT0046( void ) {
    uint8   intFlg1;

    /* Get interrupt source determination flag. */
    intFlg1 = INTFLG1;

    if ( INTFLG16 == ( intFlg1 & INTFLG16 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG1 = (uint8)(~INTFLG16);

        /* INTTM06 interrupt process */
    } else {
        /* INTLIN0RVC interrupt process */
#if ( SAMPLE_LIN_ENABLE != FALSE )
        Lin_70_Isr_RxCh0();
#endif
    }
}


/* INT0048 */
#pragma interrupt Sample_Isr_INT0048( vect=INT0048 )
void Sample_Isr_INT0048( void ) {
    uint8   intFlg1;

    /* Get interrupt source determination flag. */
    intFlg1 = INTFLG1;

    if ( INTFLG17 == ( intFlg1 & INTFLG17 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG1 = (uint8)(~INTFLG17);

        /* INTTM07 interrupt process */
#if ( SAMPLE_ICU_ENABLE != FALSE )
        Icu_70_Isr_TAU07();
#endif
    } else {
        /* INTLIN0STA/INTLIN0 interrupt process */
#if ( SAMPLE_LIN_ENABLE != FALSE )
        Lin_70_Isr_ErrCh0();
#endif
    }
}


/* INT004A */
#pragma interrupt Sample_Isr_INT004A( vect=INT004A )
void Sample_Isr_INT004A( void ) {
    uint8   iscReg;

    /* Get input switch control register value. */
    iscReg = ISC;

    if ( ISC2 == ( iscReg & ISC2 ) ) {
        /* INTLIN0WUP interrupt process */
#if ( SAMPLE_LIN_ENABLE != FALSE )
        Lin_70_Isr_WakeupCh0();
#endif
    } else {
        /* INTP11 interrupt process */
    }
}


/* INT004C */
#pragma interrupt Sample_Isr_INT004C( vect=INT004C )
void Sample_Isr_INT004C( void ) {
#if ( ( ( SAMPLE_PWM_ENABLE != FALSE ) && \
      ( SAMPLE_PWM_INTERRUPT_ENABLE != FALSE ) ) || \
      ( SAMPLE_ICU_ENABLE != FALSE ) )
    Pwm_70_Isr_TAU10();
#endif


}


/* INT004E */
#pragma interrupt Sample_Isr_INT004E( vect=INT004E )
void Sample_Isr_INT004E( void ) {
    uint8   intFlg2;

    /* Get interrupt source determination flag. */
    intFlg2 = INTFLG2;

    if ( INTFLG21 == ( intFlg2 & INTFLG21 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG2 = (uint8)(~INTFLG21);

        /* INTTM11 interrupt process */
#if ( ( ( SAMPLE_PWM_ENABLE != FALSE ) && \
      ( SAMPLE_PWM_INTERRUPT_ENABLE != FALSE ) ) || \
      ( SAMPLE_ICU_ENABLE != FALSE ) )
        Pwm_70_Isr_TAU11();
#endif
    } else {
        /* INTLIN1TRM interrupt process */
#if ( SAMPLE_LIN_ENABLE != FALSE )
        Lin_70_Isr_TxCh1();
#endif
    }
}


/* INT0050 */
#pragma interrupt Sample_Isr_INT0050( vect=INT0050 )
void Sample_Isr_INT0050( void ) {
    uint8   intFlg2;

    /* Get interrupt source determination flag. */
    intFlg2 = INTFLG2;

    if ( INTFLG22 == ( intFlg2 & INTFLG22 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG2 = (uint8)(~INTFLG22);

        /* INTTM12 interrupt process */
    } else {
        /* INTLIN1RVC interrupt process */
#if ( SAMPLE_LIN_ENABLE != FALSE )
        Lin_70_Isr_RxCh1();
#endif
    }
}


/* INT0052 */
#pragma interrupt Sample_Isr_INT0052( vect=INT0052 )
void Sample_Isr_INT0052( void ) {
    uint8   intFlg2;

    /* Get interrupt source determination flag. */
    intFlg2 = INTFLG2;

    if ( INTFLG23 == ( intFlg2 & INTFLG23 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG2 = (uint8)(~INTFLG23);

        /* INTTM13 interrupt process */
    } else {
        /* INTLIN1STA/INTLIN1 interrupt process */
#if ( SAMPLE_LIN_ENABLE != FALSE )
        Lin_70_Isr_ErrCh0();
#endif
    }
}


/* INT0058 */
#pragma interrupt Sample_Isr_INT0058( vect=INT0058 )
void Sample_Isr_INT0058( void ) {
#if ( SAMPLE_ADC_ENABLE != FALSE )
    Adc_70_Isr_INTADGB();
#endif


}


/* INT005A */
#pragma interrupt Sample_Isr_INT005A( vect=INT005A )
void Sample_Isr_INT005A( void ) {


}


/* INT005C */
#pragma interrupt Sample_Isr_INT005C( vect=INT005C )
void Sample_Isr_INT005C( void ) {


}


/* INT005E */
#pragma interrupt Sample_Isr_INT005E( vect=INT005E )
void Sample_Isr_INT005E( void ) {
#if ( SAMPLE_CAN_ENABLE != FALSE )
    Can_70_Isr_ChannelError_CAN0();
#endif


}


/* INT0060 */
#pragma interrupt Sample_Isr_INT0060( vect=INT0060 )
void Sample_Isr_INT0060( void ) {
#if ( SAMPLE_CAN_ENABLE != FALSE )
#if ( ( CAN_70_WAKEUP_SUPPORT == TRUE ) && ( CAN_70_WAKEUP_INTERRUPT_PROCESSING == TRUE ) )
    Can_70_Isr_Wakeup_CAN0();
#endif
#endif


}


/* INT0064 */
#pragma interrupt Sample_Isr_INT0064( vect=INT0064 )
void Sample_Isr_INT0064( void ) {


}


/* INT0066 */
#pragma interrupt Sample_Isr_INT0066( vect=INT0066 )
void Sample_Isr_INT0066( void ) {
#if ( SAMPLE_CAN_ENABLE != FALSE )
#if ( ( CAN_70_TX_INTERRUPT_PROCESSING == TRUE ) \
   || ( CAN_70_TX_MIXED_PROCESSING     == TRUE ) )
    Can_70_Isr_Transmission_CAN0();
#endif
#endif


}


/* INT0068 */
#pragma interrupt Sample_Isr_INT0068( vect=INT0068 )
void Sample_Isr_INT0068( void ) {
#if ( SAMPLE_CAN_ENABLE != FALSE )
#if ( ( CAN_70_RX_INTERRUPT_PROCESSING == TRUE ) \
   || ( CAN_70_RX_MIXED_PROCESSING     == TRUE ) )
    Can_70_Isr_Reception_CAN0();
#endif
#endif


}


/* INT006A */
#pragma interrupt Sample_Isr_INT006A( vect=INT006A )
void Sample_Isr_INT006A( void ) {
#if ( SAMPLE_CAN_ENABLE != FALSE )
    Can_70_Isr_GlobalError_CAN0();
#endif


}


/* INT006C */
#pragma interrupt Sample_Isr_INT006C( vect=INT006C )
void Sample_Isr_INT006C( void ) {
    uint8   iscReg;

    /* Get input switch controll register value. */
    iscReg = ISC;

    if ( ISC3 == ( iscReg & ISC3 ) ) {
        /* INTLIN1WUP interrupt process */
#if ( SAMPLE_LIN_ENABLE != FALSE )
        Lin_70_Isr_WakeupCh1();
#endif
    } else {
        /* INTP12 interrupt process */
    }
}


/* INT006E */
#pragma interrupt Sample_Isr_INT006E( vect=INT006E )
void Sample_Isr_INT006E( void ) {

#if ( SAMPLE_CAN_ENABLE != FALSE )
#if ( ( CAN_70_RX_INTERRUPT_PROCESSING == TRUE ) \
   || ( CAN_70_RX_MIXED_PROCESSING     == TRUE ) )
    Can_70_Isr_Reception_CAN1();
#endif
#endif

}


/* INT0070 */
#pragma interrupt Sample_Isr_INT0070( vect=INT0070 )
void Sample_Isr_INT0070( void ) {

#if ( SAMPLE_CAN_ENABLE != FALSE )
    Can_70_Isr_GlobalError_CAN1();
#endif

}


/* INT0072 */
#pragma interrupt Sample_Isr_INT0072( vect=INT0072 )
void Sample_Isr_INT0072( void ) {

#if ( SAMPLE_CAN_ENABLE != FALSE )
#if ( ( CAN_70_WAKEUP_SUPPORT == TRUE ) && ( CAN_70_WAKEUP_INTERRUPT_PROCESSING == TRUE ) )
    Can_70_Isr_Wakeup_CAN1();
#endif
#endif

}


/* INT0074 */
#pragma interrupt Sample_Isr_INT0074( vect=INT0074 )
void Sample_Isr_INT0074( void ) {
    uint8   intFlg2;
    uint8   intFlg3;

    /* Get interrupt source determination flag. */
    intFlg2 = INTFLG2;
    intFlg3 = INTFLG3;

    if ( INTFLG24 == ( intFlg2 & INTFLG24 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG2 = (uint8)(~INTFLG24);

        /* INTTM14 interrupt process */
#if ( SAMPLE_GPT_ENABLE != FALSE)
        Gpt_70_Isr_TAU_1_CH4();
#endif
    } else if ( INTFLG32 == ( intFlg3 & INTFLG32 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG3 = (uint8)(~INTFLG32);

        /* INTRCAN1GRVC interrupt process */
    }
}


/* INT0076 */
#pragma interrupt Sample_Isr_INT0076( vect=INT0076 )
void Sample_Isr_INT0076( void ) {
    uint8   intFlg2;
    uint8   intFlg3;

    /* Get interrupt source determination flag. */
    intFlg2 = INTFLG2;
    intFlg3 = INTFLG3;

    if ( INTFLG25 == ( intFlg2 & INTFLG25 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG2 = (uint8)(~INTFLG25);

        /* INTTM15 interrupt process */
    } else if ( INTFLG33 == ( intFlg3 & INTFLG33 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG3 = (uint8)(~INTFLG33);
 
        /* INTRCAN1ERR interrupt process */
#if ( SAMPLE_CAN_ENABLE != FALSE )
        Can_70_Isr_ChannelError_CAN1();
#endif
    }
}


/* INT0078 */
#pragma interrupt Sample_Isr_INT0078( vect=INT0078 )
void Sample_Isr_INT0078( void ) {
    uint8   intFlg2;
    uint8   intFlg3;

    /* Get interrupt source determination flag. */
    intFlg2 = INTFLG2;
    intFlg3 = INTFLG3;

    if ( INTFLG26 == ( intFlg2 & INTFLG26 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG2 = (uint8)(~INTFLG26);

        /* INTTM16 interrupt process */
    } else if ( INTFLG34 == ( intFlg3 & INTFLG34 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG3 = (uint8)(~INTFLG34);

        /* INTRCAN1CFR interrupt process */
    }
}


/* INT007A */
#pragma interrupt Sample_Isr_INT007A( vect=INT007A )
void Sample_Isr_INT007A( void ) {
    uint8   intFlg2;
    uint8   intFlg3;

    /* Get interrupt source determination flag. */
    intFlg2 = INTFLG2;
    intFlg3 = INTFLG3;

    if ( INTFLG27 == ( intFlg2 & INTFLG27 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG2 = (uint8)(~INTFLG27);

        /* INTTM17 interrupt process */
#if ( SAMPLE_ICU_ENABLE != FALSE )
        Icu_70_Isr_TAU17();
#endif
    } else if ( INTFLG35 == ( intFlg3 & INTFLG35 ) ) {
        /* Clear interrupt source determination flag. */
        INTFLG3 = (uint8)(~INTFLG35);

        /* INTRCAN1TRM interrupt process */
#if ( SAMPLE_CAN_ENABLE != FALSE )
#if ( ( CAN_70_TX_INTERRUPT_PROCESSING == TRUE ) \
   || ( CAN_70_TX_MIXED_PROCESSING     == TRUE ) )
        Can_70_Isr_Transmission_CAN1();
#endif
#endif
    }
}


/* INT007C */
#pragma interrupt Sample_Isr_INT007C( vect=INT007C )
void Sample_Isr_INT007C( void ) {
#if ( SAMPLE_CAN_ENABLE != FALSE )
    Can_70_Isr_CanRamEcc();
#endif


}



