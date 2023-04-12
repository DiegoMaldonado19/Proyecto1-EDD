#include "ListaPlaylist.hpp"
#include <stdlib.h>
#include <string>
#include <locale>
#include <iostream>
#include "XMLReader.hpp"
#include "tinyxml2.h"

using namespace tinyxml2;

string revisarEspacioEnBlanco(string nombre){
    int espacios=0;
    string resultado;
    for (int i = 0; i <= (int) nombre.length(); ++i){
        if (nombre[i] == ' '){
            espacios++;
        }
    }

    if(espacios!=0){
        resultado = "\'"+nombre+"\'";
        return resultado;
    }
    return nombre;
}

ListaCanciones* crearStore(){
    ListaCanciones* store = new ListaCanciones("Lista creada", "Lista cargada por sistema");

    Cancion *cancion = new Cancion("'Bad Bunny - Moscow Mule.mp3'", "/home/diego/Escritorio/LabEDD/Proyecto1/Music/");
    Cancion *cancion2 = new Cancion("'Bad Bunny - Yonaguni.mp3'", "/home/diego/Escritorio/LabEDD/Proyecto1/Music/");
    Cancion *cancion3 = new Cancion("'Bad Bunny ft Bomba Estéreo - Ojitos Lindos.mp3'", "/home/diego/Escritorio/LabEDD/Proyecto1/Music/");
    Cancion *cancion4 = new Cancion("'BAD BUNNY x JHAY CORTEZ - DÁKITI.mp3'", "/home/diego/Escritorio/LabEDD/Proyecto1/Music/");
    Cancion *cancion5 = new Cancion("'Ferxxo - Pantysito.mp3'", "/home/diego/Escritorio/LabEDD/Proyecto1/Music/");
    Cancion *cancion6 = new Cancion("'Jugaste y Sufri - Eslabon Armado ft DannyLux.mp3'", "/home/diego/Escritorio/LabEDD/Proyecto1/Music/");
    Cancion *cancion7 = new Cancion("'Megadeth - Holy WarsThe Punishment Due.mp3'", "/home/diego/Escritorio/LabEDD/Proyecto1/Music/");
    Cancion *cancion8 = new Cancion("'Metallica - One.mp3'", "/home/diego/Escritorio/LabEDD/Proyecto1/Music/");
    Cancion *cancion9 = new Cancion("'Recuerda Bien - Eslabon Armado.mp3'", "/home/diego/Escritorio/LabEDD/Proyecto1/Music/");
    Cancion *cancion10 = new Cancion("'Slayer - Seasons In The Abyss.mp3'", "/home/diego/Escritorio/LabEDD/Proyecto1/Music/");

    store->insertarCancion(cancion);
    store->insertarCancion(cancion2);
    store->insertarCancion(cancion3);
    store->insertarCancion(cancion4);
    store->insertarCancion(cancion5);
    store->insertarCancion(cancion6);
    store->insertarCancion(cancion7);
    store->insertarCancion(cancion8);
    store->insertarCancion(cancion9);
    store->insertarCancion(cancion10);

    return store;
}

ListaPlaylist* añadirListas(){
    ListaPlaylist* playlist = new ListaPlaylist();
    ListaCanciones* lista = new ListaCanciones("Perreo", "Para perrear hasta el subsuelo");
    ListaCanciones* lista2 = new ListaCanciones("Las mas perronas", "Estas no tienen comparacion");
    NodoPlaylist* nodo = new NodoPlaylist(lista, NULL);
    NodoPlaylist* nodo2 = new NodoPlaylist(lista2, NULL);
    playlist->insertarListaPlaylist(nodo);
    playlist->insertarListaPlaylist(nodo2);

    return playlist;
}

ListaPlaylist* crearListaPlaylist(ListaCanciones* store, ListaPlaylist* playlist){
    Cancion* pivote;

   
    for(int j=1; j<=5; j++){
        pivote = store->obtenerCancionProvidencial(j);

        playlist->ingresarCancion(pivote, 1);
    }
    for(int k=6; k<=10; k++){
        pivote = store->obtenerCancionProvidencial(k);

        playlist->ingresarCancion(pivote, 2);
    }

    store->reiniciarNumeroElementos();

    return playlist;
}

void menuReproduccion(ListaPlaylist* playlist){
    int opcion=0;
    int opcionReproduccion=0;
    int opcionReproduccionRep=0;
    bool salir=false;
    
    system("clear");
    cout<<"Menu de reproduccion"<<endl;
    cout<<"_______________________________________"<<endl;
    cout<<"1) Reproduccion normal"<<endl;
    cout<<"2) Reproduccion en Repeticion"<<endl;
    cout<<"3) Salir"<<endl;
    cin>>opcion;
    switch(opcion){
        case 1:
            salir=false;
            if(playlist->isVacia()){
                system("clear");
                cout<<"Debe crear al menos una lista para poder reproducirla, puede crearla en la opcion 2 del menu principal"<<endl;
                system("read -p 'Presione enter para continuar...' var");
            } else {
                system("clear");
                cout<<"Listas disponibles para reproduccion:"<<endl;
                playlist->graficarListaPlaylist();

                cout<<"Seleccione una lista para reproducir"<<endl;
                cin>>opcionReproduccion;

                playlist->reproduccionNormal(opcionReproduccion);
            }
        break;

        case 2:
            salir=false;
            if(playlist->isVacia()){
                system("clear");
                cout<<"Debe crear al menos una lista para poder reproducirla, puede crearla en la opcion 2 del menu principal"<<endl;
                system("read -p 'Presione enter para continuar...' var");
            } else {
                system("clear");
                cout<<"Listas disponibles para reproduccion:"<<endl;
                playlist->graficarListaPlaylist();

                cout<<"Seleccione una lista para reproducir"<<endl;
                cin>>opcionReproduccionRep;

                playlist->reproduccionRepeticion(opcionReproduccionRep);
            }
        break;

        case 3:
            system("clear");
            salir=true;
            cout<<"Saliendo"<<endl;
            system("read -p 'Presione enter para continuar...' var");
        break;

        default:
            system("clear");
            salir=false;
            cout<<"Opcion incorrecta"<<endl;
            system("read -p 'Presione enter para continuar...' var");
        break;
    }
}

ListaPlaylist* menuPlaylist(ListaCanciones* store,ListaPlaylist* playlist){
    int opcion=0;
    bool salir=0;
    string nombrePlaylist;
    string descripcionPlaylist;
    int idPlaylist=0;
    int idPlaylist2=0;
    int idPlaylist3=0;
    int idCancion=0;
    int idCancionIngreso=0;
    ListaCanciones* listaNueva;
    NodoPlaylist* nodoNuevo;
    Cancion* cancion;
    string resultado;
    Cancion* pivote;

    while(salir==false){
        system("clear");
        cout<<"Menu Playlist Personalizadas"<<endl;
        cout<<"__________________"<<endl;
        cout<<"1) Crear Playlist"<<endl;
        cout<<"2) Elminar Playlist"<<endl;
        cout<<"3) Actualizar Playlist"<<endl;
        cout<<"4) Mostrar Listado de Playlist"<<endl;
        cout<<"5) Agregar canciones a playlist especifica"<<endl;
        cout<<"6) Eliminar canciones de playlist especifica"<<endl;
        cout<<"7) Salir"<<endl;
        cin>>opcion;
        cin.ignore();
        switch(opcion){
            case 1:
                salir=false;
                system("clear");
                cout<<"Ingresa el nombre de la Playlist"<<endl;
                getline(cin, nombrePlaylist);
                cout<<"Ingresa la descripcion de la Playlist"<<endl;
                getline(cin, descripcionPlaylist);

                listaNueva = new ListaCanciones(nombrePlaylist, descripcionPlaylist);
                nodoNuevo = new NodoPlaylist(listaNueva, NULL);
                playlist->insertarListaPlaylist(nodoNuevo);

            break;

            case 2:
                salir=false;
                if(playlist->isVacia()){
                    system("clear");
                    cout<<"Lista Vacia"<<endl;
                }
                else {
                    system("clear");
                    playlist->graficarListaPlaylist();

                    cout<<"Ingresa el id de la playlist a eliminar"<<endl;
                    cin>>idPlaylist;

                    playlist->eliminarListaPorIndice(idPlaylist);
                }   
            break;

            case 3:
                salir=false;
                if(playlist->isVacia()){
                    system("clear");
                    cout<<"Lista Vacia"<<endl;
                } else {
                    system("clear");
                    playlist->graficarListaPlaylist();

                    cout<<"Ingresa el id de la playlist a modificar"<<endl;
                    cin>>idPlaylist;

                    playlist->actualizarDatosListaPorIndice(idPlaylist);
                }
            break;

            case 4:
                salir=false;
                if(playlist->isVacia()){
                    system("clear");
                    cout<<"Lista Vacia"<<endl;
                    system("read -p 'Presione enter para continuar...' var");
                } else {
                    system("clear");
                    playlist->graficarListaPlaylist();
                    system("read -p 'Presione enter para continuar...' var");
                }
            break;

            case 5:
                salir=false;
                if(playlist->isVacia()){
                    system("clear");
                    cout<<"Lista Vacia"<<endl;
                } else {
                    system("clear");
                    playlist->graficarListaPlaylist();
                    cout<<"Ingresa el id de la playlist donde deseas agregar la cancion"<<endl;
                    cin>>idPlaylist2;

                    cout<<"Canciones en store: "<<endl;
                    cout<<"_____________________________"<<endl;
                    store->imprimirLista();

                    cout<<"Ingrese el indice de la cancion que desea agregar"<<endl;
                    cin>>idCancionIngreso;

                    pivote = store->obtenerCancion(idCancionIngreso);

                    playlist->ingresarCancion(pivote, idPlaylist2);
                }
            break;

            case 6:
                salir=false;
                if(playlist->isVacia()){
                    system("clear");
                    cout<<"Lista Vacia"<<endl;
                } else {
                    system("clear");
                    playlist->graficarListaPlaylist();
                    cout<<"Ingresa el id de la playlist donde deseas eliminar la cancion"<<endl;
                    cin>>idPlaylist3;

                    playlist->imprimirListaEspecifica(idPlaylist3);

                    cout<<"Ingrese el id de la cancion"<<endl;
                    cin>>idCancion;

                    playlist->eliminarCancion(idCancion, idPlaylist3);
                }
            break;

            case 7:
                system("clear");
                salir=true;
                cout<<"Saliendo"<<endl;
                system("read -p 'Presione enter para continuar...' var");
            break;

            default:
                system("clear");
                salir=false;
                cout<<"Opcion incorrecta"<<endl;
                system("read -p 'Presione enter para continuar...' var");
            break;
        }
    }  

    return playlist;
}

ListaCanciones* menuStore(ListaCanciones* listaCanciones){
    int opcion=0;
    bool salir=false;
    string nombre;
    string path;
    int opcion2=0;
    int idEliminacion=0;
    string nombreEliminacion;
    string nombreBusqueda;
    Cancion* cancion;
    string resultado;
    string nombreRaiz;

    while(salir==false){
        system("clear");
        cout<<"Menu Store"<<endl;
        cout<<"__________________"<<endl;
        cout<<"1) Insertar Cancion"<<endl;
        cout<<"2) Eliminar Cancion"<<endl;
        cout<<"3) Buscar cancion"<<endl;
        cout<<"4) Listar Canciones"<<endl;
        cout<<"5) Salir"<<endl;
        cin>>opcion;
        cin.ignore();
        switch(opcion){
            case 1:
                system("clear");
                cout<<"Ingrese el nombre de la cancion, recuerde ingresar la extension .mp3"<<endl;
                getline(cin, nombre);
                resultado = revisarEspacioEnBlanco(nombre);
                cout<<"Ingrese el path de la cancion, recuerde que debe de ser asi: /home/diego/Escritorio/LabEDD/Proyecto1/Music/"<<endl;
                getline(cin, path);
                cancion = new Cancion(resultado, path);
                listaCanciones->insertarCancion(cancion);
                salir=false;
            break;

            case 2:
                system("clear");
                cout<<"1) Eliminar por id"<<endl;
                cout<<"2) Eliminar por nombre"<<endl;
                cout<<"Ingrese una opcion"<<endl;
                cin>>opcion2;
                cin.ignore();
                switch (opcion2){
                    case 1:
                        system("clear");
                        listaCanciones->imprimirLista();

                        cout<<"Ingrese el id de la cancion que desea eliminar"<<endl;
                        cin>>idEliminacion;

                        listaCanciones->eliminarElementoPorId(idEliminacion);

                        break;

                    case 2:
                        system("clear");
                        listaCanciones->imprimirLista();

                        cout<<"Ingrese el nombre de la cancion que desea eliminar"<<endl;
                        getline(cin, nombreEliminacion);

                        listaCanciones->eliminarElementoPorNombre(nombreEliminacion);

                        break;
                    
                    default:
                        cout<<"Opcion incorrecta"<<endl;
                        system("read -p 'Presione enter para continuar...' var");
                        break;
                }
                salir=false;
            break;

            case 3:
                system("clear");
                cout<<"Ingrese el nombre de la cancion que desea buscar"<<endl;
                getline(cin, nombreBusqueda);

                listaCanciones->buscarElemento(nombreBusqueda);
                salir=false;
            break;

            case 4:
                salir=false;
                system("clear");
                listaCanciones->imprimirLista();
                system("read -p 'Presione enter para continuar...' var");
            break;

            case 5:
                salir=true;
                cout<<"Saliendo..."<<endl;
                system("read -p 'Presione enter para continuar...' var");
            break;

            default:
                salir=false;
                cout<<"Opcion incorrecta"<<endl;
                system("read -p 'Presione enter para continuar...' var");
            break;
        }
    }

    return listaCanciones;
}

void bienvenida(){
    system("clear");
    cout<<"Bienvenido!"<<endl;
    cout<<"Proyecto 1 - Spotify por consola"<<endl;
    cout<<"Diego José Maldonado Monterroso - 201931811"<<endl;
    system("read -p 'Presione enter para continuar...' var");
}

void menu(){
    int opcion=0;
    bool salir=false;
    int op=0;
    int opA=0;
    string pathArchivo;
    string nombreRaiz;
    XMLDocument doc;
    XMLElement* raiz;

    ListaCanciones* store = new ListaCanciones("Spotify Store", "Tienda de canciones, que contiene todas las canciones disponibles para escuchar");
    ListaPlaylist* playlist;

    XMLReader* reader = new XMLReader();

    bienvenida();

    while(salir==false){
        system("clear");
        cout<<"Menu de Spotify C++"<<endl;
        cout<<"____________________________"<<endl;
        cout<<"1) Store"<<endl;
        cout<<"2) Playlist Personalizadas"<<endl;
        cout<<"3) Carga Masiva de datos"<<endl;
        cout<<"4) Reproduccion"<<endl;
        cout<<"5) Visualizar Listas"<<endl;
        cout<<"6) Salir"<<endl;
        cout<<"Ingrese una opcion valida..."<<endl;
        cin>>opcion;
        cin.ignore();
        switch(opcion){
            case 1:
                system("clear");
                salir=false;
                store = menuStore(store);
            break;

            case 2:
                system("clear");
                playlist = menuPlaylist(store, playlist);
                salir=false;
            break;

            case 3:
                salir=false;
                system("clear");
                cout<<"Desea cargar datos?"<<endl;
                cout<<"1) SI"<<endl;
                cout<<"2) NO"<<endl;
                cout<<"3) De archivo XML"<<endl;
                cout<<"Ingrese una opcion valida..."<<endl;
                cin>>op;
                if(op==1){
                    system("clear");
                    store= crearStore();
                    system("read -p 'Presione enter para continuar...' var");
                    system("clear");
                    playlist = añadirListas();
                    system("read -p 'Presione enter para continuar...' var");
                    system("clear");
                    playlist = crearListaPlaylist(store, playlist);
                    system("read -p 'Presione enter para continuar...' var");
                    system("clear");
                } else if(op==2){
                    system("clear");
                    cout<<"Saliendo..."<<endl;
                    system("read -p 'Presione enter para continuar...' var");
                } else if(op==3){
                    system("clear");
                    cout<<"Ingrese el path de su archivo junto con su nombre: "<<endl;
                    getline(cin, pathArchivo);
                    doc.LoadFile(pathArchivo.c_str());
                    raiz = doc.FirstChildElement();
                    nombreRaiz = raiz->Name();
                    while (raiz != nullptr) {
                        if (nombreRaiz == "Eliminar" &&  raiz->FirstChildElement("cancion")!= nullptr){
                            store = reader->eliminarCancionStoreXML(raiz, store);
                        } else if(nombreRaiz =="Eliminar" &&  raiz->FirstChildElement("Lista")!= nullptr){
                            playlist = reader->eliminarListaXML(raiz, playlist);
                        } else if(nombreRaiz == "Insertar" &&  raiz->FirstChildElement("cancion")!= nullptr){
                            store = reader->storeXML(raiz, store);
                        } else if(nombreRaiz == "Insertar" &&  raiz->FirstChildElement("Lista")!= nullptr){
                            playlist = reader->listaXML(raiz, playlist, store);
                        }
                    }
                } else {
                    system("clear");
                    cout<<"Opcion Invalida..."<<endl;
                    cout<<"Saliendo..."<<endl;
                    system("read -p 'Presione enter para continuar...' var");
                }
            break;

            case 4:
                menuReproduccion(playlist);
            break;

            case 5:
                salir=false;
                system("clear");
                cout<<"1)Store"<<endl;
                cout<<"2)Listas Playlist"<<endl;
                cout<<"Ingrese una opcion valida..."<<endl;
                cin>>opA;
                if(opA==1){
                    if(store->isVacia()){
                        system("clear");
                        cout<<"Lista Vacia"<<endl;
                    } else {
                        system("clear");
                        store->imprimirLista();
                        system("read -p 'Presione enter para continuar...' var");
                    }
                } else if(opA==2){
                    if(playlist->isVacia()){
                        system("clear");
                        cout<<"Lista Vacia"<<endl;
                    } else {
                        system("clear");
                        playlist->graficarListaPlaylist();
                        system("read -p 'Presione enter para continuar...' var");
                    }
                } else {
                    system("clear");
                    cout<<"Opcion invalida..."<<endl;
                    system("read -p 'Presione enter para continuar...' var");
                }  
            break;

            case 6:
                system("clear");
                salir=true;
                cout<<"Saliendo..."<<endl;
                system("read -p 'Presione enter para continuar...' var");
            break;

            default:
                system("clear");
                salir=false;
                cout<<"Opcion incorrecta"<<endl;
                system("read -p 'Presione enter para continuar...' var");
            break;
        }
    }
}

int main(){
    menu();
    return 0;
}