#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funcionesAuxiliares.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=0;

    if(pArrayListEmployee!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            retorno = parser_EmployeeFromText(pFile,pArrayListEmployee);
            fclose(pFile);
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
     return employee_registerEmployee(pArrayListEmployee);
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleadoAux;
    int opcion;
    int indiceEmpleadoModificar;
    int retorno=0;

    indiceEmpleadoModificar=employee_AskIdAndGetTheIndex(pArrayListEmployee,"Ingrese el id del empleado que quiere modificar: ","Solo se admiten letras. Reeingrese: ","Numero fuera del rango existente. Reeingrese: ");
    do{
        printf("\n1.Modificar nombre\n2.Modificar horas trabajadas\n3.Modificar sueldo\n4.Salir de este menu\n");
        inputs_getAndValidateInt(&opcion,"\nIngrese su opcion: ","Error.Debe ingresar un numero:","\nError,solo puedes ingresar del [1] al [4]:",1,4);


        if(indiceEmpleadoModificar!=-1)
        {
            empleadoAux= ll_get(pArrayListEmployee,indiceEmpleadoModificar);

             if(employee_modifyEmployee(empleadoAux,opcion) )
            {
                retorno=1;
            }
        }

    }while(opcion!=4);

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int indexIdAEliminar;
    int retorno=0;
    indexIdAEliminar= employee_askIdToDelete(pArrayListEmployee);
    if(indexIdAEliminar!=-1)
    {
        ll_remove(pArrayListEmployee,indexIdAEliminar);
        retorno=1;
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pListEmployee)
{
    int retorno=0;

    if(pListEmployee!=NULL)
    {
        employee_showAllEmployees(pListEmployee);
        retorno = 1;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

