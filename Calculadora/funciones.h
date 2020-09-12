
/** \brief Muestra el men� de opciones, en el cual se mostrar�n los datos que va ingresando el usuario.
 * \param int Bandera para saber si se ingreso o no el primer operando.
 * \param int Bandera para saber si se ingreso o no el segundo operando.
 * \param float El primer numero que ingreso el usuario.
 * \param float El segundo numero que ingreso el usuario.
 * \return int La opci�n elegida por el usuario.
 *
 */
 int MostrarMenu(int,int, float, float);


/** \brief Calcula la suma de los n�meros ingresados.
 *
 * \param El valor de uno de los sumandos.
 * \param El valor de uno de los sumandos
 * \return El resultado de la suma entre los n�meros.
 *
 */
float SumarNumeros (float, float);



/** \brief Calcula la resta de los n�meros ingresados.
 *
 * \param El valor del minuendo.
 * \param El valor del sustraendo.
 * \return El resultado de la resta entre los n�meros.
 *
 */
float RestarNumeros (float, float);


/** \brief Calcula la multiplicaci�n de los n�meros ingresados.
 *
 * \param Uno de los operandos de la multiplicac�on.
 * \param Uno de los operandos de la multiplicac�on.
 * \return  El resultado de la multiplicacion de los n�meros.
 *
 */
float MultiplicacionNumeros (float, float);


/** \brief Calcula la divisi�n de los n�meros ingresados(siempre y cuando el divisor no sea 0).
 *
 * \param El valor del dividendo.
 * \param El valor del divisor.
 * \return El resultado de la divisi�n de los n�meros.
 *
 */
float DividirNumeros (float, float);


/** \brief Verifica si se puede realizar el factorial de un n�mero(osea si es un entero positivo)
 *
 * \param float El n�meros que deseo verificar
 * \return int El resultado de la verificaci�n:
               0 si es valido(entero)
               1 si no es valido(decimal o negativo)
 *
 */

int ValidarNumeroParaFactorial(float);


/** \brief Calcula el factorial de un n�mero.
 *
 * \param int El n�meros sobre el cual se realiza el factorial.
 * \return long int -Si se pudo calcular --- devuelve resultado del factorial del n�mero.
                    -Si no se pudo calcular ---devuelve un 0.
 */
long int CalcularFactorial(int);
