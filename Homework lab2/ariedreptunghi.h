#ifndef ARIE
#define ARIE

#include <string>
#include <stdexcept>

// Functie helper pentru validarea si conversia unui string in double strict pozitiv
inline double parsePozitiv(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("Inputul nu poate fi gol!");
    }
    size_t idx = 0;
    double val = 0.0;
    try {
        val = std::stod(str, &idx);
    }
    catch (...) {
        throw std::invalid_argument("Conversia a esuat pentru valoarea: \"" + str + "\"");
    }

    // Daca au ramas caractere neconvertite (ex: "192a")
    if (idx < str.length()) {
        throw std::invalid_argument("Valoarea contine caractere invalide: \"" + str + "\"");
    }

    if (val <= 0.0) {
        throw std::invalid_argument("Dimensiunea trebuie sa fie un numar strict pozitiv!");
    }

    return val;
}

// Functia standard de calcul arie
inline double calculArieDreptunghi(double l, double L) {
    return l * L;
}

// Functia ceruta: parametri string, b cu valoare implicita (""), pointer la functie
inline double calculeazaArie(const std::string& a,
    const std::string& b = "",
    double (*formula)(double, double) = calculArieDreptunghi) {
    double l1 = parsePozitiv(a);
    // Daca b este gol, consideram ca este patrat (lungime egala pentru ambele laturi)
    double l2 = b.empty() ? l1 : parsePozitiv(b);

    return formula(l1, l2);
}

#endif 