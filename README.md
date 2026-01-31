# SMART-HOME-GARDEN-SYSTEM

## Overview
This project implements a Smart Garden system using the STM32F4
microcontroller with direct register-level programming (no HAL).

## Features
- Soil moisture monitoring via ADC
- Light intensity detection using LDR
- Buzzer alert for dry soil
- User interrupt buttons for LED control and alarm mute
- Fully interrupt-driven design

## Hardware Used
- STM32F446RE
- Soil moisture sensor (analog)
- LDR sensor
- Push buttons (PA2, PA3)
- LEDs (PB12–PB15, PC0–PC15)
- Buzzer (PD2)

## Programming Approach
- Bare-metal C
- Register-level GPIO, ADC, EXTI, NVIC configuration
- Modular code structure

## Pin Configuration
| Pin | Function |
|----|---------|
| PA0 | Soil Sensor (ADC) |
| PA1 | LDR (ADC) |
| PA2 | LED Toggle Button |
| PA3 | Buzzer Mute Button |
| PD2 | Buzzer |
