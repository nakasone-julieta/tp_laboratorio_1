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
		respuestaMenu = utn_getNumero(&opcion, "\nSELECCIONE UNA OPCION\n1. Ingresar 1er operando"
				"\n2. Ingresar 2do operando \n3. Calcular todas las operaciones \n4. Informar resultados \n5. Salir\n",
				"\nOpcion Invalida[1-5]", 1, 5, 1);
		if(!respuestaMenu) //respuesta negado es 1 (verdadero), se ingresó una respuesta válida
		{
			switch(opcion)
			{
			case 1:
				printf("\nINGRESAR NUMERO A");
				utn_getFlotante (&numeroA, "ingrese el primer número (puede ser positivo,negativo,decimal):\n",
											"ERROR. Por favor ingrese un dato válido entre -1000 y 1000", -1000, 1000, 3);
				break;
			case 2:
				printf("\n INGRESAR NUMERO B");
				utn_getFlotante(&numeroB, "ingrese el segundo número (puede ser positivo,negativo,decimal)",
								"ERROR. Por favor ingrese un dato válido entre -1000 y 1000",-1000, 1000, 3);
				break;
			case 3:
				printf("\n*****************************************");
				printf("\nCALCULAMOS TODAS LAS OPERACIONES");
				printf("\nprocesando....");
				utn_sumarFloat(&resultadoSuma, numeroA, numeroB);
				utn_restarFloat(&resultadoResta, numeroA, numeroB);
				utn_dividirFloat(&resultadoDivision, numeroA, numeroB);
				utn_multiplicarFloat(&resultadoMultiplicacion, numeroA, numeroB);
				utn_factorialFloat(&resultadoFactorial, numeroA);
				utn_factorialFloat(&resultadoFactorial, numeroB);
				printf("\nCálculo de operaciones exitoso\n\n");
				printf("\n*****************************************");
				break;
			case 4:
				printf("\n INFORMAMOS TODOS LOS RESULTADOS");

				printf("\na)El resultado de %.2f+%.2f es: %.2f\n", numeroA, numeroB, resultadoSuma);
				printf("\nb)El resultado de %.2f-%.2f es: %.2f\n", numeroA, numeroB, resultadoResta);

				if (utn_dividirFloat(&resultadoDivision, numeroA, numeroB)==0)
					printf("\nc)nEl resultado de %.2f/%.2f es: %.2f\n",numeroA, numeroB, resultadoDivision);
				else if (utn_dividirFloat(&resultadoDivision, numeroA, numeroB)==-2)
					printf("\nc)no se puede dividir por 0:(\n");

				printf("\nd)El resultado de %.2f*%.2f es: %.2f\n", numeroA, numeroB, resultadoMultiplicacion);

				if (utn_factorialFloat(&resultadoFactorial, numeroA)==0)
					printf("\ne)El factorial de %.2f es: %.2f\n", numeroA, resultadoFactorial);
				else if (utn_factorialFloat(&resultadoFactorial, numeroA)==-2)
					printf("\ne)no existe el factorial de %.2f porque es numero negativo :(\n", numeroA);
				else if (utn_factorialFloat(&resultadoFactorial, numeroA)==-2)
					printf("\ne)se calcula factorial solo para numeros enteros :(\n");

				if (utn_factorialFloat(&resultadoFactorial, numeroB)==0)
					printf("\nf)El factorial de %.2f es: %.2f\n", numeroB, resultadoFactorial);
				else if (utn_factorialFloat(&resultadoFactorial, numeroB)==-2)
					printf("\nf)no existe el factorial de %.2f porque es numero negativo :(\n", numeroB);
				else if (utn_factorialFloat(&resultadoFactorial, numeroB)==-3)
					printf("\nf)se calcula factorial solo para numeros enteros :(\n\n");
				break;
			}
		}
	}while (opcion != 5);
	printf("\n*****************************************");
	printf("usted ingresó los números %.2f y %.2f", numeroA, numeroB);
	printf("\nSaliendo");
	printf("\n*****************************************");

	return EXIT_SUCCESS;
}
