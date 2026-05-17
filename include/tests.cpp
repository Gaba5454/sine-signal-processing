#include "tests.h"


double TestQuantizationNoise(double freq, double fs, int num_samples) {
    // 1. Генератор синуса, на частоте которая задается вручную
    std::vector<double> signal = sine_generator(freq, fs, num_samples);

    // 2. Операция квантования и обработка ошибки квантования
    std::vector<int16_t> quant_sig = quantization(signal);
    double error = quantization_error(signal, quant_sig);
    std::cout << error << "\n";
    return error;
}

void WriteQuantizationResultToCsv(const std::string& filepath, double freq, double error) {

    std::ofstream file(filepath, std::ios::app);
    
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filepath << "\n";
        return;
    }
    
    if (file.tellp() == 0) {
        file << "freq_hz,error\n";  
    }
    
    file << freq << "," << error << "\n";
    
    file.close();
}



double TestFloatQualityOfInterpolation(double freq, double fs, int num_samples) {

    // 1. Генератор синуса, на частоте которая задается вручную
    std::vector<double> signal = sine_generator(freq, fs, num_samples);
    std::vector<double> signal_ideal = sine_generator(freq, fs * 2, num_samples * 2);

    // 2. Функция интерполяции с плавающей точкой
    std::vector<double> inter_sig = linear_interpolation_float_point(signal);
    
    // 3. Анализ интерполяции
    double error = interpolation_error_float_point(signal_ideal, inter_sig);

    return error;
}

void WriteResultsFloatInterpolationToCsv(const std::string& filepath, double freq, double fs, double error){

    std::ofstream file(filepath, std::ios::app);
    
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filepath << "\n";
        return;
    }
    
    if (file.tellp() == 0) {
        file << "freq_hz,fs, error\n";  
    }
    
    file << freq << "," << fs << "," << error << "\n";
    
    file.close();
}



double TestIntQualityOfInterpolation(double freq, double fs, int num_samples) {

    // Генератор синуса
    std::vector<double> signal = sine_generator(freq, fs, num_samples);
    std::vector<double> signal_ideal = sine_generator(freq, fs * 2, num_samples * 2);
   
    // Операция квантования для сигнала под интерполяцию
    std::vector<int16_t> quant_sig = quantization(signal);

    // Операция квантования для эталонного сигнала
    std::vector<int16_t> quant_sig_ideal = quantization(signal_ideal);

    // Функция интерполяции с фиксированной точкой
    std::vector<int16_t> inter_sig_quant = linear_interpolation_fixed_point(quant_sig);

    // Анализ интерполяции
    double error = interpolation_error_fixed_point(quant_sig_ideal, inter_sig_quant);
    
    return error;
}

void WriteResultsIntInterpolationToCsv(const std::string& filepath, double freq, double fs, double error){

    std::ofstream file(filepath, std::ios::app);
    
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filepath << "\n";
        return;
    }
    
    if (file.tellp() == 0) {
        file << "freq_hz, fs, error\n";  
    }
    
    file << freq << "," << fs << "," << error << "\n";
    
    file.close();
}


