#include <iostream>
using namespace std;
#include "ManagerEntrada.h"
#include "ManagerPeliculas.h"
#include "ManagerSalas.h"
#include "Fecha.h"
#include "Constante.h"
void ManagerEntrada::cargarEntrada()
{
/// DECLARACION DE VARIABLES PARA EL OBJETO ENTRADA
    bool banderaDeCarga=true;
    bool banderaDeError=false;
    int iDPelicula;
    int fila;
    int butacas;
    string entradaAPelicula;
    int numeroDeSala;
    Fecha fechaDeProyeccion;
    int dNIComprador;
    Entrada registro;
    /// MANAGER PARA MOSTRAR LAS BUTACAS DISPONIBLES Y COLABORAR CON LA ASIGNACION EN LA MATRIZ DE LOS NUMERO DE SALA
    ManagerSalas managerButacas;
    int cantidadTotalSalas=managerButacas.cantidadDeSalas();
    /// PARA MOSTRAR LA CARTELERA
    ManagerPeliculas managerCartelera;
    int totalPeliculasEnCartelera=managerCartelera.cantidadPeliculasEnCartelera();
    Pelicula *miCartelera;/// GUARDAMOS EN ESTE PUNTERO EL ARRAY DE PELICULAS EN CARTELERA Y SACAMOS EL ID Y NOMBRE DE PELICULA DESDE ACA

    Entrada miEntrada;
    int eleccionPelicula;

    if(totalPeliculasEnCartelera>0&&cantidadTotalSalas>0)
    {
        ///matriz dinamica con los numero de sala declaracion y asignacion de salas
        int** matrizNumeroDeSalas = new int*[totalPeliculasEnCartelera];
        if (matrizNumeroDeSalas == nullptr)
        {
            cout << "No se pudo reservar memoria para las salas." << endl;
            return;
        }/// se valido la optencion de memoria

        for (int i = 0; i < totalPeliculasEnCartelera; i++)
        {
            matrizNumeroDeSalas[i] = new int[3];
        }
        int contador=1;
        for(int i=0; i<totalPeliculasEnCartelera; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(contador<=cantidadTotalSalas)
                {
                    matrizNumeroDeSalas[i][j]=contador;
                    contador++;
                }
                else
                {
                    matrizNumeroDeSalas[i][j]=-1;
                }
            }
        }

        miCartelera=managerCartelera.traerPeliculasEnCartelera();/// retorna un ARRAY que usa memoria dinamica


        while(banderaDeCarga&&!banderaDeError)
        {
            cout<< "INGRESE EL DNI DEL COMPRADOR: "<<endl;
            cin>> dNIComprador;
            banderaDeError=registro.setDNIComprador(dNIComprador);
            if(!banderaDeError)
            {
                cout<<"Error con la carga del DNI, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
                cin>>banderaDeCarga;
            }
        }
        banderaDeError=false;

        fechaDeProyeccion.cargarFecha();

        while(banderaDeCarga&&!banderaDeError)
        {
            cout<< "INGRESE NUMERO LA PELICULA QUE QUIERE VER"<<endl;
            cout<< "Se van a mostrar : " << totalPeliculasEnCartelera<<" peliculas para elegir por segun el orden que aparecen"<<endl;
            cout<< "(MARQUE 1 o 2 o 3...etc"<<endl;
            managerCartelera.mostrarPeliculasEnCartelera();
            cin>> eleccionPelicula;
            banderaDeError=eleccionPelicula<=totalPeliculasEnCartelera&&eleccionPelicula>0;/// validamos que no ponga un numero negativo
            if(!banderaDeError)
            {
                cout<<"Error con el numero de pelicula elegida, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
                cin>>banderaDeCarga;
            }
        }
        banderaDeError=false;

        iDPelicula=miCartelera[eleccionPelicula-1].getNumeroDeID();///traemos el ID
        entradaAPelicula=miCartelera[eleccionPelicula-1].getNombrePelicula();/// traemos el nombre de la pelicula elegida


        while (banderaDeCarga && !banderaDeError)
        {
            int contadorDeSalasFueraDeServicio = 0;
            cout << "INGRESE NUMERO DE SALA QUE QUIERE ELEGIR: " << endl;
            /// EN ESTE FOR LE MOSTRAMOS LAS SALAS AL USUARIO
            for (int i = 0; i < 3; i++)
            {
                int nroSala = matrizNumeroDeSalas[eleccionPelicula - 1][i];
                if (nroSala != -1)
                {
                    managerButacas.mostrarSalaConNumero(nroSala, contadorDeSalasFueraDeServicio);
                }
                else
                {
                    cout << "ESTA SALA NO FUE ASIGNADA" << endl;
                    contadorDeSalasFueraDeServicio++;
                }
            }

            /// SI LAS 3 SALAS ESTAN ENTRE FUERA DE SERVICIO O SIN ASIGNAR MOSTRAMOS UN CARTEL Y SALIMOS SIN DEJAR ELEGIR UNA SALA AL USUARIO
            if (contadorDeSalasFueraDeServicio != 3)
            {
                cin >> numeroDeSala;

                for (int i = 0; i < 3; i++)
                {
                    if (numeroDeSala == matrizNumeroDeSalas[eleccionPelicula - 1][i])
                    {
                        ///CHEQUEAMOS QUE LA SALA QUE SI ESTA ASIGNADA NO ESTE FUERA DE SERVICIO
                        banderaDeError=managerButacas.validaEstadoSala(numeroDeSala);
                    }
                }

                if (!banderaDeError)
                {
                    cout << "Error con el número de sala elegida. (Presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir): ";
                    cin >> banderaDeCarga;
                }
            }
            else
            {
                ///AL NO HABER SALAS PARA ESA PELICULA LO HACEMOS SALIR DESPUES DE UN MENSAJE
                cout << "LO SENTIMOS, NO HAY SALAS DISPONIBLES PARA ESA PELICULA. POR FAVOR ELIJA OTRA." << endl;
                banderaDeCarga = false;
            }

        }

        banderaDeError=false;


        while(banderaDeCarga&&!banderaDeError)
        {
            // for contidad entradas compradas
           /// managerButacas.mostrarSalaPorNumero(numeroDeSala);///tiene valor por defecto/// ELIMINE EL VALOR POR DEFECTO
            cout<< "ELIJA LA FILA QUE DESEA COMPRAR"<<endl;
            cin>> fila;
            cout<< "INGRESE LA BUTACA QUE DESEA COMPRAR (entre 1 y 10)"<<endl;
            cin>> butacas;
            banderaDeError=fila>0&&fila<=FILAS&&butacas>0&&butacas<=COLUMNAS;///validamos que sea una fila y columna validos
            if(banderaDeError)
            {
                banderaDeError=managerButacas.comprarButaca(numeroDeSala,fila,butacas);///validamos que la butaca no este ocupada
            }
            if(!banderaDeError)
            {
                cout<<"Error con el numero de butaca elegida, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
                cin>>banderaDeCarga;
            }
        }
        banderaDeError=false;

        if(banderaDeCarga&&!banderaDeError)
        {

            miEntrada=Entrada(iDPelicula,fila,butacas,1/*cantidad de entradas*/,entradaAPelicula,numeroDeSala,fechaDeProyeccion,dNIComprador);

            if(_archiTikets.guardarEntrada(miEntrada))
            {
                cout<< "LA ENTRADA SE GUARDO CON EXITO"<<endl;
            }
            else
            {
                cout<< "NO SE PUDO GUARDAR LA ENTRADA"<<endl;
            }
        }
        delete[]miCartelera;/// en necesario eliminar la memoria dinamica
        for (int i = 0; i < totalPeliculasEnCartelera; i++)
        {
            delete[] matrizNumeroDeSalas[i];
        }
        delete[] matrizNumeroDeSalas;
    }
    else
    {
        cout<<"NO HAY PELICULAS EN CARTELERA O SALAS DISPONIBLES"<<endl;
    }
    system("pause");
    system("cls");
}

void ManagerEntrada::mostrarEntradas()
{
    int cantidad;
    Entrada *vecEntradas;

    cantidad=_archiTikets.getCantidadDeEntradas();
    if(cantidad>0)
    {
        vecEntradas= new Entrada[cantidad];
        if (vecEntradas == nullptr)
        {
            cout << "No se pudo reservar memoria para las entradas." << endl;
            return;
        }/// se valido la optencion de memoria

        _archiTikets.leerTodas(vecEntradas,cantidad);

        for(int i=0; i< cantidad; i++)
        {
            mostrarEntrada(vecEntradas[i]);
        }

        delete[]vecEntradas;
    }
    else
    {
        cout<<"NO HAY ENTRADAS COMPRADAS" <<endl;
    }
    system("pause");
    system("cls");
}


void ManagerEntrada::mostrarEntrada(Entrada reg)
{

    cout<< "EL NOMBRE DE LA PELICULA ES: "<< reg.getEntradaAPelicula()<<endl;
    cout<< "EL NUMERO DE SALA DONDE SE PROYECTA ES: "<< reg.getNumeroDeSala()<<endl;
    cout<< "LA FILA ES: "<< reg.getFila()<<endl;
    cout<< "LA BUTACA ES: "<< reg.getButacas()<<endl;
    cout<< "LA FECHA DE PROYECCION ES: ";
    reg.getFechaDeProyeccion().mostrarFecha();
    cout<< "EL NUMERO DE DNI DEL COMPRADOR ES: "<< reg.getDNIComprador()<<endl;
    cout<< "LA CANTIDAD DE ENTRADAS COMPRADAS ES:"<< reg.getCantEntradas()<<endl;
    cout<<"____________________________________________________"<<endl;

}
void ManagerEntrada::mostrarSoloPorCliente()
{
    int BuscandoDni;
    int option;

    do
    {
        cout<<"INGRESE EL DNI DEL CLIENTE: "<<endl;
        cin>>BuscandoDni;
        int contadorDeErrores=0;
        ///SI SE EQUIVOCA 3 VECES DEJAMOS DE PEDIRLE EL DNI Y SALIMOS
        while(BuscandoDni<1000000&&contadorDeErrores<2)
        {
            if(BuscandoDni<=1000000)
            {
                contadorDeErrores++;
            }
            if(contadorDeErrores<2)
            {
                cout << "DNI INVALIDO. INGRESE UN NUMERO MAYOR A 0: "<<endl;
                cin >> BuscandoDni;
            }
        }
        /// SI NO SE EQUIVOCO 3 VECES ENTRAMOS
        if(contadorDeErrores<2)
        {
            int cantidad;
            Entrada *vecEntradas;

            cantidad=_archiTikets.getCantidadDeEntradas();
            if(cantidad>0)
            {
                vecEntradas= new Entrada[cantidad];
                if (vecEntradas == nullptr)
                {
                    cout << "No se pudo reservar memoria para las entradas." << endl;
                    return;
                }/// se valido la optencion de memoria

                _archiTikets.leerTodas(vecEntradas, cantidad);
                bool aquiEstan=false;

                for(int i=0; i< cantidad; i++)
                {
                    if(vecEntradas[i].getDNIComprador()==BuscandoDni)
                    {
                        cout<<"NOMBRE DE LA PELICULA: "<<vecEntradas[i].getEntradaAPelicula()<<endl;
                        cout<<"NOMBRE DE LA NUMERO DE SALA: "<<vecEntradas[i].getNumeroDeSala()<<endl;
                        cout<<"NUMERO DE LA FILA: "<<vecEntradas[i].getFila()<<endl;
                        cout<<"BUTACA NUMERO : "<<vecEntradas[i].getButacas()<<endl;
                        cout<<"--------------------------------------------------"<<endl;
                        // mostrarEntrada(vecEntradas[i]);
                        aquiEstan=true;
                    }
                }
                if(!aquiEstan)
                {
                    cout<<"NO HAY ENTRADAS CON ESE DNI!"<<endl;
                }

                delete[]vecEntradas;


                cout << "¿DESEA BUSCAR OTRO DNI? (1-Si/0-No): ";
                cin >> option;
            }
            else
            {
                cout<<"NO HAY ENTRADAS COMPRADAS "<<endl;
                option=0;
            }
        }
        else
        {
            option=0;
        }

    }
    while (option == 1);

    cout << "FIN DE LA BUSQUEDA."<<endl;
    system("pause");
    system("cls");
}

