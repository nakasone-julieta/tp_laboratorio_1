/*
 ============================================================================
 Name        : algoritmo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
/***********************************************************/
#define PEDIR_NUM 5

int main(void)
{
	int numeros[PEDIR_NUM];
	int unNumero;
	int elMinimo;
	int indiceDelMinimo;
	int aux;
	int i;
	//int iIndice;

	for (i=0; i<PEDIR_NUM; i++)
	{
		utn_getInt(&unNumero, "ingrese un numero", "su numero no sirve [min0, max30]", 0, 30, 2);
		numeros[i]= unNumero;
	}
	for (i=0; i<PEDIR_NUM-1; i++)
	{
		if (i==0 || i!= indiceDelMinimo)
		{
			if (utn_buscarIndiceDelMinimoArrayInt(&numeros, PEDIR_NUM, &indiceDelMinimo)==0)
				{
					aux=indiceDelMinimo;
				}
			if (utn_buscarMinimoArrayInt(&numeros, PEDIR_NUM, elMinimo)==0)
			{
				i=elMinimo;//como hago para guardar el valor de elMinimo en un INDICE. Porque si hago i=elMinimo, estoy sobreescribiendo la i,pero no el valor que guarda???
				//indiceDelMin=aux
			}
		}
	}


}


