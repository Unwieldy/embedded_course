#pragma once
#include "hardware/i2c.h"

// LCD command and flag definitions
const int LCD_CLEARDISPLAY = 0x01;
const int LCD_RETURNHOME = 0x02;
const int LCD_ENTRYMODESET = 0x04;
const int LCD_DISPLAYCONTROL = 0x08;
const int LCD_FUNCTIONSET = 0x20;
const int LCD_SETDDRAMADDR = 0x80;

const int LCD_ENTRYLEFT = 0x02;
const int LCD_DISPLAYON = 0x04;
const int LCD_2LINE = 0x08;

const int LCD_BACKLIGHT = 0x08;
const int LCD_ENABLE_BIT = 0x04;

// Modes for sending data or command
#define LCD_CHARACTER  1
#define LCD_COMMAND 0

// Default I2C address for many LCD I2C backpacks
static int addr = 0x27;

// Quick helper function for sending a single I2C byte
void i2c_write_byte(uint8_t value) {
    i2c_write_blocking(i2c0, addr, &value, 1, false);
}

// Toggle the Enable line to latch data
void lcd_toggle_enable(uint8_t value) {
    #define DELAY_US 600
    sleep_us(DELAY_US);
    i2c_write_byte(value | LCD_ENABLE_BIT);
    sleep_us(DELAY_US);
    i2c_write_byte(value & ~LCD_ENABLE_BIT);
    sleep_us(DELAY_US);
}

// Send a byte to the LCD as two nibbles
void lcd_send_byte(uint8_t value, int mode) {
    uint8_t high = mode | (value & 0xF0) | LCD_BACKLIGHT;
    uint8_t low = mode | ((value << 4) & 0xF0) | LCD_BACKLIGHT;

    i2c_write_byte(high);
    lcd_toggle_enable(high);
    i2c_write_byte(low);
    lcd_toggle_enable(low);
}

void lcd_data(uint8_t data) {
    lcd_send_byte(data, true);
}

void lcd_print(const char *str) {
    while (*str) {
        lcd_data(*str++);
    }
}

// Write a single character to the LCD
void lcd_char(char value) {
    lcd_send_byte(value, LCD_CHARACTER);
}

void lcd_send_command(uint8_t value) {
    lcd_send_byte(value, LCD_COMMAND);
}

void lcd_set_cursor(uint8_t row, uint8_t col) {
    uint8_t address = (row == 0) ? 0x00 + col : 0x40 + col;
    lcd_send_command(0x80 | address);
}

// Clear the LCD display
void lcd_clear(void) {
    lcd_send_command(LCD_CLEARDISPLAY);
    sleep_ms(2);  // a short delay for the command to settle
}

// Initialize the LCD in 4-bit mode
void lcd_init(void) {
    // According to the LCD datasheet, we need to start in 8-bit mode,
    // then switch to 4-bit mode.
    sleep_ms(50);    // Wait for >40ms after power-up
    lcd_send_command(0x03);
    sleep_ms(5);
    lcd_send_command(0x03);
    sleep_us(150);
    lcd_send_command(0x03);
    sleep_ms(1);
    lcd_send_command(0x02);  // Set to 4-bit mode

    // Function set: 4-bit mode, 2 lines (the 5x10 dots flag is usually 0 for 16x2 LCD)
    lcd_send_command(LCD_FUNCTIONSET | LCD_2LINE);

    // Display control: turn the display on (no cursor or blinking needed here)
    lcd_send_command(LCD_DISPLAYCONTROL | LCD_DISPLAYON);

    // Entry mode: set text direction to left-to-right
    lcd_send_command(LCD_ENTRYMODESET | LCD_ENTRYLEFT);

    // Clear the display
    lcd_clear();
}

