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

String:
	cd src
	$(CC) -c String.c -o String.o
	ar rcs libString.a String.o
	gcc StringTest.c -L. -lString
	mkdir -p lib
	doxygen $(DOXYFILE)