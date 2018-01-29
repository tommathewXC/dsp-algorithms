all:	build test

clean:
	rm -f unittest


build:
	gcc test.c tComplex.c fft.c -o unittest -lm;

test:
	./unittest