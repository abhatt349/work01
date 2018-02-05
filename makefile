all: maker.c
	gcc maker.c

run: all
	./a.out

clean:
	rm basic.ppm
	rm a.out
	rm *~
