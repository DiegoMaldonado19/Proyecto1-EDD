#include "ListaEnlazada.hpp"

ListaEnlazada::ListaEnlazada(string nombre, string descripcion){
    this->cabeza = NULL;
    /**
    this->numeroElementos = (int *)0;
    */
    this->nombre = nombre;
    this->descripcion = descripcion;
    /*
    this->cabeza->setIndice((int *)0);
    */
}

ListaEnlazada::~ListaEnlazada(){
    cout<<"Eliminando Lista "<<this->nombre<<endl;
}

void ListaEnlazada::insertarCancion(Cancion *cancion){
    Nodo *nuevo = new Nodo(cancion, NULL);
    if (this->cabeza == NULL){
        this->cabeza = nuevo;
        cout<< "insertando al inicio"<<endl;
        /*
        this->cabeza->setIndice((int *)1);
        */
    }
    else {
        Nodo *actual = this->cabeza;
        while (actual->getSiguiente() != NULL){
            actual = actual->getSiguiente();
            
        }
        actual->setSiguiente(nuevo);
        cout<< "insertando al final"<<endl;
        /*
        this->numeroElementos++;
        nuevo->setIndice(this->numeroElementos);
        */
    }
}

void ListaEnlazada::graficarLista(){
    Nodo *actual = this->cabeza;
    cout<<"CABEZA: "<<this->cabeza->getCancion()->getNombre()<<endl;
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