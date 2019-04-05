#include <stdio.h>
#include <stdlib.h>

int main()
{
    int aux;
    int vectorNumeros[10]={100,23,37,41,5,46,73,8,91,99};

    printf("*** Vector sin ordenar ***\n\n");

    for(int i=0;i<10;i++){
        printf(" %d",vectorNumeros[i]);
    }

    for(int i=0;i<9;i++){
        for(int j=i+1;j<10;j++){
            if(vectorNumeros[i]>vectorNumeros[j]){
                aux=vectorNumeros[i];
                vectorNumeros[i]=vectorNumeros[j];
                vectorNumeros[j]=aux;
            }
        }
    }

    printf("\n*** Vector ordenado ***\n\n");

    for(int i=0;i<10;i++){
        printf(" %d",vectorNumeros[i]);
    }

    return 0;
}
