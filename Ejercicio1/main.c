#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroIngresado;
    int contador;
    int contadorPregunta;
    float acumulador;
    float promedio;

    acumulador=0;
    contadorPregunta=1;

    for(contador=0;contador<5;contador++)
    {

        printf("Ingrese el #%d numero\n",contadorPregunta);
        fflush(stdin);
        scanf("%d",&numeroIngresado);

        acumulador=acumulador+numeroIngresado;
        contadorPregunta++;
    }

    promedio=(float)acumulador/contador;

    printf("La media (o promedio) es: %.2f\n\n",promedio);

    return 0;
}
