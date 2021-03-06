#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH
#include <iostream>


#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */


//void Wyswietl(WyrazenieZesp  WyrZ);
LZespolona Oblicz(WyrazenieZesp  WyrZ);
std::ostream & operator << (std::ostream &, LZespolona LZespolona);
std::ostream & operator << (std::ostream &, WyrazenieZesp WyraZ);
std::istream & operator >> (std::istream &, LZespolona &LZespolona);
//void Znak(WyrazenieZesp WyraZ);

#endif
