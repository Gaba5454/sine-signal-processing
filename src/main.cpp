#include <iostream>
#include <vector>
#include <cmath>
#include "../include/sine_generator.h"
#include "../include/quantization.h"
#include "../include/interpolation.h"

int main() {

    const double f = 2.0;
    const double fs_low = 100.0;
    const double fs_high = 200.0;
    const int num_samples = 50;
    const int num_samples2 = 100;

    // 1. Генератор синуса, на частоте которая задается вручную
    std::vector<double> signal100 = sine_generator(f, fs_low, num_samples);
    std::vector<double> signal200 = sine_generator(f, fs_high, num_samples2);

    // 2. Операция квантования и обработка ошибки квантования
    std::vector<int16_t> quant_sig = quantization(signal100);
    double error = quantization_error(signal100, quant_sig);
    std::cout << error<< "\n";

    std::vector<int16_t> quant_sig2 = quantization(signal200);
    error = quantization_error(signal200, quant_sig2);
    std::cout << error<< "\n";

    // 3. Функция интерполяции с плавающей точкой
    std::vector<double> inter_sig = linear_interpolation_float_point(signal100);
    
    // 4. Анализ интерполяции
    error = interpolation_error_float_point(signal200, inter_sig);

    // 5. Функия интерполяции с фиксированной точкой
    std::vector<int16_t> inter_sig_quant = linear_interpolation_fixed_point(quant_sig);
    error = interpolation_error_fixed_point(quant_sig2, inter_sig_quant);

    return 0;

}