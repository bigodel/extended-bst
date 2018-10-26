# Makefile for the Binary Search Tree project
.POSIX:

INC := node.hpp bst.hpp io.hpp
SRC := node.cpp bst.cpp io.cpp main.cpp
OBJ := $(SRC:.cpp=.o)

CC = c++
CFLAGS = -g -ggdb -O0 -std=c++11 -I. -W -Wall

all: options bst

options:
	@echo "bst build options:"
	@echo "CFLAGS = $(CFLAGS)"
	@echo "CC     = $(CC)"

.SUFFIXES: .cpp .o

.cpp.o:
	$(CC) $(CFLAGS) -c $<

node.o: node.hpp
bst.o: bst.hpp
io.o: io.hpp bst.hpp
main.o: io.hpp bst.hpp

# $(OBJ):

bst: $(OBJ)
	$(CC) -o $@ $(OBJ)

clean: clean_obj clean_bin

clean_obj:
	@echo "Removing objects"
	@rm -f $(OBJ)

clean_bin:
	@echo "Removing binary fils"
	@rm -f bst

.PHONY: all options clean clean_obj clean_bin
