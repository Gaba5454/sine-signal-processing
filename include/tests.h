#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "sine_generator.h"
#include "quantization.h"
#include "interpolation.h"

double test_quantizationNoise(double freq, double fs, int num_samples);
void   writeResults_quantizationt_toCsv(const std::string& filepath, double freq, double error);


double test_qualityInterpolation_float(double freq, double fs, int num_samples);
void   writeResults_floatInterpolation_toCsv(const std::string& filepath, double freq, double fs, double error);

double test_qualityIterpolation_fixed(double freq, double fs, int num_samples);
void   writeResults_fixedInterpolation_toCsv(const std::string& filepath, double freq, double fs, double error);

double test_qualityCubicInterpolation_fixed(double freq, double fs, int num_samples);
double test_qualityCubicInterpolation_float(double freq, double fs, int num_samples);

void writeResults_allInterpolation_toCsv(const std::string& filepath, double freq, double fs, double float_error, double fixed_error);

