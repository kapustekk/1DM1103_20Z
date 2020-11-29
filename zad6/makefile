
DEPS=main.o math.o in_out.o

main: $(DEPS)
	cc $(DEPS) -Wall -o $@ -Wall --pedantic -lm

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f main
	rm -f *.o
