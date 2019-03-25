#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;

    for(numero=100;numero>0;numero--)
    {
        if(numero%2==0)
        {
            printf("El %d es numero par\n",numero);
        }
    }

    return 0;
}
