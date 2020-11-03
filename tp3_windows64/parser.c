#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    char idAux[51];
    char nombreAux[51];
    char horasTrabajadasAux[51];
    char sueldoAux[51];
    int retorno = 0;
    if(pFile!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);
        do{
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);
            empleado =employee_newParametros(idAux,nombreAux,horasTrabajadasAux,sueldoAux);
            ll_add(pArrayListEmployee,empleado);
        }while(!feof(pFile));
        retorno = 1;
    }
    return retorno;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int retorno = 0;

    if(pFile!=NULL)
    {
        do{
            empleado = employee_new();
            if( (fread(empleado,sizeof(Employee),1,pFile)) == 1)
            {
                ll_add(pArrayListEmployee,empleado);
            }
        }while(!feof(pFile));
        retorno = 1;
    }
    return retorno;
}
