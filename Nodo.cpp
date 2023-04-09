#include "Nodo.hpp"

using namespace std;

Nodo::Nodo(Cancion* cancion){
    this->anterior=NULL;
    this->siguiente=NULL;
    this->cancion=cancion;
    this->indice=0;
}

Nodo::~Nodo(){
    cout<<"Destruyendo Nodo: "<<this->cancion->getNombre()<<endl;
}

Nodo* Nodo::getAnterior(){
    return this->anterior;
}

void Nodo::setAnterior(Nodo* anterior){
    this->anterior = anterior;
}

Nodo* Nodo::getSiguiente(){
    return this->siguiente;
}

void Nodo::setSiguiente(Nodo* siguiente){
    this->siguiente = siguiente;
}

Cancion* Nodo::getCancion(){
    return this->cancion;
}

void Nodo::setCancion(Cancion* cancion){
    this->cancion = cancion;
}

int Nodo::getIndice(){
    return this->indice;
}

void Nodo::setIndice(int indice){
    this->indice = indice;
}