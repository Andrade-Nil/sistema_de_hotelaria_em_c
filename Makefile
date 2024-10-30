# Makefile para compilar o projeto

CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = main.c relatorio.c reserva.c util.c
OBJ = $(SRC:.c=.o)
TARGET = hotel

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
