# Имя программы
TARGET = mysyslog-daemon

# Компилятор
CC = gcc

# Флаги компиляции
CFLAGS = -Wall -Wextra -O2

# Исходные файлы
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Правило по умолчанию
all: $(TARGET)

# Компиляция исполняемого файла
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Компиляция объектных файлов
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка объектных файлов и исполняемого файла
clean:
	rm -f $(OBJS) $(TARGET)

# Установка
install: $(TARGET)
	install -Dm755 $(TARGET) /usr/local/bin/

.PHONY: all clean install
