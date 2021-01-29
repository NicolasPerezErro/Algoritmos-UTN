#include <iostream>

using namespace std;

void inicializar(int vec[], int tam);
void agregar(int vec[], int len);
void mostrar(int vec[], int len);
void eliminar(int vec[], int& len, int pos);
int buscar (int vec[], int len, int v);
int insertar(int vec[], int &len, int pos, int v);

int main(){

int n;
int len = 0;
int pos;
int v;


cout << "Capacidad del vector: ";
cin >> n;

cout << "Cantidad de numeros reales: ";
cin >> len;

int vec[n];

inicializar(vec,n);

agregar(vec,len);

mostrar(vec,len);

cout << "Que elemento queres buscar: ";
cin >> v;

int pos_buscada = buscar(vec,len,v);

if (pos_buscada != -1){ cout << "Encontrada: " << pos_buscada << endl;} else {cout << "No encontrado " << endl;}

cout << "Que posicion queres eliminar: ";
cin >> pos;

eliminar(vec,len,pos);

mostrar(vec,len);


cout << "Numero a insertar: ";
cin >> v;

cout << "Posicion a insertar: ";
cin >> pos;

insertar(vec,len,v,pos);
mostrar(vec,len);


return 0;

}

void inicializar(int vec[], int tam){

        for (int i = 0; i < tam; i++){

                vec[i] = 0;
                                    }

}


void agregar(int vec[], int len){

        for (int i = 0; i < len; i++){

            cout << "Numeros: ";
            cin >> vec[i];


                                    }

    }

void mostrar(int vec[], int len){


        for (int i = 0; i < len; i++){

            cout << vec[i] << endl;


                                    }

}

int buscar (int vec[], int len, int v){

int pos = -1;
int i = 0;

while (i < len && v != vec[i]){i++;}

if (i < len && v == vec[i]){

    pos = i;

}


return pos;

}


void eliminar(int vec[], int& len, int pos){


for (int i = pos; i < len - 1 ; i++){

    vec[i] = vec[i+1];

}

len--;

vec[len] = 0;

}


int insertar(int vec[], int &len, int pos, int v){ // funciona raro


        for (int i = len - 1; i >= pos; i--){

                vec[i+1] = vec[i];
                                            }

vec[pos] = v;

len++;

}
