#include "ListaEnlazada.hpp"

int ListaEnlazada::numeroElementos = 0;

ListaEnlazada::ListaEnlazada(string nombre, string descripcion)
{
    this->cabeza = NULL;
    this->nombre = nombre;
    this->descripcion = descripcion;
}

ListaEnlazada::~ListaEnlazada()
{
    cout << "Eliminando Lista " << this->nombre << endl;
}

void ListaEnlazada::insertarCancion(Cancion *cancion)
{
    Nodo *nuevo = new Nodo(cancion, NULL);
    if (this->isVacia())
    {
        this->cabeza = nuevo;
        numeroElementos++;
        this->cabeza->setIndice(numeroElementos);
    }
    else
    {
        Nodo *actual = this->cabeza;
        while (actual->getSiguiente() != NULL)
        {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
        numeroElementos++;
        nuevo->setIndice(numeroElementos);
    }
}

void ListaEnlazada::graficarLista()
{
    cout << "Lista: " << this->nombre << endl;
    cout << "Descripcion: " << this->descripcion << endl;
    Nodo *actual = this->cabeza;
    while (actual->getSiguiente() != NULL)
    {
        cout << "Indice: " << actual->getIndice();
        cout << " Cancion: " << actual->getCancion()->getNombre();
        cout << " Path: " << actual->getCancion()->getPath() << endl;

        actual = actual->getSiguiente();
    }
    cout << "Indice: " << actual->getIndice();
    cout << " Cancion: " << actual->getCancion()->getNombre();
    cout << " Path: " << actual->getCancion()->getPath() << endl;
}

void ListaEnlazada::eliminarCancionPorNombre(string nombre)
{
    if (this->isVacia())
    {
        cout << "Lista vacia" << endl;
    }
    else
    {
        if (this->cabeza->getCancion()->getNombre() == nombre)
        {
            this->cabeza = this->cabeza->getSiguiente();
            numeroElementos--;
            this->arreglarIndices();
        }
        else
        {
            Nodo *actual = this->cabeza;
            while (actual->getSiguiente() != NULL && actual->getSiguiente()->getCancion()->getNombre() != nombre)
            {
                actual = actual->getSiguiente();
            }
            if (actual->getSiguiente() == NULL)
            {
                cout << "Cancion: " << nombre << " no existe dentro de la lista" << endl;
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

void ListaEnlazada::eliminarCancionPorIndice(int indice)
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
            Nodo *actual = this->cabeza;
            while (actual->getSiguiente() != NULL && actual->getSiguiente()->getIndice() != indice)
            {
                actual = actual->getSiguiente();
            }
            if (actual->getSiguiente() == NULL)
            {
                cout << "Cancion: " << nombre << " no existe dentro de la lista" << endl;
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

bool ListaEnlazada::isVacia()
{
    if (this->cabeza == NULL)
    {
        return true;
    }
    return false;
}

void ListaEnlazada::arreglarIndices()
{
    Nodo *actual = this->cabeza;
    int iterador = 1;
    while (actual != NULL)
    {
        actual->setIndice(iterador);
        actual = actual->getSiguiente();
        iterador++;
    }
}

void ListaEnlazada::buscarCancionPorNombre(string nombre)
{
    Nodo *actual = this->cabeza;
    while (actual != NULL)
    {
        if (actual->getCancion()->getNombre() == nombre)
        {
            cout << "Nodo encontrado: " << endl;
            cout << "Indice: " << actual->getIndice();
            cout << " Cancion: " << actual->getCancion()->getNombre();
            cout << " Path: " << actual->getCancion()->getPath() << endl;
            break;
        }
        actual = actual->getSiguiente();
    }
}

void ListaEnlazada::buscarCancionPorIndice(int indice)
{
    Nodo *actual = this->cabeza;
    while (actual != NULL)
    {
        if (actual->getIndice() == indice)
        {
            cout << "Nodo encontrado: " << endl;
            cout << "Indice: " << actual->getIndice();
            cout << " Cancion: " << actual->getCancion()->getNombre();
            cout << " Path: " << actual->getCancion()->getPath() << endl;
            break;
        }
        actual = actual->getSiguiente();
    }
}

Nodo *ListaEnlazada::obtenerNodo(int indice)
{
    Nodo *actual = this->cabeza;
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
