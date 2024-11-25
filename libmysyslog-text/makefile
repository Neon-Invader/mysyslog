# Имя библиотеки
LIBRARY = libmysyslog_text.so

# Компилятор
CC = gcc

# Флаги компиляции
CFLAGS = -fPIC -Wall -Wextra -O2

# Исходные файлы
SRCS = mysyslog_text.c

# Объектные файлы
OBJS = $(SRCS:.c=.o)

# Правило для создания динамической библиотеки
all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	$(CC) -shared -o $@ $^

# Правило для сборки объектных файлов
%.o: %.c plugin.h
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJS) $(LIBRARY)

# Установка библиотеки
install: $(LIBRARY)
	install -Dm755 $(LIBRARY) /usr/local/lib/

.PHONY: all clean install
