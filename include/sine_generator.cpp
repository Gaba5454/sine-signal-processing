#include "sine_generator.h"

/**
 * Генератор синусоидального сигнала
 * 
 * @param f_hz Частота сигнала (от 0 до 50 Гц)
 * @param fs_hz Частота дискретизации (фиксирована 100 Гц)
 * @param num_samples Количество отсчетов (длина сигнала)
 * @return std::vector<double> Массив сгенерированных значений
 *
 */

std::vector<double> sine_generator(double f_hz, double fs_hz, int num_samples) {
    std::vector<double> signal;
    signal.reserve(num_samples); 

    // Защита от некорректных данных
    if (fs_hz <= 0) {
        throw std::invalid_argument("fs_hz must be positive");
    }
    
    for (int n = 0; n < num_samples; ++n) {
        // Формула дискретного синуса:
        // x[n] = sin(2 * pi * f * n / Fs)
        // где n/Fs - это время t в секундах для n-го отсчета
        
        double phase = 2.0 * M_PI * f_hz * n / fs_hz;
        double value = std::sin(phase);
        
        signal.push_back(value);
    }

    return signal;
}