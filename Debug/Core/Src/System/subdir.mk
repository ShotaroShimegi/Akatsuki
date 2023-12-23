################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/System/s_mode.c \
../Core/Src/System/s_task.c \
../Core/Src/System/s_test.c 

C_DEPS += \
./Core/Src/System/s_mode.d \
./Core/Src/System/s_task.d \
./Core/Src/System/s_test.d 

OBJS += \
./Core/Src/System/s_mode.o \
./Core/Src/System/s_task.o \
./Core/Src/System/s_test.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/System/%.o Core/Src/System/%.su Core/Src/System/%.cyclo: ../Core/Src/System/%.c Core/Src/System/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411xE -DUSE_FULL_LL_DRIVER -DHSE_VALUE=25000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DEXTERNAL_CLOCK_VALUE=12288000 -DHSI_VALUE=16000000 -DLSI_VALUE=32000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=1 -DINSTRUCTION_CACHE_ENABLE=1 -DDATA_CACHE_ENABLE=1 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-System

clean-Core-2f-Src-2f-System:
	-$(RM) ./Core/Src/System/s_mode.cyclo ./Core/Src/System/s_mode.d ./Core/Src/System/s_mode.o ./Core/Src/System/s_mode.su ./Core/Src/System/s_task.cyclo ./Core/Src/System/s_task.d ./Core/Src/System/s_task.o ./Core/Src/System/s_task.su ./Core/Src/System/s_test.cyclo ./Core/Src/System/s_test.d ./Core/Src/System/s_test.o ./Core/Src/System/s_test.su

.PHONY: clean-Core-2f-Src-2f-System

