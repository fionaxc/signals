all: signal.c
	gcc signal.c

run: a.out
	./a.out

clean:
	rm *.out
