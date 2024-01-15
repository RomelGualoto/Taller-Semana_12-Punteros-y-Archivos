//Romel Gualoto Taller semana 12
#include <stdio.h>
#include "lecturas.h"
#include "funciones.h"
#include "menu.h"
#define F 100
#define C 15

FILE*archivo;

int main() {
    char NombreProducto[F][C];
    int cantidadProductos[F];
    float precio[F];
    printf("Bienvenido al inventario de Micromercado Vaquita \n");
    if ((archivo = fopen("inventario.txt", "a+")) != NULL) {
        int tamanio;
        int opcion;
        do {
            opcion = Menu();
            switch (opcion) {
                case 1:
                    ingresarProductos(&tamanio, NombreProducto, precio, cantidadProductos);
                    guardarEnArchivo(tamanio, NombreProducto, precio, cantidadProductos);
                    break;
                case 2:
                    modificarProductos();
                    break;
                case 3:
                    sacarDatos(NombreProducto, precio, cantidadProductos);
                    break;
            }
        } while (opcion != 4);
    } else {
        printf("Lamentablemente el archivo no logro abrirse\n");
    }

    fclose(archivo);
    return 0;
}