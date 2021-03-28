#include "WyrazenieZesp.hh"
#include <iostream>



/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
std::ostream & operator << (std::ostream &StrmWyj, LZespolona LZesp){
StrmWyj << "(" << LZesp.re << std::showpos <<LZesp.im<< std::noshowpos << "i)";
return StrmWyj;

 }
 void CzytajZnak ( std::istream & StrmWej, char Znak){
char WczytanyZnak = ' ';
StrmWej >> WczytanyZnak;
if (WczytanyZnak != Znak)
{
    StrmWej.setstate(std::ios::failbit);
}
 }
 std::istream& operator >> ( std::istream & StrmWej, LZespolona &LZesp){
     CzytajZnak(StrmWej,'(');
     StrmWej >> LZesp.re;
     StrmWej >> LZesp.im;
     CzytajZnak(StrmWej,'i');
     CzytajZnak(StrmWej,')');
     return StrmWej;
 }
 LZespolona Oblicz(WyrazenieZesp WyraZ){
     LZespolona Wynik;
switch (WyraZ.Op)
{
case 0:
    Wynik=WyraZ.Arg1 + WyraZ.Arg2;
    break;
case 1:
    Wynik=WyraZ.Arg1 - WyraZ.Arg2;
    break;
    case 2:
    Wynik=WyraZ.Arg1 * WyraZ.Arg2;
    break;
    case 3:
    Wynik=WyraZ.Arg1 / WyraZ.Arg2;
    break;


default:
    break;

    }
    return Wynik;
 }
