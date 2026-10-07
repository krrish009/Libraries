CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude/sorting -Iinclude/searching

# Automatically gathers all .c files in the src folder
SRC = src/main.c $(wildcard src/sorting/*.c) $(wildcard src/searching/*.c)
OBJ = $(SRC:.c=.o)
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o src/sorting/*.o src/searching/*.o $(TARGET)

