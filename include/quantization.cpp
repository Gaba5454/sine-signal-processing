#include "quantization.h"

std::vector<int16_t> quantization(const std::vector<double>& signal){
    
    std::vector<int16_t> quant_sig;
    quant_sig.reserve(signal.size());

    for(size_t i = 0; i < signal.size(); i++) {
        quant_sig.push_back(round(signal[i] * 32767.0));
    }

    return quant_sig;
}