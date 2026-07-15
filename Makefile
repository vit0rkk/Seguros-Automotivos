# ==============================
# Makefile - Sistema de Seguros
# ==============================

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = cotacao

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f *.o $(TARGET) $(TARGET).exe

.PHONY: all clean run