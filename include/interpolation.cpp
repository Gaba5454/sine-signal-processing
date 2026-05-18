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

std::vector<double> cubicSpline_interpolation_float_point(const std::vector<double>& signal) {
    if (signal.empty()) return {};

    std::vector<double> inter_sig;
    inter_sig.reserve(signal.size() * 2);

    for(size_t i = 0; i < signal.size() - 1; ++i) {
        double p0 = signal[i];
        double p1 = signal[i + 1];

        double pm1;
        if (i == 0) {
            pm1 = p0;
        } else {
            pm1 = signal[i - 1];
        }

        double p2;
        if (i + 2 >= signal.size()) {
            p2 = p1;
        } else {
            p2 = signal[i+2];
        }

        double mid = (-pm1 + 9.0 * p0 + 9.0 * p1 - p2) / 16.0;

        inter_sig.push_back(p0);  
        inter_sig.push_back(mid); 
    }

    inter_sig.push_back(signal.back());
    inter_sig.push_back(signal.back()); 

    return inter_sig;
}

std::vector<int16_t> cubicSpline_interpolation_fixed_point(const std::vector<int16_t>& signal) {
    if (signal.empty()) return {};

    std::vector<int16_t> inter_sig;
    inter_sig.reserve(signal.size() * 2);

    for (size_t i = 0; i < signal.size() - 1; ++i) {

        int32_t p0  = signal[i];
        int32_t p1  = signal[i + 1];
        int32_t pm1 = (i == 0) ? p0 : static_cast<int32_t>(signal[i - 1]);
        int32_t p2  = (i + 2 >= signal.size()) ? p1 : static_cast<int32_t>(signal[i + 2]);

        int32_t numerator = -pm1 + 9 * p0 + 9 * p1 - p2;

        int32_t rounded = (numerator >= 0) ? (numerator + 8) / 16 
                                           : (numerator - 8) / 16;
    
        int16_t mid = static_cast<int16_t>(rounded);

        inter_sig.push_back(static_cast<int16_t>(p0));
        inter_sig.push_back(mid);
    }

    inter_sig.push_back(signal.back());
    inter_sig.push_back(signal.back());

    return inter_sig;
}

double interpolation_error_float(const std::vector<double>& ideal, 
                                 const std::vector<double>& interpolated) {
    if (ideal.size() != interpolated.size()) {
        throw std::invalid_argument("size must match(float)");
    }
    if (ideal.empty()) return 0.0;

    double sum_sq = 0.0;
    for (size_t i = 0; i < ideal.size(); ++i) {
        double diff = ideal[i] - interpolated[i];
        sum_sq += diff * diff;
    }
    return std::sqrt(sum_sq / ideal.size());
}

double interpolation_error_fixed(const std::vector<int16_t>& ideal_quant, 
                                 const std::vector<int16_t>& interpolated_quant) {
    if (ideal_quant.size() != interpolated_quant.size()) {
        throw std::invalid_argument("size must match(fixed)");
    }
    if (ideal_quant.empty()) return 0.0;

    double sum_sq = 0.0;
    constexpr double SCALE = 32767.0;

    for (size_t i = 0; i < ideal_quant.size(); ++i) {

        double v_ideal = ideal_quant[i] / SCALE;
        double v_interp = interpolated_quant[i] / SCALE;
        
        double diff = v_ideal - v_interp;
        sum_sq += diff * diff;
    }
    return std::sqrt(sum_sq / ideal_quant.size());
}