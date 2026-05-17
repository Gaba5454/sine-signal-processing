#include "tests.h"


double TestFloatQuantizationNoise(double freq, double fs, int num_samples) {
    // 1. Генератор синуса, на частоте которая задается вручную
    std::vector<double> signal = sine_generator(freq, fs, num_samples);

    // 2. Операция квантования и обработка ошибки квантования
    std::vector<int16_t> quant_sig = quantization(signal);
    double error = quantization_error(signal, quant_sig);
    std::cout << error << "\n";
    return error;
}

void WriteQuantizationResultToCsv(const std::string& filepath, double freq_hz, double error) {

    std::ofstream file(filepath, std::ios::app);
    
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filepath << "\n";
        return;
    }
    
    if (file.tellp() == 0) {
        file << "freq_hz, error\n";  
    }
    
    file << freq_hz << ",     " << error << "\n";
    
    file.close();
}



double TestFloatQualityOfInterpolation(double freq, double fs, double num_samples) {

    // 1. Генератор синуса, на частоте которая задается вручную
    std::vector<double> signal = sine_generator(freq, fs, num_samples);
    std::vector<double> signal_ideal = sine_generator(freq, fs * 2, num_samples * 2);

    // 2. Функция интерполяции с плавающей точкой
    std::vector<double> inter_sig = linear_interpolation_float_point(signal);
    
    // 3. Анализ интерполяции
    double error = interpolation_error_float_point(signal_ideal, inter_sig);

    return error;
}

void WriteRedultsInterpolationToCsv(const std::string& filepath, double freq_hz, double fs, double error){

    std::ofstream file(filepath, std::ios::app);
    
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filepath << "\n";
        return;
    }
    
    if (file.tellp() == 0) {
        file << "freq_hz, fs, error\n";  
    }
    
    file << freq_hz << ",     " << fs << ",   " << error << "\n";
    
    file.close();
}

    //     // 1. Генератор синуса, на частоте которая задается вручную
    // std::vector<double> signal100 = sine_generator(freq_hz, fs_low, num_samples);
    // std::vector<double> signal200 = sine_generator(freq_hz, fs_high, num_samples2);

    // // 2. Операция квантования и обработка ошибки квантования
    // std::vector<int16_t> quant_sig = quantization(signal100);
    // double error = quantization_error(signal100, quant_sig);

    // std::vector<int16_t> quant_sig2 = quantization(signal200);
    // error = quantization_error(signal200, quant_sig2);

    // // 3. Функция интерполяции с плавающей точкой
    // std::vector<double> inter_sig = linear_interpolation_float_point(signal100);
    
    // // 4. Анализ интерполяции
    // error = interpolation_error_float_point(signal200, inter_sig);

    // // 5. Функия интерполяции с фиксированной точкой
    // std::vector<int16_t> inter_sig_quant = linear_interpolation_fixed_point(quant_sig);
    // error = interpolation_error_fixed_point(quant_sig2, inter_sig_quant);