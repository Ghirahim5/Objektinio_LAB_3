#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <algorithm>
#include <chrono>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <numeric>
#include <deque>


struct Studentas {
    std::string v;
    std::string p;
    int n;
    double egz_rez;
    std::deque<double> nd_rez;
    double nd_sum = 0;
    double nd_vid;
    double rez;
    double mediana;
};

#endif
