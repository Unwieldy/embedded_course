/**
 * Minimal example to initialize a 16x2 LCD via I2C and print a single dot on it.
 *
 * Connections (for Raspberry Pi Pico):
 *   GPIO 4 (pin 6)  -> SDA on LCD I2C bridge board
 *   GPIO 5 (pin 7)  -> SCL on LCD I2C bridge board
 *   3.3v (pin 36)   -> VCC on LCD I2C bridge board
 *   GND (pin 38)    -> GND on LCD I2C bridge board
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "lcd.h"

#define SDA_PIN 4
#define SCL_PIN 5

int main() {
    // Initialize chosen serial port (for debugging, if needed)
    stdio_init_all();

    // Initialize I2C0 at 100kHz on default SDA and SCL pins for the Pico
    i2c_init(i2c0, 100 * 1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    // Initialize the LCD
    lcd_init();

    // Move the cursor to the beginning of the first line (address 0x80)
    
    lcd_send_command(0x80);
    const uint32_t char_delay = 200;

    while (true) {
      lcd_send_command(LCD_RETURNHOME);
      for (int i = 0; i < 16; i++){
        lcd_char('.');
        sleep_ms(char_delay);
      }
      lcd_set_cursor(1,0);
      lcd_send_command(LCD_RETURNHOME);
      for (int i = 0; i < 16; i++){
        lcd_char(' ');
        sleep_ms(char_delay);
      }
      // tight_loop_contents();  
    }
}
