#ifndef MYSYSLOG_H
#define MYSYSLOG_H

// Уровни журналирования
#define LEVEL_DEBUG    0
#define LEVEL_INFO     1
#define LEVEL_WARN     2
#define LEVEL_ERROR    3
#define LEVEL_CRITICAL 4

int mysyslog(const char* msg, int level, int driver, int format, const char* path);

#endif // MYSYSLOG_H
