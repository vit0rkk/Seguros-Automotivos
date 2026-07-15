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
ifeq ($(OS),Windows_NT)
	del /Q *.o 2>nul
	del /Q $(TARGET).exe 2>nul
	del /Q $(TARGET) 2>nul
else
	rm -f *.o $(TARGET)
endif

.PHONY: all clean run