#ifndef ENCODER_MBED_H_INCLUDED
#define ENCODER_MBED_H_INCLUDED

#include "PeripheralNamesExt.h"

namespace mhal {

const PinMap *pinmap_enc_t1();
const PinMap *pinmap_enc_t2();

struct encoder_t {
	ENCName encoder;
	PinName pin1;
	PinName pin2;
};

enum encoder_pin_polarity_t {
	encoder_pin_polarity_syn,
	encoder_pin_polarity_rev,
	encoder_pin_polarity_none,
};

enum encoder_counter_resolution_t {
	encoder_counter_resolution_16bit,
	encoder_counter_resolution_32bit,
};

inline encoder_pin_polarity_t encoder_pin_polarity(PinName pin1, PinName pin2) {
	ENCName pin1_t1 = (ENCName)pinmap_find_peripheral(pin1, pinmap_enc_t1());
	ENCName pin2_t2 = (ENCName)pinmap_find_peripheral(pin2, pinmap_enc_t2());

	if (pin1_t1 != (ENCName)NC && pin2_t2 != (ENCName)NC && pin1_t1 == pin2_t2) {
		return encoder_pin_polarity_syn;
	}

	ENCName pin1_t2 = (ENCName)pinmap_find_peripheral(pin1, pinmap_enc_t2());
	ENCName pin2_t1 = (ENCName)pinmap_find_peripheral(pin2, pinmap_enc_t1());

	if (pin1_t2 != (ENCName)NC && pin2_t1 != (ENCName)NC && pin1_t2 == pin2_t1) {
		return encoder_pin_polarity_rev;
	}

	return encoder_pin_polarity_none;
}

inline void encoder_init(encoder_t *obj, PinName pin1, PinName pin2) {
	ENCName enc_t1 = (ENCName)pinmap_peripheral(pin1, pinmap_enc_t1());
	ENCName enc_t2 = (ENCName)pinmap_peripheral(pin2, pinmap_enc_t2());
	int peripheral = (int)pinmap_merge(enc_t1, enc_t2);

	obj->encoder = (ENCName)peripheral;
	MBED_ASSERT(obj->encoder != (ENCName)NC);

#if defined(TIM1_BASE)
	if (obj->encoder == ENC_1) {
		__HAL_RCC_TIM1_CLK_ENABLE();
	}
#endif
#if defined(TIM2_BASE)
	if (obj->encoder == ENC_2) {
		__HAL_RCC_TIM2_CLK_ENABLE();
	}
#endif
#if defined(TIM3_BASE)
	if (obj->encoder == ENC_3) {
		__HAL_RCC_TIM3_CLK_ENABLE();
	}
#endif
#if defined(TIM4_BASE)
	if (obj->encoder == ENC_4) {
		__HAL_RCC_TIM4_CLK_ENABLE();
	}
#endif
#if defined(TIM5_BASE)
	if (obj->encoder == ENC_5) {
		__HAL_RCC_TIM5_CLK_ENABLE();
	}
#endif
#if defined(TIM8_BASE)
	if (obj->encoder == ENC_8) {
		__HAL_RCC_TIM8_CLK_ENABLE();
	}
#endif
#if defined(TIM9_BASE)
	if (obj->encoder == ENC_9) {
		__HAL_RCC_TIM9_CLK_ENABLE();
	}
#endif
#if defined(TIM10_BASE)
	if (obj->encoder == ENC_10) {
		__HAL_RCC_TIM10_CLK_ENABLE();
	}
#endif
#if defined(TIM11_BASE)
	if (obj->encoder == ENC_11) {
		__HAL_RCC_TIM11_CLK_ENABLE();
	}
#endif
#if defined(TIM12_BASE)
	if (obj->encoder == ENC_12) {
		__HAL_RCC_TIM12_CLK_ENABLE();
	}
#endif
#if defined(TIM13_BASE)
	if (obj->encoder == ENC_13) {
		__HAL_RCC_TIM13_CLK_ENABLE();
	}
#endif
#if defined(TIM14_BASE)
	if (obj->encoder == ENC_14) {
		__HAL_RCC_TIM14_CLK_ENABLE();
	}
#endif
#if defined(TIM15_BASE)
	if (obj->encoder == ENC_15) {
		__HAL_RCC_TIM15_CLK_ENABLE();
	}
#endif
#if defined(TIM16_BASE)
	if (obj->encoder == ENC_16) {
		__HAL_RCC_TIM16_CLK_ENABLE();
	}
#endif
#if defined(TIM17_BASE)
	if (obj->encoder == ENC_17) {
		__HAL_RCC_TIM17_CLK_ENABLE();
	}
#endif
#if defined(TIM18_BASE)
	if (obj->encoder == ENC_18) {
		__HAL_RCC_TIM18_CLK_ENABLE();
	}
#endif
#if defined(TIM19_BASE)
	if (obj->encoder == ENC_19) {
		__HAL_RCC_TIM19_CLK_ENABLE();
	}
#endif
#if defined(TIM20_BASE)
	if (obj->encoder == ENC_20) {
		__HAL_RCC_TIM20_CLK_ENABLE();
	}
#endif
#if defined(TIM21_BASE)
	if (obj->encoder == ENC_21) {
		__HAL_RCC_TIM21_CLK_ENABLE();
	}
#endif
#if defined(TIM22_BASE)
	if (obj->encoder == ENC_22) {
		__HAL_RCC_TIM22_CLK_ENABLE();
	}
#endif

	pin_function(pin1, (std::uint32_t)pinmap_function(pin1, pinmap_enc_t1()));
	pin_function(pin2, (std::uint32_t)pinmap_function(pin2, pinmap_enc_t2()));

	TIM_HandleTypeDef htim{};
	htim.Instance = (TIM_TypeDef *)obj->encoder;
	htim.Init.Prescaler = 0;
	htim.Init.Period = IS_TIM_32B_COUNTER_INSTANCE(htim.Instance) ? 0xFFFFFFFF : 0xFFFF;
	htim.Init.ClockDivision = 0;

	TIM_Encoder_InitTypeDef sConfig{};
	sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
	sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC1Prescaler = 0;
	sConfig.IC1Filter = 0;
	sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC2Prescaler = 0;
	sConfig.IC2Filter = 0;

	if (HAL_TIM_Encoder_Init(&htim, &sConfig) != HAL_OK) {
		error("Failed to initialize Encoder");
	}

	HAL_TIM_Encoder_Start(&htim, TIM_CHANNEL_1 | TIM_CHANNEL_2);
}

inline void encoder_free(encoder_t *obj) {
	pin_function(obj->pin1, STM_PIN_DATA(STM_MODE_ANALOG, GPIO_NOPULL, 0));
	pin_function(obj->pin2, STM_PIN_DATA(STM_MODE_ANALOG, GPIO_NOPULL, 0));
}

inline void encoder_write(encoder_t *obj, std::uint32_t num) {
	LL_TIM_SetCounter((TIM_TypeDef *)obj->encoder, num);
}

inline std::uint32_t encoder_read(const encoder_t *obj) {
	return LL_TIM_GetCounter((TIM_TypeDef *)obj->encoder);
}

inline encoder_counter_resolution_t encoder_counter_resolution(const encoder_t *obj) {
	return IS_TIM_32B_COUNTER_INSTANCE((TIM_TypeDef *)obj->encoder)
		? encoder_counter_resolution_32bit
		: encoder_counter_resolution_16bit;
}

}

#endif
