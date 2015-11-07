CC           = gcc
MAIN_SOURCE  = main.c
MAIN_EXEC    = main
BUILD_FOLDER = builds
FLAGS        = -Wall
LIB_HEADERS  = $(wildcard libs/**/*.h)
LIB_SOURCES  = $(wildcard libs/**/*.c)

all: main

main: $(BUILD_FOLDER)/$(patsubst %.c, %.o, $(LIB_SOURCES)) $(MAIN_SOURCE)
	$(CC) $(MAIN_SOURCE) $(patsubst %.o, $(BUILD_FOLDER)/%.o, $(notdir $(LIB_HEADERS:%.h=%.o))) -o $(BUILD_FOLDER)/$(MAIN_EXEC) $(FLAGS)

%.o : %.c $(LIB_HEADERS)
	$(CC) $< -c -o $(BUILD_FOLDER)/$(notdir $(<:%.c=%.o)) $(FLAGS)

debug: main
	valgrind $(BUILD_FOLDER)/$(MAIN_EXEC) --leak-check=full

run: main
	$(BUILD_FOLDER)/$(MAIN_EXEC)

clean:
	rm $(BUILD_FOLDER)/*
	rm libs/**/*.o
