#include <stdio.h>
#include <stdlib.h>

int RestaDosNumeros(int, int);

int main()
{
    int num1;
    int num2;
    int resta;

    printf("Ingrese el primer numero\n");
    fflush(stdin);
    scanf("%d",&num1);

    printf("Ingrese el segundo numero\n");
    fflush(stdin);
    scanf("%d",&num2);

    resta=RestaDosNumeros(num1,num2);

    if(resta<0)
    {
        printf("Resultado negativo: %d",resta);
    }
    else
    {
        printf("Resultado positivo: %d",resta);
    }

    return 0;
}

int RestaDosNumeros(int numero1, int numero2)
{
    int resultadoResta;

    resultadoResta=numero1-numero2;

    return resultadoResta;
}
