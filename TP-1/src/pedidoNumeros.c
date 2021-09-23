#include "TP-1.h"


int sumaNumeros(int NumeroUno, int numeroDos)
{
	int suma;

	suma = NumeroUno + numeroDos;
	return suma;
}
int restaNumeros(int numeroUno, int numeroDos)
{

	int resta;

	resta = numeroUno - numeroDos;

	return resta;
}
void divisionNumeros(int numeroUno, int numeroDos)
{

	float division;

	if (numeroDos != 0)
	{
		division = numeroUno / (float) numeroDos;
		printf("La division entre %d y %d es igual a: %.2f", numeroUno,
				numeroDos, division);
	} else {
		printf("No es posible realizar una division por 0\n");
	}

	;
}

int multiplicacionNumeros(int numeroUno, int numeroDos)
{

	int multi;

	multi = numeroUno * numeroDos;

	return multi;
}
int factorialNumeros(int numero)
{
	int a;
	int factorial = 1;

	if(numero>1){
	for (a = numero; a > 1; a--)
	{
		factorial = factorial * a;
	}
	}
	else
	{
		for (a = numero; a < -1; a++)
		{
			factorial = factorial * a;
		}
	}

	return factorial;

}

