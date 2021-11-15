#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include <string.h>
#include <ctype.h>

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = -1;
	char strId[50];
	char strNombre[128];
	char strHorasTrabajadas[50];
	char strSueldo[50];
	int leidos;
	Employee* pNewEmpleado;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", strId, strNombre,strHorasTrabajadas,strSueldo);
		do
		{
			leidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", strId, strNombre,strHorasTrabajadas,strSueldo);
			if(leidos == 4)
			{
				pNewEmpleado = employee_newParametros(strId, strNombre,strHorasTrabajadas,strSueldo);
				ll_add(pArrayListEmployee,pNewEmpleado);
				todoOk = 0;
			}
			else
			{
				printf("\n »» Error en la lectura.");
				todoOk = -1;
				break;
			}
		}while(!feof(pFile));
	}
   return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
		int contador=0;
		int todoOk;
		Employee* aux;

		if(pFile != NULL && pArrayListEmployee != NULL){
			while(!feof(pFile)){
				todoOk = 0;
				aux = employee_new();
				fread(aux, sizeof(Employee), 1, pFile);
				if(feof(pFile)){
					break;
				}
				todoOk = ll_add(pArrayListEmployee,aux);
				if(!todoOk){
					contador++;
				}

			}
		}

	    return contador;
}
