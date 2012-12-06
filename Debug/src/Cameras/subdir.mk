################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Cameras/Camera.cpp 

OBJS += \
./src/Cameras/Camera.o 

CPP_DEPS += \
./src/Cameras/Camera.d 


# Each subdirectory must supply rules for building sources it contributes
src/Cameras/%.o: ../src/Cameras/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/local/include/ImageMagick/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


