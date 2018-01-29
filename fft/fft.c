#include <stdio.h>
#include "fft.h"
#include "tComplex.h"
#include <stdlib.h>
#include <math.h>
#define PI acos(-1.0)
void FFT_2Point(tComplex * x, tComplex * z){
	tAdd(&x[0], &x[1], &z[0]);
	tSub(&x[0], &x[1], &z[1]);
}
void FFT(tComplex * x, tComplex * output, int size){
	if(size == 2){
		FFT_2Point(x, output);
	}else{
		if ( size < 2 ){
			printf("%s\n", "size has to be greater than 2 or equal to 2");
		}else{
			if(ceil(log2(size)) - floor(log2(size)) == 0.0){
				int newSize = size / 2;		
				tComplex * memBlock = malloc(4 * newSize * sizeof(tComplex));		// allocate memory for 4 vectors
				extract(x, &memBlock[0], size, 'o');								// put the even terms in the first
				extract(x, &memBlock[newSize ], size, 'e');							// put the odd terms in the second
				FFT( &memBlock[0], &memBlock[(2 * newSize)], newSize);				// put the fft of the first vector in the third
				FFT( &memBlock[newSize ], &memBlock[(3 * newSize)], newSize);		// put the fft of the secpmd vector in the fourth
				tComplex twiddleFactor = get(0, 0); 
				tComplex buffer;

				for(int q=0; q<size; q++){															// for every element in the output vector...

					twiddleFactor = getFromPhasor(1, (-2 * PI * q) / size);							// 		compute the complex twiddle factor
					tMultiply( &twiddleFactor, &(&memBlock[(3 * newSize)])[ q % 2], &buffer );		// 		multiply the twiddle factor to the right term
					tAdd( &(&memBlock[(2 * newSize)])[q % 2], &buffer, &output[q] );				//		add the product to the left term and put it into the output
				}
				free(memBlock);
			}else{
				printf("Size %d is not supported. Must be a power of 2\n", size );
			}
		}
	}
}
void extract(tComplex * input, tComplex * output, int inputLength, char odd){
	int offset = 0;
	if(odd == 'e'){
		offset = 1;
	}
	for(int i=0; i < inputLength / 2; i++){
		output[i] = input[(2 * i) + offset];
	}
}