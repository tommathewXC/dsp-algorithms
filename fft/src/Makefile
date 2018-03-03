all: build test

clean:
	@rm -f fft-good

build:
	@gcc test.c tFFT.c -o fft-good -lm;

test:
	@./fft-good