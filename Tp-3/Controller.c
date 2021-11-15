#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"

int controller_findEmployee(LinkedList* pArrayListEmployee) {
	int i;
	int largo;
	int id;

	Employee* aux = employee_new();

	if (pArrayListEmployee != NULL) {
		largo = ll_len(pArrayListEmployee);

		id = getInt("Ingrese el ID del Empleado: ", 1, 100000);

		for (i = 0; i < largo; i++) {
			aux = ll_get(pArrayListEmployee, i);

			if (id == aux->id) {
				break;
			}

		}

		if (i == largo) {
			i = -1;
		}
	}
	return i;
}
int controller_setIDUpdate(char *path, int idEmpleado) {
	int todoOk = 0;
	char aux[100];

	FILE *pFile;
	if (path != NULL && idEmpleado != -1) {
		pFile = fopen(path, "w");

		sprintf(aux, "%d", idEmpleado);

		if (pFile != NULL) {
			fprintf(pFile, "%s", aux);
			todoOk = 1;
		}

		fclose(pFile);
	}
	return todoOk;
}
int controller_loadID(char *path) {
	int id = -1;
	char aux[100];

	FILE *pFile;

	if (path != NULL) {
		pFile = fopen(path, "r");

		if (pFile != NULL) {
			fread(&aux, sizeof(aux), 1, pFile);
		}

		fclose(pFile);
		id = atoi(aux);
	}

	return id;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee) {
	int todoOk = 0;
	FILE* pFile;

	if (path != NULL && pArrayListEmployee != NULL) {
		pFile = fopen(path, "r");

		if (pFile != NULL) {
			ll_clear(pArrayListEmployee);
			parser_EmployeeFromText(pFile, pArrayListEmployee);
			todoOk = 1;
		}

		fclose(pFile);
	}
	return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee) {
	FILE* pFile;
	int todoOk = 0;
	int check;

	if (path != NULL && pArrayListEmployee != NULL) {
		pFile = fopen(path, "rb");
		if (pFile != NULL) {
			ll_clear(pArrayListEmployee);
			check = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			if (check) {
				todoOk = 1;
			}
		}

		fclose(pFile);
	}

	return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee) {
	Employee* aux;
	Employee Empleado;
	int idEmpleado;
	int todoOk = 0;
	char idStr[50];
	char hsTrabajadasStr[50];
	char sueldoStr[50];

	if (pArrayListEmployee != NULL) {

		if (ll_len(pArrayListEmployee) == 0) {
			idEmpleado = 1;
			controller_setIDUpdate("id.csv", idEmpleado);
		} else {
			idEmpleado = controller_loadID("id.csv");
		}

		if (idEmpleado != -1) {
			todoOk = 1;
			Empleado = crearEmployee(idEmpleado);
			itoa(Empleado.id,idStr,10);
			itoa(Empleado.horasTrabajadas,hsTrabajadasStr,10);
			itoa(Empleado.sueldo,sueldoStr,10);
			aux = employee_newParametros(idStr, Empleado.nombre,
					hsTrabajadasStr,sueldoStr);
			ll_add(pArrayListEmployee, aux);
		}
	}
	return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee) {
	int indice;
	int todoOk = 0;
	Employee* aux;

	if (pArrayListEmployee != NULL) {
		indice = controller_findEmployee(pArrayListEmployee);

		if (indice != -1) {

			aux = (Employee*) ll_get(pArrayListEmployee, indice);
			todoOk = modificarEmployee(aux);
			if (todoOk == 1) {

				ll_set(pArrayListEmployee, indice, aux);
			}

		}
	}
	return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee) {

	int index;
	int todoOk = 0;
	Employee* aux;

	if (pArrayListEmployee != NULL) {
		index = controller_findEmployee(pArrayListEmployee);
		if (index != -1) {
			todoOk = 1;
			aux = (Employee*) ll_get(pArrayListEmployee, index);
			ll_remove(pArrayListEmployee, index);
			employee_delete(aux);
		}
	}
	return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int todoOk = 0;
	int largo;
	Employee* aux = employee_new();

	if (pArrayListEmployee != NULL) {
		largo = ll_len(pArrayListEmployee);
		if (largo > 0) {
			todoOk = 1;
			printf("			***LISTA DE EMPLEADOS***		   \n");
			printf("-----------------------------------------------\n");
			printf("   ID         NOMBRE         HORAS    SUELDO   \n");
			printf("-----------------------------------------------\n");
			for (int i = 0; i < largo; i++) {
				aux = (Employee*) ll_get(pArrayListEmployee, i);
				show_Employee(aux);
			}
		}
	}
	return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int opcion;
	int todoOk = 0;
	int check;
	int orden;
	int retorno;

	if (pArrayListEmployee != NULL) {
		do {
			printf("		***Menu ordenamiento***			\n");
			printf("1.Ordenar por ID\n");
			printf("2.Ordenar por nombre\n");
			printf("3.Ordenar por horas trabajadas\n");
			printf("4.Ordenar por salarios.\n");
			printf("5. Salir.\n");
			opcion = getInt("\nIngrese una opcion: ",
					1, 5);
			if (opcion != 5) {
				printf("1. Ascendente.\n");
				printf("2. Descendente.\n");
				orden =
						getInt(
								"Ingrese si desea ordenar de manera ascendente o descendente: ",
								1, 2);
				if (orden != 1) {
					orden = 0;
				}
				printf("La lista esta siendo ordenada.\n");
				switch (opcion) {
				case 1:
					check = ll_sort(pArrayListEmployee, ordenarEmployeePorID,
							orden);
					if (check) {
						todoOk = 1;
					}
					retorno=1;
					break;

				case 2:
					check = ll_sort(pArrayListEmployee,
							ordenarEmployeePorNombre, orden);
					if (check) {
						todoOk = 2;
					}
					retorno=2;
					break;

				case 3:
					check = ll_sort(pArrayListEmployee,
							ordenarEmployeePorHorasTrabajadas, orden);
					if (check) {
						todoOk = 3;
					}
					retorno=3;
					break;
				case 4:
					check = ll_sort(pArrayListEmployee,
							ordenarEmployeePorSueldo, orden);
					if (check) {
						todoOk = 4;
					}
					retorno=4;
					break;
				}
			}
		} while (todoOk != 0);
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	int todoOk = 0;
	int largo;

	FILE *pFile;
	Employee *aux;

	if (path != NULL && pArrayListEmployee != NULL) {
		largo = ll_len(pArrayListEmployee);

		pFile = fopen(path, "w");

		if (pFile != NULL) {
			fprintf(pFile, "ID,Nombre,HorasTrabajadas,Salario\n");
			for (int i = 0; i < largo; i++) {
				aux = (Employee*) ll_get(pArrayListEmployee, i);
				if (aux != NULL) {
					fprintf(pFile, "%d,%s,%d,%d\n", aux->id, aux->nombre,
							aux->horasTrabajadas, aux->sueldo);
				}
			}
			todoOk = 1;
		}
		fclose(pFile);
	}
	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	int todoOk = 0;
	int largo;

	FILE *pFile;
	Employee *aux;

	if (path != NULL && pArrayListEmployee != NULL) {
		largo = ll_len(pArrayListEmployee);

		pFile = fopen(path, "wb");

		if (pFile != NULL) {

			for (int i = 0; i < largo; i++) {
				aux = (Employee*) ll_get(pArrayListEmployee, i);
				fwrite(aux, sizeof(Employee), 1, pFile);
			}
			todoOk = 1;
		}
		fclose(pFile);
	}
	return todoOk;
}

