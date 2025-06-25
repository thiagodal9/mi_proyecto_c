#include "Merge.h"

int CrearArchMaestro(char* NomArch)
{
    FILE *pf;
    int i;
    Templeado emp[5] = {{1,"Lionel", 750},
        {2,"Cristiano", 800},
        {4,"Franco", 300},
        {6,"Angel",600},
        {7,"Enzo", 550}
    };
    pf = fopen(NomArch, "wb");
    if(!pf)
    {
        printf("\nNo se pudo crear el archivo maestro");
        return ERROR_ARCH;
    }
    for(i = 0; i < 5; i++)
    {
        fwrite(&emp[i],sizeof(emp[i]),1,pf);
    }
    fclose(pf);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CrearArchNovedades(char* NomArch)
{
    FILE *pf;
    int i;
    Tnovedad nov[5] = {{{1,"Lionel",10000}, 'm'},
        {{3,"Luciano", 1500}, 'a'},
        {{4,"Franco", 3}, 'b'},
        {{8,"Matias",6}, 'b'},
        {{9,"Mika", 7}, 'a'}};

    pf = fopen(NomArch, "wb");
    if(!pf)
    {
        printf("\nNo se pudo crear el archivo Novedades");
        return ERROR_ARCH;
    }
    for(i = 0; i < 5; i++)
    {
        fwrite(&nov[i],sizeof(nov[i]),1,pf);
    }
    fclose(pf);
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Merge(char* NomMaestro, char* NomVovedades)
{
    FILE *ArchMaestro, *ArchNov, *ArchTemp, *ArchError;
    Tnovedad nov;
    Templeado empleado, aux;

    ArchMaestro = fopen(NomMaestro, "r + b");
    if(!ArchMaestro)
    {
        printf("\nNo se pudo abrir el archivo maestro");
        return ERROR_ARCH;
    }

    ArchNov = fopen(NomVovedades, "r + b");
    if(!ArchNov)
    {
        printf("\nNo se pudo abrir el archivo Novedad");
        return ERROR_ARCH;
    }

    ArchTemp = fopen("ArchTemp", "wb");
    if(!ArchTemp)
    {
        printf("\nNo se pudo abrir el archivo Temporal");
        return ERROR_ARCH;
    }

    ArchError = fopen("ArchError", "wt");
    if(!ArchError)
    {
        printf("\nNo se pudo abrir el archivo Error");
        return ERROR_ARCH;
    }

    fread(&nov, sizeof(Tnovedad), 1, ArchNov);//Leo el primer registro del archivo novedad

    fread(&empleado, sizeof(Templeado), 1, ArchMaestro);//Leo el primer registro del archivo Maestro

    while(!feof(ArchNov)  && !feof(ArchMaestro))//Si ninguno de los 2 llego al fin
    {
        if(empleado.dni > nov.emp.dni)//Si el registro del empleado es mas grande que el del novedad
        {
            if(nov.Nov == 'a')//Si lo que hay en novedades es una alta
            {
                aux = nov.emp;//Pongo en aux la info del empleado bajado de novedad
                fwrite(&aux,sizeof(Templeado), 1, ArchTemp);//Escribo en el archivo temporal
            }

            else//Si es mas bajo que empleado y no es alta, es un error
            {
                fprintf(ArchError, "%d%s%d%c\n", nov.emp.dni, nov.emp.nom, nov.emp.sueldo, nov.Nov);//Escribo el registro novedad en el archivo de error
            }
            fread(&nov, sizeof(Tnovedad), 1, ArchNov);//Leo un registro del archivo novedad
        }



        if(empleado.dni < nov.emp.dni)//Si el registro de novedad es mas grande que el de empleado
        {

            fwrite(&empleado, sizeof(Templeado), 1, ArchTemp);//Escribo al empleado en el archivo temporal
            fread(&empleado, sizeof(Templeado), 1, ArchMaestro);//Leo un registro del archivo maestro
        }




        if(empleado.dni == nov.emp.dni)//Si hay match
        {

            if(nov.Nov == 'm')//Si es una modificacion
            {
                aux = nov.emp;//Copio en aux la info del empleado
                fwrite(&aux, sizeof(Templeado), 1, ArchTemp);//Escribo en temporal la nueva info del empleado

            }



            if(nov.Nov == 'a')//Si es una alta siendo match, significa que es un error
            {
                fprintf(ArchError, "%d%s%d%c", nov.emp.dni, nov.emp.nom, nov.emp.sueldo, nov.Nov);//Escribo el registro novedad en el archivo de error
            }


            fread(&nov, sizeof(Tnovedad), 1, ArchNov);//Leo un registro del archivo novedad

            fread(&empleado, sizeof(Templeado), 1, ArchMaestro);//Leo un registro del archivo Maestro
        }
    }

    while(!feof(ArchMaestro))//Si lo que queda es del maestro
    {
        fwrite(&empleado, sizeof(Templeado),1, ArchTemp);//Escribo el registro en el archivo temporal
        fread(&empleado, sizeof(Templeado),1, ArchMaestro);//Leo un registro del archivo Maestro
    }

    while(!feof(ArchNov))//Si lo que queda es el archivo novedad
    {
        if(nov.Nov == 'a')//Solo pueden ser altas, ya que no tengo con que comparar
        {
            aux = nov.emp;//Pongo en aux la info del empleado bajado de novedad
            fwrite(&aux,sizeof(Templeado), 1, ArchTemp);//Escribo en el archivo temporal
        }

        else//Si solo queda novedad y no es alta, es un error
        {
            fprintf(ArchError, "%d%s%d%c",nov.emp.dni, nov.emp.nom, nov.emp.sueldo, nov.Nov);//Escribo el registro novedad en el archivo de error
        }
        fread(&nov, sizeof(Tnovedad), 1, ArchNov);//Leo un registro del archivo novedad
    }

    fclose(ArchMaestro);//Cierro el archivo maestro
    fclose(ArchNov);//Cierro el archivo novedad
    fclose(ArchError);//Cierro el archivo de errores
    fclose(ArchTemp);//Cierro el archivo temporal

    remove(NomMaestro);//Borro el archivo maestro

    rename("ArchTemp", NomMaestro);//Renombro el archivo temporal, para que sea el nuevo maestro

    return 0;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MostrarArchEmpleados(char* NomArch)
{
    FILE *ArchEmpleados;
    Templeado aux;

    ArchEmpleados = fopen(NomArch, "rb");

    if(!ArchEmpleados)
    {
        printf("\nNo se pudo abrir el archivo empleados");
        return ERROR_ARCH;
    }


    fread(&aux, sizeof(Templeado), 1, ArchEmpleados);
    printf("\nSueldo\tNombre\tSueldo");
    while(!feof(ArchEmpleados))
    {
        printf("\n%d\t%s\t%d", aux.dni, aux.nom, aux.sueldo);
        fread(&aux, sizeof(Templeado), 1, ArchEmpleados);

    }

    fclose(ArchEmpleados);
    return 0;
}
