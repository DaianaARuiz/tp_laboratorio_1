#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"
#include "funcionesAuxiliares.h"

void employee_showAllEmployees(LinkedList* pListEmployee)
{
    Employee* empleado;
    int lengthListEmployee = ll_len(pListEmployee);
    printf("\tID\tNOMBRE\tHORAS\tSALARIO\n");
    for(int i=0;i<lengthListEmployee;i++)
    {
        empleado =(Employee*) ll_get(pListEmployee,i);
        employee_showOneEmployee(empleado);
    }
}

int employee_askIdToDelete(LinkedList* pListEmployee)
{
    int retorno=-1;
    int idIngresado;
    int indexIdAEliminar;
     int lengthListEmployee=ll_len(pListEmployee);

    inputs_getAndValidateInt(&idIngresado,"\nIngrese el id del empleado que quiere dar de baja: ","\nError.Por favor Ingrese un numero: ","\nError.Ingrese un id existente:",0,lengthListEmployee);
    indexIdAEliminar=employee_searchById(pListEmployee,idIngresado );
    if(indexIdAEliminar!=-1)
    {
       retorno= indexIdAEliminar;
    }
    return retorno;
}

int employee_AskIdAndGetTheIndex(LinkedList* pListEmployee, char msj[],char emsj1[],char emsj2[])
{
    int idIngresado;
    int indexId=-1;
    int lengthListEmployee=ll_len(pListEmployee);


    inputs_getAndValidateInt(&idIngresado,msj,emsj1,emsj2,0,lengthListEmployee);
    indexId=employee_searchById(pListEmployee,idIngresado);

    return indexId;
}

int employee_searchById(LinkedList* pListEmployee,int idIngresado)
{
    Employee* AuxEmpleado;
    int idAux;
    int indexIdBuscado=-1;
    int lengthListEmployee = ll_len(pListEmployee);

    for(int i=0;i<lengthListEmployee;i++)
    {
        AuxEmpleado=(Employee*)ll_get(pListEmployee,i);
        employee_getId(AuxEmpleado,&idAux);
        if(idAux==idIngresado)
        {
            indexIdBuscado=i;
            break;
        }
    }
    return indexIdBuscado;
}

int employee_registerEmployee(LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmpleado;
    char nombreIngresado[51] ;
    int horasIngresadas;
    int sueldoIngresado;
    int retorno=0;
    int id;

    nuevoEmpleado=employee_new();

    inputs_PedirNombre("Ingrese nombre: ","Nombre no valido. Reeingrese: ",51,nombreIngresado);
    inputs_getAndValidateInt(&horasIngresadas,"Ingrese horas trabajadas: ","Error.En este campo no se admiten letras. Reingrese: ","Error. Solo se admite de [0] a [400]hs. Reingrese: ",0,400);
    inputs_getAndValidateInt(&sueldoIngresado,"Ingrese sueldo: ","Error.En este campo no se admiten letras. Reingrese: ","Error. Solo se admite de [0] a [100000]. Reingrese: ",0,100000);
    employee_calculateNewId(pArrayListEmployee,&id);

    if(nuevoEmpleado!=NULL)
    {
        employee_setNombre(nuevoEmpleado,nombreIngresado);
        employee_setHorasTrabajadas(nuevoEmpleado,horasIngresadas);
        employee_setSueldo(nuevoEmpleado,sueldoIngresado);
        employee_setId(nuevoEmpleado,id);

        ll_add(pArrayListEmployee,nuevoEmpleado);
        retorno=1;
    }
    return retorno;
}

/*
int employee_lastId(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int IdAux;
    int IdMax=0;
    int lengthListEmployee = ll_len(pArrayListEmployee);

    for(int i=0 ; i<lengthListEmployee; i++)
    {
        pEmployee = ll_get(pArrayListEmployee, i);
        if(pEmployee != NULL)
        {
            employee_getId(pEmployee, &IdAux);
            if(IdAux > IdMax)
            {
                IdMax = IdAux;
            }
        }
    }
    return IdMax;
}
*/

int employee_lastId(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int IdAux;
    int IdMax=0;
    int lengthListEmployee = ll_len(pArrayListEmployee);

    for(int i=0 ; i<lengthListEmployee; i++)
    {
        pEmployee = ll_get(pArrayListEmployee, i);
        if(pEmployee != NULL)
        {
            employee_getId(pEmployee, &IdAux);
            if(IdAux > IdMax)
            {
                IdMax = IdAux;
            }
        }
    }
    return IdMax;
}



void employee_calculateNewId(LinkedList* pArrayListEmployee,int* id)
{
    *id = employee_lastId(pArrayListEmployee)+1;
}

int employee_modifyEmployee(Employee* empleado, int opcion)
{
    char nombreModificado[51];
    int horasModificadas;
    int sueldoModificado;
    int retorno=0;

        switch(opcion)
        {
            case 1:
                inputs_PedirNombre("\nIngrese nuevo nombre: ","Nombre no valido. Reeingrese: ",51,nombreModificado);
                if(employee_setNombre(empleado,nombreModificado))
                {
                    retorno=1;
                }
                break;
            case 2:
                inputs_getAndValidateInt(&horasModificadas,"\nIngrese nueva horas trabajadas: ","Error.En este campo no se admiten letras. Reingrese: ","Error. Solo se admite de [0] a [400]hs. Reingrese: ",0,400);
                if(employee_setHorasTrabajadas(empleado,horasModificadas))
                {
                    retorno=1;
                }
                break;
            case 3:
                inputs_getAndValidateInt(&sueldoModificado,"\nIngrese nuevo sueldo: ","Error.En este campo no se admiten letras. Reingrese: ","Error. Solo se admite de [0] a [100000]. Reingrese: ",0,100000);
                if(employee_setSueldo(empleado,sueldoModificado))
                {
                    retorno=1;
                }
                break;
        }

    return retorno;
}
