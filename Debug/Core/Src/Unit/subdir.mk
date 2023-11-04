################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Unit/u_dial.c 

C_DEPS += \
./Core/Src/Unit/u_dial.d 

OBJS += \
./Core/Src/Unit/u_dial.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Unit/%.o Core/Src/Unit/%.su Core/Src/Unit/%.cyclo: ../Core/Src/Unit/%.c Core/Src/Unit/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -DUSE_FULL_LL_DRIVER -DHSE_VALUE=25000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DEXTERNAL_CLOCK_VALUE=12288000 -DHSI_VALUE=16000000 -DLSI_VALUE=32000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=1 -DINSTRUCTION_CACHE_ENABLE=1 -DDATA_CACHE_ENABLE=1 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Unit

clean-Core-2f-Src-2f-Unit:
	-$(RM) ./Core/Src/Unit/u_dial.cyclo ./Core/Src/Unit/u_dial.d ./Core/Src/Unit/u_dial.o ./Core/Src/Unit/u_dial.su

.PHONY: clean-Core-2f-Src-2f-Unit

