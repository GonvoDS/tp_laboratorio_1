#ifndef EMPLOYEESEXTRA_H_INCLUDED
#define EMPLOYEESEXTRA_H_INCLUDED



#endif // EMPLOYEESEXTRA_H_INCLUDED

#include "ArrayEmployees.h"
#include "utn.h"
/// \fn int menu()
/// \brief Menu de opciones para el programa
/// \return Retorna la opcion seleccionada
int menu();
/// \fn int buscarEmployeeLibre(Employee*, int)
/// \brief Busca el primer lugar con la opcion isEmpty en 1 y lo retorna
/// \param list
/// \param tam
/// \return El indice del primer lugar que tenga isEmpty en 0 o -1 en caso de no haber ninguno
int buscarEmployeeLibre(Employee* list,int tam);
/// \fn Employee crearEmpleado(int)
/// \brief Crea un estructura en la cual se cargan los datos de un empleado
/// \param id
/// \return La estructura con todos los datos cargados
Employee crearEmpleado(int id);
/// \fn void mostrarEmpleado(Employee, int)
/// \brief Muestra un empleado cargado
/// \param Empleado
/// \param tam
void mostrarEmpleado(Employee Empleado,int tam);
/// \fn int modificarEmployee(Employee*, int)
/// \brief Modifica un empleado de la estructura
/// \param list
/// \param tam
/// \return Retorna 0 en caso de cancelar o no hacer la modificacion y 1 si esta es exitosa
int modificarEmployee(Employee* list, int tam);
/// \fn int menuModificacion()
/// \brief Menu para las opciones de modificacion del programa
/// \return Retorna la opcion seleccionada
int menuModificacion();
/// \fn float totalSalarios(Employee*, int, int*)
/// \brief Suma el total de los salarios y cuenta la cantidad de empleados.
/// \param list
/// \param tam
/// \param totalEmpleados
/// \return Retorna la suma total de los salarios y mediante un puntero la cantidad de empleados que cobran los sueldos
float totalSalarios(Employee* list,int tam,int* totalEmpleados);
/// \fn float CalcularPromedio(float, int)
/// \brief Calcula un promedio
/// \param numero
/// \param divisor
/// \return Retorna el promedio en caso de ser posible la division y -1 en caso de no poder realizarla
float CalcularPromedio(float numero, int divisor);
/// \fn void empleadosSalarioMayor(Employee*, int, float)
/// \brief Muestra los empleados con un salario mayor al promedio.
/// \param list
/// \param tam
/// \param salario
void empleadosSalarioMayor(Employee* list, int tam, float salario);
