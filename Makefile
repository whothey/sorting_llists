CC           = gcc
MAIN_SOURCE  = main.c
MAIN_EXEC    = main
BUILD_FOLDER = builds
FLAGS        = -Wall

all: main

main: $(MAIN_SOURCE)
	$(CC) $(MAIN_SOURCE) -o $(BUILD_FOLDER)/$(MAIN_EXEC) $(FLAGS)

debug: main
	valgrind $(BUILD_FOLDER)/$(MAIN_EXEC)

run: main
	$(BUILD_FOLDER)/$(MAIN_EXEC)
