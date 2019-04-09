#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char seguir;

    do
    {
        system("clear");
        printf("Desea seguir? ingrese 'S' o 'N'\n");
        scanf("%c",&seguir);
        getchar();
        seguir=toupper(seguir);
    }while(seguir=='S');


    return 0;
}
