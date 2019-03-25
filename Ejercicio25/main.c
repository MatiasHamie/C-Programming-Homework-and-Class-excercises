#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vendedor;
    float importeBoleta;
    float porcentajeComision=0.05;
    float gananciaVendedor1=0;
    float gananciaVendedor2=0;
    float gananciaVendedor3=0;
    char seguir;

    do
    {
        printf("Ingrese numero de vendedor '1', '2' o '3':\n");
        scanf("%d", &vendedor);
        getchar();

        while(vendedor!=1 && vendedor!=2 && vendedor!=3)
        {
            printf("REINGRESE el numero de vendedor '1', '2' o '3':\n");
            scanf("%d", &vendedor);
            getchar();
        }

        printf("Ingrese importe de venta:\n");
        scanf("%f", &importeBoleta);
        getchar();

        switch(vendedor)
            {
            case 1:
                gananciaVendedor1+=importeBoleta;
                break;
            case 2:
                gananciaVendedor2+=importeBoleta;
                break;
            case 3:
                gananciaVendedor3+=importeBoleta;
                break;
            }

        printf("Ingrese 's' para continuar o '0' para terminar\n");
        scanf("%c",&seguir);
        getchar();

    }while(seguir!='0');

    gananciaVendedor1*=0.05;
    gananciaVendedor2*=0.05;
    gananciaVendedor3*=0.05;

    printf("Ganancia vendedor 1: %.2f\n",gananciaVendedor1);
    printf("Ganancia vendedor 2: %.2f\n",gananciaVendedor2);
    printf("Ganancia vendedor 3: %.2f\n",gananciaVendedor3);

    return 0;
}
