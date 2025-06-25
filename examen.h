#ifndef EXAMEN_H
#define EXAMEN_H

#define TAM_NOMAPELLIDO 50

typedef struct {
    int dni;
    char nombre[TAM_NOMAPELLIDO];
    char apellido[TAM_NOMAPELLIDO];
    float promedio;
} tEstudiante;

int crearLoteEstudiantesDefault(const char* nomArchivoEstudiantes);
int comEstDNI(const void* a, const void* b);
int fbbinaria(void *clave, const char* nomarch, size_t tam, int cmp(const void *, const void *));
int fbbinariaALU(void *clave, const char* nomarch, size_t tam, int cmp(const void *, const void *));

#endif // EXAMEN_H
