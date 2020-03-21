#include "Partida.hpp"
#include "Pieza.hpp"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Partida::Partida(string nombre, Pieza pieza) {
  this -> nombre = nombre;
  this-> pieza = pieza;
}

void Partida::guardarPartida() {
  archivo.open("bitacoraPartidas.txt", ios::app);
  if(archivo.is_open()) {
    archivo << nombre << "\n";
    archivo << pieza.toString() << "\n";
    for (int i = 0; i < movimientos.size(); i++) {
      archivo << movimientos[i] << ';';
    }
    archivo << endl << '!';
  }
}
