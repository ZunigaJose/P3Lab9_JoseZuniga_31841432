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

Pieza *pieza;
Rey rey1, rey2;
vector<Partida> partidas;
string posP1 = "", posR1 = "", posP2 = "", posR2 = "";

int charInt(char c) {
  return c - 97;
}

void posini() {
  posP1 = pieza->getPosInij1();
  posP2 = pieza->getPosInij2();
  posR1 = "e1";
  posR2 = "e8";
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
      pieza = new Dama();
    break;
    case 2:
      pieza = new Alfil();
    break;
    case 3:
      pieza = new Caballo();
    break;
    case 4:
      pieza = new Peon();
    break;
    case 5:
      pieza = new Torre();
    break;
    posini();
  }
}

bool validarEntrada(string coor) {
  if (coor.size() != 7) {
    return false;
  }
  string cp = coor;
  string act = cp.substr(1, 2);
  string nuevo = coor.substr(4, 5);
  int act1, act2, nuevo1, nuevo2;
  act1 = charInt(act[0]);
  nuevo1 = charInt(nuevo[0]);
  cout << nuevo;
  //cout << endl << nuevo;
  if (act1 < 0 || act1 > 7 || nuevo1 < 0 || nuevo1 > 7) {
    return false;
  }
  act2 = act[1] - 49;
  nuevo2 = nuevo[1] - 49;
  if (act2 < 0 || act2 > 7 || nuevo2 < 0 || nuevo2 > 7) {
    return false;
  }
  cout << "act1: " << act1 << " act2 " << act2 << " nuevo1 " << nuevo1 << " nuevo2 " << nuevo2;
  return true;
}

bool validar(string coor, bool j1 = false) {
  cout << "Hasta aqui";
  string act = coor.substr(1, 2);
  string nuevo = coor.substr(4, 5);
  int act1, act2, nuevo1, nuevo2;
  act1 = charInt(act[0]);
  nuevo1 = charInt(nuevo[0]);
  act2 = act[1] - 49;
  nuevo2 = nuevo[1] - 49;
  if (j1) {
    if (act == posP1) {
      return pieza->validarMoviento(act1, act2, nuevo1, nuevo2);
    }
    if (act == posR1) {
      Pieza *rey = new Rey;
      return rey->validarMoviento(act1, act2, nuevo1, nuevo2);
    }
  } else {
    if (act == posP2) {
      return pieza->validarMoviento(act1, act2, nuevo1, nuevo2);
    }
    if (act == posR2) {
      Pieza *rey = new Rey;
      return rey->validarMoviento(act1, act2, nuevo1, nuevo2);
    }
  }
  return false;
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

string ingresoCoor() {
  string coor;
  cout << "Ingrese las coordenadas: ";
  cin >> coor;
  cin.ignore();
  while (!validarEntrada(coor)) {
    cout << "Coordenadas invalidas!!!\nIngrese de la forma [actual, nuevo]!\nVuelva a intentar: ";
    cin >> coor;
    cin.ignore();
  }
  cout << "Hasta aqui";
  return coor;
}

void jugar() {
  string coorj1, coorj2;
  string act;
  stPieza();
  do {
    //Jugador 1
    coorj1 = ingresoCoor();
    while (validar(coorj1, true)) {
      cout << "Esta intentando hacer una movida ILEGAL!!\a\nVuelva a intentar: ";
      cin >> coorj1;
    }
    partidas[partidas.size() - 1].setMovimiento(coorj1);
    act = coorj1.substr(1, 2);
    if(act == posP1) {
      posP1 = act;
    }
    if (act == posR1){
      posR2 = act;
    }
    coorj2 = ingresoCoor();
    while (validar(coorj2)) {
      cout << "Esta intentando hacer una movida ILEGAL!!\a\nVuelva a intentar: ";
      cin >> coorj2;
    }
    partidas[partidas.size() - 1].setMovimiento(coorj2);
    act = coorj2.substr(1, 2);
    if(act == posP2) {
      posP1 = act;
    }
    if (act == posR2){
      posR2 = act;
    }
  } while (continuar());
  partidas[partidas.size() - 1].guardarPartida();
}

int main() {
  int op, subOpP;
  do {
    op = menuP();
    switch (op) {
      case 1:
      jugar();
      break;
      case 2:
      //recrear;
      break;
    }
  } while (op);
  return 0;
}
