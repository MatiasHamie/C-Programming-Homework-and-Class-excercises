#include <stdio.h>
#include <stdlib.h>

int main()
{
    float base;
    float altura;
    float area;

    printf("Ingrese la base del triangulo\n");
    fflush(stdin);
    scanf("%f",&base);

    printf("Ingrese la atura del triangulo\n");
    fflush(stdin);
    scanf("%f",&altura);

    area=(base*altura)/2;

    printf("El area del triangulo es: %.2f", area);

    return 0;
}
