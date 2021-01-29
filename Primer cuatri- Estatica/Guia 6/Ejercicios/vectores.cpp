#include <iostream>
#include <string>
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

i++;

}

if (i < len && arr[i] != v){

    pos = i;

}

return pos;

}

void eliminar(int arr[], int& len, int pos){


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

int insertarOrdenado(int arr[], int& len, int v){ // RECORRE EL VECTOR HASTA ENCONTRAR UN VALOR MENOR AL QUE PUSISTE Y LO INSERTAS EN ESA POS

int i = 0;
while(i < len && arr[i] <= v){

  i++;
    }

    insertar(arr,len,v,i);
    return i; // POS

}

int buscaEInserta(int arr[], int& len, int v, bool& enc) {

int pos = buscar(arr,len,v);
if (pos == -1){
    enc = false;
    pos = insertarOrdenado(arr,len,v);

} else{ enc = true;   }

return pos;
}


int buscarMaximaVelocidad(pais vec[], int len, int& pos){

int maxi = 0;

for (int i = 0; i < len; i++){
    if (vec[i].velocidadMax > maxi){

        maxi = vec[i].velocidadMax;
        pos = i;
    }

}

return maxi;

}

int buscarMinimaVelocidad(pais vec[], int len, int& pos){

int mini = 9999999;

for (int i = 0; i < len; i++){
    if (vec[i].velocidadMin < mini){

        mini = vec[i].velocidadMin;
        pos = i;
    }

}

return mini;

}

float promedioVelocidadMax(pais vec[], int len){

int suma = 0;

for (int i = 0; i < len; i++){

    suma = suma + vec[i].velocidadMax;

}

return suma/len;

}




int buscarMaximoAlumnos(alumnos vec[], int len){

int maxi = 0;
int materia = -1;
int pos = 0;

for (int i = 0; i < len; i++){
    if (vec[i].cantAlumnos > maxi){

        maxi = vec[i].cantAlumnos;
        materia = vec[i].codigoMateria;

    }

}

return maxi;
}

int buscarMinimoAlumnos(alumnos vec[], int len){

int mini = 999999;
int materia = -1;

for (int i = 0; i < len; i++){
    if (vec[i].cantAlumnos < mini){

        mini = vec[i].cantAlumnos;
        materia = vec[i].codigoMateria;
    }

}

return mini;
}

float promedioInscriptos(alumnos vec[],int len){

float suma = 0;

for (int i = 0; i < len; i++){

    suma = suma + vec[i].cantAlumnos;

}

return suma/len;
}



int buscarProducto(quiosko arr[], int len, string v){

int i = 0;
int pos = -1;

while (i < len && arr[i].nombre != v){ // USO UN WHILE Y NO FOR PORQUE DESCONOZCO EL VALOR DEL LEN, EN UN FOR LO CONOZCO

i++;

}

if (i < len){

    pos = i;

}

return pos;
}

void modificar(quiosko arr[], int len, string producto ,int stock, int precio){

for (int i = 0; i < len; i++){
    if (arr[i].nombre == producto){
            arr[i].cantStock = stock;
            arr[i].precio = precio;

            }
        }
    }


void imprimirMenu(){

cout << "Ingrese 1 para dar de alta un producto" << endl;
cout << "Ingrese 2 para buscar un producto" << endl;
cout << "Ingrese 3 para modificar el stock" << endl;
cout << "Ingrese 0 para salir" << endl;

}


void agregarProducto(quiosko arr[],int n,int& len, quiosko productoAInsertar){

  if (len < n){
        arr[len] = productoAInsertar; // EN LEN ESTA VACIO, POS 3, ENTONCES AGREGO EL CUARTO Y ADEMAS EL N ES HASTA 10
        len++;
    } else { cout << "El vector esta lleno" << endl;}

}

void mostrarProducto(quiosko arr[], int len){

for (int i = 0; i < len; i++){

    cout << "Codigo del producto: " << arr[i].codigoProducto << endl;
    cout << "Nombre del producto: " << arr[i].nombre << endl;
    cout << "Precio del producto: " << arr[i].precio << endl;
    cout << "Stock del producto: " << arr[i].cantStock << endl;
    }
}


int buscarAlumno(notas arr[], int len, string alum){

int legajo;


for (int i = 0; i < len; i++){

if (arr[i].nombre == alum){

    legajo = arr[i].legajo;



        }


    }

    return legajo;

}

void modificarNota(notas arr[], int len, string alum, int nota){


    for (int i = 0; i < len; i++){

            if (arr[i].nombre == alum){

                arr[i].notas = nota;

        }

    }



}

void mostrarNotas(notas arr[], int len){

    for (int i = 0; i <len; i++){

        cout << "Legajo: " << arr[i].legajo << endl;
        cout << "Nombre: " << arr[i].nombre << endl;
        cout << "Nota: "   << arr[i].notas << endl;
    }



}

float promedioNotas(notas arr[], int len){

float suma = 0;


    for (int i = 0; i < len; i++){

            suma = suma + arr[i].notas;


        }

return suma/len;

}

int mejorNota(notas arr[], int len){

int notaMax = 0;
int posMax = 0;

for (int i = 0; i < len; i++){

    if (arr[i].notas > notaMax){

        notaMax = arr[i].notas;
        posMax = i;
        }


    }

return posMax;

}

int peorNota(notas arr[], int len){

int notaMin = 1000;
int posMin = 0;

for (int i = 0; i < len; i++){

    if (arr[i].notas < notaMin){

        notaMin = arr[i].notas;
        posMin = i;
        }


    }

return posMin;

}

void imprimirMenuNotas(){

cout << "1. Nombre a buscar" << endl;
cout << "2. Modificar nota" << endl;
cout << "3. Promedio de las notas" << endl;
cout << "4. Alumno con la mejor nota" << endl;
cout << "5. Alumno con la peor nota" << endl;

}
