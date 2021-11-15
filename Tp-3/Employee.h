#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct {
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
} Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salaryStr);
Employee crearEmployee(int id);
void employee_delete(Employee *this);

int employee_setId(Employee *this, int id);
int employee_getId(Employee *this, int *id);

int employee_setNombre(Employee *this, char *nombre);
int employee_getNombre(Employee *this, char *nombre);

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas);

int employee_setSueldo(Employee *this, int sueldo);
int employee_getSueldo(Employee *this, int *sueldo);

void show_Employee(Employee *this);
int modificarEmployee(Employee *empleado);
int ordenarEmployeePorID(void *empleado1, void *empleado2);
int ordenarEmployeePorNombre(void *empleado1, void *empleado2);
int ordenarEmployeePorHorasTrabajadas(void *empleado1, void *empleado2);
int ordenarEmployeePorSueldo(void *empleado1, void *empleado2);

#endif // employee_H_INCLUDED
