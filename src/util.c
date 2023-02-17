#include "util.h"
#include <stddef.h>
#include <stdio.h>

void picoos_util_getline(const char prompt[], char *line, size_t size)
{
    int linelen = 0;

    printf("%s", prompt);
    char ch;

    while(linelen < 100)
    {
        ch = getchar();

        if(ch != '\n' && ch != '\r'
           && ch != '\377') // \377 appears to be sent on start?
        {
            if(ch != '\b')
            {
                printf("%c", ch);
                line[linelen] = ch;
                linelen++;
            }
            else
            {
                if(linelen > 0)
                {
                    printf("\b\x20\b"); // backspace, space (delete char),
                                        // backspace
                    linelen--;
                    line[linelen] = '\0'; // Remove last char
                }
            }
        }
        else
        {
            line[linelen] = '\0';
            linelen++;
            break;
        }
    }

    printf("\n%s\n", line);
    return;
}