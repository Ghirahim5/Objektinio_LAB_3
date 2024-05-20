/**
 * @file studentas.h
 * @brief Sis failas apima Studento klases deklaracija.
 */

#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "Asmuo.h"
#include "ManoVektorius.h"

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <limits>
#include <random>
#include <fstream>
#include <sstream>

/**
 * @brief Representuoja studenta ir jo asmenine informacija bei akademinius rezultatus.
 *
 * Si klase suteikia funkcionaluma saugoti ir manipuliuoti studentu duomenimis,
 * iskaitant ju vardus, pavardes, egzamino rezultatus, namu darbu rezultatus. Taip pat
 * si klase suteikia galimybe apskaiciuoti galutinius rezultatus.
 */
class Studentas : public Asmuo {

private:

    std::string v; /**< Vardas */
	std::string p; /**< Pavarde */
	double egz_rez; /**< Egzamino rezultatas */
	std::vector<double> nd_rez; /**< Namu darbu rezultatai */
    double nd_sum = 0; /**< Namu darbu rezultatu suma */
    double rez; /**< Galutinis rezultatas */

    /**
     * @brief Atnaujina namu darbu rezultatu suma.
     */
    void UpdateNdSum() { nd_sum = std::accumulate(nd_rez.begin(), nd_rez.end(), 0.0); }

public:

    /**
     * @brief Konstruktorius be parametru.
     */
    Studentas();

    /**
     * @brief Konstruktorius su parametrais.
     * @param v_ Vardas
     * @param p_ Pavarde
     * @param egz_rez_ Egzamino rezultatas
     * @param rez_ Galutinis rezultatas
     * @param nd_rez_ Namu darbu rezultatai
     */
    Studentas(const std::string& v_, const std::string& p_, double egz_rez_, double rez_, const std::vector<double>& nd_rez_);

    /**
     * @brief Copy konstruktorius.
     * @param other Kito objekto kopija
     */
    Studentas(const Studentas& other);

    /**
     * @brief Move konstruktorius.
     * @param other Kito objekto perkelimas
     */
    Studentas(Studentas&& other) noexcept;

    /**
     * @brief Copy priskyrimo operatorius.
     * @param other Kito objekto kopija
     * @return Sis objektas
     */
    Studentas& operator=(const Studentas& other);

    /**
     * @brief Move priskyrimo operatorius.
     * @param other Kito objekto perkelimas
     * @return Sis objektas
     */
    Studentas& operator=(Studentas&& other) noexcept;

    /**
     * @brief Ivesties operatorius.
     * @param is Ivesties srautas
     * @param studentas Studento objektas
     * @return Ivesties srautas
     */
    friend std::istream& operator>>(std::istream& is, Studentas& studentas);

    /**
     * @brief Isvesties operatorius.
     * @param os Isvesties srautas
     * @param studentas Studento objektas
     * @return Isvesties srautas
     */
    friend std::ostream& operator<<(std::ostream& os, const Studentas& studentas);

    /**
     * @brief Destruktorius.
     */
    ~Studentas() {
		v.clear();
		p.clear();
		nd_rez.clear();
    }

    /**
     * @brief Grazina varda.
     * @return Vardas
     */
    inline std::string getV() const { return v; }

    /**
     * @brief Grazina pavarde.
     * @return Pavarde
     */
    inline std::string getP() const { return p; }

    /**
     * @brief Grazina varda ir pavarde.
     * @return Vardas ir pavarde
     */
    std::string getName() const { return getV() + " " + getP(); }

    /**
     * @brief Grazina namu darbu rezultatus.
     * @return Namu darbu rezultatai
     */
    const std::vector<double>& getNd_rez() const { return nd_rez; }

    /**
     * @brief Grazina egzamino rezultata.
     * @return Egzamino rezultatas
     */
    double getEgz_rez() const { return egz_rez; }

    /**
     * @brief Grazina namu darbu rezultatu suma.
     * @return Namu darbu rezultatu suma
     */
    double getNd_sum() const { return nd_sum; }

    /**
     * @brief Grazina galutini rezultata.
     * @return Galutinis rezultatas
     */
    double getRez() const { return rez; }

    /**
     * @brief Nustato varda.
     * @param v Vardas
     */
    void setV(const std::string& v) { this->v = v; }

    /**
     * @brief Nustato pavarde.
     * @param p Pavarde
     */
    void setP(const std::string& p) { this->p = p; }

    /**
     * @brief Nustato galutini rezultata.
     * @param rez Galutinis rezultatas
     */
    void setRez(double rez) { this->rez = rez; }

    /**
     * @brief Nustato egzamino rezultata.
     * @param egz_rez Egzamino rezultatas
     */
    void setEgz_rez(double egz_rez) { this->egz_rez = egz_rez; }

    /**
     * @brief Nustato namu darbu rezultatus ir atnaujina suma.
     * @param nd_rez Namu darbu rezultatai
     */
    void setNd_rez(const std::vector<double>& nd_rez) { this->nd_rez = nd_rez; UpdateNdSum(); }

    /**
     * @brief Nustato namu darbu rezultatu suma.
     * @param nd_sum Namu darbu rezultatu suma
     */
    void setNd_sum(double nd_sum) { this->nd_sum = nd_sum; }

    /**
     * @brief Apskaiciuoja namu darbu rezultatu mediana.
     * @return Namu darbu rezultatu mediana
     */
    double ApskaiciuotiMediana() const;

    /**
     * @brief Apskaiciuoja namu darbu rezultatu vidurki.
     * @return Namu darbu rezultatu vidurkis
     */
    double ApskaiciuotiVidurki() const;

    /**
     * @brief Apskaiciuoja galutini rezultata.
     * @param mediana Ar naudoti mediana
     * @return Galutinis rezultatas
     */
    double ApskaiciuotiGalutini(bool mediana);

    /**
     * @brief Prideda namu darbu rezultata.
     * @param result Namu darbu rezultatas
     */
    void addNd_rez(double result) { nd_rez.push_back(result); }

    /**
     * @brief Pakeicia namu darbu rezultatu dydi.
     * @param n Naujas dydis
     */
    void resizeNd_rez(int n) { nd_rez.resize(n); }

    /**
     * @brief Pasalina paskutini namu darbu rezultata.
     */
    void popNd_rez() { nd_rez.pop_back(); }

    /**
     * @brief Isvalo namu darbu rezultatus.
     */
    void clearNdRez() { nd_rez.clear(); }

};

#endif
