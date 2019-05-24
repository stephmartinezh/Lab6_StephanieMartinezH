#include "Motor.h"

Motor::Motor(bool ele, string conf){
    electrico = ele;
    configuracion = conf;
}

bool Motor::getElectrico(){
    return electrico;
}

void Motor::setElectrico(bool ele){
    electrico = ele;
}

string Motor::getConfiguracion(){
    return configuracion;
}

void Motor::setConfiguracion(string conf){
    configuracion = conf;
}