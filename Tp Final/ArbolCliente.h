#ifndef ARBOLCLIENTE_H_INCLUDED
#define ARBOLCLIENTE_H_INCLUDED

#include "generales.h"
#include "cliente.h"
#include "ListaConsumos.h"

typedef struct _nodoArbol{
	stCliente dato;
	nodoLista* consumos;
	struct _nodoArbol* izq;
	struct _nodoArbol* der;
}nodoArbol;

///---------------------- Recorrer Archivo de consumos y crea un arbol de Clientes ----------------------
nodoArbol* crearArbolClientes(const char nombreArchivoConsumos[],const char nombreArchivoClientes[]);

///---------------------- Carga el arbol CLientes a partir del archivo de clientes ----------------------
nodoArbol* archivoClientesToArbol(const char nombreArchivoConsumos[],const char nombreArchivoClientes[]);

///---------------------- Crea un nodo del Arbol ----------------------
nodoArbol* crearNodoArbol(stCliente dato);

///---------------------- Agrega al final del arbol ----------------------
nodoArbol* agregarAlFinalArbol(nodoArbol* arbol,nodoArbol* nuevo);

///---------------------- Carga los datos en el arbol ----------------------
nodoArbol* alta(nodoArbol* arbol,stCliente cliente,stConsumos consumo);

///---------------------- Busca un cliente del arbol por id ----------------------
nodoArbol* buscaCliente(nodoArbol* arbol,int idCliente);


///---------------------- Muestra todo el arbol ----------------------
void muestraArbol(nodoArbol* arbol);
///---------------------- Muestra un nodo del arbol ----------------------
void muestraUnNodoArbol(nodoArbol* arbol);


///---------------------- Busca el nodo mas derecho del sub arbol izquierdo ----------------------
nodoArbol* NMD(nodoArbol* arbol);
///---------------------- Busca el nodo mas izquierdo del sub arbol derecho ----------------------
nodoArbol* NMI(nodoArbol* arbol);
///---------------------- Borra un nodo ----------------------
nodoArbol* borrarNodo(nodoArbol* arbol, int id);


///---------------------- Menu de buscar cliente en arbol ----------------------
void menuBuscarClienteArbol(nodoArbol* arbol,int id);
///---------------------- Busca el id del cliente y muestra los consumos de un mes en especifico ----------------------
void liquidarConsumos(nodoArbol* arbol, int idCliente, int dato,int opcion);

#endif // ARBOLCLIENTE_H_INCLUDED
