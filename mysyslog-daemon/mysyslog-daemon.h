#ifndef MYSYSLOG_H
#define MYSYSLOG_H

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char log_file[256];
    char log_level[16];
} SyslogConfig;

void load_config(const char* filepath, SyslogConfig* config);
void log_message(const SyslogConfig* config, const char* message);
void run_daemon(const SyslogConfig* config);

#endif // MYSYSLOG_H
