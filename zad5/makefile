
DEPS=main.o studenci.o dziekanat.o

main: $(DEPS)
	cc $(DEPS) -Wall -o $@ -Wall --pedantic

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f main
	rm -f *.o
