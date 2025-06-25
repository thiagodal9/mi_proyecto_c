#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "VectorD.h"
#include <time.h>
#include <memory.h>

void* buscarMenor(void* ini, void* fin, size_t tamElem, Cmp cmp);

bool vectorCrear(Vector* v, size_t tamElem) //malloc
{
    v->vec = malloc(CAP_INI * tamElem);

    if (v->vec == NULL)
        return false;

    v->cap = CAP_INI;
    v->ce = 0;
    v->tamElem = tamElem;

    return true;
}

void vectorDestruir(Vector* v) //free
{
    free(v->vec);
    v->vec = NULL;
    v->cap = 0;
    v->ce = 0;
    v->tamElem = 0;
}

void vectorVaciar(Vector* v) //realloc -
{
    v->vec = realloc(v->vec, CAP_INI * v->tamElem);
    v->cap = CAP_INI;
    v->ce = 0;
}

int vectorOrdInsertar(Vector* v, const void* dato) //realloc +
{
    if (v->ce == v->cap)
    {
        int nCap = v->cap * 1.5;
        int* nVec = realloc(v->vec, nCap * sizeof(int));

        if(!nVec)
            return SIN_MEM;

        v->vec = nVec;
        v->cap = nCap;
    }

    int* posIns = v->vec;
    int* ult = v->vec + v->ce - 1;

    while (posIns <= ult && *posIns < dato)
        posIns++;

    if(posIns <= ult && dato == *posIns)
        return DUPLICADO;

    for(int* i = ult; i >= posIns; i--)
        *(i + 1) = *i;

    *posIns = dato;
    v->ce++;

    return TODO_OK;
}

bool vectorOrdEliminarElemento(Vector* v, void* dato) //realloc -
{
    int* posElim = v->vec;
    int* ult = v->vec + v->ce - 1;

    while (posElim <= ult && *posElim < dato)
    {
        posElim++;
    }

    if(posElim > ult || dato != *posElim)
        return false;

    for(int* i = posElim; i < ult; i++)
        *i = *(i + 1);

    v->ce--;

    if(v->cap >= v->ce *4)
    {
        v->cap /= 2;
        v->vec = realloc(v->vec, v->cap * sizeof(int));
    }

    return true;
}

void vectorMostrar(Vector* v, Imprimir imprimir)
{
    void* ult = v->vec + (v->ce) * v->tamElem;
    for(void* i = v->vec ; i < ult; i += v->tamElem)
    {
        imprimir(i);
        putchar('\n');
    }

    printf("\n");
}

void vectorOrdenarBurbujeo(Vector *v)
{
    for (int i = 0, *limJ = v->vec + v->ce - 2; i < v->ce; i++, limJ--)
    {
        for(int* j = v->vec; j <= limJ; j++)
        {
            if(*j > *(j+1))
            {
                intercambiar(j, j+1, v->tamElem);
            }
        }
    }

}


void intercambiar(void* e1, void* e2, size_t tamElem)
{
    void* e1temp = malloc(tamElem);

    memcpy(e1temp, e1, tamElem); // e1temp = *e1;
    memcpy(e1, e2, tamElem); // *e1 = *e2;
    memcpy(e2, e1temp, tamElem); // *e2 = e1temp;

    free(e1temp);
}

int vectorInsertarAlFinal(Vector *v, const void* dato)
{
    if (v->ce == v->cap)
    {
        int nCap = v->cap * 1.5;
        int* nVec = realloc(v->vec, nCap * v->tamElem);

        if(!nVec)
            return SIN_MEM;

        v->vec = nVec;
        v->cap = nCap;
    }

    void* ult = v->vec + v->ce * v->tamElem;
    memcpy(ult, dato, v->tamElem); //*ult = dato;
    v->ce++;
}

void vectorOrdenarSeleccion(Vector *v, Cmp cmp)
{
    void* ult = v->vec + (v->ce - 1) * v->tamElem;
    void* m;
    for (void* i = v->vec; i < ult; i+=v->tamElem)
    {
        m = buscarMenor(i, ult, v->tamElem, cmp);
        intercambiar(i, m, v->tamElem);
    }
}

void* buscarMenor(void* ini, void* fin, size_t tamElem, Cmp cmp)
{
    void* m = ini;
    for (void* j = ini + tamElem; j <= fin; j += tamElem)
    {
        if(cmp(j, m) < 0)
            m = j;
    }
    return m;
}

void vectorOrdenarInsercion(Vector *v)
{
    int* ult = v->vec + v->ce - 1;
    int* j;
    int elemAIns;
    for( int* i = v->vec + 1; i <= ult; i++)
    {
        elemAIns = *i;
        j = i - 1;
        while(j >= v->vec && elemAIns < *j)
        {
            *(j+1) = *j;
            j--;
        }
        *(j+1) = elemAIns;
    }
}

//void vectorInicializarRandom(Vector* v,int ce)
//{
//    v->ce = ce;
//    v->cap = ce;
//    v->vec = realloc(v->vec, ce * sizeof(int));
//
//    srand(time(NULL));
//
//    for(int i = 0; i < ce; i++)
//        v->vec[i] = rand() % 100;
//}
