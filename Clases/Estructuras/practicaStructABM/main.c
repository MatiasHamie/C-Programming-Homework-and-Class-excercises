#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LARGO 3
#define VACIO 0
#define OCUPADO 1

typedef struct
{
    char nombre[20];
    char sexo;
    int legajo;
    float sueldo;
    int estado;

} Eempleado;

void pedirDatos(Eempleado listaEmpleados[],int );
void mostrarDatos(Eempleado listaEmpleados[],int );
int buscarVacio(Eempleado listaEmpleados[],int );

int main()
{
    Eempleado listaEmpleados[LARGO];
    int opcion;

    for(int i=0; i<LARGO; i++)
    {
        listaEmpleados[i].estado=VACIO;
    }

    do
    {
        printf("1. Agregar empleado\n");
        printf("2. Mostrar empleados ingresados\n");
        printf("3. Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                pedirDatos(listaEmpleados,LARGO);
                break;
            case 2:
                mostrarDatos(listaEmpleados,LARGO);
                system("pause");
                break;
        }
        system("cls");
    }while(opcion!=3);


    return 0;
}

void pedirDatos(Eempleado listaEmpleados[],int tam)
{
    int indiceLibre=buscarVacio(listaEmpleados,LARGO);

        if(indiceLibre)
        {
            printf("Ingrese nombre: \n");
            fflush(stdin);
            scanf("%s",listaEmpleados[indiceLibre].nombre);

            printf("Ingrese sexo: \n");
            fflush(stdin);
            scanf("%c",&listaEmpleados[indiceLibre].sexo);

            printf("Ingrese legajo: \n");
            scanf("%d",&listaEmpleados[indiceLibre].legajo);

            printf("Ingrese sueldo: \n");
            scanf("%f",&listaEmpleados[indiceLibre].sueldo);

            listaEmpleados[indiceLibre].estado=OCUPADO;
        }
}

void mostrarDatos(Eempleado listaEmpleados[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        if(listaEmpleados[i].estado==OCUPADO)
        {
            printf("Nombre: %s Sexo: %c Legajo: %d Sueldo: %.2f\n",listaEmpleados[i].nombre,listaEmpleados[i].sexo,listaEmpleados[i].legajo,listaEmpleados[i].sueldo);
        }
    }
}

int buscarVacio(Eempleado listaEmpleados[],int tam)
{
    int indiceVacio;

    for(int i=0;i<tam;i++)
    {
        if(listaEmpleados[i].estado==VACIO)
        {
            indiceVacio=i;
        }
    }

    return indiceVacio;
}
