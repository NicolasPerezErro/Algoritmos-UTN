#include <iostream>
#include "matrices.hpp"
using namespace std;

void inicializar (float m[][MAX_COLUMNAS], int f, int c){
	for(int i = 0; i < f; i++) {
		for(int j=0; j < c; j++){
			m[i][j] = 0;
		}
	}
	return;
}

void cargar (float m[][MAX_COLUMNAS], int f, int c){
	float medicion;
	for(int i = 0; i < f; i++) {
		for(int j=0; j < c; j++){
			cout << "Ingresar Medicion" << endl;
			cin >> medicion;
			m[i][j] = medicion;
		}
	}
	return;
}

void mostrar(float m[][MAX_COLUMNAS], int f, int c){
	for(int i = 0; i < f; i++) {
		for(int j=0; j < c; j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

float buscarMaximaMedicion(float m[][MAX_COLUMNAS], int f, int c, int &posF, int &posC){

	float maximo = 0;

	for(int i = 0; i < f; i++) {

		for(int j=0; j < c; j++){

			if (m[i][j] > maximo){

                maximo = m[i][j];
                posC = j;
                posF = i;
			}
	}
	}

	return maximo;
}

float buscarMinimaMedicion(float m[][MAX_COLUMNAS], int f, int c, int &posF, int &posC){

	float minimo = 300;

	for(int i = 0; i < f; i++) {

		for(int j=0; j < c; j++){

			if (m[i][j] < minimo){

                minimo = m[i][j];
                posC = j;
                posF = i;
        }
	}

}

	return minimo;

}

void mostrarResultado(string texto, float valor, int posF, int posC){

    cout << texto << " " << valor << " fue obtenida ";

    switch(posC) {

    case 0:
        cout << "El domingo ";
        break;
    case 1:
        cout << "El lunes ";
        break;
    case 2:
        cout << "El martes ";
        break;
    case 3:
        cout << "El miercoles ";
        break;

    case 4:
        cout << "El jueves ";
        break;
    case 5:
        cout << "El viernes ";
        break;
    case 6:
        cout << "El sabado ";
        break;

        default:
        break;
                }

if (posF == 0){

    cout << "a la mañana";

} else if (posF == 1){

    cout << "a la tarde";

} else{

cout << "a la noche";
}

	return;
}
