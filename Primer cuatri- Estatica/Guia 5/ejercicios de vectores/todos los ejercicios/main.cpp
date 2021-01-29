#include <iostream>
#include "vectores.h"

using namespace std;

int main()
{

/*
int n;
int vec[30];
int len = 0;

cout << "Ingrese numero n: ";
cin >> n;

while (n<0 || n>30){

    cout << "Ingrese numero correcto: ";
    cin >> n;
                    }

for (int i = 0; i < n; i++{
agregar(vec,n,len,2*i + 2);
}

mostrar(vec,len)

*/

/*
int n = 100;
int vec[n];
int len = 0;
int minimo = 10000;
int numeros;
int vecMinimos[100];
int len2 = 0;

cout << "Ingrese numeros: ";
cin >> numeros;

while (numeros > 0 && numeros <= 100){

    agregar(vec,n,len,numeros);
    cout << "ingrese numeros: ";
    cin >> numeros;                  }



for (int i = 0; i < len; i++){

    if (vec[i] < minimo){

        minimo = vec[i];
                        }

                              }



for (int i = 0; i < len; i++){

    if (vec[i] == minimo){

        agregar(vecMinimos,100,len2,i);
                        }


                            }

cout << "Posiciones del " << minimo << " : ";

mostrar(vecMinimos,len2);



for (int i = 0; i < len; i++){

    if (vec[i]%2 != 0 && i%2 == 0){ // valido?

        cout << vec[i] << endl;

    }
}

*/

/*
int vecA[25];
int posA[25];
int vecB[25];
int vecC[25];
int vecD[25];
int lenA = 0;
int posLenA = 0;
int lenB = 0;
int lenC = 0;
int lenD = 0;
int n = 25;
int numeros;



for (int ia = 0; ia < 25; ia++){

    agregar(vecA,n,lenA,ia*2 + 1);

                            }



for (int i = 0; i < 25; i++){

    agregar(vecB,n,lenB,i*2 + 2);

                            }

for (int i = 0; i < 25; i++){

    if (i%2 == 0){

        agregar(vecC,n,lenC,i*2 + 2);
    }

    else {agregar(vecC,n,lenC,i*2 + 1);}

}

mostrar(vecC,lenC);

for (int i = 0; i < 25; i++){

    if (vecA[i] == vecB[i]){

        agregar(vecD,n,lenD,0);

    } else {agregar(vecD,n,lenD,1);}


}

mostrar(vecD,lenD);

*/

 int dado1;
  int dado2;
  int suma;
  int resultado[11]; //0 a 10
  int n = 11;
  int indice;

  inicializar(resultado, n);

  //En realidad es i < 50
  for(int i=0; i < 5; i++) {
      cout << "Ingrese los dados de la tirada " << i+1 << endl;
      cout << "Ingrese el dado 1: " << endl;
      cin >> dado1;
      cout << "Ingrese el dado 2: " << endl;
      cin >> dado2;
      suma = dado1 + dado2;
      indice = suma - 2;
      resultado[indice]++;
  }

  for(int i=0; i < n; i++) {
    cout << i+2 << " salió " << resultado[i] << " veces" << endl;
  }

}






    return 0;
}



