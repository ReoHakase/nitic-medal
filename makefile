CC = gcc
DEPS = main.o csv.o swap-countries.o is-empty-country.o fill-empty.o count-countries.o

exe: $(DEPS)
	$(CC) -o exe $(DEPS)

.c.o: inc.h
	$(CC) -c -o $@ $<

clean:
	rm -f exe $(DEPS)