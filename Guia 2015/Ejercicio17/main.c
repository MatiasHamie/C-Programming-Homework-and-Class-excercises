#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int numeroIngresado;
    char seguir;

    do
    {
        printf("Ingrese un numero: \n");
        scanf("%d",&numeroIngresado);
        getchar();

        if(numeroIngresado%2==0)
        {
            printf("El numero es PAR\n");
        }
        else
        {
            printf("El numero es IMPAR\n");
        }

        printf("Ingrese la letra s para continuar\n");
        seguir=tolower(seguir);
        scanf("%c",&seguir);
        getchar();

        system("clear");
    }while(seguir=='s');

    return 0;
}
