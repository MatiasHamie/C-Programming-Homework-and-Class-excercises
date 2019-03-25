#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int multiplo;

    for(numero=0;numero<100;numero++)
    {
        if(numero%6==0)
        {
            printf("%d ", numero);
        }
    }


    return 0;
}
