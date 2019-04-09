#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroIngresado;
    int contadorNumIng;
    int contadorEnunciado=1;
    int acumuladorPositivos=0;
    int acumuladorNegativos=1;

    for(contadorNumIng=0;contadorNumIng<10;contadorNumIng++)
    {
        printf("Ingrese el #%d numero\n", contadorEnunciado);
        scanf("%d", &numeroIngresado);
        getchar();

        if(numeroIngresado>0)
        {
            acumuladorPositivos+=numeroIngresado;
        }
        else
        {
            acumuladorNegativos*=numeroIngresado;
        }

        contadorEnunciado++;
    }

    printf("Suma positivos: %d\n", acumuladorPositivos);
    printf("Producto negativos: %d\n", acumuladorNegativos);

    return 0;
}
