
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef BUSQUEDA_BIN_H_INCLUDED
#define BUSQUEDA_BIN_H_INCLUDED
#define AMAYUS(x) (((x) >= 'a' && (x)<='z') ? (x - 32) : x)
#define AMINUS(x) (((x) >= 'A' && (x)<='Z') ? (x + 32) : x)
#define TAM 8

void* busqueda_bin(void* vec, void* bus, size_t ce, size_t tam_d);
int cmp_int(const void*, const void*);
int cmp_char(const void* a, const void* b);


#endif // BUSQUEDA_BIN_H_INCLUDED
