#include "fft_fn.h"

//Cooley-Tukey FFT **this will overwrite the initial array**
//https://rosettacode.org/wiki/Fast_Fourier_transform#C.2B.2B
//https://www.youtube.com/watch?v=h7apO7q16V0
void fft(CArray& x) {
    const size_t N = x.size();

    //can't DFT a sample of just 1
    if (N <= 1) return;

    //divide sample into even and odd arrays
    CArray even = x[std::slice(0, N / 2, 2)];
    CArray odd = x[std::slice(1, N / 2, 2)];

    //recursively call the fft function to decimate
    fft(even);
    fft(odd);

    //combine results
    for (size_t k = 0; k < N / 2; ++k) {
        Complex t = std::polar(1.0, -2 * pi * k / N) * odd[k];
        x[k] = even[k] + t;
        x[k + N / 2] = even[k] - t;
    }
}

// inverse fft (in-place)
void ifft(CArray& x)
{
    // conjugate the complex numbers
    x = x.apply(std::conj);

    // forward fft
    fft(x);

    // conjugate the complex numbers again
    x = x.apply(std::conj);

    // scale the numbers
    x /= x.size();
}