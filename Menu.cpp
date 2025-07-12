#include <iostream>
using namespace std;

#include "Menu.h"

void Menu::mostrarMenuPrincipal()
{
    do
    {
        cout<<"-----------> BIENVENIDO AL CINE FAFY&PANCHO <--------------"<<endl;
        cout<<"-------> PODES ACCEDER A LOS SIGUIENTES MENUES <-----------"<<endl;
        cout<<"OPCION 1.- MENU DE PELICULAS"<<endl;
        cout<<"OPCION 2.- MENU DE SALAS"<<endl;
        cout<<"OPCION 3.- MENU DE ENTRADAS"<<endl;
        cout<<"OPCION 4.- MENU DE RESPALDOS"<<endl;
        cout<<"OPCION 5.- MENU DE INFORMES"<<endl;
        cout<<"OPCION 0.- SALIR DEL PROGRAMA"<<endl;
        cin>>_opcionPrincipal;

        system("cls");
        switch(_opcionPrincipal)
        {
        case 1:
            menuPelicula();
            break;
        case 2:
            menuSalas();
            break;
        case 3:
            menuEntradas();
            break;
        case 4:
            menuRespaldo();
            break;
        case 5:
            menuInformes();
            break;
        case 0:
            cout<<"saliste del programa "<<endl;
            break;
        default:
            cout<<"la opcion elegida es incorrecta"<<endl;
            break;

        }
    }
    while(_opcionPrincipal!=0);
}

void Menu::menuPelicula()
{
    do
    {
        cout<<"------------> SECCION PELICULAS <-------------"<<endl;
        cout<<"OPCION 1.- GUARDAR PELICULA"<<endl;
        cout<<"OPCION 2.- LISTAR PELICULAS"<<endl;
        cout<<"OPCION 3.- BUSCAR PELICULA POR ID"<<endl;
        cout<<"OPCION 4.- SACAR DE CARTELERA"<<endl;
        cout<<"OPCION 5.- PONER EN CARTELERA"<<endl;
        cout<<"OPCION 6.- MOSTRAR PELICULAS EN CARTELERA"<<endl;
        cout<<"OPCION 0.- SALIR DE PELICULAS"<<endl;
        cin>>_opcionPelicula;

        system("cls");
        switch(_opcionPelicula)
        {
        case 1:
            _managerMovies.cargarPelicula();
            break;
        case 2:
            _managerMovies.mostrarPeliculas();
            break;
        case 3:
            _managerMovies.mostrarPeliculasPorID();
            break;
        case 4:
            _managerMovies.sacarDeCartelera();
            break;
        case 5:
            _managerMovies.ponerEnCartelera();
            break;
        case 6:
            _managerMovies.mostrarPeliculasEnCartelera();
                system("pause");
                system("cls");
            break;
        case 0:
            cout<<"SALISTE DE LA SECCION PELICULAS"<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<<"LA OPCION ELEGIDA ES INCORRECTA"<<endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while(_opcionPelicula!=0);

}
void Menu::menuSalas()
{
    int _opcionSala;

    do
    {
        cout<<"------------> SECCION SALAS <-------------"<<endl;
        cout<<"OPCION 1.- GUARDAR SALA"<<endl;
        cout<<"OPCION 2.- LISTAR SALAS"<<endl;
        cout<<"OPCION 3.- BUSCAR SALA POR NUMERO"<<endl;
        cout<<"OPCION 4.- BAJA DE SALA POR MANTENIMIENTO"<<endl;
        cout<<"OPCION 5.- ALTA DE SALA POST MANTENIMIENTO"<<endl;
        cout<<"OPCION 6.- MOSTRAR SALAS POR FECHA"<<endl;
        cout<<"OPCION 0.- VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>_opcionSala;

        system("cls");
        switch(_opcionSala)
        {
        case 1:
            _ManagerSalas.cargarSala();
            break;
        case 2:
            _ManagerSalas.mostrarSalas();
            system("pause");
            system("cls");
            break;
        case 3:
            _ManagerSalas.mostrarSalaPorNumero();
            break;
        case 4:
            _ManagerSalas.bajaPorMantenimiento();
            break;
        case 5:
            _ManagerSalas.altaPostMantenimiento();
            break;
        case 6:
            _ManagerSalas.mostrarSalasPorFecha();
            break;
        case 0:
            cout<<"SALISTE DE LA SECCION SALAS"<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<<"LA OPCION ELEGIDA ES INCORRECTA"<<endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while(_opcionSala!=0);


}

void Menu::menuEntradas()
{
    do
    {
        cout<<"------------> SECCION ENTRADAS <-------------"<<endl;
        cout<<"OPCION 1.- COMPRAR ENTRADA "<<endl;
        cout<<"OPCION 2.- MOSTRAR MIS ENTRADAS"<<endl;
        cout<<"OPCION 3.- LISTAR ENTRADAS COMPRADAS"<<endl;
        cout<<"OPCION 0.- SALIR DE ENTRADAS"<<endl;
        cin>>_opcionEntrada;

        system("cls");
        switch(_opcionEntrada)
        {
        case 1:
            _managerEntradas.cargarEntrada();
            break;
        case 2:
            _managerEntradas.mostrarSoloPorCliente();
            break;
        case 3:
            _managerEntradas.mostrarEntradas();

            break;
        case 0:
            cout<<"SALISTE DE LA SECCION ENTRADAS"<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<<"LA OPCION ELEGIDA ES INCORRECTA"<<endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while(_opcionEntrada!=0);

}

void Menu::menuRespaldo()
{

    do
    {
        cout<< "---------------> SECCION RESPALDOS <---------------"<<endl;
        cout<< "OPCION 1.- RESPALDAR ENTRADAS"<<endl;
        cout<< "OPCION 2.- RECUPERAR ENTRADAS"<< endl;
        cout<< "OPCION 3.- RESPALDAR PELICULAS"<<endl;
        cout<< "OPCION 4.- RECUPERAR PELICULAS"<<endl;
        cout<< "OPCION 5.- RESPALDAR SALAS"<<endl;
        cout<< "OPCION 6.- RECUPERAR SALAS"<<endl;
        cout<< "OPCION 7.- RESPALDAR TODOS LOS ARCHIVOS"<<endl;
        cout<< "OPCION 8.- RECUPERAR TODOS LOS ARCHIVOS"<<endl;
        cout<< "OPCION 0.- SALIR DEL MENU RESPALDOS"<< endl;
        cin>> _opcionRespaldo;

        system("cls");
        switch(_opcionRespaldo)
        {
        case 1:
            _managerRespaldo.crearNuevoRespaldoEntradas();
            break;
        case 2:
            _managerRespaldo.traerElRespaldoDeEntradas();
            break;
        case 3:
            _managerRespaldo.crearNuevoRespaldoPeliculas();
            break;
        case 4:
            _managerRespaldo.traerElRespaldoDePeliculas();
            break;
        case 5:
            _managerRespaldo.crearNuevoRespaldoSalas();
            break;
        case 6:
            _managerRespaldo.traerElRespaldoDeSalas();
            break;
        case 7:
            _managerRespaldo.crearNuevoRespaldoEntradas();
            _managerRespaldo.crearNuevoRespaldoPeliculas();
            _managerRespaldo.crearNuevoRespaldoSalas();
            break;
        case 8:
            _managerRespaldo.traerElRespaldoDeEntradas();
            _managerRespaldo.traerElRespaldoDePeliculas();
            _managerRespaldo.traerElRespaldoDeSalas();
            break;
        case 0:
            cout<< "SALISTE DE LA SECCION DE RESPALDOS"<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<< "LA OPCION ELEGIDA ES INCORRECTA"<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    while(_opcionRespaldo!=0);
}

void Menu::menuInformes()
{
    do
    {
        cout<<"------------> SECCION INFORMES <-------------"<<endl;
        cout<<"OPCION 1.- MOSTRAR TOTAL ENTRADAS VENDIDAS"<<endl;
        cout<<"OPCION 2.- MOSTRAR ENTRADAS VENDIDAS POR GENERO"<<endl;
        cout<<"OPCION 3.- MOSTRAR ENTRADAS VENDIDAS POR TITULO"<<endl;
        cout<<"OPCION 4.- MOSTRAR ENTRADAS VENDIDAS POR TIPO DE SALA"<<endl;
        cout<<"OPCION 0.- VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>_opcionInforme;

        system("cls");
        switch(_opcionInforme)
        {
        case 1:
            _informe.mostrarCantidadDeEntradasVendidas();
            break;
        case 2:
            _informe.mostrarCantidadEntradasVendidasPorgenero();
            break;
        case 3:
            _informe.mostrarCantidadDeEntradasVendidasPorTitulo();
            break;
        case 4:
            _informe.mostrarCantidadDeEntradasVendidasPorTipoDeSala();
            break;
        case 0:
            cout<<"SALISTE DE LA SECCION INFORMES"<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<<"LA OPCION ELEGIDA ES INCORRECTA"<<endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while(_opcionInforme!=0);


}
