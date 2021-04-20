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
	//char texto[]="las medidas de aislamiento bla bla";
	if(utn_getNumero(&palabras, "numero", "error", 0, 10, 1)==0)
	{
		printf("palabras: %d", palabras);
	}

}


