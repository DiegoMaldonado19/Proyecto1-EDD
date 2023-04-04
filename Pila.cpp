#include "Pila.hpp"

Pila::Pila(int tamanio){
    this->array = new Cancion[tamanio];
    this->capacidad = tamanio;
    this->top = -1;
}

Pila:: ~Pila(){
    cout<<"Destruyendo Pila"<<endl;
}

void Pila::push(Cancion *cancion){
    if(this->llena()){
        cout<<"Pila llena"<<endl;
    }
    else {
        cout<<"Insertando: "<<cancion->getNombre()<<endl;
        this->array[++top] = cancion;
    }
}

void Pila:pop(){
    if(this->vacia()){
        cout<<"Pila vacia"<<endl;
    }
    else {
        this->array[top--];
    }
}

bool Pila::llena(){
    return top == capacidad-1;
}

bool Pila::vacia(){
    return top == -1;
}

int Pila::getTamanio(){
    return this->capacidad;
}


