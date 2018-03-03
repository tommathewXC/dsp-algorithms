#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#ifndef  TFFT_H
#define TFFT_H
	#define PI 3.14159265359
	int reverseBits(const int input, const int length);
	int isPowerOf2( const int input);
	int isEven(const int input);
	void radix2(const double complex * input, double complex * output, const int inputSize);
#endif
