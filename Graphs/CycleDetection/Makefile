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

_DEPS = Cycle.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Cycle.o Main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

CFLAGS =  -Wall -I$(IDIR)

.PHONY: clean 

# binaries
EXECUTABLE = $(BINDIR)/Cycle

all: build $(EXECUTABLE)

# Creating directories
build: 
	@echo "$(COMPILE_COLOR)|-- Building "bin" Directory --|$(NO_COLOR)"
	@mkdir -p $(BINDIR)
	@echo "$(COMPILE_COLOR)|-- Building "obj" Directory --|$(NO_COLOR)"
	@mkdir -p $(ODIR)

# Object files
$(ODIR)/Cycle.o: $(SRCDIR)/Cycle.cpp
	@echo "$(COMPILE_COLOR)|----- Building Cycle Object File -----|$(NO_COLOR)"
	@echo "$(NO_COLOR)                            $(NO_COLOR)" 
	$(CC) $(CFLAGS) -c $(SRCDIR)/Cycle.cpp -o $(ODIR)/Cycle.o

$(ODIR)/Main.o: $(SRCDIR)/Main.cpp
	@echo "$(COMPILE_COLOR)|----- Building Main object file -----|$(NO_COLOR)"
	@echo "$(NO_COLOR)                            $(NO_COLOR)" 
	$(CC) $(CFLAGS) -c $(SRCDIR)/Main.cpp -o $(ODIR)/Main.o

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
