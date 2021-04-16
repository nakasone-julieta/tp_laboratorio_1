/*
 ============================================================================
 Name        : julietan_tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	float numeroA;
	float numeroB;
	float resultadoDivision;
	float resultadoMultiplicacion;
	float resultadoSuma;
	float resultadoResta;
	float resultadoFactorial;
	int respuestaMenu;
	int opcion;


	do{
		respuestaMenu = utn_getNumero(&opcion, "\nSELECCIONE UNA OPCION\n\n1. Ingresar 1er operando"
				"\n2. Ingresar 2do operando \n3. Calcular todas las operaciones \n4. Informar resultados \n5. Salir\n",
				"\nOpcion Invalida[1-5]", 1, 5, 1);
		if(!respuestaMenu) //respuesta negado es 1 (verdadero), se ingresó una respuesta válida
		{
			switch(opcion)
			{
			case 1:
				printf("\n INGRESAR NUMERO A");
				utn_getFlotante (&numeroA, "ingrese el primer número (puede ser positivo,negativo,decimal)",
											"ERROR. Por favor ingrese un dato válido entre -1000 y 1000", -1000, 1000, 3);
				break;
			case 2:
				printf("\n INGRESAR NUMERO B");
				utn_getFlotante(&numeroB, "ingrese el segundo número (puede ser positivo,negativo,decimal)",
								"ERROR. Por favor ingrese un dato válido entre -1000 y 1000",-1000, 1000, 3);
				break;
			case 3:
				printf("\n CALCULAMOS TODAS LAS OPERACIONES");
				printf("\n procesando....");

				printf("\n Cálculo de operaciones exitoso");
				break;
			case 4:
				printf("\n INFORMAMOS TODOS LOS RESULTADOS");

				if(utn_sumarFloat(&resultadoSuma, numeroA, numeroB)==0)
					printf("\nEl resultado de %.2f+%.2f es: %.2f", numeroA, numeroB, resultadoSuma);

				if (utn_restarFloat(&resultadoResta, numeroA, numeroB)==0)
					printf("\nEl resultado de %.2f-%.2f es: %.2f", numeroA, numeroB, resultadoResta);

				if (utn_dividirFloat(&resultadoDivision, numeroA, numeroB)==0)
					printf("\n El resultado de %.2f/%.2f es: %.2f",numeroA, numeroB, resultadoDivision);
				else if (utn_dividirFloat(&resultadoDivision, numeroA, numeroB)==-2)
					printf("\nno se puede dividir por un numero negativo numero negativo :(");

				if (utn_multiplicarFloat(&resultadoMultiplicacion, numeroA, numeroB)==0)
					printf("\nEl resultado de %.2f*%.2f es: %.2f", numeroA, numeroB, resultadoMultiplicacion);

				if (utn_factorialFloat(&resultadoFactorial, numeroA)==0)
					printf("\nEl factorial de %.2f es: %.2f", numeroA, resultadoFactorial);
				else if (utn_factorialFloat(&resultadoFactorial, numeroA)==-2)
					printf("\nno existe el factorial de %.2f porque es numero negativo :(", numeroA);
				else if (utn_factorialFloat(&resultadoFactorial, numeroA)==-2)
					printf("\nse calcula factorial solo para numeros enteros :(");


				if (utn_factorialFloat(&resultadoFactorial, numeroB)==0)
					printf("\nEl factorial de %.2f es: %.2f", numeroB, resultadoFactorial);
				else if (utn_factorialFloat(&resultadoFactorial, numeroB)==-2)
					printf("\nno existe el factorial de %.2f porque es numero negativo :(", numeroB);
				else if (utn_factorialFloat(&resultadoFactorial, numeroB)==-3)
					printf("\nse calcula factorial solo para numeros enteros :(");
				break;
			}
		}
	}while (opcion != 5);

	printf("usted ingresó los números %.2f y %.2f", numeroA, numeroB);

	return EXIT_SUCCESS;
}
