#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaConsumos.h"

///---------------------- Inicia la lista ----------------------
nodoLista* inicLista(){
    return NULL;
}
///---------------------- Inicia la lista ----------------------

///---------------------- Crea un nodo de la lista ----------------------
nodoLista* crearNodo(stConsumos dato){
    nodoLista* nuevo = (nodoLista *)malloc(sizeof(nodoLista));

    nuevo->dato = dato;
    nuevo->sig = NULL;

    return nuevo;
}
///---------------------- Crea un nodo de la lista ----------------------

///---------------------- Agrega al principio de la lista ----------------------
nodoLista* agregarAlPrincipio(nodoLista* lista,nodoLista* nuevo){
    nuevo->sig = lista;

    return nuevo;
}
///---------------------- Agrega al principio de la lista ----------------------

///---------------------- Muestra la lista ----------------------
void muestraLista(nodoLista* lista){
    if(lista){
        nodoLista* seg = lista;
        while(seg){
            muestraNodo(seg);
            printf("\n");
            seg = seg->sig;
        }
    }
}
///---------------------- Muestra la lista ----------------------

///---------------------- Muestra un nodo de la lista ----------------------
void muestraNodo(nodoLista* nodo){
    muestraUnConsumo(nodo->dato);
}
///---------------------- Muestra un nodo de la lista ----------------------

///---------------------- Muestra los consumos de un cliente en un mes en especifico ----------------------
void mostrarConsumoClientePorMes(nodoLista* consumos, int mes){
    int flag = 0;
    nodoLista* seg = consumos;

    while(seg){
        if(consumos->dato.mes == mes){
            muestraUnConsumo(consumos->dato);
            flag++;
        }
        seg = seg->sig;
    }

    if(flag == 0){
        printf("\n\n\n\tCliente sin consumos.\n");
    }
}
///---------------------- Muestra los consumos de un cliente en un mes en especifico ----------------------

///---------------------- Muestra los consumos de un cliente en un anio en especifico ----------------------
void mostrarConsumoClientePorAnio(nodoLista* consumos,int anio){
    int flag = 0;
    nodoLista* seg = consumos;

    while(seg){
        if(consumos->dato.anio == anio){
            muestraUnConsumo(consumos->dato);
            flag++;
        }
        seg = seg->sig;
    }

    if(flag == 0){
        printf("\n\n\n\tCliente sin consumos.\n");
    }
}
///---------------------- Muestra los consumos de un cliente en un anio en especifico ----------------------

///---------------------- Borra la lista ----------------------
nodoLista* borrarLista(nodoLista* lista){
    nodoLista* proximo = inicLista();
    nodoLista* seg = lista;
    while(seg){
        proximo = seg->sig;
        free(seg);
        seg = proximo;
    }
    return seg;
}
///---------------------- Borra la lista ----------------------
