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
    employee_searchById(pListEmployee,idIngresado,&indexIdAEliminar );
    if(indexIdAEliminar!=-1)
    {
       retorno= indexIdAEliminar;
    }
    return retorno;
}

void employee_AskIdAndGetTheIndex(LinkedList* pListEmployee, char msj[],char emsj1[],char emsj2[],int* indexId)
{
    int idIngresado;
    int lengthListEmployee=ll_len(pListEmployee);

    inputs_getAndValidateInt(&idIngresado,msj,emsj1,emsj2,0,lengthListEmployee);
    employee_searchById(pListEmployee,idIngresado,indexId);
}

int employee_searchById(LinkedList* pListEmployee,int idIngresado, int* indexIdBuscado)
{
    Employee* AuxEmpleado;
    int idAux;

    int retorno=0;
    int lengthListEmployee = ll_len(pListEmployee);
    *indexIdBuscado=-1;

    for(int i=0;i<lengthListEmployee;i++)
    {
        AuxEmpleado=(Employee*)ll_get(pListEmployee,i);
        employee_getId(AuxEmpleado,&idAux);
        if(idAux==idIngresado)
        {
            *indexIdBuscado=i;
            retorno=1;
            break;
        }
    }
    return retorno;
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

int guardarEnTexto(LinkedList* pArrayListEmployee, FILE* pFile, int len)
{
    Employee* empleado;
    int retorno = 0;
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;

    for(int i=0;i<len;i++)
    {
        empleado = ll_get(pArrayListEmployee,i);
        employee_getId(empleado,&id);
        employee_getNombre(empleado,nombre);
        employee_getHorasTrabajadas(empleado,&horasTrabajadas);
        employee_getSueldo(empleado,&sueldo);
        fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
        retorno=1;
    }
    fclose(pFile);

    return retorno;
}




