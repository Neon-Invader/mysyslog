#ifndef MYSYSLOG_H
#define MYSYSLOG_H

// Уровни логирования
#define LEVEL_DEBUG 0
#define LEVEL_INFO  1
#define LEVEL_WARN  2
#define LEVEL_ERROR 3

// Прототип функции mysyslog
void mysyslog(const char* message, int level, int driver, int format, const char* path);

typedef struct 
{
    int level;      // Уровень логирования
    int driver;     // Драйвер логирования
    int format;     // Формат сообщения
    const char* path; // Путь для записи логов
} log_config_t;

void set_log_config(log_config_t* config);

#endif
