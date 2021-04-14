/*
 ============================================================================
 Name        : clase0413.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define QTY_PERSONAS 2

typedef struct
{
	float medida;
	float peso;
	char nombre[50];
}Persona;

int main(void)
{
	Persona arrayPersonas[QTY_PERSONAS]; //ahora tengo mi propio TIPO de variable, que corresponde al struct con todos sus elementos
	int i;

	for(i=0; i<QTY_PERSONAS; i++)
	{
		printf("ingrese medida:");
		scanf("%f", arrayPersonas[i].medida);
	}

	printf("el segundo ingresdo tiene los siguientes parametros: %s ",arrayPersonas[1]);


}
