#include "Dama.hpp"
using namespace std;

Dama::Dama() : Pieza() {

}

bool Dama::validarMoviento(int act1, int act2, int nuevo1, int nuevo2) {
  if ((act1 + act2) == (nuevo1 + nuevo2)) {
    return true;
  }
  if ((act1 - act2) == (nuevo1 - nuevo2)) {
    return true;
  }
  if (act1 == nuevo1) {
    return true;
  }
  if (act2 == nuevo2) {
    return true;
  }
  return false;
}
