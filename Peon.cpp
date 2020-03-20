#include "Peon.hpp"
using namespace std;

Peon::Peon() : Pieza() {

}

bool Peon::validarMoviento(int act1, int act2, int nuevo1, int nuevo2) {
  if (act2 == nuevo2) {
    if(act1 < 4 && act1 < nuevo1) {
      return true;
    } else if (act1 > 4 && act1 > nuevo1) {
      return true;
    }
  }
  return false;
}
