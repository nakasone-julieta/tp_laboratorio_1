/*
 * utn.c
 *
 *  Created on: 25 mar. 2021
 *      Author: julieta_enee
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>//siempre en linux************
#include "utn.h"

int utn_getInt(int *pNumero,char*pMensaje,char*pMensajeError, int min, int max,int reintentos)
{
	int retornoFuncion = -1; //ERROR alguno de los parámetros no verifica: esto sería un problema de la persona que llamó a la función?
	int bufferInt;

	if (pNumero != NULL && pMensaje != NULL && pMensajeError != NULL && min <= max && reintentos >= 0 )
	{
		for (int i= reintentos; i >= 0; i --)
		{
			retornoFuncion = -2; //otro tipo de error: bufferInt no se encuentra dentro del rango establecido ÉSTO SERÍA IGUAL SI ESTUVIERA EN EL ELSE?
			printf ("%s", pMensaje);//**********NO SE PUEDE COLAR INFO PROPIA !! Se imprime tal cual me lo mandan
			__fpurge(stdin);
			scanf("%d",&bufferInt);
			if (bufferInt>= min && bufferInt<= max)
			{
				*pNumero = bufferInt;
				retornoFuncion =0;
				break; //***************salgo de la iteración del DO para llegar directamente al return (en este caso)
			}
			else
			{
				retornoFuncion = -3;
				printf ("%s", pMensajeError);
				reintentos --; //*************si entra, la variable int reinteno (con su valor del main) desciende en 1
			}
		}
	}
	else
	{
		printf ("%s", pMensajeError);
		reintentos --;
	}
	return retornoFuncion;
}

int utn_getFloat(float *pDecimal,char*pMensaje,char*pMensajeError, float min, float max,int reintentos)
{
	int retornoFuncion = -1;
	float bufferFloat;

	if (pDecimal != NULL && pMensaje != NULL && pMensajeError != NULL && min <= max && reintentos >= 0 )
	{
		for (int i= reintentos; i >= 0; i --)
		{
			printf ("%s", pMensaje);
			__fpurge(stdin);
			scanf("%f",&bufferFloat);
			if (bufferFloat>= min && bufferFloat<= max)
			{
				*pDecimal = bufferFloat;
				retornoFuncion =0;
				break;
			}
			else
			{
				printf ("%s", pMensajeError);
				reintentos --;
			}
		}
	}
	else
	{
		printf ("%s", pMensajeError);
		reintentos --;
	}

	return retornoFuncion;
}

int utn_getChar (char* pCaracter, char* pMensaje, char* pMensajeError, char min, char max, int reintentos)
{
	int retornoFuncion = -1;
	char bufferChar;
	if (pCaracter != NULL && pMensaje != NULL && pMensajeError != NULL && min <= max && reintentos >= 0 )
	{
		for (int i= reintentos; i >= 0; i --)
		{
			printf ("%s", pMensaje);
			__fpurge(stdin);
			scanf("%c",&bufferChar);
			if (bufferChar>= min && bufferChar<= max)
			{
				*pCaracter = bufferChar;
				retornoFuncion =0;
				break; //salgo de la iteración del DO para llegar directamente al return (en este caso)
			}
			else
			{
				printf ("%s", pMensajeError);
				reintentos --; //si entra, la variable int reinteno (con su valor del main) desciende en 1
			}
		}
	}
	else
	{
		printf ("%s", pMensajeError);
		reintentos --;
	}

		return retornoFuncion;
}

void utn_imprimirArray(int array[], int len)
{
	int i;
	for (i=0; i<len; i++)
	{
		printf ("%d ", array[1]);
	}
}

