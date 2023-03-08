#include <stdio.h>
#include <stdlib.h>
#include "linenoise/linenoise.h"
#include <string.h>

char *hints(const char *buf, int *color, int *bold) {
    if (!strcasecmp(buf,"hello")) {
        *color = 35;
        *bold = 0;
        return " World";
    }
    return NULL;
}

int main()
{
    char *line;
    linenoiseSetHintsCallback(hints);

    while ((line = linenoise("Shell>")) != NULL)
    {
        if (line[0] == '\n')
        {
            free(line);
            continue;
        }

        if (!strncmp(line, "clear", 5))
        {
            linenoiseClearScreen();
            free(line);
            continue;
        }

        if (!strncmp(line, "quit", 4))
        {
            free(line);
            break;
        }

        printf("echo: '%s'\n", line);
        linenoiseHistoryAdd(line);
        linenoiseHistorySave("history.txt");
        free(line);
    }

    return 0;
}