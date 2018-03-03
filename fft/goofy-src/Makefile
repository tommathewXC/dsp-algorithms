all:	build test

clean:
	rm -f fft-bad


build:
	gcc test.c tComplex.c fft.c -o fft-bad -lm;

test:
	./fft-bad