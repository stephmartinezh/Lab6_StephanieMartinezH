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

void liberarMatriz(string**);

string** llenarMatrizP(string**, int);

string** mat();

void imprimirMatriz(string**);

int main(){
    int opcion;
    string** matriz = NULL;
    vector<Carros*> carro;
    vector<Chasis*> chasis;
    vector<Motor*> motor;
    vector<Pintura*> pintura;
    matriz = mat();
    do{
        int cont = 0;
        // int sizeCarros*** carro;
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
                matriz = llenarMatrizP(matriz, cont);
                imprimirMatriz(matriz);
                cont++;
                cout<<"Se ha agregado la línea de producción correctamente"<<endl;
            }else{
                cout<<"Ya se ha alcanzado el máximo de carros modelo."<<endl;
            }
            cout<<"-------------------------"<<endl;
        }
        if(opcion == 2){
            cout<<"-------------------------"<<endl;
            imprimirMatriz(matriz);
            cout<<"-------------------------"<<endl;
        }
        
    }while(opcion!=6);
    for (int i = 0; i < carro.size(); i++)
        {
            delete carro[i];
            delete chasis[i];
            delete motor[i];
            delete pintura[i];
        }
    liberarMatriz(matriz);
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

/*Carros*** agregar(){carro
    Carros*** carro;
        //return carro;
}*/

vector<Carros*> agregarCarro(){
    vector<Carros*> carro;
    string modelo;
    int numero;
    cout<<"Ingrese el nombre del modelo: ";
    cin>>modelo;
    cout<<"Ingrese el número: ";
    cin>> numero;
    carro.push_back(new Carros(modelo,numero));
    return carro;
}

vector<Chasis*> agregarChasis(){
    string tipo;
    bool transmicion;
    vector<Chasis*> chasis;
    cout<<"Ingrese el tipo de ruedas: ";
    cin>>tipo;
    cout<<"Ingrese 1 si es automático o 2 si no es automatico: ";
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
    cout<<"Ingrese 1 si tiene un motor eléctrico o 2 si no tiene un motor eléctrico: ";
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

string** mat(){
    string** mat = new string*[5];
    for (int i = 0; i < 5; i++)
    {
        mat[i] = new string[5];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mat[i][j] = "[ ]";
        }
        
    }
    return mat;
}

void liberarMatriz(string** mat){
        for(int i = 0; i<5; i++){
                delete[] mat[i];
        }
        delete[] mat;
}

void imprimirMatriz(string** matriz){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }   
}

string** llenarMatrizP(string** mat, int cont){
    mat[cont][0] = "[P]";
    return mat;
}