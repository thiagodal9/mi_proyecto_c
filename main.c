
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "cadenas.h"

int main()
{
    char s1[] = "Hola a todos";
    char s2[] = "H";
    printf( "s1=%s\n", s1 );
    printf( "s2=%s\n", s2 );
    printf( "strstr(s1,s2) = %s\n", m_strstr( s1, s2 ) );
    return 0;
}
