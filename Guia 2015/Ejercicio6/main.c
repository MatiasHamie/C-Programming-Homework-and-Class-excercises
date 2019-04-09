#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroIngresado;
    int contadorNumeroIngresado;
    int contadorEnunciado;
    int contadorPositivo;
    int contadorNegativo;

    contadorEnunciado=1;
    contadorPositivo=0;
    contadorNegativo=0;

    for(contadorNumeroIngresado=0;contadorNumeroIngresado<10;contadorNumeroIngresado++)
    {
        printf("Ingrese el #%d numero\n",contadorEnunciado);
        fflush(stdin);
        scanf("%d",&numeroIngresado);

        if(numeroIngresado<0)
        {
            contadorNegativo++;
        }
        else
        {
            contadorPositivo++;
        }

        contadorEnunciado++;
    }

    printf("Cantidad de numeros mayores a cero: %d\n",contadorPositivo);
    printf("Cantidad de numeros menores a cero: %d\n\n",contadorNegativo);

    return 0;
}
