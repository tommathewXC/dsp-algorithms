#include <stdio.h>
#include "tComplex.h"
#include "fft.h"
#include <math.h>

void space(int count){
	for(int i=0; i<count; i++){
		printf("\n" );
	}
}
void tArithmeticTest(){
	printf("%s", "tArithmeticTest");
	space(2);
	tComplex t = get(1, 0);
	tComplex s = get(-1, 0);
	tComplex z = get(0, 0);
	printf("%s\t\t","z1: " );
	tPrint( &t );
	printf("%s\t\t","z2: " );
	tPrint( &s );
	printf("%s\t\t","sum: " );
	tAdd(&t, &s, &z);
	tPrint( &z );
	printf("%s\t\t","dif: " );
	tSub(&t, &s, &z);
	tPrint( &z );
	printf("%s\t","product: " );
	tMultiply(&t, &s, &z);
	tPrint( &z );
	space(3);
}


void extractTest(){
	printf("%s", "extractTest");
	space(2);
	int vectorSize = 4;
	tComplex vector[vectorSize];
	tComplex output[vectorSize / 2];
	vector[0] = get(1, 0);
	vector[1] = get(2, 0);
	vector[2] = get(3, 0);
	vector[3] = get(4, 0);
	printf("Input: ");
	space(2);
	tPrintVector(vector, vectorSize);
	space(2);
	printf("Odd: ");
	space(2);
	extract(vector, output, vectorSize , 'o');
	tPrintVector(output, vectorSize / 2);
	space(2);
	printf("Even: ");
	space(2);
	extract(vector, output, vectorSize , 'e');
	tPrintVector(output, vectorSize / 2);
	space(2);
}

void FFT_Test(){
	printf("%s", "FFT_Test");
	space(2);
	int vectorSize = 8;
	tComplex vector[vectorSize];
	tComplex output[vectorSize];
	vector[0] = get(1, 0);
	vector[1] = get(1, 1);
	vector[2] = get(1, 0);
	vector[3] = get(1, 2);
	vector[4] = get(1, 0);
	vector[5] = get(-1, 1);
	vector[6] = get(3, 0);
	vector[7] = get(5, 2);
	for(int j=0; j<vectorSize; j++){
		output[j] = get(0, 0);
	}
	printf("%s\n", "Input");
	tPrintVector(vector, vectorSize);
	FFT(vector, output, vectorSize);
	printf("%s\n", "Output");
	tPrintVector(output, vectorSize);
	space(3);
}

int main(){
	FFT_Test();
	return 0;
}