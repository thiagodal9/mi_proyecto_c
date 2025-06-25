#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_ARCH 1

typedef struct
{
    int dni;
    char nom[20];
    int sueldo;
}Templeado;

typedef struct
{
    Templeado emp;
    char Nov;
}Tnovedad;

int CrearArchMaestro(char* NomArch);
int CrearArchNovedades(char* NomArch);
int Merge(char* NomMaestro, char* NomVovedades);

int MostrarArchEmpleados(char* NomArch);

#endif // MERGE_H_INCLUDED
