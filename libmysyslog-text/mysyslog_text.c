#include <stdio.h>
#include <time.h>

void log_text(const char* msg, int level, const char* process) 
{
    time_t now = time(NULL);
    printf("%ld %d %s %s\n", now, level, process, msg);
}