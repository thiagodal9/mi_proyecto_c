#include "Busqueda_bin.h"

void* busqueda_bin(void* vec, void* bus, size_t ce, size_t tam_d)
{
    char *pi = vec;
    char *pf = vec + ((ce - 1)* tam_d);
    char *medio = pi + ((((pf - pi)/tam_d)/2) * tam_d);
    while(pi <= pf)
    {
        medio = pi + ((((pf - pi)/tam_d)/2) * tam_d);
        int aux = cmp_char(medio,bus);
        if(aux == 0)
        {
            return medio;
        }
        if(aux > 0)
        {
           pf = medio - tam_d;
        }
        if(aux < 0)
        {
            pi = medio + tam_d;
        }
    }
    return NULL;//Si no lo encuentra
}

int cmp_int(const void* a, const void* b)
{
    return(*(int*)a - *(int*)b);
}


int cmp_char(const void* a, const void* b)
{
    return(*(char*)a - *(char*)b);
}
