#include "funciones.h"
#include <stdio.h>

int MostrarMenu(int banderaIngresoNum1,int banderaIngresoNum2,float primerNumIngresado, float segundoNumIngresado)
{

    int opcion;

   if(banderaIngresoNum1==0 && banderaIngresoNum2==0)
    {
        printf("\n1.Ingresar el 1er operando (A=x)\n2.Ingresar el 2do operando (B=x)\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n");
        printf ("Elija una opcion: ");
        scanf ("%d", &opcion);
    }else
    {
        if(banderaIngresoNum1!=0 && banderaIngresoNum2==0)
        {
            printf("\n1.Ingresar el 1er operando (A= %.2f)\n2.Ingresar el 2do operando (B=x)\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n",primerNumIngresado);
            printf ("Elija una opcion: ");
            scanf ("%d", &opcion);
        }else
        {
            if(banderaIngresoNum1==0 && banderaIngresoNum2!=0)
            {
                printf("\n1.Ingresar el 1er operando (A=X)\n2.Ingresar el 2do operando (B= %.2f )\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n",segundoNumIngresado);
                printf ("Elija una opcion: ");
                scanf ("%d", &opcion);

            }else
            {
                printf("\n1.Ingresar el 1er operando (A= %.2f )\n2.Ingresar el 2do operando (B= %.2f )\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n",primerNumIngresado,segundoNumIngresado);
                printf ("Elija una opcion: ");
                scanf ("%d", &opcion);
            }
        }

    }
    return opcion;
}



float
SumarNumeros (float primerNumero, float segundoNumero)
{
  float suma;
  suma = primerNumero + segundoNumero;
  return suma;
}


float RestarNumeros (float primerNumero, float segundoNumero)
{
  float resta;
  resta = primerNumero - segundoNumero;
  return resta;
}


float MultiplicacionNumeros (float primerNumero, float segundoNumero)
{
  float multiplicacion;
  multiplicacion = primerNumero * segundoNumero;
  return multiplicacion;
}



float DividirNumeros (float numero1, float numero2)
{
    float division;
    if(numero2!=0)
    {
      division = numero1 / numero2;
    }
    return division;
}

int ValidarNumeroParaFactorial(float decimal)
{
  int valido;
  int entero;

  entero = decimal;
  valido=1;

  if (decimal - entero || entero < 0)
  {
    valido=0;
  }

    return valido;
}


long int CalcularFactorial(int numero)
{
    long int resultado;
    resultado=0;

    if(ValidarNumeroParaFactorial(numero)==1)
    {
        if(numero == 0)
        {
            resultado = 1;
        }
        else
        {
            resultado = numero * CalcularFactorial(numero - 1);
        }

    }
    return resultado;
}
