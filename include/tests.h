#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "sine_generator.h"
#include "quantization.h"
#include "interpolation.h"

double TestFloatQuantizationNoise(double freq, double fs, int num_samples);
void   WriteQuantizationResultToCsv(const std::string& filepath, double freq_hz, double error);

double TestFloatQualityOfInterpolation(double freq, double fs, int num_samples);
void   WriteRedultsInterpolationToCsv(const std::string& filepath, double freq_hz, double fs, double error);