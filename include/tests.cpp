#include "tests.h"

void run_test_interpolation(double freq_hz, double fs_low, double fs_high, double num_samples, double num_samples2) {
    
        // 1. Генератор синуса, на частоте которая задается вручную
    std::vector<double> signal100 = sine_generator(freq_hz, fs_low, num_samples);
    std::vector<double> signal200 = sine_generator(freq_hz, fs_high, num_samples2);

    // 2. Операция квантования и обработка ошибки квантования
    std::vector<int16_t> quant_sig = quantization(signal100);
    double error = quantization_error(signal100, quant_sig);

    std::vector<int16_t> quant_sig2 = quantization(signal200);
    error = quantization_error(signal200, quant_sig2);

    // 3. Функция интерполяции с плавающей точкой
    std::vector<double> inter_sig = linear_interpolation_float_point(signal100);
    
    // 4. Анализ интерполяции
    error = interpolation_error_float_point(signal200, inter_sig);

    // 5. Функия интерполяции с фиксированной точкой
    std::vector<int16_t> inter_sig_quant = linear_interpolation_fixed_point(quant_sig);
    error = interpolation_error_fixed_point(quant_sig2, inter_sig_quant);

    std::ofstream file("results/data.csv");
    file << "freq_hz,quant_error,interp_float_error,interp_fixed_error\n";
    // внутри цикла по частотам:
    file << f << "," << err_quant << "," << err_float << "," << err_fixed << "\n";
    file.close();
}