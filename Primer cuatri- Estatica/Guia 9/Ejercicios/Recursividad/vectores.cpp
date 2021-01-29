#include <iostream>
#include <string>
#include "vectores.h"

using namespace std;

void inicializar(int vec[], int n) {
    for(int i = 0; i < n; i++) {
          vec[i] = 0;
    }
}

// Primera iteracion -> vector vacío -> len = 0
// llamo a agregar -> inserto valor en pos O  -> len = 1
// Segunda iteración -> len = 1
// llamo a agregar -> inserto valor en pos 1 -> len = 2

void agregar(float arr[], int n, int &len, float v) {
    if (len < n) {
      arr[len] = v;
      len++;
    } else {
      cout << "El vector está lleno :( " << endl;
    }
}

void mostrar(float arr[], int len) {
    for(int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
}

int buscar(int arr[], int len, int v) {
    int i = 0;
    int pos = -1;

    while( i < len && arr[i] != v) {
        i++;
    }

    if (i < len) {
      pos = i;
    }

    return pos;
}

void eliminar(int arr[], int &len, int pos) {
    for(int i = pos; i < len - 1 ; i ++) {
        arr[i] = arr[i + 1];
    }
    len--;
    arr[len] = 0;
}

void insertar(int arr[], int &len, int v, int pos) {
    for(int i = len-1; i >= pos; i--) {
        arr[i+1] = arr[i];
    }
    arr[pos] = v;
    len++;
}

int insertarOrdenado(int arr[],int &len, int v) {
    int i = 0;
    while(i < len && arr[i] <= v) {
      i++;
    }

    insertar(arr,len,v,i);
    return i;
}

int buscaEInserta(int arr[],int& len, int v, bool& enc) {
    int pos = buscar(arr,len,v);
    if(pos == -1) {
      enc = false;
      pos = insertarOrdenado(arr, len, v);
    } else {
      enc = true;
    }
    return pos;
}

int buscarMinimo(int vec[],int len) {
  int min = 999999999;
  for(int i = 0; i < len; i ++) {
      if(vec[i] < min) {
        min = vec[i];
      }
  }
  return min;
}

void lineaSeparatoria() {
  cout << endl;
  cout << "_____________________________" << endl;
  cout << endl;
}

int buscarMaximaVelocidad(pais vec[], int len, int &pos) {
  int max = -1;
  for(int i = 0; i < len; i ++) {
      if(vec[i].velocidadMax > max) {
        max = vec[i].velocidadMax;
        pos = i;
      }
  }
  return max;
}

int buscarMinimaVelocidad(pais vec[], int len, int &pos) {
  int min = 99999999;
  for(int i = 0; i < len; i ++) {
      if(vec[i].velocidadMin < min) {
        min = vec[i].velocidadMin;
        pos = i;
      }
  }
  return min;
}

float sacarPromedioVelocidadMaxima(pais vec[], int len) {
  float suma = 0;
  for(int i = 0; i < len; i ++) {
    suma += vec[i].velocidadMax;
  }
  return suma/len;
}

int buscarMaxInscriptos(nota vec[], int len) {
  int max = -1;
  int materia = -1;
  for(int i = 0; i < len; i ++) {
      if(vec[i].cantidadAlumnos > max) {
        max = vec[i].cantidadAlumnos;
        materia = vec[i].codigo;
      }
  }
  return materia;
}

int buscarMinInscriptos(nota vec[], int len) {
  int min = 99999999;
  int materia = -1;
  for(int i = 0; i < len; i ++) {
      if(vec[i].cantidadAlumnos < min) {
        min = vec[i].cantidadAlumnos;
        materia = vec[i].codigo;
      }
  }
  return materia;
}


float sacarPromedioInscriptos(nota vec[], int len) {
  float suma = 0;
  for(int i = 0; i < len; i ++) {
    suma += vec[i].cantidadAlumnos;
  }
  return suma/len;
}

void imprimirMenu() {
   cout << "Ingrese 1 para dar de alta un producto" << endl;
   cout << "Ingrese 2 para buscar un producto" << endl;
   cout << "Ingrese 3 para modificar el stock de un producto" << endl;
   cout << "Ingrese 4 para modificar el precio de un producto" << endl;
   cout << "Ingrese 0 para salir" << endl;
};

void agregarProducto(producto arr[], int n, int &len, producto productoAGuardar) {
    if (len < n) {
      arr[len] = productoAGuardar;
      len++;
    } else {
      cout << "El vector está lleno :( " << endl;
    }
}

void mostrarProducto(producto arr[], int len) {
  for(int i =0; i < len; i++) {
    cout << "Código: " << arr[i].codigo << endl;
    cout << "Nombre: " << arr[i].nombre << endl;
    cout << "Precio: " << arr[i].precio << endl;
    cout << "Stock: " << arr[i].stock << endl;
    lineaSeparatoria();
  }
}

int buscarProducto(producto arr[], int len, string nombre) {
    int i = 0;
    int pos = -1;

    while( i < len && arr[i].nombre != nombre) {
        i++;
    }

    if (i < len) {
      pos = i;
    }

    return pos;
}

void modificarProducto(producto arr[], int len, string producto ,int stock, int precio){

for (int i = 0; i < len; i++){
    if (arr[i].nombre == producto){
            arr[i].stock = stock;
            arr[i].precio = precio;

            }
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

void agregarEstudiantes(estudiantes arr[], int n, int &len, estudiantes info){

    if (len < n){

        arr[len] = info;
        len++;

    } else {cout << "Vector lleno" << endl;}

}

void mostrarEstudiantes(estudiantes arr[],int len){

for (int i = 0; i < len; i++){

    cout << arr[i].legajo << endl;
    cout << arr[i].apellido << endl;
    cout << arr[i].promedio << endl;
    }
}


void insertarClaustro(claustroConsolidado arr[], int &len, claustroConsolidado v, int pos) {
    for(int i = len-1; i >= pos; i--) {
        arr[i+1] = arr[i];
    }
    arr[pos] = v;
    len++;
}

int insertarOrdenadoClaustro(claustroConsolidado arr[],int &len, claustroConsolidado v) {
    int i = 0;
    while(i < len && arr[i].claustro1.legajo <= v.claustro1.legajo) {
      i++;
    }

    insertarClaustro(arr,len,v,i);
    return i;
}

void agregarVentas(datos vec[],int n,int& len,datos v){

if (len < n){

    vec[len] = v;
    len++;
}

}
