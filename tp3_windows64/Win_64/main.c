#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
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
                      controller_ListEmployee(listaEmpleados);
                    }else{
                         printf("\nError. No hay empleados cargados.\n");
                    }
                    break;
                case 7:
                    /*
                    if(controller_sortEmployee(listaEmpleados))
                    {
                        printf("Los empleados se ordenaron correctamente");
                    }
                    */
                    break;
                case 8:
                    //controller_saveAsText("data.csv",listaEmpleados);
                    break;
                case 9:
                    //controller_saveAsBinary("databin",listaEmpleados);
                    break;
            }
        }while(option != 10);
    }else
    {
        printf("Error. No hubo espacio en memoria para cargar la lista.");
    }

    return 0;
}
