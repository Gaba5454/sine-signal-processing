#include "interpolation.h"

std::vector<double> linear_interpolation(const std::vector<double>& signal){
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

// добавить ещё парочку методов интерполяции