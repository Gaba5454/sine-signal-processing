#include <iostream>
#include <vector>
#include <cmath>
#include "../include/sine_generator.h"

int main() {

    double f = 10;
    double fs = 50;
    int num_samples = 50;
    std::vector<double> signal = sine_generator(f,fs,num_samples);

    for (size_t i = 0; i < signal.size(); i++){
        std::cout << signal[i] << "\n";
    }
    return 0;

}