#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroIngresado;
    int numeroAnterior;
    int acumuladorNumeros=0;

    printf("Ingrese un numero:\n");
    scanf("%d", &numeroIngresado);
    getchar();

    for(numeroAnterior=numeroIngresado-1;numeroAnterior>=0;numeroAnterior--)
    {
        acumuladorNumeros+=numeroAnterior;
    }

    printf("La suma de los numeros anteriores a %d es: %d",numeroIngresado,acumuladorNumeros);

    return 0;
}
