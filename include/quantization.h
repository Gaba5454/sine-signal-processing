#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

std::vector<int16_t> quantization(const std::vector<double>& signal);
double quantization_error(const std::vector<double>& signal, 
                       const std::vector<int16_t>& quant_sig);