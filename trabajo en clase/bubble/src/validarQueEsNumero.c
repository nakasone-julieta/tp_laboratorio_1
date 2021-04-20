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

	char palabras[150];

	if(utn_getTexto(palabras, "palabra", "error",150, 1)==0)
	{
		printf("palabras: %s", palabras);
	}
}
