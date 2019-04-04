#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float num1;
    float num2;
    char seguir = 's';
    int opcion;
    float resulSuma,resulResta,resulDivi, resulMult;
    int resFactorial;
    int flagA=0,flagB=0;

    while(seguir=='s')
    {
        printf("Menu de opciones: \n");

        if(flagA==0)
        {
         printf("\n1.Ingrese el primer valor (A): \n");
        }
        else
        {
            printf("\n1.Ingrese el primer valor (A = %.2f): \n",num1);
        }

        if(flagB==0)
        {
            printf("2.Ingrese segundo valor (B): \n");
        }
        else
        {
            printf("2.Ingrese segundo valor (B = %.2f): \n",num2);
        }

        printf("3.Calcular todas las opeciones\n");
        printf("4.Informe de todos los resultados\n");
        printf("5.Salir\n\n");

        printf("La opcion ingresada es: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("Ingrese el primer valor (A):");
            scanf("%f",&num1);
            flagA=1;
            system("cls");
            break;
        case 2:
            system("cls");
            printf("Ingrese el segundo valor (B): ");
            scanf("%f",&num2);
            flagB=1;
            system("cls");
            break;
        case 3:
            system("cls");
            resulSuma=sumar(num1,num2);
            resulResta=restar(num1,num2);
            resulDivi=dividir(num1,num2);
            resulMult=multiplicar(num1,num2);
            resFactorial=factorial(num1);
            printf("Los calculos se han realizado con exito.\n\n");
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            printf("Informe de los resultados: \n\n");
            printf("El resultado de la suma es: %.2f\n\n",resulSuma);
            printf("El resultado de la resta es: %.2f\n\n",resulResta);
            printf("El resultado de la division es: %.2f\n\n",resulDivi);
            printf("El resultado de la multiplicacion es: %.2f\n\n",resulMult);
            printf("El factorial de A es: %d\n\n",resFactorial);
            system("pause");
            system("cls");
            break;
        case 5:
            seguir ='n';
            break;

        }

    }


    return 0;
}


