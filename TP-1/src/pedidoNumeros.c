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
void factorialNumeros(int numeroUno, int numeroDos)
{
	int a, b;
	int factorialX = 1;
	int factorialZ = 1;
	if(numeroUno>1){
	for (a = numeroUno; a > 1; a--)
	{
		factorialX = factorialX * a;
	}
	}
	else
	{
		for (a = numeroUno; a < -1; a++)
		{
			factorialX = factorialX * a;
		}
	}
	if(numeroDos>1){
	for (b = numeroDos; b > 1; b--)
	{
		factorialZ = factorialZ * b;
	}
	}
	else
	{
		for (b = numeroDos; b < -1; b++)
		{
			factorialZ = factorialZ * b;
		}
	}

	printf("El factorial del numero %d es igual a %d, mientras que el del numero %d es igual a %d",numeroUno, factorialX, numeroDos, factorialZ);

}

