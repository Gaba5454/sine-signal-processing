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

    //  ================ Linear interpolation
    std::string csv_path_float_linear = "../results/float_linearInterpolation_Data.csv";
    double float_error_linear = test_qualityInterpolation_float(freq, fs, num_samples);
    writeResults_floatInterpolation_toCsv(csv_path_float_linear, freq, fs, float_error_linear);    

    std::string csv_path_int_linear = "../results/fixed_linearInterpolation_Data.csv";
    double fixed_error_linear = test_qualityIterpolation_fixed(freq, fs, num_samples);
    writeResults_fixedInterpolation_toCsv(csv_path_int_linear, freq, fs, fixed_error_linear);

    std::string csv_path_all_linear = "../results/all_linearInterpolation_Data.csv";
    writeResults_allInterpolation_toCsv(csv_path_all_linear, freq, fs, float_error_linear, fixed_error_linear);

    //  ================ Cubic spline interpolation
    std::string csv_path_float_cubic = "../results/float_cubicInterpolation_Data.csv";
    double float_error_cubic = test_qualityCubicInterpolation_float(freq, fs, num_samples);
    writeResults_floatInterpolation_toCsv(csv_path_float_cubic, freq, fs, float_error_cubic);    

    std::string csv_path_int_cubic = "../results/fixed_cubicInterpolation_Data.csv";
    double fixed_error_cubic = test_qualityCubicInterpolation_fixed(freq, fs, num_samples);
    writeResults_fixedInterpolation_toCsv(csv_path_int_cubic, freq, fs, fixed_error_cubic);

    std::string csv_path_all_cubic = "../results/all_cubicInterpolation_Data.csv";
    writeResults_allInterpolation_toCsv(csv_path_all_cubic, freq, fs, float_error_cubic, fixed_error_cubic);


    }

    return 0;

}
