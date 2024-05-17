#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include "studentas.h"

void GeneruotiPazymius(std::vector<Studentas> & Duomenys);
void GeneruotiPazymiusVardus();
double Skaitymas(std::vector<Studentas>& Duomenys);
void RusiuotiSpausdinti(std::vector<Studentas>& Duomenys, double laikas, const std::string& pavadinimas);
void RankinisIvedimas(std::vector<Studentas>& Duomenys);
void GeneruotiFailus();
void RusiuotiGeraisBlogais(std::vector<Studentas>& Duomenys);
std::vector<double> Testavimas(std::vector<Studentas>& Duomenys);
void TestavimasRuleOfFive();

#endif