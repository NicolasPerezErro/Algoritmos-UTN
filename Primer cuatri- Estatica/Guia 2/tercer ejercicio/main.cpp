#include <iostream>

using namespace std;

int main()
{

int numeros;
int Max = 0;
int posicion = 0;
int contador = 0; // SOLO SIRVE PARA PONER BIEN LAS POSICIONES Y QUE NO SOLO SE CUENTEN CUANDO ENTRA EN EL IF

cout << "Ingresar Numeros: ";
cin >> numeros;


while (numeros > 0){

if (numeros > Max){

    Max = numeros;

    posicion = contador + 1;

}

contador++;

cout << "Ingresar Numeros: ";
cin >> numeros;

}

cout << "Numero Maximo: " << Max << endl;
cout << "Posicion: " << posicion << endl;






    return 0;
}
