#include <stdio.h>
#include "tComplex.h"
#include <math.h>
#include <stdlib.h>

tComplex get(double r, double i){
	tComplex t;
	t.real = r;
	t.imag = i;
	return t;
}
tComplex getFromPhasor(double amplitude, double phase){
	tComplex t;
	t.real = amplitude * cos(phase);
	t.imag = amplitude * sin(phase);
	return t;
}
void tPrint(tComplex * t){
	printf("Real: %f, Imag: %f\n", t->real, t->imag );
}
void tCongugate( tComplex * x){
	x->imag = -1 * (x->imag);
}
void tNegate( tComplex * x){
	x->imag = -1 * (x->imag);
	x->real = -1 * (x->real);
}
void tAdd(tComplex * val1, tComplex * val2, tComplex * output){
	output->real = val1->real + val2->real;
	output->imag = val1->imag + val2->imag;
}
void tSub(tComplex * val1, tComplex * val2, tComplex * output){
	output->real = val1->real - val2->real;
	output->imag = val1->imag - val2->imag;
}
void tMultiply(tComplex * val1, tComplex * val2, tComplex * output){
	output->real = (val1->real * val2->real) - (val1->imag * val2->imag);
	output->imag = (val1->real * val2->imag) + (val2->real * val1->imag);
}
void tPrintVector(tComplex * input, int size){
	for(int i=0; i<size; i++){
		tPrint( & input[i] );
	}
}