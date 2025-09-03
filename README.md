# STM32 Bare-metal Blink (PA5)

This project demonstrates a simple **bare-metal C program** to blink the LED connected to **PA5** on the STM32F446RE.

## How it works
- RCC clock for GPIOA is enabled.
- PA5 is configured as output.
- LED is toggled inside an infinite loop using software delay.

## Code
See main.c

## Tools
- Keil uVision IDE
- STM32F446RE (Nucleo board)

## Output
The on-board LED (LD2 on Nucleo) blinks with visible delay.
