#include <iostream>
#include "linenoise/linenoise.h"

int main() {
    std::cout << "start" << std::endl;

    char *line;
    while ((line = linenoise("the world>")) != nullptr) {
        if (line[0] != '\0' && line[0] != '/') {
            printf("echo: '%s'\n", line);
            linenoiseHistoryAdd(line);
            linenoiseHistorySave("history.txt");
        } else if (line[0] == '/') {
            printf("UnRecognized command: %s\n", line);
        }

        free(line);
    }
}