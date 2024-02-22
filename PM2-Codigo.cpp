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
    string realname;
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

void test(alianza ali) {
    if(ali.name.length() < 4) {
        cout << "Tu alianza es la N1, indica su nombre: ";
        cin >> ali.name;
    }
    cout << ali.name << endl;
}

int main() {
    alianza alianzas[4];

    cout << "hola" << endl;
}
