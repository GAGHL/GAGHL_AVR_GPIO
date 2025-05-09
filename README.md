# GAGHL AVR GPIO Library
In the name of GOD

This library provides a set of functions for controlling the GPIO pins of AVR microcontrollers using a syntax similar to the popular Arduino environment. It is designed to allow easy integration with AVR projects while maintaining compatibility with the commonly used Arduino functions.

## Features

- **Pin Mode Configuration**: Set the pin modes (INPUT, OUTPUT, INPUT_PULLUP) for GPIO pins.
- **Digital Write and Read**: Read and write digital values (HIGH or LOW) to the pins.
- **Pin Toggle**: Toggle the value of a specific pin (invert HIGH/LOW).
- **PWM Control**: Generate Pulse Width Modulation (PWM) signals with adjustable duty cycle on specific pins.
- **AVR GCC Compatibility**: Specifically designed for use with AVR microcontrollers and the GCC compiler.


## Functions

### `void pinMode(pin_t pin, uint8_t pinModeVal)`
This function sets the mode of a specific pin (0 to 55) to either `INPUT`, `OUTPUT`, or `INPUT_PULLUP`.

- **pin**: The pin number to configure (0 to 55).
- **pinModeVal**: The desired mode for the pin.
    - `INPUT`: Configures the pin as an input.
    - `OUTPUT`: Configures the pin as an output.
    - `INPUT_PULLUP`: Configures the pin as an input with a pull-up resistor enabled.

### `void digitalWrite(pin_t pin, uint8_t pinValue)`
This function sets the output value of a specific pin (0 to 55) to either `HIGH` or `LOW`.

- **pin**: The pin number to write to (0 to 55).
- **pinValue**: The value to set for the pin.
    - `HIGH`: Sets the pin to a high voltage (typically 5V or 3.3V).
    - `LOW`: Sets the pin to a low voltage (0V).

### `void digitalToggle(pin_t pin)`
This function toggles the output value of a specific pin (0 to 55). It inverts the current state of the pin from `HIGH` to `LOW` or vice versa.

- **pin**: The pin number to toggle (0 to 55).

### `void digitalPWM(pin_t pin, uint8_t duty_cycle)`
This function generates a PWM signal with a specified duty cycle on a given pin. The duty cycle is expressed as a percentage (0-100).

- **pin**: The PWM-capable pin to output the PWM signal on.
- **duty_cycle**: The duty cycle for the PWM signal, as a percentage (0-100). If set to 0, the PWM output is disabled and the pin is pulled LOW.


### `int8_t digitalRead(pin_t pin)`
This function reads the current input state of a specific pin (0 to 55). It returns `HIGH` if the pin is high and `LOW` if the pin is low.

- **pin**: The pin number to read (0 to 55).
- **Returns**:
    - `HIGH` (1) if the pin is high.
    - `LOW` (0) if the pin is low.
    - `-1` if the pin number is invalid.

## Installation

To use this library in your AVR projects, simply include the header file `GAGHL_AVR_GPIO.h` in your source code and use the provided functions to control the GPIO pins.

### Example

```c
#include "GAGHL_AVR_GPIO.h"

int main(){
    pinMode(PA_0,OUTPUT);     // Set PA0 as an output pin
    digitalWrite(PA_0,HIGH);  // Set PA0 to HIGH
    while(1){
        // Toggle PA0 every second
        digitalToggle(PA_0);
        _delay_ms(1000);
    }
}
```

```c
#include "GAGHL_AVR_GPIO.h"

int main(){
    pinMode(PB_3, OUTPUT);     // Set PB3 as an output pin (PWM pin)
    while(1){
        // Generate a PWM signal with 50% duty cycle on PB3
        digitalPWM(PB_3,50);
        _delay_ms(1000);
        
        // Generate a PWM signal with 90% duty cycle on PD4
        digitalPWM(PD_4,90);
        _delay_ms(1000);
        
    }
}
```
## License

This project is licensed under the Creative Commons Attribution-NonCommercial 4.0 International (CC BY-NC 4.0).

You are free to:
- Share — copy and redistribute the material in any medium or format
- Adapt — remix, transform, and build upon the material

Under the following terms:
- **Attribution** — You must give appropriate credit to the author (GAGHL).
- **NonCommercial** — You may not use the material for commercial purposes without explicit permission.

For more information, see the full license: [https://creativecommons.org/licenses/by-nc/4.0/](https://creativecommons.org/licenses/by-nc/4.0/)

© 2025 GAGHL. All rights reserved.

## Author

Developed by [GAGHL](https://github.com/GAGHL)
