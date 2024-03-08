#include <iostream>
#include <vector>
#include "funkcijos.h"

using namespace std;

double bendras_laikas = 0;
int vykdymu_skaicius = 0;

int main() {

    vector<Studentas> Duomenys;  // Vektorius skirtas saugoti studentu duomenims
    srand(time(NULL));
    int veiksmas;
    string pavadinimas;

    while (true) {
        cout << endl;
        cout << "1 - Vesti duomenis rankiniu budu" << endl;
        cout << "2 - Generuoti pazymius" << endl;
        cout << "3 - Generuoti ir pazymius ir studentu vardus" << endl;
        cout << "4 - Generuoti studentu duomenu faila" << endl;
        cout << "5 - Nuskaityti duomenis is failo" << endl;
        cout << "6 - Testavimas" << endl;
        cout << "7 - Baigti darba" << endl;
        cout << endl;
        cout << "Pasirinkite veiksma ivesdami skaiciu: ";
        cin >> veiksmas;
        cout << endl;

        switch (veiksmas) {
        case 1:

            RankinisIvedimas(Duomenys);
            break;

        case 2:
            GeneruotiPazymius(Duomenys);
            break;

        case 3:
            GeneruotiPazymiusVardus();
            break;

        case 4:
            GeneruotiFailus();
            break;

        case 5: {
            double laikas = Skaitymas(Duomenys);
            RusiuotiSpausdinti(Duomenys, laikas, pavadinimas);

            bendras_laikas += laikas;
            vykdymu_skaicius++;

            cout << "Keliu testu laiku vidurkis: " << bendras_laikas / vykdymu_skaicius << " sekundes" << endl;
            cout << endl;

        } break;

        case 6: {
            Testavimas(Duomenys);
            break;
        } 
        case 7:
            cout << "Programa baigia darba." << endl;
            return 0;

        default:
            cout << "Neteisinga ivestis, prasome ivesti viena is pateiktu pasirinkimo variantu" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
        }
    }
}