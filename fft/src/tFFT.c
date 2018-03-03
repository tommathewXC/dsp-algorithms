#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tFFT.h"
#include <complex.h>

int reverseBits( const int buffer,const int length){
	int output = 0;
	int input = buffer;
	for(int i=0; i<length; i++){
		output = output << 1;
		output += (input & 1);
		input = input >> 1;
	}
	return output;
}
int isPowerOf2( const int input){
	if(input < 1)
		return 0;
	return (input & (input - 1)) == 0;
}
int isEven(const int input){
	return (input & 1) == 0;
}
void radix2(const double complex * inputVector, double complex * ouputVector, const int N){
	const int bitLength = log2(N);
	int evenIndex = 0;
	int oddIndex = 0;
	for(int i=0; i < N / 2; i++){
		evenIndex = reverseBits(2 * i, bitLength);
		oddIndex = reverseBits((2*i) + 1, bitLength);
		ouputVector[2 * i] = inputVector[evenIndex] + inputVector[oddIndex];
		ouputVector[(2*i) + 1] = inputVector[evenIndex] - inputVector[oddIndex];
	}
	// TODO: calculate twiddle factors and perform rest of butterfly network
	for(int j = 2; j < N; j*=2 ){
		printf("%s, %d\n", "network size: ", j * 2);
	}
}