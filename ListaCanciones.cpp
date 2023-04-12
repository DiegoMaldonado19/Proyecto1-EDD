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

void ListaCanciones::reiniciarNumeroElementos(){
    Nodo* actual = this->primero;
    int contador=0;
    do{
        actual = actual->getSiguiente();
        contador++;
    } while(actual != this->primero);

    numeroElementos = contador;
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
        system("read -p 'Presione enter para continuar...' var");
    } else {
        ultimo->setSiguiente(nuevo);
        nuevo->setSiguiente(this->primero);
        nuevo->setAnterior(this->ultimo);
        this->ultimo = nuevo;

        primero->setAnterior(this->ultimo);

        numeroElementos++;
        nuevo->setIndice(numeroElementos);
        cout<<"Cancion agregada con exito: "<<nuevo->getCancion()->getNombre()<<endl;
        system("read -p 'Presione enter para continuar...' var");
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
        system("read -p 'Presione enter para continuar...' var");
    }
}

void ListaCanciones::buscarElemento(string nombre){
    Nodo* actual = this->primero;
    bool encontrado = false;

    if(this->primero != NULL){
       do{
            if(actual->getCancion()->getNombre() == nombre){
                cout<<"Indice: "<<actual->getIndice();
                cout<<" Cancion: "<<actual->getCancion()->getNombre()<<" encontrada "<<endl;
                system("read -p 'Presione enter para continuar...' var");
                encontrado=true;
            }
            actual = actual->getSiguiente();
        }
        while(actual!=this->primero && encontrado!=true);

        if(encontrado==false){
            cout<<"Cancion: "<<nombre<<" no encontrada"<<endl;
            system("read -p 'Presione enter para continuar...' var");
        }
    } else {
        cout<<"Lista vacia"<<endl;
        system("read -p 'Presione enter para continuar...' var");
    }
}

Cancion* ListaCanciones::obtenerCancion(int id){
    Nodo* actual = this->primero;
    bool encontrado = false;

    if(this->primero != NULL){
        do{
            if(actual->getIndice() == id){
                cout<<"Indice: "<<actual->getIndice();
                cout<<" Cancion: "<<actual->getCancion()->getNombre()<<" encontrada "<<endl;
                system("read -p 'Presione enter para continuar...' var");
                encontrado=true;
                return actual->getCancion();
            }
            actual = actual->getSiguiente();
        }
        while(actual!=this->primero && encontrado!=true);

        if(encontrado==false){
            cout<<"Cancion: "<<nombre<<" no encontrada"<<endl;
            system("read -p 'Presione enter para continuar...' var");
        }
    } else {
        cout<<"Lista vacia"<<endl;
        system("read -p 'Presione enter para continuar...' var");
    }
    return actual->getCancion();
}

Cancion* ListaCanciones::obtenerCancionProvidencial(int id){
    Nodo* actual = this->primero;
    bool encontrado = false;

    if(this->primero != NULL){
        do{
            if(actual->getIndice() == id){
                encontrado=true;
                return actual->getCancion();
            }
            actual = actual->getSiguiente();
        }
        while(actual!=this->primero && encontrado!=true);
    } else {
        cout<<"Lista vacia"<<endl;
        system("read -p 'Presione enter para continuar...' var");
    }
    return actual->getCancion();
}

void ListaCanciones::eliminarElementoPorId(int id){
    Nodo* actual = this->primero;
    Nodo* anterior = this->ultimo;

    char eleccion;
    bool encontrado = false;

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
                    system("read -p 'Presione enter para continuar...' var");
                    break;
                } else if (eleccion=='N' || eleccion=='n'){
                    system("clear");
                    cout<<"Saliendo..."<<endl;
                    system("read -p 'Presione enter para continuar...' var");
                    break;
                } else {
                    cout<<"Opcion incorrecta"<<endl;
                    system("read -p 'Presione enter para continuar...' var");
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
                    system("read -p 'Presione enter para continuar...' var");
                    break;
                } else if (eleccion=='N' || eleccion=='n'){
                    system("clear");
                    cout<<"Saliendo..."<<endl;
                    system("read -p 'Presione enter para continuar...' var");
                    break;
                } else {
                    cout<<"Opcion incorrecta"<<endl;
                    system("read -p 'Presione enter para continuar...' var");
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
                    system("read -p 'Presione enter para continuar...' var");
                    break;
                } else if (eleccion=='N' || eleccion=='n'){
                    system("clear");
                    cout<<"Saliendo..."<<endl;
                    system("read -p 'Presione enter para continuar...' var");
                    break;
                }  else {
                    cout<<"Opcion incorrecta"<<endl;
                    system("read -p 'Presione enter para continuar...' var");
                    break;
                }
            }
            encontrado = true;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    } while(actual!=this->primero && encontrado==false);
}

void ListaCanciones::eliminarElementoPorNombre(string nombre){
    Nodo* actual = this->primero;
    Nodo* anterior = this->ultimo;

    char eleccion;
    bool encontrado = false;

    do{
        if(actual->getCancion()->getNombre() == nombre){
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
                    system("read -p 'Presione enter para continuar...' var");
                    break;
                } else if (eleccion=='N' || eleccion=='n'){
                    system("clear");
                    cout<<"Saliendo..."<<endl;
                    system("read -p 'Presione enter para continuar...' var");
                    break;
                } else {
                    cout<<"Opcion incorrecta"<<endl;
                    system("read -p 'Presione enter para continuar...' var");
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
                    system("read -p 'Presione enter para continuar...' var");
                    break;
                } else if (eleccion=='N' || eleccion=='n'){
                    system("clear");
                    cout<<"Saliendo..."<<endl;
                    system("read -p 'Presione enter para continuar...' var");
                    break;
                } else {
                    cout<<"Opcion incorrecta"<<endl;
                    system("read -p 'Presione enter para continuar...' var");
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
                    system("read -p 'Presione enter para continuar...' var");
                    break;
                } else if (eleccion=='N' || eleccion=='n'){
                    system("clear");
                    cout<<"Saliendo..."<<endl;
                    break;
                }  else {
                    cout<<"Opcion incorrecta"<<endl;
                    system("read -p 'Presione enter para continuar...' var");
                    break;
                }
            }
            encontrado = true;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    } while(actual!=this->primero && encontrado==false);
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
        system("read -p 'Presione enter para continuar...' var");
    }
}

void ListaCanciones::reproduccionNormal(){
    Nodo* actual = this->primero;
    Pila* pila = listaDeReproduccion(actual->getCancion());
    if(this->primero != NULL){
        do{ 
            reproduccion(actual->getCancion());
            actual = actual->getSiguiente();
            if(pila->vacia()){
                
            }
            else{
                pila->pop();
                visualizarListaDeReproduccion(pila);
            }
            system("read -p 'Presione enter para continuar...' var");
        }
        while(actual!=this->primero);
    } else {
        cout<<"Lista vacia"<<endl;
        system("read -p 'Presione enter para continuar...' var");
    }
}

void ListaCanciones::reproduccionRepeticion(){
    Nodo* actual = this->primero;
    bool cancelarReproduccion=false;
    char opcion;
    Pila* pila = listaDeReproduccion(actual->getCancion());

    if(this->primero != NULL){
        do{
            reproduccion(actual->getCancion());
            actual = actual->getSiguiente();
            if(pila->vacia()){
                pila = listaDeReproduccion(actual->getCancion());
            }
            else{
                pila->pop();
                visualizarListaDeReproduccion(pila);
            }
            system("read -p 'Presione enter para continuar...' var");
            cout<<"\n\n"<<endl;
            cout<<"Desea salir de la reproduccion en repeticion?"<<endl;
            cout<<"Presione Y, si desea salir..."<<endl;
            cout<<"Presione N, si desea continuar con la reproduccion..."<<endl;
            cin>>opcion;
            if(opcion == 'Y' || opcion=='y'){
                cancelarReproduccion = true;
            } else if(opcion == 'N' || opcion == 'n'){
                cancelarReproduccion = false;
            } else {    
                cout<<"Opcion incorrecta, la reproduccion continuara..."<<endl;
                system("read -p 'Presione enter para continuar...' var");
                cancelarReproduccion = false;
            }
        } while(cancelarReproduccion==false);
    } else {
        cout<<"Lista vacia"<<endl;
    }
}

void ListaCanciones::reproduccion(Cancion* cancion){
    system("clear");
    cout<<"\n\n"<<endl;
    cout<<"IMPORTANTE: para finalizar la reproduccion, puede presionar la tecla q"<<endl;
    cout<<"\n\n"<<endl;
    string informacion = cancion->getPath() + cancion->getNombre();
    string command = "mpg123 " + informacion;
    system(command.c_str());
    system("clear");
}

Pila* ListaCanciones::listaDeReproduccion(Cancion* cancionActual){
    Pila* pila = new Pila(this->numeroElementos);

    Nodo* actual = this->ultimo;

    if(this->primero != NULL){
        do{
            pila->push(actual->getCancion());
            actual = actual->getAnterior();
        } while(actual->getCancion() != cancionActual);
    } else {
        cout<<"Lista vacia"<<endl;
    }

    return pila;
}

void ListaCanciones::visualizarListaDeReproduccion(Pila* pila){
    cout<<"Lista de Reproduccion"<<endl;
    pila->imprimirPila();
}

bool ListaCanciones::isVacia(){
    if(this->primero==NULL){
        return true;
    }
    return false;
}