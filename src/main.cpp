#include <iostream>
#include <vector>
#include <cmath>
#include "../include/tests.h"
int main() {

    constexpr double fs = 100.0;
    constexpr int num_samples = 50;

    for (double freq : {2.0, 10.0, 25.0, 33.0, 49.0}) {
    std::string csv_path = "../results/QuantizationNoiseData.csv";
    double error = test_quantizationNoise(freq, fs, num_samples);
    writeResults_quantizationt_toCsv(csv_path, freq, error);

    std::string csv_path_float = "../results/FloatQualityOfInterpolationData.csv";
    double float_error = test_qualityInterpolation_float(freq, fs, num_samples);
    writeResults_floatInterpolation_toCsv(csv_path_float, freq, fs, float_error);    

    std::string csv_path_int = "../results/IntQualityOfInterpolationData.csv";
    double fixed_error = test_qualityIterpolation_fixed(freq, fs, num_samples);
    writeResults_fixedInterpolation_toCsv(csv_path_int, freq, fs, fixed_error);

    std::string csv_path_all = "../results/AllQualityOfInterpolationData.csv";
    writeResults_allInterpolation_toCsv(csv_path_all, freq, fs, float_error, fixed_error);
    }
    return 0;

}

// Написать ещё один метод интерполяции
