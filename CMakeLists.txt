
add_library(mext_encoder_stm32 INTERFACE)

target_include_directories(mext_encoder_stm32 INTERFACE .)

if (STM32F303x8 IN_LIST MBED_TARGET_LABELS)

	target_sources(mext_encoder_stm32
		PUBLIC
		pins_f303k8.cpp
		)

elseif (STM32F446xE IN_LIST MBED_TARGET_LABELS)

	target_sources(mext_encoder_stm32
		PUBLIC
		pins_f446re.cpp
		)

endif()

