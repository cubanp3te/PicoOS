#include "home.h"
#include "hardware/gpio.h"
#include <stdio.h>
#include <string.h>

const char prompt[] = "interactive> ";
char line[100];
int linelen = 0;
const unsigned int GPIO_PIN = 18;

void picoos_home()
{
    printf(prompt);
    char ch;

    while(linelen < 100)
    {
        ch = getchar();

        if(ch != '\n' && ch != '\r')
        {
            printf("%c", ch);
            line[linelen] = ch;
            linelen++;
        }
        else
        {
            line[linelen] = '\0';
            linelen++;
            break;
        }
    }

    printf("\n%s\n", line);

    if(strcmp(line, "on") == 0)
    {
        gpio_put(GPIO_PIN, 1);
    }
    else if(strcmp(line, "off") == 0)
    {
        gpio_put(GPIO_PIN, 0);
    }
    else
    {
        printf("Valid commands are: on, off\n");
    }

    linelen = 0;
    line[0] = '\0';
}