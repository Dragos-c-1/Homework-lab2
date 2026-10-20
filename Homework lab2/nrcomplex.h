#ifndef complex
#define complex

#include <cmath>

struct nrComplex {
    float a; // partea reala
    float b; // partea imaginara
};

// Supraincarcare 1: modulul unui numar real (float)
inline float modul(float x) {
    return (x < 0.0f) ? -x : x;
}

// Supraincarcare 2: modulul unui numar complex (|z| = sqrt(a^2 + b^2))
inline float modul(nrComplex z) {
    return std::sqrt(z.a * z.a + z.b * z.b);
}

#endif 