#include "ManoVektorius.h"

extern "C" ManoVektorius<int>*createAndFillMyVector() {
    ManoVektorius<int>* vec = new ManoVektorius<int>();
    vec->push_back(1);
    vec->push_back(2);
    vec->push_back(3);
    return vec;
}