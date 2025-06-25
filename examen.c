#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//descomente para implementar



int fbbinariaALU(void *clave, const char* nomarch, size_t tam, int cmp(const void *, const void *))
{
    int CantRegistros;
    int ini = 0, fin, pm;
    void* aux = malloc(tam);
    if(!aux)
    {
        return 0;
    }

    FILE *pf = fopen(nomarch, "rb");

    if(!pf)
    {
        return 0;
    }

    fseek(pf, 0, SEEK_END);//Posiciono el puntero al final del archivo

    CantRegistros = ftell(pf);//Le asigno el tamaño en bytes del archivo

    CantRegistros = CantRegistros/tam;//Al dividir el tam en bytes del archivo por el tamaño en bytes del tipo de dato, me da como resultado la cantidad de registros

    fin = CantRegistros - 1;

    while(ini <= fin)
    {
        pm = (fin - ini)/2;

        fseek(pf,((ini + pm) * tam),SEEK_SET);//Paro al puntero en el medio

        fread(aux, tam, 1, pf);//Bajo el regitro que se encuentra en el medio

        if(cmp(aux,clave) == 0)//La funcion me compara los dni, si devuelve cero, significa que lo que hay en aux tiene el mismo dni que me mandaron a buscar
        {
            memcpy(clave, aux, tam);//Le pongo a clave lo que hay en aux(estudiante buscado)
            return 1;
        }

        if(cmp(aux,clave) > 0)//Si la funcion retorna mayot que cero, significa que lo que hay en aux es mas grande
        {
            CantRegistros = CantRegistros - pm - 1;
            fin = pm - 1;
        }

        if(cmp(aux,clave) < 0)//Si la funcion retorna menor que cero, significa que lo que hay en aux es mas chico
        {
            ini = pm + 1;
            CantRegistros = CantRegistros - pm - 1;
        }

    }//Si sale de aca significa que no lo encontro

    free(aux);

    fclose(pf);

    return 1;

}

