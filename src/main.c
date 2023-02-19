#include "home.h"
#include "pico/stdio.h"
#include <stdio.h>

int main()
{
    stdio_init_all();

    do
    {
        picoos_home();
    } while(true);
}