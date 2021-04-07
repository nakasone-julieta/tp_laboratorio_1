/*
 ============================================================================
 Name        : bubble.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
/**************************FALTA ARREGLAR*********************************/


int main(void)
{
	int array[5]={8,25,-1,3,9};
	int aux;
	int i;
	int flagSwipeo=0;

	do
	{
		if (array[i] < array[i+1])
		{
			//hago el swap. si lo tengo como funcion, qué parámetros levantaría?
			aux = array[i];
			array [i]= array [i+1];
			array[i+1]=aux;
			flagSwipeo=1;
		}
	} while(flagSwipeo==1);



}
//int swap (int* array,)
