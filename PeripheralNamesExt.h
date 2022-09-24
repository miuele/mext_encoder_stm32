#ifndef ENCODER_PERIPHERAL_NAMES_EXT_H_INCLUDED
#define ENCODER_PERIPHERAL_NAMES_EXT_H_INCLUDED

namespace mhal {

typedef enum {
	ENC_1  = (int)TIM1_BASE,
#if defined TIM2_BASE
	ENC_2  = (int)TIM2_BASE,
#endif
#if defined TIM3_BASE
	ENC_3  = (int)TIM3_BASE,
#endif
#if defined TIM4_BASE
	ENC_4  = (int)TIM4_BASE,
#endif
#if defined TIM5_BASE
	ENC_5  = (int)TIM5_BASE,
#endif
#if defined TIM6_BASE
	ENC_6  = (int)TIM6_BASE,
#endif
#if defined TIM7_BASE
	ENC_7  = (int)TIM7_BASE,
#endif
#if defined TIM8_BASE
	ENC_8  = (int)TIM8_BASE,
#endif
#if defined TIM9_BASE
	ENC_9  = (int)TIM9_BASE,
#endif
#if defined TIM10_BASE
	ENC_10 = (int)TIM10_BASE,
#endif
#if defined TIM11_BASE
	ENC_11 = (int)TIM11_BASE,
#endif
#if defined TIM12_BASE
	ENC_12 = (int)TIM12_BASE,
#endif
#if defined TIM13_BASE
	ENC_13 = (int)TIM13_BASE,
#endif
#if defined TIM14_BASE
	ENC_14 = (int)TIM14_BASE,
#endif
#if defined TIM15_BASE
	ENC_15 = (int)TIM15_BASE,
#endif
#if defined TIM16_BASE
	ENC_16 = (int)TIM16_BASE,
#endif
#if defined TIM17_BASE
	ENC_17 = (int)TIM17_BASE,
#endif
#if defined TIM18_BASE
	ENC_18 = (int)TIM18_BASE,
#endif
#if defined TIM19_BASE
	ENC_19 = (int)TIM19_BASE,
#endif
#if defined TIM20_BASE
	ENC_20 = (int)TIM20_BASE,
#endif
#if defined TIM21_BASE
	ENC_21 = (int)TIM21_BASE,
#endif
#if defined TIM22_BASE
	ENC_22 = (int)TIM22_BASE,
#endif
} ENCName;

}

#endif
