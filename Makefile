# compiler
CC = gcc

# libraries to link (eg. "-lm", etc.)
LIBS =

# compiler flags
CFLAGS = -Wall -Werror

# source directory to build in
SOURCE_DIR = src

# Doxygen options
DOXYFILE = Doxyfile

all: String Test docs

String:
	cd src && $(CC) -c String.c -o String.o -Wall -Werror
	cd src && ar rcs libString.a String.o

Test: String
	cd src && gcc StringTest.c -L. -lString -Wall -Werror -o StringTest

docs:
	doxygen $(DOXYFILE)