#include <iostream>

using namespace std;

int main()
{

int cantEquipos;
int cantPartidos;
string codEq;
char codRe;
int sumaG = 0;
int sumaP = 0;



cout << "Ingrese el numero de equipos: ";
cin >> cantEquipos;


cantPartidos = cantEquipos - 1;


if (cantEquipos >= 2){

for (int i = 0; i < cantEquipos; i++){

cout << " " << endl;
cout << "Equipo numero: " << i+1 << endl;
cout << "Codigo de equipo: ";
cin >> codEq;


    for (int i = 0; i < cantPartidos; i++){

        cout << "Partido " << i+1 << ": ";
        cin >> codRe;

        if (codRe == 'G'){

            sumaG = sumaG + 3;

                                }

        if (codRe == 'P'){

            sumaP = sumaP + 3; }


        if (codRe == 'E'){

            sumaG = sumaG + 1;
            sumaP = sumaP + 1;

        }



                                            }

 cout << "Codigo de equipo " << i+1 << ": " << codEq << endl;
 cout << "Puntos a favor: " << sumaG << endl;
 cout << "Puntos en contra: " << sumaP << endl;

sumaG = 0;
sumaP = 0;

                                        }

}else ( cout << "Error, la cantidad de equipos tiene que ser mayor o igual a 2");





    return 0;
}
