#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
  int opcion;
  float primerNumIngresado;
  float segundoNumIngresado;
  float suma;
  float resta;
  float multiplicacion;
  float division;
  int factorialPrimerNumero;
  int factorialSegundoNumero;
  int banderaIngresoNum1;
  int banderaIngresoNum2;
  int banderaPrimeraVez;
  int banderaCalculoRealizado;

  banderaPrimeraVez=0;
  banderaIngresoNum1=0;
  banderaIngresoNum2=0;
  banderaCalculoRealizado=0;

  do
  {
    if(banderaPrimeraVez==0)
    {
      printf("****************************************");
      printf("\n\nBIENVENIDOS A NUESTRA CALCULADORA\n");
      printf("****************************************\n");
      banderaPrimeraVez=1;
    }
    opcion=MostrarMenu(banderaIngresoNum1,banderaIngresoNum2,primerNumIngresado,segundoNumIngresado);

    switch (opcion)
	{
	    case 1:
	        printf ("\nIngrese aqui el 1er operando: ");
	        scanf ("%f", &primerNumIngresado);
	        banderaIngresoNum1=1;
	        break;
	    case 2:
	        printf ("\nIngrese aqui el 2do operando: ");
	        scanf ("%f", &segundoNumIngresado);
	        banderaIngresoNum2=1;
	        break;
	    case 3:
            if(banderaIngresoNum1 !=0 && banderaIngresoNum2 !=0)
            {
                suma = SumarNumeros (primerNumIngresado, segundoNumIngresado);
                resta = RestarNumeros (primerNumIngresado, segundoNumIngresado);
                multiplicacion=MultiplicacionNumeros (primerNumIngresado, segundoNumIngresado);
                division = DividirNumeros (primerNumIngresado, segundoNumIngresado);
                factorialPrimerNumero=CalcularFactorial(primerNumIngresado);
                factorialSegundoNumero=CalcularFactorial(segundoNumIngresado);
                banderaCalculoRealizado=1;
            }else
            {
                printf("\nAntes de calcular las operaciones. Por favor ingrese los operandos.\n");
            }
            break;
        case 4:
            if(banderaCalculoRealizado==1)
            {
                printf ("El resultado de  %.2f + %.2f es: %.2f \n",
                primerNumIngresado, segundoNumIngresado, suma);
                printf ("El resultado de  %.2f - %.2f es: %.2f \n",
                primerNumIngresado, segundoNumIngresado, resta);
                printf ("El resultado de  %.2f * %.2f es: %.2f \n",
                primerNumIngresado, segundoNumIngresado, multiplicacion);

                if(segundoNumIngresado!=0)
                {
                    printf ("El resultado de  %.2f / %.2f es: %.2f \n",primerNumIngresado, segundoNumIngresado, division);
                }else
                {
                    printf("No es posible dividir por 0\n");
                }

                if(CalcularFactorial(primerNumIngresado)!=0 && CalcularFactorial(segundoNumIngresado)!=0)
                {
                    printf("El factorial de %.2f es: %d y El factorial de %.2f es: %d \n", primerNumIngresado,factorialPrimerNumero,segundoNumIngresado,factorialSegundoNumero);
                }else
                {
                    printf("No se puede calcular el factorial de un numero decimal, ni de un numero negativo.\n");
                }
            }else
            {
                printf("\nAntes de mostrarle los resultados, tenemos que calcularlos. Por favor, una vez ingresados los datos, seleccione la opcion 3.\n");
            }

            break;

        case 5:
            printf ("\n¡Gracias por usar nuestra calculadora!\n");
            break;
	}

    }while (opcion != 5);
}
