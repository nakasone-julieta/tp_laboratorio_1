/*
 * utn2.c
 *
 *  Created on: 15 abr. 2021
 *      Author: julieta_enee
 */



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
/**
 * \brief		Solicita al usuario el ingreso de un caracter
 * \param char pMensaje: puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * \param char pMensajeError: puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido
 * \param int min:Valor mínimo admitido (inclusive)
 * \param int max: Valor máximo admitido (inclusive)
 * \param int reintentos: cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
 * \param retorna 0 si se obtuvo el numero, sino -1
 *
 */
int utn_getChar (char* pCaracter, char* pMensaje, char* pMensajeError, char min, char max, int reintentos)
{
	int retornoFuncion = -1;
	__fpurge(stdin);
	char bufferChar;
	if (pCaracter != NULL && pMensaje != NULL && pMensajeError != NULL && min <= max && reintentos >= 0 )
	{
		do
		{
			printf ("%s", pMensaje);
			__fpurge(stdin);
			scanf("%c",&bufferChar);

			if (bufferChar>= min  && bufferChar<= max)
			{
				*pCaracter = bufferChar;
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
 * \brief		Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de 'longitud - 1'
 * 				caracteres.
 * \param char pCadena: Puntero al espacio de memoria donde se copiará la cadea obtenida
 * \param int longitud: define el tamaño de cadena
 * \return Retorna 0(EXITO) si se obtiene una cadena. Sino se obtiene -1(ERROR)
 *
 */
static int myGets(char* pCadena, int longitud)
{
	int retorno= -1;
	if (pCadena != NULL && longitud >0 && fgets(pCadena, longitud, stdin)==pCadena)
	{
		__fpurge(stdin);
		if (pCadena [strlen(pCadena)-1]=='\n')
		{
			pCadena  [strlen(pCadena)-1]= 0;
		}
		retorno=0;
	}
	return retorno;
}


/**
 * \brief		Verifica si la cadena ingresada es numérica
 * \param int pResultado: Puntero al espacio de memoria donde se dejará el resultado de la función
 * \return Retorna 0(EXITO)si se obtiene un numero entero. Sino, -1(ERROR)
 *
 */
static int getInt(int* pResultado)
{
	int ret= -1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esNumerica(buffer))
		{
			*pResultado =atoi(buffer);
			ret= 0;
		}
	}

	return ret;
}

/**
 * \brief		Verifica si la cadena ingresada es numerica
 * \param char pCadena: cadena de caracteres a ser analizada (si es un puntero, no tendrìa que ser una variable, para analizar el contenido??)p15
 * \return Retorna 0(EXITO)si se obtiene un numero entero. Sino, -1(ERROR)
 *
 */
static int esNumerica(char* pCadena)
{
	int i=0;
	int retorno =1;
	if(pCadena != NULL && strlen(pCadena)>0)
	{
		while(pCadena[i]!='\0')
		{
			if (pCadena[i]<'0' || pCadena[i]>'9')
			{
				retorno =0;
				break;
			}
			i++;
		}
	}
	return retorno;
}




/**
 * \brief	Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param int pResultado: puntero al espacio de memoria donde se escribirá el valor ingresado en el caso de ser correcto
 * \param char pMensaje: puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * \param char pMensajeError: puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido
 * \param int min:Valor mínimo admitido (inclusive)
 * \param int max: Valor máximo admitido (inclusive)
 * \param int reintentos: cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
 * \param retorna 0 si se obtuvo el numero, sino -1
 *
 */
int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int min, int max, int reintentos)
{
	int retornoFuncion;
	int numero;
	//if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && min <= max && reintentos >= 0 )
		//{
			do
			{
				printf(pMensaje);
				__fpurge(stdin);
				if(getInt(&numero)==1)
				{
					if(numero<=max && numero>=min)
					{
						break;
					}
				}

				reintentos --;
				printf(pMensajeError);
			}while(reintentos>=0);
			if(reintentos==0)
			{
				retornoFuncion=-1;
			}
			else
			{
				retornoFuncion=0;
				*pResultado=numero;
			}
	//	}
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

int utn_imprimirArrayChar(int array[],int len)//no anda :(
{
	int retornoFuncion =-1;
	int i;
	if(array !=NULL && len >0)
	{
		for(i=0; i<len; i++)
		{
			printf("%c",array[i]);
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

int utn_validarQueSeaNumero(char* texto)
{
	int retorno=-1;
	int i=0;

	if(texto!=NULL)
	{
		retorno=1; // sopongo que esta ok

		while(texto[i]!='\0')
		{
			if(texto[i]<'0'|| texto[i]>'9')
			{
				retorno=-2; // HAY UN ERROR
				break; //dejo de leer (dejo de iterar)
			}
			i++;
		}
	}
	return retorno;
}


