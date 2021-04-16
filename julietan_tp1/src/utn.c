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

/** \brief función que opera entre dos variables tipo float, sumandolas y devuelve el retorno de la función
 * \param float pResultado Puntero al espacio de memoria donde se escribirá el resultado de la operación
 * \param float sumando1: recibe el valor alojado en la variable float para operar sobre él
 * \param float sumando2: recibe el valor alojado en la variable float para operar sobre él
 * \return retorna 0 los datos ingresados son válidos, sino -1
 */
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

/** \brief función que opera entre dos variables tipo float con una resta y devuelve el retorno de la función
 * \param float pResultado Puntero al espacio de memoria donde se escribirá el resultado de la operación
 * \param float minuendo: recibe el valor alojado en la variable float para operar sobre él
 * \param float sustraendo: recibe el valor alojado en la variable float para operar con él
 * \return retorna 0 los datos ingresados son válidos, sino -1
 */
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

/** \brief función que opera entre dos variables tipo float con una división y devuelve el retorno de la función
 * \param float pResultado Puntero al espacio de memoria donde se escribirá el resultado de la operación
 * \param float dividendo: recibe el valor alojado en la variable float para operar sobre él
 * \param float divisor: recibe el valor alojado en la variable float para operar con él
 * \return retorna 0 los datos ingresados son válidos y logra hacer la operación.
 * 	 	   retorna -1 si los datos ingresados no son válidos
 * 	 	   retorna -2 si los datos ingresados son válidos pero no lora hacer la operación
 */
int utn_dividirFloat (float* pResultado, float dividendo, float divisor)
{
	float division;
	int retorno = -1;
	if(pResultado!= NULL)
	{
		if(divisor != 0)
		{
			division = dividendo/divisor;
			*pResultado=division;
			retorno = 0;
		}
		else
		{
			retorno= -2;
		}

	}
	return retorno;
}


/**\ brief función que opera entre dos variables tipo float multiplicándolos y devuelve el retorno de la función
 * \param float pResultado Puntero al espacio de memoria donde se escribirá el resultado de la operación
 * \param float factor1 recibe el valor alojado en la variable float para operar con él
 * \param float factor2 recibe el valor alojado en la variable float para operar con él
 * \return retorna 0 si los datos ingresados son válidos
 * 		   retorna -1 si los datos ingresados no son válidos
 */
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

/**\ brief función que opera el número recibido y le calcula el factorial
 * \param float pResultado Puntero al espacio de memoria donde se escribirá el resultado de la operación
 * \param float numero recibe el valor alojado en la variable float para operar sobre él
 * \return retorna 0 si los datos ingresados son válidos y se pudo calcular el factorial
 * 		   retorna -1 si los datos ingresados no son válidos
 * 		   retorna -2 si el número recibido es negativo, por lo cual no se calcula el factorial
 * 		   retorna -3 si el número recibido no es un entero, por lo cual no se calcula el factorial
 */
int utn_factorialFloat(float* pResultado, float numero) //retornoFuncion=-2 -> numero negativo no tiene factorial//// retornoFuncion=0 -> el numero era positivo
{
	int retornoFuncion=-1;
	float numeroPositivo;
	//int flagPositivo=1;
	int i;
	float multiplicar;
	float acumulador=0;

	if(pResultado!=NULL)
	{
		retornoFuncion=0;
		if(numero<0)//de -1 a menos
		{
			retornoFuncion =-2;
		}
		/*else if(numero>0 && numero<1)//entre 0 y 1
		{
			retornoFuncion =-3;
		}*/
		else if(numero>1)// de 2 (inclusive) en adelante
		{
			numeroPositivo=numero;
			for (i=numero; i>1; i--)
			{
				if(i==numeroPositivo)
				{
					multiplicar=i*1;
					acumulador=multiplicar;
				}
				else
				{
					multiplicar = acumulador*i;
					acumulador=multiplicar;
				}
			}
			if((*pResultado=acumulador)==0)
			{
				retornoFuncion =-3;
			}
		}
		else//si nuermo es 0 o 1
		{
			*pResultado=1;
		}
	}
	return retornoFuncion;
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

/** \brief Solicita un numero(float) al usuario, luego de verificarlo lo guarda en pResultado y devuelve el retorno de la funcion
 * \param float pResultado: Puntero al espacio de memoria donde se dejará el resultado de la función
 * \param char pMensaje: mensaje que a ser mostrado previo a recibir datos
 * \param char pMensajeError: mensaje a ser mostrado en caso de error
 * \param float min: criterio minimo para aceptar el valor ingresado
 * \param float max: criterio maximo para aceptar el valor ingresado
 * \param int reintentos: oportunidades para reintentar la carga una vez que se haya cometido un error
 * \param retorna 0(EXITO)si el valor ingresado cumple con el criterio, siendo todos los parámetros son válidos.
 * 		  Retorna -1(ERROR) si los parametros no son válidos
 * 		  Retorna -2(ERROR) si los parametros son válidos pero no se cumple el criterio
 */
int utn_getFloat(float *pDecimal,char*pMensaje,char*pMensajeError, float min, float max,int reintentos)
{
	int retornoFuncion = -1;
	float bufferFloat;

	if (pDecimal != NULL && pMensaje != NULL && pMensajeError != NULL && min <= max && reintentos >= 0 )
	{
		retornoFuncion = -2;
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
	/*else
	{
		printf ("%s", pMensajeError);
		reintentos --;
	}*/

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

int utn_buscarMinimoArrayInt (int array[],int limite, int* pResultado)
{
    int retorno=-1;
    int minimo;
    int i;
    if(array !=NULL && limite>0 && pResultado !=NULL)
    {
    	minimo=array[0];

    	for(i=1;i<limite;i++)
    	{
    		if(array[i]<minimo)
    		{
    			minimo=array[i];
    		}
    	}
        retorno=0;
    }
    *pResultado=minimo;

    return retorno;
}





