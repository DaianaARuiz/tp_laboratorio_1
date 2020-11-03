#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funcionesAuxiliares.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* El nombre del archivo
 * \param pArrayListEmployee LinkedList* La lista donde se cargaran los datos del archivo
 * \return int  [0] en caso de que no se hayan podido cargar los datos
                [1] si se cargaron con exito
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
 * \param path char* El nombre del archivo
 * \param pArrayListEmployee LinkedList* La lista donde se cargaran los datos del archivo
 * \return int  [0] en caso de que no se hayan podido cargar los datos
                [1] si se cargaron con exito
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    int retorno=0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        if((pFile = fopen(path,"rb"))==NULL)
        {
            printf("\nNo se encontró el archivo. \n");
            printf("\nCreando el archivo....\n");
            if( (pFile=fopen(path,"wb"))!=NULL)
            {
                fwrite(pArrayListEmployee, sizeof(LinkedList),1,pFile);
            }else
            {
                printf("\nError al crear archivo.\n");
            }

        }else
        {
            retorno=parser_EmployeeFromBinary(pFile , pArrayListEmployee);
        }
        fclose(pFile);
    }
    return retorno;
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
    int retorno=0;
    int opcion;

    printf("\n1.Ordenar por nombre.\n2.Ordenar por ID\n3.Ordenar por sueldo.\n4.Ordenar por horas trabajadas.\n5.Salir de este menu.\n");
    inputs_getAndValidateInt(&opcion,"\nIngrese su opcion: ","Error.Debe ingresar un numero:","\nError,solo puedes ingresar del [1] al [5]:",1,5);

    do{
          switch(opcion)
        {
            case 1:
                    printf("Retorno antes ort: %d",retorno);
                    ll_sort(pArrayListEmployee, employee_compareByName,1);
                    retorno=1;
                break;
            case 2:
                 if(ll_sort(pArrayListEmployee, employee_CompareById,1)==0){
                        retorno=1;
                    }else{
                        printf("\nHubo un error al ordenar la lista por nombre\n");
                    }
                break;
            case 3:
                    if( ll_sort(pArrayListEmployee,employee_CompareBySueldo,1)  ==0  )
                    {
                         retorno=1;
                    }
                break;
            case 4:
                 if(ll_sort(pArrayListEmployee, employee_CompareByHoras,1)==0){
                        retorno=1;
                    }else{
                        printf("\nHubo un error al ordenar la lista por horas trabajadas\n");
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
    Employee* empleado;
    int len;
    int retorno = 0;
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        len = ll_len(pArrayListEmployee);

        for(int i=0;i<len;i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&id);
            employee_getNombre(empleado,nombre);
            employee_getHorasTrabajadas(empleado,&horasTrabajadas);
            employee_getSueldo(empleado,&sueldo);
            fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
        }
        fclose(pFile);
        retorno = 1;
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
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        len = ll_len(pArrayListEmployee);

        for(int i=0;i<len;i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&id);
            employee_getNombre(empleado,nombre);
            employee_getHorasTrabajadas(empleado,&horasTrabajadas);
            employee_getSueldo(empleado,&sueldo);
            //fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
            fwrite(empleado,sizeof(empleado),1,pFile);
        }
        fclose(pFile);
        retorno = 1;
    }
    return retorno;
}

