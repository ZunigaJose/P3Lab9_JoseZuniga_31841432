#pragma once
#include <string>

using namespace std;
class Pieza {
  public:
    Pieza(){};
    virtual bool validarMoviento(int act1, int act2, int nuevo1, int nuevo2) {return true;}
    virtual string getPosInij1() {return "";}
    virtual string getPosInij2() {return "";}
    virtual string toString() {return "";}
};
