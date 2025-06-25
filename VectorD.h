#ifndef VECTORD_H_INCLUDED
#define VECTORD_H_INCLUDED

#include <stdbool.h>

#define TODO_OK 0
#define DUPLICADO 1
#define SIN_MEM 2

#define CAP_INI 10

typedef struct
{
    void* vec;
    int ce;
    int cap;
    size_t tamElem;
}
Vector;

typedef int (*Cmp)(const void* e1, const void* e2);
typedef void (*Imprimir)(const void* e);

void vectorInicializarRandom(Vector* v, int ce);
bool vectorCrear(Vector* v, size_t tamElem); //malloc
void vectorDestruir(Vector* v); //free
void vectorVaciar(Vector* v); //realloc -
int vectorOrdInsertar(Vector* v, const void* dato); //realloc +
bool vectorOrdEliminarElemento(Vector* v, void* dato); //realloc -
void vectorMostrar(Vector* v, Imprimir imprimir);
int vectorInsertarAlFinal(Vector *v, const void* dato);
void intercambiar(void* e1, void* e2, size_t tamElem);
void vectorOrdenarBurbujeo(Vector *v);
void vectorOrdenarSeleccion(Vector *v, Cmp cmp);
void vectorOrdenarInsercion(Vector *v);



#endif // VECTORD_H_INCLUDED
