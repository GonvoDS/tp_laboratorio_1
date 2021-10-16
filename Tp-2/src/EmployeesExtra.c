#include "EmployeesExtra.h"
#include "utn.h"
#include "ArrayEmployees.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000

int menu()
{
    int opcion;

    system("cls");
    printf("    Sistema de empleados    \n");
    printf("-----------------------------\n");
    printf("1)Dar un empleado de alta.\n");
    printf("2)Dar un empleado de baja.\n");
    printf("3)Modificar datos de un empleado.\n");
    printf("4)Acceder a informes.\n");
    printf("5)Salir.\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
int buscarEmployeeLibre(Employee* list, int tam)
{
    int libre=-1;

    if(list!=NULL&&tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(list[i].isEmpty==1)
            {
                libre=i;
                break;
            }
        }
    }
    return libre;
}
Employee crearEmpleado(int id)
{
	Employee Empleado;

	if(id>0){
        system("cls");
        printf("    ***Alta empleado***    \n");
        printf("----------------------------\n");

		Empleado.id = id;
		getString("Ingrese nombre del empleado: ", Empleado.name,51);
		getString("Ingrese apellido del empleado: ", Empleado.lastName,51);
		Empleado.salary = getFloat("Ingrese Salario del empleado: ", 1,10000000);
		Empleado.sector = getInt("Ingrese Sector del empleado(en numeros): ", 1,1000);
	}

	return Empleado;
}
void mostrarEmpleado(Employee Empleado,int tam)
{

    printf("%4d     |%-10s    |%-10s   |%.2f    |%4d\n",Empleado.id,
                                                   Empleado.name,
                                                   Empleado.lastName,
                                                   Empleado.salary,
                                                   Empleado.sector);

}
int menuModificacion()
{
    int opcion;

    printf("1.Modificar nombre\n");
    printf("2.Modificar apellido\n");
    printf("3.Modificar salario\n");
    printf("4.Modificar sector\n");
    printf("5.Cancelar modificacion\n");
    opcion=getInt("Ingrese una opcion: ",1,5);
    return opcion;
}
int modificarEmployee(Employee* list, int tam)
{
    int todoOk=0;
    int id;
    int indice;
    char confirma;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;

    if(list!=NULL&&tam>0)
    {
        system("cls");
        printf("    ***Modificar empleado***    \n");
        printf("---------------------------------\n");
        id= getInt("Ingrese id del empleado: ",1,1000);
        indice=findEmployeeById(list,tam,id);
        if(indice==-1){
            printf("No existe un empleado con id %d\n",id);
        }
        else{
            mostrarEmpleado(list[indice],tam);
            printf("  Id     |Nombre         |Apellido    |Salario    |Sector\n");
            printf("------------------------------------------------------------\n");
            printf("Desea modificar este empleado?(s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            while(confirma!= 's' && confirma!='n')
            {
                printf("Opcion invalida, ingrese una opcion correcta(s/n): ");
                fflush(stdin);
                scanf("%c",&confirma);
            }
            if (confirma=='s'){
                    system("cls");
             printf("    ***Modificar empleado***    \n");
                switch(menuModificacion()){
                    case 1:
                    getString("Ingrese un nuevo nombre: ",auxName,51);
                    strcpy(list[indice].name,auxName);
                    break;
                    case 2:
                    getString("Ingrese un nuevo apellido: ",auxLastName,51);
                    strcpy(list[indice].lastName,auxLastName);
                    break;
                case 3:
                    getValidFloat("Ingrese un nuevo salario: ","Dato invalido. Ingrese nuevamente el salario");
                    scanf("%f",&auxSalary);
                    list[indice].salary=auxSalary;
                    break;
                case 4:
                    getValidInt("Ingrese un nuevo sector: ","Dato invalido. Ingrese nuevamente el sector");
                    scanf("%d", &auxSector);
                    list[indice].sector = auxSector;
                    break;
                case 5:
                    printf("\nSe ha cancelado la modificacion\n");
                    break;
                }
                todoOk=1;
            }
            else
            {
                printf("Se ha cancelado la modificacion\n");
            }

        }
    }
    return todoOk;
}
float totalSalarios(Employee* list,int tam,int* totalEmpleados)
{

    float sumaSalarios=0;
	int cantidadEmpleados=0;

	for(int i=0; i<tam; i++){
		if(list[i].isEmpty==0){
			cantidadEmpleados++;
			sumaSalarios += list[i].salary;
		}
	}

	*totalEmpleados = cantidadEmpleados;
	return sumaSalarios;

}
float CalcularPromedio(float numero, int divisor)
{
    float promedio;
    if(divisor==0)
    {
        promedio=-1;
    }
    else{
        promedio=numero/divisor;
    }
    return promedio;
}
void empleadosSalarioMayor(Employee* list, int tam, float salario)
{
    for(int i=0;i<tam;i++)
    {
        if(list[i].salary>salario&&list[i].isEmpty==0)
        {
            mostrarEmpleado(list[i],i);
        }
    }
}
