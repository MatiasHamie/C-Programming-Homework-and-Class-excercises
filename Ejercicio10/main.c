#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contadorPares=0;
    int contadorImpares=0;
    int numero;

    for(numero=100;numero>0;numero--)
    {
        if(numero%2==0)
        {
            contadorPares++;
        }
        else
        {
            contadorImpares++;
        }
    }

    printf("Cantidad de numeros pares: %d\n", contadorPares);
    printf("Cantidad de numeros impares: %d\n\n", contadorImpares);

    return 0;
}
