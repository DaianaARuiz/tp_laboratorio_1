/** \brief Imprime todos los empleados que contiene el linked List
 *
 * \param pListEmployee LinkedList*
 * \return void
 *
 */void employee_showAllEmployees(LinkedList* );

/** \brief Pide el id que se desea eliminar, verifica que existe y retorna el index de ese id
 *
 * \param pListEmployee LinkedList*
 * \return int index del id a eliminar
 *
 */int employee_askIdToDelete(LinkedList* );

/** \brief Pide un id al usuario, verifica que exista, muestra mensajes de error en caso de que no y devuelve el indice del ID buscado
 *
 * \param pListEmployee LinkedList*
 * \param msj[] char Mensaje solicitando el id
 * \param emsj1[] char Mensaje en caso de que se ingresen letras
 * \param emsj2[] char Mensaje en caso de que se ingrese un numero fuera del rango
 * \param int* Parametro de salida, puntero al indexID
 * \return void
 *
 */void employee_AskIdAndGetTheIndex(LinkedList* , char [],char [],char [],int*);

int employee_searchById(LinkedList* pListEmployee,int idIngresado, int*);

/** \brief Genera un nuevo empleado a partir de los datos ingresados por el asuario
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna [1] si se pudo generar un nuevo empleado [0] en caso de que no
 *
 */
int employee_registerEmployee(LinkedList* pArrayListEmployee);


/** \brief Busca el valor del mayor id generado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int El valor de ese id
 *
 */int employee_lastId(LinkedList* pArrayListEmployee);


/** \brief Genera el valor de un nuevo id
 *
 * \param LinkedList* pArrayListEmployee
 * \param puntero a id, parametro de salida
 * \return
 *
 */void employee_calculateNewId(LinkedList* pArrayListEmployee,int* id);

/** \brief Modifica campos de una entidad de acuerdo a la opcion elegida por el usuario
 *
 * \param empleado Employee*
 * \param opcion int El numero de la opcion elegida por el usuario
 * \return int Retorna [1] si se pudo realizar la modificacion [0] en caso de que no
 *
 */int employee_modifyEmployee(Employee* empleado, int opcion);

/** \brief Recorre la lista, obtiene los valores de sus campos y los imprime en un archivo
 *
 * \param pArrayListEmployee LinkedList*
 * \param pFile FILE*
 * \param len int la longitud de la lista
 * \return int Retorna [1] si se pudo escribir el archivo [0] en caso de que no

 *
 */
int guardarEnTexto(LinkedList* pArrayListEmployee, FILE* pFile, int len);

