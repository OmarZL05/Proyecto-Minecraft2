#include <stdio.h>
#include <string.h>

struct cartera {
    int dinero;
};

struct persona {
    int edad;
    struct cartera carteras[2];
};

struct persona llenarDatos(struct persona pepe) {
    printf("Cuantos años tienes\n");
    scanf("%i", &pepe.edad);
    return pepe;
}

int main() {
    struct persona personas[2];
    for(int i=0;i<2;i++) {
        personas[i] = llenarDatos(personas[i]);
    }
    printf("edad: %i\n", personas[0].edad);
}