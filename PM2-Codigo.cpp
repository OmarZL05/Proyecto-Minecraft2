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
    string experienza;
    slot mochila[3];
};

struct alianza
{
    string nombre;
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

void registrarJugadores(alianza &ali) {
    char op = 's';
    int i=0;
    cout << "Registre a continuacion los integrantes de su equipo" << endl;
    cout << "Nota: El maximo de jugadores es 8" << endl;
    while(op == 's' && i<8) {
        cout << "Ingrese los datos del jugador " << i+1 << endl;
        registrarJugador(ali.jugadores[i]);
        cout << "¿Desea registrar otro integrante? [s = Si] [s <> No]: ";
        cin >> op;
        i++;
    }

}

void registrarAlianza(alianza &ali) {
    cout << "Indique el nombre de la alianza: ";
    cin >> ali.nombre;
    registrarJugadores(ali);

}

void registrarAlianzas(alianza alianzas[]) {
    for(int i=0;i<4;i++) {
        cout << "\nBienvenido, estás a punto de registrar la alianza N." << i+1 << endl;
        registrarAlianza(alianzas[i]);
    }
}

int equipoMinar(string equipo) {
    cout << "Indica la cantidad de menas minadas equipo " << equipo << ".";
    int cantDiamantes, cantOro, cantHierro;
    cout << "Menas de diamantes minadas: ";
    cin >> cantDiamantes;
    cout << "Menas de hierro minadas: ";
    cin >> cantHierro;
    cout << "Menas de oro minadas: ";
    cin >> cantHierro;

    return cantDiamantes*25 + cantOro*10 + cantHierro;

}

void iniciarRonda(alianza &equipo1, alianza &equipo2, bool rondaFinal) {
    int ptsEquipo1, ptsEquipo2;
    bool op;

    ptsEquipo1 = equipoMinar(equipo1.nombre);
    ptsEquipo2 = equipoMinar(equipo2.nombre);

    equipo1.puntosAFavor += ptsEquipo1;
    equipo1.puntosEnContra += ptsEquipo2;
    
    equipo2.puntosAFavor += ptsEquipo2;
    equipo2.puntosEnContra += ptsEquipo1;

    if(ptsEquipo1 > ptsEquipo2) {
        // equipo1 gano
        equipo1.esmeraldas += 3;
        
    }

    if(ptsEquipo1 < ptsEquipo2) {
        // equipo2 gano
        equipo2.esmeraldas += 3;
    }
 
    if(ptsEquipo1 == ptsEquipo2) {
        // empataron
        if(rondaFinal == true) {
            
        } else {
            equipo1.esmeraldas++;
            equipo2.esmeraldas++;
        }
    }
    
}

void clasificacion() {
    /* 
        [1, 2] 
        [3, 4]
        
        [1, 3]
        [1, 4]
        [2, 3]
        [2, 4]
        
    */
}

int main() {
    // Variables
    alianza alianzas[4];

    registrarAlianzas(alianzas);

}
