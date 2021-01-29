#include <string>

using namespace std;

struct pais {
  string nombre;
  int velocidadMax;
  int velocidadMin;
};

struct nota {
  int codigo;
  int cantidadAlumnos;
};

struct producto {
  int codigo;
  string nombre;
  float precio;
  int stock;
};

struct notas{

int legajo;
string nombre;
int notas;

};

struct estudiantes{

int legajo;
string apellido;
int promedio;
};

struct estudiantePA {
  int legajo;
  string nya;
  string materia;
  float notaFinal;
};

struct sucursal{

int sucursal;
int dia;
int dineroRecaudado;

};

struct claustro{
int legajo;
char nombre[50];

};

struct claustroConsolidado{ // ESTA ESTRUCTURA ALMACENA TODOS LOS DATOS JUNTOS

claustro claustro1;
char descripcion[50]; //SE REFIERE AL CLAUSTRO AL QUE PERTENECE!

};

struct venta{

int codArt;
int cantVendida;
float precioUnitario;

};

struct datos{

venta datos1;

};


#ifndef vectores
#define vectores

//n -> cantidad de elementos totales que puede almacenar el vector
//len -> cantidad de elementos reales que hay en el vector
void inicializar(int vec[], int n);
void agregar(float arr[], int n, int &len, float v);
void mostrar(float arr[], int len);
int buscar(int arr[], int len, int v);
void eliminar(int arr[], int &len, int pos);
void insertar(int arr[], int &len, int v, int pos);
int insertarOrdenado(int arr[],int &len, int v);
int buscaEInserta(int arr[],int& len, int v, bool& enc);
int buscarMinimo(int vec[],int len);
void lineaSeparatoria();

int buscarMaximaVelocidad(pais vec[], int len, int &pos);
int buscarMinimaVelocidad(pais vec[], int len, int &pos);
float sacarPromedioVelocidadMaxima(pais vec[], int len);

int buscarMaxInscriptos(nota vec[], int len);
int buscarMinInscriptos(nota vec[], int len);
float sacarPromedioInscriptos(nota vec[], int len);

void imprimirMenu();
void agregarProducto(producto arr[], int n, int &len, producto productoAGuardar);
void mostrarProducto(producto arr[], int len);
int buscarProducto(producto arr[], int len, string nombre);
void modificarProducto(producto arr[], int len, string producto ,int stock, int precio);

int buscarAlumno(notas arr[], int len, string alum);
void modificarNota(notas arr[], int len, string alum, int nota);
void mostrarNotas(notas arr[],int len);
float promedioNotas(notas arr[], int len);
int mejorNota(notas arr[], int len);
int peorNota(notas arr[], int len);

void agregarEstudiantes(estudiantes arr[], int n, int& len, estudiantes info);
void mostrarEstudiantes(estudiantes arr[],int len);

void insertarClaustro(claustroConsolidado arr[], int &len, claustroConsolidado v, int pos);
int insertarOrdenadoClaustro(claustroConsolidado arr[],int &len, claustroConsolidado v);

void agregarVentas(venta vec[],int n,int& len,venta v);

#endif
