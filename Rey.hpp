#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Rey : public Pieza {
  public:
    Rey();
    bool validarMoviento(int act1, int act2, int nuevo1, int nuevo2);
    string getPosInij1() {return "e1"; }
    string getPosInij2() {return "e8"; }
};
