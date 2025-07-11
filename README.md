<h1 align="center">In the name of GOD</h1>

# GAGHL_AVR_GPIO

**GPIO driver for AVR microcontrollers**

This library provides a set of functions for controlling the GPIO pins of AVR microcontrollers using a syntax similar to the Arduino environment. It is designed to allow easy integration with AVR projects while maintaining compatibility with the commonly used Arduino functions.

## 📦 Features

- ✅ **Pin Mode Configuration**: Set the pin modes (INPUT, OUTPUT, INPUT_PULLUP) for GPIO pins.
- ✅ **Digital Write and Read**: Read and write digital values (HIGH or LOW) to the pins.
- ✅ **Pin Toggle**: Toggle the value of a specific pin (invert HIGH/LOW).
- ✅ **PWM Control**: Generate Pulse Width Modulation (PWM) signals with adjustable duty cycle on specific pins.
- ✅ **AVR GCC Compatibility**: Specifically designed for use with AVR microcontrollers and the GCC compiler.

## 📚 API Overview

| Function          | Parameters                      | Description                                                                |
| ----------------- | ------------------------------- | -------------------------------------------------------------------------- |
| `pinMode()`       | `pin_t pin, uint8_t pinModeVal` | Sets the mode of a pin (INPUT, OUTPUT, or INPUT\_PULLUP)                   |
| `digitalWrite()`  | `pin_t pin, uint8_t pinValue`   | Writes a digital value (HIGH or LOW) to the specified pin                  |
| `digitalToggle()` | `pin_t pin`                     | Toggles the digital state of a pin (HIGH ↔ LOW)                            |
| `digitalRead()`   | `pin_t pin`                     | Reads the current digital state of the specified pin (returns HIGH or LOW) |
| `digitalPWM()`    | `pin_t pin, uint8_t duty_cycle` | Generates a PWM signal on a pin with the specified duty cycle (0–100%)     |


## 🚀 Getting Started

### Add the files to your project

Copy these files into your AVR project:

- `GAGHL_AVR_GPIO.c`
- `GAGHL_AVR_GPIO.h`


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

## 🤝 Contributing

Contributions are welcome!  
Whether it's bug fixes, feature suggestions, or improvements — your help is appreciated.

- Fork the repository
- Create a new branch (`git checkout -b feature/my-feature`)
- Commit your changes (`git commit -am 'Add new feature'`)
- Push to the branch (`git push origin feature/my-feature`)
- Open a Pull Request

If you’re using this library in your project, feel free to let me know — I’d love to check it out!


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
