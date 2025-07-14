#include <iostream>
using namespace std;
#include "ArchivoClientes.h"

ArchivoClientes::ArchivoClientes(string nombreArchivo)
{
    _nombreclienteArchivo=nombreArchivo;
}

bool ArchivoClientes::guardarCliente(Clientes reg)
{
    FILE *pFile;
    bool guardado;
    pFile=fopen(_nombreclienteArchivo.c_str(), "ab");
    if(pFile==nullptr)
    {
        return false;
    }
    guardado=fwrite(&reg, sizeof(Clientes),1, pFile);
    fclose(pFile);
    return guardado;
}
///respaldo de clientes
bool ArchivoClientes::guardarClientes(Clientes reg[], int cantidad)
{
    FILE *pFile;
    bool registroCliente;
    pFile=fopen(_nombreclienteArchivo.c_str(), "wb");
    if(pFile==nullptr)
    {
        return false;
    }
    registroCliente=fwrite(reg, sizeof(Clientes), cantidad, pFile);
    fclose(pFile);
    return registroCliente;
}
int ArchivoClientes::getCantidadClientes()
{
    int cantidad;
    FILE *pFile;
    pFile=fopen(_nombreclienteArchivo.c_str(), "rb");
    if(pFile==nullptr)
    {
        return -1;
    }
    fseek(pFile,0,SEEK_END);
    cantidad=ftell(pFile)/sizeof(Clientes);
    fclose(pFile);
    return cantidad;
}

bool ArchivoClientes::leerTodo(Clientes reg[], int cantidad)
{
    FILE *pFile;
    bool leido;
    pFile=fopen(_nombreclienteArchivo.c_str(),"rb");
    if(pFile==nullptr)
    {
        return false;
    }
    leido=fread(reg, sizeof(Clientes),cantidad,pFile);
    fclose(pFile);
    return leido;
}

bool ArchivoClientes::bajaLogicaCliente(Clientes reg, int posicion)
{
    FILE *pFile;
    bool escrito;
    pFile=fopen(_nombreclienteArchivo.c_str(), "rb+");
    if(pFile==nullptr)
    {
        return false;
    }
    fseek(pFile, posicion* sizeof(Clientes), SEEK_SET);
    fread(&reg, sizeof(Clientes), 1, pFile);
    if(reg.getEstado())
    {
        reg.setEstado(false);
        fseek(pFile, posicion* sizeof(Clientes), SEEK_SET);
        escrito=fwrite(&reg,sizeof(Clientes),1, pFile);
    }
    else
    {
        escrito=false;
    }
    fclose(pFile);
    return escrito;
}
bool ArchivoClientes::altaLogicaCliente(Clientes reg, int posicion){
FILE *pFile;
bool escrito;
pFile=fopen(_nombreclienteArchivo.c_str(), "rb+");
if(pFile==nullptr){
    return false;
}
fseek(pFile, posicion *sizeof(Clientes), SEEK_SET);
fread(&reg, sizeof(Clientes),1, pFile);
if(!reg.getEstado()){
    reg.setEstado(true);
    fseek(pFile, posicion* sizeof(Clientes), SEEK_SET);
    escrito=fwrite(&reg, sizeof(Clientes), 1,pFile);
}else{
escrito=false;
}
fclose(pFile);
return escrito;

}
