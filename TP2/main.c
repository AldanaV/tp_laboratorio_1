#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"


#define TAM 1000
#define TAMS 4


int main()
{
    char seguir='s';


    eSector sector[TAMS]={{1,"Sistemas"},{2,"RRHH"},{3,"Ventas"},{4,"Compras"}};
    eEmployee list[TAM];
    initEmployee(list,TAM);

    do
    {
        switch(menu())
        {
            case 1:
                system("cls");
                addEmployee(list,TAM);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                modificarEmpleado(list,TAM);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                removeEmployee(list,TAM);
                system("pause");
                system("cls");
                break;
            case 4:
                break;
            case 5:
                seguir='n';
                break;
            default:
                system("cls");
                printf("Error, reingrese opcion.\n\n");
                system("pause");
                system("cls");
                break;
        }
    }while(seguir=='s');


    return 0;
}
