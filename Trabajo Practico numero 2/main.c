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
#define TRUE 1
#define FALSE 0
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

int initEmployees(eEmpleado [],int);
eEmpleado CargarEmpleado();
int BuscarLibre(eEmpleado [],int);
void CargarTodosLosEmpleados(eEmpleado [],int,int);
void MostrarNominaDeEmpleados(eEmpleado [],int );
void MostrarNominaEmpleadosOrdenadosPorApellidoSector(eEmpleado [],int);
float CalcularTotalSalarios(eEmpleado [],int);
float CalcularPromedioSalarios(eEmpleado [],int ,float);
float ContarEmpleadosSueldoMayorAlPromedio(eEmpleado [],int ,float);


int ValidarLetras(char []);
int ValidarNumero(char []);

int PedirEntero(char [],char []);
void PedirString(char [],char [],int ,char []);

void ModificarUnEmpleado(eEmpleado [],int,int,int);
int findEmployeeById(int,int,eEmpleado []);
void EliminarUnEmpleadoPorID(eEmpleado [],int,int);


int main(void) {

	int opcionMenu;
	int indiceLibre;

	int contadorEmpleadosCargados;
	int idAModificar;
	int idEliminar;
	int opcionModificar;
	int opcionMenuMostrar;

	float SalarioTotal;
	float promedioSalarios;
	int empleadosConSueldoMayorAlPromedio;

    contadorEmpleadosCargados=0;
	eEmpleado listaEmpleados[TAM];
    printf("\n*********************************************************************************\n");
     printf("\tSISTEMA PARA ADMINISTRAR NOMINA DE EMPLEADOS");
    printf("\n*********************************************************************************\n");
    if(initEmployees(listaEmpleados,TAM)==0)
    {
        do{
            opcionMenu=PedirEntero("\n1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\nEliga una opcion:","Error.No se permiten letras. Reingrese la opcion: ");
            switch(opcionMenu)
            {
                case 1:
                    indiceLibre= BuscarLibre(listaEmpleados,TAM);
                    if(indiceLibre!=-1)
                    {
                        CargarTodosLosEmpleados(listaEmpleados,TAM,indiceLibre);
                        contadorEmpleadosCargados++;
                        printf("\nEmpleado cargado con exito\n");
                    }else
                    {
                        printf("\nNo hay mas espacio de almacenamiento\n");
                    }

                    break;
                case 2:
                    if(contadorEmpleadosCargados!=0)
                    {
                            MostrarNominaDeEmpleados (listaEmpleados,TAM);
                            printf("\nIngrese el ID del empleado que desea modificar:");
                            scanf("%d", &idAModificar);

                            if(findEmployeeById(idAModificar,contadorEmpleadosCargados,listaEmpleados)!=-1)
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
                    if(contadorEmpleadosCargados!=0)
                    {
                            MostrarNominaDeEmpleados (listaEmpleados,TAM);
                            printf("\nIngrese el ID del empleado que desea dar de baja:");
                            scanf("%d", &idEliminar);

                            if(findEmployeeById(idEliminar,contadorEmpleadosCargados,listaEmpleados)!=-1)
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
                        if(contadorEmpleadosCargados!=0)
                        {
                            do{
                                printf("\n1.Mostrar lista de empleados\n");
                                printf("2.Ordenar lista de empleados alfabeticamente por apellido y sector\n");
                                printf("3.Informar total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
                                printf("4.Salir de este menu\n");

                                opcionMenuMostrar=PedirEntero("Eliga una opcion: ","Error.No se permiten letras. Reingrese la opcion: ");

                                switch(opcionMenuMostrar)
                                {
                                    case 1:
                                         MostrarNominaDeEmpleados (listaEmpleados,contadorEmpleadosCargados);
                                        break;
                                    case 2:
                                        MostrarNominaEmpleadosOrdenadosPorApellidoSector(listaEmpleados,contadorEmpleadosCargados);
                                        break;
                                    case 3:
                                        SalarioTotal=CalcularTotalSalarios(listaEmpleados,contadorEmpleadosCargados);
                                        promedioSalarios=CalcularPromedioSalarios(listaEmpleados,contadorEmpleadosCargados,SalarioTotal);
                                        empleadosConSueldoMayorAlPromedio=ContarEmpleadosSueldoMayorAlPromedio(listaEmpleados,contadorEmpleadosCargados,promedioSalarios);
                                        printf("\n*********************************************************************************");
                                        printf("\nEl salario total de los empleados: $%f",SalarioTotal);
                                        printf("\nEl salario promedio es: $%f ",promedioSalarios);
                                        if(empleadosConSueldoMayorAlPromedio>0)
                                        {
                                            printf("\nCantidad de empleados que superan el salario promedio: $%d \n",empleadosConSueldoMayorAlPromedio);
                                        }else
                                        {
                                             printf("\nNo hay empleados cuyo sueldo supere al promedio \n");
                                        }
                                        printf("\n*********************************************************************************\n");
                                        break;
                                    case 4:
                                        break;
                                    default:
                                        printf("Por favor. Seleccione una opcion dentro de las marcadas");
                                        break;
                                }
                            }while(opcionMenuMostrar!=4);

                        }else
                        {
                            printf("\nPor favor.Primero realize la carga de los empleados\n");
                        }
                    break;
                default:
                    printf("\nSelecione una opcion dentro de las marcadas\n");
               }

            }while(opcionMenu!=5);
    }else
    {
        printf("No puede usar el programa porque hubo un error en el sistema.");
    }
 return 0;
}

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


void PedirString(char texto[],char textoError[],int tam,char input[])
{
    char auxiliar[500];

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);
    while(ValidarLetras(auxiliar)==0|| strlen(auxiliar)>tam-1)
    {
        printf("%s", textoError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
    }
     strcpy(input,auxiliar);
}

void CargarTodosLosEmpleados(eEmpleado listaEmpleados[],int cant, int indiceLibre)
 {
    eEmpleado unEmpleado;
    listaEmpleados[indiceLibre]= CargarEmpleado();
    unEmpleado.id=indiceLibre;
 }

 eEmpleado CargarEmpleado()
 {
	 eEmpleado unEmpleado;
	 char auxiliarSueldo[7];

     PedirString("\nIngrese nombre: ","Error. Reingrese nombre: ",51,unEmpleado.nombre);
     PedirString("Ingrese apellido: ","Error. Reingrese apellido: ",51,unEmpleado.apellido);
     unEmpleado.sector= PedirEntero("Ingrese sector: ","Error, reingrese sector valido: ");

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
    unEmpleado.isEmpty=FALSE; //mi bandera de que el lugar ya esta ocupado

    return unEmpleado;
 }



 int BuscarLibre(eEmpleado listaEmpleados[],int cant)
 {
     int index=-1;
     for(int i=0;i<cant;i++)
     {
         if(listaEmpleados[i].isEmpty==TRUE)
         {
             index=i;
             break;
         }
     }
     return index; //Devuelve el indice donde puedo guardar el dato, o -1(si no hay espacio)
 }

//Listado de los empleados ordenados alfabéticamente por Apellido y Sector.


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

void EliminarUnEmpleadoPorID(eEmpleado listaEmpleados[],int contadorEmpleadosCargados,int idEliminar)
{
    listaEmpleados[idEliminar].isEmpty=TRUE;
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
            if( strcmp(unEmpleado[i].apellido,unEmpleado[j].apellido)>0 || (strcmp(unEmpleado[i].apellido,unEmpleado[j].apellido)==0 ) && (unEmpleado[i].sector) < (unEmpleado[j].sector) )
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

