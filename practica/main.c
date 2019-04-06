#include <stdio.h>
#include <stdlib.h>

#define largoArrays 5

int sortingMenue();
int condicional(int opcionMenu, int i, int j, int legajos[], int nota1[], int nota2[], float promedios[], char sexos[]);

int main()
{
    int auxInt;
    int opcionMenu;
    int legajos[largoArrays]={123, 789, 456, 102, 104};
    int nota1[largoArrays]={9, 3, 5, 4, 8};
    int nota2[largoArrays]={3, 9, 2, 5, 8};
    float auxFloat;
    float promedios[largoArrays]={6, 6.5, 3.5, 4.5, 8};
    char sexos[largoArrays]={'f','m','m','m','f'};

    printf("*** Practica de arrays ***\n");
    printf("\n    *** Arrays sin ordenar ***\n");
    printf("LEGAJOS   NOTA1   NOTA2   PROMEDIOS\n");

    for(int i=0;i<largoArrays;i++){
        printf("   %d     %d        %d       %.2f\n",legajos[i],nota1[i],nota2[i],promedios[i]);
    }

    opcionMenu=sortingMenue();

    for(int i=0;i<largoArrays-1;i++){
        for(int j=i+1;j<largoArrays;j++){
            if(condicional(opcionMenu,i,j,legajos,nota1,nota2,promedios)){
                auxInt=legajos[i];
                legajos[i]=legajos[j];
                legajos[j]=auxInt;

                auxInt=nota1[i];
                nota1[i]=nota1[j];
                nota1[j]=auxInt;

                auxInt=nota2[i];
                nota2[i]=nota2[j];
                nota2[j]=auxInt;

                auxFloat=promedios[i];
                promedios[i]=promedios[j];
                promedios[j]=auxFloat;
                }
            }
        }

        printf("*** Arrays ordenados ***\n");
        printf("LEGAJOS   NOTA1   NOTA2   PROMEDIOS\n");

        for(int i=0;i<largoArrays;i++){
        printf("   %d     %d     %d     %.2f\n",legajos[i],nota1[i],nota2[i],promedios[i]);
        }

    return 0;
}

int sortingMenue(void)
{
    int eleccion;
    printf("\n\n* *** MENU DE ORDENAMIENTO DE DATOS ***    *\n");
    printf("* 1) Ordenar por 'LEGAJO' (Ascendente)     *\n");
    printf("* 2) Ordenar por 'LEGAJO' (Descendente)    *\n\n");
    printf("* 3) Ordenar por 'NOTA 1' (Ascendente)     *\n");
    printf("* 4) Ordenar por 'NOTA 1' (Descendente)    *\n\n");
    printf("* 5) Ordenar por 'NOTA 2' (Ascendente)     *\n");
    printf("* 6) Ordenar por 'NOTA 2' (Descendente)    *\n\n");
    printf("* 7) Ordenar por 'PROMEDIOS' (Ascendente)  *\n");
    printf("* 8) Ordenar por 'PROMEDIOS' (Descendente) *\n");

    printf("\nIngrese una opcion para ordenar segun lo desee: ");
    scanf("%d",&eleccion);

    return eleccion;
}

int condicional(int opcionMenu, int i, int j, int legajos[], int nota1[], int nota2[], float promedios[])
{
    int condicion;

    switch(opcionMenu){
        case 1:
            condicion=legajos[i]>legajos[j];
            break;
        case 2:
            condicion=legajos[i]<legajos[j];
            break;
        case 3:
            condicion=nota1[i]>nota1[j];
            break;
        case 4:
            condicion=nota1[i]<nota1[j];
            break;
        case 5:
            condicion=nota2[i]>nota2[j];
            break;
        case 6:
            condicion=nota2[i]<nota2[j];
            break;
        case 7:
            condicion=promedios[i]>promedios[j];
            break;
        case 8:
            condicion=promedios[i]<promedios[j];
            break;
        default:
            printf("Opcion invalida...\n");
            break;
    }

    return condicion;
}
