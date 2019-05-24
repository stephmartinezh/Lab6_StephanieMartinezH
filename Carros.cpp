#include "Carros.h"

Carros::Carros(string Nombre, int Numero){
    nombre = Nombre;
    numero = Numero;
}

string Carros::getNombre(){
    return nombre;
}

void Carros::setNombre(string Nombre){
    nombre = Nombre;
}

int Carros::getNumero(){
    return numero;
}

void Carros::setNumero(int Numero){
    numero = Numero;
}
