#include "ListaCanciones.hpp"

int ListaCanciones::numeroElementos = 0;

ListaCanciones::ListaCanciones()
{

}

ListaCanciones::ListaCanciones(string nombre, string descripcion)
{
    this->cabeza = NULL;
    this->nombre = nombre;
    this->descripcion = descripcion;
}

ListaCanciones::~ListaCanciones()
{
    cout << "Eliminando Lista " << this->getNombre() << endl;
}

void ListaCanciones::insertarCancion(Cancion *cancion)
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

void ListaCanciones::graficarLista()
{
    cout << "Lista: " << this->getNombre() << endl;
    cout << "Descripcion: " << this->getDescripcion() << endl;
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

void ListaCanciones::eliminarCancionPorNombre(string nombre)
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

void ListaCanciones::eliminarCancionPorIndice(int indice)
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
                cout << "Cancion no existe dentro de la lista" << endl;
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

bool ListaCanciones::isVacia()
{
    if (this->cabeza == NULL)
    {
        return true;
    }
    return false;
}

void ListaCanciones::arreglarIndices()
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

void ListaCanciones::buscarCancionPorNombre(string nombre)
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

void ListaCanciones::buscarCancionPorIndice(int indice)
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

Nodo *ListaCanciones::obtenerNodo(int indice)
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


