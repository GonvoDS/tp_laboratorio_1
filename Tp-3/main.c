#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

    int option = 0;
    int flagLoad=0;
    int flagSave=0;
    int salir=0;
    int idEmpleado=1;
    int check;


    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	system("cls");
    	printf("    ***********************************************************************************************************\n\n");
    	printf("                \t\t\t***Menu principal carga de empleados***                 \n\n");
    	printf("    ***********************************************************************************************************\n\n\n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
        printf("10. Salir\n");
        option=getInt("Ingrese una opcion: ",1,10);


        switch(option)
        {
            case 1:
                check=controller_loadFromText("data.csv",listaEmpleados);
                if(check)
                {
                	printf("Carga desde texto exitosa!.\n");
                	idEmpleado=controller_loadID("id.csv");
                	flagLoad=1;
                	if(idEmpleado==-1)
                	{
                		printf("Error en la carga del ID\n");
                   	}
                	else
                	{
                		printf("ID incializado en %d\n",idEmpleado);
                	}

                }
                system("pause");
                break;
            case 2:
            	check=controller_loadFromBinary("data.bin",listaEmpleados);
            	if(check){
            		printf("Carga desde binario exitosa!\n");
            		idEmpleado=controller_loadID("id.csv");
            		flagLoad=1;
            		if(idEmpleado==-1){
            			printf("Error en la carga del ID\n");
            		}
            		else{
            		    printf("ID incializado en %d\n",idEmpleado);
            		}
            	}
            	system("pause");
                break;
            case 3:
            	check = controller_addEmployee(listaEmpleados);
            	if(check){
            		idEmpleado++;
            		controller_setIDUpdate("id.csv", idEmpleado);
            		flagSave=0;
            		flagLoad=1;
            	}
            	system("pause");
            	break;
            case 4:
            	if(flagLoad==1){
            		check=controller_editEmployee(listaEmpleados);
					if(check){
						printf("Empleado nodificado con exito!\n");
						flagSave=0;
					}
            	}
            	else{
            		printf("No hay empleados cargados\n");
            	}
            	system("pause");
            	break;
            case 5:
            	if(flagLoad==1){
            		check=controller_removeEmployee(listaEmpleados);
					if(check){
						printf("Empleado removido con exito!\n");
						flagSave=0;
					}
            	}
            	else{
            		printf("No hay empleados cargados\n");
            	}
            	system("pause");
            	break;
            case 6:
            	if(flagLoad==1){
            		system("cls");
					controller_ListEmployee(listaEmpleados);
            	}
            	else{
            		printf("No hay empleados cargados\n");
            	}
            	system("pause");
            	break;
            case 7:
            	if(flagLoad==1){
            		system("cls");
            		check=controller_sortEmployee(listaEmpleados);
					if(check==1){
						printf("La lista de empleados fue ordenada por ID\n");
					}
					else if(check==2){
						printf("La lista de empleado fue ordenada por nombre\n");
					}
					else if(check==3){
						printf("La lista de empleados fue ordenada segun las horas de trabajo\n");
					}
					else if(check==4){
						printf("La lista de empleados fue ordenada por sueldo\n");
					}
					else{
						printf("No se ha ordenado la lista\n");
					}
            	}
            	else{
            		printf("No hay empleados cargados");
            	}
            	system("pause");
            	break;
            case 8:
            	if(flagLoad==1){
            		check=controller_saveAsText("data.csv",listaEmpleados);
					if(check){
						 printf("Archivo guardado como texto\n");
						 controller_setIDUpdate("id.csv", idEmpleado);
						 flagSave=1;
					}
            	}
            	else{
            		printf("No hay empleados cargados");
            	}
                 system("pause");
                 break;
            case 9:
            	if(flagLoad==1){
            		check=controller_saveAsBinary("data.bin",listaEmpleados);
					if(check){
						printf("Archivo guardado como binario\n");
						controller_setIDUpdate("id.csv", idEmpleado);
						flagSave=1;
					}
            	}
            	else{
            		printf("No hay empleados cargados.\n");
            	}
            	system("pause");
            	break;
            case 10:
            	if(flagSave){
            		salir=1;
            	}
            	else{
            		printf("No guardo los cambios, desea salir igualmente?\n");
            		printf("1.Si\n");
            		printf("2.No\n");
            		option = getInt("Ingrese una opcion: \n",1,2);
            		switch(option){
            			case 1:
            				salir=1;
            				break;
            		}
            	}
            	system("pause");
            	break;
        }
    }while(salir == 0);
    return 0;
}

