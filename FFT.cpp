#include <iostream>
#include <fstream>
#include "fft_fn.h"

CArray seed_test_signal(); //use for generating test signals, comment out if not generating test signals

int main()
{
    const int N = 32768; //sample size
    
    //initialize a csv to visualize the input file
    std::ofstream input_raw;
    input_raw.open("input.csv");
    input_raw << "Raw Input by Index\n";

    //seed the test signal. you can modify this signal in seed_test_signal.cpp
    CArray data = seed_test_signal();
    
    for (int i = 0; i < N; ++i) {
        input_raw << i << ","
                  << 2 * pi * i / 10 << ","
                  << data[i].real() << "," 
                  << data[i].imag() << "\n";
    }
    input_raw.close();


    //actually do the fft
    fft(data);

    //initialize the fft csv file
    std::ofstream input_fft;
    input_fft.open("input_fft.csv");
    input_fft << "FFT of Input Signal\n";
    input_fft << "Index,Real,Imag,Mag,Phase\n";

    for (int i = 0; i < N; ++i)
    {
        input_fft << i << "," 
                  << data[i].real() << ","
                  << data[i].imag() << ","
                  << std::abs(data[i]) << ","
                  << std::arg(data[i]) << "\n";
    }
    input_fft.close();

    //MANIPULATE FFT DATA HERE!!!
    
    
    //actually do the inverse fft
    ifft(data);

      //initialize a csv for the time domain reconstruction to visualize it
    std::ofstream output_time_domain;
    output_time_domain.open("output.csv");
    output_time_domain << "Time-Domain Reconstruction of Signal\n";
    output_time_domain << "i,Time,Signal\n";
    for (int i = 0; i < N; ++i)
    {
        output_time_domain << i << ","
                           << 2 * pi * i / 10000 << ","
                           << data[i].real() << "\n";
    }
    output_time_domain.close();
    return 0;
}