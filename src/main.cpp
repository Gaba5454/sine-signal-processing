#include <iostream>
#include <vector>
#include <cmath>
#include "../include/tests.h"
int main() {

    const double fs = 100.0;
    const int num_samples = 50;

    for (double freq : {2.0, 10.0, 25.0, 33.0, 49.0}) {
    std::string csv_path = "results/QuantizationNoiseData.csv";
    double error = TestQuantizationNoise(freq, fs, num_samples);
    WriteQuantizationResultToCsv(csv_path, freq, error);

    csv_path = "results/FloatQualityOfInterpolationData.csv";
    error = TestFloatQualityOfInterpolation(freq, fs, num_samples);
    WriteResultsFloatInterpolationToCsv(csv_path, freq, fs, error);    

    csv_path = "results/IntQualityOfInterpolationData.csv";
    error = TestIntQualityOfInterpolation(freq, fs, num_samples);
    WriteResultsIntInterpolationToCsv(csv_path, freq, fs, error);
    }
    return 0;

}

// Магическое число 32767
// Сравнение float и int 