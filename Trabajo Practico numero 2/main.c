/*
 ============================================================================
 Name        : tp2.c
 Author      : Daiana Ruiz
 Version     :
 Copyright   : Your copyright notice
 Description : Sistema para administrar nómina de empleados en una empresa
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 4


typedef struct
{
 int id;
 char nombre[51];
 char apellido[51];
 float sueldo;
 int sector;
 int isEmpty;
}eEmpleado;

void InicializarArray(eEmpleado [],int,int);
eEmpleado CargarEmpleado();
int BuscarLibre(eEmpleado [],int);
void CargarTodosLosEmpleados(eEmpleado [],int,int);
void MostrarNominaDeEmpleados(eEmpleado listaEmpleados[],int cant);

int ValidarLetras(char []);
int ValidarNumero(char []);

int PedirEntero(char [],char []);
void PedirString(char [],char [],int ,char []);

void ModificarUnEmpleado(eEmpleado [],int,int,int);
int BuscarEmpleadoPorID(int,int,eEmpleado []);
void EliminarUnEmpleadoPorID(eEmpleado [],int,int);


int main(void) {

	int opcionMenu;
	int indiceLibre;
	int flagCarga;
	int contadorEmpleadosCargados;
	int idAModificar;
	int idEliminar;
	int opcionModificar;
	flagCarga=0;
    contadorEmpleadosCargados=0;
	eEmpleado listaEmpleados[TAM];
	InicializarArray(listaEmpleados,TAM,1); //1=esta vacia

    do{

        printf("\n1.ALTAS\n");
        printf("2.MODIFICAR\n");
        printf("3.BAJA\n");
        printf("4.INFORMAR\n");
         printf("5.SALIR\n");
        printf("Eliga una opcion:");
        scanf("%d",&opcionMenu);

        switch(opcionMenu)
        {
            case 1:
                indiceLibre= BuscarLibre(listaEmpleados,TAM);
                if(indiceLibre!=-1)
                {
                    CargarTodosLosEmpleados(listaEmpleados,TAM,indiceLibre);
                    flagCarga=1;
                    contadorEmpleadosCargados++;
                    printf("\nEmpleado cargado con exito\n");
                }else
                {
                    printf("\nNo hay más espacio de almacenamiento\n");
                }

                break;
            case 2:
                 if(flagCarga==1)
                    {
                        MostrarNominaDeEmpleados (listaEmpleados,TAM);
                        printf("\nIngrese el ID del empleado que desea modificar:");
                        scanf("%d", &idAModificar);

                        if(BuscarEmpleadoPorID(idAModificar,contadorEmpleadosCargados,listaEmpleados)!=-1)
                        {
                            printf("\n1-MODIFICAR NOMBRE\n2-MODIFICAR APELLIDO\n3-MODIFICAR SECTOR\n4-MODIFICAR SUELDO\nSeleccione la accion que desea realizar:");
                            scanf("%d", &opcionModificar);
                            ModificarUnEmpleado(listaEmpleados,idAModificar,opcionModificar,contadorEmpleadosCargados);
                            printf("\nModificacion cargada con exito\n");
                        }else
                        {
                            printf("\nEl ID ingresado no corresponde a ningun empleado.Por favor, verifique e intente nuevamente\n");
                        }

                    }else
                    {
                        printf("\nPor favor.Primero realize la carga de los empleados.\n");
                    }
                    break;
            case 3:
                if(flagCarga==1)
                {
                        MostrarNominaDeEmpleados (listaEmpleados,TAM);
                        printf("\nIngrese el ID del empleado que desea dar de baja:");
                        scanf("%d", &idEliminar);

                        if(BuscarEmpleadoPorID(idEliminar,contadorEmpleadosCargados,listaEmpleados)!=-1)
                        {
                            EliminarUnEmpleadoPorID(listaEmpleados,contadorEmpleadosCargados,idEliminar);
                            printf("\nSe ha eliminado el empleado exitosamente\n");

                        }else
                        {
                            printf("\nEl ID ingresado no corresponde a ningun empleado.Por favor, verifique e intente nuevamente\n");
                        }
                }else
                {
                    printf("\nPor favor.Primero realize la carga de los empleados\n");
                }
                break;
            case 4:
                    if(flagCarga==1)
                    {
                        MostrarNominaDeEmpleados (listaEmpleados,contadorEmpleadosCargados);
                    }else
                    {
                        printf("\nPor favor.Primero realize la carga de los empleados\n");
                    }
                break;
            default:
                printf("\nSelecione una opcion dentro de las marcadas\n");
           }

        }while(opcionMenu!=5);

 return 0;
}

void InicializarArray(eEmpleado listaEmpleados[],int tam,int valor)
 {
	 int i;
	 for(i=0;i < tam; i++)
	  {
		 listaEmpleados[i].isEmpty = valor;
	  }
  }


  int PedirEntero(char texto[],char textoError[],int max)
{
    char auxiliar[max];
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


void PedirString(char texto[],char textoError[],int tam,char input[])
{
    char auxiliar[tam];

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);
    while(ValidarLetras(auxiliar)==0|| strlen(auxiliar)>tam) //REVEER
    {
        printf("%s", textoError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
    }
     strcpy(input,auxiliar);
}

 eEmpleado CargarEmpleado()
 {
	 eEmpleado unEmpleado;
	 char auxiliarSueldo[7];
	 char auxiliarNombre[51];
     char auxiliarApellido[51];

     PedirString("Ingrese nombre: ","Error. Reingrese nombre: ",51,auxiliarNombre);
     strcpy(unEmpleado.nombre,auxiliarNombre);

     PedirString("Ingrese apellido: ","Error. Reingrese apellido: ",51,auxiliarApellido);
     strcpy(unEmpleado.apellido,auxiliarApellido);

     unEmpleado.sector= PedirEntero("Ingrese sector: ","Error, reingrese sector valido: ",5);

    printf("Ingrese sueldo: ");
    fflush(stdin);
    scanf("%[^\n]",auxiliarSueldo);
    while(ValidarNumero(auxiliarSueldo)==0)
    {
        printf("Error, reingrese sueldo valido: ");
        fflush(stdin);
        scanf("%[^\n]",auxiliarSueldo);
    }

    unEmpleado.sueldo=atoi(auxiliarSueldo);
    unEmpleado.isEmpty=0; //mi bandera de que el lugar ya esta ocupado

    return unEmpleado;
 }

 void CargarTodosLosEmpleados(eEmpleado listaEmpleados[],int cant, int indiceLibre)
 {
     eEmpleado unEmpleado;

    listaEmpleados[indiceLibre]= CargarEmpleado();//cargo empleado
    unEmpleado.id=indiceLibre;
 }

 int BuscarLibre(eEmpleado listaEmpleados[],int cant)
 {
     int index=-1;
     for(int i=0;i<cant;i++)
     {
         if(listaEmpleados[i].isEmpty==1)//=1, osea esta vacio
         {
             index=i;
             break;
         }
     }
     return index; //Devuelve el indice donde puedo guardar el dato, o -1(si no hay espacio)
 }

//Listado de los empleados ordenados alfabéticamente por Apellido y Sector.


void MostrarNominaDeEmpleados(eEmpleado listaEmpleados[],int cant)//la lista
{
    printf("\n*********************************************************************************");
    printf("\n\t \tListado de empleados: \n\n");
    printf("ID \tNOMBRE\t\tAPELLIDO\t SECTOR\t \tSUELDO\n");
    for(int i=0;i<cant;i++)
    {
        if(listaEmpleados[i].isEmpty==0) //si esta llena llamo a mostrar
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

int BuscarEmpleadoPorID(int idIngresado, int tam, eEmpleado listaEmpleados[])
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
             listaEmpleados[idAModificar].sector=PedirEntero("Ingrese nuevo sector: ","Error, reingrese sector valido: ",5);
            break;
        case 4:
            listaEmpleados[idAModificar].sueldo=PedirEntero("Ingrese nuevo sueldo: ","Error, reingrese sueldo valido: ",5);
               break;
        default:
                printf("\nOpcion no valida. Intente nuevamente\n");
    }
}

void EliminarUnEmpleadoPorID(eEmpleado listaEmpleados[],int contadorEmpleadosCargados,int idEliminar)
{
    listaEmpleados[idEliminar].isEmpty=1;
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


