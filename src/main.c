#include "hardware/gpio.h"
#include "hardware/uart.h"
#include "home.h"
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "pico/time.h"
#include <stdio.h>

int main()
{
    stdio_init_all();
    gpio_init(GPIO_PIN);
    gpio_set_dir(GPIO_PIN, GPIO_OUT);

    do
    {
        picoos_home();
    } while(true);
}