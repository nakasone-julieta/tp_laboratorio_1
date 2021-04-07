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
	int numeroA;
	char signo;
	int numeroB;
	int retornoFuncion;
	float resultado;

	utn_getInt(&numeroA, "ingrese el primer número", "ERROR. Por favor ingrese un dato válido entre -100 y 100",
			-100, 100, 3);
	utn_getInt(&numeroA, "ingrese el segundo número", "ERROR. Por favor ingrese un dato válido entre -100 y 100",
			-100, 100, 3);
	utn_getChar(&signo, "ingrese el signo de la operación que desea realizar [* / - + %]",
			"ERROR. Por favor ingresar un signo válido", , , );
	if (signo != '*' && signo !='/' && signo != '-' && signo != '+')
	{
		printf("ERROR. Por favor ingresar un signo válido");
		utn_getChar(&signo, "ingrese el signo de la operación que desea realizar [* / - + %]",
				"ERROR. Por favor ingresar un signo válido", , , );
	}
	utn_getInt(&numeroB, "ingrese el segundo número", "ERROR. Por favor ingrese un dato válido entre -100 y 100",
			-100, 100, 3);


	switch (signo)
		{
			case '/':
				retornoFuncion = dividir (&resultado, numeroA, numeroB);
				break;
			case '*':
				retornoFuncion = multiplicar (&resultado, numeroA, numeroB);
				break;
			case '+':
				retornoFuncion = sumar (&resultado, numeroA, numeroB);
				break;
			case '-':
				retornoFuncion = restar (&resultado, numeroA, numeroB);
				break;
		}
		if (retornoFuncion == 0)
		{
			printf("la operacion ha sido exitosa, \n el resultado de %d %c %d es %.2f",numeroA,signo,numeroB, resultado);
		}
		else
		{
			printf ("la operación no se realizó, se ha encontrado un error");
		}


}
