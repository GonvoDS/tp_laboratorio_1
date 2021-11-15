#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

Employee* employee_new() {

	Employee *NewEmployee;
	NewEmployee = (Employee*)malloc(sizeof(Employee));

	return NewEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salaryStr)
{
	Employee *pBufferEmployee;

	pBufferEmployee = employee_new();

	if(pBufferEmployee != NULL)
	{
       (*pBufferEmployee).id = atoi(idStr);
       strcpy((*pBufferEmployee).nombre, nombreStr);
       (*pBufferEmployee).horasTrabajadas = atoi(horasTrabajadasStr);
       (*pBufferEmployee).sueldo = atoi(salaryStr);
       return pBufferEmployee;
   	}
       return NULL;
}

void employee_delete(Employee *this) {
	free(this);
}
int employee_setId(Employee *this, int id) {
	int todoOk = 0;
	if (this != NULL) {
		todoOk = 1;
		this->id = id;
	}
	return todoOk;
}
int employee_getId(Employee *this, int *id) {
	int todoOk = 0;
	if (this != NULL) {
		todoOk = 1;
		*id = this->id;
	}
	return todoOk;
}
int employee_setNombre(Employee *this, char *nombre) {
	int todoOk = 0;
	if (this != NULL) {
		todoOk = 1;
		strcpy(this->nombre, nombre);
	}
	return todoOk;
}
int employee_getNombre(Employee *this, char *nombre) {
	int todoOk = 0;
	if (this != NULL) {
		todoOk = 1;
		strcpy(nombre, this->nombre);
	}
	return todoOk;

}
int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int todoOk = 0;
	if (this != NULL) {
		todoOk = 1;
		this->horasTrabajadas = horasTrabajadas;
	}
	return todoOk;
}
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	int todoOk = 0;
	if (this != NULL) {
		todoOk = 1;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return todoOk;
}

int employee_setSueldo(Employee *this, int sueldo) {
	int todoOk = 0;
	if (this != NULL) {
		todoOk = 1;
		this->sueldo = sueldo;
	}
	return todoOk;
}
int employee_getSueldo(Employee *this, int *sueldo) {
	int todoOk = 0;
	if (this != NULL) {
		todoOk = 1;
		*sueldo = this->sueldo;
	}
	return todoOk;
}
void show_Employee(Employee *this) {
	if (this != NULL) {
		printf("%5d    %10s      %8d     %5d\n", this->id, this->nombre,
				this->horasTrabajadas, this->sueldo);
	}
}
Employee crearEmployee(int id) {
	Employee empleado;

	if (id > 0) {
		empleado.id = id;
		getString("Ingrese nombre del empleado: ", empleado.nombre, 128);
		empleado.horasTrabajadas = getInt(
				"Ingrese horas trabajadas por el empleado: ", 1, 1000000);
		empleado.sueldo = getInt("Ingrese sueldo del empleado: ", 1, 100000000);

	}
	return empleado;
}
int modificarEmployee(Employee *empleado) {
	int todoOk = 0;
	int opcion;

	do {
		show_Employee(empleado);
		printf("Que dato desea modificar?\n");
		printf("1. Modificar nombre.\n");
		printf("2. Modificar horas trabajadas.\n");
		printf("3. Modificar sueldo.\n");
		printf("4. Salir.\n");
		opcion = getInt("\n\tIngrese una opcion: ", 1, 4);
		switch (opcion) {
		case 1:
			getString("Ingrese el nuevo nombre del empleado: ",
					empleado->nombre, 128);
			todoOk = 1;
			break;

		case 2:
			empleado->horasTrabajadas = getInt(
					"Ingrese las nuevas horas trabajadas del empleado: ", 1,
					1000000);
			todoOk = 1;
			break;

		case 3:
			empleado->sueldo = getInt("Ingrese el nuevo salario del empleado: ",
					1, 100000000);
			todoOk = 1;
			break;
		}
	} while (opcion != 4);

	return todoOk;
}
int ordenarEmployeePorID(void *empleado1, void *empleado2) {
	int todoOk;
	Employee *EmpleadoUno;
	Employee *EmpleadoDos;

	if (empleado1 != NULL && empleado2 != NULL) {
		todoOk = 0;
		EmpleadoUno = (Employee*) empleado1;
		EmpleadoDos = (Employee*) empleado2;

		if (EmpleadoUno->id < EmpleadoDos->id) {
			todoOk = -1;
		} else if (EmpleadoUno->id > EmpleadoDos->id) {
			todoOk = 1;
		}
	}

	return todoOk;
}

int ordenarEmployeePorNombre(void *empleado1, void *empleado2) {
	int todoOk;
	Employee *EmpleadoUno;
	Employee *otroEmpleado;

	if (empleado1 != NULL && empleado2 != NULL) {
		EmpleadoUno = (Employee*) empleado1;
		otroEmpleado = (Employee*) empleado2;

		todoOk = strcmp(EmpleadoUno->nombre, otroEmpleado->nombre);
	}

	return todoOk;
}

int ordenarEmployeePorHorasTrabajadas(void *empleado1, void *empleado2) {
	int todoOk;
	Employee *EmpleadoUno;
	Employee *EmpleadoDos;

	if (empleado1 != NULL && empleado2 != NULL) {
		todoOk = 0;
		EmpleadoUno = (Employee*) empleado1;
		EmpleadoDos = (Employee*) empleado2;

		if (EmpleadoUno->horasTrabajadas < EmpleadoDos->horasTrabajadas) {
			todoOk = -1;
		} else if (EmpleadoUno->horasTrabajadas
				> EmpleadoDos->horasTrabajadas) {
			todoOk = 1;
		}
	}

	return todoOk;
}

int ordenarEmployeePorSueldo(void *empleado1, void *empleado2) {
	int todoOk;
	Employee *EmpleadoUno;
	Employee *EmpleadoDos;

	if (empleado1 != NULL && empleado2 != NULL) {
		todoOk = 0;
		EmpleadoUno = (Employee*) empleado1;
		EmpleadoDos = (Employee*) empleado2;

		if (EmpleadoUno->sueldo < EmpleadoDos->sueldo) {
			todoOk = -1;
		} else if (EmpleadoUno->sueldo > EmpleadoDos->sueldo) {
			todoOk = 1;
		}
	}

	return todoOk;
}

