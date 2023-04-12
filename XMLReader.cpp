#include "tinyxml2.h"
#include "XMLReader.hpp"


using namespace tinyxml2;


XMLReader::XMLReader(){

}

XMLReader::~XMLReader(){

}

ListaCanciones* XMLReader::storeXML(XMLElement* raiz, ListaCanciones* store){
    string nombre;
    if (raiz != nullptr) {
        XMLElement* cancionElem = raiz->FirstChildElement("cancion");
        while (cancionElem != nullptr) {
            Cancion* cancion = new Cancion();
            nombre = cancionElem->FirstChildElement("Nombre")->GetText();
            cancion->setNombre(cancionElem->FirstChildElement("Nombre")->GetText());
            cancion->setPath(cancionElem->FirstChildElement("path")->GetText());
            XMLElement* posElem = cancionElem->FirstChildElement("Pos");
            store->insertarCancion(cancion);
            if (posElem != nullptr) {
                store->cambiarIdCancion(nombre, posElem->IntText());
            }
            cancionElem = cancionElem->NextSiblingElement("cancion");
        }
    }
    return store; 
}

ListaPlaylist* XMLReader::listaXML(XMLElement* raiz, ListaPlaylist* playlist, ListaCanciones* store){
    ListaCanciones* listaNueva;
    NodoPlaylist* nodoNuevo;
    Cancion* pivote;
    string nombre;
    string descripcion;
    int pos=0;
    if (raiz != nullptr) {
        XMLElement* listaElem = raiz->FirstChildElement("Lista");
        while (listaElem != nullptr) {
            nombre = listaElem->FirstChildElement("Nombre")->GetText();
            descripcion = listaElem->FirstChildElement("Description")->GetText();
            listaNueva = new ListaCanciones(nombre, descripcion);
            XMLElement* cancionesElem = listaElem->FirstChildElement("Canciones");
            if (cancionesElem != nullptr) {
                XMLElement* posElem = listaElem->FirstChildElement("Pos");
                while (posElem != nullptr) {
                    pos = posElem->IntText();

                    pivote = store->obtenerCancion(pos);

                    if(pivote==NULL){
                        cout<<"Cancion no existe dentro de store"<<endl;
                        system("read -p 'Presione enter para continuar...' var");
                    }
                    listaNueva->insertarCancion(pivote);
                    posElem = posElem->NextSiblingElement("Pos");
                }
                nodoNuevo = new NodoPlaylist(listaNueva, NULL);
                playlist->insertarListaPlaylist(nodoNuevo);
            } else {
                nodoNuevo = new NodoPlaylist(listaNueva, NULL);
                playlist->insertarListaPlaylist(nodoNuevo);
            }
            listaElem = listaElem->NextSiblingElement("Lista");
        }
    }
    return playlist;
}

ListaCanciones* XMLReader::eliminarCancionStoreXML(XMLElement* raiz, ListaCanciones* store){
    int pos=0;
    string nombre;
    if (raiz != nullptr) {
        XMLElement* cancionElem = raiz->FirstChildElement("cancion");
        while (cancionElem != nullptr) {
            XMLElement* posElem = cancionElem->FirstChildElement("Id");
            if(posElem != nullptr){
                pos = posElem->IntText();
                store->eliminarElementoPorId(pos);
                posElem = posElem->NextSiblingElement("Id");
            }

            XMLElement* nombreElem = cancionElem->FirstChildElement("Nombre");
            if(nombreElem != nullptr){
                nombre = cancionElem->FirstChildElement("Nombre")->GetText();
                store->eliminarElementoPorNombre(nombre);
                nombreElem = nombreElem->NextSiblingElement("Nombre");
            }
            cancionElem = cancionElem->NextSiblingElement("cancion");
        }
    }
    return store;
}

ListaPlaylist* XMLReader::eliminarListaXML(XMLElement* raiz, ListaPlaylist* playlist){
    int pos=0;
    int pos2=0;
    string nombre;
    if (raiz != nullptr) {
        XMLElement* listaElem = raiz->FirstChildElement("Lista");
        while (listaElem != nullptr) {

            XMLElement* nombreElem = listaElem->FirstChildElement("Nombre");
            if(nombreElem != nullptr){
                nombre = listaElem->FirstChildElement("Nombre")->GetText();
                playlist->eliminarListaPorNombre(nombre);
                nombreElem = nombreElem->NextSiblingElement("Nombre");
            }

            XMLElement* posElem = listaElem->FirstChildElement("Id");
            if(posElem != nullptr){
                pos = posElem->IntText();
                posElem = posElem->NextSiblingElement("Id");
                XMLElement* cancionesElem = listaElem->FirstChildElement("Canciones");
                if (cancionesElem != nullptr) {
                    XMLElement* pos2Elem = listaElem->FirstChildElement("Pos");
                    while (pos2Elem != nullptr) {
                        pos2 = pos2Elem->IntText();
                        playlist->eliminarCancion(pos2, pos);
                        posElem = posElem->NextSiblingElement("Pos");
                    }
                } else {
                    playlist->eliminarListaPorIndice(pos);
                }
            }
            listaElem = listaElem->NextSiblingElement("Lista");
        }
    }
    return playlist;
}


