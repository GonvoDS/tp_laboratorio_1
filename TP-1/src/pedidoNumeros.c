#include "TP-1.h"

int sumaNumeros(int x, int z)
{
	int suma;


	suma=x+z;
	return suma;
}
int restaNumeros(int x, int z){

	int resta;

	resta=x-z;

	return resta;
}
void divisionNumeros(int x, int z){

	float division;

	if(z!=0){
	division=x/(float)z;
	printf("La division entre %d y %d es igual a: %.2f",x,z,division);
	}
	else
	{
		printf("No es posible realizar una division por 0\n");
	}

;
}

int multiplicacionNumeros(int x, int z){

	int multi;

	multi=x*z;

	return multi;
}
void factorialNumeros(int x, int z){
	int a,b;
	int factorialX=1;
	int factorialZ=1;
	for (a = x; a > 1; a--){
	    factorialX = factorialX * a;
	}
	for (b = z; b > 1; b--){
	    factorialZ = factorialZ * b;
	}

	printf("El factorial del numero %d es igual a %d, mientras que el del numero %d es igual a %d", x, factorialX, z,factorialZ);

}

