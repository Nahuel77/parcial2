#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct empleados
{
    int dni;
    char apellido[50];
    char categoria[50];
    int horas;
} T_Empleado;

T_Empleado carga()
{
    int i, status;
    T_Empleado empleado;
    do
    {
        printf("Ingrese el numero de DNI.\n");
        fflush(stdin);
        scanf("%d", &empleado.dni);
        if(empleado.dni<=0)
        {
            printf("El numero de DNI ingresado es invalido.\n");
        }
    }while(empleado.dni<=0);

    printf("Ingrese el apellido.\n");
    fflush(stdin);
    gets(empleado.apellido);

    do
    {
        printf("Ingrese la categoria (Peon/Capataz/jefe/Gerente).\n");
        fflush(stdin);
        gets(empleado.categoria);
        empleado.categoria[0]=toupper(empleado.categoria[0]);
        i=1;
        status=1;
        while(empleado.categoria[i]!='\0')
        {
            empleado.categoria[i]=tolower(empleado.categoria[i]);
            i++;
        }
        if(strcmp(empleado.categoria, "Peon")==0)
        {
            status=0;
        }
        if(strcmp(empleado.categoria, "Capataz")==0)
        {
            status=0;
        }
        if(strcmp(empleado.categoria, "Jefe")==0)
        {
            status=0;
        }
        if(strcmp(empleado.categoria, "Gerente")==0)
        {
            status=0;
        }
    }
    while(status!=0);

    do
    {
        printf("Ingrese la cantidad de horas trabajadas.\n");
        fflush(stdin);
        scanf("%d", &empleado.horas);
        if(empleado.horas<0)
        {
            printf("La cantidad de horas ingresadas no son validas.\n");
        }
    }
    while(empleado.horas<0);

    return empleado;
}

void calcularAbonos(T_Empleado empleados[], int num)
{
    int i, j;
    FILE *txt;
    txt=fopen("VALORES.txt", "r");
    char cate[50];
    int valor;
    int total;
    if(txt!=NULL)
    {
        while(fscanf(txt, "%s%d", &cate, &valor)!=EOF)
        {
            for(i=0; i<num; i++)
            {
                if(strcmp(empleados[i].categoria, cate)==0)
                {
                    total=empleados[i].horas*valor;
                    printf("%s\t\t%d\n", empleados[i].apellido, total);
                }
            }
        }
    }
    else
    {
        printf("Archivo no encontrado.\n");
    }
}

void calcularAbonosMenosHoras(T_Empleado empleados[], int num)
{
    int i, j;
    FILE *txt;
    txt=fopen("VALORES.txt", "r");
    char cate[50];
    int valor;
    int total;
    if(txt!=NULL)
    {
        while(fscanf(txt, "%s%d", &cate, &valor)!=EOF)
        {
            for(i=0; i<num; i++)
            {
                if(strcmp(empleados[i].categoria, cate)==0)
                {
                    if(empleados[i].horas<10)
                    {
                        total=empleados[i].horas*valor;
                        printf("%s\t\t%d\n", empleados[i].apellido, total);
                    }
                }
            }
        }
    }
    else
    {
        printf("Archivo no encontrado.\n");
    }
}

#endif // HEADER_H_INCLUDED
