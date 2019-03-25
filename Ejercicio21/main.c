#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroIngresado;
    int multiplo;
    int contadorMultiplo=0;

    printf("Ingrese un numero:\n");
    scanf("%d", &numeroIngresado);
    getchar();

    for(multiplo=1;multiplo<=numeroIngresado;multiplo++)
    {
        if(multiplo%3==0)
        {
            contadorMultiplo++;
        }
    }
    system("clear");
    printf("Cantidad de multiplos de 3: %d\n", contadorMultiplo);

    return 0;
}
