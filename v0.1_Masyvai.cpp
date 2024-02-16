#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <numeric>

using namespace std;

struct {
	 
	string v;
	string p;
	double nd_rez[10];
	double egz_rez;
	int nd_sk;

} Duomenys[100];

int main()
{
	int sk;
	double rez;

	cout << "Iveskite studentu skaiciu:" << endl;
	cin >> sk;

	for (int i = 1; i <= sk; i++) {
		cout << "Koks jusu vardas?" << endl;
		cin >> Duomenys[i].v;
		cout << "Kokia jusu pavarde?" << endl;
		cin >> Duomenys[i].p;
		cout << "Koks buvo jusu egzamino rezultatas?" << endl;
		cin >> Duomenys[i].egz_rez;
		cout << "Kiek namu darbu atlikote?" << endl;
		cin >> Duomenys[i].nd_sk;
	}


	for (int i = 1; i <= sk; i++){
		for (int j = 1; j <= Duomenys[i].nd_sk; j++) {
			cout << "Koks buvo " << j << "-o namu darbo vertinimas?" << endl;
			cin >> Duomenys[i].nd_rez[j];
		}
	}
	for (int i = 1; i <= sk; i++) {
		double nd_sum = accumulate(Duomenys[i].nd_rez, Duomenys[i].nd_rez + , 0.0);
		double nd_avg = nd_sum / n;
	}

	rez = 0.4 * nd_avg + 0.6 * Duomenys[i].egz_rez;

	cout <<"Pavarde     Vardas     Galutinis (Vid.)" <<endl;
	cout <<"---------------------------------------" << endl;
	cout << Duomenys[i].v << "     " << Duomenys[i].p << "          " << rez << endl;



	return 0; 
}