#include <iostream>
using namespace std;

struct slot
{
    string nombre;
    string tipo;
};

struct jugador
{
    string nickname;
    string nombre;
    string experienza;
    slot mochila[3];
};

struct alianza
{
    string name;
    int puntosAFavor;
    int puntosEnContra;
    int esmeraldas;
    jugador jugadores[8];
};

void registrarJugador(jugador &jug) {
    int op;
    cout << "Indique el nombre: ";
    getline(cin >> ws, jug.nombre);
    cout << "Indique el nickname en minecraft: ";
    cin >> jug.nickname;
    cout << "Elija su nivel de experiencia [1 = Pro] [2 = Noob]: ";
    do {
        cin >> op;
        switch (op) {
            case 1:
                jug.experienza = "pro";
                break;
            case 2:
                jug.experienza = "noob";
                break;
            default:
                cout << "Escoja una de las opciones indicadas.";
        }
    } while(op < 1 || op > 2);

}

void registrarJugadores(alianza ali) {
    jugador jugadores[8];
    char op = 's';
    int i=0;
    cout << "Registre a continuacion los integrantes de su equipo" << endl;
    cout << "Nota: El maximo de jugadores es 8" << endl;
    while(op == 's' && i<=8) {
        cout << "Ingrese los datos del jugador " << i+1 << endl;
        registrarJugador(jugadores[i]);
        cout << "¿Desea registrar otro integrante? [s = Si] [s <> No]: ";
        cin >> op;
        i++;
    }

}

void registrarAlianza(alianza ali) {
    cout << "Indique el nombre de la alianza: ";
    cin >> ali.name;
    registrarJugadores(ali);

}

void registrarAlianzas(alianza alianzas[]) {
    for(int i=0;i<4;i++) {
        cout << "\nBienvenido, estás a punto de registrar la alianza N." << i+1 << endl;
        registrarAlianza(alianzas[i]);
    }
}

int main() {
    alianza alianzas[4];

    registrarAlianzas(alianzas);

}
