#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Pieza.hpp"
using namespace std;

class Partida {
  private:
    string nombre;
    ofstream archivo;
    vector<string> movimientos;
    Pieza pieza;
  public:
    Partida() {};
    Partida(string, Pieza);
    void guardarPartida();
    void setMovimiento(string x) {movimientos.push_back(x);}
};
