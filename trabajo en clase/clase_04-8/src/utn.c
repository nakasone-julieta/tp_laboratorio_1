

/*
 * utn.c
 *
 *  Created on: 25 mar. 2021
 *      Author: julieta_enee
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>//siempre en linux************
#include <string.h>
#include "utn.h"

static int esNumerica(char* cadena);

static int getInt (int* pResultado);
static int esNumerica(char* cadena);

static int getFloat (float* pResultado);
static int esFlotante(char* cadena);

static int getChar (char* pResultado);
static int esLetra(char* cadena);
static int getCharInt (char* pResultado);
static int esAlfaNumerico(char* cadena);
static int esTelefono(char* cadena);



/**
 * \brief 		Lee de archivo(stdin) hasta que encuentra un '\n' o hasta que haya copiado en cadena
 *  			un máximo de 'longitud -1' caracteres.
 * \param pCadena Puntero al espacio de memoria donde se copiará la cadena obtenida
 * \param len Define el tamaño de la cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena, sino -1(ERROR)
 * nota: se encarga de recibir un string
 */
int myGets(char* pCadena, int len)
{
	int retornoFuncion = -1;
	char bufferString[4096];//recibo como un string *********kk

	if(pCadena != NULL && len > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]== '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] ='\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<=len) //se se cumplieron los criterios y lo ingresado al buffer es menor a la longitud del array
			{
				strncpy(pCadena,bufferString,len);//copio lo cargado en el buffer, dentro del array
				retornoFuncion=0;

			}
		}
	}
	return retornoFuncion;
}


//////////////////////////////////////////////////NUMERO ENTERO
////////VALIDA NUMERO
/**
 *  \brief 		Verifica si la cadena ingresada es numérica, contempla su signo
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1(verdadero) si la cadena es numérica, y si no lo es retorna 0(FALSO)
 *
 */
static int esNumerica(char* cadena)
{
	int retorno=1;
	int i=0;
	if(cadena!=NULL && strlen(cadena)>0)
	{

		while (cadena[i] != '\0')//puedo usar un for porq tengo todos los elementos tmb
		{
			if (cadena[0]=='-'||cadena[0]=='+')
			{
				i=1;
			}

			if (cadena [i]<'0' || cadena[i]>'9')//si el elemento en i sale de los parametros como numero
			{
				retorno =0; //devuelvo falso
				break;
			}
			i++;
		}
		/*CUANDO QUIERO USAR ESTE CODIGO, ME TIRA ERROR EN LA FIRMA :(
													 * FIRMA:  static int esNumerica(char* cadena, int len )
													 * for(i=0; i<len && aCadena[i]!= '\0'; i++)
													{
														if (i==0 && (aCadena[i]=='-' || aCadena[i]=='+'))
														{
															continue; //vuelve a comenzar el for, se saltea el siguiente if
														}
														if(aCadena[i]>'9' || aCadena [i] <'0')
														{
															retornoVerdad = 0;
															break;//sale de la iteracion mas cercana
														}
													}*/
	}
	return retorno;
}

///////////////////////TRANSFORMA A NUMERO
/**
 *  \brief 		​ Verifica​ ​ si​ ​ la​ ​ cadena​ ingresada​ ​ es​ ​ numerica, si lo es, la trannsforma  a int
 *  \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función
 *  \return Retorna 0(EXITO) si se obtiene un numero entero, sino -1(ERROR)
 *  * NOTAS: incluye el uso de: esNumerica para verificar que todos los elementos sean numeros
 * 		   					 myGets para obtener datos ingresados por el usuario, de modo seguro, sin desbordar la variable en la que se escribe
 *
 */
static int getInt (int* pResultado)
{
	int retorno=-1;
	char bufferString[4096];

	if( pResultado != NULL &&
		myGets(bufferString, sizeof(bufferString))==0 &&
		esNumerica(bufferString))//esNumerica(bufferString)==1 es verdadero :)
	{
			retorno = 0;
			*pResultado = atoi(bufferString);
	}


	return retorno;
}


//////////////////PIDE UN NUMERO
/**
 * \brief		Solicita al usuario el ingreso de un número entero, lo valida, lo verifica
 * 				y devuelve el resultado
 * \param char pMensaje: puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * \param char pMensajeError: puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido
 * \param int min:Valor mínimo admitido (inclusive)
 * \param int max: Valor máximo admitido (inclusive)
 * \param int reintentos: cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
 * \param retorna 0 si se obtuvo el numero, sino -1
 *
 */
int utn_getNumero (int* pNumero, char* pMensaje, char* pMensajeError, char min, char max, int reintentos)
{
	int retornoFuncion = -1;
	int bufferInt;

	if (pNumero != NULL && pMensaje != NULL && pMensajeError != NULL && min <= max && reintentos >= 0 )
	{
		do
		{
			printf ("%s", pMensaje);
			__fpurge(stdin);
			if( getInt(&bufferInt)==0 &&
				bufferInt>= min  &&
				bufferInt<= max)
			{
				*pNumero = bufferInt;
				retornoFuncion =0;
				break;
			}
			printf ("%s", pMensajeError);
			reintentos --;
		}while(reintentos >=0);
	}
	return retornoFuncion;
}


/////////////////////////////////////////////////////////NUMERO FLOTANTE
/////////////VALIDA QUE ES FLOTANTE
/**
 *  \brief 		Verifica si la cadena ingresada es numérica flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1(verdadero) si la cadena es flotante, y si no lo es retorna 0(FALSO)
 *
 */
static int esFlotante(char* cadena)
{
	int retorno=1;
	int i=0;
	int contadorPuntos=0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0; cadena [i] != '\0'; i++)
		{
			if(i==0 && (cadena[i]== '-' || cadena[i]== '+'))
			{
				continue;
			}
			if(cadena [i] < '0' || cadena [i] > '9')
			{
				if(cadena[i] == '.' && contadorPuntos ==0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno=0;
					break;
				}

			}
		}
	}
	return retorno;
}

/////////////////////////TRANSFORMA A FLOTANTE
/**
 *  \brief 		​ Verifica​ ​ si​ ​ la​ ​ cadena​ ingresada​ ​ es​ ​ flotante, si lo es, la transforma a float
 *  \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función
 *  \return Retorna 0(EXITO) si se obtiene un numero flotante, sino -1(ERROR)
 *
 */
static int getFloat (float* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esFlotante(buffer))
		{
			retorno = 0;
			*pResultado = atof(buffer);
		}
	}


	return retorno;
}
///////////////////////SOLICITA UN FLOTANTE
/**
 * \brief		Solicita al usuario el ingreso de un número flotante, luego de verificarlo devuelve el resultado
 * * \param char pMensaje: puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * \param char pMensajeError: puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido
 * \param int min:Valor mínimo admitido (inclusive)
 * \param int max: Valor máximo admitido (inclusive)
 * \param int reintentos: cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
 * \param retorna 0 si se obtuvo el numero, sino -1
 *
 */
int utn_getFlotante (float* pNumFloat, char* pMensaje, char* pMensajeError, float min, float max, int reintentos)
{
	int retornoFuncion = -1;
	float bufferFloat;
	if (pNumFloat != NULL && pMensaje != NULL && pMensajeError != NULL && min <= max && reintentos >= 0 )
	{
		do
		{
			printf ("%s", pMensaje);
			__fpurge(stdin);

			if (getFloat(&bufferFloat)==0 && bufferFloat>= min  && bufferFloat<= max)
			{
				*pNumFloat = bufferFloat;
				retornoFuncion =0;
				break;
			}
			printf ("%s", pMensajeError);
			reintentos --;
		}while(reintentos >=0);
	}
	return retornoFuncion;
}



/////////////////////////////////////////////////////////ALFABETICA
/////////////VALIDA QUE SON LETRAS
/**
 *  \brief 		Verifica si la cadena ingresada son letras
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1(verdadero) si la cadena es flotante, y si no lo es retorna 0(FALSO)
 *
 */
static int esLetra(char* cadena)
{
	int retorno=1;
	int i=0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0; cadena [i] != '\0'; i++)
		{
			printf("no es letra %s",*cadena);
			if(cadena[i]!= ' ' && (cadena[i] < 'a' || cadena[i] > 'z')&& (cadena[i] < 'A' || cadena[i] > 'Z'))
				{
					printf("no es letra %s",*cadena);
					retorno = 0;
				}
		}
	}
	return retorno;
}

/////////////VALIDA QUE SON LETRAS y NUmeros
/**
 *  \brief 		Verifica si la cadena ingresada son letras y numeros
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1(verdadero) si la cadena es flotante, y si no lo es retorna 0(FALSO)
 *
 */
static int esAlfaNumerico(char* cadena)
{
	int retorno=1;
	int i=0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0; cadena [i] != '\0'; i++)
		{
			if(cadena[i]!= ' ' && (cadena[i] < 'a' || cadena[i] > 'z')&& (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9'))
				retorno = 0;
		}
	}
	return retorno;
}

/////////////VALIDA QUE SON numers y 1 '-'
/**
 *  \brief 		Verifica si la cadena ingresada cuenta con caracteristicas de telefono
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1(verdadero) si la cadena es flotante, y si no lo es retorna 0(FALSO)
 *
 */
static int esTelefono(char* cadena)
{
	int retorno=1;
	int i=0;
	int contadorGuion=0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0; cadena [i] != '\0'; i++)
		{
			if((cadena[i]!= ' ') && (cadena[i] != '-') && (cadena[i] < '0' || cadena[i] > '9'))
				retorno = 0;
			if(cadena[i]!= '-')
				contadorGuion++;
		}
		if(contadorGuion==1)
			retorno = 1;
	}
	return retorno;
}

/////////////VALIDA QUE SON numers y 2 '-'
/**
 *  \brief 		Verifica si la cadena ingresada cuenta con caracteristicas de telefono
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1(verdadero) si la cadena es flotante, y si no lo es retorna 0(FALSO)
 *
 */
static int esCelular(char* cadena)
{
	int retorno=1;
	int i=0;
	int contadorGuion=0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0; cadena [i] != '\0'; i++)
		{
			if((cadena[i]!= ' ') && (cadena[i] != '-') && (cadena[i] < '0' || cadena[i] > '9'))
				retorno = 0;
			if(cadena[i]!= '-')
				contadorGuion++;
		}
		if(contadorGuion==2)
			retorno = 1;
	}
	return retorno;
}

/////////////////////////COPIA LETRAS / caracteres
/**
 *  \brief 		​ Verifica​ ​ si​ ​ la​ ​ cadena​ ingresada​ ​ es​ ​ de letras, si lo es, lo copia para pasarlo como resultado
 *  \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función
 *  \return Retorna 0(EXITO) si se obtiene un numero flotante, sino -1(ERROR)
 *
 */
static int getChar (char* pResultado)
{
	int retorno=-1;
	char buffer[2096];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esLetra(buffer))
		{
			retorno = 0;
			strncpy(pResultado, buffer, sizeof(pResultado));
			printf("puntero: %s", pResultado);
			printf("puntero: %s", buffer);

		}
	}
	return retorno;
}

/**
 *  \brief 		​ Verifica​ ​ si​ ​ la​ ​ cadena​ ingresada​ ​ es​ ​ de LETRAS Y NUMEROS, si lo es, lo copia para pasarlo como resultado
 *  \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función
 *  \return Retorna 0(EXITO) si se obtiene un numero flotante, sino -1(ERROR)
 *
 */
static int getCharInt (char* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esAlfaNumerico(buffer))
		{
			retorno = 0;
			strcpy(*pResultado, buffer);
		}
	}
	return retorno;
}

/**
 *  \brief 		​ Verifica​ ​ si​ ​ la​ ​ cadena​ ingresada​ ​ es​ ​ de NUMEROS y 1 gui, si lo es, lo copia para pasarlo como resultado
 *  \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función
 *  \return Retorna 0(EXITO) si se obtiene un numero flotante, sino -1(ERROR)
 *
 */
static int getTelefono (char* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esTelefono(buffer))
		{
			retorno = 0;
			strcpy(*pResultado, buffer);
		}
	}
	return retorno;
}


///////////////////////SOLICITA CARACTERES
/**
 * \brief		Solicita al usuario el ingreso de letras, luego de verificarlo devuelve el resultado
 * * \param char pMensaje: puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * \param char pMensajeError: puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido
 * \param int min:Valor mínimo admitido (inclusive)
 * \param int max: Valor máximo admitido (inclusive)
 * \param int reintentos: cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
 * \param retorna 0 si se obtuvo el numero, sino -1
 *
 */
int utn_getTexto (char* pCaracter, char* pMensaje, char* pMensajeError, int len, int reintentos)
{
	int retornoFuncion = -1;
	char bufferChar[4096];
	if (pCaracter != NULL && pMensaje != NULL && pMensajeError != NULL && len >0 && reintentos >= 0 )
	{
		do
		{
			printf ("%s", pMensaje);
			__fpurge(stdin);

			//if (getChar(&bufferChar)==0 && bufferChar<= len)
			//{
				//strncpy(*pCaracter, bufferChar,sizeof(pCaracter));
				//retornoFuncion =0;
				//break;
			//}
			printf ("%s", pMensajeError);
			reintentos --;
		}while(reintentos >=0);
	}
	return retornoFuncion;
}

/**
 * \brief		Solicita al usuario el ingreso de letras y numeros, luego de verificarlo devuelve el resultado
 * * \param char pMensaje: puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * \param char pMensajeError: puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido
 * \param int min:Valor mínimo admitido (inclusive)
 * \param int max: Valor máximo admitido (inclusive)
 * \param int reintentos: cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
 * \param retorna 0 si se obtuvo el numero, sino -1
 *
 */
int utn_getAlfanumerica (char* pCaracter, char* pMensaje, char* pMensajeError, int len, int reintentos)
{
	int retornoFuncion = -1;
	char bufferChar;
	if (pCaracter != NULL && pMensaje != NULL && pMensajeError != NULL && len >0 && reintentos >= 0 )
	{
		do
		{
			printf ("%s", pMensaje);
			__fpurge(stdin);

			if (getCharInt(&bufferChar)==0 && bufferChar<= len)
			{
				strcpy(*pCaracter, bufferChar);
				retornoFuncion =0;
				break;
			}
			printf ("%s", pMensajeError);
			reintentos --;
		}while(reintentos >=0);
	}
	return retornoFuncion;
}

/**
 * \brief		Solicita al usuario el ingreso de letras y numeros, luego de verificarlo devuelve el resultado
 * * \param char pMensaje: puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * \param char pMensajeError: puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido
 * \param int min:Valor mínimo admitido (inclusive)
 * \param int max: Valor máximo admitido (inclusive)
 * \param int reintentos: cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
 * \param retorna 0 si se obtuvo el numero, sino -1
 *
 */
int utn_getTelefono (char* pCaracter, char* pMensaje, char* pMensajeError, int len, int reintentos)
{
	int retornoFuncion = -1;
	char bufferChar;
	if (pCaracter != NULL && pMensaje != NULL && pMensajeError != NULL && len >0 && reintentos >= 0 )
	{
		do
		{
			printf ("%s", pMensaje);
			__fpurge(stdin);

			if (getCharInt(&bufferChar)==0 && bufferChar<= len)
			{
				strcpy(*pCaracter, bufferChar);
				retornoFuncion =0;
				break;
			}
			printf ("%s", pMensajeError);
			reintentos --;
		}while(reintentos >=0);
	}
	return retornoFuncion;
}











/////////////////////////////////////////////////////////Funciones para array
/**
 * \brief	imprime un array de flotantes
 * \param float pArray Puntero al array
 * \param int len Define el tamaño del array
 * \return Retorna 0 (EXITO) y -1(ERRORI
 *
 */
int utn_imprimirArrayFlotante(float* pArray, int len)
{
	int retornoFuncion = -1;
	int i;
	if (pArray != NULL && len>0)
	{
		retornoFuncion = 0;
		for (i=0; i<len; i++)
		{
			printf("\nIndice:  [%d] - Posicion Usuario: [%d] - Valor:%.2f", i,i+1, pArray[i]);//posicion del usuario :sin contar 0
		}
	}

	return retornoFuncion;
}

/**
 * \brief	inicializa un array de flotantes
 * \param float pArray Puntero al array
 * \param int len Define el tamaño del array
 * \return Retorna 0 (EXITO) y -1(ERROR)
 *
 */
int utn_initArrayFlotante(float* pArray, int len, float valorInicial)
{
	int retornoFuncion = -1;
	int i;
	if (pArray != NULL && len>0)
	{
		retornoFuncion = 0;
		for (i=0; i<len; i++)
		{
			pArray[i] = valorInicial;
		}
	}

	return retornoFuncion;
}



/*---------int---------*/

/**
 * \brief	identifica el menor número dentro de un array Int
 * \param int pResultado Puntero al espacio de memoria donde se escribirá el resultado de la operación
 * \param int array[] Apunta a la direccion de memoria del primer elemento del array
 * \param int len Define el tamaño del array
 * \return Retorna 0 (EXITO) y -1(ERROR)
 *
 */
int utn_buscarMinimoArrayInt (int* pResultado, int array[],int limite)
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

/**
 * \brief	identifica el indice del menor número dentro de un array Int
 * \param int pResultadoIndice Puntero al espacio de memoria donde se escribirá el resultado de la función
 * \param int array[] Apunta a la direccion de memoria del primer elemento del array
 * \param int len Define el tamaño del array
 * \return Retorna 0 (EXITO) y -1(ERROR)
 *
 */
int utn_buscarIndiceDelMinimoArrayInt (int* pResultadoIndice, int* pArray,int limite)
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
    			retorno=0;
    		}
    	}
    }
    *pResultadoIndice=indiceDeMinimo;

    return retorno;
}


/**
 * \brief	identifica el mayor número dentro de un array Int
 * \param int pResultado Puntero al espacio de memoria donde se escribirá el resultado de la operación
 * \param int array[] Apunta a la direccion de memoria del primer elemento del array
 * \param int len Define el tamaño del array
 * \return Retorna 0 (EXITO) y -1(ERROR)
 *
 */
int utn_buscarMaximoArrayInt (int* pResultado, int* pArray,int limite)
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


/**
 * \brief	imprime un array de eneteros
 * \param int pArray Puntero al array
 * \param int len Define el tamaño del array
 * \return Retorna 0 (EXITO) y -1(ERRORI
 *
 */
int utn_imprimirArrayInt(int* pArray, int len)
{
	int retornoFuncion = -1;
	int i;
	if (pArray != NULL && len>0)
	{
		retornoFuncion = 0;
		for (i=0; i<len; i++)
		{
			printf("\nIndice:  [%d] - Posicion Usuario: [%d] - Valor:%d", i,i+1, pArray[i]);//posicion del usuario :sin contar 0
		}
	}

	return retornoFuncion;
}


/**
 * \brief	Solicita numeros enteros para cargarlos secuencialmente en el array
 * \param int pArray Puntero al array
 * \param int len Define el tamaño del array
 * \return Retorna 0 (EXITO) y -1(ERROR)
 *
 */
int utn_cargarArrayIntSecuencial(int* pArray, int len)
{
	int retornoFuncion= -1;
	int i;
	if(pArray != NULL && len > 0)
	{
		retornoFuncion = 0;
		for(i=0; i<len; i++)
		{
			if(utn_getNumero(&pArray[i],"\nIngrese un valor", "ERROR fuera de rango", -100, 100, 2)==-1)
			{
				retornoFuncion=-1;
				break;
			}
		}

	}
	return retornoFuncion;
}


/**
 * \brief	Borra los numeros impares dentro de un Array int
 * \param int pArray Puntero al array
 * \param int len Define el tamaño del array
 * \return Retorna 0 (EXITO) y -1(ERROR)
 *
 */
int utn_borrarImparesArrayInt(int* pArray, int len)
{
	int retornoFuncion= -1;
	int i;
	if(pArray != NULL && len > 0)
	{

		for(i=0; i<len; i++)
		{
			if((pArray[i]%2)!=0)
			{
				pArray[i]=0;
			}
		}
		retornoFuncion = 0;
	}
	return retornoFuncion;
}

/**
 * \brief	Calcula el promedio de un array de enteros y devuelve el resultado
 * \param float pResultado Puntero a la dirección de memoria de la variable que alojará el valor resultante de la operación
 * \param int pArray Puntero al array
 * \param int len Define el tamaño del array
 * \return Retorna 0 (EXITO) y -1(ERROR)
 *
 */
int utn_promediarArrayInt(float* pResultado, int array[], int len)//calcular promedio de los valores de Array
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


/**
 * \brief	Ordena un array de enteros de menor a mayor
 * \param float pArray Puntero al array
 * \param int len Define el tamaño del array
 * \return Retorna 0 (EXITO) y -1(ERROR)
 *
 */
int utn_ordenarArrayInt(int* pArray, int len)
{
	int retornoFuncion = -1;
	int i;
	int flagSwap;
	int bufferInt;
	if (pArray != NULL && len>0)
	{
		do
		{
			flagSwap=0;
			len--;
			for(i=0; i<len;i++)
			{
				if(pArray[i]>pArray[i+1])
				{
					bufferInt = pArray[i];
					pArray[i]= pArray[i+1];
					pArray[i+1] = bufferInt;
					flagSwap=1;
				}
			}
		}while(flagSwap);

		retornoFuncion = 0;
	}

	return retornoFuncion;
}

/*---------char---------*/
/**
 * \brief 		Cuenta la cantidad de palabras en un array de char
 * \param pResultado int Puntero a la dirección de memoria de la variable donde se aloja la cuenta de palabras
 * \param pCadena char Puntero al espacio de memoria donde se copiará la cadena obtenida
 * \param len int Define el tamaño de la cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena, sino -1(ERROR)
 *
 */
int utn_contarPalabras(int* pResultado, char* pCadena,int len)
{
	int retornoFuncion =-1;
	int contadorEspacios = 0;
	int i;
	if(pResultado!= NULL && pCadena != NULL && len > 0)
	{
		retornoFuncion =0;
		for(i=0;i<len && pCadena[i] != '\0'; i++)
		{
			if(pCadena[i] == ' ')
			{
				contadorEspacios++;
			}
		}
		*pResultado=contadorEspacios+1;
	}
	return retornoFuncion;
}

///////////////////////////////operaciones matematicas

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
int utn_factorialFloat(float* pResultado, float numero)
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
