################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Device/d_MPU6500.c \
../Core/Src/Device/d_TLA2518.c \
../Core/Src/Device/d_basic_timer.c \
../Core/Src/Device/d_buzzer.c \
../Core/Src/Device/d_encoder.c \
../Core/Src/Device/d_indicator.c 

C_DEPS += \
./Core/Src/Device/d_MPU6500.d \
./Core/Src/Device/d_TLA2518.d \
./Core/Src/Device/d_basic_timer.d \
./Core/Src/Device/d_buzzer.d \
./Core/Src/Device/d_encoder.d \
./Core/Src/Device/d_indicator.d 

OBJS += \
./Core/Src/Device/d_MPU6500.o \
./Core/Src/Device/d_TLA2518.o \
./Core/Src/Device/d_basic_timer.o \
./Core/Src/Device/d_buzzer.o \
./Core/Src/Device/d_encoder.o \
./Core/Src/Device/d_indicator.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Device/%.o Core/Src/Device/%.su Core/Src/Device/%.cyclo: ../Core/Src/Device/%.c Core/Src/Device/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -DUSE_FULL_LL_DRIVER -DHSE_VALUE=25000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DEXTERNAL_CLOCK_VALUE=12288000 -DHSI_VALUE=16000000 -DLSI_VALUE=32000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=1 -DINSTRUCTION_CACHE_ENABLE=1 -DDATA_CACHE_ENABLE=1 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Device

clean-Core-2f-Src-2f-Device:
	-$(RM) ./Core/Src/Device/d_MPU6500.cyclo ./Core/Src/Device/d_MPU6500.d ./Core/Src/Device/d_MPU6500.o ./Core/Src/Device/d_MPU6500.su ./Core/Src/Device/d_TLA2518.cyclo ./Core/Src/Device/d_TLA2518.d ./Core/Src/Device/d_TLA2518.o ./Core/Src/Device/d_TLA2518.su ./Core/Src/Device/d_basic_timer.cyclo ./Core/Src/Device/d_basic_timer.d ./Core/Src/Device/d_basic_timer.o ./Core/Src/Device/d_basic_timer.su ./Core/Src/Device/d_buzzer.cyclo ./Core/Src/Device/d_buzzer.d ./Core/Src/Device/d_buzzer.o ./Core/Src/Device/d_buzzer.su ./Core/Src/Device/d_encoder.cyclo ./Core/Src/Device/d_encoder.d ./Core/Src/Device/d_encoder.o ./Core/Src/Device/d_encoder.su ./Core/Src/Device/d_indicator.cyclo ./Core/Src/Device/d_indicator.d ./Core/Src/Device/d_indicator.o ./Core/Src/Device/d_indicator.su

.PHONY: clean-Core-2f-Src-2f-Device

