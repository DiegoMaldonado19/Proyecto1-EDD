# Reproductor de Música - Spotify en Consola

_Proyecto 1, donde se desarrolla una aplicacion en consola usando c++._

_Se utilizó POO para la construccion de nuestras clases y listas._

_Se aplicaron diferentes tipos de estructuras de datos:_

* _Lista Simplemente Enlazada._
* _Lista Doblemente Enlazada._
* _Lista Doblemente Enlazada Circular._
* _Pila._

_En un principio se buscaba la lectura de un archivo XML, ya no me dio tiempo, pero el programa tiene implementada una carga local de datos para poder simular la carga masiva de datos._

_Para la reproducción de música se utilizó el reproducctor mpg123, con el cual se pueden reproduccir canciones desde consola._

_Pueden agregar canciones usando las canciones dentro de la carpeta Music._
_Bajo este path: /home/diego/Escritorio/LabEDD/Proyecto1/Music/_
_De cualquier manera, si usted tuviera una cancion ubicada dentro de su sistema la puede abrir, solamente debe recordar de agregar la contradiagonal '/' como ultimo elemento de su path, como se muestra en el path de ejemplo._

_Hecho puramente con c++._

_Comando para compilar con gcc:_
_gcc Main.cpp ListaPlaylist.cpp ListaPlaylist.hpp NodoPlaylist.cpp NodoPlaylist.hpp ListaCanciones.cpp ListaCanciones.hpp Nodo.cpp Nodo.hpp Cancion.cpp Cancion.hpp Pila.cpp Pila.hpp -lstdc++ -g -o salida_

_Comando para ejecutar el programa: ./salida_

## Autor ✒️

* **Diego José Maldonado Monterroso - 201931811 - Estudiante de Ingeniería**
* **11 de abril de 2023.** 
* **Quetzaltenango, Guatemala.** 