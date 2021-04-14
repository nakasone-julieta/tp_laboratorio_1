/*
 ============================================================================
 Name        : validarqueseanumero.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void)
{
	int unNumero=1;
	utn_getNumero(&unNumero, "\ningresa algo", "\neso no vale, un numero?", 0, 10, 2);
	printf("su numero es %d", unNumero);
}
/*{
	char texto[11];
	int saldo=1;//saldo del banco


	printf("escriba algo");
	fgets(texto, 11, stdin);//​el ultimo parametro es desde donde lee; en este caso es mi propio programa de main
	if(texto[strlen(texto)-1]==10)
	{
		texto[strlen(texto)-1]=0;
	}

	if(utn_validarQueSeaNumero(texto)==1)//validar que sean todos los caracteres numericos(del 0 al 9)
	{

		saldo = atoi(texto);


	}
	printf("\n tenes %d pesos en el banco", saldo);



}*/


