#include <iostream>
#include "matrices.hpp"
#include <math.h>

using namespace std;


int main()
{
//  EJERCICIO 1

int cantFilas = 3;
int cantColumnas = 3;
float matriz[MAX_FILAS][MAX_COLUMNAS];

inicializar(matriz,cantFilas,cantColumnas);


for (int i = 0; i < cantFilas; i++){

    for (int j = 0; j < cantColumnas; j++){

        cout << "Ingresar numeros: ";
        cin >> matriz[i][j];

    }

    cout << "" << endl;
}


for (int i = 0; i < cantFilas; i++){

    for (int j = 0; j < cantColumnas; j++){

        cout << matriz[j][i] << " ";

    }

    cout << "" << endl;
}




 // EJERCICIO 2

 /*

int cantFilas = 3;
int cantColumnas = 3;
float matriz[MAX_FILAS][MAX_COLUMNAS];
int determinante = 0;
int resultado1;
int resultado2;
int resultado3;



for (int i = 0; i < cantFilas; i++){

    for (int j = 0; j < cantColumnas; j++){

        cout << "Ingresar numeros: ";
        cin >> matriz[i][j];

    }

    cout << "" << endl;
}





resultado1 = matriz[0][0]* ((matriz[1][1]*matriz[2][2]) - (matriz[2][1]*matriz[1][2]));
resultado2 = -(matriz[0][1])* ((matriz[1][0]*matriz[2][2]) - (matriz[1][2]*matriz[2][0]));
resultado3 = matriz[0][2]* ((matriz[1][0]*matriz[2][1]) - (matriz[1][1]*matriz[2][0]));

determinante = resultado1 + resultado2 + resultado3;

cout << "El determinante es: " << determinante << endl;

*/






// EJERCICIO 3
/*
int cantFilas = 3;
int cantColumnas = 3;
float matriz[MAX_FILAS][MAX_COLUMNAS];
float matrizSignos[MAX_FILAS][MAX_COLUMNAS];
float matrizAdjunta [MAX_FILAS][MAX_COLUMNAS];


for (int i = 0; i < cantFilas; i++){

    for (int j = 0; j < cantColumnas; j++){

        cout << "Ingresar numeros: ";
        cin >> matriz[i][j];

    }

    cout << "" << endl;
}


for (int i = 0; i < cantFilas; i++){

    for (int j = 0; j < cantColumnas; j++){

        matrizSignos[i][j] = pow(-1,i+j);
    }

    cout << "" << endl;
}












for (int i = 0; i < cantFilas; i++){

    for (int j = 0; j < cantColumnas; j++){

        matrizAdjunta[i][j] =

    }
}

*/







/* EJERCICIO 4

// INVERSA = ADJ(TRASPUESTA)/DETERMINANTE

float matrizInversa[cantFilas][cantColumnas];








*/


/* EJERCICIO 5

int cantFilas = 2;
int cantColumnas = 2;
int matriz1[MAX_FILAS][MAX_COLUMNAS];
int matriz2[MAX_FILAS][MAX_COLUMNAS];
int producto[MAX_FILAS][MAX_COLUMNAS];

cout << "Matriz 1: " << endl;

for (int i = 0; i < cantFilas; i++){

    for (int j = 0; j < cantColumnas; j++){

        cout << "Ingresar numeros: ";
        cin >> matriz1[i][j];

    }

    cout << "" << endl;
}

cout << "" << endl;
cout << "Matriz 2: " << endl;


for (int i = 0; i < cantFilas; i++){

    for (int j = 0; j < cantColumnas; j++){

        cout << "Ingresar numeros: ";
        cin >> matriz2[i][j];

    }

    cout << "" << endl;
}

inicializar(producto,cantFilas,cantColumnas);

    cout << "" << endl;
}


for (int i = 0; i < cantFilas; i++){

    for (int j = 0; j < cantColumnas; j++){

        producto[i][j] = matriz1[i][j] * matriz2[i][j];

    }

    cout << "" << endl;
}

cout << "Matriz producto: " << endl;


for (int i = 0; i < cantFilas; i++){

    for (int j = 0; j < cantColumnas; j++){

        cout << producto[i][j] << " ";

    }

    cout << "" << endl;
}

*/


    return 0;
}









