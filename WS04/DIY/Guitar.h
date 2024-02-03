// Guitar.h
// Summer 2023 WS04 p2
// Michael Huang
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include <iostream>

namespace seneca{

  const int MAT_LEN = 10;

  class GuitarStr {
     char m_material[MAT_LEN]{};
     double m_gauge{};
  public:
     const char* material()const;
     double gauge()const;
     GuitarStr();
     GuitarStr(const char* ma, double ga);
  };

}

#endif
