#include "Caballo.hpp"
using namespace std;

Caballo::Caballo() : Pieza() {

}

bool Caballo::validarMoviento(int act1, int act2, int nuevo1, int nuevo2) {
  if ((2 + act1) == nuevo1 && (1+ act2) == nuevo2) {
    return true;
  }
  if ((2 + act1) == nuevo1 && (act2 - 1) == nuevo2) {
    return true;
  }
  if ((2 - act1) == nuevo1 && (1+ act2) == nuevo2) {
    return true;
  }
  if ((2 - act1) == nuevo1 && (act2 - 1) == nuevo2) {
    return true;
  }
  
  if ((1 + act1) == nuevo1 && (act2 + 1) == nuevo2) {
    return true;
  }
  if ((1 + act1) == nuevo1 && (act2 - 1) == nuevo2) {
    return true;
  }
  if ((1 - act1) == nuevo1 && (act2 + 1) == nuevo2) {
    return true;
  }
  if ((1 - act1) == nuevo1 && (act2 - 2) == nuevo2) {
    return true;
  }
  return false;
}
