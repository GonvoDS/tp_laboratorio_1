#include "TP-1.h"

int menuCalculadora(int numeroUno, int numeroDos, int flag1, int flag2)
{
	int opcion;

	if(flag1==0&&flag2==0)
	{
		printf("\nNumero A = X\n");
		printf("Numero B = Y\n");
	}
	else
	{
		if(flag1>=1&&flag2==0)
		{
			printf("\nNumero A = %d.\n",numeroUno);
			printf("Numero B = Y\n");

		}
		else
		{
			if(flag1==0&&flag2>=1)
			{
						printf("\nNumero A = X\n");
						printf("Numero B = %d.\n",numeroDos);
			}
			else{
				printf("\nNumero A = %d.\n",numeroUno);
				printf("Numero B = %d.\n",numeroDos);
			}
		}
	}
	printf("Menu de opciones: ");
	printf("\n1. Ingresar primero operando.\n");
	printf("2. Ingresar segundo operando.\n");
	printf("3. Suma.\n");
	printf("4. Resta.\n");
	printf("5. Division.\n");
	printf("6. Multiplicacion.\n");
	printf("7. Factorial.\n");
	printf("8. Salir\n");
	printf("Elija opcion: ");
	scanf("%d", &opcion);

	return opcion;
}



int sumaNumeros(int numeroUno, int numeroDos)
{
	int suma;

	suma = numeroUno + numeroDos;
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
		printf("La division entre %d y %d es igual a: %.2f\n", numeroUno,
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

	if(numero>1)
	{
	for (a = numero; a > 1; a--)
	{
		factorial = factorial * a;
	}
	}

	return factorial;

}

