/*
 ============================================================================
 Name        : utn-funciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>//siempre en linux
//__fpurge(stdin) para limpiar el buffer, antes de llamar al scanf
#include "utn.h" //para mis  bibliotecas usamos comillas. LO USAMOS EN EL C

/******************************************************/

#define EDADES_SIZE 2

int main(void)
{
	int edad;
	int edades[EDADES_SIZE];
	int i;

	for(i=0; i<EDADES_SIZE; i++)
	{
		if (utn_getInt(&edad, "ingrese edad:", "ingrese un valor correcto\n", 0, 110, 3)==0)
		{
			edades[i] = edad;
		}
		else
		{
			printf("Usted no está ingresando un valor correcto en la edad\n");
		}
	}
	utn_imprimirArray(edades, EDADES_SIZE);
}







