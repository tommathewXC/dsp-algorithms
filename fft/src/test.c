#include <stdio.h>
#include "tFFT.h"
#include <math.h>
#include <complex.h>

void bitReversalTest(){
	const int vectorSize = 4;
	for(int i=0; i<vectorSize; i++){
		printf("Input: %d, Output: %d\n", i, reverseBits(i, log2(vectorSize)));
	}
}
void safe_FFT(){
	const int vectorSize = 8;
	double complex inputVector[vectorSize];
	double complex ouputVector[vectorSize];
	printf("Size %d, %s\n", vectorSize,  "Input:");
	for(int i=0; i<vectorSize; i++){
		inputVector[i] = i + 1;
		printf("\t%f + i%f\n", creal(inputVector[i]), cimag(inputVector[i]) );
	}
	radix2(inputVector, ouputVector, vectorSize);
	printf("%s\n",  "Output:");
	for(int i=0; i<vectorSize; i++){
		printf("\t%f + i%f\n", creal(ouputVector[i]), cimag(ouputVector[i]) );
	}
}

int main(){
	safe_FFT();
	return 0;
}