CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

# Automatically gathers all .c files in the src folder
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
