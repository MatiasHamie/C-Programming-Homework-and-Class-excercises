#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    float pesoEmpleado;
    int contadorPesados=0;
    int contadorLivianos=0;
    char seguir;

    do
    {
        printf("Ingrese peso del empleado\n");
        scanf("%f", &pesoEmpleado);
        getchar();

        while(pesoEmpleado<40.0)
        {
            printf("Ingrese un peso valido\n");
            scanf("%f", &pesoEmpleado);
            getchar();
        }

        if(pesoEmpleado<=80.0)
        {
            contadorLivianos++;
        }
        else
        {
            contadorPesados++;
        }

        printf("Ingrese la letra 's' para continuar o 'n' para terminar\n");
        seguir=getchar();
        seguir=tolower(seguir);
        getchar();
    }while(seguir=='s');

    printf("Cantidad de empleados con peso menor/igual a 80kg: %d\n",contadorLivianos);
    printf("Cantidad de empleados con peso mayor a 80kg: %d\n",contadorPesados);

    return 0;
}
