#include "C:\Users\matas\OneDrive\Desktop\vu\Objektinis\v2.0\v2.0_vektoriai\v2.0_vektoriai\studentas.h"
#include "C:\Users\matas\OneDrive\Desktop\vu\Objektinis\v2.0\v2.0_vektoriai\v2.0_vektoriai\studentas.cpp"
#include "gtest/gtest.h"

// Testuojamas konstruktorius be parametru
TEST(StudentasTest, Konstruktorius_be_parametru) {
    Studentas studentas;
    EXPECT_EQ(" ", studentas.getV());
    EXPECT_EQ(" ", studentas.getP());
    EXPECT_EQ(0.0, studentas.getEgz_rez());
    EXPECT_EQ(0.0, studentas.getRez());
    EXPECT_EQ(0.0, studentas.getNd_sum());
    EXPECT_EQ(1, studentas.getNd_rez().size());
}

// Testuojamas konstruktorius su parametrais
TEST(StudentasTest, Konstruktorius_su_parametrais) {
    std::string v = "Matas";
    std::string p = "Siaurodinas";
    double egz_rez = 8;
    double rez = 0;
    std::vector<double> nd_rez = { 7, 9, 8 };

    Studentas studentas(v, p, egz_rez, rez, nd_rez);

    rez = studentas.ApskaiciuotiGalutini(true);
    EXPECT_EQ(v, studentas.getV());
    EXPECT_EQ(p, studentas.getP());
    EXPECT_EQ(egz_rez, studentas.getEgz_rez());
    EXPECT_EQ(rez, studentas.getRez());
    EXPECT_EQ(nd_rez.size(), studentas.getNd_rez().size());
    EXPECT_EQ(nd_rez, studentas.getNd_rez());
}

// Testuojamas Copy konstruktorius
TEST(StudentasTest, Konstruktorius_Copy) {
    std::string v = "Matas";
    std::string p = "Siaurodinas";
    double egz_rez = 8;
    double rez = 0;
    std::vector<double> nd_rez = { 7, 9, 8 };

    Studentas studentas1(v, p, egz_rez, rez, nd_rez);
    rez = studentas1.ApskaiciuotiGalutini(true);
    Studentas studentas2(studentas1);

    EXPECT_EQ(studentas1.getV(), studentas2.getV());
    EXPECT_EQ(studentas1.getP(), studentas2.getP());
    EXPECT_EQ(studentas1.getEgz_rez(), studentas2.getEgz_rez());
    EXPECT_EQ(studentas1.getRez(), studentas2.getRez());
    EXPECT_EQ(studentas1.getNd_rez().size(), studentas2.getNd_rez().size());
    EXPECT_EQ(studentas1.getNd_rez(), studentas2.getNd_rez());
}

// Testuojanas Move konstruktorius
TEST(StudentasTest, Konstruktorius_Move) {
    std::string v = "Matas";
    std::string p = "Siaurodinas";
    double egz_rez = 8;
    double rez = 0;
    std::vector<double> nd_rez = { 7, 9, 8 };

    Studentas studentas1(v, p, egz_rez, rez, nd_rez);
    rez = studentas1.ApskaiciuotiGalutini(true);
    Studentas studentas2(std::move(studentas1));

    EXPECT_EQ(v, studentas2.getV());
    EXPECT_EQ(p, studentas2.getP());
    EXPECT_EQ(egz_rez, studentas2.getEgz_rez());
    EXPECT_EQ(rez, studentas2.getRez());
    EXPECT_EQ(nd_rez.size(), studentas2.getNd_rez().size());
    EXPECT_EQ(nd_rez, studentas2.getNd_rez());
}

// Testuojamas Copy priskyrimo operatorius
TEST(StudentasTest, Copy_Priskyrimo_Operatorius) {
    std::string v1 = "Matas";
    std::string p1 = "Siaurodinas";
    double egz_rez1 = 8;
    double rez1 = 8;
    std::vector<double> nd_rez1 = { 7, 9, 8 };

    std::string v2 = "Vardenis";
    std::string p2 = "Pavardenis";
    double egz_rez2 = 9;
    double rez2 = 9;
    std::vector<double> nd_rez2 = { 8, 9, 9 };

    Studentas studentas1(v1, p1, egz_rez1, rez1, nd_rez1);
    Studentas studentas2(v2, p2, egz_rez2, rez2, nd_rez2);

    studentas2 = studentas1;

    EXPECT_EQ(studentas1.getV(), studentas2.getV());
    EXPECT_EQ(studentas1.getP(), studentas2.getP());
    EXPECT_EQ(studentas1.getEgz_rez(), studentas2.getEgz_rez());
    EXPECT_EQ(studentas1.getRez(), studentas2.getRez());
    EXPECT_EQ(studentas1.getNd_rez().size(), studentas2.getNd_rez().size());
    EXPECT_EQ(studentas1.getNd_rez(), studentas2.getNd_rez());
}

// Testuojamas Move priskyrimo operatorius
TEST(StudentasTest, Move_Priskyrimo_Operatorius) {
    std::string v1 = "Matas";
    std::string p1 = "Siaurodinas";
    double egz_rez1 = 8;
    double rez1 = 0;
    std::vector<double> nd_rez1 = { 7, 9, 8 };

    std::string v2 = "Vardenis";
    std::string p2 = "Pavardenis";
    double egz_rez2 = 9;
    double rez2 = 0;
    std::vector<double> nd_rez2 = { 8, 9, 9 };

    Studentas studentas1(v1, p1, egz_rez1, rez1, nd_rez1);
    rez1 = studentas1.ApskaiciuotiGalutini(true);
    Studentas studentas2(v2, p2, egz_rez2, rez2, nd_rez2);
    rez2 = studentas2.ApskaiciuotiGalutini(true);

    studentas2 = std::move(studentas1);

    EXPECT_EQ(v1, studentas2.getV());
    EXPECT_EQ(p1, studentas2.getP());
    EXPECT_EQ(egz_rez1, studentas2.getEgz_rez());
    EXPECT_EQ(rez1, studentas2.getRez());
    EXPECT_EQ(nd_rez1.size(), studentas2.getNd_rez().size());
    EXPECT_EQ(nd_rez1, studentas2.getNd_rez());
}