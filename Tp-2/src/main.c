#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"
#include "EmployeesExtra.h"
#define TAM 1000

int main()
{
    setbuf(stdout,NULL);

    Employee listaEmpleados[TAM];
    Employee Empleado;
    char seguir='s';
    int idEmpleado=1;
    int verificar=-1;
    int flagCarga=0;
    int id;
    int opcion;
    int totalEmpleados=0;
    float salarioTotal;
    float salarioPromedio;


    if(initEmployees(listaEmpleados,TAM)==-1)
       {
           printf("Ocurrio un error al inicializar el programa.");
       }
    do{
        switch(menu())
       {
        case 1:
            Empleado = crearEmpleado(idEmpleado);
            verificar=addEmployee(listaEmpleados,TAM,Empleado.id,Empleado.name,Empleado.lastName,Empleado.salary,Empleado.sector);
            if(verificar==-1)
            {
             printf("Error, empleado no ingresado");
            }
            else
            {
                idEmpleado=Empleado.id+1;
                flagCarga=1;
            }
        break;
        case 2:
        if(flagCarga==1)
        {
            system("cls");
            printf("    ***Baja persona***  \n");
            printf("------------------------\n");
            printEmployees(listaEmpleados,TAM);
            id=getInt("Ingrese el id del empleado a buscar: ",1,1000);
            verificar=removeEmployee(listaEmpleados,TAM,id);
            if(verificar==0)
            {
                printf("Baja exitosa!");
            }

        }
        else
        {
          printf("Ningun empleado fue dado de alta aun.\n");
        }
        break;
        case 3:
        if(flagCarga==1)
        {

            verificar=modificarEmployee(listaEmpleados,TAM);
            if(verificar==1)
            {
                printf("Modificacion exitosa!");
            }

        }
        else
        {
          printf("Ningun empleado fue dado de alta aun.\n");
        }
        break;
        case 4:
            if(flagCarga==1)
            {
            do
            {
            system("cls");
            printf("    ***Informe de empleados***  \n");
            printf("---------------------------------\n");
            printf("1. Listado de empleados.\n");
            printf("2. Informe de salarios.\n");
            printf("3. Volver.\n");
            opcion=getInt("Ingrese una opcion: ",1,3);
            switch(opcion)
            {
            case 1:
                system("cls");
                printf("    ***Listado de empleados***  \n");
                printf("----------------------------------\n");
                printf("En que orden desea mostrar los empleados?\n");
                printf("1. Ascendente.\n");
                printf("2. Descendente.\n");
                opcion=getInt("Ingrese una opcion: ",1,2);
                if(opcion==2)
                {
                    opcion=0;
                }
                sortEmployees(listaEmpleados,TAM,opcion);
                printEmployees(listaEmpleados,TAM);
                system("pause");
                break;
            case 2:
                system("cls");
                printf("    ***Informe de salarios***    \n");
                printf("----------------------------------\n");
                salarioTotal=totalSalarios(listaEmpleados,TAM,&totalEmpleados);
                printf("La suma total de los salarios es: %.2f\n",salarioTotal);
                salarioPromedio=CalcularPromedio(salarioTotal,totalEmpleados);
                printf("El promedio de los salarios es: %.2f\n",salarioPromedio);
                printf("Empleados que superan el promedio salarial: \n");
                printf("  Id     Nombre         Apellido    Salario    Sector\n");
                printf("------------------------------------------------------------\n");
                empleadosSalarioMayor(listaEmpleados,TAM,salarioPromedio);
                system("pause");
                break;
            default:
                printf("Opcion invalida, seleccione una correcta. \n");
                break;
            case 3:
                printf("Regreso al menu principal. \n");
                break;
            }
            }while(opcion!=3);
            }
            else
            {
                printf("Ningun empleado fue dado de alta aun.\n");
            }
        break;
        case 5:
            printf("Gracias por utilizar el programa!\n");
            seguir='n';
        break;
       }
       system("pause");

    }while(seguir=='s');
}
//Gonzalo de Salvo
