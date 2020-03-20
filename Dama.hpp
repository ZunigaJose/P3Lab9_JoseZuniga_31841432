#pragma once
#include "Pieza.hpp"
#include <string>
using namespace std;

class Dama : public Pieza {
  public:
    Dama();
    bool validarMoviento(int act1, int act2, int nuevo1, int nuevo2);
    string getPosInij1() {return "d1"; }
    string getPosInij2() {return "d8"; }
};
