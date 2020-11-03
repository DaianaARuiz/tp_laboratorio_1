#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funcionesAuxiliares.h"
#include "parser.h"


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


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    int retorno=0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        if((pFile = fopen(path,"rb"))==NULL)
        {
            printf("\nEl archivo no existe. Realize la carga desde el archivo en modo binario(opcion 1)\n");
        }else{
            retorno=parser_EmployeeFromBinary(pFile , pArrayListEmployee);
        }
        fclose(pFile);
    }
    return retorno;
}



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

    employee_AskIdAndGetTheIndex(pArrayListEmployee,"Ingrese el id del empleado que quiere modificar: ","Solo se admiten letras. Reeingrese: ","Numero fuera del rango existente. Reeingrese: ",&indiceEmpleadoModificar);
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

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int opcion;

    printf("\n1.Ordenar por nombre.\n2.Ordenar por ID\n3.Ordenar por sueldo.\n4.Ordenar por horas trabajadas.\n5.Salir de este menu.\n");
    inputs_getAndValidateInt(&opcion,"\nIngrese su opcion: ","Error.Debe ingresar un numero:","\nError,solo puedes ingresar del [1] al [5]:",1,5);

    do{
          switch(opcion)
        {
            case 1:
                    if(ll_sort(pArrayListEmployee, employee_compareByName,1)==0){
                            retorno=1;
                    }else{
                        printf("\nHubo un error al ordenar la lista por nombre.\n");
                    }
                break;
            case 2:
                 if(ll_sort(pArrayListEmployee, employee_CompareById,1)==0){
                        retorno=1;
                    }else{
                        printf("\nHubo un error al ordenar la lista por id.\n");
                    }
                break;
            case 3:
                    if( ll_sort(pArrayListEmployee,employee_CompareBySueldo,1) ==0 ){
                         retorno=1;
                    }else{
                        printf("\nHubo un error al ordenar la lista por sueldo.\n");
                    }
                break;
            case 4:
                 if(ll_sort(pArrayListEmployee, employee_CompareByHoras,1)==0){
                        retorno=1;
                    }else{
                        printf("\nHubo un error al ordenar la lista por horas trabajadas.\n");
                    }
                break;
            case 5:
                break;
        }
    }while(opcion!=5);

    return retorno;
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
    FILE* pFile = fopen(path,"w");
    int retorno;
    int len;

    len = ll_len(pArrayListEmployee);

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        retorno = guardarEnTexto(pArrayListEmployee,pFile,len);
    }
    return retorno;
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
    FILE* pFile = fopen(path,"wb");
    Employee* empleado;
    int len;
    int retorno = 0;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        len = ll_len(pArrayListEmployee);

        for(int i=0;i<len;i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            fwrite(empleado,sizeof(empleado),1,pFile);
        }
        fclose(pFile);
        retorno = 1;
    }
    return retorno;
}

