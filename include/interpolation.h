#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include "const.h"
// Linear interpolation
std::vector<double> linear_interpolation_float_point(const std::vector<double>& signal);
std::vector<int16_t> linear_interpolation_fixed_point(const std::vector<int16_t>& quant_sig);
double interpolation_error_float_point(const std::vector<double>& signal, 
                                       const std::vector<double>& inter_sig);
double interpolation_error_fixed_point(const std::vector<int16_t>& signal, 
                                        const std::vector<int16_t>& inter_sig);

// Cubic interpolation
std::vector<double> cubicSpline_interpolation_float_point(const std::vector<double>& signal);
std::vector<int16_t> cubicSpline_interpolation_fixed_point(const std::vector<int16_t>& signal);
double interpolation_error_float(const std::vector<double>& ideal, 
                                 const std::vector<double>& interpolated);
double interpolation_error_fixed(const std::vector<int16_t>& ideal_quant, 
                                 const std::vector<int16_t>& interpolated_quant);