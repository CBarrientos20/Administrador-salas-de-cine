#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "Constante.h"
#include <iostream>
#include "Fecha.h"
using namespace std;
class Clientes{

public:
    Clientes();
    Clientes(string nombreCliente, string apellidoCliente, string emailCliente, int dniCliente, int telefonoCliente, Fecha fechaDeNacimientoCliente, bool estado);
    void pasarAMinusculas(string &cadena);

    bool cargarCliente();
    void mostrarCliente();
    bool validarEmail(const string& email);


    bool setNombreCliente(string nombreCliente);
    bool setApellidoCliente(string apellidoCliente);
    bool setEmailCliente(string emailCliente);
    bool setDniCliente(int dniCliente);
    bool setTelefonoCliente(int telefonoCliente);
    void setEstado(bool estado);
    void setFechaNacimiento(Fecha fechaDeNacimiento);

    string getNombreCliente();
    string getApellidoCliente();
    string getEmailCliente();
    int getDniCliente();
    int getTelefonoCliente();
    bool getEstado();
    Fecha getFechaDeNacimiento();

private:
    char _nombreCliente[TAMANIOCHARMEDIO];
    char _apellidoCliente[TAMANIOCHARMEDIO];
    char _emailCliente[TAMANIOCHARMEDIO];
    int _dniCliente;
    int _telefonoCliente;
    Fecha _fechaDeNacimientoCliente;
    bool _estado;
};

#endif // CLIENTES_H_INCLUDED
