#pragma  once
#include "Pieza.hpp"
#include <string>
using namespace std;

class Caballo : public Pieza {
  public:
    Caballo();
    bool validarMoviento(int act1, int act2, int nuevo1, int nuevo2);
    string getPosInij1() {return "b1"; }
    string getPosInij2() {return "g8"; }
};
