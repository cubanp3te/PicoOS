#include "config.h"
#include "hardware/gpio.h"
#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static void _config_gpio(unsigned int pin);

void picoos_config()
{
    const char *prompt = "config> ";
    do
    {
        char line[100];
        unsigned int pin;

        picoos_util_getline(prompt, line, sizeof(line));

        if(sscanf(line, "gpio %d", &pin) == 1)
        {
            _config_gpio(pin);
        }
        else if(strcmp(line, "exit") == 0)
        {
            break; // break out of command loop
        }
        else
        {
            printf("Valid commands are: gpio <pin>, exit\n");
        }
    } while(true); // command loop

    return;
}

static void _config_gpio(unsigned int pin)
{
    char prompt[17 + 1];
    sprintf(prompt, "config gpio #%u>", pin);

    do
    {
        char line[100];

        picoos_util_getline(prompt, line, sizeof(line));

        if(strcmp(line, "init") == 0)
        {
            gpio_init(pin);
            printf("Pin %d initialised!\n", pin);
        }
        else if(strcmp(line, "set dir in") == 0)
        {
            gpio_set_dir(pin, GPIO_IN);
            printf("Pin %d direction set to IN!\n", pin);
        }
        else if(strcmp(line, "set dir out") == 0)
        {
            gpio_set_dir(pin, GPIO_OUT);
            printf("Pin %d direction set to OUT!\n", pin);
        }
        else if(strcmp(line, "exit") == 0)
        {
            break; // break out of command loop
        }
        else
        {
            printf("Valid commands are: init, set dir in/out, exit\n");
        }
    } while(true); // command loop

    return;
}