#include "mysyslog.h"
#include <string.h>

void load_config(const char* filepath, SyslogConfig* config) 
{
    FILE* file = fopen(filepath, "r");
    if (!file) 
    {
        perror("Не удалось открыть файл конфигурации");
        exit(EXIT_FAILURE);
    }

    char line[512];
    while (fgets(line, sizeof(line), file)) 
    {
        if (strncmp(line, "log_file=", 9) == 0) 
        {
            sscanf(line + 9, "%255s", config->log_file);
        }
        else if (strncmp(line, "log_level=", 10) == 0) 
        {
            sscanf(line + 10, "%15s", config->log_level);
        }
    }
    fclose(file);
}

void log_message(const SyslogConfig* config, const char* message) 
{
    FILE* log_file = fopen(config->log_file, "a");
    if (!log_file) 
    {
        perror("Не удалось открыть файл журналирования");
        return;
    }

    fprintf(log_file, "[%s] %s\n", config->log_level, message);
    fclose(log_file);
}

void run_daemon(const SyslogConfig* config) 
{
    // Логирования
    log_message(config, "Демон запущен");

    while (1) 
    {
        // Каждые 10 секунд записываем в лог
        sleep(10);
        log_message(config, "Демон работает...");
    }
}

int main() 
{
    SyslogConfig config;
    load_config("/etc/mysyslog/mysyslog.cfg", &config);

    run_daemon(&config);

    return 0;
}
