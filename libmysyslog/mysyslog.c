#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "mysyslog.h"

int mysyslog(const char* msg, int level, int driver, int format, const char* path) 
{
    // Уровни журналирования
    const char* level_names[] = { "DEBUG", "INFO", "WARN", "ERROR", "CRITICAL" };

    // Проверка уровня
    if (level < LEVEL_DEBUG || level > LEVEL_CRITICAL) 
    {
        return -1; // Неверный уровень
    }

    // Получение текущего времени
    time_t now;
    time(&now);
    char* time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Убирает символ новой строки

    // Форматирование сообщения
    char output[512]; // Можно увеличить размер (если необходимо)
    if (format == 0) 
    { 
        // Стандратный формат
        snprintf(output, sizeof(output), "[%s] [%s] %s\n", time_str, level_names[level], msg);
    }
    else 
    { 
        // Воззможность добавлять другие форматы
        snprintf(output, sizeof(output), "{\"time\": \"%s\", \"level\": \"%s\", \"message\": \"%s\"}\n", time_str, level_names[level], msg);
    }

    // Выбор драйвера
    if (driver == 0) 
    {
        printf("%s", output);
    }
    else 
    {
        FILE* file = fopen(path, "a");
        if (file == NULL) 
        {
            return -1; // Ошибка открытия файла
        }
        fprintf(file, "%s", output);
        fclose(file);
    }

    return 0;
}

int main() 
{
    mysyslog("Системное сообщение: запустите систему", LEVEL_INFO, 0, 0, NULL);
    mysyslog("Ошибка загрузки файла", LEVEL_ERROR, 1, 0, "log.txt");
    mysyslog("Отладочное сообщение", LEVEL_DEBUG, 0, 0, NULL);
    mysyslog("Критическая ошибка", LEVEL_CRITICAL, 1, 0, "log.txt");

    return 0;
}
