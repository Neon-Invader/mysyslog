# Имя целевого исполняемого файла
TARGET = mysyslog-client

# Компилятор
CC = gcc

# Флаги компиляции
CFLAGS = -Wall -Wextra -O2 -I.

# Исходные файлы
SRCS = mysyslog-client.c
# Объектные файлы
OBJS = $(SRCS:.c=.o)

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Правило для создания объектных файлов
%.o: %.c mysyslog.h
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка объектных файлов и исполняемого файла
clean:
	rm -f $(OBJS) $(TARGET)

# Установка программы
install: $(TARGET)
	install -Dm755 $(TARGET) /usr/local/bin/

.PHONY: all clean install
