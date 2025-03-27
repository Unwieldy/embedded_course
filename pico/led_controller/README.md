# LED controller

Write a program to controll the states of a row of LEDs over UART/USB.
- The Pico should display a welcome screen when starting up.
- The Pico should take the following commands.
    + `ON [n]`: Turn on LED at position `n`.
    + `OFF [n]`: Turn off LED at position `n`.
    + `TOGGLE [n]`: Toggle LED at position `n`.
    + `ALL ON`: Turn on all LEDs.
    + `ALL OFF`: Turn off all LEDs.
    + `STATUS`: Send current state of LEDs.
    + `HELP`: Send list of available command.
