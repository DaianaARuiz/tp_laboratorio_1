#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

void inputs_getAndValidateInt(int* input, char message[],char eMessage1[],char eMessage2[], int lowLimit, int hiLimit)
{
    char bufferNumStr[200];
    int bufferNum;

    printf("%s", message);
    fflush(stdin);
    scanf("%s", bufferNumStr);

    while(validateNumber(bufferNumStr)==0)
    {
        printf("%s", eMessage1);
        fflush(stdin);
        scanf("%s", bufferNumStr);
    }

    bufferNum=atoi(bufferNumStr);
    while(ValidarRangoEntero(bufferNum,lowLimit,hiLimit)==0)
    {
        printf("%s", eMessage2);
        fflush(stdin);
        scanf("%d", &bufferNum);
    }
    *input=bufferNum;
}

int ValidarRangoEntero(int dato,int lowLimit ,int hiLimit)
{
    int valido=1;

    if(dato<lowLimit || dato>hiLimit)
    {
       valido=0;
    }

    return valido;
}


int validateNumber(char* numeroStr)
{
    int valido=1;
    for(int i=0;i<strlen(numeroStr);i++)
    {
	  if(numeroStr[i] < '0' || numeroStr[i] > '9')
	  {
		  valido=0;
	  }
    }
   return valido;
}


int isValidName(char* cadena,int longitud)
{
    int retorno=1;
    if(cadena !=NULL && longitud>0)
    {
        for(int i=0; cadena[i]!='\0' && i<longitud; i++)
        {
            if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z'))
            {
                retorno=0;
            }
        }
    }
    return retorno;
}

void inputs_PedirNombre(char texto[],char textoError[],int max, char input[])
{
    char auxiliar[500];

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);
    while(!isValidName(auxiliar,max)|| strlen(auxiliar)>max-1)
    {
        printf("%s", textoError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
    }
     strcpy(input,auxiliar);
}



