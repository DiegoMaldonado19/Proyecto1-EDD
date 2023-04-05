#include <iostream>
#include <string>
#include "Cancion.hpp"

using namespace std;

Cancion::Cancion(string nombre, string path){
    this->nombre = nombre;
    this->path = path;
}

Cancion::~Cancion(){
    cout << "ELiminando cancion "<< this->nombre << endl;
}

string Cancion::getPath(){
    return this->path;
}

void Cancion::setPath(string path){
    this->path = path;
}

string Cancion::getNombre(){
    return this->nombre;
}

void Cancion::setNombre(string nombre){
    this->nombre = nombre;
}