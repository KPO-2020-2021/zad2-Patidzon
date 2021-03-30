//#ifndef WYRAZENIEZESP_HH
//#define WYRAZENIEZESP_HH



#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

/*
 * Tu nalezy zdefiniowac funkcje, ktore definiuja model statystyki 
 */
struct Statystyki
{
   double liczbapytan;
   double liczbadobrych;
   
  double Oblicz()const;

};

//#endif
