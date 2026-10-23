CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = Clinica_VidaSaudavel

ifeq ($(OS),Windows_NT)
    RM = del /Q
else
    RM = rm -f
endif

SRC = Clinica_VidaSaudavel.c \
      paciente.c \
      plantao.c \
      sala_espera.c \
      historico.c \
      fila.c \
      pilha.c \
      lista_com_cabeca.c \
      lista_circular.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJ)

.PHONY: all clean
