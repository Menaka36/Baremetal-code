// Bare-metal C code for STM32 (Blinking LED on PA5)
// Define register addresses
#define RCC_AHB1ENR   (*(volatile unsigned int*)0x40023830) // RCC AHB1 peripheral clock enable register
#define GPIOA_MODER   (*(volatile unsigned int*)0x40020000) // GPIOA mode register
#define GPIOA_ODR     (*(volatile unsigned int*)0x40020014) // GPIOA output data register

// Function prototype
void delay(void);

int main(void) {
    // 1. Enable clock for GPIOA (bit 0 of RCC_AHB1ENR)
    RCC_AHB1ENR |= (1 << 0);

    // 2. Set PA5 as output (MODER5 = 0b01, bits 11:10)
    GPIOA_MODER &= ~(0x3 << 10);  // clear bits
    GPIOA_MODER |=  (0x1 << 10);  // set as output

    // 3. Blink loop
    while (1) {
        GPIOA_ODR ^= (1 << 5);  // Toggle PA5
        delay();                // Wait
    }
}

// Simple software delay
void delay(void) {
    for (volatile int i = 0; i < 1000; i++) {
        for (volatile int j = 0; j < 3195; j++) {
            // Waste some cycles (busy wait)
        }
    }
}
