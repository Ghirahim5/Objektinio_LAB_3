#include "funkcijos.h"

using namespace std;

double bendras_laikas_1 = 0;
double bendras_laikas_2 = 0;
double bendras_laikas_3 = 0;
double bendras_laikas_4 = 0;
double bendras_laikas_5 = 0;
double bendras_laikas_6 = 0;
int vykdymu_skaicius_1 = 0;
int vykdymu_skaicius_2 = 0;

int main() {

    deque<Studentas> Duomenys;  // Deque skirtas saugoti studentu duomenims
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

            bendras_laikas_1 += laikas;
            vykdymu_skaicius_1++;

            cout << "Keliu testu laiku vidurkis: " << bendras_laikas_1 / vykdymu_skaicius_1 << " sekundes" << endl;
            cout << endl;

        } break;

        case 6: {
            deque<double> trukme_count = Testavimas(Duomenys);

            bendras_laikas_2 += trukme_count[0];
            bendras_laikas_3 += trukme_count[1];
            bendras_laikas_4 += trukme_count[2];
            bendras_laikas_5 += trukme_count[3];
            bendras_laikas_6 += trukme_count[4];

            vykdymu_skaicius_2++;

            cout << "Duomenu nuskaitymo is failo laiku vidurkis: " << bendras_laikas_3 / vykdymu_skaicius_2 << " sekundziu" << endl;
            cout << "Studentu rusiavimo i atskirus deques laiku vidurkis: " << bendras_laikas_4 / vykdymu_skaicius_2 << " sekundziu" << endl;
            cout << "Studentu rikiavimo didejimo arba mazejimo tvarka laiku vidurkis: " << bendras_laikas_5 / vykdymu_skaicius_2 << " sekundziu" << endl;
            //cout << "Studentu irasymo i atskirus failus laiku vidurkis: " << bendras_laikas_6/ vykdymu_skaicius_2 << " sekundziu" << endl;
            cout << "Visos programos veikimo laiku vidurkis: " << bendras_laikas_2 / vykdymu_skaicius_2 << " sekundziu" << endl;
            cout << endl;
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