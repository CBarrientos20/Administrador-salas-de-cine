#ifndef ARCHIVOCLIENTES_H_INCLUDED
#define ARCHIVOCLIENTES_H_INCLUDED
#include "Clientes.h"
#include <string>

class ArchivoClientes{
public:
ArchivoClientes(string nombreArchivo="clientes.dat");
bool guardarCliente(Clientes reg);
bool guardarClientes(Clientes reg[], int cantidad);
int getCantidadClientes();
bool leerTodo(Clientes reg[], int cantidad);
bool bajaLogicaCliente(Clientes reg, int posicion);
bool altaLogicaCliente(Clientes reg, int posicion);

private:
    string _nombreclienteArchivo;

};


#endif // ARCHIVOCLIENTES_H_INCLUDED
