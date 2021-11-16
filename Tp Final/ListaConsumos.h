#ifndef LISTACONSUMOS_H_INCLUDED
#define LISTACONSUMOS_H_INCLUDED

#include "consumo.h"

typedef struct _nodoLista{
	stConsumos dato;
	struct _nodoLista* sig;
}nodoLista;

///---------------------- Inicia la lista ----------------------
nodoLista* inicLista();

///---------------------- Crea un nodo de la lista ----------------------
nodoLista* crearNodo(stConsumos dato);

///---------------------- Agrega al principio de la lista ----------------------
nodoLista* agregarAlPrincipio(nodoLista* lista,nodoLista* nuevo);

///---------------------- Muestra la lista ----------------------
void muestraLista(nodoLista* lista);
///---------------------- Muestra un nodo de la lista ----------------------
void muestraNodo(nodoLista* nodo);

///---------------------- Muestra los consumos de un cliente en un mes en especifico ----------------------
void mostrarConsumoClientePorMes(nodoLista* consumos, int mes);
///---------------------- Muestra los consumos de un cliente en un anio en especifico ----------------------
void mostrarConsumoClientePorAnio(nodoLista* consumos,int anio);


///---------------------- Borra la lista ----------------------
nodoLista* borrarLista(nodoLista* lista);

#endif // LISTACONSUMOS_H_INCLUDED
