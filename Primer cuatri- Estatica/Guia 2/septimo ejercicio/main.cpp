#include <iostream>

using namespace std;

int main()
{
    int numeroEquipos=0;
    int codigoEq=0;
    char respuesta;
    cout << "Ingrese el numero de equipos: ";
    cin >> numeroEquipos;


    for (int equipo = 0; equipo < numeroEquipos; equipo++) {
        int puntos = 0;
        cout << "Ingrese el codigo del equipo "<<equipo<<" -> ";
        cin >> codigoEq;
        cout << "Completar partidos para el equipo: " << codigoEq <<  endl;
        for (int partido = 0; partido < numeroEquipos - 1 ; partido++)
        {
            cout << "Partido: " << partido << endl;
            cout << "Elija un resultado: 'P' = perdido, 'E' = empatado, 'G'= ganado " << endl;
            cout << "Su respuesta: ";
            cin >> respuesta;
            switch (respuesta) {

            case 'G':
                cout << "Victoria suma 3 puntos" << endl;
                puntos = puntos + 3;
                cout << "Llevamos un total de " << puntos << " puntos." << endl;
                break;
            case 'E':

                cout << "Empate suma 1 punto" << endl;
                puntos = puntos + 1;
                cout << "Llevamos un total de " << puntos << " puntos." << endl;
                break;
            case 'P':
                cout << "Derrota no suma puntos" << endl;
                cout << "Llevamos un total de " << puntos << " puntos." << endl;
                break;
            }
        }
        cout << "#######################################################################################" << endl;
        cout << "La carga del equipo ha finalizado, su total es de " << puntos << " puntos." << endl;
        cout << "#######################################################################################" << endl;
    }


    return 0;
}
