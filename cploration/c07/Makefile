CC = gcc
CFLAGS = -Wall -I.
LDFLAGS =
OBJFILES = main.o parser.o symtable.o   # Include symtable.o here
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

main.o: main.c parser.h symtable.h    # Update dependencies for main.o
	$(CC) $(CFLAGS) -c main.c

parser.o: parser.c parser.h symtable.h  # Update dependencies for parser.o
	$(CC) $(CFLAGS) -c parser.c

symtable.o: symtable.c symtable.h    # New rule for symtable.o
	$(CC) $(CFLAGS) -c symtable.c

clean:
	rm -f $(OBJFILES) $(TARGET) *~
