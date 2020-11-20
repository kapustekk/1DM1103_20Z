
DEPS=main.o studenci.o dziekanat.o

main: $(DEPS)
	cc $(DEPS) -Wall

%.o:%.c
	cc -c $^ 

clean:
	rm -f main
	rm -f *.o
