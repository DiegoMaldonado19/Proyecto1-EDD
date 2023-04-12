#include "tinyxml2.h"
#include "ListaPlaylist.hpp"

class XMLReader{
    public: 

        XMLReader();

        ~XMLReader();

        ListaCanciones* storeXML(XMLElement* raiz, ListaCanciones* store);

        ListaPlaylist* listaXML(XMLElement* raiz, ListaPlaylist* playlist, ListaCanciones* store);

        ListaCanciones* eliminarCancionStoreXML(XMLElement* raiz, ListaCanciones* store);

        ListaPlaylist* eliminarListaXML(XMLElement* raiz, ListaPlaylist* playlist);
};