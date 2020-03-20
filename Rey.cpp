#include "Rey.hpp"

using namespace std;

Rey::Rey() : Pieza() {

}

bool Rey::validarMoviento(int act1, int act2, int nuevo1, int nuevo2) {
  if(act1 == nuevo1) {
    if (nuevo2 == act2 + 1 || nuevo2 == act2 - 1) {
      return true;
    }
  } else if (nuevo2 == act2) {
    if (nuevo1 == act1 + 1 || nuevo1 == act1 - 1) {
      return true;
    }
  }
  return false;
}
