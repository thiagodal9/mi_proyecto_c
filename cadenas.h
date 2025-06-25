#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED

#define ERROR_MALLOC 2

#define ESLETRA(x) ( ((x) >= 'A' && (x) <= 'Z') || ((x) >= 'a' && (x) <= 'z')   ? 1 : 0)

#define AMAYUS(x) ((x) >= 'a' && (x) <= 'z' ? (x  - 32) : (x))

#define AMINUS(x) ((x) >= 'A' && (x) <= 'Z' ?(x + 32) : (x))

//////////////////////////////FUNCIONES DE BIBLIOTECA//////////////////////////////
int m_strlen(const char* cad);

char* m_strchr(char* cad, int c);

int m_strcmp(const char *s1, const char *s2);

char* m_strrchr(char* cad, int c);

char* m_strcat(char* cad1, const char* cad2);

char* m_strcpy(char* cad1, const char* cad2);

int m_strncmp(const char *s1, const char *s2, size_t n);

char* m_strncpy(char *s1, const char *s2, size_t n);

char* m_strncat(char*s1, const char *s2, size_t n);

char* m_strpbrk(const char *s1, const char *s2);

size_t m_strspn(const char *s1, const char *s2);

size_t m_strspn_completo(const char *s1, const char *s2);

char* m_strstr(const char *s1, const char *s2);

void* m_memchr(const void *cad, int c, size_t n);

int m_memcmp(const void *s1, const void *s2, size_t n);

void* m_memcpy(void *s1, const void *s2, size_t n);

void* m_memmove(void *s1, const void *s2, size_t n);

void* m_memset(void *s, int c, size_t n);

size_t m_strcspn(const char *s1, const char *s2);

size_t m_strcspn_sensitive(const char *s1, const char *s2);

///////////////////////////////////////////////////////////////////////////////////
int cmp_char(const void* a, const void* b);

char* copiacadena(const char* cad);

size_t proxpal(char* cad);

char* Desofuscar(char* cad, char* grupo);

//1.8
size_t CantReps(char* cad, char* bus);


//Mio
void Abuelo();

#endif // CADENAS_H_INCLUDED
