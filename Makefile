CC=gcc
FLAGS=-Wall -Wpedantic -Wextra -std=c99 -Wvla
SOURCE=*.c
TARGET=test
all:
	$(CC) $(FLAGS) $(INCLUDE) $(SOURCE) -o $(TARGET)

debug:
	$(CC) $(FLAGS) -g $(SOURCE) -o $(TARGET)

clean:
	rm -rf $(TARGET)