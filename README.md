Apžvalga
Ši programa skirta generuoti studentų pažymių ataskaitas. Vartotojas gali pasirinkti iš kelių variantų:

Generuoti pažymius:
Suvedus studento vardą ir pavardę, programa sugeneruos atsitiktinį namų darbų skaičių (nuo 1 iki 10),
atsitiktinius namų darbų rezultatus (nuo 1 iki 10) ir atsitiktinį egzamino rezultatą (nuo 1 iki 10).
Galutinis balas bus apskaičiuojamas pagal formulę: 0.4 * vidutinis namų darbų balas + 0.6 * egzamino balas.
Rezultatai bus rodomi lentelėje su stulpeliais: Pavarde, Vardas, Galutinis (Vid.) arba Galutinis (Med.) (priklausomai nuo pasirinkimo).

Skaityti iš failo:
Programa nuskaitys duomenis iš pasirinkto failo. Failas turi būti suformatuotas taip, kad kiekvienoje eilutėje
būtų studento vardas, pavardė ir namų darbų rezultatai (atskirti tarpais).
Galutinis balas bus apskaičiuojamas taip pat, kaip ir ankstesniame variante.
Rezultatai bus rodomi lentelėje su stulpeliais: Pavarde, Vardas, Galutinis (Vid.) arba Galutinis (Med.) (priklausomai nuo pasirinkimo).

Rankinis įvedimas:
Vartotojas galės rankiniu būdu įvesti studentų vardus, pavardes, namų darbų rezultatus ir egzamino rezultatus.
Galutinis balas bus apskaičiuojamas taip pat, kaip ir ankstesniuose variantuose.
Rezultatai bus rodomi lentelėje su stulpeliais: Pavarde, Vardas, Galutinis (Vid.) arba Galutinis (Med.) (priklausomai nuo pasirinkimo).

Funkcijos

Pagrindinės funkcijos:

GeneruotiPazymius: Ši funkcija sugeneruoja atsitiktinius studentų duomenis ir apskaičiuoja galutinius balus.
Skaitymas: Ši funkcija nuskaito duomenis iš pasirinkto failo ir apskaičiuoja galutinius balus.
RankinisIvedimas: Ši funkcija leidžia vartotojui rankiniu būdu įvesti studentų duomenis ir apskaičiuoja galutinius balus.
RusiuotiSpausdinti: Ši funkcija rūšiuoja ir spausdina rezultatų lentelę.
PasirinktiFaila: Ši funkcija leidžia vartotojui pasirinkti failą iš pateikto sąrašo.
RusiuotiGeraisBlogais: Ši funkcija rūšiuoja studentus pagal vidurkį į du atskirus failus: "Kietiakai" (studentai su vidurkiu > 5) ir "Nuskriaustukai" (studentai su vidurkiu < 5).
Papildomos funkcijos:

Galimybė apskaičiuoti ir parodyti medianą vietoj vidurkio.

Galimybė rūšiuoti rezultatus pagal vardą, pavardę arba balą.

Galimybė išsaugoti rezultatus faile.


Naudojimo instrukcija:

Paleiskite programą.

Pasirinkite norimą variantą:
Generuoti pažymius
Skaityti iš failo
Rankinis įvedimas

Jei pasirinkote "Skaityti iš failo", pasirinkite norimą failą iš sąrašo.

Jei pasirinkote "Rankinis įvedimas", įveskite studentų duomenis.

Pasirinkite, kaip norite matyti savo galutinį balą:
Vidutinis (Vid.)
Mediana (Med.)

Pasirinkite, kaip norite rusiuoti rezultatus:
Vardo
Pavardės
Balais

Pasirinkite, kaip norite matyti rezultatus:
Ekrane
Faile


Pavyzdys

Vartotojas pasirenka "Generuoti pažymius".

Įveda studento vardą: Jonas

Įveda studento pavardę: Jonaitis

Programa sugeneruoja 5 namų darbus.

Namų darbų rezultatai: 8, 7, 9, 6, 10.

Egzamino rezultatas: 8.

Rezultatai:

Pavarde | Vardas | Galutinis (Vid.)
------- | -------- | --------
Jonaitis | Jonas | 8.20

Sąrankos failas

Programa gali dirbti su duomenų failu, kuriame kiekvienoje eilutėje yra studentų informacija, atskirta tarpais:

Vardas Pavardė Namų_darbo_rezultatas1 Namų_darbo_rezultatas2 ... Egzamino_rezultatas
Pavyzdys:

Petras Petraitis 7 8 9 10 7
Ona Onaitytė 5 6 8 4 8
