#include "cliente.h"
#include "clientes.h"

///--------------------- Cargar archivo Clientes ---------------------
void cargaArchivoClientes(const char archivo[]){
    char opcion = 0;
    int id = pasarUltimoIdClientes(archivo) + 1;

    stCliente a;

    FILE *pArchiClientes = fopen(archivo,"a+b");
    if(pArchiClientes != NULL){
        do{
            printf("\n\n");

            cargarUnCliente(&a,id,pArchiClientes);

            fwrite(&a, sizeof(stCliente), 1, pArchiClientes);

            id++;

            printf("\n\n\t ESC para salir - cualquier tecla para continuar");
            opcion = getch();
            system("cls");
        }
        while(opcion!=27);

        fclose(pArchiClientes);
    }else{
        printf("\n ERROR DE APERTURA DE ARCHIVO ");
    }
}
///--------------------- Cargar archivo Clientes ---------------------

///--------------------- Retorna el ultimo ID del archivo Clientes ---------------------
int pasarUltimoIdClientes(const char archivo[]){
    stCliente a;
    int id = 0;
    FILE *archi = fopen(archivo,"rb");

    if(archi){
            fseek(archi,sizeof(stCliente) * -1,SEEK_END);
            if(fread(&a,sizeof(stCliente),1,archi) > 0){
                id = a.id;
            }
        fclose(archi);
    }
    return id;
}
///--------------------- Retorna el ultimo ID del archivo Clientes ---------------------



///--------------------- Muestra todo el archivo Clientes ---------------------
void muestraArchivoClientes(const char archivo[]){
    stCliente a;
    FILE *pArchiClientes = fopen(archivo, "rb");

    if(pArchiClientes != NULL){
        while(fread(&a, sizeof(stCliente), 1, pArchiClientes) > 0){
            if(a.baja == 0){
                muestraUnCliente(a);
                printf("\n\n----------------------------------------------\n");
            }
        }
        fclose(pArchiClientes);
    }else{
        printf("\n ERROR DE APERTURA DE ARCHIVO ");
    }
}
///--------------------- Muestra todo el archivo Clientes ---------------------
