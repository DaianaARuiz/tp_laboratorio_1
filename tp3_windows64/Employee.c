#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmpleado = employee_new();
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;

    id = atoi(idStr);
    strcpy(nombre,nombreStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atof(sueldoStr);

    if(pEmpleado!=NULL)
    {
        if( employee_setId(pEmpleado,id) )
        {
            employee_setNombre(pEmpleado,nombre);
            employee_setHorasTrabajadas(pEmpleado,horasTrabajadas);
            employee_setSueldo(pEmpleado,sueldo);
        }
    }
    return pEmpleado;
}


//Nombre---------------------------------------------
int employee_setNombre(Employee* this,char* nombre)
{
    int setteo=0;
    if(this!=NULL && nombre!=NULL)
    {
        if( isValidName(nombre,50 ) )
        {
           strcpy(this->nombre,nombre);
           setteo=1;
        }
    }
    return setteo;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }
    return retorno;
}

//--------------------------ID-------------------
int employee_setId(Employee* this,int id)
{
    int setteo=0;
    if(this!=NULL && id>=0)
    {
        setteo=1;
        this->id =id;
    }
    return setteo;
}


int employee_getId(Employee* this,int* id)
{
   int retorno=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=1;
    }
    return retorno;
}

//--------------------------HORAS-------------------

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int setteo=0;
    if(this!=NULL && horasTrabajadas>=0 && horasTrabajadas<400)
    {
        this->horasTrabajadas=horasTrabajadas;
        setteo=1;
    }
    return setteo;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}
//--------------------------SUELDO-------------------
int employee_setSueldo(Employee* this,int sueldo)
{
    int setteo=0;
    if(this!=NULL && sueldo<100000)
    {
        this->sueldo=sueldo;
        setteo=1;
    }
    return setteo;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=1;
    }
    return retorno;
}

void employee_showOneEmployee(Employee* empleado)
{
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;

    employee_getId(empleado,&id);
    employee_getNombre(empleado,nombre);
    employee_getHorasTrabajadas(empleado,&horasTrabajadas);
    employee_getSueldo(empleado,&sueldo);

    if(empleado != NULL)
    {
        printf("\t%d   %-11s %5d hs   $%2d\n",id,nombre,horasTrabajadas,sueldo);
    }
}

int employee_CompareBySueldo(void* item1, void* item2)
{
    Employee* empleado1;
    Employee* empleado2;
    int sueldo1;
    int sueldo2;
    int retorno=-1;

    empleado1=(Employee*)item1;
    empleado2=(Employee*)item2;

    employee_getHorasTrabajadas(empleado1,&sueldo1);
    employee_getHorasTrabajadas(empleado2,&sueldo2);

    if(sueldo1 > sueldo2){
        retorno = 1;
    }else{
        if(sueldo1==sueldo2){
            retorno = 0;
        }
    }
    return retorno;
}


int employee_CompareByHoras(void* item1, void* item2)
{
    Employee* empleado1;
    Employee* empleado2;
    int horas1;
    int horas2;
    int retorno=0;

    empleado1=(Employee*)item1;
    empleado2=(Employee*)item2;

    if(employee_getHorasTrabajadas(empleado1,&horas1)==1 &&
    employee_getHorasTrabajadas(empleado2,&horas2)==1  )
    {
        if(horas1>horas2){
            retorno=1;
        }else{
            retorno=-1;
        }
    }
    return retorno;
}

int employee_compareByName(void* item1, void* item2)
{
    Employee* empleado1;
    Employee* empleado2;
    char nombre1[51];
    char nombre2[51];

    empleado1=(Employee*)item1;
    empleado2=(Employee*)item2;

    employee_getNombre(empleado1,nombre1);
    employee_getNombre(empleado2,nombre2);

    return strcmp(nombre1,nombre2);
}

int employee_CompareById(void* item1, void* item2)
{
    Employee* empleado1;
    Employee* empleado2;
    int id1;
    int id2;
    int retorno=-1;

    empleado1=(Employee*)item1;
    empleado2=(Employee*)item2;
    employee_getId(empleado1,&id1);
    employee_getId(empleado2,&id2);

    if(id1>id2){
        retorno=1;
    }else{
        retorno=0;
    }

    return retorno;
}
