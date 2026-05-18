#include "tests.h"


double test_quantizationNoise(double freq, double fs, int num_samples) {

    std::vector<double> signal = sine_generator(freq, fs, num_samples);

    std::vector<int16_t> quant_sig = quantization(signal);
    double error = quantization_error(signal, quant_sig);
    std::cout << error << "\n";
    return error;
}

void writeResults_quantizationt_toCsv(const std::string& filepath, double freq, double error) {

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



double test_qualityInterpolation_float(double freq, double fs, int num_samples) {

    std::vector<double> signal = sine_generator(freq, fs, num_samples);
    std::vector<double> signal_ideal = sine_generator(freq, fs * 2, num_samples * 2);

    std::vector<double> inter_sig = linear_interpolation_float_point(signal);
    
    double error = interpolation_error_float_point(signal_ideal, inter_sig);

    return error;
}

void writeResults_floatInterpolation_toCsv(const std::string& filepath, double freq, double fs, double error){

    std::ofstream file(filepath, std::ios::app);
    
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filepath << "\n";
        return;
    }
    
    if (file.tellp() == 0) {
        file << "freq_hz,fs,error\n";  
    }
    
    file << freq << "," << fs << "," << error << "\n";
    
    file.close();
}



double test_qualityIterpolation_fixed(double freq, double fs, int num_samples) {

    std::vector<double> signal = sine_generator(freq, fs, num_samples);
    std::vector<double> signal_ideal = sine_generator(freq, fs * 2, num_samples * 2);
   
    std::vector<int16_t> quant_sig = quantization(signal);

    std::vector<int16_t> quant_sig_ideal = quantization(signal_ideal);

    std::vector<int16_t> inter_sig_quant = linear_interpolation_fixed_point(quant_sig);

    double error = interpolation_error_fixed_point(quant_sig_ideal, inter_sig_quant);
    
    return error;
}

void writeResults_fixedInterpolation_toCsv(const std::string& filepath, double freq, double fs, double error){

    std::ofstream file(filepath, std::ios::app);
    
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filepath << "\n";
        return;
    }
    
    if (file.tellp() == 0) {
        file << "freq_hz,fs,error\n";  
    }
    
    file << freq << "," << fs << "," << error << "\n";
    
    file.close();
}

void writeResults_allInterpolation_toCsv(const std::string& filepath, double freq, double fs, double float_error, double fixed_error){
    
    std::ofstream file(filepath, std::ios::app);
    
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filepath << "\n";
        return;
    }
    
    if (file.tellp() == 0) {
        file << "freq_hz,fs,float_err,fixed_err,difference\n";  
    }
    double difference = std::abs(float_error - fixed_error);
    file << freq << "," << fs << "," << float_error << "," << fixed_error << "," << difference <<"\n";
    
    file.close();
}