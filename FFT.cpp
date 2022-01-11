#include <iostream>
#include <fstream>
#include <string>
#include "fft_fn.h"
#include "freq_classifier.h"

CArray seed_test_signal(); //use for generating test signals, comment out if not generating test signals

int main()
{
    std::string CSV;
    bool wants_CSV = false;
    std::cout << "Beginning FFT analysis...\n" << "Output CSV files? (y/n): \n";
    std::cin >> CSV;
    if ((CSV == "Y") || (CSV == "y")) {
        wants_CSV = true;
    }
   
    //seed the test signal. you can modify this signal in seed_test_signal.cpp
    CArray data = seed_test_signal();

    if (wants_CSV) {
        //initialize a csv to visualize the input file
        std::cout << "Outputting input signal to CSV file...\n";
        std::ofstream input_raw;
        input_raw.open("input.csv");
        input_raw << "Raw Input by Index\n";
        input_raw << "i,Time,Signal\n";
        for (int i = 0; i < N; ++i) {
            input_raw << i << ","
                << i / sample_rate << ","
                << data[i].real() << ","
                << data[i].imag() << "\n";
        }
        input_raw.close();
    }
    

    //actually do the fft
    std::cout << "Conducting FFT...\n";
    fft(data);

    if (wants_CSV) {
        //initialize the fft csv file
        std::cout << "Outputting FFT to CSV file...\n";
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
    }
    

    //create a one-sided fft for visualization and manipulation
    std::cout << "Generating one-sided FFT with time-domain index...\n";
    
    
    //this array will track our 10 most prevalent frequencies. It is ordered by peak height in a unique way.
    //Each freq is paired with peak height such that {max freq, max peak, second freq, second peak...}
    double max10_freq[10] = {};
    double max10_peak[10] = {};
    
    //iterate through the one-sided time-domain index to find maxima frequencies
    for (int i = 0; i < N / 2; ++i) {
        double magn = std::abs(data[i]);
        if (magn > max10_peak[0]) {
            //this bumps everything down the max OML
            for (int j = 8; j > 0; --j) {
                max10_freq[j + 1] = max10_freq[j];
                max10_peak[j + 1] = max10_peak[j];
            }
            //new peak replaces the old peak
            max10_freq[0] = i * sample_rate / N;
            max10_peak[0] = magn;
        }
        else if (magn > max10_peak[1]) {
            //this bumps everything down the max OML
            for (int j = 8; j > 1; --j) {
                max10_freq[j + 1] = max10_freq[j];
                max10_peak[j + 1] = max10_peak[j];
            }
            //new peak replaces the old peak
            max10_freq[1] = i * sample_rate / N;
            max10_peak[1] = magn;
        } 
        else if (magn > max10_peak[2]) {
            //this bumps everything down the max OML
            for (int j = 8; j > 2; --j) {
                max10_freq[j + 1] = max10_freq[j];
                max10_peak[j + 1] = max10_peak[j];
            }
            //new peak replaces the old peak
            max10_freq[2] = i * sample_rate / N;
            max10_peak[2] = magn;
        } 
        else if (magn > max10_peak[3]) {
            //this bumps everything down the max OML
            for (int j = 8; j > 3; --j) {
                max10_freq[j + 1] = max10_freq[j];
                max10_peak[j + 1] = max10_peak[j];
            }
            //new peak replaces the old peak
            max10_freq[3] = i * sample_rate / N;
            max10_peak[3] = magn;
        }
        else if (magn > max10_peak[4]) {
            //this bumps everything down the max OML
            for (int j = 8; j > 4; --j) {
                max10_freq[j + 1] = max10_freq[j];
                max10_peak[j + 1] = max10_peak[j];
            }
            //new peak replaces the old peak
            max10_freq[4] = i * sample_rate / N;
            max10_peak[4] = magn;
        }
        else if (magn > max10_peak[5]) {
            //this bumps everything down the max OML
            for (int j = 8; j > 5; --j) {
                max10_freq[j + 1] = max10_freq[j];
                max10_peak[j + 1] = max10_peak[j];
            }
            //new peak replaces the old peak
            max10_freq[5] = i * sample_rate / N;
            max10_peak[5] = magn;
        }
        else if (magn > max10_peak[6]) {
            //this bumps everything down the max OML
            for (int j = 8; j > 6; --j) {
                max10_freq[j + 1] = max10_freq[j];
                max10_peak[j + 1] = max10_peak[j];
            }
            //new peak replaces the old peak
            max10_freq[6] = i * sample_rate / N;
            max10_peak[6] = magn;
        }
        else if (magn > max10_peak[7]) {
            //this bumps everything down the max OML
            for (int j = 8; j > 7; --j) {
                max10_freq[j + 1] = max10_freq[j];
                max10_peak[j + 1] = max10_peak[j];
            }
            //new peak replaces the old peak
            max10_freq[7] = i * sample_rate / N;
            max10_peak[7] = magn;
        }
        else if (magn > max10_peak[8]) {
            //this bumps everything down the max OML
            max10_freq[9] = max10_freq[8];
            max10_peak[9] = max10_peak[8];
            //new peak replaces the old peak
            max10_freq[8] = i * sample_rate / N;
            max10_peak[8] = magn;
        }
        else if (magn > max10_peak[9]) {
            //new peak replaces the old peak
            max10_freq[9] = i * sample_rate / N;
            max10_peak[9] = magn;
        }
    }

    //display the one_sided FFT with time indices
    if (wants_CSV) {
        std::ofstream one_sided;
        one_sided.open("input_fft_one_sided.csv");
        one_sided << "FFT of Input Signal\n";
        one_sided << "Freq (Hz),Mag (Normalized for N)\n";
        for (int i = 0; i < N / 2; ++i)
        {
            one_sided << i*sample_rate/N << ","
                      << std::abs(data[i]) << "\n";
        }
        one_sided.close();
    }
    

      
    //actually do the inverse fft
    std::cout << "Conducting inverse FFT...\n";
    ifft(data);

    if (wants_CSV) {
        //initialize a csv for the time domain reconstruction to visualize it
        std::cout << "Outputting reconstructed signal to CSV file...\n";
        std::ofstream output_time_domain;
        output_time_domain.open("output.csv");
        output_time_domain << "Time-Domain Reconstruction of Signal\n";
        output_time_domain << "i,Time,Signal\n";
        for (int i = 0; i < N; ++i)
        {
            output_time_domain << i << ","
                << i / sample_rate << ","
                << data[i].real() << "\n";
        }
        output_time_domain.close();
    }
   
       
    std::cout << "FFT operations complete.\n";
    std::cout << "Strongest Frequencies Relative to Peak Frequency: \n\n";
    std::cout << "###########################################################\n";
    std::cout << "## Frequency              ## Relative Strength           ##\n";
    for (int i = 0; i < 10; i++) {
        std::cout << "## " << freq_classify(max10_freq[i]) << "         ## " << std::to_string(max10_peak[i] / max10_peak[0]) << "                    ##\n";
    }
    std::cout << "###########################################################\n";
   
    return 0;
}