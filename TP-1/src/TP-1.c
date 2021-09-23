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
	int multi;
	int flag1=0;
	int flag2=0;

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
				printf("Reingrese el primer operando a cargar: ");
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
				printf("Reingrese el segundo operando a cargar: ");
				scanf("%d", &numDos);
			}
			break;
		case 3:
			if(flag1==0 ||flag2==0){
				printf("Por favor ingrese los dos operandos antes de hacer la operacion.\n");
			}
			else
			{
			suma = sumaNumeros(numUno, numDos);
			printf("La suma de %d y %d es igual a: %d\n",numUno,numDos, suma);
			}
			break;
		case 4:
			if(flag1==0 ||flag2==0)
			{
				printf("Por favor ingrese los dos operandos antes de hacer la operacion.\n");
			}
			else
			{
			resta = restaNumeros(numUno,numDos);
			printf("La resta de %d y %d es igual a: %d\n",numUno,numDos, resta);
			}
			break;
		case 5:
			if(flag1==0 ||flag2==0){
				printf("Por favor ingrese los dos operandos antes de hacer la operacion.\n");
			}
			else
			{
			divisionNumeros(numUno, numDos);
			}
			break;
		case 6:
			if(flag1==0 ||flag2==0){
				printf("Por favor ingrese los dos operandos antes de hacer la operacion.\n");
			}
			else
			{
			multi= multiplicacionNumeros(numUno, numDos);
			printf("La multiplicacion de %d y %d es igual a: %d\n",numUno,numDos, multi);
			}
			break;
		case 7:
			if(flag1==0 ||flag2==0){
				printf("Por favor ingrese los dos operandos antes de hacer la operacion.\n");
			}
			else{
			factUno=factorialNumeros(numUno);
			factDos=factorialNumeros(numDos);
			printf("El factorial del numero %d es %d mientras que el de %d es %d\n", numUno, factUno,numDos,factDos);
			}
			break;
		case 8:
			printf("Hasta luego!\n");
			opcion=8;
			break;
		default:
			printf("Numero invalido por favor ingrese una opcion correcta\n");
			break;
		}
			system("pause");
	} while (opcion != 8);

}

//Gonzalo de Salvo
