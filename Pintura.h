#ifndef PINTURA_H
#define PINTURA_H

#include <string>
using std::string;

class Pintura{
    private:
        string color, acabado;
    public:
        Pintura(string, string);
        string getColor();
        void setColor(string);
        string getAcabado();
        void setAcabado(string);
};
#endif