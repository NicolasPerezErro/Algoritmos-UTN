#include <iostream>

using namespace std;

struct articulo{

int numero;
char descripcion[50];

};

int buscar(int vec[], int len, int v);
int busquedaBinaria(int vec[], int len, int v);

int main()
{



int vec[6] = {1,2,3,4,5,6};
int len = 6;
int v = 5;

int b;

b = buscar(vec,len,v);

cout << b << endl;



int vec2[10] = {4,5,6,23,34,45,59,60,70,87};
int len2 = 10;
int valorBuscado;




int x = busquedaBinaria(vec2,len2,23);

cout << x << endl;






    return 0;
}

int buscar(int vec[], int len, int v){

int pos = -1;
int i = 0;

while (i < len && vec[i] != v){

    pos = i;

    i++;
}

if (vec[i] == v){

    pos = i;

}

return pos;
}

int busquedaBinaria(int vec[],int len, int v){
int pos = -1;
int primero = 0;
int ultimo = len - 1;
int medio = (primero+ultimo)/2;


while (primero <= ultimo){

    if (v == vec[medio]){
        pos = medio;
        break;
    }

    if (v < vec[medio]){

        ultimo = medio - 1;

        // medio = (primero+ultimo)/2;

    }

    if (v > vec[medio]){

        primero = medio + 1;

         // medio = (primero+ultimo)/2;
        }


      medio = (primero+ultimo)/2;

    }



return pos;
}







