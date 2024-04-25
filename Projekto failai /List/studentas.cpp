#include "studentas.h"

//  konstruktorius
Studentas::Studentas() {
    v = " ";
    p = " ";
    egz_rez = 0;
    rez = 0;
    nd_rez = { 0 };
}

//  konstruktorius su parametrais
Studentas::Studentas(const std::string& v_, const std::string& p_, double mediana, double egz_rez_, double rez_, const std::list<double>& nd_rez_){
    v = v_;
    p = p_;
    egz_rez = egz_rez_;
    rez = ApskaiciuotiGalutini(true);
    nd_rez.assign(nd_rez_.begin(), nd_rez_.end());
}

double Studentas::ApskaiciuotiVidurki() const {
    if (nd_rez.empty()) {
        return 0;
    }
    double sum = std::accumulate(nd_rez.begin(), nd_rez.end(), 0.0);
    return sum / nd_rez.size();
}
double Studentas::ApskaiciuotiMediana() const {
    if (nd_rez.empty()) {
        return 0;
    }
    std::list<double> scores = nd_rez;
    scores.sort();
    size_t size = scores.size();
    auto it = scores.begin();
    std::advance(it, size / 2 - 1);
    double median = *it;
    if (size % 2 == 0) {
        std::advance(it, 1);
        median = (median + *it) / 2.0;
    }
    return median;
}

double Studentas::ApskaiciuotiGalutini(bool mediana) {
    double nd_bal = mediana ? ApskaiciuotiMediana() : ApskaiciuotiVidurki();
    double temp_rez = 0.4 * nd_bal + 0.6 * egz_rez;
    setRez(temp_rez); 
    return temp_rez;
}

