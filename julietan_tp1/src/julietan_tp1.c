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

	utn_getFloat(&numeroA, "ingrese el primer número (puede ser positivo,negativo,decimal)", "ERROR. Por favor ingrese un dato válido entre -1000 y 1000",-1000, 1000, 3);
	utn_getFloat(&numeroB, "ingrese el segundo número (puede ser positivo,negativo,decimal)", "ERROR. Por favor ingrese un dato válido entre -1000 y 1000",-1000, 1000, 3);


	if (utn_dividirFloat(&resultadoDivision, numeroA, numeroB)==0)
	{
		printf("\nEl resultado de %.2f/%.2f es: %.2f",numeroA, numeroB, resultadoDivision);
	}
	if (utn_multiplicarFloat(&resultadoMultiplicacion, numeroA, numeroB)==0)
	{
		printf("\nEl resultado de %.2f*%.2f es: %.2f", numeroA, numeroB, resultadoMultiplicacion);
	}
	if (utn_sumarFloat(&resultadoSuma, numeroA, numeroB)==0)
	{
		printf("\nEl resultado de %.2f+%.2f es: %.2f", numeroA, numeroB, resultadoSuma);
	}
	if (utn_restarFloat(&resultadoResta, numeroA, numeroB)==0)
	{
		printf("\nEl resultado de %.2f-%.2f es: %.2f", numeroA, numeroB, resultadoResta);
	}
	if (utn_factorialFloat(&resultadoFactorial, numeroA)==0)
	{
		printf("\nEl factorial de %.2f es: %.2f", numeroA, resultadoFactorial);
	}
	else if (utn_factorialFloat(&resultadoFactorial, numeroA)==-2)
	{
		printf("\nno existe el factoral de %.2f porque es numero negativo :(", numeroA);
	}

	if (utn_factorialFloat(&resultadoFactorial, numeroB)==0)
	{
		printf("\nEl factorial de %.2f es: %.2f", numeroB, resultadoFactorial);
	}
	else if (utn_factorialFloat(&resultadoFactorial, numeroB)==-2)
	{
		printf("\nno existe el factoral de %.2f porque es numero negativo :(", numeroB);
	}
}
