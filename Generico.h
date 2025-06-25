#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef GENERICO_H_INCLUDED
#define GENERICO_H_INCLUDED

int cmp_int(const void* a, const void* b);

float cmp_float(const void* a, const void* b);

void* buscar_min(void* vec, size_t ce, size_t tam_d, int (*cmp_float)(const void*, const void*));

void m_qsort(void* vec, size_t ce, size_t tam_d, int (*cmp)(const void *, const void *));

void *m_bsearch(const void *bus, const void *vec, size_t ce, size_t tam_d, int (*cmp)(const void *, const void *));

//3.1
void menu(float* vec, size_t ce);
int crear_vec(float* vec, size_t ce, size_t tam);
void buscar_min_float(float* vec, size_t ce);
void prom_pares(float* vec, size_t ce);
void mostrar_inversa(float* vec, size_t ce);
//3.2
long long int indice(void* vec, size_t ce, size_t tam_d, void* bus);
//3.3
int crear_vec_int(int* vec);
void mostrar_vec(void* vec, size_t ce, size_t tam_d);


#endif // GENERICO_H_INCLUDED
