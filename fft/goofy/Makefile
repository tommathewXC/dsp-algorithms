all: clean build test 

clean:
	rm -f unittest

build:
	gcc test.c tFFT.c tComplex.c fft.c -o unittest -lm;

test:
	./unittest