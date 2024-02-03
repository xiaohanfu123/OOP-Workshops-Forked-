// Guitar.cpp
// Summer 2023 WS04 p2
// Michael Huang
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Guitar.h"
using namespace std;

namespace seneca{
   const char* GuitarStr::material() const {
      return m_material;
   }
   double GuitarStr::gauge() const {
      return m_gauge;
   }
   GuitarStr::GuitarStr() {};

   GuitarStr::GuitarStr(const char* ma, double ga) {
      strncpy(m_material, ma, MAT_LEN);
      m_gauge = ga;
   };
}
