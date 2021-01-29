#include <iostream>
#include "vectores.h"

using namespace std;


int main(){

int len = 0;
int n= 5;
int vec[n];

int m = 6;
int vec2[m];
int len2 = 0;
int v;

inicializar(vec,n);

// ejercicio 1

agregar(vec,n,len,5);
agregar(vec,n,len,10);
agregar(vec,n,len,20);
agregar(vec,n,len,30); // esta demas para que tire que esta lleno



cout << len << endl; // vale 3

cout << "-----------" << endl;


// ejercicio 2

mostrar(vec, len);



cout << "-----------" << endl;

// ejercicio 3


int posBuscada = buscar(vec,len,5);

if(posBuscada != -1){

    cout << "El elemento se encuentra en la posicion: " << posBuscada << endl;


} else { cout << "No se encuentra " << endl; }



cout << "-----------" << endl;

// ejercicio 4


eliminar(vec,len,1);

mostrar(vec,len);

cout << len << endl; // se le resta 1
cout << vec[len] << endl;


cout << "-----------" << endl;

// ejercicio 5

agregar(vec2,m,len2,5);
agregar(vec2,m,len2,60);
agregar(vec2,m,len2,30);
agregar(vec2,m,len2,45);

insertarOrdenado(vec2, len2, 25);
mostrar(vec2,len2);
cout << len2 << endl;


cout << "-----------" << endl;

// ejercicio 6

bool encontrado;
int pos = buscaEInserta(vec2,len2,25,encontrado);
if (encontrado){

    cout << "Ya estaba en la posicion: " << pos << endl;

} else {
        cout << "Se inserto ordenado en la posicion " << pos << endl;


}

    return 0;
}



