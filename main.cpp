#include "Rey.hpp"
#include "Pieza.hpp"
#include "Dama.hpp"
#include "Alfil.hpp"
#include "Caballo.hpp"
#include "Partida.hpp"
#include "Peon.hpp"
#include "Pieza.hpp"
#include "Torre.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Pieza pieza, pieza2;
Rey rey1, rey2;
vector<Partida> partidas;

int charInt(char c) {
  return c - 97;
}

int menuPieza() {
  int op;
  cout << "1. Dama" << endl << "2. Alfil" << endl << "3. Caballo" << endl << "4. Peon" << endl;
  cout << "5. Torre: ";
  cin >> op;
  cin.ignore();
  if (op < 1 || op > 5) {
    cout << "Ingreso Invalido!!! Vuelva a intentar!!" << endl;
    return menuPieza();
  }
  return op;
}

void stPieza() {
  switch(menuPieza()) {
    case 1:
      pieza = Dama();
      pieza2 = Dama();
    break;
    case 2:
      pieza = Alfil();
      pieza2 = Alfil();
    break;
    case 3:
      pieza = Caballo();
      pieza2 = Caballo();
    break;
    case 4:
      pieza = Peon();
      pieza2 = Peon();
    break;
    case 5:
      pieza = Torre();
      pieza2 = Torre();
    break;
  }
}

bool validar(string coor, bool si = false) {
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
    if (si) {
      return pieza.validarMoviento(act1, act2, nuevo1, nuevo2);
    }
    return true;
}

int menuP() {
  int op;
  cout << "0. Salir" << endl;
  cout << "1. Juego Nuevo" << endl << "2. Recrear Partida: ";
  cin >> op;
  cin.ignore();
  if (op < 0 || op > 2) {
    return menuP();
  }
  return op;
}

int continuar() {
  int op;
  cout << "Desea continuar?" << endl << "1. Si" << endl << "0. No: ";
  cin >> op;
  cin.ignore();
  if (op < 0 || op > 1) {
    return continuar();
  }
  return op;
}

string ingresoPos() {
  string coor;
  cout << "Ingrese las coordenadas: ";
  cin >> coor;
  cin.ignore();
  while (!validar(coor)) {
    cout << "Coordenadas invalidas!!!\nIngrese de la forma [actual, nuevo]!\nVuelva a intentar: ";
    cin >> coor;
  }
  return coor;
}

void jugar() {
  stPieza();
  do {
    //Jugador 1

  } while (continuar());
}

int main() {
  int op, subOpP;
  do {
    op = menuP();

  } while (op);
  return 0;
}
