/** * \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage1 Es el mensaje a ser mostrado en caso de que no sea un numero
* \param eMessage2 Es el mensaje a ser mostrado en caso de que no este dentro del rango
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* */
void inputs_getAndValidateInt(int* valor, char message[],char eMessage1[],char eMessage2[], int lowLimit, int hiLimit);


/** \brief valida que lo que se ingresa sea un  numero
 *
 * \param input a validar
 * \return int si solo se ingreseo una numero [0] si no [-1]
 *
 */
int validateNumber(char* numeroChar);



/** \brief Verifica si la cadena ingresada es un nombre valido
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param longitud int Longitud maxima que debe tener la cadena
 * \return int [1] si la cadena es valida,  [0] si no lo es
 *
 */
int isValidName(char* cadena,int longitud);

int ValidarRangoEntero(int dato,int lowLimit ,int hiLimit);

void inputs_PedirNombre(char [],char [],int , char []);
