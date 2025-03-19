# Toggle a led state

## Task
The task is to write a program that toggles the state of a led with the use of a button.
With a starting state: OFF, the led will stay off until you press the button. Once you press the button you the state should change to ON, and stay ON until the button is pressed again.

If you need help with connecting your led you can look at the schematic in the ref folder.
Try to write the code yourself! Do not look at the example code unless you are stuck.

## Tips
You will probably need to use the folloing funtions from the pico sdk:
* [gpio_init](https://www.raspberrypi.com/documentation/pico-sdk/hardware.html#group_hardware_gpio_1ga8aa4741d93dc40bc728dbd3e41813ad1)
* [gpio_set_dir](https://www.raspberrypi.com/documentation/pico-sdk/hardware.html#group_hardware_gpio_1ga6a40edf0d86f6b3f0dcb51a768cf4681)
* [gpio_put](https://www.raspberrypi.com/documentation/pico-sdk/hardware.html#group_hardware_gpio_1ga71d35b29e897b9bb4fc881b587b08cab)
* [gpio_get](https://www.raspberrypi.com/documentation/pico-sdk/hardware.html#group_hardware_gpio_1gaf38c0b39fba06d1a49d1be56ef548d73)
* [gpio_pull_up](https://www.raspberrypi.com/documentation/pico-sdk/hardware.html#group_hardware_gpio_1ga30a6733240f3d2e25e6b579b6c3902da)
