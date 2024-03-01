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
    
    cout << "\nNoobs registrados: " << totalNoobs;
    cout << "Pros registrados: " << totalPros;
    cout << "Cantidad de objetos de Diamante: " << totalItemsDiamante; 
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

void iniciarRonda(alianza &equipo1, alianza &equipo2)
{
    int ptsEquipo1, ptsEquipo2;
    char op;

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
    }

    if (ptsEquipo1 < ptsEquipo2)
    {
        // equipo2 gano
        equipo2.esmeraldas += 3;
    }

    if (ptsEquipo1 == ptsEquipo2)
    {
        equipo1.esmeraldas++;
        equipo2.esmeraldas++;
    }
}

void postTorneo()
{
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

    iniciarRonda(alianzas[0], alianzas[1]);
    iniciarRonda(alianzas[0], alianzas[2]);
    iniciarRonda(alianzas[0], alianzas[3]);
    iniciarRonda(alianzas[1], alianzas[2]);
    iniciarRonda(alianzas[1], alianzas[3]);
    iniciarRonda(alianzas[2], alianzas[3]);

    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << alianzas[i].nombre << endl;
        cout << alianzas[i].esmeraldas << endl;
        cout << alianzas[i].puntosAFavor << endl;
        cout << alianzas[i].puntosEnContra << endl;
    }
}
