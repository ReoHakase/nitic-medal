CC = gcc
DEPS = main.o sort.o csv.o swap-countries.o is-empty-country.o fill-empty.o count-countries.o print-table.o compare-total.o compare-medal-rank.o compare-name.o search.o add-country.o

exe: $(DEPS)
	$(CC) -o exe $(DEPS)

.c.o: inc.h
	$(CC) -c -o $@ $<

clean:
	rm -f exe $(DEPS)