#include "pinmap.h"
#include "PeripheralNamesExt.h"

namespace mhal {

const PinMap PinMap_ENC_T1[] = {
	{PA_0,		 ENC_2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM2)}, // TIM2_CH1
//	{PA_0,		 ENC_5,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM5)}, // TIM5_CH1
//	{PA_2,		 ENC_9,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF3_TIM9)}, // TIM9_CH1 // Connected to STDIO_UART_TX
	{PA_5,		 ENC_2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM2)}, // TIM2_CH1 // Connected to LD2 [Green Led]
	{PA_6,		 ENC_3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM3)}, // TIM3_CH1
	{PA_8,		 ENC_1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM1)}, // TIM1_CH1
	{PA_15,		 ENC_2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM2)}, // TIM2_CH1
	{PB_4,		 ENC_3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM3)}, // TIM3_CH1
	{PB_6,		 ENC_4,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM4)}, // TIM4_CH1
	{PB_8,		 ENC_2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM2)}, // TIM2_CH1
	{PB_14,		 ENC_12, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF9_TIM12)}, // TIM12_CH1
	{PC_6,		 ENC_3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM3)}, // TIM3_CH1
	{PC_6_ALT0,  ENC_8,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF3_TIM8)}, // TIM8_CH1
	{NC, NC, 0}
};

const PinMap PinMap_ENC_T2[] = {
	{PA_1,		 ENC_2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM2)}, // TIM2_CH2
//	{PA_1,		 ENC_5,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM5)}, // TIM5_CH2
//	{PA_3,		 ENC_9,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF3_TIM9)}, // TIM9_CH2 // Connected to STDIO_UART_RX
	{PA_7,		 ENC_3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM3)}, // TIM3_CH2
	{PA_9,		 ENC_1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM1)}, // TIM1_CH2
//	{PB_3,		 ENC_2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM2)}, // TIM2_CH2 // Connected to SWO
	{PB_5,		 ENC_3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM3)}, // TIM3_CH2
	{PB_7,		 ENC_4,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM4)}, // TIM4_CH2
	{PB_9,		 ENC_2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM2)}, // TIM2_CH2
	{PB_15,		 ENC_12, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF9_TIM12)}, // TIM12_CH2
	{PC_7,		 ENC_3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM3)}, // TIM3_CH2
	{PC_7_ALT0,  ENC_8,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF3_TIM8)}, // TIM8_CH2
	{NC, NC, 0}
};

const PinMap *pinmap_enc_t1() {
	return PinMap_ENC_T1;
}

const PinMap *pinmap_enc_t2() {
	return PinMap_ENC_T2;
}

}
