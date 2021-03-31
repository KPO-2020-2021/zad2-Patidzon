#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"
#define MIN_DIFF 0.00001
TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.66666667;
    y.im = 0.66666667;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}


TEST_CASE("operator wypisania"){
LZespolona x;
x.re = 2;
x.im =2;

std::ostringstream out ;
out << x;
std::cout << out.str() << std::endl;
CHECK( "(2.00+2.00i)"== out.str() );



}
TEST_CASE("operator wczytywania"){
LZespolona x;
std::istringstream in("(5+5i)");
in >> x;

std::ostringstream out ;
out << x;
CHECK( "(5.00+5.00i)"== out.str() );



}
TEST_CASE("Oblicz+"){
//LZespolona Arg1 , Arg2;
WyrazenieZesp WyraZ;
LZespolona wynik ,wynikpoprawny;
WyraZ.Arg1.re=1;
WyraZ.Arg1.im=1;
WyraZ.Arg2.re=1;
WyraZ.Arg2.im=1;
WyraZ.Op=Op_Dodaj;
wynikpoprawny.re=2;
wynikpoprawny.im=2;
wynik=Oblicz(WyraZ);
CHECK(wynik==wynikpoprawny);
}
TEST_CASE("test LZespolona Mnożenie"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = 3;

    z.re = -2;
    z.im = 10;
 
    CHECK((y*x) == z);
}
TEST_CASE("test LZespolona Suma przypisanie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    x+=y;
    CHECK(x == z);
}
TEST_CASE("argument glowny"){
    LZespolona x;
double wynik,odp;
    x.re = 4;
    x.im = 4;
wynik=arg(x);
   odp=0.785398163397;
    
    CHECK(std::abs(wynik-odp)<=MIN_DIFF);
}
 TEST_CASE("test LZespolona dziel przypisanie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = -0.2;
    z.im = 0.4;
    x/=y;
    CHECK(x == z);
}