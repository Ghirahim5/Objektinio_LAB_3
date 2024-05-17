/**
 * @file asmuo.h
 * @brief Sis failas apima Asmens klases deklaracija.
 */

#ifndef ASMUO_H
#define ASMUO_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <istream>
#include <ostream>
#include <iomanip>
#include <sstream>

/**
 * @class Asmuo
 * @brief Bazine klase, kuri atstovauja asmeniui.
 */
class Asmuo {
public:

    /**
     * @brief Virtualus destruktorius.
     */
    virtual ~Asmuo() = default;

    /**
     * @brief Gauti varda.
     * @return Asmens vardas.
     */
    virtual std::string getV() const = 0;

    /**
     * @brief Gauti pavarde.
     * @return Asmens pavarde.
     */
    virtual std::string getP() const = 0;

    /**
     * @brief Gauti namu darbu rezultatus.
     * @return Asmens namu darbu rezultatai.
     */
    virtual const std::vector<double>& getNd_rez() const = 0;

    /**
     * @brief Gauti egzamino rezultata.
     * @return Asmens egzamino rezultatas.
     */
    virtual double getEgz_rez() const = 0;

    /**
     * @brief Gauti namu darbu rezultatu suma.
     * @return Asmens namu darbu rezultatu suma.
     */
    virtual double getNd_sum() const = 0;

    /**
     * @brief Gauti galutini rezultata.
     * @return Asmens galutinis rezultatas.
     */
    virtual double getRez() const = 0;

};

#endif // ASMUO_H
