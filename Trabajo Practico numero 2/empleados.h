typedef struct
{
 int id;
 char nombre[51];
 char apellido[51];
 float sueldo;
 int sector;
 int isEmpty;
}eEmpleado;


/** \brief  Inicializa un array con el valor indicado
 *
 * \param [] eEmpleado Es el array a ser inicializado
 * \param int La longitud de dicho array
 * \return int El resultado de la inicializacion:
                                                 - (0)Si fue inicializado exitosamente
                                                 - (-1)Si no se inicializó
 *
 */int initEmployees(eEmpleado [],int);


/** \brief Solicita los valores a guardar en una estructura y los guarda en una posición libre
 *
 * \param [] eEmpleado El array donde se cargaran los valores
 * \param int La longitud del array
 * \param int El indice de la posicion libre donde se cargaran los datos
 * \return eEmpleado Una copia de todos los valores que se cargaron
 *
 */eEmpleado addEmployees(eEmpleado [],int,int);

/** \brief Busca el primer indice libre en un array
 *
 * \param [] eEmpleado El array donde se buscará
 * \param int  La longitud de dicho array
 * \return int Devuelve -el indice donde puedo guardar el dato, o
                        - (-1) si no hay espacio
 *
 */int BuscarLibre(eEmpleado [],int);

/** \brief Imprime el array de empleados de forma encolumnada.
 *
 * \param [] eEmpleado El array a imprimir
 * \param int  La longitud de dicho array
 * \return void
 *
 */ void printEmployees(eEmpleado [],int );



/** \brief Ordena los empleados por nombre y sector
 *
 * \param [] eEmpleado
 * \param int Tamaño array
 * \return void
 *
 */
void sortEmployees(eEmpleado [],int);

/** \brief Modifica un campo a eleccion del array de empleados
 *
 * \param [] eEmpleado
 * \param int El id del empleado que se quiere modificar
 * \param int Numero que representa cual es el campo que se quiere modificar
 * \return void
 *
 */
void ModificarUnEmpleado(eEmpleado [],int,int);



/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
 *
 * \param int El id a buscar
 * \param int El tamaño del array donde lo buscará
 * \param [] eEmpleado El array donde buscará el id
 * \return int Devuelve -(-1)Si no encuentra ese id
                        -El numero del id en caso de encontrarlo

 *
 */int findEmployeeById(int,int,eEmpleado []);

/** \brief Elimina de manera lógica un empleado recibiendo como parámetro su Id.
 *
 * \param [] eEmpleado
 * \param int El longitud del array(solo la longitud de datos ya cargados)
 * \param int El id a eliminar
 * \return int Devuelve -(-1)Si no pudo eliminar
                        -0 si se elimino correctamente

 *
 */int removeEmployee(eEmpleado [],int,int);

/** \brief Calcula la suma de todos los sueldos ingresados
 *
 * \param [] eEmpleado
 * \param int Cantidad de empleados cargados
 * \return float La suma de todos los sueldos ingresados
 *
 */ float CalcularTotalSalarios(eEmpleado [],int);


/** \brief Calcula el salario promedio de los empleados
 *
 * \param [] eEmpleado
 * \param int Cantidad de empleados cargados
 * \param float El acumulador de sueldos
 * \return float Devuelve el sueldo promedio de los empleados
 *
 */float CalcularPromedioSalarios(eEmpleado [],int ,float);

/** \brief Cuenta la cantidad de empleados cuyo sueldo es mayor a el sueldo promedio
 *
 * \param [] eEmpleado
 * \param int Cantidad de empleados ingresados
 * \param float Sueldo promedio
 * \return float
 *
 */float ContarEmpleadosSueldoMayorAlPromedio(eEmpleado [],int ,float);

/** \brief Verifica si el valor recibido contiene solo letras
 *
 * \param [] char Array con la cadena a ser analizada
 * \return int Devuelve - (1) si contiene solo ' ' y letras, o
                         - (0) en caso de que no
 *
 */
int ValidarLetras(char []);


/** \brief Verifica si el valor recibido es numérico
 *
 * \param [] char  Array con la cadena a ser analizada
 * \return int Devuelve - (1) si contiene solo numeros, o
                        -(0) en caso de que tenga otro tipo de caracteres
 *
 */
int ValidarNumero(char []);


/** \brief Verifica si el valor recibido es numérico flotante
 *
 * \param numero[] char Array con la cadena a ser analizada
 * \return int Devuelve  - (1) si contiene solo numeros y ".", o
                         - (0) en caso de que tenga otro tipo de caracteres
 *
 */
int ValidarFlotante(char numero[]);



/** \brief Solicita un numero entero y valida que no se ingrese otro tipo de dato
            (mostrando error y pidiendo reingreso en caso de que no sea asi)
 *
 * \param [] char El mensaje a mostrar para solicitar el numero
 * \param [] char  El mensaje de error que se mostrará en caso de que lo ingresado no sea un numero
 * \return int Devuelve el numero ingresado
 *
 */
int PedirEntero(char [],char []);


/** \brief Solicita un string, valida que contenga caracteres alfabeticos(mostrando error y pidiendo reingreso en caso de que no sea asi)
 y lo guarda en una variable
 *
 * \param [] char El mensaje solicitando el texto
 * \param [] char El mensaje en caso de error
 * \param int El tamaño maximo que soporta el array donde se guardara el texto ingresado
 * \param [] char El array donde se guardará la texto ingresado
 * \return void
 *
 */
void PedirString(char [],char [],int ,char []);



/** \brief Solicita un numero flotante, y valida que contenga caracteres numericos(mostrando error y pidiendo reingreso en caso de que no sea asi)
 *
 * \param texto[] char El mensaje solicitando el dato
 * \param textoError[] char El mensaje en caso de error
 * \return float Devuelve el numero ingresado
 *
 */
float PedirFlotante(char texto[],char textoError[]);


