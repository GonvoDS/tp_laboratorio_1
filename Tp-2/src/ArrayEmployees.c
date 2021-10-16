#include "ArrayEmployees.h"
#include "utn.h"
#include "EmployeesExtra.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int initEmployees(Employee* list, int len)
{
 int todoOk=-1;

 if(list != NULL || len<=1000 || len >=1)
 {
     todoOk=0;
     for(int i=0;i<len;i++)
     {
         list[i].isEmpty=1;
     }
 }
    return todoOk;
}
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary, int sector)
{
    int todoOk = -1;

	if(list != NULL && (len<1000 || len>1)){
		for(int i=0; i<len; i++){
			if(list[i].isEmpty==1){

				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = 0;
                todoOk = 0;
				break;
			}
		}
	}
    return todoOk;
}
int printEmployees(Employee* list, int length)
{
     int todoOk=0;
 if(list!=NULL&&length>0)
 {
     system("cls");
     printf("   ***Listado de empleados  ***\n");
     printf("  Id     |Nombre         |Apellido    |Salario    |Sector\n");
     printf("------------------------------------------------------------\n");
     for(int i=0;i<length;i++)
     {
         if(list[i].isEmpty==0)
         {
             mostrarEmpleado(list[i],length);
         }
         todoOk=1;
     }
}
     return todoOk;
}
int findEmployeeById(Employee* list, int len,int id)
{
  int indice= -1;

    if(list!=NULL && len>0 && id>=1)
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].id==id&&list[i].isEmpty==0)
            {
                indice=i;
                break;

            }

        }
    }
        return indice;
}
int removeEmployee(Employee* list, int len, int id)
{
    int todoOk=-1;
    int indice;
    char confirma;

    if(list!=NULL&&len>0)
    {
        system("cls");
        printf("    ***Baja persona***  \n\n");
        printf("---------------------------\n");
        indice=findEmployeeById(list,len,id);

        if(indice==-1){
            printf("No existe una persona con id %d\n",id);
        }
        else{
            mostrarEmpleado(list[indice],len);
            printf("  Id     |Nombre         |Apellido    |Salario    |Sector\n");
            printf("------------------------------------------------------------\n");
            printf("Confirma baja?(s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            while(confirma!='s'&&confirma!='n')
            {
                printf("Opcion invalida, ingrese una opcion correcta(s/n): ");
                fflush(stdin);
                scanf("%c",&confirma);
            }
            if (confirma=='n'){
                printf("Se ha cancelado la baja\n");

            }
            else if(confirma=='s'){
                    list[indice].isEmpty=1;
                    todoOk=0;
            }
        }
    }
    return todoOk;
}
int sortEmployees(Employee* list, int len, int order)
{
 int todoOk=-1;
 Employee auxEmployee;
 if(list!=NULL&&len>0)
{
    for(int i=0; i<len-1; i++){
			for(int j=i+1; j<len; j++){

				if(order==1 && list[i].isEmpty==0 && ((strcmp(list[i].lastName,list[j].lastName)<0)  || (strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector > list[j].sector))){
					auxEmployee = list[i];
					list[i]=list[j];
					list[j]=auxEmployee;
				}
				if(order==0 && list[i].isEmpty==0 && ((strcmp(list[i].lastName,list[j].lastName)>0) || (strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector < list[j].sector))){
					auxEmployee = list[i];
					list[i]=list[j];
					list[j]=auxEmployee;
				}

			}
		}
	}

    return todoOk;
}
