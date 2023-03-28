#include <iostream>
#include <string>

using namespace std;

class Cancion{
    private:
        string path;
        string nombre;

    public:
        Cancion(string nombre, string path);

        ~Cancion();

        string getPath();

        void setPath(string path);

        string getNombre();

        void setNombre(string nombre);
};