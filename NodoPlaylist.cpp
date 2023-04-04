#include "NodoPlaylist.hpp"

NodoPlaylist::NodoPlaylist(ListaCanciones *lista, NodoPlaylist *siguiente){
    this->lista = lista;
    this->siguiente = siguiente;
    this->indice=0;
}

NodoPlaylist::~NodoPlaylist(){
    cout<<"Eliminando Lista: "<<this->getLista()->getNombre()<<endl;
}

ListaCanciones* NodoPlaylist::getLista(){
    return this->lista;
}

void NodoPlaylist::setLista(ListaCanciones *lista){
    this->lista = lista;
}

NodoPlaylist* NodoPlaylist::getSiguiente(){
    return this->siguiente;
}

void NodoPlaylist::setSiguiente(NodoPlaylist *siguiente){
    this->siguiente = siguiente;
}

int NodoPlaylist::getIndice(){
    return this->indice;
}

void NodoPlaylist::setIndice(int indice){
    this->indice = indice;
}
