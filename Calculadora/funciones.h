
/** \brief Muestra el menú de opciones, en el cual se mostrarán los datos que va ingresando el usuario.
 * \param int Bandera para saber si se ingreso o no el primer operando.
 * \param int Bandera para saber si se ingreso o no el segundo operando.
 * \param float El primer numero que ingreso el usuario.
 * \param float El segundo numero que ingreso el usuario.
 * \return int La opción elegida por el usuario.
 *
 */
 int MostrarMenu(int,int, float, float);


/** \brief Calcula la suma de los números ingresados.
 *
 * \param El valor de uno de los sumandos.
 * \param El valor de uno de los sumandos
 * \return El resultado de la suma entre los números.
 *
 */
float SumarNumeros (float, float);



/** \brief Calcula la resta de los números ingresados.
 *
 * \param El valor del minuendo.
 * \param El valor del sustraendo.
 * \return El resultado de la resta entre los números.
 *
 */
float RestarNumeros (float, float);


/** \brief Calcula la multiplicación de los números ingresados.
 *
 * \param Uno de los operandos de la multiplicacíon.
 * \param Uno de los operandos de la multiplicacíon.
 * \return  El resultado de la multiplicacion de los números.
 *
 */
float MultiplicacionNumeros (float, float);


/** \brief Calcula la división de los números ingresados(siempre y cuando el divisor no sea 0).
 *
 * \param El valor del dividendo.
 * \param El valor del divisor.
 * \return El resultado de la división de los números.
 *
 */
float DividirNumeros (float, float);


/** \brief Verifica si se puede realizar el factorial de un número(osea si es un entero positivo)
 *
 * \param float El números que deseo verificar
 * \return int El resultado de la verificación:
               0 si es valido(entero)
               1 si no es valido(decimal o negativo)
 *
 */

int ValidarNumeroParaFactorial(float);


/** \brief Calcula el factorial de un número.
 *
 * \param int El números sobre el cual se realiza el factorial.
 * \return long int -Si se pudo calcular --- devuelve resultado del factorial del número.
                    -Si no se pudo calcular ---devuelve un 0.
 */
long int CalcularFactorial(int);
