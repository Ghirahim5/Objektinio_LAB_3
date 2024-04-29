#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <list>
#include "studentas.h"

void GeneruotiPazymius(std::list<Studentas> & Duomenys);
void GeneruotiPazymiusVardus();
double Skaitymas(std::list<Studentas>& Duomenys);
void RusiuotiSpausdinti(std::list<Studentas>& Duomenys, double laikas, const std::string& pavadinimas);
void RankinisIvedimas(std::list<Studentas>& Duomenys);
void GeneruotiFailus();
void RusiuotiGeraisBlogais(std::list<Studentas>& Duomenys);
std::list<double> Testavimas(std::list<Studentas>& Duomenys);
void TestavimasRuleOfFive();

#endif