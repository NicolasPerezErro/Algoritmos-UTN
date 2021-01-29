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




#endif // VECTORES_H_INCLUDED
