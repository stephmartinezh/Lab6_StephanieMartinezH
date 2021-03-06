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

void detalles(int cont, vector<Carros*>, vector<Chasis*>, vector<Motor*>, vector<Pintura*>, int);

string** avanzar(string** mat, int cont);

int main(){
    int opcion, avanzar1 = 1;
    string** matriz = NULL;
    vector<Carros*> carro;
    vector<Chasis*> chasis;
    vector<Motor*> motor;
    vector<Pintura*> pintura;
    matriz = mat();
    int cont = 0;
    do{
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
        if(opcion == 3){
            cout<<"-------------------------"<<endl;
            if(avanzar == 0){
                cout<<"No hay carros en la línea de producción"<<endl;
            }else{
                detalles(cont, carro, chasis, motor, pintura, avanzar1);                
            }
            cout<<"-------------------------"<<endl;
        }
        if(opcion == 4){
            cout<<"-------------------------"<<endl;
            cout<<"-------------------------"<<endl;
        }
        if(opcion == 5){
            cout<<"-------------------------"<<endl;
            matriz = avanzar(matriz,avanzar1);
            avanzar1++;
            cout<<"Se ha avanzado exitosamente"<<endl;
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
    string** mat = new string*[4];
    for (int i = 0; i < 4; i++)
    {
        mat[i] = new string[4];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat[i][j] = "[ ]";
        }
        
    }
    return mat;
}

void liberarMatriz(string** mat){
        for(int i = 0; i<4; i++){
                delete[] mat[i];
        }
        delete[] mat;
}

void imprimirMatriz(string** matriz){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
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

void detalles(int cont, vector<Carros*> carro,vector<Chasis*> chasis, vector<Motor*> motor, vector<Pintura*> pintura, int avanzar){
    for (int i = 0; i < cont; i++)
    {
        for (int j = 0; j < avanzar; j++)
        {
            cout<<"Modelo: "<<carro[j]->getNombre()<<carro[j]->getNumero()+1;
            cout<<" Tipo de ruedas: "<<chasis[j]->getTipo()<<" Transmición: "<<chasis[j]->getTransmicion();
            cout<<" Motor: "<<motor[j]->getElectrico()<<" Configuración: "<<motor[j]->getConfiguracion();
            cout<<" Color: "<<pintura[j]->getColor()<<" Acabado: "<<pintura[j]->getAcabado();
        }
        
    }
    
}

string** avanzar(string** mat, int cont){
    int cont2 = 0;
    for (int i = 0; i < 4; i++)
    {
        if(mat[i][0] == "[P]"){
            cont2++;
        }
    }

    for (int i = 0; i < cont2; i++)
    {
        for (int j = 1; j <= cont; j++)
        {
            mat[i][j] = "[C]";
        }
        
    }
    return mat;
}