/*
 ============================================================================
 Name        : algoritmo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : hacer un algoritmo que, ante un array:
 1. busque el numero menor desde el indice
 2. si el indice es menor al indice del minimo:
 2a. en un auxiliar guarde el valor del indice [i]
 2b. coloque el menor en el indice [i]
 2c. coloque aux en el indice [indice del minimo]
 3. reitere comenzando con un i=o i menor al límite del array, i incrementado de 1 en 1.
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
	//int indiceDelMinimo;
	//int aux;
	int i;
	//int iIndice;

	for (i=0; i<PEDIR_NUM; i++) /// lo puedo hacer una funcion??!?!?!?!?!
	{
		utn_getInt(&unNumero, "ingrese un numero", "su numero no sirve [min0, max30]", 0, 30, 2);
		numeros[i]= unNumero;

	}
	if (utn_buscarMinimoArrayInt(numeros, PEDIR_NUM, &elMinimo)==0)
			{
				utn_imprimirArray(numeros, PEDIR_NUM);
				printf("el minimo es: %d", elMinimo);
			}
		/*if (i==0 || i!= indiceDelMinimo)
		{
			if (utn_buscarIndiceDelMinimoArrayInt(numeros, PEDIR_NUM, &indiceDelMinimo)==0 && utn_buscarMinimoArrayInt(numeros, PEDIR_NUM, &elMinimo)==0)
			{
				aux=numeros[i];
				numeros[i]=elMinimo;
				indiceDelMinimo=aux;
			}
		}
	}
	//if (==0)
	//{
		utn_imprimirArray(numeros, PEDIR_NUM);
	//}*/

}




