#include "Pintura.h"

Pintura::Pintura(string Color, string aca){
    color = Color;
    acabado = aca;
}

string Pintura::getColor(){
    return color;
}

void Pintura::setColor(string c){
    color = c;
}

string Pintura::getAcabado(){
    return acabado;
}

void Pintura::setAcabado(string a){
    acabado = a;
}