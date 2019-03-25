#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main()
{
    int numeroFinal;
    int contadorDivisores=0;
    int divisor;//Ojo con inicializarlo con 0, indeterminado!

    printf("Ingrese el numero a verificar si es primo:\n");
    scanf("%d",&numeroFinal);


    for(divisor=1;divisor<=numeroFinal;divisor++)
    {
        if(numeroFinal%divisor==0)
        {
            contadorDivisores++;
        }
    }

    system("clear");

    if(contadorDivisores>2)
    {
        printf("El numero %d no es primo",numeroFinal);
    }
    else
    {
        printf("El numero %d es primo",numeroFinal);
    }

    return 0;
}
