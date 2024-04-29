#include "studentas.h"

//  konstruktorius

Studentas::Studentas() {
    v = " ";
    p = " ";
    egz_rez = 0;
    rez = 0;
    nd_rez = { 0 };
}

// konstruktorius su parametrais

Studentas::Studentas(const std::string& v_, const std::string& p_, double egz_rez_, double rez_, const std::deque<double>& nd_rez_) {
    v = v_;
    p = p_;
    egz_rez = egz_rez_;
    rez = ApskaiciuotiGalutini(true);
    nd_rez.assign(nd_rez_.begin(), nd_rez_.end());
}

// copy konstruktorius
Studentas::Studentas(const Studentas& other) {
    v = other.v;
    p = other.p;
    egz_rez = other.egz_rez;
    rez = other.rez;
    nd_rez = other.nd_rez;
}

// move konstruktorius
Studentas::Studentas(Studentas&& other) noexcept {
    v = std::move(other.v);
    p = std::move(other.p);
    egz_rez = std::move(other.egz_rez);
    rez = std::move(other.rez);
    nd_rez = std::move(other.nd_rez);

    other.v.clear();
    other.p.clear();
    other.egz_rez = 0;
    other.rez = 0;
    other.nd_rez.clear();
}

// copy priskyrimo operatorius
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        v = other.v;
        p = other.p;
        egz_rez = other.egz_rez;
        rez = other.rez;
        nd_rez = other.nd_rez;
    }
    return *this;
}

// move priskyrimo operatorius
Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this != &other) {
        v = std::move(other.v);
        p = std::move(other.p);
        egz_rez = std::move(other.egz_rez);
        rez = std::move(other.rez);
        nd_rez = std::move(other.nd_rez);

        other.v.clear();
        other.p.clear();
        other.egz_rez = 0;
        other.rez = 0;
        other.nd_rez.clear();
    }
    return *this;
}


// ivesties operatorius
std::istream& operator>>(std::istream& is, Studentas& studentas) {
    std::string tempV, tempP;
    std::deque<double> temp_Ndrez;
    double temp_grade;

    if (!(is >> tempV >> tempP)) {
        return is;
    }
    studentas.setV(tempV);
    studentas.setP(tempP);

    while (is >> temp_grade) {
        temp_Ndrez.push_back(temp_grade);
    }

    if (is.eof()) {
        is.clear();
    }

    if (!temp_Ndrez.empty()) {
        studentas.setEgz_rez(temp_Ndrez.back());
        temp_Ndrez.pop_back();
    }
    studentas.setNd_rez(std::move(temp_Ndrez));

    return is;
}

// isvesties operatorius 
std::ostream& operator<<(std::ostream& os, const Studentas& studentas) {
    os << studentas.getV() << " " << studentas.getP();
    for (const auto& rez : studentas.getNd_rez()) {
        os << " " << rez;
    }
    os << " " << studentas.getEgz_rez();
    return os;
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
    std::deque<double> scores = nd_rez;
    std::sort(scores.begin(), scores.end());
    size_t size = scores.size();
    if (size % 2 == 0) {
        return (scores[size / 2 - 1] + scores[size / 2]) / 2.0;
    }
    else {
        return scores[size / 2];
    }
}

double Studentas::ApskaiciuotiGalutini(bool mediana) {
    double nd_bal = mediana ? ApskaiciuotiMediana() : ApskaiciuotiVidurki();
    double temp_rez = 0.4 * nd_bal + 0.6 * egz_rez;
    setRez(temp_rez); 
    return temp_rez;
}

