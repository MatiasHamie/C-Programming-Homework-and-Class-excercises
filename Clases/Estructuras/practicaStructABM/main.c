#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int menuPrincipal();
void pedirDatos(Eempleado listaEmpleados[],int );
void mostrarDatos(Eempleado listaEmpleados[],int );
int buscarVacio(Eempleado listaEmpleados[],int );
void buscarEmpleado(int opcionBusqueda,Eempleado listaEmpleados[],int );
void buscarLegajo(int auxInt,Eempleado listaEmpleados[],int tam);
void buscarSexo(char auxChar,Eempleado listaEmpleados[],int tam);
void buscarSueldo(float auxFloatMinimo,float auxFloatMaximo,Eempleado listaEmpleados[],int tam);
void buscarNombre(char auxCadena[],Eempleado listaEmpleados[],int tam);

int main()
{
    Eempleado listaEmpleados[LARGO];
    int opcion;
    int opcionBusqueda;

    for(int i=0; i<LARGO; i++)
    {
        listaEmpleados[i].estado=VACIO;
    }

    do
    {
        opcion=menuPrincipal();

        switch(opcion)
        {
            case 1:
                pedirDatos(listaEmpleados,LARGO);
                break;
            case 2:
                mostrarDatos(listaEmpleados,LARGO);
                system("pause");
                break;
            case 3:
                system("cls");
                printf("*** Buscar por ***\n");
                printf("1. Nombre\n");
                printf("2. Legajo\n");
                printf("3. Sexo\n");
                printf("4. Sueldo\n");
                scanf("%d",&opcionBusqueda);
                buscarEmpleado(opcionBusqueda,listaEmpleados,LARGO);
                break;
        }
        system("cls");
    }while(opcion!=3);

    return 0;
}

void pedirDatos(Eempleado listaEmpleados[],int tam)
{
    int indiceLibre=buscarVacio(listaEmpleados,LARGO);
    char auxCadena[100];
    char auxChar;
    int auxInt;
    float auxFloat;

        if(indiceLibre<tam)
        {
            printf("Ingrese nombre: \n");
            fflush(stdin);
            scanf("%s",auxCadena);

            while(strlen(auxCadena)>99)
            {
                printf("ERROR..! Nombre muy largo, Reingrese nombre: \n");
                fflush(stdin);
                scanf("%s",auxCadena);
            }

            strcpy(listaEmpleados[indiceLibre].nombre,auxCadena);
            listaEmpleados[indiceLibre].nombre[0]=toupper(listaEmpleados[indiceLibre].nombre[0]);

            printf("Ingrese sexo: \n");
            fflush(stdin);
            scanf("%c",&auxChar);

            while(auxChar!='f' && auxChar!='m')
            {
                printf("ERROR, Reingrese sexo: \n");
                fflush(stdin);
                scanf("%c",&auxChar);
            }

            listaEmpleados[indiceLibre].sexo=auxChar;

            printf("Ingrese legajo: \n");
            scanf("%d",&auxInt);

            while(auxInt<1000 || auxInt>9999)
            {
                printf("ERROR, Reingrese legajo (4 cifras): \n");
                scanf("%d",&auxInt);
            }

            listaEmpleados[indiceLibre].legajo=auxInt;

            printf("Ingrese sueldo: \n");
            scanf("%f",&auxFloat);

            while(auxFloat<0)
            {
                printf("ERROR, Reingrese sueldo(mayor a cero): \n");
                scanf("%f",&auxFloat);
            }

            listaEmpleados[indiceLibre].sueldo=auxFloat;
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
            break;
        }
    }

    return indiceVacio;
}

void buscarEmpleado(int opcionBusqueda,Eempleado listaEmpleados[],int tam)
{
    char auxCadena[100];
    int auxInt;
    int seguir;
    char auxChar;
    float auxFloatMinimo;
    float auxFloatMaximo;

    do
    {
        switch(opcionBusqueda)
        {
            case 1:
                system("cls");
                printf("Ingrese el nombre del empleado: \n");
                scanf("%s",auxCadena);
                buscarNombre(auxCadena,listaEmpleados,3);
                break;
            case 2:
                system("cls");
                printf("Ingrese el legajo del empleado: \n");
                scanf("%d",&auxInt);
                buscarLegajo(auxInt,listaEmpleados,3);
                break;
            case 3:
                system("cls");
                printf("Ingrese el sexo de los empleados a buscar: \n");
                scanf("%c",&auxChar);
                buscarSexo(auxChar,listaEmpleados,3);
                break;
            case 4:
                system("cls");
                printf("Ingrese el rango de sueldos de empleados a buscar: \n");
                printf("Desde: (Ingrese sueldo minimo)");
                scanf("%f",&auxFloatMinimo);
                printf("Hasta: (Ingrese sueldo maximo)");
                scanf("%f",&auxFloatMaximo);
                buscarSueldo(auxFloatMinimo,auxFloatMaximo,listaEmpleados,3);
        }
        printf("\nIngrese una opcion\n");
        printf("1. Seguir buscando\n");
        printf("2. Finalizar e ir al menu principal\n");
        printf("3. Finalizar\n");
        fflush(stdin);
        scanf("%d",&seguir);
    }while(seguir==1);
}

int menuPrincipal()
{
    int opcion;

    printf("1. Agregar empleado\n");
    printf("2. Mostrar empleados ingresados\n");
    printf("3. Buscar y mostrar empleado buscado\n");
    printf("4. Salir\n");
    scanf("%d",&opcion);

    return opcion;
}

void buscarNombre(char auxCadena[],Eempleado listaEmpleados[],int tam)
{
    for(int i=0;i<LARGO;i++)
    {
        if(stricmp(listaEmpleados[i].nombre,auxCadena)==0)
        {
            printf("Nombre: %s Sexo: %c Legajo: %d Sueldo: %.2f\n",listaEmpleados[i].nombre,listaEmpleados[i].sexo,listaEmpleados[i].legajo,listaEmpleados[i].sueldo);
            system("pause");
            break;
        }
        else
        {
            printf("No se ha encontrado el nombre del empleado en nuestra base de datos");
        }
    }
}

void buscarLegajo(int auxInt,Eempleado listaEmpleados[],int tam)
{
    for(int i=0;i<LARGO;i++)
    {
        if(auxInt==listaEmpleados[i].legajo)
        {
            printf("Nombre: %s Sexo: %c Legajo: %d Sueldo: %.2f\n",listaEmpleados[i].nombre,listaEmpleados[i].sexo,listaEmpleados[i].legajo,listaEmpleados[i].sueldo);
            system("pause");
            break;
        }
        else
        {
            printf("No se ha encontrado el legajo del empleado en nuestra base de datos");
        }
    }
}

void buscarSexo(char auxChar,Eempleado listaEmpleados[],int tam)
{
    for(int i=0;i<LARGO;i++)
    {
        if(auxChar==listaEmpleados[i].sexo)
        {
            printf("Nombre: %s Sexo: %c Legajo: %d Sueldo: %.2f\n",listaEmpleados[i].nombre,listaEmpleados[i].sexo,listaEmpleados[i].legajo,listaEmpleados[i].sueldo);
            system("pause");
            break;
        }
        else
        {
            printf("No se ha encontrado el sexo: %c en nuestra base de datos",auxChar);
        }
    }
}

void buscarSueldo(float auxFloatMinimo,float auxFloatMaximo,Eempleado listaEmpleados[],int tam)
{
    for(int i=0;i<LARGO;i++)
    {
        if(listaEmpleados[i].sueldo>auxFloatMinimo && listaEmpleados[i].sueldo<auxFloatMaximo)
        {
            printf("Nombre: %s Sexo: %c Legajo: %d Sueldo: %.2f\n",listaEmpleados[i].nombre,listaEmpleados[i].sexo,listaEmpleados[i].legajo,listaEmpleados[i].sueldo);
            system("pause");
            break;
        }
        else
        {
            printf("No se ha encontrado el sueldo en nuestra base de datos");
        }
    }
}
