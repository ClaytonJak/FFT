#pragma once
#include <complex>
#include <valarray>
#include <cmath>

const double pi = 3.141592653589793238460;

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

void fft(CArray& x);
void ifft(CArray& x);