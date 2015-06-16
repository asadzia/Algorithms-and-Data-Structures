#####################################################################
# Author: Asad Zia
#####################################################################

#[Coloring]
NO_COLOR=\033[0m
OK_COLOR=\033[36;01m
COMPILE_COLOR=\033[45;33;01m
STATEMENT_COLOR=\033[46;33;01m

# compiler
CC = g++

# directories
IDIR = ./include
ODIR = ./obj
BINDIR = ./bin
SRCDIR = ./src

_DEPS = DFS.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = DFS.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

CFLAGS =  -Wall -I$(IDIR)

.PHONY: clean 

# binaries
EXECUTABLE = $(BINDIR)/DFS

all: build $(EXECUTABLE)

# Creating directories
build: 
	@echo "$(COMPILE_COLOR)|-- Building "bin" Directory --|$(NO_COLOR)"
	@mkdir -p $(BINDIR)
	@echo "$(COMPILE_COLOR)|-- Building "obj" Directory --|$(NO_COLOR)"
	@mkdir -p $(ODIR)

# Object files
$(ODIR)/DFS.o: $(SRCDIR)/DFS.cpp
	@echo "$(COMPILE_COLOR)|----- Building DFS Object File -----|$(NO_COLOR)"
	@echo "$(NO_COLOR)                            $(NO_COLOR)" 
	$(CC) $(CFLAGS) -c $(SRCDIR)/DFS.cpp -o $(ODIR)/DFS.o

$(ODIR)/main.o: $(SRCDIR)/main.cpp
	@echo "$(COMPILE_COLOR)|----- Building Main object file -----|$(NO_COLOR)"
	@echo "$(NO_COLOR)                            $(NO_COLOR)" 
	$(CC) $(CFLAGS) -c $(SRCDIR)/main.cpp -o $(ODIR)/main.o

# Building Executable
$(EXECUTABLE): $(OBJ)
	@echo "$(COMPILE_COLOR)|----- Finished Compiling -----|$(NO_COLOR)"
	@echo "$(NO_COLOR)                            $(NO_COLOR)"
	@echo "$(COMPILE_COLOR)|-- Building --|$(NO_COLOR)"
	$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE)
	@echo "$(COMPILE_COLOR)|--------------------------|$(NO_COLOR)"

# Cleaning up
clean:
	rm -rf $(BINDIR)
	rm -rf $(ODIR)
