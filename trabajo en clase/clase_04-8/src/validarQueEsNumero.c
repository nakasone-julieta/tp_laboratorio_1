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
	int palabras;
	char texto[]="las medidas de aislamiento bla bla";

	if(utn_contarPalabras(&palabras, texto, sizeof(texto))==0)
	{
		printf("el txt contiene: %d palabras", palabras);
	}

}


