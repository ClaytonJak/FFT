#include "fft_fn.h"

CArray seed_test_signal() { //N is the size of the seed signal and should be a multiple of 2 if able
    const int N = 32768;
    Complex test_sig[N];
    for (int i = 0; i < N; ++i) {
        double t = 2 * pi * i / 10000; //2*pi/10000 seconds per sample --> 1.59kHz sampling rate
        test_sig[i] = 10 * cos(t);
        //std::cout << test_sig[i] << std::endl; use this for debugging
    }
    CArray test_sig_array(test_sig,N);
    return test_sig_array;
}