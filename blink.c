// Import required libraries
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

// Main function
int main() {
    const uint LED_PIN = 25;                // LED is on pin 25
    gpio_init(LED_PIN);                     // Initialize GPIO
    adc_init();                             // Initialize the ADC
    adc_gpio_init(26);                      // Initialize pin A0/26 as an ADC
    adc_select_input(0);                    // Select A0 to read
    gpio_set_dir(LED_PIN, GPIO_OUT);        // Set LED_PIN to output
    int state = 0;                          // Initialize state to 0 = off
    int count = 0;                          // Initialize count to 0
    while (true) {                          // Loop forever
        gpio_put(LED_PIN, state);           // Set LED to state
        if (count >= adc_read()) {          // Compare count to analogue value, checking if it's greater than or equal to
            if (state == 0) {               // Toggle state
                state = 1;
            } else {
                state = 0;
            }
            count = 0;                      // Reset count
        }
        sleep_ms(1);                        // Wait 1 milisecond
        count++;                            // Count up one
    }
}