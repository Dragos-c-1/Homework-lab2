#include <iostream>
#include <string>
#include <limits>

#include "ariedreptunghi.h"
#include "nrcomplex.h"
#include "ecuatiegrad1.h"

using namespace std;

void afiseazaMeniu() {
    cout << "\n==========================================\n";
    cout << "         MENIU LABORATOR 2 (C++)          \n";
    cout << "==========================================\n";
    cout << "1. T.2.1: Arie Dreptunghi / Patrat \n";
    cout << "2. T.2.2: Valoare absoluta Real / Complex \n";
    cout << "3. T.2.3: Rezolvare ax + b = 0 \n";
    cout << "0. Iesire\n";
    cout << "Alege o optiune: ";
}

int main() {
    string optiuneStr;

    while (true) {
        afiseazaMeniu();

        if (!getline(cin, optiuneStr)) {
            break;
        }

        if (optiuneStr.empty()) {
            continue;
        }

        int optiune = -1;
        try {
            optiune = stoi(optiuneStr);
        }
        catch (...) {
            cout << "Optiune invalida! Introduceti o cifra valida.\n";
            continue;
        }

        if (optiune == 0) {
            cout << "Program finalizat.\n";
            break;
        }

        switch (optiune) {
        case 1: {
            cout << "\n--- T.2.1: Calcul Arie ---\n";
            cout << "Introduceti prima latura [Enter pt valoarea implicita \"5.5\"]: ";
            string lat1;
            getline(cin, lat1);
            if (lat1.empty()) lat1 = "5.5";

            cout << "Introduceti a doua latura [Enter pt Patrat]: ";
            string lat2;
            getline(cin, lat2);

            try {
                // Daca lat2 e gol, se apeleaza cu default argument pentru patrat
                double arie = lat2.empty() ? calculeazaArie(lat1) : calculeazaArie(lat1, lat2);
                cout << "-> Arie calculata cu succes: " << arie << "\n";
            }
            catch (const exception& e) {
                cout << "-> [Exceptie prinsa]: " << e.what() << "\n";
            }
            break;
        }

        case 2: {
            cout << "\n--- T.2.2: Modul Real vs Complex ---\n";
            // Modul Real
            cout << "Introduceti un numar real [Enter pt -15.75]: ";
            string realStr;
            getline(cin, realStr);
            float valReal = realStr.empty() ? -15.75f : stof(realStr);
            cout << "-> Modulul real: |" << valReal << "| = " << modul(valReal) << "\n";

            // Modul Complex
            cout << "Introduceti partea reala 'a' a complexului [Enter pt 3]: ";
            string aStr;
            getline(cin, aStr);
            float a = aStr.empty() ? 3.0f : stof(aStr);

            cout << "Introduceti partea imaginara 'b' a complexului [Enter pt 4]: ";
            string bStr;
            getline(cin, bStr);
            float b = bStr.empty() ? 4.0f : stof(bStr);

            nrComplex z = { a, b };
            cout << "-> Modulul complex: |" << z.a << " + " << z.b << "i| = " << modul(z) << "\n";
            break;
        }

        case 3: {
            cout << "\n--- T.2.3: Rezolvare ax + b = 0 ---\n";
            cout << "Introduceti coeficientul 'a' [Enter pt 2]: ";
            string aStr;
            getline(cin, aStr);
            double a = aStr.empty() ? 2.0 : stod(aStr);

            cout << "Introduceti coeficientul 'b' [Enter pt -8]: ";
            string bStr;
            getline(cin, bStr);
            double b = bStr.empty() ? -8.0 : stod(bStr);

            try {
                double x = rezolvaEcuatie(a, b);
                cout << "-> Ecuatia " << a << "x + (" << b << ") = 0 are solutia x = " << x << "\n";
            }
            catch (const exception& e) {
                cout << "-> [Exceptie prinsa]: " << e.what() << "\n";
            }
            break;
        }

        default:
            cout << "Optiune invalida! Incercati din nou.\n";
            break;
        }
    }

    return 0;
}