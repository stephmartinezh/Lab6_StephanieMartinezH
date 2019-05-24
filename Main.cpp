#include "Carros.h"
#include "Chasis.h"
#include "Motor.h"
#include "Pintura.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

#include <typeinfo>

#include <string>
using std::string;

int menu();

//Carros*** agregar();

vector<Carros*> agregarCarro();

vector<Chasis*> agregarChasis();

vector<Motor*> agregarMotor();

vector<Pintura*> agregarPintura();

int main(){
    int opcion;
    do{
        vector<Carros*> carro;
        vector<Chasis*> chasis;
        vector<Motor*> motor;
        vector<Pintura*> pintura;
        
        int cont = 0;
        //Carros*** carro;
        opcion = menu();
        while(opcion<1 || opcion >6){
            cout<<"El número que ha ingreasado no está dentro del rango"<<endl;
            opcion = menu();
        }
        if(opcion == 1){
            cout<<"-------------------------"<<endl;
            if(cont<=5){
                carro = agregarCarro();
                chasis = agregarChasis();
                motor = agregarMotor();
                pintura = agregarPintura();
            }else{
                cout<<"Ya se ha alcanzado el máximo de carros modelo."<<endl;
            }
            cout<<"-------------------------"<<endl;
        }
        for (int i = 0; i < carro.size(); i++)
        {
            delete carro[i];
            delete chasis[i];
            delete motor[i];
            delete pintura[i];
        }
        
    }while(opcion!=6);
    return 0;
}

int menu(){
    int opcion;
    cout<<"1.- Agregar una línea de producción"<<endl
        <<"2.- Ver matríz de líneas de producción"<<endl
        <<"3.- Ver detalles"<<endl
        <<"4.- Ver listado de carros producidos"<<endl
        <<"5.- Avanzar ciclo de línea de producción"<<endl
        <<"6.- Salir"<<endl;
    cout<<"     Ingrese una opción: ";
    cin>>opcion;
    return opcion;
}

/*Carros*** agregar(){
    Carros*** carro;
    string modelo, tipo, configuracion,color,acabado;
    bool transmicion, electrico;
    int numero = 0;
    cout<<"Ingrese el nombre del modelo: ";
    cin>>modelo;
    cout<<"Ingrese el tipo de ruedas: ";
    cin>>tipo;
    cout<<"Ingrese 1 si es automático o 2 si no es automatico";
    int a;
    cin>> a;
    if(a == 1){
        transmicion = true;
    }else{
        transmicion = false;
    }
    cout<<"Ingrese 1 si tiene un motor eléctrico o 2 si no tiene un motor eléctrico";
    int conf;
    cin>>conf;
    if(conf == 1){
        electrico = true;
    }else{
        electrico = false;
    }
    cout<<"Ingrese el color de la pintura: ";
    cin>>color;
    cout<<"Ingrese el acabado de la pintura: ";
    cin>>acabado;
    //return carro;
}*/

vector<Carros*> agregarCarro(){
    vector<Carros*> carro;
    string modelo;
    int numero = 0;
    cout<<"Ingrese el nombre del modelo: ";
    cin>>modelo;
    carro.push_back(new Carros(modelo,0));
    return carro;
}

vector<Chasis*> agregarChasis(){
    string tipo;
    bool transmicion;
    vector<Chasis*> chasis;
    cout<<"Ingrese el tipo de ruedas: ";
    cin>>tipo;
    cout<<"Ingrese 1 si es automático o 2 si no es automatico";
    int a;
    cin>> a;
    if(a == 1){
        transmicion = true;
    }else{
        transmicion = false;
    }
    chasis.push_back(new Chasis(tipo,transmicion));
    return chasis;
}

vector<Motor*> agregarMotor(){
    string  configuracion;
    bool electrico;
    vector<Motor*> motor;
    cout<<"Ingrese 1 si tiene un motor eléctrico o 2 si no tiene un motor eléctrico";
    int conf;
    cin>>conf;
    if(conf == 1){
        electrico = true;
    }else{
        electrico = false;
    }
    motor.push_back(new Motor(electrico, configuracion));
    return motor;
}

vector<Pintura*> agregarPintura(){
    string color,acabado;
    vector<Pintura*> pintura;
    cout<<"Ingrese el color de la pintura: ";
    cin>>color;
    cout<<"Ingrese el acabado: ";
    cin>>acabado;
    pintura.push_back(new Pintura(color,acabado));
    return pintura;
}