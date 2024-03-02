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

void registrarJugador(jugador &jug)
{
    int op;
    cout << "Indique el nombre: ";
    getline(cin >> ws, jug.nombre);
    cout << "Indique el nickname en minecraft: ";
    cin >> jug.nickname;
    cout << "Elija su nivel de experiencia [1: pro] [2: noob]" << endl;
    do
    {
        cin >> op;
        switch (op)
        {
        case 1:
            jug.experiencia = "pro";
            break;
        case 2:
            jug.experiencia = "noob";
            break;
        default:
            cout << "Escoja una de las opciones indicadas.";
        }
    } while (op < 1 || op > 2);
    cout << "Puedes llevar 3 items en tu mochila." << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Tienes " << 3 - i << " slots libres." << endl;
        cout << "Indique el item. [pico] [pala] [hacha]" << endl;
        cin >> jug.mochila[i].nombre;
        cout << "Indique el material del item. [madera] [piedra] [oro] [hierro] "
                "[diamante]"
             << endl;
        cin >> jug.mochila[i].tipo;
    }
}

void registrarJugadores(alianza &ali)
{
    char op = 's';
    int i = 0;
    cout << "Registre a continuacion los integrantes de su equipo" << endl;
    cout << "Nota: El maximo de jugadores es 8" << endl;
    while (op == 's' && i < 8)
    {
        cout << "Ingrese los datos del jugador " << i + 1 << endl;
        registrarJugador(ali.jugadores[i]);
        ali.registrosConcretados++;
        if (i < 7)
        {
            cout << "¿Desea registrar otro integrante? [s:si] [otro:no]: ";
            cin >> op;
        }
        i++;
    }
}

void registrarAlianza(alianza &ali)
{
    cout << "Indique el nombre de la alianza: ";
    cin >> ali.nombre;
    ali.esmeraldas = 0;
    ali.puntosAFavor = 0;
    ali.puntosEnContra = 0;
    registrarJugadores(ali);
}


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
    for (int i = 0; i < 4; i++)
    {
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

void mostrarEquipoGanador(alianza equipo, bool final)
{
    cout << "\nGanador: " << equipo.nombre << endl;
    if (final == true)
    {
        cout << "Integrantes: " << endl;
        for (int i = 0; i < equipo.registrosConcretados; i++)
        {
            cout << equipo.jugadores[i].nombre << " ";
        }
        cout << "\nPuntos a favor: " << equipo.puntosAFavor << endl;
        cout << "Puntos en contra: " << equipo.puntosEnContra << endl;
        cout << "Average de puntos: " << (equipo.puntosAFavor - equipo.puntosEnContra) << endl;
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

    cout << "Ronda final"
         << ": " << equipo1.nombre << " vs " << equipo2.nombre << endl;
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
        if (op == 's')
        {
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
        }
        else
        {
            cout << "El PvP fue activo, el equipo con más jugadores ganará" << endl;
            cout << "¿cuantos sobrevivieron " << equipo1.nombre << "?: ";
            cin >> sobrev1;
            cout << "¿cuantos sobrevivieron " << equipo2.nombre << "?: ";
            cin >> sobrev2;
            if (sobrev1 > sobrev2)
            {
                mostrarEquipoGanador(equipo1, true);
            }
            else
            {
                mostrarEquipoGanador(equipo2, true);
            }

            cout << "Sobrevivientes " << equipo1.nombre << ": " << sobrev1 << endl;
            cout << "Sobrevivientes " << equipo2.nombre << ": " << sobrev2 << endl;
        }
    }
    else
    {
        cout << "Sobrevivientes " << equipo1.nombre << ": " << equipo1.registrosConcretados << endl;
        cout << "Sobrevivientes " << equipo2.nombre << ": " << equipo2.registrosConcretados << endl;
    }
    cout << endl;
}

int posicionIntegrante(alianza ali, string nombre) {
    for(int i=0;i<ali.registrosConcretados;i++) {
        if(ali.jugadores[i].nickname == nombre) {
            return i;
        }
    }
    return -1;
}

void mostrarPosicionTop(alianza alianzas[4]) {
    string nombre;
    int i, pos;
    i = 0;
    pos = -1;

    cout << "Indica un nombre de minecraft para buscar su posicion: ";
    cin >> nombre;

    while(pos == -1 && i < 4) {
        pos = posicionIntegrante(alianzas[i], nombre);
        if(pos > -1) {
            cout << "El jugador " << alianzas[i].jugadores[pos].nickname << " quedo en el top " << i << endl;
        }
        i++;
    }

    if(pos == -1) {
        cout << "No se ha encontrado al jugador" << endl;
    }

}

int main()
{
    // Variables
    alianza alianzas[4];

    for (int i = 0; i < 4; i++)
    {
        cout << "\nBienvenido, estás a punto de registrar la alianza N." << i + 1
             << endl;
        registrarAlianza(alianzas[i]);
    }

    preTorneo(alianzas);

    iniciarRonda(alianzas[0], alianzas[1], 1);
    iniciarRonda(alianzas[0], alianzas[2], 2);
    iniciarRonda(alianzas[0], alianzas[3], 3);
    iniciarRonda(alianzas[1], alianzas[2], 4);
    iniciarRonda(alianzas[1], alianzas[3], 5);
    iniciarRonda(alianzas[2], alianzas[3], 6);

    alianza top[4];
    alianza aux;

    for (int i = 0; i < 4; i++)
    {
        top[i] = alianzas[i];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (top[j].esmeraldas < top[j + 1].esmeraldas)
            {
                aux = top[j];
                top[j] = top[j + 1];
                top[j + 1] = aux;
            }
            else
            {
                if (top[j].esmeraldas == top[j + 1].esmeraldas)
                {
                    if ((top[j].puntosAFavor - top[j].puntosEnContra) < (top[j + 1].puntosAFavor - top[j + 1].puntosEnContra))
                    {
                        aux = top[j];
                        top[j] = top[j + 1];
                        top[j + 1] = aux;
                    }
                }
            }
        }
    }

    rondaFinal(top[0], top[1]);

    mostrarPosicionTop(top);


}
