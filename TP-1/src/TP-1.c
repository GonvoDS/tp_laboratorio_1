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

		printf("Ingrese el primer numero a cargar: ");
		scanf("%d", &numUno);
		printf("Ingrese el segundo numero a cargar: ");
		scanf("%d", &numDos);
	do
	{
		system("cls");
		opcion=menuCalculadora(numUno,numDos);

		switch (opcion) {
		case 1:
			suma = sumaNumeros(numUno, numDos);
			printf("La suma de %d y %d es igual a: %d\n",numUno,numDos, suma);
			break;
		case 2:
			resta = restaNumeros(numUno,numDos);
			printf("La resta de %d y %d es igual a: %d\n",numUno,numDos, resta);
			break;
		case 3:
			divisionNumeros(numUno, numDos);
			break;
		case 4:
			multi= multiplicacionNumeros(numUno, numDos);
			printf("La multiplicacion de %d y %d es igual a: %d\n",numUno,numDos, multi);
			break;
		case 5:
			factUno=factorialNumeros(numUno);
			factDos=factorialNumeros(numDos);
			printf("El factorial del numero %d es %d mientras que el de %d es %d\n", numUno, factUno,numDos,factDos);
			break;
		case 6:
			printf("Ingrese el nuevo numero a cargar: ");
			scanf("%d", &numUno);
			break;
		case 7:
			printf("Ingrese el nuevo numero a cargar: ");
			scanf("%d", &numDos);
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
