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

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
{
	int i;
	char texto[11];
	int saldoDelBanco=1;​
	fgets(texto,11,stdin);
	// me deshago del enter antes de usar la cadena
	if(texto[strlen(texto)-1]==10)
	texto[strlen(texto)-1] = 0;
	//*********************************************​
	//scanf("%s",texto);
	// validar que sean todos los caracteres numericos (del 0 al 9)
	if(validarQueSeaNumero(texto)==1)
	{
		saldoDelBanco = atoi(texto);
	}​
	printf("\ntenes %d pesos",saldoDelBanco);​
	return EXIT_SUCCESS;
}
