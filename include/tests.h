#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "sine_generator.h"
#include "quantization.h"
#include "interpolation.h"

double TestQuantizationNoise(double freq, double fs, int num_samples);
void   WriteQuantizationResultToCsv(const std::string& filepath, double freq, double error);

double TestFloatQualityOfInterpolation(double freq, double fs, int num_samples);
void   WriteResultsFloatInterpolationToCsv(const std::string& filepath, double freq, double fs, double error);

double TestIntQualityOfInterpolation(double freq, double fs, int num_samples);
void   WriteResultsIntInterpolationToCsv(const std::string& filepath, double freq, double fs, double error);