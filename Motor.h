#ifndef MOTOR_H
#define MOTOR_H

#include <string>
using std::string;

class Motor{
    private:
        bool electrico;
        string configuracion;
    public:
        Motor(bool, string);
        bool getElectrico();
        void setElectrico(bool);
        string getConfiguracion();
        void setConfiguracion(string);
};
#endif