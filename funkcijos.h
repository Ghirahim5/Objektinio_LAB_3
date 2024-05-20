#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include "studentas.h"

void GeneruotiPazymius(std::vector<Studentas> & Duomenys);
void GeneruotiPazymiusVardus();
double Skaitymas(ManoVektorius<Studentas>& Duomenys1);
void RusiuotiSpausdinti(ManoVektorius<Studentas>& Duomenys1, double laikas, const std::string& pavadinimas);
void RankinisIvedimas(std::vector<Studentas>& Duomenys);
void GeneruotiFailus();
void RusiuotiGeraisBlogais(ManoVektorius<Studentas>& Duomenys1);
std::vector<double> Testavimas(ManoVektorius<Studentas>& Duomenys1);
void TestavimasRuleOfFive();

#endif