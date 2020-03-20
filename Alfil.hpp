#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Alfil : public Pieza {
  public:
    Alfil();
    bool validarMoviento(int act1, int act2, int nuevo1, int nuevo2);
    string getPosInij1() {return "c1"; }
    string getPosInij2() {return "f8"; }
};
