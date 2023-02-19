#include "home.h"
#include "config.h"
#include "hardware/gpio.h"
#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static const char prompt[] = "interactive> ";

void picoos_home()
{
    do
    {
        char line[100];
        unsigned int pin;

        picoos_util_getline(prompt, line, sizeof(line));

        if(sscanf(line, "gpio on %i", &pin) == 1)
        {
            printf("Setting GPIO pin #%i HIGH\n", pin);
            gpio_put(pin, 1);
        }
        else if(sscanf(line, "gpio off %i", &pin) == 1)
        {
            printf("Setting GPIO pin #%i LOW\n", pin);
            gpio_put(pin, 0);
        }
        else if(strcmp(line, "config") == 0)
        {
            picoos_config();
        }
        else
        {
            printf(
                "Valid commands are: gpio on <pin>, gpio off <pin>, config\n");
        }
    } while(true); // command loop

    return;
}