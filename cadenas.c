#include "cadenas.h"

int m_strlen(const char* cad)
{
    int cant = 0;
    while(*cad != '\0')
    {
        cant++;
        cad++;
    }
    return cant;
}
///////////////////////////////////////////////////////////////
char* m_strchr(char* cad, int c)
{
    while(*cad)
    {
        if(*cad == c)
        {
            return cad;
        }
        cad++;
    }
    return 0;//Salio mal
}

///////////////////////////////////////////////////////////////
int m_strcmp(const char *s1, const char *s2)
{
    while(*s1 && *s2)//Mientras ninguna de las 2 cadenas llegue al fin
    {
        if(cmp_char(s1,s2) == 0)//Comparo los caracter de las cadena son iguales
        {
            s1++;//Incremento s1
            s2++;//Incremento s2
        }

        else//Si los caracteres no son iguales
        {
            return (*(s1) - *(s2));//Retorno la diferencia
        }

    }//Si sale, es porque una de las 2 cadenas se termino, es decir, que hasta donde comparo, todos los caracteres eran iguales

    return 0;//Retorno 0 porque no habia diferencia entre una cadena y la otra
}
///////////////////////////////////////////////////////////////
char* m_strrchr(char* cad, int c)
{
    char* ini = cad;
    size_t tam = m_strlen(cad);
    char* fin = ini + tam;
    while(fin > ini)
    {
        if(*(fin) == c)
        {
            return fin;
        }
        fin--;
    }
    return 0;//No se encontro
}

///////////////////////////////////////////////////////////////
char* m_strcat(char* cad1, const char* cad2)
{
    size_t tam1 = m_strlen(cad1);
    char* fin = cad1 + tam1;
    while(*cad2)
    {
        *fin = *cad2;
        fin++;
        cad2++;
    }
    *fin = '\0';
    return cad1;
}
///////////////////////////////////////////////////////////////
char* m_strcpy(char* cad1, const char* cad2)
{
    char* ini = cad1;
    while(*cad2)
    {
        *cad1 = *cad2;
        cad1++;
        cad2++;
    }
    return ini;
}
///////////////////////////////////////////////////////////////
char* m_strstr(const char *s1, const char *s2)
{
    size_t TamCad2 = m_strlen(s2);//Le asigno la cantidad de caracteres de s2, para saber si es una cadena vacia
    char *inicio;
    char *p1;
    char *p2;

    if(TamCad2 == 0)//Si es una cadena vacia
    {
        return (char*)s1;//Retorno s1
    }

    while (*s1)
    {
        inicio = (char*)s1;
        p1 = (char*)s1;
        p2 = (char*)s2;

        while (*p1 && *p2 && (*p1 == *p2))
        {
            p1++;
            p2++;
        }

        if (*p2 == '\0')  // Si llegamos al final de s2, hubo coincidencia completa
            return (char *)inicio;

        s1++;  // Si no hubo coincidencia completa, probamos desde el siguiente carácter
    }

    return NULL;  // No se encontró
}
///////////////////////////////////////////////////////////////
int m_strncmp(const char *s1, const char *s2, size_t n)
{
    int i = 0;
    while((*s1 && *s2) && i < n)//Mientras que ninguna de las 2 cadenas se termine y haya comparado menos de n caracteres
    {
        if(cmp_char(s1,s2) == 0)//Comparo los caracter de las cadena son iguales
        {
            s1++;//Incremento s1
            s2++;//Incremento s2
        }

        else//Si los caracteres no son iguales
        {
            return (*(s1) - *(s2));//Retorno la diferencia
        }

        i++;
    }//Si sale es porque hasta la cantidad de caracteres que se compararon son iguales

    return 0;
}
///////////////////////////////////////////////////////////////
char* m_strncpy(char *s1, const char *s2, size_t n)
{
    int i = 0;
    char* IniS1 = s1;//Le asigno la direccion inicial de s1
    while(i < n)//Mientras haya copiado menos de n caracteres
    {
        if(*s2)//Si s2 no se terminó
        {
            *s1 = *s2;//Copio en s1 el caracter que hay en s2
            s2++;//Incremento s2
        }

        else//Si entra es porque aunque no se hayan copiado n caracteres, s2 ya terminó, entonces debo completar con caracteres nulos
        {
            *s1 = '\0';
        }

        s1++;//Incremento s1
        i++;
    }//Sale porque se termino s2 o porque ya copio todos los caracteres que queria(i = n)

    return IniS1;//Retorna la direccion inicial de s1
}
///////////////////////////////////////////////////////////////
char* m_strncat(char* s1, const char *s2, size_t n)
{
    size_t tam1 = m_strlen(s1);//Le asigno la cant de caracteress de la cadena 1
    char* fin = s1 + tam1;//Para a fin sobre el caracter nulo de s1
    int i = 0;
    while(*s2 && i < n)//Mientras que no se termine s2 y haya copiado menos de n caracteres
    {
        *fin = *s2;//Pongo en fin lo que hay en s2
        fin++;//Incremento fin
        s2++;//Incremento s2
        i++;
    }//Sale porque se terminó s2 o porque ya copio toso los caracteres(i = n)

    *fin = '\0';//Le añado el caracter nulo al final de la cadena
    return s1;//Retorno la direccion inicial de s1, ya que nunca lo moví
}
///////////////////////////////////////////////////////////////
char* m_strpbrk(const char *s1, const char *s2)
{
    char* Inis2 = (char*)s2;//Le asigno la direccion inicial de s2
    while(*s1)//Mientras no se termine s1
    {
        while(*s2)//Mientras no se termine s2
        {
            if(*s1 == *s2)//Si lo que hay en s1 es igual a lo que hay en s2
            {
                return ((char*)s1);//Retorna la direccion de el caracter
            }

            else//Si lo que hay es diferente
            {
                s2++;//Incremento s2
            }

        }//Sale porque el caracter apuntado por s1 no coincide con ninguno de los de s2
        s2 = Inis2;//Posiciono a s2 al inicio
        s1++;//Incremento s1
    }//Si sale es que no coincidio ningun caracter

    return NULL;//Retorno un puntero nulo porque no hay coincidencia
}
///////////////////////////////////////////////////////////////
size_t m_strspn(const char *s1, const char *s2)
{
    char* IniS2 = (char*)s2;//Le asigno la direccion inicial de s2
    size_t cont = 0;
    while(*s1)//Mientras no termine s1
    {
        while(*s2 && ESLETRA(*s1))//Mientras no termine s2 y s1 apunte a una letra
        {
            if(*s1 == *s2)//Si hay match
            {
                cont++;//incremento contados porque hubo match
                s1++;//Incremento s1
                s2 = IniS2;//Vuelvo a posicionar a s2 al principio
            }

            else//Si no hay match tengo que seguir omparando el caracter de s1 con los demas caractes de s2
            {
                s2++;
            }
        }//sale cuando termina s2 o cuando no es letra

        if(cont != 0)//Al no ser strspn completo, cuando hay una coincidencia ya devuele
        {
            return cont;
        }
        s2 = IniS2;//Si termino s2 tengo que posicionarlo al principio para poder seguir comparando
        s1++;//Si

    }//Si sale de aca es porque se termino s1

    return cont;
}
///////////////////////////////////////////////////////////////
size_t m_strspn_completo(const char *s1, const char *s2)
{
    char* IniS2 = (char*)s2;//Le asigno la direccion inicial de s2
    size_t cont = 0;
    while(*s1)//Mientras no termine s1
    {
        while(*s2 && ESLETRA(*s1))//Mientras no termine s2 y s1 apunte a una letra
        {
            if(*s1 == *s2)//Si hay match
            {
                cont++;//incremento contados porque hubo match
                s1++;//Incremento s1
                s2 = IniS2;//Vuelvo a posicionar a s2 al principio
            }

            else//Si no hay match tengo que seguir omparando el caracter de s1 con los demas caractes de s2
            {
                s2++;
            }
        }//sale cuando termina s2 y no hubo coincidencia

        s2 = IniS2;//Si termino s2 tengo que posicionarlo al principio para poder seguir comparando
        s1++;//Si

    }//Si sale de aca es porque se termino s1

    return cont;
}

///////////////////////////////////////////////////////////////
void* m_memchr(const void *cad, int c, size_t n)
{
    unsigned char c1 = (unsigned char)c;
    int i;
    int tam = m_strlen(cad);//Mido la cadena
    void* pCad = malloc(tam*sizeof(unsigned char));
    if(!pCad)
    {
        printf("\nNo se pudo crear pCad");
        return NULL;
    }

    pCad = (void*)cad;//Apunto el puntero al inicio de cad
    for(i = 0; i < n; i++)//Como me dice en cuantos caracteres debo buscar al caracter, lo puedo hacer en un for
    {
        if(cmp_char(pCad,&c1) == 0)//Si el caracter en pcad es igual al que busco
        {
            return pCad;//Devuelvo la direc de pCad
        }
        else//Si el caracter no es igual
        {
            pCad += sizeof(unsigned char);//Incremento hacia el proximo elemento de pcad
        }
    }//Si sale del for significa que no lo encontro

    return NULL;//Retorno puntero nulo
}
///////////////////////////////////////////////////////////////
int m_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *c1 = (unsigned char*)s1;
    unsigned char *c2 = (unsigned char*)s2;
    int cmp, i = 0;

    cmp = cmp_char(c1,c2);//Comparo el primer caracter de c1 con el primero de c2
    while((i < n - 1) && (cmp == 0))//Si i es menor a n - 1(caracteres a comparar -1 porque ya hicimos una comparacion afuera del ciclo) y los caracteres son iguales(no hay uno amyor que el otro)
    {
        c1++;//Incremento c1 para que apunte al siguiente elemento, puedo hacer ++ porque es un puntero char
        c2++;//Incremento c1 para que apunte al siguiente elemento, puedo hacer ++ porque es un puntero char
        cmp = cmp_char(c1,c2);//Vuelvo a comparar lo que hay en c1 con lo que hay en c2
        i++;
    }//Si sale es porque ya comparo todos los caracteres o porque cmp != 0

    return (cmp_char(c1,c2));
}

///////////////////////////////////////////////////////////////
void* m_memcpy(void *s1, const void *s2, size_t n)
{
    int i;
    char* c1 = s1;//Apunto c1 a la direccion de s1
    char* c2 = (char*)s2;//Apunto c2 a la direccion de s2

    for(i = 0; i < n; i++)//Hago ciclo por la cant de caracteres a escribir
    {
        *c1 = *c2;//Escribo en el contenido de c1(s1) el contenido de c2(s2)
        c1++;//Incremento c1 (Lo puedo hacer con ++ porque es char)
        c2++;//Incremento c1 (Lo puedo hacer con ++ porque es char)
    }
    return s1;
}
///////////////////////////////////////////////////////////////
void* m_memmove(void *s1, const void *s2, size_t n)
{
    int i;
    char* cad = malloc(m_strlen(s1));//Creo cad con el tamaño de s1
    char* cadIni = cad;//Apunta a la direccion inicial de cad
    char* c1 = s1;
    char* c2 = (char*)s2;
    for(i = 0; i < (m_strlen(s2)); i++)//Recorre la cantidad de caracteres de s1
    {
        *cad = *c2;//Pongo en cad lo que hay en c1
        cad++;
        c2++;
    }//Cuando sale tengo en cad lo que tenia en s2(que es lo que quiero copiar)

    cad = cadIni;

    for(i = 0; i < n; i++)
    {
        *c1 = *cad;//Pongo en c1 lo que hay en cad;
        c1++;
        cad++;
    }
    return s1;
}

///////////////////////////////////////////////////////////////
void* m_memset(void *s, int c, size_t n)
{
    int i;
    unsigned char c1 = (unsigned char)c;//Convierto a c en un unsigned char y lo llamo c1
    char* s1 = s;//Apunto s1 al comienzo de s

    for(i = 0; i < n; i++)//Itera la cantidad de caracteres indicado (n)
    {
        m_memcpy(s,&c1,1);//Pongo en s lo que hay en c1
        s += sizeof(unsigned char);//Incremento s;
    }

    return s1;//Retorno s1(Que seria s)
}
///////////////////////////////////////////////////////////////
size_t m_strcspn(const char *s1, const char *s2)//Esta diferencia entre mayusculas y minusculas
{
    char* IniS2 = (char*)s2;//Le asigno la direccion de inicio de s2
    size_t cant = 0;
    while(*s1)//Mientras no llegue al fin de la cadena s1
    {
        while(*s2)//Mientras no llegue al fin de la cadena s2
        {
            if(*s1 == *s2)//Si el caracter de s1 es diferente al caracter de s2
            {
                return cant;//Si el caracter es igual, termina la funcion
            }
            s2++;//Incremento s2
        }//Si sale de aca significa que el caracter de s1 no es ninguno de los caracteres de s2

        cant++;//Increment
        s2 = IniS2;//Posiciono a s2 al principio de la cadena otra vez
        s1++;//Incremento s1

    }
    return cant;
}
///////////////////////////////////////////////////////////////
size_t m_strcspn_sensitive(const char *s1, const char *s2)//Esta no diferencia entre mayusculas y minusculas
{
    char* IniS2 = (char*)s2;//Le asigno la direccion de inicio de s2
    char c1, c2;
    size_t cant = 0;
    while(*s1)//Mientras no llegue al fin de la cadena s1
    {
        while(*s2)//Mientras no llegue al fin de la cadena s2
        {
            c1 = AMAYUS(*s1);
            c2 = AMAYUS(*s2);

            if(c1 == c2)//Si el caracter de s1 es diferente al caracter de s2
            {
                return cant;//Si el caracter es igual, termina la funcion
            }
            s2++;//Incremento s2
        }//Si sale de aca significa que el caracter de s1 no es ninguno de los caracteres de s2

        cant++;//Increment
        s2 = IniS2;//Posiciono a s2 al principio de la cadena otra vez
        s1++;//Incremento s1

    }
    return cant;
}
///////////////////////////////////////////////////////////////
int cmp_char(const void* a, const void* b)
{
    char* a1 = (char*)a;
    char* b1 = (char*)b;
    return (*a1 - *b1);
}
///////////////////////////////////////////////////////////////
char* copiacadena(const char* cad)
{
    int cant = m_strlen(cad);
    int cont = 0;
    char* cad2 = malloc(sizeof(char) * cant);
    if(!cad2)
    {
        printf("\nNo hay memoria");
        return '\0';
    }
    char* pi = (char*)cad;
    char* pf = (char*)cad + cant - 1;
    while(pi <= pf)
    {
        *cad2 = *cad;
        cad++;
        cad2++;
        cont++;
        pi++;
    }
    return (cad2 - cont);
}
///////////////////////////////////////////////////////////////
size_t proxpal(char* cad)
{
    size_t cont = 0;
    while(*cad)
    {
        while(!ESLETRA(*cad))
        {
            cad++;
        }


        while(ESLETRA(*cad))
        {
            cont++;
            cad++;
        }
        return cont;
    }
    return 0;
}
///////////////////////////////////////////////////////////////
size_t CantReps(char* cad, char* bus)
{
    size_t cont = 0;

    char* BusIni = bus;

    while(*cad)
    {

        if(AMAYUS(*cad) != AMAYUS(*bus))
        {
            cad++;
        }

        if(AMAYUS(*cad) == AMAYUS(*bus))
        {
            while(AMAYUS(*bus) == AMAYUS(*cad) && *cad )
            {
                cad++;
                bus++;
            }
            if(*bus == '\0')
            {
                cont++;
            }
            bus = BusIni;
        }
    }
    return cont;
}
///////////////////////////////////////////////////////////////
char* Desofuscar(char* cad, char* grupo)
{
    size_t TamGrupo = m_strlen(grupo);
    char* GrupoIni = grupo;
    char* CadIni = cad;
    size_t cant_c, desplazamiento;
    int i;
    while(*cad)
    {
        cant_c = proxpal(cad);
        while(!ESLETRA(*cad))
        {
            cad++;
        }

        for(i = 0; i < cant_c; i++)
        {
            while(*grupo && (AMAYUS(*grupo) != AMAYUS(*cad)))
            {
                grupo++;

            }
            //grupo = GrupoIni;

            if(AMAYUS(*cad) == AMAYUS(*grupo))
            {
                desplazamiento = (grupo - GrupoIni + i + 1)%TamGrupo;

                *cad = *(GrupoIni + desplazamiento);
            }
            cad++;
            grupo = GrupoIni;
        }


    }
    return CadIni;
}



























void Abuelo()
{
    char cad[] = "Abuelo";
    char cad2[m_strlen(cad)];
    m_strcpy(cad2,cad);
    char grupo[] = "adbuecrflojnqits";

    printf("\nLa frase desofuscada es: %s %s te extranio",cad2, Desofuscar(cad, grupo));
}
