CC=gcc
CFLAGS=-I.

EXECUTABLE=main

OBJ = linked_list/linked_list.o stack/stack.o main.o

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

main.o: main.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean run

clean:
	rm -f $(OBJ) $(EXECUTABLE)

run: 
	make && ./main
