#include <iostream>

using namespace std;

/* SI QUIERO CREAR UN ACUMULADOR ES DEL TIPO: VARIABLE = VARIABLE + X. DEPENDIENDO LA OPERACION */

int main()
{

int numeros;
int promedio = 0;
int cantidadNumeros = 0;
int sumaNumerosMenor10 = 0;
int sumaNumerosMayor100 = 0;

for (int i = 0; i < 5; i++){

    cout << "Numeros: ";
    cin >> numeros;


    if (numeros > 100){

        cantidadNumeros++;

        sumaNumerosMayor100 = sumaNumerosMayor100 + numeros; // sumaNumerosMayor100 es un acumulador de suma


    }

    if (numeros < -10){

        sumaNumerosMenor10 = sumaNumerosMenor10 + numeros;


    }



}

cout << (sumaNumerosMayor100/cantidadNumeros) << endl;

cout << sumaNumerosMenor10 << endl;







    return 0;
}
