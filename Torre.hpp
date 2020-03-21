#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Torre : public Pieza {
  public:
    Torre();
    bool validarMoviento(int act1, int act2, int nuevo1, int nuevo2);
    string getPosInij1() {return "a1"; }
    string getPosInij2() {return "h8"; }
    string toString() {return "Torre";}
};
