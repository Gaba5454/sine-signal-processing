#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include "const.h"

std::vector<double> linear_interpolation_float_point(const std::vector<double>& signal);
std::vector<int16_t> linear_interpolation_fixed_point(const std::vector<int16_t>& quant_sig);
double interpolation_error_float_point(const std::vector<double>& signal, 
                                       const std::vector<double>& inter_sig);
double interpolation_error_fixed_point(const std::vector<int16_t>& signal, 
                                        const std::vector<int16_t>& inter_sig);