#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroIngresado;
    int numeroIncremental;

    printf("Ingrese un numero\n");
    scanf("%d", &numeroIngresado);
    getchar();
    system("clear");

    for(numeroIncremental=1;numeroIncremental<=numeroIngresado;numeroIncremental++)
    {
        printf("%d\n", numeroIncremental);
    }


    return 0;
}
