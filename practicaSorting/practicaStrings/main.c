#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nom[20];
    char ape[25];
    char nombreCompleto[55];

    printf("Ingrese su nombre: \n");
    gets(nom);

    printf("Ingrese su apellido: \n");
    gets(ape);

    strcat(ape,", ");
    strcpy(nombreCompleto,ape);
    strcat(nombreCompleto,nom);

    printf("Su nombre es: %s\n",nombreCompleto);

    //puts(nombreCompleto);

    return 0;
}
