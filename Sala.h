#ifndef SALA_H_INCLUDED
#define SALA_H_INCLUDED
#include "Constante.h"
#include "Fecha.h"
#include <string>

using namespace std;

class Sala{

public:
    Sala();
    Sala(int numero,string nombre,string tipo,bool estadoSala,Fecha fechaAsignada);

    bool cargarSala();
    void mostrarSala();
    void mostrarSalaNumeroNombreYFecha();
    void mostrarSalaNumeroEstadoYFecha();

    int getnumero();
    string getnombre();
    string gettipo();
    bool getEstadoSala();
    bool getButaca(int fila, int columna);
    Fecha getFechaAsignada();

    void setButacas();
    void setButaca(int fila,int columna,bool estado);
    void setnumero(int numero);
    void setnombre(string nombre);
    void settipo(string tipo);
    void setEstado(bool estadoSala);
    void setFechaAsignada(Fecha fechaAsignada);

private:
    int _numero;
    char _nombre[TAMANIOCHARMEDIO];
    char _tipo[TAMANIOCHARMEDIO];
    bool _butacas[FILAS][COLUMNAS];
    bool _estadoSala;
    Fecha _fechaAsignada;

};








#endif // SALA_H_INCLUDED
