#include <stdio.h>
#include <stdlib.h>

float cuadradoNum(int);

int main()
{
    int num1;
    float cuadrado;

    printf("Ingrese un numero mayor que 0\n");
    fflush(stdin);
    scanf("%d",&num1);

    while(num1<0)
    {
        printf("ERROR, Ingrese un numero mayor que 0\n");
        fflush(stdin);
        scanf("%d",&num1);
    }

    cuadrado=cuadradoNum(num1);

    printf("El cuadrado del numero ingresado es: %.2f\n\n",cuadrado);

    return 0;
}

float cuadradoNum(int numero1)
{
    float cuadradoNumero;

    cuadradoNumero=(float)numero1*numero1;

    return cuadradoNumero;
}


