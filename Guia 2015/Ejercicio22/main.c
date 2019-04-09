#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int aux;

    printf("Ingrese un numero\n");
    scanf("%d",&num1);
    getchar();

    printf("Ingrese otro numero\n");
    scanf("%d",&num2);
    getchar();

    system("clear");

    printf("Numero 1: %d\n", num1);
    printf("Numero 2: %d\n", num2);
    printf("Inviertiendo uno por el otro queda..\n");

    aux=num1;
    num1=num2;
    num2=aux;

    printf("Numero 1: %d\n", num1);
    printf("Numero 2: %d\n", num2);

    return 0;
}
