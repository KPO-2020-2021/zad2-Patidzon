#include "LZespolona.hh"
#include <cmath>

#define MIN_DIFF 0.00001

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  LZespolona::operator == (  LZespolona  Skl2)const{
  /*if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    return true;
  else
    return false;*/
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  
  if ((std::abs(re - Skl2.re) <= MIN_DIFF) && (std::abs(im - Skl2.im) <= MIN_DIFF)){
    return true;
  }
  else {
    return false;
  }
  
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator + ( LZespolona  Skl2)const
{
 /// LZespolona  Wynik;
Skl2.re += re; Skl2.im += im;
 /* Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;*/
  return Skl2;
}


/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator / (  LZespolona  Skl2)const
{
  LZespolona  Wynik;

  Wynik.re = (re*Skl2.re + Skl2.im*im)/(Skl2.re*Skl2.re+Skl2.im*Skl2.im);
  Wynik.im = (Skl2.re*im-re*Skl2.im)/(Skl2.re*Skl2.re+Skl2.im*Skl2.im) ;
  /* Wynik.re = (Skl1.re*Skl2.re + Skl2.im*Skl1.im)/(Skl2.re*Skl2.re+Skl2.im*Skl2.im);
  Wynik.im = (Skl2.re*Skl1.im-Skl1.re*Skl2.im)/(Skl2.re*Skl2.re+Skl2.im*Skl2.im) ;*/
  return Wynik;
}
LZespolona LZespolona::operator - (  LZespolona  Skl2)const
{
 // LZespolona  Wynik;

  Skl2.re = re - Skl2.re;
  Skl2.im = im - Skl2.im;
  return Skl2;
}
LZespolona  LZespolona::operator * ( LZespolona  Skl2)const
{
  //LZespolona  Wynik;

  Skl2.re = re*Skl2.re - Skl2.im*im;
  Skl2.im = re*Skl2.im + Skl2.re*im;
  return Skl2;
}