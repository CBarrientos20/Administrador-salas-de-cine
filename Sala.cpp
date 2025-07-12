#include <iostream>
#include "Sala.h"
#include "Constante.h"
#include <cstring>
#include "ArchivoSala.h"

using namespace std;

Sala::Sala() {}

Sala::Sala(int numero,string nombre,string tipo,bool estadoSala,Fecha fechaAsignada)
{
    setnumero(numero);
    setnombre(nombre);
    settipo(tipo);
    setEstado(estadoSala);
    setButacas();
    setFechaAsignada(fechaAsignada);
}

bool Sala::cargarSala(){
    int contadorDeErrores=0;
    bool esDatoValido;
    int numeroSala;
    Fecha fechaAsignada;
    string nombreSala;
    string tipo;
    int estado;
    Sala reg;

    ArchivoSala archivoSala;

/// COMO SOLO DAMOS BAJAS DE MANTENIMIENTO LOGICAS Y NO ELIMINAMOS NADA
    numeroSala=archivoSala.getCantidadSalas()+1;/// se retorna 0 si no puede leer el archivo
    reg.setnumero(numeroSala);

/// no secesita el contador para entrar ya q en esta clase es el primer dato a cargar
    if(fechaAsignada.cargarFecha())
    {
        setFechaAsignada(fechaAsignada);
    }
    else
    {
        contadorDeErrores=3;/// ya que no se cargo una fecha valida
    }

    while(contadorDeErrores<3)
    {
        cout<< "Ingrese el nombre de la Sala: "<<endl;
        cin.ignore();
        getline(cin,nombreSala);
        esDatoValido=nombreSala.length() > 0 && nombreSala.length() < TAMANIOCHARMEDIO;/// falta crear la funcion que traiga salas por fecha para poder validar que no se creen 2 salas con el mismo nombre el mismo dia
        if(esDatoValido)
        {
            setnombre(nombreSala);
            contadorDeErrores=0;
            break;
        }else{
            cout<< "NO ES UN NOMBRE VALIDO EL QUE DESEA INGRESAR"<<endl;
            contadorDeErrores++;
        }
    }

    while(contadorDeErrores<3)
    {
        int tipoElegido;
        cout<< "Ingrese el tipo de Sala(1:estandar,2:premium,3:confort plus): "<<endl;
        cin>> tipoElegido;
        cin.ignore();/// falta la funcion de  ingresar un numero seguro
        switch(tipoElegido)
        {
        case 1:
            tipo="estandar";
            esDatoValido=true;
            break;
        case 2:
            tipo="premium";
            esDatoValido=true;
            break;
        case 3:
            tipo="confort plus";
            esDatoValido=true;
            break;
        default:
            cout<< "ERROR EN LA CARGA DEL TIPO DE LA SALA" <<endl;
            esDatoValido=false;
            contadorDeErrores++;
        }
        if(esDatoValido)
        {
            settipo(tipo);
            contadorDeErrores=0;
            break;
        }
    }

    while(contadorDeErrores<3)
    {
        cout<< "Ingrese estado de la sala : (si no esta diponible 0, si esta disponible 1)"<<endl;
        cin>> estado;
         cin.ignore();/// falta la funcion de  ingresar un numero seguro
        esDatoValido=estado==1||estado==0;
        if(esDatoValido)
        {
            reg.setEstado(estado);
            contadorDeErrores=0;
            break;
        }
        else
        {
            cout<<"Error con la carga del estado de la sala"<<endl;
            contadorDeErrores++;
        }
    }

    ///por defecto cuando creamos una sala todas las butacas las seteamos a false
    reg.setButacas();

    cout <<"_________________________" << endl;
    cout << endl;
    return contadorDeErrores<3;
}
void Sala::mostrarSala(){
    cout<< "SALA #: "<<getnumero()<<endl;
    cout<< "EL NOMBRE DE LA SALA ES: "<< getnombre()<<endl;
    cout<< "LA SALA ES :"<< gettipo()<<endl;
    getFechaAsignada().mostrarFecha();
    if(getEstadoSala())cout<< "LA SALA ESTA ACTIVA"<<endl;
    if(!getEstadoSala())cout<< "LA SALA ESTA EN MANTENIMIENTO"<<endl;

    for(int i=0; i<FILAS; i++)
    {
        cout<<"FILA: "<<i+1<<" :";
        for(int j=0; j<COLUMNAS; j++)
        {
            if(!getButaca(i,j))
            {
                cout<< "L ";
            }
            else
            {
                cout<< "O ";
            }
        }
        cout<<endl;
    }
    cout<< "---------------------------"<<endl;
}

void Sala::mostrarSalaNumeroNombreYFecha(){
    cout<< "SALA #: "<<getnumero()<<endl;
    cout<< "EL NOMBRE DE LA SALA ES: "<< getnombre()<<endl;
    getFechaAsignada().mostrarFecha();
}
void Sala::mostrarSalaNumeroEstadoYFecha(){
    cout<< "SALA #: "<<getnumero()<<endl;
    if(getEstadoSala())cout<< "LA SALA ESTA ACTIVA"<<endl;
    if(!getEstadoSala())cout<< "LA SALA ESTA EN MANTENIMIENTO"<<endl;
    getFechaAsignada().mostrarFecha();
}

int Sala::getnumero()
{
    return _numero;
}

string Sala::getnombre()
{
    return _nombre;
}

string Sala::gettipo()
{
    return _tipo;
}

bool Sala::getEstadoSala()
{
    return _estadoSala;
}


bool Sala::getButaca(int fila,int columna)
{
    return _butacas[fila][columna];
}

Fecha Sala::getFechaAsignada()
{
    return _fechaAsignada;
}


void Sala::setButacas()
{
    for(int i=0; i<FILAS; i++)
    {
        for(int j=0; j<COLUMNAS; j++)
        {
            _butacas[i][j]=false;
        }
    }
}

void Sala::setButaca(int fila,int columna,bool estado)
{
    _butacas[fila][columna]=estado;
}

void Sala::setnumero(int numero)
{
    _numero=numero;
}

void Sala::setnombre(string nombre)
{
    strcpy(_nombre,nombre.c_str());
}

void Sala::settipo(string tipo)
{
    strcpy(_tipo,tipo.c_str());
}

void Sala::setEstado(bool estadoSala)
{
    _estadoSala=estadoSala;
}
void Sala::setFechaAsignada(Fecha fechaAsignada)
{
    _fechaAsignada=fechaAsignada;
}










