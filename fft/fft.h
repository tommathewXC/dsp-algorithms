#include <stdio.h>
#include "tComplex.h"

#ifndef  FFT_H
#define FFT_H
	void FFT_2Point(tComplex * x, tComplex * z);
	void FFT(tComplex * x, tComplex * output, int size);
	void extract(tComplex * input, tComplex * output, int inputLength, char odd);
#endif
