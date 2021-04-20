/*
 * producto.h
 *
 *  Created on: 19 abr. 2021
 *      Author: julieta_enee
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct
{
	char nombre[32];
	char descripcion[500];
	float precio;
	int isEmpty; //cuando es verdadero (1) significa que el elemento está vacío
}Producto;


int inicializarArrayProducto(Producto* pArray, int len);
int imprimirArrayProducto(Producto* pArray, int len);



#endif /* PRODUCTO_H_ */
