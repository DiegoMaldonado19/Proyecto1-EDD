#include "ListaPlaylist.hpp"

int ListaPlaylist::numeroElementos = 0;

ListaPlaylist::ListaPlaylist()
{
    this->cabeza = NULL;
}

ListaPlaylist::~ListaPlaylist()
{
    cout << "Eliminando Playlist " << endl;
}

void ListaPlaylist::insertarListaPlaylist(NodoPlaylist *nuevo)
{
    if (this->isVacia())
    {
        this->cabeza = nuevo;
        numeroElementos++;
        this->cabeza->setIndice(numeroElementos);
    }
    else
    {
        NodoPlaylist *actual = this->cabeza;
        while (actual->getSiguiente() != NULL)
        {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
        numeroElementos++;
        nuevo->setIndice(numeroElementos);
    }
}

void ListaPlaylist::graficarListaPlaylist()
{
    NodoPlaylist *actual = this->cabeza;
    while (actual->getSiguiente() != NULL)
    {
        cout << "Indice: " << actual->getIndice();
        cout << " Lista: " << actual->getLista()->getNombre();
        cout << " Descripcion: " << actual->getLista()->getDescripcion() << endl;

        actual = actual->getSiguiente();
    }
    cout << "Indice: " << actual->getIndice();
    cout << " Lista: " << actual->getLista()->getNombre();
    cout << " Descripcion: " << actual->getLista()->getDescripcion() << endl;
}

void ListaPlaylist::eliminarListaPorIndice(int indice)
{
    if (this->isVacia())
    {
        cout << "Lista vacia" << endl;
    }
    else
    {
        if (this->cabeza->getIndice() == indice)
        {
            this->cabeza = this->cabeza->getSiguiente();
            numeroElementos--;
            this->arreglarIndices();
        }
        else
        {
            NodoPlaylist *actual = this->cabeza;
            while (actual->getSiguiente() != NULL && actual->getSiguiente()->getIndice() != indice)
            {
                actual = actual->getSiguiente();
            }
            if (actual->getSiguiente() == NULL)
            {
                cout << "Lista no existe dentro de la lista" << endl;
            }
            else
            {
                actual->setSiguiente(actual->getSiguiente()->getSiguiente());
                numeroElementos--;
            }
            this->arreglarIndices();
        }
    }
}

bool ListaPlaylist::isVacia()
{
    if (this->cabeza == NULL)
    {
        return true;
    }
    return false;
}

void ListaPlaylist::arreglarIndices()
{
    NodoPlaylist *actual = this->cabeza;
    int iterador = 1;
    while (actual != NULL)
    {
        actual->setIndice(iterador);
        actual = actual->getSiguiente();
        iterador++;
    }
}

void ListaPlaylist::actualizarDatosListaPorIndice(int indice)
{
    NodoPlaylist *actual = this->cabeza;
    string nombre;
    string descripcion;

    cout<< "Ingrese el nuevo nombre: "<<endl;
    cin>> nombre;
    cout<< "Ingrese la nueva descripcion: "<<endl;
    cin>> descripcion;

    while (actual != NULL)
    {
        if (actual->getIndice() == indice)
        {
            actual->getLista()->setNombre(nombre);
            actual->getLista()->setDescripcion(descripcion);
            break;
        }
        actual = actual->getSiguiente();
    }
}

NodoPlaylist *ListaPlaylist::obtenerNodoPlaylist(int indice)
{
    NodoPlaylist *actual = this->cabeza;
    if (this->cabeza == NULL)
    {
        cout << "Lista Vacia" << endl;
    }
    else
    {
        while (actual != NULL)
        {
            if (actual->getIndice() == indice)
            {
                break;
            }
            actual = actual->getSiguiente();
        }
    }
    if (actual == NULL)
    {
        cout << "Nodo no encontrado" << endl;
        return NULL;
    }

    return actual;
}