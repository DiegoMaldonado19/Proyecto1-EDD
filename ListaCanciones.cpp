#include "ListaCanciones.hpp"
#include <stdlib.h>
#include <iostream>
#include <stdio.h> 

using namespace std;

int ListaCanciones::numeroElementos = 0;

ListaCanciones::ListaCanciones(string nombre, string descripcion){
    this->primero = NULL;
    this->ultimo = NULL;
    this->nombre = nombre;
    this->descripcion = descripcion;
}

ListaCanciones::~ListaCanciones(){
    cout<<"Destruyendo Lista: "<<this->nombre;
    cout<<" Descripcion: "<<this->descripcion<<endl;
}

string ListaCanciones::getNombre(){
    return this->nombre;
}

void ListaCanciones::setNombre(string nombre){
    this->nombre = nombre;
}

string ListaCanciones::getDescripcion(){
    return this->descripcion;
}

void ListaCanciones::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

Nodo* ListaCanciones::getPrimero(){
    return this->primero;
}

void ListaCanciones::setPrimero(Nodo* primero){
    this->primero = primero;
}

Nodo* ListaCanciones::getUltimo(){
    return this->ultimo;
}

void ListaCanciones::setUltimo(Nodo* ultimo){
    this->ultimo = ultimo;
}

void ListaCanciones::insertarCancion(Cancion* cancion){
    Nodo* nuevo = new Nodo(cancion);
    if(this->primero == NULL){
        this->primero = nuevo;
        this->ultimo = nuevo;

        primero->setSiguiente(this->primero);

        ultimo->setAnterior(this->ultimo);

        numeroElementos++;
        primero->setIndice(numeroElementos);
        cout<<"Cancion agregada con exito: "<<nuevo->getCancion()->getNombre()<<endl;
    } else {
        ultimo->setSiguiente(nuevo);
        nuevo->setSiguiente(this->primero);
        nuevo->setAnterior(this->ultimo);
        this->ultimo = nuevo;

        primero->setAnterior(this->ultimo);

        numeroElementos++;
        nuevo->setIndice(numeroElementos);
        cout<<"Cancion agregada con exito: "<<nuevo->getCancion()->getNombre()<<endl;
    }
}

void ListaCanciones::imprimirLista(){
    Nodo* actual = this->primero;

    if(this->primero != NULL){
        do{
            cout << "Indice: " << actual->getIndice();
            cout << " Cancion: " << actual->getCancion()->getNombre();
            cout << " Path: " << actual->getCancion()->getPath() << endl;
            actual = actual->getSiguiente();
        } while(actual != this->primero);
    } else {
        cout<<"Lista vacia"<<endl;
    }
}

void ListaCanciones::buscarElemento(string nombre){
    Nodo* actual = this->primero;
    bool encontrado = false;

    if(this->primero != NULL){
        while(actual!=NULL && encontrado!=true){
            if(actual->getCancion()->getNombre() == nombre){
                cout<<"Indice: "<<actual->getIndice();
                cout<<" Cancion: "<<actual->getCancion()->getNombre()<<" encontrada "<<endl;
                encontrado=true;
            }
            actual = actual->getSiguiente();
        }
        if(encontrado==false){
            cout<<"Cancion: "<<nombre<<" no encontrada"<<endl;
        }
    } else {
        cout<<"Lista vacia"<<endl;
    }
}

void ListaCanciones::eliminarElementoPorId(int id){
    Nodo* actual = this->primero;
    Nodo* anterior = this->ultimo;

    char eleccion;

    do{
        if(actual->getIndice() == id){
            if(actual == this->primero){
                cout<<"Necesitamos su confirmacion para eliminar el elemento: "<<endl;
                cout<<"Indice: "<<actual->getIndice()<< " | Nombre: "<<actual->getCancion()->getNombre()<<endl;
                cout<<"Ingrese Y para eliminar"<<endl;
                cout<<"Ingrese N para no eliminar la cancion"<<endl;
                cin>>eleccion;

                if(eleccion=='Y' || eleccion=='y'){
                    this->primero = this->primero->getSiguiente();
                    this->ultimo->setSiguiente(this->primero);
                    this->primero->setAnterior(this->ultimo);
                    numeroElementos--;
                    arreglarIndices();
                    cout<<"Cancion eliminada con exito"<<endl;
                    break;
                } else if (eleccion=='N' || eleccion=='n'){
                    system("clear");
                    cout<<"Saliendo..."<<endl;
                    break;
                } else {
                    cout<<"Opcion incorrecta"<<endl;
                    break;
                }
            } else if(actual == this->ultimo){

                cout<<"Necesitamos su confirmacion para eliminar el elemento: "<<endl;
                cout<<"Indice: "<<actual->getIndice()<< " | Nombre: "<<actual->getCancion()->getNombre()<<endl;
                cout<<"Ingrese Y para eliminar"<<endl;
                cout<<"Ingrese N para no eliminar la cancion"<<endl;
                cin>>eleccion;

                if(eleccion=='Y' || eleccion=='y'){
                    this->ultimo = anterior;
                    this->primero->setAnterior(this->ultimo);
                    this->ultimo->setSiguiente(this->primero);
                    numeroElementos--;
                    arreglarIndices();
                    cout<<"Cancion eliminada con exito"<<endl;
                    break;
                } else if (eleccion=='N' || eleccion=='n'){
                    system("clear");
                    cout<<"Saliendo..."<<endl;
                    break;
                } else {
                    cout<<"Opcion incorrecta"<<endl;
                    break;
                }              
            } else {
                cout<<"Necesitamos su confirmacion para eliminar el elemento: "<<endl;
                cout<<"Indice: "<<actual->getIndice()<< " | Nombre: "<<actual->getCancion()->getNombre()<<endl;
                cout<<"Ingrese Y para eliminar"<<endl;
                cout<<"Ingrese N para no eliminar la cancion"<<endl;
                cin>>eleccion;

                if(eleccion=='Y' || eleccion=='y'){
                    anterior->setSiguiente(actual->getSiguiente());
                    actual->getSiguiente()->setAnterior(anterior);
                    numeroElementos--;
                    arreglarIndices();
                    cout<<"Cancion eliminada con exito"<<endl;
                    break;
                } else if (eleccion=='N' || eleccion=='n'){
                    system("clear");
                    cout<<"Saliendo..."<<endl;
                    break;
                }  else {
                    cout<<"Opcion incorrecta"<<endl;
                    break;
                }
            }
        }
        anterior = actual;
        actual = actual->getSiguiente();
    } while(actual!=this->primero);
}

void ListaCanciones::arreglarIndices(){

    Nodo* actual = this->primero;
    int contador = 1;

    if(this->primero != NULL){
        do{
            actual->setIndice(contador);
            contador++;
            actual = actual->getSiguiente();
        }
        while(actual!=this->primero);
    } else {
        cout<<"Lista vacia"<<endl;
    }
}