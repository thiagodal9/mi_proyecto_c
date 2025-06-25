#include "Generico.h"

int cmp_int(const void* a, const void* b)
{
    return(*(int*)a - *(int*)b);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float cmp_float(const void* a, const void* b)
{
    return(*(float*)a - *(float*)b);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void* buscar_min(void* vec, size_t ce, size_t tam_d, int (*cmp)(const void*a, const void* b))
{
    void *min = (char*)vec;//Le asigno la direccion del primer elemento
    void *prox = (char*)vec;
    int i;

    for (i = 1; i < ce; i++)
    {
        prox += tam_d;//Hago que se posicione en el siguiente elemento
        if (cmp(prox, min) < 0)//Si lo que hay en el siguiente elemento es mas chico
        {
            min = prox;//Pngo en min lo que hay en el siguiente elemento
        }
    }

    return min;//Retorno la direccion de min
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void m_qsort(void *vec, size_t ce, size_t tam_d, int (*cmp)(const void *a, const void *b))
{
    void *fin = vec + (ce - 1) * tam_d;//Lo posiciono en el ultimo elemento
    void *aux = malloc(tam_d);//Hago un malloc para que pueda contener al dato
    void *min;

    while (vec < fin)
    {
        ce = ((fin - vec) / tam_d) + 1;

        min = buscar_min(vec, ce, tam_d, cmp);

        if (cmp(vec, min) > 0)
        {
            memcpy(aux, vec, tam_d);
            memcpy(vec, min, tam_d);
            memcpy(min, aux, tam_d);
        }

        vec += tam_d;
    }

    free(aux);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void *m_bsearch(const void *bus, const void *vec, size_t ce, size_t tam_d, int (*cmp)(const void *, const void *))
{
    int pm = (ce/2);
    void* ppm = (char*)vec + (pm * tam_d);
    void* pi = (char*)vec;
    void* fin = (void*)vec + (ce-1)*tam_d;
    while(pi <= fin)
    {
        pm = (ce/2);
        ppm = (char*)pi + (pm)* tam_d;

        if(cmp(ppm,bus) > 0)//Si ppm es mayor, significa que el valor buscado esta antes
        {
            ce = pm;
            fin = ppm - tam_d;
        }

        if(cmp(ppm,bus) < 0)//Si ppm es menor, significa que el valor buscado esta despues
        {
            ce = ce - pm - 1;
            pi = (char*)ppm + tam_d;
        }

        if(cmp(ppm,bus) == 0)
        {
            return ppm;//Retorno el puntero al elemento
        }

    }//Si sale de aca es que no lo encontro

    return NULL;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu(float* vec, size_t ce)
{
    int op;
    printf("\n1-Buscar el minimo elemento\n2-Calcular el promedio de los valores de las posiciones pares\n3-Mostrarlo en orden inverso\n4-Salir");
    printf("\nElegir una opcion:");
    scanf("%d",&op);
    while(op != 4)
    {
        switch(op)
        {
        case 1:
            buscar_min_float(vec, ce);
            break;

        case 2:
            prom_pares(vec, ce);
            break;

        case 3:
            mostrar_inversa(vec, ce);
            break;

        case 4:
            break;

        }
        printf("\nElegir una opcion:");
        scanf("%d",&op);
    }

}
///////////////////////////////////////////////////////////////
int crear_vec(float* vec, size_t ce, size_t tam)
{
    int tamanio;
    float* orig = vec;
    float aux;
    printf("\nIngresar valor(termina con 0):");
    scanf("%f", &aux);
    //printf("\n%.2f", aux);
    while(aux != 0)
    {
        *vec = aux;
        //printf("\n%.2f", *vec);
        ce++;
        tamanio = ce + (ce * 0.2);
        if(ce == 10)
        {
            vec = realloc(vec, tamanio);
            if(!vec)
            {
                printf("\nNo hay memoria");
                return 1;
            }
        }
        vec++;
        printf("\nIngresar valor(termina con 0):");
        scanf("%f", &aux);
    }
    vec = orig;
    vec = realloc(vec, ce);//Lo reduzco a la cantida de elementos
    return ce;

}
///////////////////////////////////////////////////////////////
void buscar_min_float(float* vec, size_t ce)
{
    float min;
    float* pi = vec;
    float* pf = vec + ce - 1;
    min = *vec;
    while(pi <= pf)
    {
        if(*pi <= min)
        {
            min = *pi;
        }
        pi++;
    }
    printf("\nEl valor minimo del vector es: %.2f", min);
}
///////////////////////////////////////////////////////////////
void prom_pares(float* vec, size_t ce)
{
    float* pi = vec + 1;
    float* pf = vec + ce - 1;
    int cont = 0;
    float prom = 0;
    while(pi <= pf)
    {
        cont++;
        prom += *(pi);
        pi+= 2;
    }
    prom = prom/ cont;
    printf("\nEL promedio de los numeros pares es: %.2f", prom);
}
///////////////////////////////////////////////////////////////
void mostrar_inversa(float* vec, size_t ce)
{
    float* pi = vec;
    float* pf = vec + ce - 1;
    printf("\n");
    while(pi <= pf)
    {
        printf("%.2f\t",*pf);
        pf--;
    }
}
///////////////////////////////////////////////////////////////
long long int indice(void* vec, size_t ce, size_t tam_d, void* bus)
{
    void* pi = vec;
    void* pf = vec + ((ce - 1) * tam_d);
    while((char*)pi <= (char*)pf)
    {
        if(*(char*)pi == *(char*)bus)
        {
            return (((char*)pi - (char*)vec)/ tam_d);
        }
        pi += tam_d;
    }
    return 0;
}
///////////////////////////////////////////////////////////////
int crear_vec_int(int* vec)
{
    int ce = 0, tamanio = 10, i;//Vamos a crear el vector en esta funcion, por lo tanto el ce = 0, le asignamos un tam inicial de 10, aux para ingresar valor
    int* ini = vec;//A ini le asigno la direccion inicial de vec
    int* tmp;
    vec = realloc(vec, tamanio);
    if(!vec)
    {
        printf("\nNo hay memoria");
        return 1;
    }
    for(i = 0; i < 5; i++)//Le cargamos n elementos al vector
    {
        *vec = (i + 1);//le asignamos un valor
        ce++;//al ingresar un nuevo valor aumenta la cantidad de elementos del vector
        if(ce == tamanio)//si la cantidad de elementos es igual al tam del vector la aumentamos el tam
        {
            printf("\nCrece");//Informa que le tuvo que aumentar el tam
            tamanio += tamanio * (0.2);//Le agregamos un 20% del tam actual
            tmp = realloc(vec, tamanio);
            if(!tmp)
            {
                printf("\nNo hay memoria");
                free(vec);
                return 1;
            }
            vec = tmp;
        }

        vec++;//Incrementamos el puntero del vec para que lo asigne a la siguiente pos
    }//Cuando sale del for ya esta el vec cargado
    vec = ini;//Le asigno a vec la direccion inicial de vec
    vec = realloc(vec, ce);//Reducimos el tam a la cant de elementos
    return ce;//Retorna la direccion de memoria del vector
}
///////////////////////////////////////////////////////////////
void mostrar_vec(void* vec, size_t ce, size_t tam_d)
{
    int i;
    printf("\n");
    for(i = 0; i < ce; i++)
    {
        printf("\n%d",*(int*)vec);//Lo casteo como char para que pueda mostrar cualquier dato
        vec+= tam_d;//Incremento vec con el tamanio del dato para pasar al prox elemento
    }
}

