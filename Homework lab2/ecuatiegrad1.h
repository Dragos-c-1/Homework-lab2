#ifndef ecg1
#define ecg1

#include <string>
#include <stdexcept>

inline double rezolvaEcuatie(double a, double b) {
    if (a == 0.0) {
        if (b == 0.0) {
            // 0 * x + 0 = 0
            throw std::runtime_error("Ecuatia are o infinitate de solutii (0 = 0).");
        }
        else {
            // 0 * x + b = 0, b != 0
            throw std::runtime_error("Ecuatia nu are solutii (imposibil: 0 * x + b = 0 cu b != 0).");
        }
    }
    return -b / a;
}

#endif 