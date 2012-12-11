################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Parsers/readOBJ.cpp 

OBJS += \
./src/Parsers/readOBJ.o 

CPP_DEPS += \
./src/Parsers/readOBJ.d 


# Each subdirectory must supply rules for building sources it contributes
src/Parsers/%.o: ../src/Parsers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/local/include/ImageMagick/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


