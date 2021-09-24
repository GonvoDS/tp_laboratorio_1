#include "TP-1.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int numUno;
	int numDos;
	int factUno;
	int factDos;
	int suma;
	int resta;
	float dividir;
	int multi;
	int flag1=0;
	int flag2=0;
	int flag3=0;

	do
	{
		system("cls");
		opcion=menuCalculadora(numUno,numDos,flag1,flag2);

		switch (opcion) {
		case 1:
			if(flag1==0){
			printf("Ingrese el primer operando a cargar: ");
			scanf("%d", &numUno);
			flag1++;
			}
			else
			{
				printf("Reingrese el primer operando a cargar (Recuerde volver a realizar las operaciones en caso de cambiar algun operando): ");
				scanf("%d", &numUno);
			}
			break;
		case 2:
			if(flag2==0){
			printf("Ingrese el segundo operando a cargar: ");
			scanf("%d", &numDos);
			flag2++;
			}
			else
			{
				printf("Reingrese el segundo operando a cargar (Recuerde volver a realizar las operaciones en caso de cambiar algun operando): ");
				scanf("%d", &numDos);
			}
			break;
		case 3:
			if(flag1==0 ||flag2==0){
				printf("Por favor ingrese los dos operandos antes de realizar las operaciones.\n");
			}
			else
			{
			suma = sumaNumeros(numUno, numDos);
			resta = restaNumeros(numUno,numDos);
			if(numDos!=0)
			{
				dividir=divisionNumeros(numUno, numDos);
			}
			multi=multiplicacionNumeros(numUno,numDos);
			factUno=factorialNumeros(numUno);
			factDos=factorialNumeros(numDos);
			flag3++;
			}
			break;
		case 4:
			if(flag3==0)
			{
				printf("Por favor realice el calculo de operaciones primero.\n");
			}
			else
			{
				printf("a) La suma de %d y %d es igual a: %d\n",numUno,numDos, suma);
				printf("b) La resta de %d y %d es igual a: %d\n",numUno,numDos, resta);
				if(numDos==0){
					printf("c) No se pueden realizar divisiones por 0.\n");
				}else
				{
				printf("c) La division entre %d y %d es igual a: %.2f\n", numUno,numDos, dividir);
				}
				printf("d) La multiplicacion de %d y %d es igual a: %d\n",numUno,numDos, multi);
				if(numUno<0 && numDos<0){
								printf("e) No es posible realizar el factorial de numeros negativos. \n");
							}
							else{
								if(numUno<0 && numDos>0){
									printf("e) El factorial del numero %d no es posile de realizar por ser negativo mientras que el de %d es %d\n",numUno, numDos, factDos);
								}
								else
								{
									if(numUno>0 && numDos<0)
									{
										printf("e) El factorial del numero %d es %d mientras que el de %d no es posile de realizar por ser negativo.\n",numUno, factUno, numDos);
									}
									else{
										printf("e) El factorial del numero %d es igual a %d, mientras que el de %d es %d\n",numUno,factUno, numDos, factDos);
									}
								}
							}
			}

			break;
		case 5:
			printf("Hasta luego!\n");
			opcion=5;
			break;
		default:
			printf("Numero invalido por favor ingrese una opcion correcta\n");
			break;
		}
			system("pause");
	} while (opcion != 5);

}

//Gonzalo de Salvo
