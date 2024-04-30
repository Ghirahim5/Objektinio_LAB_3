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
    virtual std::string getName() const = 0;
};

#endif // PERSON_H
