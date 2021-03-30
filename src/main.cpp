#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"
using namespace std;




int main(int argc, char **argv)
{
 double ocena;
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;
Statystyki wyniki;
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona odpowiedz, poprawnaodp;
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    //cout << " Czesc rzeczywista pierwszego argumentu: ";
    //cout << WyrZ_PytanieTestowe.Arg1.re << endl;
    if(WyrZ_PytanieTestowe.Op==3&&WyrZ_PytanieTestowe.Arg2.im==0&&WyrZ_PytanieTestowe.Arg2.re==0)
    {cout<<"wystepuje dzielenie przez 0"<<endl<<"pytanie zostanie pominiete"<<endl;}
    else{
    wyniki.liczbapytan+=1;
    
    cout << WyrZ_PytanieTestowe<<endl;
    poprawnaodp=Oblicz(WyrZ_PytanieTestowe);
cout<<poprawnaodp<<endl<<"podaj odpowiedz ";
cin>>odpowiedz;
while (!cin)
{cout<< "zly format liczby"<<endl;
cin.clear();
  cin >> odpowiedz;
  
}
if (odpowiedz==poprawnaodp)
{
  cout<<"poprawna odpowiedz"<<endl;
  wyniki.liczbadobrych+=1;
}
else
{
cout<<"niepoprawna odpowiedz"<<endl;
}
//cout<<odpowiedz<<endl;

  }
  }
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << "liczba pytan w tescie:"<<wyniki.liczbapytan<<endl;
  cout <<"Liczba dobrych odpowiedzi:"<< wyniki.liczbadobrych<<endl;
  ocena=wyniki.Oblicz();
  cout<<"wynik w procentach:"<<ocena<<"%"<<endl;
  cout << endl;

}
