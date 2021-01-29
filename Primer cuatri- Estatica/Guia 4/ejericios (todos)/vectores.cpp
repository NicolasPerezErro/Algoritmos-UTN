#include <iostream>
#include "vectores.h"

using namespace std;

// n-> la cantidad de elemenotos que puede contener
// len -> los elementos que hay en el vector

void inicializar(int vec[], int n){

for(int i = 0; i < n; i++){

    vec[i] = 0;
                      }

}

void agregar(int arr[], int n, int& len, int v){

    if (len < n){
        arr[len] = v;
        len++;
    } else { cout << "El vector esta lleno" << endl;}


}

// PRIMERA ITERACION -> VACIO -> LEN = 0
// LLAMO A AGREGAR -> INSERTO VALOR EN POS 0 ->  LEN = 1
// SEGUNDA ITERACION -> LEN = 1
// LLAMO A AGREGAR -> INSERTO VALOR EN POS 1 --> LEN = 2


void mostrar(int arr[], int len){ // MOSTRAR EL VECTOR

for (int i = 0; i < len; i++){

    cout << arr[i] << endl;

                            }


}

// el n no se pasa porque vas a mostrar posiciones ocupadas
// no se pasa & porque se muestra nada mas


int buscar(int arr[], int len, int v){

int i = 0;
int pos = -1;

while (i < len && arr[i] != v){ // USO UN WHILE Y NO FOR PORQUE DESCONOZCO EL VALOR DEL LEN, EN UN FOR LO CONOZCO

i++; // SI SALE PORQUE EL VECTOR ESTA VACIO O PORQUE NO ENCONTRO EL ELEMENTO
     // NOSOTROS TENEMOS QUE DECIR QUE SI SE PUEDE RECORRER EL VECTOR Y SALE PORQUE ENCONTRO EL ELEMENTO, ENTONCES EXIGIR QUE SI SE PUEDE RECORRER
     // QUE GUARDE LA POS

}

if (i < len && arr[i] != v){

    pos = i;

}

return pos;

}

void eliminar(int arr[], int& len, int v){


for(int i = pos; i < len - 1; i++){

arr[i] = arr[i+1];

}
len--;

arr[len] = 0; // LA ULTIMA POS SEA 0


}

void insertar(int arr[], int& len, int v, int pos){

for (int i = len-1 ; i >= pos ; i--){ // DE ATRAS PARA ADELANTE

arr[i+1] = arr[i];

}

arr[pos] = v;
len++;

}

int insertarOrdenado(int arr[], int& len, int v){ // RECORRE EL VECTOR HASTA ENCONTRAR UN VALOR MAYOR AL QUE PUSISTE Y LO INSERTAS EN ESA POS

int i = 0;
while(i < len && arr[i] <= v){

  i++;
    }

    insertar(arr,len,v,i); // INSERTO EL VALOR QUE ME DISTE EN LA POSICION QUE SALIO.
    return i; // POS -- LO INSERTO EN LA POSICION i

}

int buscaEInserta(int arr[], int& len, int v, bool& enc) {

int pos = buscar(arr,len,v);
if (pos == -1){
    enc = false;
    pos = insertarOrdenado(arr,len,v);

} else{ enc = true;   }

return pos;
}


