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
#define TAM 1000
#include "empleados.h"

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
                        addEmployees(listaEmpleados,TAM,indiceLibre);
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
                            printEmployees (listaEmpleados,TAM);
                            printf("\nIngrese el ID del empleado que desea modificar:");
                            scanf("%d", &idAModificar);

                            if(findEmployeeById(idAModificar,contadorEmpleadosCargados,listaEmpleados)!=-1)
                            {
                                printf("\n1-MODIFICAR NOMBRE\n2-MODIFICAR APELLIDO\n3-MODIFICAR SECTOR\n4-MODIFICAR SUELDO\nSeleccione la accion que desea realizar:");
                                scanf("%d", &opcionModificar);
                                ModificarUnEmpleado(listaEmpleados,idAModificar,opcionModificar);
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
                            printEmployees (listaEmpleados,TAM);
                            printf("\nIngrese el ID del empleado que desea dar de baja:");
                            scanf("%d", &idEliminar);
                            if(removeEmployee(listaEmpleados,contadorEmpleadosCargados,idEliminar)!=-1)
                            {
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
                                         printEmployees (listaEmpleados,contadorEmpleadosCargados);
                                        break;
                                    case 2:
                                        sortEmployees(listaEmpleados,TAM);
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
                            printf("\nPor favor.Primero realice la carga de los empleados\n");
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
