#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArbolCliente.h"
#include "ListaConsumos.h"
#include "cliente.h"

///---------------------- Recorrer Archivo de consumos y crea un arbol de Clientes ----------------------
nodoArbol* crearArbolClientes(const char nombreArchivoConsumos[],const char nombreArchivoClientes[]){
    stConsumos consumo;
    stCliente cliente;
    nodoArbol* arbol = NULL;
    FILE* archi = fopen(nombreArchivoConsumos,"rb");

    if(archi){
        while(fread(&consumo,sizeof(stConsumos),1,archi) > 0){
            cliente = recorrerArchivoClientes(nombreArchivoClientes,consumo.idCliente);

            arbol = alta(arbol,cliente,consumo);
        }
        fclose(archi);
    }
    return arbol;
}
///---------------------- Recorrer Archivo de consumos y crea un arbol de Clientes ----------------------


///---------------------- Carga el arbol CLientes a partir del archivo de clientes ----------------------
nodoArbol* archivoClientesToArbol(const char nombreArchivoConsumos[],const char nombreArchivoClientes[]){
    nodoArbol* arbol = crearArbolClientes(nombreArchivoConsumos,nombreArchivoClientes);

    stCliente a;

    FILE* archi = fopen(nombreArchivoClientes,"rb");

    if(archi){
        while(fread(&a,sizeof(stCliente),1,archi)){
            arbol = agregarAlFinalArbol(arbol,crearNodoArbol(a));
        }
        fclose(archi);
    }
    return arbol;
}
///---------------------- Carga el arbol CLientes a partir del archivo de clientes ----------------------


///---------------------- Carga el arbol CLientes a partir del archivo de clientes ----------------------
nodoArbol* crearNodoArbol(stCliente dato){
    nodoArbol* nuevo = (nodoArbol*)malloc(sizeof(nodoArbol));

    nuevo->dato = dato;
    nuevo->consumos = inicLista();
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}
///---------------------- Carga el arbol CLientes a partir del archivo de clientes ----------------------

///---------------------- Agrega al final del arbol ----------------------
nodoArbol* agregarAlFinalArbol(nodoArbol* arbol,nodoArbol* nuevo){
    if(!arbol){
        arbol = nuevo;
    }else{
        if(nuevo->dato.id != arbol->dato.id){
            if(nuevo->dato.id < arbol->dato.id){
                arbol->izq = agregarAlFinalArbol(arbol->izq,nuevo);
            }else{
                arbol->der = agregarAlFinalArbol(arbol->der,nuevo);
            }
        }
    }
    return arbol;
}
///---------------------- Agrega al final del arbol ----------------------

///---------------------- Carga los datos en el arbol ----------------------
nodoArbol* alta(nodoArbol* arbol,stCliente cliente,stConsumos consumo){
    nodoLista* aux = crearNodo(consumo);
    nodoArbol* pos = buscaCliente(arbol,cliente.id);

    if(!pos){
        arbol = agregarAlFinalArbol(arbol,crearNodoArbol(cliente));
        pos = buscaCliente(arbol,cliente.id);
    }
    if(!pos->consumos){
        pos->consumos = inicLista();
    }
    pos->consumos = agregarAlPrincipio(pos->consumos,aux);
    return arbol;
}
///---------------------- Carga los datos en el arbol ----------------------

///---------------------- Busca un cliente del arbol por id ----------------------
nodoArbol* buscaCliente(nodoArbol* arbol,int idCliente){
    nodoArbol* rta = NULL;
    if(arbol){
        if(arbol->dato.id == idCliente){
            rta = arbol;
        }else{
            if(idCliente < arbol->dato.id){
                rta = buscaCliente(arbol->izq,idCliente);
            }else{
                rta = buscaCliente(arbol->der,idCliente);
            }
        }
    }
    return rta;
}
///---------------------- Busca un cliente del arbol por id ----------------------


///---------------------- Muestra todo el arbol ----------------------
void muestraArbol(nodoArbol* arbol){
    if(arbol){
        muestraUnNodoArbol(arbol);
        printf("\n\n------------------------------------------------------------------\n\n");
        muestraArbol(arbol->izq);
        muestraArbol(arbol->der);
    }
}
///---------------------- Muestra todo el arbol ----------------------

///---------------------- Muestra un nodo del arbol ----------------------
void muestraUnNodoArbol(nodoArbol* arbol){
    printf("\n\tCliente Nro: %d \n",arbol->dato.nroCliente);
    muestraUnCliente(arbol->dato);
    if(arbol->consumos){
        printf("\n\n\n\tConsumos del Cliente Nro %d: \n",arbol->dato.nroCliente);
        muestraLista(arbol->consumos);
    }else{
        printf("\n\n\n\tCliente sin consumos.\n");
    }
}
///---------------------- Muestra un nodo del arbol ----------------------


/// Funciones de borrar nodo
///---------------------- Busca el nodo mas derecho del sub arbol izquierdo ----------------------
nodoArbol* NMD(nodoArbol* arbol){
    if(arbol){
        if(arbol->der){
            arbol = NMD(arbol->der);
        }
    }

    return arbol;
}
///---------------------- Busca el nodo mas derecho del sub arbol izquierdo ----------------------

///---------------------- Busca el nodo mas izquierdo del sub arbol derecho ----------------------
nodoArbol* NMI(nodoArbol* arbol){
    if(arbol){
        if(arbol->izq){
            arbol = NMI(arbol->izq);
        }
    }

    return arbol;
}
///---------------------- Busca el nodo mas izquierdo del sub arbol derecho ----------------------

///---------------------- Borra un nodo ----------------------
nodoArbol* borrarNodo(nodoArbol* arbol, int id){
    if(arbol){
        if(id == arbol->dato.id){
            if(arbol->izq){
                nodoArbol* masDer = NMD(arbol->izq);
                arbol->dato = masDer->dato;
                arbol->izq = borrarNodo(arbol->izq, masDer->dato.id);
            }else{
                if(arbol->der){
                    nodoArbol* masIzq = NMI(arbol->der);
                    arbol->dato = masIzq->dato;
                    arbol->der = borrarNodo(arbol->der, masIzq->dato.id);
                }else{
                    if(arbol->consumos){
                        arbol->consumos = borrarLista(arbol->consumos);
                    }
                    free(arbol);
                    arbol = NULL;
                }
            }
        }else{
            if(id > arbol->dato.id){
                arbol->der = borrarNodo(arbol->der,id);
            }else{
                arbol->izq = borrarNodo(arbol->izq,id);
            }
        }
    }

    return arbol;
}
///---------------------- Borra un nodo ----------------------


///---------------------- Menu de buscar cliente en arbol ----------------------
void menuBuscarClienteArbol(nodoArbol* arbol,int id){
    int opcion;
    int dato;

    do{
        printf("\n\n\t1. Liquidar por mes.");
        printf("\n\t2. Liquidar por anio.");

        printf("\n\n\tElija una opcion: ");
        scanf("%d",&opcion);

        system("cls");
    }while(opcion != 1 && opcion != 2);

    if(opcion == 1){
        do{
            printf("\n\tIngrese un mes: ");
            scanf("%d",&dato);

            if(dato < 1 || dato > 12){
                printf("\n\n\tMes iconrrecto, ingresalo de nuevo.\n");
            }
        }while(dato < 1 || dato > 12);
    }else{
        int anioHoy;
        devolverAnioHoy(&anioHoy);

        do{
            printf("\n\tIngrese un anio: ");
            scanf("%d",&dato);

            if(dato > anioHoy){
                printf("\n\n\tAnio incorrecto, ingreselo de nuevo.\n");
            }
        }while(dato > anioHoy);
    }
    system("cls");

    liquidarConsumos(arbol,id,dato,opcion);
}
///---------------------- Menu de buscar cliente en arbol ----------------------

///---------------------- Busca el id del cliente y muestra los consumos de un mes en especifico ----------------------
void liquidarConsumos(nodoArbol* arbol, int idCliente, int dato,int opcion){
    nodoArbol* cliente = buscaCliente(arbol,idCliente);
    if(cliente){
        if(opcion == 1){
            printf("\n\tMostrando los consumos del cliente %s %s en el mes %d:\n\n\n", cliente->dato.nombre, cliente->dato.apellido, dato);
            mostrarConsumoClientePorMes(cliente->consumos,dato);
        }else{
            printf("\n\tMostrando los consumos del cliente %s %s en el anio %d:\n\n\n", cliente->dato.nombre, cliente->dato.apellido, dato);
            mostrarConsumoClientePorAnio(cliente->consumos,dato);
        }
    }else{
        printf("\n\tId no encontrado.");
    }
}
///---------------------- Busca el id del cliente y muestra los consumos de un mes en especifico ----------------------
