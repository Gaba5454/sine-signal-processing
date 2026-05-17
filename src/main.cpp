#include <iostream>
#include <vector>
#include <cmath>
#include "../include/sine_generator.h"
#include "../include/quantization.h"
#include "../include/interpolation.h"

int main() {

    double f = 33;
    double fs = 100;
    int num_samples = 50;

    std::vector<double> signal = sine_generator(f,fs,num_samples);
    for(size_t i = 0; i < 5; ++i){
        std::cout << signal[i] << " ";
    }
    std::vector<int16_t> quant_sig = quantization(signal);
    double error = quantization_error(signal, quant_sig);

    std::cout << "\n" << error << "\n";
    
    std::vector<double> inter_sig = linear_interpolation(signal);

    for(size_t i = 0; i < 10; ++i){
        std::cout << inter_sig[i] << " ";
    }
    std::cout << "\n";
    return 0;

}