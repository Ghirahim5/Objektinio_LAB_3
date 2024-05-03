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

class Asmuo {
public:

    // destruktorius
    virtual ~Asmuo() = default;

    // get'eriai
    virtual std::string getV() const = 0;
    virtual std::string getP() const = 0;
    virtual const std::vector<double>& getNd_rez() const = 0;
    virtual double getEgz_rez() const = 0;
    virtual double getNd_sum() const = 0;
    virtual double getRez() const = 0;

};

#endif // ASMUO_H
