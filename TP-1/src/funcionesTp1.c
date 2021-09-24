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
	printf("3. Realizar operaciones:\n");
	if(flag1==0&&flag2==0)
		{
		printf(" a) Calcular la suma de A+B\n");
		printf(" b) Calcular la resta de A-B\n");
		printf(" c) Calcular la division de A/B \n");
		printf(" d) Calcular la multiplicacion de A*B\n");
		printf(" e) Calcular el factorial de (A!) y (B!)\n");
		}
		else
		{
			if(flag1>=1&&flag2==0)
			{
				printf(" a) Calcular la suma de %d+B\n",numeroUno);
				if(numeroUno<0){
				printf(" b) Calcular la resta de (%d)-B\n",numeroUno);
				}
				else{
					printf(" b) Calcular la resta de %d-B\n",numeroUno);
				}
				printf(" c) Calcular la division de %d/B\n",numeroUno);
				printf(" d) Calcular la multiplicacion de %d*B\n",numeroUno);
				printf(" e) Calcular el factorial de (%d!) y (B!)\n",numeroUno);

			}
			else
			{
				if(flag1==0&&flag2>=1)
				{
					if(numeroDos<0){
						printf(" a) Calcular la suma de A+(%d)\n",numeroDos);
					}
					else{
					printf(" a) Calcular la suma de A+%d\n",numeroDos);
					}

					if(numeroDos<0){
					printf(" b) Calcular la resta de A-(%d)\n",numeroDos);
					}
					else{
						printf(" b) Calcular la resta de A-%d\n",numeroDos);
					}
					printf(" c) Calcular la division de A/%d\n",numeroDos);
					printf(" d) Calcular la multiplicacion de A*%d\n",numeroDos);
					printf(" e) Calcular el factorial de (A!) y (%d!)\n",numeroDos);
				}
				else{
					if(numeroDos<0){
						printf(" a) Calcular la suma de %d+(%d)\n",numeroUno,numeroDos);
					}
					else{
					printf(" a) Calcular la suma de %d+%d\n",numeroUno,numeroDos);
					}

					if(numeroUno<0 && numeroDos<0)
					{
						printf(" b) Calcular la resta de (%d)-(%d)\n",numeroUno, numeroDos);
					}
					else
					{
						if(numeroUno<0)
						{
							printf(" b) Calcular la resta de (%d)-%d\n",numeroUno, numeroDos);
						}
						else{
							if(numeroDos<0)
							{
							printf(" b) Calcular la resta de %d-(%d)\n",numeroUno, numeroDos);
							}
							else
							{
								printf(" b) Calcular la resta de %d-%d\n",numeroUno, numeroDos);
							}
						}
					}
					printf(" c) Calcular la division de %d/%d\n",numeroUno,numeroDos);
					printf(" d) Calcular la multiplicacion de %d*%d\n",numeroUno,numeroDos);
					printf(" e) Calcular el factorial de (%d!) y (%d!)\n",numeroUno,numeroDos);
				}
			}
		}
	printf("4. Mostrar resultados.\n");
	printf("5. Salir.\n");
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
float divisionNumeros(int numeroUno, int numeroDos)
{

	float division;
	division = numeroUno / (float) numeroDos;
	return division;

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

