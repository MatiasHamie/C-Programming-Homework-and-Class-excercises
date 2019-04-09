#include <stdio.h>
#include <stdlib.h>

int sumarNumeros(int,int);

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("Por favor ingrese el primer numero\n");
    fflush(stdin);
    scanf("%d",&num1);

    printf("Por favor ingrese el segundo numero\n");
    fflush(stdin);
    scanf("%d",&num2);

    resultado=sumarNumeros(num1,num2);

    printf("El resultado de la suma es: %d\n\n",resultado);

    return 0;
}

int sumarNumeros(int numero1, int numero2)
{
    int resultadoSuma;

    resultadoSuma=numero1+numero2;

    return resultadoSuma;
}
