#include "ListaCanciones.hpp"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <alsa/asoundlib.h>

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
    }
}

void ListaCanciones::reproduccionNormal(){
    Nodo* actual = this->primero;

    if(this->primero != NULL){
        do{ 
            reproduccion(actual->getCancion());
            actual = actual->getSiguiente();
        }
        while(actual!=this->primero);
    } else {
        cout<<"Lista vacia"<<endl;
    }
}

void ListaCanciones::reproduccion(Cancion* cancion){

  const char* file_name = cancion->getNombre().c_str();

  snd_pcm_t* pcm_handle;
  snd_pcm_hw_params_t* params;
  int dir;
  unsigned int rate = 44100;
  int channels = 2;
  snd_pcm_uframes_t frames;
  char* buffer;

  // Open the default PCM device for playback.
  if (snd_pcm_open(&pcm_handle, "default", SND_PCM_STREAM_PLAYBACK, 0) < 0) {
    std::cerr << "Error opening PCM device" << std::endl;
  }

  // Allocate a hardware parameters object.
  snd_pcm_hw_params_alloca(&params);

  // Fill it with default values.
  snd_pcm_hw_params_any(pcm_handle, params);

  // Set the desired hardware parameters.
  snd_pcm_hw_params_set_access(pcm_handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
  snd_pcm_hw_params_set_format(pcm_handle, params, SND_PCM_FORMAT_S16_LE);
  snd_pcm_hw_params_set_channels(pcm_handle, params, channels);
  snd_pcm_hw_params_set_rate_near(pcm_handle, params, &rate, &dir);

  // Write the parameters to the driver.
  if (snd_pcm_hw_params(pcm_handle, params) < 0) {
    std::cerr << "Error setting hardware parameters" << std::endl;
  }

  // Allocate a buffer to hold one period of audio data.
  snd_pcm_hw_params_get_period_size(params, &frames, &dir);
  int size = frames * channels * 2;
  buffer = (char*)malloc(size);

  // Open the audio file for reading.
  FILE* audio_file = fopen(file_name, "rb");
  if (audio_file == nullptr) {
    std::cerr << "Error opening audio file" << std::endl;
  }

  // Read audio data from the file and play it.
  while (fread(buffer, 1, size, audio_file) == (unsigned int)size) {
    if (snd_pcm_writei(pcm_handle, buffer, frames) == -EPIPE) {
      snd_pcm_prepare(pcm_handle);
    }
  }

  // Clean up resources.
  free(buffer);
  snd_pcm_drain(pcm_handle);
  snd_pcm_close(pcm_handle);
  fclose(audio_file);
}