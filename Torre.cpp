#include "Torre.hpp"

using namespace std;

Torre::Torre() : Pieza() {

}

bool Torre::validarMoviento(int act1, int act2, int nuevo1, int nuevo2) {
  if (act1 == nuevo1) {
    return true;
  }
  if (act2 == nuevo2) {
    return true;
  }
  return false;
}
