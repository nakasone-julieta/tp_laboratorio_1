/*
 ============================================================================
 Name        : repaso10-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 3-3 (ORDENAMIENTO)/////NAKASONE JULIETA
Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos).
Necesito generar un listado de los números positivos de manera
creciente y negativos de manera decreciente. (Como máximo 4 for)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>//siempre en linux
//__fpurge(stdin) para limpiar el buffer, antes de llamar al scanf
#include "utn.h" //para mis  bibliotecas usamos comillas. LO USAMOS EN EL C

/////////////////////////////////////////////////////////
#define PEDIR_NUM 6

int main(void)
{
	int numerosIngresados[PEDIR_NUM];//={-1,2,56,8,9,-10,-5,-3,5,9};

	int unNumeroIngresado;
	int i;

	for (i=0; i<PEDIR_NUM; i++) /// CARGO NUMEROS EN ARRAY lo puedo hacer una funcion??!?!?!?!?!
		{
			utn_getInt(&unNumeroIngresado, "ingrese un numero", "su numero no sirve [min-100, max100]", -100, 100, 2);

				numerosIngresados[i]=unNumeroIngresado;
		}
	printf("los numeros ingresados son: ");
	for (i=0; i<PEDIR_NUM; i++)
	{
		if(numerosIngresados[i]<0)
		{
			if(utn_arrayOrdenarDescendente(numerosIngresados, PEDIR_NUM)==0)
			{
				printf("%d", numerosIngresados);
			}
		}
		else if(numerosIngresados[i]>=0)
		{
			if(utn_ordenarArrayAscendente(numerosIngresados, PEDIR_NUM)==0);
			{
				printf("%d", numerosIngresados);
			}
		}
	}

	/*if(utn_arrayOrdenarAscendente(numerosIngresados, PEDIR_NUM)==0)
	{

		utn_imprimirArray(numerosIngresados, PEDIR_NUM);
	}*/


}
