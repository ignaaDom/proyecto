#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "gotoxy.h"
#include "generales.h"
#include "cliente.h"
#include "clientes.h"
#include "consumo.h"
#include "consumos.h"


const char archivo_clientes[30] = "clientes.dat";
const char archivo_consumos[30] = "consumos.dat";

///--------------------- Menú de opciones ---------------------
char menu();

/// -------------------- Opciones Consumos --------------------
char opcionesConsumos();

/// -------------------- Opciones Clientes --------------------
char opcionesClientes();


int main()
{
    char ctr;
    int id;
    int flag;

    char opcion;
    char consulta[20];
    int consultaCon;
    int cargarConsumos;

    stConsumos consumo;

    system("color 1F");

    loader();

    gotoxy(15,14);
    system("pause");

    system("cls");

    do{
        ctr = menu();
        system("cls");

        switch(ctr){


        case '0':
            gotoxy(15,3);
            printf(" * Volviendo al menu principal...");
            ctr = 0;
            break;
        ///Alta de clientes
        case '1':
            cargaArchivoClientes(archivo_clientes);
            break;

        ///Baja de cliente
        case '2':
            muestraArchivoClientes(archivo_clientes);

            //Pide el id del cliente eliminar
            printf("\n\n\tIngrese el id del cliente que desea eliminar: ");
            scanf("%d", &id);

            flag = eliminarCliente(archivo_clientes,id);

            system("cls");

            //Verifica el valor de la bandera
            if(flag == 1)
            {
                printf("\n\tCliente eliminado con exito.");
            }
            else
            {
                printf("\n\tNo se encontró el id del cliente solicitado.");
            }

            break;

        ///Modificar un cliente
        case '3':
            muestraArchivoClientes(archivo_clientes);

            //Pide el id del cliente a modificar
            printf("\n\tIngresa el id del cliente que desea modificar: ");
            scanf("%d", &id);

            system("cls");

            modificarCliente(archivo_clientes,id);
            break;

        ///Consultar un cliente
        case '4':
            opcion = menuConsulta();

            //Pide un dato para realizar la busqueda.
            printf("\n\n\tIngresa el dato a buscar: ");
            gets(consulta);

            system("cls");

            consultarUnCliente(archivo_clientes,opcion,consulta);
            break;
        ///Listado de clientes
        case '5':
            muestraArchivoClientes(archivo_clientes);
            break;


        ///Cargar archivo Consumos----------------------------
        case 'a':
            cargaArchivoConsumos(archivo_consumos,archivo_clientes);
            break;

        ///Da de baja un Consumo
        case 'b':
            muestraArchivoConsumos(archivo_consumos);

            //Pide el id del consumo eliminar
            printf("\n\n\tIngrese el id del consumo que desea eliminar: ");
            scanf("%d", &id);

            flag = eliminarConsumo(archivo_consumos,id);

            system("cls");

            //Verifica el valor de la bandera
            if(flag == 1)
            {
                printf("\n\tConsumo eliminado con exito.");
            }
            else
            {
                printf("\n\tNo se encontro el id del consumo solicitado.");
            }
            break;

        ///Modificar un consumo
        case 'c':
            //Pide el id del cliente a modificar
            printf("\n\tIngresa el id del consumo que desea modificar: ");
            scanf("%d", &id);

            system("cls");

            modificarConsumo(archivo_consumos,id,archivo_clientes);
            break;

        ///Consultar un consumo
        case 'd':
            opcion = menuConsultaConsumo();
            //Pide un dato para realizar la busqueda.
            gotoxy(15,20);
            printf("\tIngresa el dato a buscar: ");
            scanf("%d", &consultaCon);

            system("cls");

            consultarUnConsumo(archivo_consumos,opcion,consultaCon);
            break;

        ///Listado de Consumos
        case 'e':
            muestraArchivoConsumos(archivo_consumos);
            break;

        ///Buscar consumo por fecha
        case 'f':

            consumo = menuBuscarConsumoFecha(archivo_consumos);

            if(consumo.id != -1)
            {
                muestraUnConsumo(consumo);
            }
            else
            {
                gotoxy(15,12);
                printf("\n\tConsumo no encontrado.");
            }

            break;

        ///Carga de consumos aleatorios
            case 'g':
                printf("\n\tIngrese la cantidad de consumos a cargar: ");
                scanf("%d", &cargarConsumos);

                printf("\n\n");

                flag = agregarConsumosAleatorios(archivo_clientes,archivo_consumos,cargarConsumos);

                if(flag == cargarConsumos){
                    printf("\n\tConsumos cargados con exito");
                }else{
                    printf("\n\tError al cargar consumos.");
                }
                break;

        case 27:
            gotoxy(15,12);
            printf("\n\tFin del sistema...");
            break;
        default:
            gotoxy(15,14);
            printf("\n\tLa opcion que ingresaste es incorrecta.");
        }

        printf("\n\n");
        //gotoxy(15,16);
        system("pause");
        system("cls");

    }
    while(ctr != 27);

    return 0;
}


///--------------------- Menú de opciones ---------------------
char menu()
{

    char opcion;
    char ctr;

    do
    {

        system("cls");
        gotoxy(20,3);
        printf("\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2 || MENU PRINCIPAL || \xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2");
        gotoxy(20,6);
        printf("\xDB\xDB\xDB\xDB | 1. CLIENTE:   ");
        gotoxy(20,8);
        printf(" \t * ABM y Gestion de Clientes.");
        gotoxy(20,12);
        printf("\xDB\xDB\xDB\xDB | 2. CONSUMOS: ");
        gotoxy(20,14);
        printf(" \t * Gestion de Consumo de datos.");
        gotoxy(20,18);
        printf("Elija una opcion - ESC para salir:");
        fflush(stdin);
        opcion = getch();

    }
    while(opcion != '1' && opcion != '2' && opcion != 27);

    switch(opcion)
    {
    case '1':
        ctr = opcionesClientes();
        break;
    case '2':
        ctr = opcionesConsumos();
        break;
    case 27:
        ctr = 27;
        break;
    }
    return ctr;
}
///--------------------- Menú de opciones ---------------------


/// -------------------- Opciones Clientes --------------------
char opcionesClientes(){

    char ctr;

    do
    {
        system("cls");
        gotoxy(20,3);
        printf("\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2 || OPCIONES DE CLIENTE  || \xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2");
        gotoxy(20,6);
        printf("\xDB\xDB\xDB\xDB | 1. Alta de Cliente.   ");
        gotoxy(20,8);
        printf("\xDB\xDB\xDB\xDB | 2. Baja de Cliente.");
        gotoxy(20,10);
        printf("\xDB\xDB\xDB\xDB | 3. Modificar Cliente.");
        gotoxy(20,12);
        printf("\xDB\xDB\xDB\xDB | 4. Consultar un Cliente.");
        gotoxy(20,14);
        printf("\xDB\xDB\xDB\xDB | 5. Listado de Clientes");
        gotoxy(20,16);
        printf("\xDB\xDB\xDB\xDB | 0. Volver.");
        gotoxy(20,19);
        gotoxy(20,21);
        printf("Elija una opcion - ESC para salir:");
        fflush(stdin);
        ctr = getch();
    }
    while((ctr < 48 || ctr > 53) && ctr != 27);

    return ctr;
}

/// -------------------- Opciones Clientes --------------------


/// -------------------- Opciones Consumos --------------------
char opcionesConsumos(){

    char ctr;

    do
    {
        system("cls");
        gotoxy(20,3);
        printf("\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2 || OPCIONES DE CONSUMOS  || \xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2\xF2");
        gotoxy(20,6);
        printf("\xDB\xDB\xDB\xDB | a. Alta de Consumo.   ");
        gotoxy(20,8);
        printf("\xDB\xDB\xDB\xDB | b. Baja de Consumo.");
        gotoxy(20,10);
        printf("\xDB\xDB\xDB\xDB | c. Modificar un Consumo.");
        gotoxy(20,12);
        printf("\xDB\xDB\xDB\xDB | d. Consulta de Consumo.");
        gotoxy(20,14);
        printf("\xDB\xDB\xDB\xDB | e. Listado de Consumos.");
        gotoxy(20,16);
        printf("\xDB\xDB\xDB\xDB | f. Buscar consumo por fecha.");
        gotoxy(20,18);
        printf("\xDB\xDB\xDB\xDB | g. Cargar consumos Aleatorios.");
        gotoxy(20,20);
        printf("\xDB\xDB\xDB\xDB | 0. Volver.");
        gotoxy(20,23);
        gotoxy(20,25);
        printf("Elija una opcion - ESC para salir:");
        fflush(stdin);
        ctr = getch();
    }
    while((ctr < 97 || ctr > 103) && ctr != 27 && ctr != 48);

    return ctr;
}
/// -------------------- Opciones Consumos --------------------

