#include "Nodo.hpp"

Nodo::Nodo(Cancion *cancion, Nodo *siguiente){
    this->cancion = cancion;
    this->siguiente = siguiente;
    this->indice=0;
}

Nodo::~Nodo(){
    cout<<"Eliminando Cancion "<<this->cancion->getNombre()<<endl;
}

Cancion* Nodo::getCancion(){
    return this->cancion;
}

void Nodo::setCancion(Cancion *cancion){
    this->cancion = cancion;
}

Nodo* Nodo::getSiguiente(){
    return this->siguiente;
}

void Nodo::setSiguiente(Nodo *siguiente){
    this->siguiente = siguiente;
}

int Nodo::getIndice(){
    return this->indice;
}

void Nodo::setIndice(int indice){
    this->indice = indice;
}
