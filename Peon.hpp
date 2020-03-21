#pragma once
#include <string>
#include "Pieza.hpp"

using namespace std;

class Peon : public Pieza {
  public:
    Peon();
    bool validarMoviento(int act1, int act2, int nuevo1, int nuevo2);
    string getPosInij1() {return "e2"; }
    string getPosInij2() {return "e7"; }
    string toString() {return "Peon";}
};
