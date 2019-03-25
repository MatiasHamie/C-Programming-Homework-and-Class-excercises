#include <stdio.h>
#include <stdlib.h>

int main()
{
    float lado1;
    float lado2;
    float lado3;
    float ladoMax;
    float sumaLadosMenores=0;

    printf("Ingrese el primer lado:\n");
    scanf("%f", &lado1);
    getchar();

    printf("Ingrese el segundo lado:\n");
    scanf("%f", &lado2);
    getchar();

    printf("Ingrese el tercer lado:\n");
    scanf("%f", &lado3);
    getchar();

    if(lado1>lado2 && lado1>lado3)
    {
        ladoMax=lado1;
        sumaLadosMenores=lado2+lado3;
    }
    else
    {
        if(lado2>lado3)
        {
            ladoMax=lado2;
            sumaLadosMenores=lado1+lado3;
        }
        else
        {
            ladoMax=lado3;
            sumaLadosMenores=lado1+lado2;
        }
    }

    while(sumaLadosMenores<ladoMax)
    {
        system("clear");
        printf("Error, lados los lados no forman un triangulo\n");
        printf("Reingrese el primer lado:\n");
        scanf("%f", &lado1);
        getchar();

        printf("Reingrese el segundo lado:\n");
        scanf("%f", &lado2);
        getchar();

        printf("Reingrese el tercer lado:\n");
        scanf("%f", &lado3);
        getchar();
    }

    if(lado1==lado2 && lado1==lado2 && lado1==lado3)
    {
        printf("El triangulo es equilatero\n");
    }
    else
    {
        if(lado1!=lado2 && lado1!=lado3 && lado2!=lado3)
        {
            printf("El triangulo es escaleno");
        }
        else
        {
            printf("El triangulo es isoceles");
        }
    }

    return 0;
}
