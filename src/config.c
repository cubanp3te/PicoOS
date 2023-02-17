#include "config.h"
#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static const char *prompt = "config> ";

void picoos_config()
{
    do
    {
        char line[100];

        picoos_util_getline(prompt, line, sizeof(line));

        if(strcmp(line, "exit") == 0)
        {
            break; // break out of command loop
        }
        else
        {
            // TODO Implement then remove
            printf("WARNING: Not yet implemented!\n");
            printf("Valid commands are: exit\n");
        }
    } while(true); // command loop

    return;
}