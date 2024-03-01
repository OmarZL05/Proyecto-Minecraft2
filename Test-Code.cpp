#include <iostream>
using namespace std;

// Registros
struct slot
{
    string nombre;
    string tipo;
};

struct jugador
{
    string nickname;
    string nombre;
    string experiencia;
    slot mochila[3];
};

struct alianza
{
    string nombre;
    int puntosAFavor;
    int puntosEnContra;
    int esmeraldas;
    jugador jugadores[8];
    int registrosConcretados;
};

int noobsEquipo(alianza ali)
{
    int cantNoobs = 0;
    int max = ali.registrosConcretados;
    for (int i = 0; i < max; i++)
    {
        if (ali.jugadores[i].experiencia == "noob")
        {
            cantNoobs++;
        }
    }
    return cantNoobs;
}

int prosEquipo(alianza ali)
{
    int cantPros = 0;
    int max = ali.registrosConcretados;
    for (int i = 0; i < 8; i++)
    {
        if (ali.jugadores[i].experiencia == "pro")
        {
            cantPros++;
        }
    }
    return cantPros;
}

int itemsDiamanteEquipo(alianza ali)
{
    int itemsDiamante = 0;
    int max = ali.registrosConcretados;
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ali.jugadores[i].mochila[j].tipo == "diamante")
            {
                itemsDiamante++;
            }
        }
    }
    return itemsDiamante;
}

void mostrarPicosDiamantes(alianza ali)
{
    int max = ali.registrosConcretados;
    int j;
    bool sinPico;
    cout << ali.nombre << ": ";
    for (int i = 0; i < max; i++)
    {
        j=0;
        sinPico = true;
        while(j < 3 && sinPico == true)
        {
            if (ali.jugadores[i].mochila[j].nombre == "pico" && ali.jugadores[i].mochila[j].tipo == "diamante")
            {
                cout << ali.jugadores[i].nombre + " ";
                sinPico = false;
            }
            j++;
        }
    }
    cout << endl;
}

void preTorneo(alianza alianzas[4])
{
    int totalNoobs, totalPros, totalItemsDiamante;
    totalNoobs = 0;
    totalPros = 0;
    totalItemsDiamante = 0;

    for (int i = 0; i < 4; i++)
    {
        totalNoobs += noobsEquipo(alianzas[i]);
        totalPros += prosEquipo(alianzas[i]);
        totalItemsDiamante += itemsDiamanteEquipo(alianzas[i]);
    }
    
    cout << "\nNoobs registrados: " << totalNoobs << endl;
    cout << "Pros registrados: " << totalPros << endl;
    cout << "Cantidad de objetos de Diamante: " << totalItemsDiamante << endl; 
    cout << "Personas con pico de diamante en" << endl;
    for(int i=0;i<4;i++) {
        mostrarPicosDiamantes(alianzas[i]);
    }
}

int equipoMinar(string equipo)
{
    cout << "\nIndica la cantidad de menas minadas, alianza " << equipo << "."
         << endl;
    int cantDiamantes, cantOro, cantHierro;

    cantDiamantes = 0;
    cantOro = 0;
    cantHierro = 0;

    cout << "Menas de diamantes minadas: ";
    cin >> cantDiamantes;
    cout << "Menas de hierro minadas: ";
    cin >> cantHierro;
    cout << "Menas de oro minadas: ";
    cin >> cantOro;

    return (cantDiamantes * 25) + (cantOro * 10) + cantHierro;
}


void mostrarEquipoGanador(alianza equipo, bool final) {
    cout << "Ganador: " << equipo.nombre << endl;
    if(final == true) {
        cout << "Integrantes: " << endl;
        for(int i=0;i<equipo.registrosConcretados;i++) {
            cout << equipo.jugadores[i].nombre << " ";
        }
        cout << endl;
    }
}

void iniciarRonda(alianza &equipo1, alianza &equipo2, int ronda)
{
    int ptsEquipo1, ptsEquipo2;

    cout << "Ronda " << ronda << ": " << equipo1.nombre << " vs " << equipo2.nombre << endl;
    ptsEquipo1 = equipoMinar(equipo1.nombre);
    ptsEquipo2 = equipoMinar(equipo2.nombre);

    equipo1.puntosAFavor += ptsEquipo1;
    equipo1.puntosEnContra += ptsEquipo2;

    equipo2.puntosAFavor += ptsEquipo2;
    equipo2.puntosEnContra += ptsEquipo1;

    if (ptsEquipo1 > ptsEquipo2)
    {
        // equipo1 gano
        equipo1.esmeraldas += 3;
        mostrarEquipoGanador(equipo1, false);
    }

    if (ptsEquipo1 < ptsEquipo2)
    {
        // equipo2 gano
        equipo2.esmeraldas += 3;
        mostrarEquipoGanador(equipo2, false);
    }

    if (ptsEquipo1 == ptsEquipo2)
    {
        equipo1.esmeraldas++;
        equipo2.esmeraldas++;
        cout << "Empate." << endl;
    }
    cout << endl;
}

void rondaFinal(alianza &equipo1, alianza &equipo2)
{
    int ptsEquipo1, ptsEquipo2;
    char op;
    int win = 0;
    int sobrev1, sobrev2;

    cout << "Ronda final" << ": " << equipo1.nombre << " vs " << equipo2.nombre << endl;
    ptsEquipo1 = equipoMinar(equipo1.nombre);
    ptsEquipo2 = equipoMinar(equipo2.nombre);

    equipo1.puntosAFavor += ptsEquipo1;
    equipo1.puntosEnContra += ptsEquipo2;

    equipo2.puntosAFavor += ptsEquipo2;
    equipo2.puntosEnContra += ptsEquipo1;

    if (ptsEquipo1 > ptsEquipo2)
    {
        // equipo1 gano
        equipo1.esmeraldas += 3;
        mostrarEquipoGanador(equipo1, true);
    }

    if (ptsEquipo1 < ptsEquipo2)
    {
        // equipo2 gano
        equipo2.esmeraldas += 3;
        mostrarEquipoGanador(equipo1, true);
    }

    if (ptsEquipo1 == ptsEquipo2)
    {
        cout << "Ha ocurrido un empate. El primero en encontrar un diamante gana." << endl;
        cout << "¿Alguno encontro un diamante? [s:si] [otro:no]: ";
        cin >> op;
        if(op == 's') {
            cout << "Que equipo lo encontro primero. [1:Equipo 1] [2:Equipo 2]: ";
            cin >> win;
            switch (win)
            {
            case 1:
                mostrarEquipoGanador(equipo1, true);
                break;
            case 2:
                mostrarEquipoGanador(equipo2, true);
                break;
            default:
                break;
            }
        } else {
            cout << "El PvP fue activo, el equipo con más jugadores ganará" << endl;
            cout << "¿" << equipo1.nombre << " sobrevivieron ?: ";
            cin >> sobrev1;
            cout << "¿" << equipo2.nombre << " sobrevivieron ?: ";
            cin >> sobrev2;
            if(sobrev1 > sobrev2) {
                mostrarEquipoGanador(equipo1, true);
            } else {
                mostrarEquipoGanador(equipo2, true);
            }
        }
    }
    cout << endl;
}

void postTorneo()
{

}

int main()
{
    // Variables
    alianza alianzas[4];

    alianzas[0].nombre = "Caotic";
    alianzas[0].esmeraldas = 0;
    alianzas[0].puntosAFavor = 0;
    alianzas[0].puntosEnContra = 0;
    alianzas[0].registrosConcretados = 2;
    alianzas[0].jugadores[0].nombre = "Omar";
    alianzas[0].jugadores[0].nickname = "OmarZL";
    alianzas[0].jugadores[0].experiencia = "noob";
    alianzas[0].jugadores[0].mochila[0].nombre = "pico";
    alianzas[0].jugadores[0].mochila[0].tipo = "diamante";
    alianzas[0].jugadores[0].mochila[1].nombre = "pico";
    alianzas[0].jugadores[0].mochila[1].tipo = "diamante";
    alianzas[0].jugadores[0].mochila[2].nombre = "pico";
    alianzas[0].jugadores[0].mochila[2].tipo = "diamante";
    alianzas[0].jugadores[1].nombre = "Cristian";
    alianzas[0].jugadores[1].nickname = "CRii2";
    alianzas[0].jugadores[1].experiencia = "pro";
    alianzas[0].jugadores[1].mochila[0].nombre = "pico";
    alianzas[0].jugadores[1].mochila[0].tipo = "oro";
    alianzas[0].jugadores[1].mochila[1].nombre = "pico";
    alianzas[0].jugadores[1].mochila[1].tipo = "oro";
    alianzas[0].jugadores[1].mochila[2].nombre = "pico";
    alianzas[0].jugadores[1].mochila[2].tipo = "diamante";

    alianzas[1].nombre = "Cyntur";
    alianzas[1].esmeraldas = 0;
    alianzas[1].puntosAFavor = 0;
    alianzas[1].puntosEnContra = 0;
    alianzas[1].registrosConcretados = 2;
    alianzas[1].jugadores[0].nombre = "Arturo";
    alianzas[1].jugadores[0].nickname = "Arrtur";
    alianzas[1].jugadores[0].experiencia = "noob";
    alianzas[1].jugadores[0].mochila[0].nombre = "pico";
    alianzas[1].jugadores[0].mochila[0].tipo = "diamante";
    alianzas[1].jugadores[0].mochila[1].nombre = "pico";
    alianzas[1].jugadores[0].mochila[1].tipo = "diamante";
    alianzas[1].jugadores[0].mochila[2].nombre = "pico";
    alianzas[1].jugadores[0].mochila[2].tipo = "diamante";
    alianzas[1].jugadores[1].nombre = "Victor";
    alianzas[1].jugadores[1].nickname = "Viktor";
    alianzas[1].jugadores[1].experiencia = "pro";
    alianzas[1].jugadores[1].mochila[0].nombre = "pico";
    alianzas[1].jugadores[1].mochila[0].tipo = "oro";
    alianzas[1].jugadores[1].mochila[1].nombre = "pico";
    alianzas[1].jugadores[1].mochila[1].tipo = "oro";
    alianzas[1].jugadores[1].mochila[2].nombre = "pico";
    alianzas[1].jugadores[1].mochila[2].tipo = "diamante";
    
    alianzas[2].nombre = "Tree";
    alianzas[2].esmeraldas = 0;
    alianzas[2].puntosAFavor = 0;
    alianzas[2].puntosEnContra = 0;
    alianzas[2].registrosConcretados = 2;
    alianzas[2].jugadores[0].nombre = "Omar";
    alianzas[2].jugadores[0].nickname = "FerrZL";
    alianzas[2].jugadores[0].experiencia = "noob";
    alianzas[2].jugadores[0].mochila[0].nombre = "pico";
    alianzas[2].jugadores[0].mochila[0].tipo = "diamante";
    alianzas[2].jugadores[0].mochila[1].nombre = "pico";
    alianzas[2].jugadores[0].mochila[1].tipo = "diamante";
    alianzas[2].jugadores[0].mochila[2].nombre = "pico";
    alianzas[2].jugadores[0].mochila[2].tipo = "diamante";
    alianzas[2].jugadores[1].nombre = "Cristian";
    alianzas[2].jugadores[1].nickname = "CRii2";
    alianzas[2].jugadores[1].experiencia = "pro";
    alianzas[2].jugadores[1].mochila[0].nombre = "pico";
    alianzas[2].jugadores[1].mochila[0].tipo = "oro";
    alianzas[2].jugadores[1].mochila[1].nombre = "pico";
    alianzas[2].jugadores[1].mochila[1].tipo = "oro";
    alianzas[2].jugadores[1].mochila[2].nombre = "pico";
    alianzas[2].jugadores[1].mochila[2].tipo = "diamante";

    alianzas[3].nombre = "Anturx";
    alianzas[3].esmeraldas = 0;
    alianzas[3].puntosAFavor = 0;
    alianzas[3].puntosEnContra = 0;
    alianzas[3].registrosConcretados = 2;
    alianzas[3].jugadores[0].nombre = "Alver";
    alianzas[3].jugadores[0].nickname = "Arur";
    alianzas[3].jugadores[0].experiencia = "noob";
    alianzas[3].jugadores[0].mochila[0].nombre = "pico";
    alianzas[3].jugadores[0].mochila[0].tipo = "diamante";
    alianzas[3].jugadores[0].mochila[1].nombre = "pico";
    alianzas[3].jugadores[0].mochila[1].tipo = "diamante";
    alianzas[3].jugadores[0].mochila[2].nombre = "pico";
    alianzas[3].jugadores[0].mochila[2].tipo = "diamante";
    alianzas[3].jugadores[1].nombre = "Jeanpool";
    alianzas[3].jugadores[1].nickname = "jeanpool";
    alianzas[3].jugadores[1].experiencia = "pro";
    alianzas[3].jugadores[1].mochila[0].nombre = "pico";
    alianzas[3].jugadores[1].mochila[0].tipo = "oro";
    alianzas[3].jugadores[1].mochila[1].nombre = "pico";
    alianzas[3].jugadores[1].mochila[1].tipo = "oro";
    alianzas[3].jugadores[1].mochila[2].nombre = "pico";
    alianzas[3].jugadores[1].mochila[2].tipo = "diamante";
    
    preTorneo(alianzas);

    iniciarRonda(alianzas[0], alianzas[1], 1);
    iniciarRonda(alianzas[0], alianzas[2], 2);
    iniciarRonda(alianzas[0], alianzas[3], 3);
    iniciarRonda(alianzas[1], alianzas[2], 4);
    iniciarRonda(alianzas[1], alianzas[3], 5);
    iniciarRonda(alianzas[2], alianzas[3], 6);

    alianza top[4];
    alianza aux;

    for(int i=0;i<4;i++) {
        top[i] = alianzas[i];
    }

    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            if(top[j].esmeraldas < top[j+1].esmeraldas) {
                aux = top[j];
                top[j] = top[j+1];
                top[j+1] = aux;
            }
            else {
                if(top[j].esmeraldas == top[j+1].esmeraldas) {
                    if( (top[j].puntosAFavor - top[j].puntosEnContra) < (top[j+1].puntosAFavor - top[j+1].puntosEnContra) ) {
                        aux = top[j];
                        top[j] = top[j+1];
                        top[j+1] = aux;
                    }
                }
            }
        }
    }

    cout << endl;  
    for (int i = 0; i < 4; i++)
    {
        cout << top[i].nombre << endl;
        cout << "Esm: " << top[i].esmeraldas << endl;
        cout << "Pts: " << top[i].puntosAFavor << " " << top[i].puntosEnContra << endl;
    }
}
