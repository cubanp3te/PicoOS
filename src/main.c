#include "hardware/gpio.h"
#include "hardware/uart.h"
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "pico/time.h"
#include <stdio.h>
#include <string.h>

const char prompt[] = "interactive> ";

int main()
{
    char line[100];
    int linelen = 0;

    stdio_init_all();
    const uint RED_PIN = 18;
    gpio_init(RED_PIN);
    gpio_set_dir(RED_PIN, GPIO_OUT);

    do
    {
        printf(prompt);
        char ch;

        while(linelen < 100)
        {
            ch = uart_getc(uart0);

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
            gpio_put(RED_PIN, 1);
        }
        else if(strcmp(line, "off") == 0)
        {
            gpio_put(RED_PIN, 0);
        }
        else
        {
            printf("Valid commands are: on, off\n");
        }

        linelen = 0;
        line[0] = '\0';
    } while(true);
}