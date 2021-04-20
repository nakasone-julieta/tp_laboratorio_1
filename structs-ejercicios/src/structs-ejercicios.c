/*
 ============================================================================
 Name        : structs-ejercicios.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : ejercicio structs
 1) Definir un tipo de dato que represente un producto. El producto tiene
 a- nombre
 b- descripcion
 c- precio

 2) Definir un array de 200 productos. Indicar de alguna manera que la info
 de cada item no está cargada.


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "producto.h"

#define QTY_PRODUCTOS 200

int main(void) {
	Producto productos[QTY_PRODUCTOS];
	Producto auxPruebas;

	inicializarArrayProducto(productos, QTY_PRODUCTOS);

	auxPruebas.precio=10;
	auxPruebas.isEmpty=0;
	productos[2]=auxPruebas;

	imprimirArrayProducto(productos, QTY_PRODUCTOS);

}
