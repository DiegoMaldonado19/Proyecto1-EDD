#include "ListaEnlazada.hpp"

int ListaEnlazada::numeroElementos = 0;

ListaEnlazada::ListaEnlazada(string nombre, string descripcion){
    this->cabeza = NULL;
    this->nombre = nombre;
    this->descripcion = descripcion;
}

ListaEnlazada::~ListaEnlazada(){
    cout<<"Eliminando Lista "<<this->nombre<<endl;
}

void ListaEnlazada::insertarCancion(Cancion *cancion){
    Nodo *nuevo = new Nodo(cancion, NULL);
    if (this->cabeza == NULL){
        this->cabeza = nuevo;
        numeroElementos++;
        this->cabeza->setIndice(numeroElementos);
    }
    else {
        Nodo *actual = this->cabeza;
        while (actual->getSiguiente() != NULL){
            actual = actual->getSiguiente();
            
        }
        actual->setSiguiente(nuevo);
        numeroElementos++;
        nuevo->setIndice(numeroElementos);
    }
}

void ListaEnlazada::graficarLista(){
    cout<<"Lista: "<<this->nombre<<endl;
    cout<<"Descripcion: "<<this->descripcion<<endl;
    Nodo *actual = this->cabeza;
    while (actual->getSiguiente() != NULL){
        cout<<"Indice: "<<actual->getIndice();
        cout<<" Cancion: "<<actual->getCancion()->getNombre();
        cout<<" Path: "<<actual->getCancion()->getPath()<<endl;

        actual = actual->getSiguiente();
    
    }
    cout<<"Indice: "<<actual->getIndice();
    cout<<" Cancion: "<<actual->getCancion()->getNombre();
    cout<<" Path: "<<actual->getCancion()->getPath()<<endl;
}