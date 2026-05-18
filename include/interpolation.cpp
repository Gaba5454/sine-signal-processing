#include "interpolation.h"
#include "const.h"

std::vector<double> linear_interpolation_float_point(const std::vector<double>& signal){
    if (signal.empty()) return {};

    std::vector<double> inter_sig;
    inter_sig.reserve(signal.size() * 2);

    for(size_t i = 0; i < signal.size() - 1; ++i) {
        inter_sig.push_back(signal[i]);
        double mid = (signal[i] + signal[i+1]) * 0.5;
        inter_sig.push_back(mid);
    }
    inter_sig.push_back(signal.back());
    inter_sig.push_back(signal.back());

    return inter_sig;
}

std::vector<int16_t> linear_interpolation_fixed_point(const std::vector<int16_t>& quant_sig){
    if (quant_sig.empty()) return {};

    std::vector<int16_t> inter_sig;
    inter_sig.reserve(quant_sig.size() * 2);

    for(size_t i = 0; i < quant_sig.size() - 1; ++i) {
        inter_sig.push_back(quant_sig[i]);
        int32_t sum = (int32_t)quant_sig[i] + (int32_t)quant_sig[i+1];
        int16_t mid = sum / 2;
        inter_sig.push_back(mid);
    }
    inter_sig.push_back(quant_sig.back());
    inter_sig.push_back(quant_sig.back());

    return inter_sig;
}


double interpolation_error_float_point(const std::vector<double>& ideal_signal, 
                                       const std::vector<double>& inter_signal) {
    if (ideal_signal.size() != inter_signal.size()) {
        throw std::invalid_argument("size must match(floated)");
    }
    if (ideal_signal.empty()) return 0.0;

    double error = 0.0;
    double sum_errors = 0.0;

    for(size_t i = 0; i < ideal_signal.size(); ++i){
        double tmp = ideal_signal[i] - inter_signal[i];
        sum_errors += tmp * tmp;
    }

    error = sqrt(sum_errors/ideal_signal.size());

    return error;
}

double interpolation_error_fixed_point(const std::vector<int16_t>& ideal_quantized, 
                                       const std::vector<int16_t>& interpolated_quantized) {
    if (ideal_quantized.size() != interpolated_quantized.size()) {
        throw std::invalid_argument("size must match(fixed)");
    }
    if (ideal_quantized.empty()) return 0.0;

    double error = 0.0;
    double sum_errors = 0.0;

    for(size_t i = 0; i < ideal_quantized.size(); ++i){
        double val_ideal = ideal_quantized[i] / MAXPOINT;
        double val_fixed = interpolated_quantized[i] / MAXPOINT;

        double tmp = val_ideal - val_fixed;
        sum_errors += tmp * tmp;
    }

    error = std::sqrt(sum_errors/ideal_quantized.size());

    return error;
}
