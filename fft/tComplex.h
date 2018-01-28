#ifndef  TCOMPLEX_H
#define TCOMPLEX_H
	typedef struct tComplex{
		double real;
		double imag;
	} tComplex;
	tComplex get(double r, double i);
	tComplex getFromPhasor(double amplitude, double phase);
	void tPrint(tComplex * t);
	void tCongugate( tComplex * x);
	void tNegate( tComplex * x);
	void tAdd(tComplex * val1, tComplex * val2, tComplex * output);
	void tSub(tComplex * val1, tComplex * val2, tComplex * output);
	void tMultiply(tComplex * val1, tComplex * val2, tComplex * output);
	void tPrintVector(tComplex * input, int size);
#endif

