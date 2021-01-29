#include <iostream>
#include <string>
#include "matrices.hpp"
using namespace std;

int main() {
	float matriz[MAX_FILAS][MAX_COLUMNAS];
	int cantFilas;
	int cantColumnas;
	float maxMedicion;
	float minMedicion;
	int posFilMax;
	int posColMax;
	int posFilMin;
	int posColMin;

	cout << "Ingrese la cantidad de filas" << endl;
	cin >> cantFilas;

	//Validar que se ingrese un numero correcto de filas

	while (cantFilas <= 0 || cantFilas > MAX_FILAS){

        cout << "Ingrese un numero de filas correcto: ";
        cin >> cantFilas;
	}

	cout << "Ingrese la cantidad de Columnas" << endl;
	cin >> cantColumnas;

	while (cantColumnas <= 0 || cantColumnas > MAX_COLUMNAS){

        cout << "Ingrese un numero de columnas correcto: ";
        cin >> cantColumnas;
	}

	//Validar que se ingrese un numero correcto de columnas

	inicializar(matriz,cantFilas,cantColumnas);
	cargar(matriz,cantFilas,cantColumnas);
	mostrar(matriz,cantFilas,cantColumnas);

	cout << endl;

maxMedicion = buscarMaximaMedicion(matriz, cantFilas, cantColumnas, posFilMax, posColMax);

mostrarResultado("La maxima medicion ",maxMedicion, posFilMax,posColMax);

minMedicion = buscarMinimaMedicion(matriz, cantFilas, cantColumnas, posFilMin, posColMin);

mostrarResultado("La minima medicion ",minMedicion, posFilMin,posColMin);


	return 0;
}

