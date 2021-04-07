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

///////////////////////////////operaciones simples
int utn_dividirFloat (float* pResultado, float dividendo, float divisor)
{
	float division;
	int retorno = -1;
	if(pResultado!= NULL && divisor != 0)
	{
		division = dividendo/divisor;
		*pResultado=division;
		retorno = 0;
	}
	return retorno;
}

int utn_multiplicarFloat (float* pResultado, float factor1, float factor2)
{
	//float producto;
	int retorno = -1;
	if (pResultado != NULL)
	{
		*pResultado = (float)factor1*factor2;
		retorno =  0;
	}
	return retorno;
}

int utn_sumarFloat (float* pResultado, float sumando1, float sumando2)
{
	int retorno = -1;
	if (pResultado != NULL)
	{
		*pResultado = (float)sumando1+sumando2;
		retorno =  0;
	}
	return retorno;
}

int utn_restarFloat (float* pResultado, float minuendo, float sustraendo)
{
	int retorno = -1;
	if (pResultado != NULL)
	{
		*pResultado = (float)minuendo-sustraendo;
		retorno =  0;
	}
	return retorno;
}

///////////////////////////////interaccion con usuario

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


///////////////////////////////operaciones con array
int utn_imprimirArray(int array[], int len)
{
	int i;
	int retornoFuncion = -1;
	if (array != NULL && len >= 0)
	{
		for (i=0; i<len; i++)
		{
			retornoFuncion = 0;
			printf ("%d ", array[i]);
		}
	}
	return retornoFuncion;
}

int utn_promediarArray(float* pResultado, int array[], int len)//calcular promedio de los valores de Array
{
	int i;
	int retornoFuncion = -1;
	int acumuladorArray=0;

	if (array != NULL && len >= 0)
		{
			for (i=0; i<len; i++)
			{
				retornoFuncion = 0;
				acumuladorArray=acumuladorArray+array[i];
			}
		}
	*pResultado=(float)acumuladorArray/len;
	return retornoFuncion;
}

int utn_sumarArray(float* pResultado, int array[], int len)//calcular la suma de los elementos del array
{
	int i;
	int retornoFuncion = -1;
	int acumuladorArray=0;

	if (array != NULL && len >= 0)
		{
			for (i=0; i<len; i++)
			{
				retornoFuncion = 0;
				acumuladorArray=acumuladorArray+array[i];
			}
		}
	*pResultado=acumuladorArray;
	return retornoFuncion;
}

int utn_buscarMinimoArrayInt (int* pArray,int limite, int* pResultado)
{
    int retorno=-1;
    int minimo;
    int i;
    if(pArray !=NULL && limite>0 && pResultado !=NULL)
    {
    	minimo=pArray[0];

    	for(i=1;i<limite;i++)
    	{
    		if(pArray[i]<minimo)
    		{
    			minimo=pArray[i];
    		}
    	}
        retorno=0;
    }
    *pResultado=minimo;

    return retorno;
}

int utn_buscarMaximoArrayInt (int* pArray,int limite, int* pResultado)
{
    int retorno=-1;
    int maximo;
    int i;
    if(pArray !=NULL && limite>0 && pResultado !=NULL)
    {
    	maximo=pArray[0];

    	for(i=1;i<limite;i++)
    	{
    		if(pArray[i]>maximo)
    		{
    			maximo=pArray[i];
    		}
    	}
        retorno=0;
    }
    *pResultado=maximo;

    return retorno;
}

int utn_buscarIndiceDelMinimoArrayInt (int* pArray,int limite, int* pResultadoIndice)
{
    int retorno=-1;
    int minimo;
    int indiceDeMinimo;
    int i;
    if(pArray !=NULL && limite>0 && pResultadoIndice !=NULL)
    {
    	minimo=pArray[0];

    	for(i=1;i<limite;i++)
    	{
    		if(pArray[i]<minimo)
    		{
    			minimo=pArray[i];
    			indiceDeMinimo = i;
    		}
    	}
        retorno=0;
    }
    *pResultadoIndice=indiceDeMinimo;

    return retorno;
}



