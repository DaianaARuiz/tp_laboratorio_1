//#include "funcionesAuxiliares.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Reserva espacio en memoria dinamica para una estructura del tipo Employee
 *
 * \return Employee*
 *
 */Employee* employee_new();


/** \brief Llama a el constructor por defecto,e inicializa la variables con los parametros que recibe
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */Employee* employee_newParametros(char* ,char* ,char* ,char* );


void employee_delete();

/** \brief  Setea el valor del atributo id de la entidad Employee
 *
 * \param  Employee*
 * \param id int Valor a asignar al id.
 * \return int Retorna [1] si se pudo setear el valor [0] en caso de que no
 *
 */int employee_setId(Employee* ,int);


/** \brief Obtiene el valor del atributo  ID de la entidad Employee.
 *
 * \param this Employee*
 * \param id int* Parametro de salida
 * \return int Retorna [1] si se pudo obtener el valor [0] en caso de que no
 *
 */int employee_getId(Employee* this,int* id);

/** \brief   Setea el valor del atributo nombre de la entidad Employee
 *
 * \param this Employee*
 * \param nombre char* Valor a asignar a ese atributo.
 * \return int Retorna [1] si se pudo setear el valor [0] en caso de que no
 *
 */int employee_setNombre(Employee* ,char* );

/** \brief  Obtiene el valor del atributo NOMBRE de la entidad Employee.
 *
 * \param this Employee*
 * \param nombre char* Parametro de salida
 * \return int Retorna [1] si se pudo obtener el valor [0] en caso de que no
 *
 */int employee_getNombre(Employee*,char*);


/** \brief Setea el valor del atributo "horas trabajadas" de la entidad Employee
 *
 *
 * \param this Employee*
 * \param horasTrabajadas int Valor a asignar a ese atributo.
 * \return int Retorna [1] si se pudo setear el valor [0] en caso de que no
 *
 */ int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** \brief  Obtiene el valor del atributo "horasTrabajadas" de la entidad Employee.
 *
 * \param this Employee*
 * \param horasTrabajadas int* Parametro de salida
 * \return int Retorna [1] si se pudo obtener el valor [0] en caso de que no
 *
 */int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief Setea el valor del atributo "sueldo" de la entidad Employee
 *
 * \param this Employee*
 * \param sueldo int Valor a asignar a ese atributo.
 * \return int Retorna [1] si se pudo setear el valor [0] en caso de que no
 *
 */int employee_setSueldo(Employee* this,int sueldo);


/** \brief Obtiene el valor del atributo "sueldo" de la entidad Employee.
 *
 * \param this Employee*
 * \param sueldo int* Parametro de salida
 * \return int  Retorna [1] si se pudo obtener el valor [0] en caso de que no
 *
 */int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Imprime UNA entidad del tipo Employee con sus respectivos campos.
 *
 * \param empleado Employee*
 * \return void
 *
 */void  employee_showOneEmployee(Employee* empleado);

/** \brief Compara los sueldos de los empleados, establece un criterio de ordenamiento
 *
 * \param void*
 * \param void*
 * \return int Retorna  [1] si item1>item2
                        [0] si item1=item2
                        [-1] si item1<item2
 *
 */int employee_CompareBySueldo(void* , void* );

/** \brief Compara las horas trabajadas de los empleados, establece un criterio de ordenamiento
 *
 * \param void*
 * \param void*
 * \return int  [1] si item1>item2
                [0] si item1=item2
                [-1] si item1<item2
 *
 */int employee_CompareByHoras(void* , void*);

/** \brief  Compara los nombres de los empleados, establece un criterio de ordenamiento
 *
 * \param void*
 * \param void*
 * \return int  [1] si item1>item2
                [0] si item1=item2
                [-1] si item1<item2
 *
 */int employee_compareByName(void* , void*);

/** \brief  Compara los nombres de los empleados, establece un criterio de ordenamiento
 *
 * \param void*
 * \param void*
 * \return int [1] si item1>item2
                [0] si item1=item2
                [-1] si item1<item2
 *
 */int employee_CompareById(void* , void*);

#endif // employee_H_INCLUDED
