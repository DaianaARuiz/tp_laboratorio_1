#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define TAM 4
#include "empleados.h"

int initEmployees(eEmpleado listaEmpleados[],int tamanioArray)
{
    int retorno;
	 retorno=-1;
    for(int i=0;i <tamanioArray; i++)
    {
        listaEmpleados[i].isEmpty =TRUE;
        retorno=0;
    }

    return retorno;
}


int PedirEntero(char texto[],char textoError[])
{
    char auxiliar[10];
    int numeroIngresado;

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);
    while(ValidarNumero(auxiliar)==0)
    {
        printf("%s", textoError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
    }
     numeroIngresado=atoi(auxiliar);

    return numeroIngresado;
}


float PedirFlotante(char texto[],char textoError[])
{
    char auxiliar[10];
    float numeroIngresado;

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);
    while(ValidarFlotante(auxiliar)==0)
    {
        printf("%s", textoError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
    }
     numeroIngresado=atof(auxiliar);

    return numeroIngresado;
}

int ValidarFlotante(char numero[])
{
   int valido=1;
   for(int i=0;i<strlen(numero);i++)
   {
	  if( (numero[i] < '0' || numero[i] > '9') && numero[i] !='.')
	  {
		  valido=0;
	  }
   }
   return valido;
}

void PedirString(char texto[],char textoError[],int max, char input[])
{
    char auxiliar[500];

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);
    while(ValidarLetras(auxiliar)==0|| strlen(auxiliar)>max-1)
    {
        printf("%s", textoError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
    }
     strcpy(input,auxiliar);
}


 eEmpleado CargarEmpleado(eEmpleado listaEmpleados[],int tamanioArray, int indiceLibre)
 {
    eEmpleado unEmpleado;

    PedirString("\nIngrese nombre: ","Error. Reingrese nombre: ",51,unEmpleado.nombre);
    PedirString("Ingrese apellido: ","Error. Reingrese apellido: ",51,unEmpleado.apellido);
    unEmpleado.sector = PedirEntero("Ingrese sector: ","Error, reingrese sector valido: ");
    unEmpleado.sueldo= PedirFlotante("Ingrese sueldo: ","Error, reingrese sueldo valido:");
    unEmpleado.isEmpty=FALSE;
    unEmpleado.id=indiceLibre;

    listaEmpleados[indiceLibre]=unEmpleado;

    return unEmpleado;
 }

 int BuscarLibre(eEmpleado listaEmpleados[],int tamanioArray)
 {
     int index=-1;
     for(int i=0;i<tamanioArray;i++)
     {
         if(listaEmpleados[i].isEmpty==TRUE)
         {
             index=i;
             break;
         }
     }
     return index;
 }


void MostrarNominaDeEmpleados(eEmpleado listaEmpleados[],int cant)
{
    printf("\n*********************************************************************************");
    printf("\n\t \tListado de empleados: \n\n");
    printf("ID \tNOMBRE\t\tAPELLIDO\t SECTOR\t \tSUELDO\n");
    for(int i=0;i<cant;i++)
    {
        if(listaEmpleados[i].isEmpty==FALSE)
        {
            listaEmpleados[i].id=i;
            printf("%2d %10s %15s %15d %20f \n", listaEmpleados[i].id,
                                                listaEmpleados[i].nombre,
                                                listaEmpleados[i].apellido,
                                                listaEmpleados[i].sector,
                                                listaEmpleados[i].sueldo );
        }
    }
    printf("\n*********************************************************************************");
}



int findEmployeeById(int idIngresado, int tam, eEmpleado listaEmpleados[])
{
    int idValido=-1;
    for(int i=0;i<tam;i++)
    {
       if(listaEmpleados[i].id==idIngresado)
       {
            idValido=idIngresado;
       }
    }
    return idValido;
}

void ModificarUnEmpleado(eEmpleado listaEmpleados[],int idAModificar,int opcionModificar,int cant)
{
    char nombreModificado[51];
    char apellidoModificado[51];


    switch(opcionModificar)
    {
        case 1:
            PedirString("Ingrese el nuevo nombre:","Error. Reingrese nombre: ",51,nombreModificado);
            strcpy(listaEmpleados[idAModificar].nombre,nombreModificado);
            break;
        case 2:
            PedirString("Ingrese el nuevo apellido:","Error. Reingrese apellido: ",51,apellidoModificado);
            strcpy(listaEmpleados[idAModificar].apellido,apellidoModificado);
             break;
        case 3:
             listaEmpleados[idAModificar].sector=PedirEntero("Ingrese nuevo sector: ","Error, reingrese sector valido: ");
            break;
        case 4:
            listaEmpleados[idAModificar].sueldo=PedirEntero("Ingrese nuevo sueldo: ","Error, reingrese sueldo valido: ");
               break;
        default:
                printf("\nOpcion no valida. Intente nuevamente\n");
    }
}



int removeEmployee(eEmpleado listaEmpleados[],int contadorEmpleadosCargados, int idEliminar)
{
    int retorno=-1;
    if(findEmployeeById(idEliminar,contadorEmpleadosCargados,listaEmpleados)!=-1)
    {
        retorno=0;
        listaEmpleados[idEliminar].isEmpty=TRUE;
    }
    return retorno;
}

int ValidarLetras(char string[])
{
   int valido;
   valido=1;

  for(int i=0;i<strlen(string);i++)
   {
        if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
        {
            valido=0;
        }
    }
   return valido;
}

int ValidarNumero(char numero[])
{
   int valido=1;
   for(int i=0;i<strlen(numero);i++)
   {
	  if(numero[i] < '0' || numero[i] > '9')
	  {
		  valido=0;
	  }
   }
   return valido;
}

void MostrarNominaEmpleadosOrdenadosPorApellidoSector(eEmpleado unEmpleado[],int tamanioarray)
{
    eEmpleado auxiliar;

    for(int i=0;i<tamanioarray-1;i++)
    {
        for(int j=i+1;j<tamanioarray;j++)
        {
            if( strcmp(unEmpleado[i].apellido,unEmpleado[j].apellido)>0 || ( strcmp(unEmpleado[i].apellido,unEmpleado[j].apellido)==0  && unEmpleado[i].sector< unEmpleado[j].sector) )
            {
                auxiliar= unEmpleado[i];
                unEmpleado[j]=unEmpleado[i];
                unEmpleado[j]=auxiliar;
            }
        }
    }

}

float CalcularTotalSalarios(eEmpleado unEmpleado[],int cantEmpleados)
{
  float acumuladorSalarios;
  acumuladorSalarios=0;

  for(int i=0;i<cantEmpleados;i++)
  {
      acumuladorSalarios=acumuladorSalarios+unEmpleado[i].sueldo;
  }
  return acumuladorSalarios;
}

float CalcularPromedioSalarios(eEmpleado unEmpleado[],int cantEmpleados,float salarioTotal)
{
    float promedioSalarios;
    promedioSalarios=salarioTotal/cantEmpleados;
    return promedioSalarios;
}

float ContarEmpleadosSueldoMayorAlPromedio(eEmpleado unEmpleado[],int cantEmpleados,float salarioPromedio)
{
    int contadorEmpleadosSueldoMayorAlPromedio=0;

    for(int i=0;i<cantEmpleados;i++)
    {
        if(unEmpleado[i].sueldo>salarioPromedio)
        {
            contadorEmpleadosSueldoMayorAlPromedio++;
        }
    }

    return contadorEmpleadosSueldoMayorAlPromedio;
}


