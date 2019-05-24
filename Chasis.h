#ifndef CHASIS_H
#define CHASIS_H

#include <string>
using std::string;

class Chasis{
    private:
        string tipo;
        bool transmicion;
    public:
        Chasis(string, bool);
        string getTipo();
        void setTipo(string);
        bool getTransmicion();
        void setTransmicion(bool);
};

#endif