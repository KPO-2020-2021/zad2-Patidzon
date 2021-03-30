#include "Statystyki.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
double Statystyki::Oblicz()const{
double wynik;
wynik=(liczbadobrych/liczbapytan)*100;
return wynik;
}