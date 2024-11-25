# Имя целевой библиотеки
LIBRARY = libmysyslog.so

# Компилятор
CC = gcc

# Флаги компиляции
CFLAGS = -fPIC -Wall -Wextra -O2

# Исходные файлы
SRCS = mysyslog.c

# Объектные файлы
OBJS = $(SRCS:.c=.o)

# Правило для создания динамической библиотеки
all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	$(CC) -shared -o $@ $^

# Правило для сборки объектных файлов
%.o: %.c mysyslog.h
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка объектов и библиотеки
clean:
	rm -f $(OBJS) $(LIBRARY)

# Установка библиотеки
install: $(LIBRARY)
	install -Dm755 $(LIBRARY) /usr/local/lib/

.PHONY: all clean install
