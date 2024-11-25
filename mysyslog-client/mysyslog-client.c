#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "mysyslog.h"

int main(int argc, char* argv[]) 
{
    int level = LEVEL_INFO;
    int driver = 0;          // Установка драйвера по умолчанию
    int format = 0;          // Установка формата по умолчанию
    char* msg = NULL;
    char* path = NULL;

    // Обработка аргументов
    int opt;
    while ((opt = getopt(argc, argv, "m:l:d:f:p:")) != -1) 
    {
        switch (opt) 
        {
        case 'm':
            msg = optarg;
            break;
        case 'l':
            level = atoi(optarg);
            break;
        case 'd':
            driver = atoi(optarg);
            break;
        case 'f':
            format = atoi(optarg);
            break;
        case 'p':
            path = optarg;
            break;
        default:
            fprintf(stderr, "Usage: %s -m message -l level -d driver -f format -p path\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    mysyslog(msg, level, driver, format, path);
    return 0;
}
