CC=gcc
FLAGS=-Wall -Wpedantic -Wextra -std=c99 -Wvla -Wimplicit-fallthrough=0 -Iinclude
SOURCE=*.c
TARGET=test
H_FILES=$(wildcard *.h)

all:
	$(CC) $(FLAGS) $(INCLUDE) $(SOURCE) -o $(TARGET)

debug:
	$(CC) $(FLAGS) -g $(SOURCE) -o $(TARGET)

clean:
	rm -rf $(TARGET)