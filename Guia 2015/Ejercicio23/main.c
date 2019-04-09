#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int num3;
    int numMax;

    printf("Ingrese el primer numero:\n");
    scanf("%d", &num1);
    getchar();

    printf("Ingrese el segundo numero:\n");
    scanf("%d", &num2);
    getchar();

    printf("Ingrese el tercer numero:\n");
    scanf("%d", &num3);
    getchar();

    if(num1>num2 && num1>num3)
    {
        numMax=num1;
    }
    else
    {
        if(num2>num3)
        {
            numMax=num2;
        }
        else
        {
            numMax=num3;
        }
    }
    system("clear");

    printf("Primer numero: %d\n", num1);
    printf("Segundo numero: %d\n", num2);
    printf("Tercer numero: %d\n", num3);
    printf("El mas grande es: %d\n", numMax);

    return 0;
}
