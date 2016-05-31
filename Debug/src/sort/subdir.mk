################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/sort/BinarySearchSort.c \
../src/sort/DirectInsertSort.c 

OBJS += \
./src/sort/BinarySearchSort.o \
./src/sort/DirectInsertSort.o 

C_DEPS += \
./src/sort/BinarySearchSort.d \
./src/sort/DirectInsertSort.d 


# Each subdirectory must supply rules for building sources it contributes
src/sort/%.o: ../src/sort/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


