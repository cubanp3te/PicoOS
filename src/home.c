#include "home.h"
#include "config.h"
#include "hardware/gpio.h"
#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static const char prompt[] = "interactive> ";
const unsigned int GPIO_PIN = 18;

void picoos_home()
{
    do
    {
        char line[100];

        picoos_util_getline(prompt, line, sizeof(line));

        if(strcmp(line, "on") == 0)
        {
            gpio_put(GPIO_PIN, 1);
        }
        else if(strcmp(line, "off") == 0)
        {
            gpio_put(GPIO_PIN, 0);
        }
        else if(strcmp(line, "config") == 0)
        {
            picoos_config();
        }
        else
        {
            printf("Valid commands are: on, off, config\n");
        }
    } while(true); // command loop

    return;
}