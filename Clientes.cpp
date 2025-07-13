#include <iostream>
#include "Clientes.h"
#include "Fecha.h"
#include<cstring>
#include "Constante.h"
#include "ArchivoClientes.h"

Clientes::Clientes()
{
    strcpy(_nombreCliente,"");
    strcpy(_apellidoCliente,"");
    strcpy(_emailCliente, "");
    _dniCliente=1000000;
    _telefonoCliente=0;
    _fechaDeNacimientoCliente=Fecha(); ///<----i'm not sure about this
    _estado=true;


}
Clientes::Clientes(string nombreCliente, string apellidoCliente, string emailCliente, int dniCliente, int telefonoCliente, Fecha fechaDeNacimientoCliente, bool estado)
{
    setNombreCliente(nombreCliente);
    setApellidoCliente(apellidoCliente);
    setEmailCliente(emailCliente);
    setDniCliente(dniCliente);
    setTelefonoCliente(telefonoCliente);
    setFechaNacimiento(fechaDeNacimientoCliente);
    setEstado(estado);

}


///getters

string Clientes::getNombreCliente()
{
    return _nombreCliente;
}
string Clientes::getApellidoCliente()
{
    return _apellidoCliente;
}
string Clientes::getEmailCliente()
{
    return _emailCliente;
}

int Clientes::getDniCliente()
{
    return _dniCliente;
}
int Clientes::getTelefonoCliente()
{
    return _telefonoCliente;
}
Fecha Clientes::getFechaDeNacimiento()
{
    return _fechaDeNacimientoCliente;
}
bool Clientes::getEstado()
{
    return _estado;
}

///setters
bool Clientes::setNombreCliente(string nombreCliente)
{
    if(nombreCliente.size()>TAMANIOCHARMEDIO)
    {
        cout<<"El nombre es demasiado largo"<<endl;
        return false;
    }

    if(nombreCliente.size()==0)
    {
        cout<<"No ingresó ningun nombre"<<endl;
        return false;
    }
    strcpy(_nombreCliente, nombreCliente.c_str());
    return true;
}
bool Clientes::setApellidoCliente(string apellidoCliente)
{
    if(apellidoCliente.size()>TAMANIOCHARMEDIO)
    {
        cout<<"El apellido ingresado es demasiado largo"<<endl;
        return false;
    }
    if(apellidoCliente.size()==0)
    {
        cout<<"No ingresó ningun apellido"<<endl;

        return false;
    }
    strcpy(_apellidoCliente, apellidoCliente.c_str());
    return true;
}

bool Clientes::setEmailCliente(string emailCliente)
{
        if(emailCliente.size()>TAMANIOCHARLARGO){
        cout<<"Email ingresado excede el limite de caracteres"<<endl;
        return false;
    }
    if(emailCliente.size()==0){
        cout<<"No ha ingresado ningun email, ingrese un email"<<endl;
        return false;
    }
    if(!validarEmail(emailCliente)){
        cout<<"El formato ingresado no es valido"<<endl;
        return false;
    }
    strcpy(_emailCliente, emailCliente.c_str());
        return true;
}
bool Clientes::setDniCliente(int dniCliente)
{
    if(dniCliente<1000000 || dniCliente>99999999)
    {
        cout << "DNI invalido (fuera de rango)."<<endl;
        return false;
    }
    _dniCliente=dniCliente;
    return true;
}

bool Clientes::setTelefonoCliente(int telefonoCliente)
{
    string telefonoStr = to_string(telefonoCliente);
    if(telefonoStr.length()>15 || telefonoStr.length()<10){
       cout<<"El telefono ingresado es invalido"<<endl;
       return false;
    }
    _telefonoCliente=telefonoCliente;
    return true;
}

 void Clientes::setFechaNacimiento(Fecha fechaDeNacimiento){
 _fechaDeNacimientoCliente=fechaDeNacimiento;
 }
void Clientes::setEstado(bool estado)
{
    _estado=estado;
}

bool Clientes::cargarCliente()
{
    string nombreCliente;
    string apellidoCliente;
    string emailCliente;
    int dniCliente;
    int telefonoCliente;
    Fecha fechaDeNacimientoCliente;
    bool estado;

ArchivoClientes archivoCliente;
int cantidadClientes;
Clientes *vecClientes;
int contadorDeErrores=0;
bool esDatoValido=false;
while(contadorDeErrores<3){

} cout<< "Ingrese el nombre del cliente: "<<endl;
        getline(cin,nombreCliente);
        pasarAMinusculas(nombreCliente);
        bool encontro=false;
        esDatoValido=nombreCliente.length()>0 && nombreCliente.length()<TAMANIOCHARMEDIO;
         for(int i=0; i<cantidadClientes; i++)
        {
            string nombreAComparar=vecClientes[i].getNombreCliente();
            pasarAMinusculas(nombreAComparar); ///despues de guardar directamente en minusculas todo esta linea se puede borrar
            if(nombreAComparar==nombreCliente)
            {
                encontro=true;
            }

        }
        if(esDatoValido)
        {
            setNombreCliente(nombreCliente);
            contadorDeErrores=0;
        }else{
            cout<< "NO ES UN NOMBRE VALIDO EL QUE DESEA INGRESAR"<<endl;
            contadorDeErrores++;
            }

}




bool Clientes::validarEmail(const string& email)
{
    size_t arrobaPos=email.find('@');
    if(arrobaPos==string::npos || arrobaPos==0 || arrobaPos==email.length()-1)
    {
        return false;
    }
    if(email.find('@', arrobaPos +1)!= string::npos)
    {
        return false;
    }
    return true;
}
void Clientes::pasarAMinusculas(string &cadena)
{
    for (char &caracter : cadena)
    {
        caracter = std::tolower(static_cast<unsigned char>(caracter));
    }
}
