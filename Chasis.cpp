#include "Chasis.h"

Chasis::Chasis(string Tipo, bool Tran){
    tipo = Tipo;
    transmicion = Tran;
}

string Chasis::getTipo(){
    return tipo;
}

void Chasis::setTipo(string Tipo){
    tipo = Tipo;
}

bool Chasis::getTransmicion(){
    return transmicion;
}

void Chasis::setTransmicion(bool tran){
    transmicion = tran;
}



