################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../buffer.cpp \
../button_driver.cpp \
../lcd_driver.cpp \
../main.cpp 

OBJS += \
./buffer.o \
./button_driver.o \
./lcd_driver.o \
./main.o 

CPP_DEPS += \
./buffer.d \
./button_driver.d \
./lcd_driver.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


