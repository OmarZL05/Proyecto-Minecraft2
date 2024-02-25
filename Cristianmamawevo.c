#include<stdio.h>
#include<string.h>
#include<conio.h>

struct Carteras{
    int Dinero;
};

struct Persona{
    int Edad;
    struct Carteras Cartera[2];
};

struct Persona LlenarDatos(struct Persona personas,int i){
    printf("Cuantos anos tiene?\n");
    scanf("%i",&personas.Edad);
    printf("Cuanto dinero tiene en su cartera %i\n",i+1);
    for(int j=0;j<2;j++){
        scanf("%i",&personas.Cartera[j].Dinero);
    }
    return personas;
}

int main(){
    struct Persona personas[2];
    for(int i=0;i<2;i++){
        personas[i]= LlenarDatos(personas[i],i);
    }

    return 0;
}
