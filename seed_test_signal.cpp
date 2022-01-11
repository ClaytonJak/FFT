#include "fft_fn.h"

CArray seed_test_signal() { //sample rate is measured in Hz

    Complex test_sig[N];
    const int w_n1 = 440;
    const int w_n2 = 500;
    const int w_n3 = 1200;
    const float A_n1 = 10.0;
    const float A_n2 = 3.6;
    const float A_n3 = 0.8;
    // analog time signal is cos(w_n1*2*pi*t)+0.7*cos(w_n2*2*pi*t)

    for (int i = 0; i < N; ++i) {
        
        // sample at sample rate
        double t = i * 2 * pi / sample_rate;
        test_sig[i] = A_n1*cos(t*w_n1)+A_n2*cos(t*w_n2)+A_n3*sin(t*w_n3);
        //std::cout << test_sig[i] << std::endl; //use this for debugging
    }
    CArray test_sig_array(test_sig,N);
    return test_sig_array;

}