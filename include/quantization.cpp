#include "quantization.h"
#include "const.h"

std::vector<int16_t> quantization(const std::vector<double>& signal){
    
    std::vector<int16_t> quant_sig;
    quant_sig.reserve(signal.size());

    for(double val : signal) {
        double clamped = val;
        if (clamped > 1.0) clamped = 1.0;
        if (clamped < -1.0) clamped = -1.0;

        double scaled = clamped * MAXPOINT;
        quant_sig.push_back(static_cast<int16_t>(round(scaled)));
    }

    return quant_sig;
}

double quantization_error(const std::vector<double>& signal, 
                          const std::vector<int16_t>& quant_sig){

    if (signal.size() != quant_sig.size()) {
        throw std::invalid_argument("signal and quant_sig must be equal size");
    }
    if (signal.empty()) return 0.0;

    double error = 0.0;
    double sum_errors = 0.0;

    for(size_t i = 0; i < signal.size(); ++i){
        double tmp = signal[i] - (quant_sig[i] / MAXPOINT);
        sum_errors += tmp * tmp;
    }

    error = sqrt(sum_errors/signal.size());

    return error;
}