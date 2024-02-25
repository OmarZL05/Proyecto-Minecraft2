#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PtsxHierro 1
#define PtsxOro 10
#define PtsxDiamante 25
#define CantPartidos 6

struct Moch{
    char NombreObj[50];
    char TipoObj[50];
};

struct Jugadores{
    char NombreMc[50];
    char NombreR[50];
    int Exp;
    struct Moch Mochila[3];
};

struct Alianzas{
    char Nombre[50];
    int PuntosFa;
    int PuntosEn;
    int Esmeraldas;
    struct Jugadores Integrantes[8];

};

int main(){
    struct Alianzas Alianza[4];
    int ContPro=0;
    int ContNoob=0;
    int h=0,i,j,k,l=0,n=0;
    int ObjDiamante=0;
    char JugadoresPicoDiamante[32][20];
    int Comprobante=0;


    for(i=0;i<2;i++){
        printf("Indique el nombre del equipo %i \n", i+1);
        fgets(Alianza[i].Nombre, 50, stdin);
        fflush(stdin);
        for(j=0;j<2;j++){
            printf("Indique el nombre de minecraft del jugador %i del equipo %i\n",j+1, i+1);
            fgets(Alianza[i].Integrantes[j].NombreMc, 50, stdin);
            fflush(stdin);
            printf("Indique su nombre real o el nombre de las redes del jugador %i del equipo %i\n",j+1, i+1);
            fgets(Alianza[i].Integrantes[j].NombreR, 50, stdin);
            fflush(stdin);
            printf("Indique el nivel de experiencia jugador %i del equipo %i\n",j+1, i+1);
            printf("pulse 0 si es Noob y 1 si es Pro\n");
            scanf("%i", &Alianza[i].Integrantes[j].Exp);
            fflush(stdin);
            if(Alianza[i].Integrantes[j].Exp==1){
                ContPro++;
            }
            if(Alianza[i].Integrantes[j].Exp==0){
                ContNoob++;
            }
            for(k=0;k<3;k++){
                printf("Indique el objeto %i\n",k+1);
                printf("Solo puede tener 3 objetos que son de recoleccion, pico, pala y hacha\n");
                scanf("%s",Alianza[i].Integrantes[j].Mochila[k].NombreObj);
                fflush(stdin);
                l=0;
                while(Alianza[i].Integrantes[j].Mochila[k].NombreObj[l]!='\0'){
                    Alianza[i].Integrantes[j].Mochila[k].NombreObj[l]= tolower(Alianza[i].Integrantes[j].Mochila[k].NombreObj[l]);
                    l++;
                }
                do{
                if(strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"pico")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"pala")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"hacha")!=0){
                    printf("su respuesta es invalida, prueve nuevamente\n");
                    scanf("%s",Alianza[i].Integrantes[j].Mochila[k].NombreObj);
                    fflush(stdin);
                }
                }while(strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"pico")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"pala")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"hacha")!=0);
                printf("De que material va a ser su %s?\n",Alianza[i].Integrantes[j].Mochila[k].NombreObj);
                printf("Madera,Piedra,Oro,Hierro o Diamante?\n");
                scanf("%s",Alianza[i].Integrantes[j].Mochila[k].TipoObj);
                fflush(stdin);

                l=0;
                while(Alianza[i].Integrantes[j].Mochila[k].TipoObj[l]!='\0'){
                    Alianza[i].Integrantes[j].Mochila[k].TipoObj[l]= tolower(Alianza[i].Integrantes[j].Mochila[k].TipoObj[l]);
                    l++;
                }
                do{
                if(strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"madera")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"piedra")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"oro")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"hierro")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"diamante")!=0){
                    printf("su respuesta es invalida, prueve nuevamente\n");
                    scanf("%s",Alianza[i].Integrantes[j].Mochila[k].TipoObj);
                    fflush(stdin);
                }
                }while(strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"madera")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"piedra")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"oro")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"hierro")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"diamante")!=0);
                if(strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"diamante")==0){
                    ObjDiamante++;
                    fflush(stdin);
                }
                strcat(Alianza[i].Integrantes[j].Mochila[k].NombreObj," de ");
                strcat(Alianza[i].Integrantes[j].Mochila[k].NombreObj,Alianza[i].Integrantes[j].Mochila[k].TipoObj);
                while(Comprobante==0){
                    if(strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"pico de diamante")==0){
                        strcpy(JugadoresPicoDiamante[n],Alianza[i].Integrantes[j].NombreMc);
                        n++;
                        Comprobante++;
                        fflush(stdin);
                    }
                }

            }
            Comprobante=0;//este comprobante es para evitar que si el usuario coloca mas de un pico de diamante, aparezca su nombre mas de una vez
        }
    
    }


    return 0;
}#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PtsxHierro 1
#define PtsxOro 10
#define PtsxDiamante 25
#define CantPartidos 6

struct Moch{
    char NombreObj[50];
    char TipoObj[50];
};

struct Jugadores{
    char NombreMc[50];
    char NombreR[50];
    int Exp;
    struct Moch Mochila[3];
};

struct Alianzas{
    char Nombre[50];
    int PuntosFa;
    int PuntosEn;
    int Esmeraldas;
    struct Jugadores Integrantes[8];

};

int main(){
    struct Alianzas Alianza[4];
    int ContPro=0;
    int ContNoob=0;
    int h=0,i,j,k,l=0,n=0;
    int ObjDiamante=0;
    char JugadoresPicoDiamante[32][20];
    int Comprobante=0;


    for(i=0;i<2;i++){
        printf("Indique el nombre del equipo %i \n", i+1);
        fgets(Alianza[i].Nombre, 50, stdin);
        fflush(stdin);
        for(j=0;j<2;j++){
            printf("Indique el nombre de minecraft del jugador %i del equipo %i\n",j+1, i+1);
            fgets(Alianza[i].Integrantes[j].NombreMc, 50, stdin);
            fflush(stdin);
            printf("Indique su nombre real o el nombre de las redes del jugador %i del equipo %i\n",j+1, i+1);
            fgets(Alianza[i].Integrantes[j].NombreR, 50, stdin);
            fflush(stdin);
            printf("Indique el nivel de experiencia jugador %i del equipo %i\n",j+1, i+1);
            printf("pulse 0 si es Noob y 1 si es Pro\n");
            scanf("%i", &Alianza[i].Integrantes[j].Exp);
            fflush(stdin);
            if(Alianza[i].Integrantes[j].Exp==1){
                ContPro++;
            }
            if(Alianza[i].Integrantes[j].Exp==0){
                ContNoob++;
            }
            for(k=0;k<3;k++){
                printf("Indique el objeto %i\n",k+1);
                printf("Solo puede tener 3 objetos que son de recoleccion, pico, pala y hacha\n");
                scanf("%s",Alianza[i].Integrantes[j].Mochila[k].NombreObj);
                fflush(stdin);
                l=0;
                while(Alianza[i].Integrantes[j].Mochila[k].NombreObj[l]!='\0'){
                    Alianza[i].Integrantes[j].Mochila[k].NombreObj[l]= tolower(Alianza[i].Integrantes[j].Mochila[k].NombreObj[l]);
                    l++;
                }
                do{
                if(strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"pico")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"pala")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"hacha")!=0){
                    printf("su respuesta es invalida, prueve nuevamente\n");
                    scanf("%s",Alianza[i].Integrantes[j].Mochila[k].NombreObj);
                    fflush(stdin);
                }
                }while(strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"pico")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"pala")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"hacha")!=0);
                printf("De que material va a ser su %s?\n",Alianza[i].Integrantes[j].Mochila[k].NombreObj);
                printf("Madera,Piedra,Oro,Hierro o Diamante?\n");
                scanf("%s",Alianza[i].Integrantes[j].Mochila[k].TipoObj);
                fflush(stdin);

                l=0;
                while(Alianza[i].Integrantes[j].Mochila[k].TipoObj[l]!='\0'){
                    Alianza[i].Integrantes[j].Mochila[k].TipoObj[l]= tolower(Alianza[i].Integrantes[j].Mochila[k].TipoObj[l]);
                    l++;
                }
                do{
                if(strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"madera")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"piedra")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"oro")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"hierro")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"diamante")!=0){
                    printf("su respuesta es invalida, prueve nuevamente\n");
                    scanf("%s",Alianza[i].Integrantes[j].Mochila[k].TipoObj);
                    fflush(stdin);
                }
                }while(strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"madera")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"piedra")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"oro")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"hierro")!=0 && strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"diamante")!=0);
                if(strcmp(Alianza[i].Integrantes[j].Mochila[k].TipoObj,"diamante")==0){
                    ObjDiamante++;
                    fflush(stdin);
                }
                strcat(Alianza[i].Integrantes[j].Mochila[k].NombreObj," de ");
                strcat(Alianza[i].Integrantes[j].Mochila[k].NombreObj,Alianza[i].Integrantes[j].Mochila[k].TipoObj);
                while(Comprobante==0){
                    if(strcmp(Alianza[i].Integrantes[j].Mochila[k].NombreObj,"pico de diamante")==0){
                        strcpy(JugadoresPicoDiamante[n],Alianza[i].Integrantes[j].NombreMc);
                        n++;
                        Comprobante++;
                        fflush(stdin);
                    }
                }

            }
            Comprobante=0;//este comprobante es para evitar que si el usuario coloca mas de un pico de diamante, aparezca su nombre mas de una vez
        }
    
    }


    return 0;
}
