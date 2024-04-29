#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <deque>
#include "studentas.h"

void GeneruotiPazymius(std::deque<Studentas> & Duomenys);
void GeneruotiPazymiusVardus();
double Skaitymas(std::deque<Studentas>& Duomenys);
void RusiuotiSpausdinti(std::deque<Studentas>& Duomenys, double laikas, const std::string& pavadinimas);
void RankinisIvedimas(std::deque<Studentas>& Duomenys);
void GeneruotiFailus();
void RusiuotiGeraisBlogais(std::deque<Studentas>& Duomenys);
std::deque<double> Testavimas(std::deque<Studentas>& Duomenys);
void TestavimasRuleOfFive();
#endif