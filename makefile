# Makefile for the Binary Search Tree project
.POSIX:

INCDIR = ./include
SRCDIR = ./src
OBJDIR = ./obj
DOCDIR = ./docs

INC = $(INCDIR)/node.hpp $(INCDIR)/bst.hpp $(INCDIR)/io.hpp
SRC = $(SRCDIR)/node.cpp $(SRCDIR)/bst.cpp $(SRCDIR)/io.cpp $(SRCDIR)/main.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -g -O0 -std=c++11 -I. -I$(INCDIR) -W

all: options bst

options:
	@echo "bst build options:"
	@echo "CFLAGS = $(CFLAGS)"
	@echo "CC     = $(CC)"
	@mkdir -p $(OBJDIR)

.SUFFIXES: .cpp .o

.cpp.o:
	$(CC) $(CFLAGS) -c $<

node.o: $(INCDIR)/node.hpp
bst.o: $(INCDIR)/bst.hpp
io.o: $(INCDIR)/io.hpp $(INCDIR)/bst.hpp
main.o: $(INCDIR)/io.hpp $(INCDIR)/bst.hpp

$(OBJ): $(INC)

bst: $(OBJ)
	$(CC) -o $@ $(OBJ)

clean: clean_obj clean_bin

clean_obj:
	rm -f $(OBJ)

clean_bin:
	rm -f bst

.PHONY: all options
