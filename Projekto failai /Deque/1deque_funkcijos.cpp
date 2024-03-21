#include "studentas.h"
#include "funkcijos.h"

using namespace std;
using namespace std::chrono;

void GeneruotiPazymius(deque<Studentas>& Duomenys) {
    Studentas studentas;

    cout << "Jei norite baigti iveskite zodi BAIGTI kaip studento varda arba pavarde" << endl;
    cout << endl;

    while (true) {
        try {
            cout << "Iveskite studento varda: ";
            cin >> studentas.v;
            cout << endl;
            if (studentas.v == "BAIGTI" || studentas.v == "Baigti" || studentas.v == "baigti") break;
            if (cin.fail() || any_of(studentas.v.begin(), studentas.v.end(), [](char c) { return !isalpha(c); })) {
                throw runtime_error("Neteisinga ivestis, prasome ivesti varda sudaryta is raidziu");
            }
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        try {
            cout << "Iveskite studento pavarde: ";
            cin >> studentas.p;
            cout << endl;
            if (studentas.p == "BAIGTI" || studentas.p == "Baigti" || studentas.p == "baigti") break;
            if (cin.fail() || any_of(studentas.p.begin(), studentas.p.end(), [](char c) { return !isalpha(c); })) {
                throw runtime_error("Neteisinga ivestis, prasome ivesti pavarde sudaryta is raidziu");
            }
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    // Egzamino rezultato generavimas

    studentas.egz_rez = (rand() % 10) + 1;

    // Namu darbu skaiciaus generavimas

    int n = (rand() % 10) + 1;

    studentas.nd_rez.resize(n);

    // Namu darbu rezultatu generavimas ir sumos skaiciavimas

    for (int j = 0; j < n; j++) {
        studentas.nd_rez[j] = (rand() % 10) + 1;
        studentas.nd_sum += studentas.nd_rez[j];
    }

    // Namu darbu masyvo rusiavimas

    sort(studentas.nd_rez.begin(), studentas.nd_rez.end());

    // Medianos skaiciavimas

    if (studentas.nd_rez.size() % 2 == 0) {
        studentas.mediana = (studentas.nd_rez[studentas.nd_rez.size() / 2 - 1] + studentas.nd_rez[studentas.nd_rez.size() / 2]) / 2.0;
    }
    else {
        studentas.mediana = studentas.nd_rez[studentas.nd_rez.size() / 2];
    }

    Duomenys.push_back(studentas);

    // Rezultatu spausdinimas pasirenkant Vid. arba Med.

    string pasirinkimas;
    cout << endl;
    cout << "Kaip norite matyti savo galutini bala?" << endl;
    cout << "1 - Vid." << endl;
    cout << "2 - Med." << endl;
    cout << endl;
    try {
        cout << "Iveskite pasirinkima: "; cin >> pasirinkimas;
        cout << endl;

        while (pasirinkimas != "1" && pasirinkimas != "2") {
            cout << "Pasirinkite arba '1' arba '2'" << endl;
            cin >> pasirinkimas;
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (pasirinkimas == "1") {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << endl;
        cout << "-----------------------------------------------" << endl;
        for (auto& studentas : Duomenys) {
            studentas.nd_vid = studentas.nd_sum / studentas.nd_rez.size();
            studentas.rez = 0.4 * studentas.nd_vid + 0.6 * studentas.egz_rez;
            cout << left << setw(15) << studentas.v << setw(15) << studentas.p << fixed << setprecision(2) << setw(15) << studentas.rez << endl;
        }
        cout << endl;
    }
    else {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Med.)" << endl;
        cout << "-----------------------------------------------" << endl;
        for (auto& studentas : Duomenys) {
            studentas.rez = 0.4 * studentas.mediana + 0.6 * studentas.egz_rez;
            cout << left << setw(15) << studentas.v << setw(15) << studentas.p << fixed << setprecision(2) << setw(15) << studentas.rez << endl;
        }
        cout << endl;
    }
    system("pause");
    system("cls");
}

void GeneruotiPazymiusVardus() {
    int m3;
    while (true) {
        try {
            cout << "Iveskite studentu skaiciu: "; cin >> m3;
            cout << endl;
            if (cin.fail() || m3 <= 0) {
                throw runtime_error("Neteisinga ivestis, prasome ivesti skaiciu");
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        catch (const exception& e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    deque<Studentas> Duomenys(m3); // Pakeistas vector i deque

    for (int i = 0; i < m3; i++) {
        // Masyvai saugantys visus variantus vardu ir pavardziu

        deque<string> VyriskiVardai = { "Arvydas", "Robertas", "Deivydas", "Marius", "Matas", "Jokubas", "Nojus", "Augustas", "Tomas", "Arnas" };
        deque<string> MoteriskiVardai = { "Gija", "Patricija", "Ieva", "Karolina", "Sandra", "Vita", "Aleksandra", "Liepa", "Smilte", "Guoste" };
        deque<string> VyriskosPavardes = { "Petrauskas", "Jankauskas", "Butkus", "Navickas", "Kazlauskas", "Urbanavicius", "Sadauskas", "Mazeika", "Kavaliauskas", "Adomaitis" };
        deque<string> MoteriskosPavardes = { "Kazlauskaite", "Petrauskaite", "Kavaliauskaite", "Jankauskaite", "Pociute", "Balciunaite", "Lukoseviciute", "Vasiliauskaite", "Butkute", "Leonaviciute" };

        // Vardo ir Pavardes generavimas

        if (rand() % 2 == 0) {
            Duomenys[i].v = VyriskiVardai[rand() % VyriskiVardai.size()];
            Duomenys[i].p = VyriskosPavardes[rand() % VyriskosPavardes.size()];
        }
        else {
            Duomenys[i].v = MoteriskiVardai[rand() % MoteriskiVardai.size()];
            Duomenys[i].p = MoteriskosPavardes[rand() % MoteriskosPavardes.size()];
        }

        // Namu darbu skaiciaus generavimas

        Duomenys[i].n = (rand() % 10) + 1;

        Duomenys[i].nd_rez.resize(Duomenys[i].n);

        // Namu darbu rezultatu generavimas

        for (int j = 0; j < Duomenys[i].n; j++) {
            Duomenys[i].nd_rez[j] = (rand() % 10) + 1;
            Duomenys[i].nd_sum += Duomenys[i].nd_rez[j];
        }
        Duomenys[i].egz_rez = (rand() % 10) + 1;  // Egzamino rezultato generavimas

        // Namu darbu masyvo rusiavimas

        sort(Duomenys[i].nd_rez.begin(), Duomenys[i].nd_rez.end());

        // Medianos skaiciavimas

        if (Duomenys[i].n % 2 == 0) {
            Duomenys[i].mediana = (Duomenys[i].nd_rez[Duomenys[i].n / 2 - 1] + Duomenys[i].nd_rez[Duomenys[i].n / 2]) / 2.0;
        }
        else {
            Duomenys[i].mediana = Duomenys[i].nd_rez[Duomenys[i].n / 2];
        }
    }

    // Rezultatu spausdinimas pasirenkant Vid. arba Med.

    string pasirinkimas;
    cout << "Kaip norite matyti savo galutini bala?" << endl;
    cout << "1 - Vid." << endl;
    cout << "2 - Med." << endl;
    cout << endl;
    try {
        cout << "Iveskite pasirinkima: "; cin >> pasirinkimas;
        cout << endl;

        while (pasirinkimas != "1" && pasirinkimas != "2") {
            cout << "Pasirinkite arba '1' arba '2'" << endl;
            cin >> pasirinkimas;
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (pasirinkimas == "1") {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << endl;
        cout << "-----------------------------------------------" << endl;
    }
    else {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Med.)" << endl;
        cout << "-----------------------------------------------" << endl;
    }

    for (int i = 0; i < m3; i++) {
        if (pasirinkimas == "1") {
            Duomenys[i].nd_vid = Duomenys[i].nd_sum / Duomenys[i].n;
            Duomenys[i].rez = 0.4 * Duomenys[i].nd_vid + 0.6 * Duomenys[i].egz_rez;
            cout << left << setw(15) << Duomenys[i].v << setw(15) << Duomenys[i].p << fixed << setprecision(2) << setw(15) << Duomenys[i].rez << endl;
        }
        else {
            Duomenys[i].rez = 0.4 * Duomenys[i].mediana + 0.6 * Duomenys[i].egz_rez;
            cout << left << setw(15) << Duomenys[i].v << setw(15) << Duomenys[i].p << fixed << setprecision(2) << setw(15) << Duomenys[i].rez << endl;
        }
    }
    cout << endl;
    system("pause");
    system("cls");
}

string PasirinktiFaila() {
    int pasirinkimas;
    string pavadinimas;

    cout << "Is kurio failo norit nuskaityti duomenis?" << endl;
    cout << endl;
    cout << "1 - 'kursiokai.txt'" << endl;
    cout << "2 - 'studentai1000.txt'" << endl;
    cout << "3 - 'studentai10000.txt'" << endl;
    cout << "4 - 'studentai100000.txt'" << endl;
    cout << "5 - 'studentai1000000.txt'" << endl;
    cout << "6 - 'studentai10000000.txt'" << endl;
    cout << endl;
    cout << "Iveskite pasirinkima: "; cin >> pasirinkimas;
    cout << endl;
    while (cin.fail() || pasirinkimas <= 0 || pasirinkimas > 6) {
        cout << "Neteisinga ivestis, prasome ivesti skaiciu nuo 1 iki 6" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> pasirinkimas;
    }
    switch (pasirinkimas) {
    case 1:
        pavadinimas = "kursiokai.txt";
        break;
    case 2:
        pavadinimas = "studentai1000.txt";
        break;
    case 3:
        pavadinimas = "studentai10000.txt";
        break;
    case 4:
        pavadinimas = "studentai100000.txt";
        break;
    case 5:
        pavadinimas = "studentai1000000.txt";
        break;
    case 6:
        pavadinimas = "studentai10000000.txt";
        break;
    }

    return pavadinimas;

    system("pause");
    system("cls");
}

double Skaitymas(deque<Studentas>& Duomenys) {
    Studentas studentas;
    string line;
    string pavadinimas;

    while (true) {
        try {
            pavadinimas = PasirinktiFaila();

            ifstream infile(pavadinimas);
            if (!infile) {
                throw runtime_error("Nepavyko atidaryti failo. Bandykite dar karta.");
            }

            auto pradzia = high_resolution_clock::now();

            getline(infile, line);

            while (getline(infile, line)) {
                istringstream iss(line);
                iss >> studentas.v >> studentas.p;

                double pazymys;
                while (iss >> pazymys) {
                    if (pazymys <= 0 || pazymys > 10) {
                        throw runtime_error("Neteisingas skaicius namu darbu rezultatuose.");
                    }
                    studentas.nd_rez.push_back(pazymys);
                }
                if (!studentas.nd_rez.empty()) {
                    studentas.egz_rez = studentas.nd_rez.back();
                    studentas.nd_rez.pop_back();
                }
                else {
                    cout << "Pasirinktas failas yra tuscias" << endl;
                    cout << endl;
                    pavadinimas = PasirinktiFaila();
                    continue;
                }

                Duomenys.push_back(studentas);
                studentas.nd_rez.clear();
            }
            infile.close();

            auto pabaiga = high_resolution_clock::now();
            duration<double> trukme = pabaiga - pradzia;
            double laikas = trukme.count();

            return laikas;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    system("pause");
    system("cls");
}

void RusiuotiSpausdinti(deque<Studentas>& Duomenys, double laikas, const string& pavadinimas) { // Pakeistas vector i deque

    string pasirinkimas, pasirinkimas1, pasirinkimas2, pasirinkimas3;

    cout << "Pagal ka norite rusiuoti rezultatus?" << endl;
    cout << "1 - Varda" << endl;
    cout << "2 - Pavarde" << endl;
    cout << "3 - Bala" << endl;
    cout << "4 - Kietiakais ir nuskriaustukais" << endl; // (studentai pagal vidurki rusiuojami i du atskirus failus Kietiakai - studentai su vidurkiu > 5 o nuskriaustukai - studentai su vidurkiu < 5)
    cout << endl;
    cout << "Iveskite pasirinkima: "; cin >> pasirinkimas3;
    while (pasirinkimas3 != "1" && pasirinkimas3 != "2" && pasirinkimas3 != "3" && pasirinkimas3 != "4") {
        cout << "Pasirinkite arba '1' arba '2' arba '3' arba '4'" << endl;
        cin >> pasirinkimas3;
    }
    if (pasirinkimas3 == "4") {
        RusiuotiGeraisBlogais(Duomenys);
        return;
    }
    cout << endl;
    cout << "Kaip norite matyti savo galutini bala?" << endl;
    cout << "1 - Vid." << endl;
    cout << "2 - Med." << endl;
    cout << endl;
    cout << "Iveskite pasirinkima: "; cin >> pasirinkimas;
    while (pasirinkimas != "1" && pasirinkimas != "2") {
        cout << "Pasirinkite arba '1' arba '2'" << endl;
        cin >> pasirinkimas;
    }

    cout << endl;
    cout << "Kokia tvarka norite rusiuoti rezultatus?" << endl;
    cout << "1 - Didejancia" << endl;
    cout << "2 - Mazejancia" << endl;
    cout << endl;
    cout << "Iveskite pasirinkima: "; cin >> pasirinkimas1;
    while (pasirinkimas1 != "1" && pasirinkimas1 != "2") {
        cout << "Pasirinkite arba '1' arba '2'" << endl;
        cin >> pasirinkimas1;
    }
    cout << endl;

    cout << "Kaip norite matyti rezultatus?" << endl;
    cout << "1 - Ekrane" << endl;
    cout << "2 - Faile" << endl;
    cout << endl;
    cout << "Iveskite pasirinkima: "; cin >> pasirinkimas2;
    while (pasirinkimas2 != "1" && pasirinkimas2 != "2") {
        cout << "Pasirinkite arba '1' arba '2'" << endl;
        cin >> pasirinkimas2;
    }
    cout << endl;

    // Rusiuojama pagal pasirinkta kriteriju
    if (pasirinkimas3 == "1") {
        if (pasirinkimas1 == "1")
            sort(Duomenys.begin(), Duomenys.end(), [](const Studentas& a, const Studentas& b) { return a.v > b.v; });
        else
            sort(Duomenys.begin(), Duomenys.end(), [](const Studentas& a, const Studentas& b) { return a.v < b.v; });
    }
    else if (pasirinkimas3 == "2") {
        if (pasirinkimas1 == "1")
            sort(Duomenys.begin(), Duomenys.end(), [](const Studentas& a, const Studentas& b) { return a.p > b.p; });
        else
            sort(Duomenys.begin(), Duomenys.end(), [](const Studentas& a, const Studentas& b) { return a.p < b.p; });
    }
    else if (pasirinkimas3 == "3") {
        if (pasirinkimas1 == "1")
            sort(Duomenys.begin(), Duomenys.end(), [](const Studentas& a, const Studentas& b) { return a.rez > b.rez; });
        else
            sort(Duomenys.begin(), Duomenys.end(), [](const Studentas& a, const Studentas& b) { return a.rez < b.rez; });
    }

    // Pasirenkamas spausdinimas i konsole arba faila
    if (pasirinkimas2 == "1") {
        if (pasirinkimas == "1") {
            cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
            cout << "-----------------------------------------------" << endl;
            for (const auto& studentas : Duomenys) {
                cout << left << setw(15) << studentas.v << setw(15) << studentas.p << fixed << setprecision(2) << setw(15) << studentas.rez << endl;
            }
            cout << endl;
        }
        else {
            cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Med.)" << endl;
            cout << "-----------------------------------------------" << endl;
            for (const auto& studentas : Duomenys) {
                cout << left << setw(15) << studentas.v << setw(15) << studentas.p << fixed << setprecision(2) << setw(15) << studentas.rez << endl;
            }
            cout << endl;
        }
    }
    else {
        // Rezultatu irasymas i faila
        ofstream outfile("rezultatai.txt");
        if (!outfile) {
            cerr << "Nepavyko sukurti rezultatu failo.";
            return;
        }
        if (pasirinkimas == "1") {
            outfile << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
            outfile << "-----------------------------------------------" << endl;
            for (const auto& studentas : Duomenys) {
                outfile << left << setw(15) << studentas.v << setw(15) << studentas.p << fixed << setprecision(2) << setw(15) << studentas.rez << endl;
            }
        }
        else {
            outfile << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Med.)" << endl;
            outfile << "-----------------------------------------------" << endl;
            for (const auto& studentas : Duomenys) {
                outfile << left << setw(15) << studentas.v << setw(15) << studentas.p << fixed << setprecision(2) << setw(15) << studentas.rez << endl;
            }
        }
        outfile.close();
        cout << "Rezultatai irasyti i faila rezultatai.txt" << endl;
    }
    system("pause");
    system("cls");
}

void RankinisIvedimas(deque<Studentas>& Duomenys) {

    Studentas studentas;
    double pazymys;

    cout << "Jei norite baigti iveskite zodi BAIGTI kaip studento varda arba pavarde" << endl;
    cout << endl;

    while (true) {
        try {
            cout << "Iveskite studento varda: ";
            cin >> studentas.v;
            cout << endl;
            if (studentas.v == "BAIGTI" || studentas.v == "Baigti" || studentas.v == "baigti") break;
            if (cin.fail() || any_of(studentas.v.begin(), studentas.v.end(), [](char c) { return !isalpha(c); })) {
                throw runtime_error("Neteisinga ivestis, prasome ivesti varda sudaryta is raidziu");
            }
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        while (true) {
            try {
                cout << "Iveskite studento pavarde: ";
                cin >> studentas.p;
                cout << endl;
                if (studentas.p == "BAIGTI" || studentas.p == "Baigti" || studentas.p == "baigti") break;
                if (cin.fail() || any_of(studentas.p.begin(), studentas.p.end(), [](char c) { return !isalpha(c); })) {
                    throw runtime_error("Neteisinga ivestis, prasome ivesti pavarde sudaryta is raidziu");
                }
                break;
            }
            catch (const exception& e) {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }

        while (true) {
            try {
                cout << "Iveskite studento namu darbu pazymi (jei norite baigti iveskite -1): " << endl;
                cin >> pazymys;
                cout << endl;
                if (cin.fail() || pazymys < -1 || pazymys > 10) {
                    throw runtime_error("Neteisinga ivestis, prasome ivesti skaiciu 10-baleje sistemoje");
                }
                if (pazymys == -1) break;
                studentas.nd_rez.push_back(pazymys);
            }
            catch (const exception& e) {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }

        // Egzamino rezultato ivestis
        while (true) {
            try {
                cout << "Koks buvo studento egzamino rezultatas?" << endl;
                cin >> studentas.egz_rez;
                cout << endl;
                if (cin.fail() || studentas.egz_rez < 0 || studentas.egz_rez > 10) {
                    throw runtime_error("Neteisinga ivestis, prasome ivesti skaiciu 10-baleje sistemoje");
                }
                break;
            }
            catch (const exception& e) {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }

        // Namu darbu sumos skaiciavimas
        studentas.nd_sum = accumulate(studentas.nd_rez.begin(), studentas.nd_rez.end(), 0.0);

        // Namu darbu masyvo rusiavimas
        sort(studentas.nd_rez.begin(), studentas.nd_rez.end());

        // Medianos skaiciavimas
        if (studentas.nd_rez.size() % 2 == 0) {
            studentas.mediana = (studentas.nd_rez[studentas.nd_rez.size() / 2 - 1] + studentas.nd_rez[studentas.nd_rez.size() / 2]) / 2.0;
        }
        else {
            studentas.mediana = studentas.nd_rez[studentas.nd_rez.size() / 2];
        }

        Duomenys.push_back(studentas);
    }

    // Rezultatu spausdinimas pasirenkant Vid. arba Med.

    string pasirinkimas;
    cout << "Kaip norite matyti savo galutini bala?" << endl;
    cout << "1 - Vid." << endl;
    cout << "2 - Med." << endl;
    cout << endl;
    try {
        cout << "Iveskite pasirinkima: "; cin >> pasirinkimas;
        cout << endl;

        while (pasirinkimas != "1" && pasirinkimas != "2") {
            cout << "Pasirinkite arba '1' arba '2'" << endl;
            cin >> pasirinkimas;
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (pasirinkimas == "1") {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << endl;
        cout << "-----------------------------------------------" << endl;
        for (auto& studentas : Duomenys) {
            studentas.nd_vid = studentas.nd_sum / studentas.nd_rez.size();
            studentas.rez = 0.4 * studentas.nd_vid + 0.6 * studentas.egz_rez;
            cout << left << setw(15) << studentas.v << setw(15) << studentas.p << fixed << setprecision(2) << setw(15) << studentas.rez << endl;
        }
    }
    else {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Med.)" << endl;
        cout << "-----------------------------------------------" << endl;
        for (auto& studentas : Duomenys) {
            studentas.rez = 0.4 * studentas.mediana + 0.6 * studentas.egz_rez;
            cout << left << setw(15) << studentas.v << setw(15) << studentas.p << fixed << setprecision(2) << setw(15) << studentas.rez << endl;
        }
    }
    cout << endl;
    system("pause");
    system("cls");
}

void GeneruotiFailus() {
    deque<Studentas> studentas;
    int m;
    int n;
    string pasirinkimas;

    while (true) {
        try {
            cout << "Iveskite pageidaujama saraso ilgi: "; cin >> m;
            cout << endl;
            if (cin.fail() || m < 1) {
                throw runtime_error("Neteisinga ivestis, prasome ivesti skaiciu didesni uz 0");
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        catch (const exception& e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) {
        try {
            cout << "Iveskite kiek is viso buvo namu darbu uzduociu: "; cin >> n;
            cout << endl;
            if (cin.fail() || n < 1) {
                throw runtime_error("Neteisinga ivestis, prasome ivesti skaiciu didesni uz 0");
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        catch (const exception& e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Kaip noretumete pavadinti faila?" << endl;
    cout << endl;
    cout << "Iveskite pageidaujama failo pavadinima: ";
    cin >> pasirinkimas;
    cout << endl;


    for (int i = 0; i < m; i++) {
        // Masyvai saugantys visus variantus vardu ir pavardziu

        deque<string> VyriskiVardai = { "Arvydas", "Robertas", "Deivydas", "Marius", "Matas", "Jokubas", "Nojus", "Augustas", "Tomas", "Arnas" };
        deque<string> MoteriskiVardai = { "Gija", "Patricija", "Ieva", "Karolina", "Sandra", "Vita", "Aleksandra", "Liepa", "Smilte", "Guoste" };
        deque<string> VyriskosPavardes = { "Petrauskas", "Jankauskas", "Butkus", "Navickas", "Kazlauskas", "Urbanavicius", "Sadauskas", "Mazeika", "Kavaliauskas", "Adomaitis" };
        deque<string> MoteriskosPavardes = { "Kazlauskaite", "Petrauskaite", "Kavaliauskaite", "Jankauskaite", "Pociute", "Balciunaite", "Lukoseviciute", "Vasiliauskaite", "Butkute", "Leonaviciute" };

        // Vardo ir Pavardes generavimas

        if (rand() % 2 == 0) {
            studentas[i].v = VyriskiVardai[rand() % VyriskiVardai.size()];
            studentas[i].p = VyriskosPavardes[rand() % VyriskosPavardes.size()];
        }
        else {
            studentas[i].v = MoteriskiVardai[rand() % MoteriskiVardai.size()];
            studentas[i].p = MoteriskosPavardes[rand() % MoteriskosPavardes.size()];
        }

        for (int j = 0; j < n; j++) {
            studentas[i].nd_rez.resize(n);
            studentas[i].nd_rez[j] = (rand() % 10) + 1;
            studentas[i].nd_sum += studentas[i].nd_rez[j];
        }
        studentas[i].egz_rez = (rand() % 10) + 1;  // Egzamino rezultato generavimas

    }

    ofstream outfile(pasirinkimas + ".txt");
    if (!outfile) {
        cerr << "Nepavyko sukurti rezultatu failo.";
        return;
    }
    outfile << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15);
    for (int i = 0; i < n; i++) {
        outfile << setw(10) << ("ND" + to_string(i + 1));
    }
    outfile << left << setw(15) << "Egz." << endl;

    for (const auto& studentas : studentas) {
        outfile << left << setw(15) << studentas.v << setw(15) << studentas.p << setw(20);
        for (int j = 0; j < n; j++) {
            outfile << setw(10) << studentas.nd_rez[j];
        }
        outfile << setw(10) << studentas.egz_rez << endl;
    }
    outfile.close();
    cout << "Rezultatai irasyti i faila: " << pasirinkimas << endl;
    system("pause");
    system("cls");
}

void RusiuotiGeraisBlogais(deque<Studentas>& Duomenys) {

    deque<Studentas> Kietiakai;
    deque<Studentas> Nuskriaustukai;

    string pasirinkimas;
    cout << "Kaip norite matyti savo galutini bala?" << endl;
    cout << "1 - Vid." << endl;
    cout << "2 - Med." << endl;
    cout << endl;
    try {
        cout << "Iveskite pasirinkima: "; cin >> pasirinkimas;
        cout << endl;

        while (pasirinkimas != "1" && pasirinkimas != "2") {
            cout << "Pasirinkite arba '1' arba '2'" << endl;
            cin >> pasirinkimas;
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (auto& studentas : Duomenys) {
        if (pasirinkimas == "1") {
            studentas.nd_vid = studentas.nd_sum / studentas.nd_rez.size();
            studentas.rez = 0.4 * studentas.nd_vid + 0.6 * studentas.egz_rez;
        }
        else {
            studentas.rez = 0.4 * studentas.mediana + 0.6 * studentas.egz_rez;
        }
    }

    for (auto& studentas : Duomenys) {
        if (studentas.rez >= 5) {
            Kietiakai.push_back(studentas);
        }
        else {
            Nuskriaustukai.push_back(studentas);
        }
    }

    // Patikriname, ar failai egzistuoja
    ifstream checkFile1("Kietiakai.txt");
    ifstream checkFile2("Nuskriaustukai.txt");
    if (checkFile1.good() || checkFile2.good()) {
        cout << "Vienas ar kiti failai jau egzistuoja, todel nebegalima juos perrasyti." << endl;
        return;
    }

    string pasirinkimas2;
    cout << "Kaip norite rikiuoti rezultatus?" << endl;
    cout << "1 - Didejimo tvarka." << endl;
    cout << "2 - Mazejimo tvarka." << endl;
    cout << endl;
    try {
        cout << "Iveskite pasirinkima: "; cin >> pasirinkimas2;
        cout << endl;

        while (pasirinkimas2 != "1" && pasirinkimas2 != "2") {
            cout << "Pasirinkite arba '1' arba '2'" << endl;
            cin >> pasirinkimas2;
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (pasirinkimas2 == "1") {
        sort(Kietiakai.begin(), Kietiakai.end(), [](const Studentas& a, const Studentas& b) { return a.rez < b.rez; });
        sort(Nuskriaustukai.begin(), Nuskriaustukai.end(), [](const Studentas& a, const Studentas& b) { return a.rez < b.rez; });
    }
    else {
        sort(Kietiakai.begin(), Kietiakai.end(), [](const Studentas& a, const Studentas& b) { return a.rez > b.rez; });
        sort(Nuskriaustukai.begin(), Nuskriaustukai.end(), [](const Studentas& a, const Studentas& b) { return a.rez > b.rez; });
    }

    ofstream outfile1("Kietiakai.txt");
    if (!outfile1) {
        cerr << "Nepavyko sukurti rezultatu failo.";
        return;
    }
    outfile1 << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
    outfile1 << "-----------------------------------------------" << endl;
    for (const auto& studentas : Kietiakai) {
        outfile1 << left << setw(15) << studentas.v << setw(15) << studentas.p << fixed << setprecision(2) << setw(15) << studentas.rez << endl;
    }
    outfile1.close();

    ofstream outfile2("Nuskriaustukai.txt");
    if (!outfile2) {
        cerr << "Nepavyko sukurti rezultatu failo.";
        return;
    }
    outfile2 << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
    outfile2 << "-----------------------------------------------" << endl;
    for (const auto& studentas : Nuskriaustukai) {
        outfile2 << left << setw(15) << studentas.v << setw(15) << studentas.p << fixed << setprecision(2) << setw(15) << studentas.rez << endl;
    }
    outfile2.close();
    cout << "Rezultatai irasyti i failus Kietiakai.txt ir Nuskriaustukai.txt" << endl;
    system("pause");
    system("cls");
}

deque<double> Testavimas(deque<Studentas>& Duomenys) {
    try {
        Studentas studentas;
        string line;
        string pavadinimas;
        string pasirinkimas, pasirinkimas2;

        high_resolution_clock::time_point pradzia1;
        high_resolution_clock::time_point pabaiga1;
        high_resolution_clock::time_point pradzia2;
        high_resolution_clock::time_point pabaiga2;
        high_resolution_clock::time_point pradzia3;
        high_resolution_clock::time_point pabaiga3;
        high_resolution_clock::time_point pradzia4;
        high_resolution_clock::time_point pabaiga4;
        high_resolution_clock::time_point pradzia5;
        high_resolution_clock::time_point pabaiga5;

        duration<double> trukme1;
        duration<double> trukme2;
        duration<double> trukme3;
        duration<double> trukme4;
        duration<double> trukme5;

        pavadinimas = PasirinktiFaila();

        cout << "Kaip norite matyti savo galutini bala?" << endl;
        cout << "1 - Vid." << endl;
        cout << "2 - Med." << endl;
        cout << endl;
        try {
            cout << "Iveskite pasirinkima: "; cin >> pasirinkimas;
            cout << endl;

            while (pasirinkimas != "1" && pasirinkimas != "2") {
                cout << "Pasirinkite arba '1' arba '2'" << endl;
                cin >> pasirinkimas;
            }
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Kaip norite rikiuoti rezultatus?" << endl;
        cout << "1 - Didejimo tvarka." << endl;
        cout << "2 - Mazejimo tvarka." << endl;
        cout << endl;
        try {
            cout << "Iveskite pasirinkima: "; cin >> pasirinkimas2;
            cout << endl;

            while (pasirinkimas2 != "1" && pasirinkimas2 != "2") {
                cout << "Pasirinkite arba '1' arba '2'" << endl;
                cin >> pasirinkimas2;
            }
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        pradzia1 = high_resolution_clock::now();
        pradzia2 = high_resolution_clock::now();

        ifstream infile(pavadinimas);
        if (!infile) {
            throw runtime_error("Nepavyko atidaryti failo. Bandykite dar karta.");
        }

        auto pradzia = high_resolution_clock::now();

        getline(infile, line);

        while (getline(infile, line)) {
            istringstream iss(line);
            iss >> studentas.v >> studentas.p;

            double pazymys;
            while (iss >> pazymys) {
                if (pazymys <= 0 || pazymys > 10) {
                    throw runtime_error("Neteisingas skaicius namu darbu rezultatuose.");
                }
                studentas.nd_rez.push_back(pazymys);
            }
            if (!studentas.nd_rez.empty()) {
                studentas.egz_rez = studentas.nd_rez.back();
                studentas.nd_rez.pop_back();
            }
            else {
                throw runtime_error("Pasirinktas failas yra tuscias");
            }

            Duomenys.push_back(studentas);
            studentas.nd_rez.clear();
        }
        infile.close();

        pabaiga2 = high_resolution_clock::now();
        trukme2 = duration_cast<duration<double>>(pabaiga2 - pradzia2);

        deque<Studentas> Kietiakai;
        deque<Studentas> Nuskriaustukai;

        for (auto& studentas : Duomenys) {
            if (pasirinkimas == "1") {
                studentas.nd_vid = studentas.nd_sum / studentas.nd_rez.size();
                studentas.rez = 0.4 * studentas.nd_vid + 0.6 * studentas.egz_rez;
            }
            else {
                studentas.rez = 0.4 * studentas.mediana + 0.6 * studentas.egz_rez;
            }
        }

        pradzia4 = high_resolution_clock::now();

        if (pasirinkimas2 == "1") {
            sort(Kietiakai.begin(), Kietiakai.end(), [](const Studentas& a, const Studentas& b) { return a.rez < b.rez; });
            sort(Nuskriaustukai.begin(), Nuskriaustukai.end(), [](const Studentas& a, const Studentas& b) { return a.rez < b.rez; });
        }
        else {
            sort(Kietiakai.begin(), Kietiakai.end(), [](const Studentas& a, const Studentas& b) { return a.rez > b.rez; });
            sort(Nuskriaustukai.begin(), Nuskriaustukai.end(), [](const Studentas& a, const Studentas& b) { return a.rez > b.rez; });
        }

        pabaiga4 = high_resolution_clock::now();
        trukme4 = duration_cast<duration<double>>(pabaiga4 - pradzia4);

        pradzia3 = high_resolution_clock::now();

        for (auto& studentas : Duomenys) {
            if (studentas.rez >= 5) {
                Kietiakai.push_back(studentas);
            }
            else {
                Nuskriaustukai.push_back(studentas);
            }
        }
        Duomenys.clear();

        pabaiga3 = high_resolution_clock::now();
        trukme3 = duration_cast<duration<double>>(pabaiga3 - pradzia3);

        pradzia5 = high_resolution_clock::now();

        ofstream outfile1("Kietiakai.txt");
        if (!outfile1) {
            cerr << "Nepavyko sukurti rezultatu failo.";
        }
        outfile1 << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
        outfile1 << "-----------------------------------------------" << endl;
        for (const auto& studentas : Kietiakai) {
            outfile1 << left << setw(15) << studentas.v << setw(15) << studentas.p << fixed << setprecision(2) << setw(15) << studentas.rez << endl;
        }
        outfile1.close();

        ofstream outfile2("Nuskriaustukai.txt");
        if (!outfile2) {
            cerr << "Nepavyko sukurti rezultatu failo.";
        }
        outfile2 << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
        outfile2 << "-----------------------------------------------" << endl;
        for (const auto& studentas : Nuskriaustukai) {
            outfile2 << left << setw(15) << studentas.v << setw(15) << studentas.p << fixed << setprecision(2) << setw(15) << studentas.rez << endl;
        }
        outfile2.close();

        pabaiga5 = high_resolution_clock::now();
        trukme5 = duration_cast<duration<double>>(pabaiga5 - pradzia5);

        pabaiga1 = high_resolution_clock::now();
        trukme1 = duration_cast<duration<double>>(pabaiga1 - pradzia1);

        cout << "Duomenu nuskaitymo is failo laikas: " << trukme2.count() << " sekundziu" << endl;
        cout << "Studentu rusiavimo i atskirus deques laikas: " << trukme3.count() << " sekundziu" << endl;
        cout << "Studentu rikiavimo didejimo arba mazejimo tvarka laikas: " << trukme4.count() << " sekundziu" << endl;
        //cout << "Studentu irasymo i atskirus failus laikas: " << trukme5.count() << " sekundziu" << endl;
        cout << "Visos programos veikimo laikas: " << trukme1.count() << " sekundziu" << endl;
        cout << endl;

        deque<double> trukme_counts;
        trukme_counts.push_back(trukme1.count());
        trukme_counts.push_back(trukme2.count());
        trukme_counts.push_back(trukme3.count());
        trukme_counts.push_back(trukme4.count());
        trukme_counts.push_back(trukme5.count());

        return trukme_counts;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
}
