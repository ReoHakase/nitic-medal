CC = gcc
DEPS = main.o sort.o csv.o array.o

exe: $(DEPS)
	$(CC) -o exe $(DEPS)

.c.o: inc.h
	$(CC) -c -o $@ $<

clean:
	rm -f exe $(DEPS)