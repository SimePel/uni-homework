CC=gcc
CFLAGS=-c -Wall -Wextra -Werror -std=c11
SOURCES=parser.c main.c list.c weekdayload.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY : clean
clean:
	rm -rf *.o