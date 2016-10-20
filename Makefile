PROJECT=test

CC=gcc
CPP=g++
MKDIR=mkdir -p
DEL=rm -rf

CFLAGS?=-c -g -W -Wall
LINK_FLAGS=-g

OBJ_DIR=obj
INCLUDE_DIR=-Isrc
OUTPUT=-o

OBJECTS=\
		$(OBJ_DIR)/main.o


.PHONY: dir_structure

.PHONY: all

all: dir_structure $(PROJECT)

dir_structure: $(OBJ_DIR)

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

$(PROJECT): $(OBJECTS)
	$(CPP) $(LINK_FLAGS) $(OBJECTS) $(OUTPUT) $(PROJECT)

$(OBJ_DIR)/main.o: src/main.cpp
	$(CPP) $(CFLAGS) $(INCLUDE_DIR) src/main.cpp $(OUTPUT) $(OBJ_DIR)/main.o

run: $(PROJECT)
	./$(PROJECT)

clean:
	$(DEL) $(OBJ_DIR)
	$(DEL) $(PROJECT)

