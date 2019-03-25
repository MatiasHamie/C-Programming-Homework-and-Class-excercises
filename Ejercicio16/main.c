#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroIngresado;
    char seguir;

    do
    {
        printf("\nPor favor ingrese un numero\n");
        scanf("%d",&numeroIngresado);
        getchar();

        system("clear");

        if(numeroIngresado<0)
        {
            printf("El numero es negativo\n");
        }
        else
        {
            printf("El numero es positivo\n");
        }

        printf("Ingrese 's' para continuar\n");
        seguir=getchar();
    }while(seguir=='s');

    return 0;
}
