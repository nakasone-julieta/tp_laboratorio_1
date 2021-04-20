/*
 * producto.c
 *
 *  Created on: 19 abr. 2021
 *      Author: julieta_enee
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>//siempre en linux************
#include <string.h> //lo uso para funciones como strnlen
#include "utn.h"
#include "producto.h"


/**
 * \brief	inicializo el array de Producto
 * \param float pArray Puntero al array
 * \param int len Define el tamaño del array
 * \return Retorna 0 (EXITO) y -1(ERROR)
 *
 */
int inicializarArrayProducto(Producto* pArray, int len) //esta funcion sirve para que cada linea del array sea nalizada como VACIA
{
	int retornoFuncion = -1;
	int i;
	if (pArray != NULL && len>0)
	{

		for (i=0; i<len; i++)
		{
			pArray[i].isEmpty = 1; //le doy un valor distinto a isEmpty. EL UNICO ELEMENTO DEL ARRAY QUE TIENE CARGA ES isEmpty
		}
		retornoFuncion = 0;
	}

	return retornoFuncion;
}

/**
 * \brief	imprime un array de Producto
 * \param float pArray Puntero al array
 * \param int len Define el tamaño del array
 * \return Retorna 0 (EXITO) y -1(ERROR)
 *
 */
int imprimirArrayProducto(Producto* pArray, int len)
{
	int retornoFuncion = -1;
	int i;
	if (pArray != NULL && len>0)
	{

		for (i=0; i<len; i++)
		{
			if(pArray[i].isEmpty == 0)//condiciono en relacion al isEmpty. No muestro hasta que isEmpty sea 0
			{
				printf("\nNombre:  %s - \nDescripcion: %s - \nPrecio:%.2f", pArray[i].nombre,
																			pArray[i].descripcion,
																			pArray[i].precio);
			}
		}
		retornoFuncion = 0;
	}

	return retornoFuncion;
}


