#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  LZespolona  operator + (  LZespolona  Skl2)const;
  LZespolona  operator - ( LZespolona  Skl2)const;
  //LZespolona  operator * (  LZespolona  Skl2)const;
  LZespolona  operator / ( LZespolona  Skl2)const;
  LZespolona operator += ( LZespolona const &Skl2);
  LZespolona operator /= ( LZespolona const &Skl2);
  LZespolona operator / (double skalar);
  bool  operator == ( LZespolona  Skl2)const;
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

//bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * ( LZespolona Skl1, LZespolona  Skl2);

double arg(LZespolona Skl1);


//LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

#endif
