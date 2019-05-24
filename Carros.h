#ifndef CARROS_H
#define CARROS_H

#include "Chasis.h"
#include "Motor.h"
#include "Pintura.h"

#include <string>
using std::string;

class Carros{
    private:
        string nombre;
        int numero;
    public:
        Carros(string,int);
        string getNombre();
        void setNombre(string);
        int getNumero();
        void setNumero(int);
};

#endif