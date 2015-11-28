CC           = gcc
MAIN_SOURCE  = main.c
MAIN_EXEC    = main
BUILD_FOLDER = builds
LIBS_FOLDER  = libs
FLAGS        = -Wall
LIB_HEADERS  = $(wildcard libs/**/*.h)
LIB_SOURCES  = $(wildcard libs/**/*.c)

all: main

main: $(BUILD_FOLDER)/$(patsubst %.c, %.o, $(LIB_SOURCES)) $(MAIN_SOURCE)
	$(CC) $(MAIN_SOURCE) $(patsubst %.o, $(BUILD_FOLDER)/%.o, $(notdir $(LIB_HEADERS:%.h=%.o))) -o $(BUILD_FOLDER)/$(MAIN_EXEC) $(FLAGS)

# llist: $(LIBS_FOLDER)/dllist/dllist.h
# 	$(CC) $(LIBS_FOLDER)/dllist/dllist.c -c -o $(BUILD_FOLDER)/dllist.o $(FLAGS)

# llsort: $(LIBS_FOLDER)/dllist/sorting.h
#	$(CC) $(LIBS_FOLDER)/dllist/sorting.c $(BUILD_FOLDER)/dllist.o -c -o $(BUILD_FOLDER)/sorting.o $(FLAGS)

# tpcontato: $(LIBS_FOLDER)/tpcontato/tpcontato.h
#	$(CC) $(LIBS_FOLDER)/tpcontato/tpcontato.c -c -o $(BUILD_FOLDER)/tpcontato.o $(FLAGS)

 %.o : %.c $(LIB_HEADERS)
	$(CC) $< -c -o $(BUILD_FOLDER)/$(notdir $(<:%.c=%.o)) $(FLAGS)

debug: main
	valgrind $(BUILD_FOLDER)/$(MAIN_EXEC) --leak-check=full

run: main
	$(BUILD_FOLDER)/$(MAIN_EXEC)

clean:
	rm $(BUILD_FOLDER)/*
	rm libs/**/*.o
