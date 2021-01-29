#include <string>
using namespace std;


struct pais { // este es el vector

string nombre;
int velocidadMax;
int velocidadMin;

    };

 struct alumnos{

 int codigoMateria;
 int cantAlumnos;

 };

struct quiosko{

int codigoProducto;
string nombre;
int precio;
int cantStock;

};

struct notas{

int legajo;
string nombre;
int notas;

};



#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

// n-> la cantidad de elemenotos que puede contener
// len -> los elementos que hay en el vector

void inicializar(int vec[], int n);
void agregar(int arr[], int n, int& len, int v);
void mostrar(int arr[], int len);
int buscar(int arr[], int len, int v);
void eliminar(int arr[], int& len, int pos);
void insertar(int arr[], int& len, int v, int pos);
int insertarOrdenado(int arr[], int& len, int v);
int buscaEInserta(int arr[], int& len, int v, bool& enc);

int buscarMaximaVelocidad(pais vec[], int len, int& pos);
int buscarMinimaVelocidad(pais vec[], int len, int& pos);
float promedioVelocidadMax(pais vec[],int len);


// DEVOLVAMOS SOLO CUAL ES LA MATERIA
int buscarMaximoAlumnos(alumnos vec[], int len);
int buscarMinimoAlumnos(alumnos vec[], int len);
float promedioInscriptos(alumnos vec[],int len);

//
void agregarProducto(quiosko arr[],int n,int& len, quiosko productoAInsertar);
int buscarProducto(quiosko arr[], int len, string v);
void modificar(quiosko arr[], int len, string producto ,int stock, int precio);
void mostrarProducto(quiosko arr[], int len);

void imprimirMenu();

//

int buscarAlumno(notas arr[], int len, string alum);
void modificarNota(notas arr[], int len, string alum, int nota);
void mostrarNotas(notas arr[],int len);
float promedioNotas(notas arr[], int len);
int mejorNota(notas arr[], int len);
int peorNota(notas arr[], int len);
void imprimirMenuNotas();



#endif // VECTORES_H_INCLUDED
