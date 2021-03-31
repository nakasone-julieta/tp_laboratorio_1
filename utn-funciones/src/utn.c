/*
 * utn.c
 *
 *  Created on: 25 mar. 2021
 *      Author: julieta_enee
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>//siempre en linux
#include "utn.h"

int utn_getInt(int *pNum,char*pTexto,char*pError, int minimo, int maximo,int reintento)
{
	int retornoFuncion = -1;
	int bufferInt;

	for (int i= reintento; i >= 0; i --)
	{
		if (pNum != NULL && pTexto != NULL && pError != NULL && minimo <= maximo && reintento >= 0 )
		{
			retornoFuncion = -2; //otro tipo de error

			printf ("%s", pTexto);//NO SE PUEDE COLAR INFO PROPIA !! Se imprime tal cual me lo mandan
			__fpurge(stdin);
			scanf("%d",&bufferInt);
			if (bufferInt>= minimo && bufferInt<= maximo)
			{
				*pNum = bufferInt;
				retornoFuncion =0;
				break; //salgo de la iteración del DO para llegar directamente al return (en este caso)
			}
			else
			{
				printf ("%s", pError);
				reintento --; //si entra, la variable int reinteno (con su valor del main) desciende en 1
			}
		}
		else
		{
			printf ("%s", pError);
			reintento --;
		}
	}
	return retornoFuncion;
}

int utn_getFloat(float *pDecimal,char*pTexto,char*pError, float minimo, float maximo,int reintento)
{
	int retornoFuncion = -1;
	float bufferFloat;

	for (int i= reintento; i >= 0; i --)
	{
		if (pDecimal != NULL && pTexto != NULL && pError != NULL && minimo <= maximo && reintento >= 0 )
		{
			printf ("%s", pTexto);
			__fpurge(stdin);
			scanf("%f",&bufferFloat);
			if (bufferFloat>= minimo && bufferFloat<= maximo)
			{
				*pDecimal = bufferFloat;
				retornoFuncion =0;
				break; //salgo de la iteración del DO para llegar directamente al return (en este caso)
			}
			else
			{
				printf ("%s", pError);
				reintento --; //si entra, la variable int reinteno (con su valor del main) desciende en 1
			}
		}
		else
		{
			printf ("%s", pError);
			reintento --;
		}
	}
	return retornoFuncion;
}

int utn_getChar (char* pCaracter, char* pTexto, char* pError, char min, char max, int reintentos)
{
	int retornoFuncion = -1;
	char bufferChar;
	if (pCaracter != NULL && pTexto != NULL && pError != NULL && min <= max && reintentos >= 0 )
	{
		for (int i= reintentos; i >= 0; i --)
		{
			printf ("%s", pTexto);
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
				printf ("%s", pError);
				reintentos --; //si entra, la variable int reinteno (con su valor del main) desciende en 1
			}
		}
	}
	else
	{
		printf ("%s", pError);
		reintentos --;
	}

		return retornoFuncion;
}


