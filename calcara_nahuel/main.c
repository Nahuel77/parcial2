#include <stdio.h>
#include <stdlib.h>
#include "header.h"

T_Empleado carga();
void calcularAbonos(T_Empleado empleados[], int num);
void calcularAbonosMenosHoras(T_Empleado empleados[], int num);

int main()
{
    int i, num;
    printf("Ingrese la cantidad de empleados a registrar.\n");
    fflush(stdin);
    scanf("%d", &num);
    T_Empleado empleados[num];
    system("cls");
    for(i=0; i<num; i++){
        printf("Empleado n %d.\n", i+1);
        empleados[i]=carga();
        system("cls");
    }
    system("pause");
    printf("Liquidacion:\n");
    calcularAbonos(empleados, num);
    system("pause");
    system("cls");
    printf("Liquidacion mostrada por quienes trabajaron menos de 10 horas.\n");
    calcularAbonosMenosHoras(empleados, num);
    return 0;
}
