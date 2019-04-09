#include <stdio.h>
#include <stdlib.h>

float productoDosNros(int,int);
float cuadradoUnNro(int);

int main()
{
    int numero1;
    int numero2;
    int producto;
    int cuadrado;

    printf("Ingrese un numero\n");
    fflush(stdin);
    scanf("%d",&numero1);

    while(numero1==0)
    {
        printf("ERROR, Reingrese un numero distinto de 0\n");
        fflush(stdin);
        scanf("%d",&numero1);
    }

    printf("Ingrese otro numero\n");
    fflush(stdin);
    scanf("%d",&numero2);

    while(numero2==0)
    {
        printf("ERROR, Reingrese un numero distinto de 0\n");
        fflush(stdin);
        scanf("%d",&numero2);
    }

    system("clear");

    producto=productoDosNros(numero1,numero2);
    cuadrado=cuadradoUnNro(numero1);

    printf("El producto es: %d\n", producto);
    printf("Numero 1 al cuadrado: %d\n\n", cuadrado);

    return 0;
}

float productoDosNros(int num1, int num2)
{
    float producto;

    producto=(float)num1*num2;

    return producto;
}

float cuadradoUnNro(int num1)
{
    float cuadrado;

    cuadrado=(float)num1*num1;

    return cuadrado;
}











   /*
    ------------------
    #include <ctype.h>
    #include <conio.h>
    ------------------
    char seguir;
    int contadorBorrado;
    ------------------
    printf("Presione S para continuar\n");
    fflush(stdin);
    scanf("%c",&seguir);
    ------------------
    seguir=tolower(seguir)
    if(seguir=='s')
    {
        system("clear");

        producto=numero1*numero2;

        printf("El producto es: %d\n",producto);
    }
    else
    {
        printf("Ok, el programa entonces no sigue..\n");
        printf("-----------------------------------\n");
        printf("---------FIN DEL PROGRAMA----------\n");
        printf("-----------------------------------\n");
    }
    */

    // clrscr();

    /*
    for(contadorBorrado=0;contadorBorrado<20;contadorBorrado++)
    {
        printf("\n");
    }
    */

