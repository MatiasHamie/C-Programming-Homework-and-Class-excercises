#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main()
{
    int legajos[TAM] = {123, 543, 679, 432, 567, 111, 323, 145, 674, 543};
    int edades[TAM] = {23, 24, 21, 23, 22, 22, 44, 36, 29, 38};
    int legajoBuscado;
    //int auxInt;
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm', 'm', 'f', 'f', 'm', 'f'};
   // char auxChar;

    for(int i=0; i < TAM;  i++)
    {
        printf("%d      %c      %d\n", legajos[i], sexos[i], edades[i]);
    }

    printf("\nIngrese el legajo a buscar: \n");
    scanf("%d",&legajoBuscado);

    for(int i=0; i<TAM ; i++){
        if(legajoBuscado==legajos[i]){
            printf("\nEl legajo %d esta en el indice: %d y tiene el sexo: %c\n",legajoBuscado,i,sexos[i]);
            break;
        }
        else if(i==TAM-1){
            printf("\nEl legajo %d NO esta en el registro\n",legajoBuscado);
        }
    }
    /*
    for(int i=0; i < TAM - 1;  i++)
    {
        for(int j = i +1; j < TAM;  j++)
        {
            if( sexos[i] > sexos[j])
            {
                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = edades[i];
                edades[i] = edades[j];
                edades[j] = auxInt;

                auxChar = sexos[i];
                sexos[i] = sexos[j];
                sexos[j] = auxChar;
            }
            else if( sexos[i] == sexos[j] && edades[i] < edades[j])
            {
                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = edades[i];
                edades[i] = edades[j];
                edades[j] = auxInt;
            }
        }
    }*/
    return 0;
    }
