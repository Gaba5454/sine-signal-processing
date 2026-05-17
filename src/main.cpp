#include <iostream>
#include <vector>
#include <cmath>
#include "../include/sine_generator.h"
#include "../include/quantization.h"
int main() {

    double f = 10;
    double fs = 50;
    int num_samples = 50;

    std::vector<double> signal = sine_generator(f,fs,num_samples);
    std::vector<int16_t> quant_sig = quantization(signal);
    double error = quantization_error(signal, quant_sig);
    std::cout << error;
    return 0;

}