#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"

void initEmployee(eEmployee vec[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        vec[i].vacio=0;
    }
}

int findEmployeeById(eEmployee vec[],int tam, int id)
{
    int i;
    int indice=-1;

    for(i=0;i<tam;i++)
    {
        if(vec[i].vacio==0 && vec[i].id==id)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void printEmployee(eEmployee emp)
{
    printf("%d %8s %8s %.2f %d",emp.id,emp.nombre,emp.apellido,emp.salario,emp.sector);
}

void printEmployees(eEmployee vec[], int tam)
{
    int i;
    int flag=0;

    printf("Id\tNombre\tApellido\tSalario\tSector\n\n");

    for(i=0;i<tam;i++)
    {
        if(vec[i].vacio==1)
        {
            flag=1; //sirve para indicar que si hay empleados
            printf("%d\t%s\t%s\t%.2f\t%d\n\n",vec[i].id,vec[i].nombre,vec[i].apellido,vec[i].salario,vec[i].sector);
        }
    }

    if(flag==0)
    {
        printf("No hay empleados registrados");
    }
}

int buscarLibre(eEmployee vec[],int tam)
{
    int indice=-1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(vec[i].vacio==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void addEmployee(eEmployee vec[],int tam)
{
    int indice;
    int esta;
    int ID;

    indice=buscarLibre(vec,tam);

    if(indice==-1)
    {
        printf("\nNo hay espacio en el sistema.");
    }
    else
    {
        printf("Ingrese ID: ");
        scanf("%d",&ID);

        esta = findEmployeeById(vec,tam,ID);

        if(esta !=-1)
        {
            printf("Existe un empleado con el ID %d en el sistema\n",ID);
            printEmployee(vec[esta]);
        }
        else
        {
            vec[indice].id=ID;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(vec[indice].apellido);

            printf("Ingrese salario: ");
            scanf("%f",&vec[indice].salario);

            printf("Ingrese sector: ");
            scanf("%d",&vec[indice].sector);

            vec[indice].vacio=1;

            printf("\nEl alta ha sido exitosa.\n\n");
        }
    }
}

void modificarEmpleado(eEmployee vec[],int tam)
{
    int i;
    int auxId;
    int opcion;
    char resp='s';

    printEmployees(vec,tam);

    printf("\n\nIngrese Id a modificar: ");
    scanf("%d",&auxId);

    for(i=0;i<tam;i++)
    {
        if(auxId==vec[i].id && vec[i].vacio==1)
        {
            printf("\nSe ha encontrado el Id, seguro que desea modificarlo? s/n: ");
            resp=getch();
            if(resp=='s')
            {
                printf("\n\nQue desea modificar?\n");
                printf("1.Nombre\n");
                printf("2.Apellido\n");
                printf("3.Salario\n");
                printf("4.Sector\n");

                printf("Su opcion es: ");
                scanf("%d",&opcion);
                printf("\n");

                switch(opcion)
                {
                    case 1:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(vec[i].nombre);
                        printf("\nEl nombre ha sido modificado.\n\n");
                        break;
                    case 2:
                        printf("Ingrese nuevo apellido: ");
                        fflush(stdin);
                        gets(vec[i].apellido);
                        printf("\nEl apellido ha sido modificado.\n\n");
                        break;
                    case 3:
                        printf("Ingrese nuevo salario: ");
                        scanf("%f",&vec[i].salario);
                        printf("\nEl salario ha sido modificado.\n\n");
                        break;
                    case 4:
                        printf("Ingrese nuevo sector: ");
                        scanf("%d",&vec[i].sector);
                        printf("\nEl sector ha sido modificado.\n\n");
                        break;
                }

            }
            else
            {
                printf("La operacion ha sido cancelada.");
            }
        }
    }
}

void removeEmployee(eEmployee vec[],int tam)
{
    int i;
    char resp;
    int auxId;

    printEmployees(vec,tam);

    printf("Ingrese Id a eliminar: ");
    scanf("%d",&auxId);

    for(i=0;i<tam;i++)
    {
        if(auxId==vec[i].id && vec[i].vacio==1)
        {
            printf("\n\nSe ha encontrado el Id ingresado, seguro que desea eliminarlo? s/n ");
            fflush(stdin);
            resp=getch();


                if(resp=='s')
                {
                    vec[i].vacio=0;
                    printf("\n\nSe ha eliminado el Id deseado.\n\n");
                }
                else
                {
                    printf("\n\nSe ha cancelado la operacion.");
                }
                break;
        }
    }

}

int menu()
{
    int opcion;

    printf("Menu de opciones: \n\n");
    printf("1.Alta\n");
    printf("2.Modificar\n");
    printf("3.Baja\n");
    printf("4.Informar\n");
    printf("5.Salir\n\n");

    printf("Su opcion es: ");
    scanf("%d",&opcion);

    return opcion;

}
