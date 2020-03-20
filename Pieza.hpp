#pragma once

class Pieza {
  public:
    Pieza();
    virtual bool validarMoviento(int act1, int act2, int nuevo1, int nuevo2);
};
