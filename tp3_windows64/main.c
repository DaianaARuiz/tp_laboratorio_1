#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). (x)
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).(x)
     3. Alta de empleado (x)
     4. Modificar datos de empleado (x)
     5. Baja de empleado (x)
     6. Listar empleados (x)
     7. Ordenar empleados (x)
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto). (x)
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).(x)
    10. Salir (x)
*****************************************************/


int main()
{
    printf("\n*********************************************************************************");
    printf("\n\t\t\tTRABAJO PRACTICO 3 \n\n Alumna:Ruiz Daiana Ayelen\n Division:1C \n");
    printf("\n*********************************************************************************\n");

    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    if(listaEmpleados!=NULL)
    {
        do{
            printf("\n1. Cargar los datos (modo texto).\n2. Cargar los datos (modo binario).\n3. Alta\n4. Modificar datos\n5. Baja\n6. Listar \n");
            printf("7. Ordenar\n8. Guardar los datos (modo texto).\n9. Guardar los datos (modo binario).\n10. Salir\n");
            inputs_getAndValidateInt(&option,"\nIngrese su opcion: ","Error.Debe ingresar un numero:","\nError,solo puedes ingresar del [1] al [10]:",1,10);

            switch(option)
            {
                case 1:
                    if(controller_loadFromText("data.csv",listaEmpleados))
                    {
                        printf("\nLos datos fueron cargados en modo Texto.\n");
                    }else{
                    printf("\nError al cargar los datos.\n");}
                    break;
                case 2:
                    controller_loadFromBinary("date.dat",listaEmpleados);
                    break;
                case 3:
                    if(controller_addEmployee(listaEmpleados))
                    {
                        printf("\nEmpleado cargado con exito.\n");
                    }else
                    {
                         printf("\nNo se pudo cargar el empleado.\n");
                    }
                    break;
                case 4:
                    if(ll_isEmpty(listaEmpleados)==0){
                        controller_ListEmployee(listaEmpleados);
                        if( controller_editEmployee(listaEmpleados) ){
                                printf("\nEmpleado modificado con exito.\n");
                        }else{
                            printf("\nError. No se pudo modificar el empleado.\n");
                        }
                    }else{
                         printf("\nError. No hay empleados cargados.\n");
                    }
                    break;
                case 5:
                     if(ll_isEmpty(listaEmpleados)==0){
                        controller_ListEmployee(listaEmpleados);
                         if(controller_removeEmployee(listaEmpleados)){
                            printf("\nEmpleado eliminado con exito.\n");
                        }else{
                             printf("\nError. No se pudo eliminar el empleado.\n");
                        }
                     }else{
                         printf("\nError. No hay empleados cargados.\n");
                     }

                    break;
                case 6:
                    if(ll_isEmpty(listaEmpleados)==0){
                      if(controller_ListEmployee(listaEmpleados)!=1)
                      {
                           printf("\nError. No se pudo cargar la lista.\n");
                      }
                    }else{
                         printf("\nError. No hay empleados cargados.\n");
                    }
                    break;
                case 7:
                    if(ll_isEmpty(listaEmpleados)==0){
                        if(controller_sortEmployee(listaEmpleados )){
                            printf("\nLa lista se ordenó con exito.\n");
                        }else{
                             printf("\nHubo un error al ordenar la lista.\n");
                        }
                    }else{
                         printf("\nError. No hay empleados cargados.\n");
                    }
                    break;
                case 8:
                    if(ll_isEmpty(listaEmpleados)==0){
                        if(controller_saveAsText("data.csv",listaEmpleados)){
                            printf("\nLos datos se guardaron con exito.(en modo texto)\n");
                        }else{
                            printf("\nHubo un error al cargar los datos.\n");
                        }
                    }else{
                         printf("\nError. No hay empleados cargados.\n");
                    }
                    break;
                case 9:
                    if(ll_isEmpty(listaEmpleados)==0){
                        if(controller_saveAsBinary("databin",listaEmpleados)){
                            printf("\nLos datos se guardaron con exito.(en modo binario)\n");
                        }else{
                            printf("\nHubo un error al cargar los datos.\n");
                        }
                    }else{
                         printf("\nError. No hay empleados cargados.\n");
                     }
                    break;
            }
        }while(option != 10);
    }else
    {
        printf("Error. No hubo espacio en memoria para cargar la lista.");
    }

    return 0;
}
