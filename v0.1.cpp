#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct {
    string v;
    string p;
    double egz_rez;
    int nd_sk;
} Duomenys;

int main() {

    double rez;

    cout << "Koks jusu vardas?" << endl;
    cin >> Duomenys.v;
    cout << "Kokia jusu pavarde?" << endl;
    cin >> Duomenys.p;
    cout << "Koks buvo jusu egzamino rezultatas?" << endl;
    cin >> Duomenys.egz_rez;
    cout << "Kiek namu darbu atlikote?" << endl;
    cin >> Duomenys.nd_sk;

    double nd_sum = 0;
    for (int i = 1; i <= Duomenys.nd_sk; i++) {
        cout << "Koks buvo " << i << "-o namu darbo vertinimas?" << endl;
        double nd_rez;
        cin >> nd_rez;
        nd_sum += nd_rez;
    }

    double nd_avg = nd_sum / Duomenys.nd_sk;
    rez = 0.4 * nd_avg + 0.6 * Duomenys.egz_rez;

    cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << left << setw(15) << Duomenys.v << setw(15) << Duomenys.p << fixed << setprecision(2) << setw(15) << rez << endl;

    return 0;
}
