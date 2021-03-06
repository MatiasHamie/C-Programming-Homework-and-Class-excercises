#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define OCUPADO 1
#define VACIO 0
#define TAMEMP 11
#define TAMSEC 4
#define TAMCOM 5
#define TAMALM 16

typedef struct
{
    int dia;
    int mes;
    int anno;

} eFecha;

typedef struct
{
    int id;
    char descripcion[21];

} eComida;

typedef struct
{
    int id;
    int legajoEmp;
    int idComida;
    eFecha fecha;

} eAlmuerzo;

typedef struct
{
    char nombre[51];
    char apellido[51];
    char sexo;
    int legajo;
    int estado;
    int idSector;
    float sueldo;
    eFecha fecha;

} eEmpleado;

typedef struct
{
    int id;
    char descripcion[51];

} eSector;

int  menuPrincipal();
int  menuBusqueda();
int  menuInformes();
int  menuSorting();
int  buscarVacio(eEmpleado empleados[],int tam);
int  buscarSectorVacio(eSector sector[],int tamSec);
int  buscarLegajo(eEmpleado empleados[], int tam);
int  buscarNombre(eEmpleado empleados[], int tam);
int  buscarApellido(eEmpleado empleados[], int tam);
int  buscarEmpleado(eEmpleado empleados[],int tam, eSector sector[],int tamSec);
int  obtenerSector(int idEmpleado, eSector sectores[], int tamSec, char auxDescID[]);
int  obtenerAlmuerzoEmpleado(eAlmuerzo almuerzo, eEmpleado empleados[], int tam, char nombreEmp[], char apellidoEmp[]);
int  obtenerAlmuerzoComida(eAlmuerzo almuerzo, eComida comidas[], int tamCom, char nombreCom[]);
int  obtenerLegajoEmpAlmuerzo(eAlmuerzo almuerzo,eEmpleado empleados[],int tam);
void buscarSexo(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void inicializarEstadoEmpleados(eEmpleado empleados[],int tam);
void hardCodearEmpleados(eEmpleado empleados[],int tam);
void hardCodearSectores(eSector empleados[],int tamSec);
void hardCodearComidas(eComida comidas[],int tamCom);
void hardCodearAlmuerzos(eAlmuerzo almuerzos[],int tamAlm);
void inicializarIdSectores(eSector sectores[],int tamSec);
void altaEmpleado(eEmpleado empleados[],int tam, eSector sector[],int tamSec);
void altaSector(eSector sector[],int tamSec);
void bajaEmpleado(eEmpleado empleados[],int tam, eSector sector[],int tamSec);
void ordenarEmpleados(eEmpleado empleados[],int tam, eSector sectores[],int tamSec);
void bubbleSorting(eEmpleado empleados[],int tam, eSector sectores[],int tamSec,int i, int j);
void mostrarEmpleado(eEmpleado emp1, eSector sectores[], int tamSec);
void mostrarEmpleados(eEmpleado empleados[],int tam, eSector sectores[], int tamSec);
void mostrarAlmuerzo(eAlmuerzo almuerzo,eEmpleado empleados[],int tam,eComida comidas[],int tamCom);
void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tamAlm , eEmpleado empleados[], int tam, eComida comidas[], int tamCom);
void mostrarSectores(eSector sectores[], int tamSec);
void mostrarComidas(eComida comidas[], int tamCom);
void mostrarInforme(eEmpleado empleados[],int tam, eSector sectores[],int tamSec, eComida comidas[],int tamCom, eAlmuerzo almuerzos[],int tamAlm);
void modificarEmpleado(eEmpleado empleados[],int tam, eSector sectores[],int tamSec);
void informeEmpPorSector(eEmpleado empleados[],int tam, eSector sector[],int tamSec);
void informeCantEmpPorSector(eEmpleado empleados[],int tam, eSector sector[],int tamSec);
void informeMaxSueldoEmpPorSector(eEmpleado empleados[],int tam, eSector sector[],int tamSec);
void informePromedioSueldosPorSector(eEmpleado empleados[],int tam, eSector sector[],int tamSec);
void informeAlmuerzosPorPersona(eAlmuerzo almuerzos[], int tamAlm , eEmpleado empleados[], int tam, eComida comidas[], int tamCom);
void informeComidaPorPersona(eAlmuerzo almuerzos[], int tamAlm , eEmpleado empleados[], int tam, eComida comidas[], int tamCom);
void informeAlmuerzosPorSector(eAlmuerzo almuerzos[], int tamAlm , eEmpleado empleados[], int tam, eComida comidas[], int tamCom, eSector sectores[], int tamSec);

int main()
{
    char seguir='s';
    char confirma;

    eEmpleado listaEmpleados[TAMEMP];
    eSector   listaSectores[TAMSEC];
    eAlmuerzo listaAlmuerzos[TAMALM];
    eComida   listaComidas[TAMCOM];

    //inicializarEstadoEmpleados(listaEmpleados,TAMEMP);
    //inicializarIdSectores(listaSectores,TAMSEC);
    hardCodearEmpleados(listaEmpleados,TAMEMP);
    hardCodearSectores(listaSectores,TAMSEC);
    hardCodearAlmuerzos(listaAlmuerzos,TAMALM);
    hardCodearComidas(listaComidas,TAMCOM);

    do
    {
        system("cls");

        switch(menuPrincipal())
        {
            case 1:
                altaEmpleado(listaEmpleados,TAMEMP,listaSectores,TAMSEC);
                system("pause");
                break;
            case 2:
                bajaEmpleado(listaEmpleados,TAMEMP,listaSectores,TAMSEC);
                system("pause");
                break;
            case 3:
                printf("3- Modificacion empleado\n");
                system("pause");
                break;
            case 4:
                mostrarEmpleados(listaEmpleados,TAMEMP,listaSectores,TAMSEC);
                system("pause");
                break;
            case 5:
                altaSector(listaSectores,TAMSEC);
                system("pause");
                break;
            case 6:
                mostrarSectores(listaSectores,TAMSEC);
                system("pause");
                break;
            case 7:
                buscarEmpleado(listaEmpleados,TAMEMP,listaSectores,TAMSEC);
                system("pause");
                break;
            case 8:
                mostrarAlmuerzos(listaAlmuerzos,TAMALM,listaEmpleados,TAMEMP,listaComidas,TAMCOM);
                system("pause");
                break;
            case 9:
                mostrarComidas(listaComidas,TAMCOM);
                system("pause");
                break;
            case 10:
                mostrarInforme(listaEmpleados,TAMEMP,listaSectores,TAMSEC,listaComidas,TAMCOM,listaAlmuerzos,TAMALM);
                system("pause");
                break;
            case 11:
                ordenarEmpleados(listaEmpleados,TAMEMP,listaSectores,TAMSEC);
                system("pause");
                break;
            case 12:
                printf("Esta seguro que desea salir? s/n\n");
                fflush(stdin);
                confirma=getche();

                if(tolower(confirma)=='s')
                {
                    seguir='n';
                    printf("Programa finalizado..!\n");
                    system("pause");
                }
                break;
        }
    }while(seguir=='s');

        return 0;
}

int menuPrincipal()
{
    int opcion;

    printf("*** MENU ABM (PRACTICA PARCIAL) ***\n\n");
    printf("1- Alta empleado\n");
    printf("2- Baja empleado\n");
    printf("3- Modificacion empleado\n");
    printf("4- Listar empleados\n");
    printf("5- Agregar Sectores\n");
    printf("6- Listar sectores\n");
    printf("7- Buscar empleados\n");
    printf("8- Mostrar Almuerzos\n");
    printf("9- Mostrar Comidas\n");
    printf("10- Informes\n");
    printf("11- Ordenar empleados\n");
    printf("12- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void inicializarEstadoEmpleados(eEmpleado empleados[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        empleados[i].estado=VACIO;
    }
}

void inicializarIdSectores(eSector sectores[],int tamSec)
{
    for(int i=0;i<tamSec;i++)
    {
        sectores[i].id=VACIO;
    }
}

int buscarVacio(eEmpleado empleados[],int tam)
{
    int indiceVacio = -1;

    for(int i=0;i<tam;i++)
    {
        if(empleados[i].estado==0)
        {
            indiceVacio=i;
            break;
        }
    }

    return indiceVacio;
}

void altaEmpleado(eEmpleado empleados[],int tam, eSector sector[],int tamSec)
{
    int indiceEEmpleadoVacio=buscarVacio(empleados,TAMEMP);

    if(indiceEEmpleadoVacio==-1)
    {
        printf("\nNo hay espacio para mas empleados...!!\n");
    }
    else
    {
        system("cls");

        printf("---Datos personales---");
        printf("\nIngrese nombre: \n");
        fflush(stdin);
        scanf("%s",empleados[indiceEEmpleadoVacio].nombre);

        printf("Ingrese apellido: \n");
        fflush(stdin);
        scanf("%s",empleados[indiceEEmpleadoVacio].apellido);

        printf("Ingrese sexo: \n");
        fflush(stdin);
        scanf("%c",&empleados[indiceEEmpleadoVacio].sexo);

        printf("Ingrese Legajo: \n");
        scanf("%d",&empleados[indiceEEmpleadoVacio].legajo);

        printf("Ingrese Sueldo: \n");
        scanf("%f",&empleados[indiceEEmpleadoVacio].sueldo);

        printf("---Fecha de Ingreso---\n");

        printf("Ingrese Dia: \n");
        scanf("%d",&empleados[indiceEEmpleadoVacio].fecha.dia);

        printf("Ingrese Mes: \n");
        scanf("%d",&empleados[indiceEEmpleadoVacio].fecha.mes);

        printf("Ingrese Anio: \n");
        scanf("%d",&empleados[indiceEEmpleadoVacio].fecha.anno);

        empleados[indiceEEmpleadoVacio].estado=OCUPADO;

        printf("\nA que sector pertenece?\n");

        if(buscarSectorVacio(sector,TAMSEC)==-1)
        {
            printf("No hay sectores para mostrar..!!!");
        }
        else
        {
            mostrarSectores(sector,TAMSEC);
        }

        scanf("%d",&empleados[indiceEEmpleadoVacio].idSector);

        //printf("\n\nProbando ID: %d\n\n",empleados[indiceEEmpleadoVacio].idSector);
        //system("pause");

        printf("\nEmpleado dado de alta de forma satisfactoria...!!\n");
    }
}

void mostrarEmpleado(eEmpleado emp1, eSector sectores[], int tamSec)
{
    char auxiliarNombreSector[20];
    int conseguirNombreSector;

    conseguirNombreSector=obtenerSector(emp1.idSector,sectores,TAMSEC,auxiliarNombreSector);

    if(!conseguirNombreSector)
    {
        strcpy(auxiliarNombreSector,"Nombre sin definir");
    }

    printf("%5d %12s %12s %8c %12.2f   %02d/%02d/%4d  %8s\n",emp1.legajo,emp1.nombre,emp1.apellido,emp1.sexo,emp1.sueldo,emp1.fecha.dia,emp1.fecha.mes,emp1.fecha.anno,auxiliarNombreSector);
}

void mostrarEmpleados(eEmpleado empleados[],int tam, eSector sectores[], int tamSec)
{
    system("cls");
    printf("%5s %12s %12s %8s %10s %12s %10s\n", "Legajo", "Nombre", "Apellido", "Sexo", "Sueldo", "Fecha Ing", "Sector");
    printf("%5s %12s %12s %8s %10s %12s %10s\n", "------", "------", "--------", "----", "------", "---------", "------");

    for(int i=0;i<tam;i++)
    {
        if(empleados[i].estado==OCUPADO)
        {
            mostrarEmpleado(empleados[i],sectores,TAMSEC);
        }
    }
}

int buscarEmpleado(eEmpleado empleados[],int tam, eSector sector[],int tamSec)
{
    int opcion;
    int esta;

    opcion = menuBusqueda();

    switch(opcion)
    {
        case 1:
            esta=buscarLegajo(empleados,TAMEMP);
            break;
        case 2:
            esta=buscarNombre(empleados,TAMEMP);
            break;
        case 3:
            esta=buscarApellido(empleados,TAMEMP);
            break;
        /*case 4:
            buscarSexo(empleados,TAMEMP,sector,TAMSEC);
            break;*/
        default:
            printf("Opcion invalida");
            break;
    }

    if (esta!=-1)
    {
        mostrarEmpleado(empleados[esta],sector,TAMSEC);
    }
    else
    {
        printf("El empleado no esta en la base de datos..!!\n");
    }
    return esta;
}

int menuBusqueda(eEmpleado empleados[],int tam)
{
    int opcion;

    system("cls");

    printf("BUSCAR POR: \n\n");
    printf("1- Legajo\n");
    printf("2- Nombre\n");
    printf("3- Apellido\n");
    //printf("4- Sexo\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void hardCodearEmpleados(eEmpleado empleados[],int tam)
{
    eEmpleado auxVec[]={
        {"Matias",  "Hamie",    'm',1001,1,1,25000,{25,4,2019}},
        {"Natalia", "Castillo", 'f',1234,1,2,25123,{26,1,2019}},
        {"Juan",    "Pinola",   'm',1245,1,2,25124,{2,2,2015}},
        {"Thiago",  "Corta",    'm',1543,1,3,31231,{5,6,2010}},
        {"Daniel",  "Clas",     'm',1800,1,4,15251,{3,7,2017}},
        {"Jimena",  "Fernandez",'f',1224,1,2,15512,{13,10,2017}},
        {"Sabrina", "Cabrera",  'f',1654,1,1,12156,{17,9,2011}},
        {"Bruno",   "Diaz",     'm',1684,1,4,12561,{21,9,2012}},
        {"Tomas",   "Gonzales", 'm',1859,1,3,62625,{18,3,2012}}
        };

    for(int i=0;i<tam;i++)
    {
        empleados[i]=auxVec[i];
    }
}

int buscarLegajo(eEmpleado empleados[], int tam)
{
    eEmpleado auxEmpleado;
    int esta=-1;

    printf("Ingrese Legajo: ");
    scanf("%d",&auxEmpleado.legajo);

    for(int i=0;i<tam;i++)
    {
        if(empleados[i].legajo==auxEmpleado.legajo)
        {
            esta=i;
            break;
        }
    }
    return esta;
}

int buscarNombre(eEmpleado empleados[], int tam)
{
    eEmpleado auxEmpleado;
    int esta=-1;

    printf("Ingrese Nombre: ");
    scanf("%s",auxEmpleado.nombre);
    auxEmpleado.nombre[0]=toupper(auxEmpleado.nombre[0]);

    for(int i=0;i<tam;i++)
    {
        if(strcmp(auxEmpleado.nombre,empleados[i].nombre)==0)
        {
            esta=i;
            break;
        }
    }
    return esta;
}

int buscarApellido(eEmpleado empleados[], int tam)
{
    eEmpleado auxEmpleado;
    int esta=-1;

    printf("Ingrese Apellido: ");
    scanf("%s",auxEmpleado.apellido);
    auxEmpleado.apellido[0]=toupper(auxEmpleado.apellido[0]);

    for(int i=0;i<tam;i++)
    {
        if(strcmp(auxEmpleado.apellido,empleados[i].apellido)==0)
        {
            esta=i;
            break;
        }
    }
    return esta;
}

void buscarSexo(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    eEmpleado auxEmpleado;

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c",&auxEmpleado.sexo);

    for(int i=0;i<tam;i++)
    {
        if(empleados[i].sexo==auxEmpleado.sexo)
        {
            mostrarEmpleado(empleados[i],sectores,TAMSEC);
            system("pause");
        }
    }
}

void bajaEmpleado(eEmpleado empleados[],int tam, eSector sector[],int tamSec)
{
    int esta=buscarEmpleado(empleados,TAMEMP,sector,TAMSEC);
    char confirma;

    if(esta == -1)
    {
        printf("No se encuentra al empleado en la base de datos..!!\n");
    }
    else
    {
        printf("Esta seguro que desea dar de baja el empleado? s/n: ");
        fflush(stdin);
        confirma=getche();
        printf("\n");
        if (tolower(confirma)=='s')
        {
            empleados[esta].estado=VACIO;
        }
    }
}

void hardCodearSectores(eSector empleados[],int tamSec)
{
    eSector auxVec[]={
        {1,"RRHH"},
        {2,"Finanzas"},
        {3,"Telecom."},
        {4,"Sistemas"},
        };

    for(int i=0;i<tamSec;i++)
    {
        empleados[i]=auxVec[i];
    }
}

int obtenerSector(int idEmpleado, eSector sectores[], int tamSec, char auxDescID[])
{
    int esta=-1;

    for(int i=0;i<tamSec;i++)
    {
        if(idEmpleado==sectores[i].id)
        {
            strcpy(auxDescID,sectores[i].descripcion);
            esta=1;
            break;
        }
    }
    return esta;
}

void mostrarSectores(eSector sectores[], int tamSec)
{
    system("cls");
    printf("*** SECTORES ***\n\n");

    for(int i=0;i<tamSec;i++)
    {
        if(sectores[i].id>0)
        {
            printf("%d %4s\n",sectores[i].id, sectores[i].descripcion);
        }
    }
}

void mostrarInforme(eEmpleado empleados[],int tam, eSector sectores[],int tamSec, eComida comidas[],int tamCom, eAlmuerzo almuerzos[],int tamAlm)
{
    system("cls");

    switch(menuInformes())
    {
        case 1:
            informeEmpPorSector(empleados,TAMEMP,sectores,TAMSEC);
            break;
        case 2:
            informeCantEmpPorSector(empleados,TAMEMP,sectores,TAMSEC);
            break;
        case 3:
            informeMaxSueldoEmpPorSector(empleados,TAMEMP,sectores,TAMSEC);
            break;
        case 4:
            informePromedioSueldosPorSector(empleados,TAMEMP,sectores,TAMSEC);
            break;
        case 5:
            informeAlmuerzosPorPersona(almuerzos,TAMALM,empleados,TAMEMP,comidas,TAMCOM);
            break;
        case 6:
            informeComidaPorPersona(almuerzos,TAMALM,empleados,TAMEMP,comidas,TAMCOM);
            break;
        case 7:
            informeAlmuerzosPorSector(almuerzos,TAMALM,empleados,TAMEMP,comidas,TAMCOM,sectores,TAMSEC);
            break;
        default:
            printf("Opcion invalida");
    }
}

int menuInformes()
{
    int opcion;

    system("cls");

    printf("Informe de: \n\n");
    printf("1- Lista de empleados por sector\n");
    printf("2- Lista de cantidad de empleados por sector\n");
    printf("3- Lista de empleados con mayor sueldo por sector\n");
    printf("4- Lista de promedio de sueldos por sector\n");
    printf("5- Lista Almuerzos por empleado\n");
    printf("6- Lista Comidas por empleado\n");
    printf("7- Lista Almuerzos por sector\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void informeEmpPorSector(eEmpleado empleados[],int tam, eSector sector[],int tamSec)
{
    for(int i=0;i<tamSec;i++)
    {
        printf("\n\n*** Sector %s ***\n\n",sector[i].descripcion);
        printf("%5s %12s %12s %8s %10s %12s %10s\n", "Legajo", "Nombre", "Apellido", "Sexo", "Sueldo", "Fecha Ing", "Sector");
        printf("%5s %12s %12s %8s %10s %12s %10s\n", "------", "------", "--------", "----", "------", "---------", "------");

        for(int j=0;j<tam;j++)
        {
            if(empleados[j].idSector==sector[i].id && empleados[j].estado==OCUPADO)
            {
                mostrarEmpleado(empleados[j],sector,TAMSEC);
            }
        }
    }
}

void altaSector(eSector sector[],int tamSec)
{
    int indiceSectorVacio;

    system("cls");
    printf("** Sectores dados de alta **\n");
    mostrarSectores(sector,TAMSEC);

    indiceSectorVacio=buscarSectorVacio(sector,tamSec);

    for(int i=0;i<tamSec;i++)
    {
        if(indiceSectorVacio>-1)
        {
            sector[indiceSectorVacio].id=indiceSectorVacio+1;

            printf("Ingrese el nombre del sector que desea dar de ALTA: ");
            fflush(stdin);
            scanf("%s",sector[indiceSectorVacio].descripcion);
            break;
        }
        else
        {
            printf("No hay espacio para agregar mas sectores..!!");
            break;
        }
    }
}

int buscarSectorVacio(eSector sector[],int tamSec)
{
    int indiceVacio = -1;

    for(int i=0;i<tamSec;i++)
    {
        if(sector[i].id==0)
        {
            indiceVacio=i;
            break;
        }
    }
    return indiceVacio;
}

void informeCantEmpPorSector(eEmpleado empleados[],int tam, eSector sector[],int tamSec)
{
    int contador;

    system("cls");

    printf("*** Cantidad de empleados ***\n\n");

    for(int i=0;i<tamSec;i++)
    {
        contador=0;

        for(int j=0;j<tam;j++)
        {
            if(empleados[j].idSector==sector[i].id && empleados[j].estado==OCUPADO)
            {
                contador++;
            }
        }
        printf("Sector %s: %d \n",sector[i].descripcion,contador);
    }
}

void informeMaxSueldoEmpPorSector(eEmpleado empleados[],int tam, eSector sector[],int tamSec)
{
    int flagAux=0;
    int indiceMax;
    float max;

    system("cls");

    printf("*** Empleados por sector con mayor sueldo ***\n\n");

    for(int i=0;i<tamSec;i++)
    {
        printf("Sector %s: \n",sector[i].descripcion);
        max=0;
        indiceMax=0;

        for(int j=0;j<tam;j++)
        {
            if(empleados[j].idSector==sector[i].id && empleados[j].estado==OCUPADO && (flagAux==0 || empleados[j].sueldo>max))
            {
                max=empleados[j].sueldo;
                indiceMax=j;
                flagAux=1;
            }
        }
        mostrarEmpleado(empleados[indiceMax],sector,TAMSEC);
    }
}

void informePromedioSueldosPorSector(eEmpleado empleados[],int tam, eSector sector[],int tamSec)
{
    int contador;
    float acumulador;
    float promedio=0;

    for(int i=0;i<tamSec;i++)
    {
        contador=0;
        acumulador=0;
        printf("\n\n*** Sector %s ***\n\n",sector[i].descripcion);

        for(int j=0;j<tam;j++)
        {
            if(empleados[j].idSector==sector[i].id && empleados[j].estado==OCUPADO)
            {
                contador++;
                acumulador+=empleados[j].sueldo;
            }
        }
        promedio=acumulador/contador;
        printf("Promedio sueldos: %.2f\n",promedio);
    }
}

void hardCodearComidas(eComida comidas[],int tamCom)
{
    eComida vecAux[]={
                    {1,"Milanesa"},
                    {2,"Fideos"},
                    {3,"Sopa"},
                    {4,"Guiso"},
                    {5,"Lasagna"},
                    };

    for(int i=0;i<tamCom;i++)
    {
        comidas[i]=vecAux[i];
    }
}

void hardCodearAlmuerzos(eAlmuerzo almuerzos[],int tamAlm)
{
    eAlmuerzo vecAux[]={
                    {100,1001,1,{25,4,2019}},
                    {101,1234,2,{25,4,2019}},
                    {102,1245,3,{25,4,2019}},
                    {103,1543,4,{25,4,2019}},
                    {104,1800,1,{25,4,2019}},
                    {105,1224,2,{25,4,2019}},
                    {106,1654,3,{25,4,2019}},
                    {107,1684,4,{25,4,2019}},
                    {108,1859,1,{25,4,2019}},
                    {109,1001,2,{26,4,2019}},
                    {110,1234,1,{26,4,2019}},
                    {111,1245,4,{26,4,2019}},
                    {112,1224,3,{26,4,2019}},
                    {113,1654,2,{26,4,2019}},
                    {114,1684,3,{26,4,2019}},
                    {115,1859,4,{26,4,2019}},
                    };

    for(int i=0;i<tamAlm;i++)
    {
        almuerzos[i]=vecAux[i];
    }
}

void mostrarAlmuerzo(eAlmuerzo almuerzo,eEmpleado empleados[],int tam,eComida comidas[],int tamCom)
{
    char nombreEmpleado[51];
    char apellidoEmpleado[51];
    char nombreComida[21];
    int indiceCoincideIDEmp;
    int indiceCoincideIDCom;

    strcpy(nombreEmpleado,"");
    strcpy(apellidoEmpleado,"");
    strcpy(nombreComida,"");

    indiceCoincideIDEmp=obtenerAlmuerzoEmpleado(almuerzo,empleados,TAMEMP,nombreEmpleado,apellidoEmpleado);
    indiceCoincideIDCom=obtenerAlmuerzoComida(almuerzo,comidas,TAMCOM,nombreComida);

    if(indiceCoincideIDEmp && indiceCoincideIDCom)
    {
        printf("%d %14s %15s %10s %7.02d/%02d/%4d\n",almuerzo.id,nombreEmpleado,apellidoEmpleado,nombreComida,almuerzo.fecha.dia,almuerzo.fecha.mes,almuerzo.fecha.anno);
    }
    else
    {
        printf("Empleado sin almuerzo..!!");
    }
}

void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tamAlm , eEmpleado empleados[], int tam, eComida comidas[], int tamCom)
{
    system("cls");

    printf("*** Almuerzos ***\n\n");
    printf("%s %15s %15s %10s %12s \n","ID","NOMBRE","APELLIDO","COMIDA","FECHA");
    printf("%s %15s %15s %10s %12s \n","--","------","--------","------","-----");

    for(int i=0;i<tamAlm;i++)
    {
        mostrarAlmuerzo(almuerzos[i],empleados,TAMEMP,comidas,TAMCOM);
    }
}

void mostrarComidas(eComida comidas[], int tamCom)
{
    system("cls");
    printf("*** COMIDAS ***\n\n");

    for(int i=0;i<tamCom;i++)
    {
        if(comidas[i].id>0)
        {
            printf("%d %4s\n",comidas[i].id, comidas[i].descripcion);
        }
    }
}

int obtenerAlmuerzoEmpleado(eAlmuerzo almuerzo, eEmpleado empleados[], int tam, char nombreEmp[], char apellidoEmp[])
{
    int esta=-1;

    for(int j=0;j<tam;j++)
    {
        if(almuerzo.legajoEmp==empleados[j].legajo && empleados[j].estado==OCUPADO)
        {
            strcpy(nombreEmp,empleados[j].nombre);
            strcpy(apellidoEmp,empleados[j].apellido);
            esta=1;
        }
    }
    return esta;
}

int obtenerAlmuerzoComida(eAlmuerzo almuerzo, eComida comidas[], int tamCom, char nombreCom[])
{
    int esta=-1;

    for(int j=0;j<tamCom;j++)
    {
        if(almuerzo.idComida==comidas[j].id)
        {
            strcpy(nombreCom,comidas[j].descripcion);
            esta=1;
        }
    }
    return esta;
}

void informeAlmuerzosPorPersona(eAlmuerzo almuerzos[], int tamAlm , eEmpleado empleados[], int tam, eComida comidas[], int tamCom)
{
    system("cls");
    printf("*** Almuerzos por persona***\n");

    for(int i=0;i<tam;i++)
    {
        if(empleados[i].estado==OCUPADO)
        {
            printf("\nNombre  Apellido\n");
            printf("%s %s\n",empleados[i].nombre,empleados[i].apellido);

            for(int j=0;j<tamAlm;j++)
            {
                for(int k=0;k<tamCom;k++)
                {
                    if(almuerzos[j].legajoEmp==empleados[i].legajo && almuerzos[j].idComida==comidas[k].id)
                    {
                        //Revisar bien que pasa aca cuando imprime todo
                        printf("Comida: %s\n",comidas[k].descripcion);
                    }
                }
            }
        }
    }
}

void informeComidaPorPersona(eAlmuerzo almuerzos[], int tamAlm , eEmpleado empleados[], int tam, eComida comidas[], int tamCom)
{
    int indiceEmpleado;

    for(int i=0;i<tamCom;i++)
    {
        printf("\nComida: %s\n\n",comidas[i].descripcion);
        for(int j=0;j<tamAlm;j++)
        {
            if(almuerzos[j].idComida==comidas[i].id)
            {
                indiceEmpleado=obtenerLegajoEmpAlmuerzo(almuerzos[j],empleados,TAMEMP);
                printf("%s %s\n",empleados[indiceEmpleado].nombre,empleados[indiceEmpleado].apellido);
            }
        }
    }
}

int obtenerLegajoEmpAlmuerzo(eAlmuerzo almuerzo,eEmpleado empleados[],int tam)
{
    int indice;

    for(int i=0;i<tam;i++)
    {
        if(almuerzo.legajoEmp==empleados[i].legajo)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int menuSorting()
{
    int opcion;

    system("cls");

    printf("Ordenar por:\n\n");
    printf("1- Fecha de ingreso ascendente\n");
    printf("2- Fecha de ingreso descendente\n");
    printf("3- Nombre A-Z\n");
    printf("4- Nombre Z-A\n");
    printf("5- Apellido A-Z\n");
    printf("6- Apellido Z-A\n");
    printf("7- Legajo ascendente\n");
    printf("8- Legajo descendente\n");
    printf("9- Sueldo ascendente\n");
    printf("10- Sueldo descendente\n");
    printf("11- Sexo F-M\n");
    printf("12- Sexo M-F\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void informeAlmuerzosPorSector(eAlmuerzo almuerzos[], int tamAlm , eEmpleado empleados[], int tam, eComida comidas[], int tamCom, eSector sectores[], int tamSec)
{
    char nombreComida[21];
    char nombreEmpleado[21];
    char apellidoEmpleado[21];

    system("cls");
    printf("*** Almuerzos por sector***\n");

    for(int i=0;i<tamSec;i++)
    {
        printf("\n*** Sector: %s ***\n\n",sectores[i].descripcion);
        printf("Nombre  Apellido   Comida   Fecha\n");

        for(int j=0;j<tamAlm;j++)
        {
            for(int k=0;k<tam;k++)
            {
                if(empleados[k].idSector==sectores[i].id && almuerzos[j].legajoEmp==empleados[k].legajo)
                {
                    obtenerAlmuerzoComida(almuerzos[j],comidas,TAMCOM,nombreComida);
                    obtenerAlmuerzoEmpleado(almuerzos[j],empleados,TAMEMP,nombreEmpleado,apellidoEmpleado);

                    printf("%s %8s %8s %02d/%02d/%d\n",nombreEmpleado,apellidoEmpleado,nombreComida,almuerzos[j].fecha.dia,almuerzos[j].fecha.mes,almuerzos[j].fecha.anno);
                }
            }
        }
    }
}

void ordenarEmpleados(eEmpleado empleados[],int tam, eSector sectores[],int tamSec)
{
    int opcion=menuSorting();

    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            switch(opcion)
            {
                case 1:
                    if(empleados[i].fecha.anno<empleados[j].fecha.anno)
                    {
                        bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                    }
                    else
                    {
                        if(empleados[i].fecha.anno==empleados[j].fecha.anno && empleados[i].fecha.mes<empleados[j].fecha.mes)
                        {
                            bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                        }
                        else
                        {
                            if(empleados[i].fecha.anno==empleados[j].fecha.anno && empleados[i].fecha.mes<empleados[j].fecha.mes && empleados[i].fecha.dia<empleados[j].fecha.dia)
                            {
                                bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                            }
                        }
                    }
                    break;
                case 2:
                    if(empleados[i].fecha.anno>empleados[j].fecha.anno)
                    {
                        bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                    }
                    else
                    {
                        if(empleados[i].fecha.mes>empleados[j].fecha.mes)
                        {
                            bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                        }
                        else
                        {
                            if(empleados[i].fecha.dia>empleados[j].fecha.dia)
                            {
                                bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                            }
                        }
                    }
                    break;
                case 3:
                    if(stricmp(empleados[i].nombre,empleados[j].nombre)==1)
                    {
                        bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                    }
                    break;
                case 4:
                    if(stricmp(empleados[i].nombre,empleados[j].nombre)==-1)
                    {
                        bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                    }
                    break;
                case 5:
                    if(stricmp(empleados[i].apellido,empleados[j].apellido)==1)
                    {
                        bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                    }
                    break;
                case 6:
                    if(stricmp(empleados[i].apellido,empleados[j].apellido)==-1)
                    {
                        bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                    }
                    break;
                case 7:
                    if(empleados[i].legajo<empleados[j].legajo)
                    {
                        bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                    }
                    break;
                case 8:
                    if(empleados[i].legajo>empleados[j].legajo)
                    {
                        bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                    }
                    break;
                case 9:
                    if(empleados[i].sueldo<empleados[j].sueldo)
                    {
                        bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                    }
                    break;
                case 10:
                    if(empleados[i].sueldo>empleados[j].sueldo)
                    {
                        bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                    }
                    break;
                case 11:
                    if(empleados[i].sexo>empleados[j].sexo)
                    {
                        bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                    }
                    break;
                case 12:
                    if(empleados[i].sexo<empleados[j].sexo)
                    {
                        bubbleSorting(empleados,TAMALM,sectores,TAMSEC,i,j);
                    }
                    break;
            }
        }
    }
    mostrarEmpleados(empleados,TAMEMP,sectores,tamSec);
}

void bubbleSorting(eEmpleado empleados[],int tam, eSector sectores[],int tamSec,int i, int j)
{
    eEmpleado auxEmp;

    auxEmp=empleados[i];
    empleados[i]=empleados[j];
    empleados[j]=auxEmp;
}

void modificarEmpleado(eEmpleado empleados[],int tam, eSector sectores[],int tamSec)


