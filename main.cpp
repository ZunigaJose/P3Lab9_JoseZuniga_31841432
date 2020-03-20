#include "Rey.hpp"
#include "Pieza.hpp"
#include <string>
#include <iostream>

using namespace std;

Pieza pieza;

int charInt(char c) {
  return c - 97;
}

bool validar(string coor) {
    if (coor.size() != 7) {
      return false;
    }
    string act = coor.substr(1, 2);
    string nuevo = coor.substr(2, 5);
    int act1, act2, nuevo1, nuevo2;
    act1 = charInt(act[0]);
    nuevo1 = charInt(nuevo[0]);
    if (act1 < 0 || act1 > 7 || nuevo1 < 0 || nuevo1 > 7) {
      return false;
    }
    act2 = act[1] - 49;
    nuevo2 = nuevo[1] - 49;
    if (act2 < 0 || act2 > 7 || nuevo2 < 0 || nuevo2 > 7) {
      return false;
    }
    return pieza.validarMoviento(act1, act2, nuevo1, nuevo2);
}

int main() {
  return 0;
}
