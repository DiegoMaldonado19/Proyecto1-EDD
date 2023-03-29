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
    if (this->isVacia()){
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

void ListaEnlazada::eliminarCancion(string nombre){
    if(this->isVacia()){
        cout<< "Lista vacia"<<endl;
    }
    else {
        if(this->cabeza->getCancion()->getNombre() == nombre ){
            this->cabeza = this->cabeza->getSiguiente();
            numeroElementos--;
        } else {
            Nodo *actual = this->cabeza;
            while(actual->getSiguiente() != NULL && actual->getSiguiente()->getCancion()->getNombre() != nombre){
                actual = actual->getSiguiente();
                if(actual->getSiguiente()==NULL){
                    cout<<"Cancion: "<<nombre<<" no existe dentro de la lista"<<endl;
                } else {
                    actual->setSiguiente(actual->getSiguiente()->getSiguiente());
                    numeroElementos--;
                }
            }
        }
    }
}

bool ListaEnlazada::isVacia(){
    if(this->cabeza == NULL){
        return true;
    }
    return false;
}