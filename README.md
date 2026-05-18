# Sine Signal Processing Project

Проект по цифровой обработке сигналов: генерация, квантование и интерполяция синусоидального сигнала с анализом точности методов.


```bash
# Сборка проекта
mkdir build && cd build
cmake ..
make

# Запуск тестов
./SineSignalProcessing

# Результаты сохраняются в папке results/
```

--- 

# Структура проекта 

sine-signal-processing/
    src/                       # Исходный код
        main.cpp               # Точка входа, запуск всех тестов
    include/                   # Заголовочные файлы и реализации
        const.h                # Константы проекта 
        sine_generator.h/.cpp  # Генерация синусоидального сигнала
        quantization.h/.cpp    # Квантование в int16_t
        interpolation.h/.cpp   # Интерполяция (Linear + Cubic Spline)
        tests.h/.cpp           # Функции для тестирования кода
    results/                                # Результаты тестирования (CSV)
        report.md                           # Отчёт о проделанной работе
        QuantizationNoiseData.csv           # Ошибки квантования
        float_linearinterpolation_Data.csv  # Linear (Float)
        fixed_linearinterpolation_Data.csv  # Linear (Fixed-Point)
        all_linearinterpolation_Data.csv    # Linear (Float vs Fixed)
        fixed_cubicinterpolation_Data.csv   # Cubic (Fixed-Point)
        float_cubicinterpolation_Data.csv   # Cubic (Float-Point)
        all_cubicinterpolation_Data.csv     # Cubic (Float vs Fixed)

    README.md               # Описание проекта
    CMakeLists.txt          # Система сборки CMake
    gitignore               # Игнорируемые файлы Git