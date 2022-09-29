#include "pinmap.h"
#include "PeripheralNamesExt.h"

namespace mhal {

const PinMap PinMap_ENC_T1[] = {
//  {PA_0,       ENC_2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM2, 1, 0)}, // TIM2_CH1
//  {PA_5,       ENC_2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM2, 1, 0)}, // TIM2_CH1
    {PA_6,       ENC_3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM3, 1, 0)}, // TIM3_CH1
    {PA_8,       ENC_1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF6_TIM1, 1, 0)}, // TIM1_CH1
//  {PA_15,      ENC_2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM2, 1, 0)}, // TIM2_CH1 // Connected to STDIO_UART_RX
    {PB_4,       ENC_3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM3, 1, 0)}, // TIM3_CH1
    {NC, NC, 0}
};

const PinMap PinMap_ENC_T2[] = {
//  {PA_1,       ENC_2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM2, 2, 0)}, // TIM2_CH2
    {PA_4,       ENC_3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM3, 2, 0)}, // TIM3_CH2
    {PA_7_ALT0,  ENC_3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM3, 2, 0)}, // TIM3_CH2
    {PA_9,       ENC_1,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF6_TIM1, 2, 0)}, // TIM1_CH2
//  {PB_3,       ENC_2,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM2, 2, 0)}, // TIM2_CH2 // Connected to LD3 [Green]
    {PB_5,       ENC_3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF2_TIM3, 2, 0)}, // TIM3_CH2
    {NC, NC, 0}
};

const PinMap *pinmap_enc_t1() {
	return PinMap_ENC_T1;
}

const PinMap *pinmap_enc_t2() {
	return PinMap_ENC_T2;
}

}
