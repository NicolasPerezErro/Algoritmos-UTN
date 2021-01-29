#include <iostream>
#include <string.h>

using namespace std;

struct Nodo {
    int info;
    Nodo* sig;
};

void agregarNodo(Nodo* &p, int x);
void mostrar (Nodo* p);
void liberar(Nodo* &p);
Nodo* buscar(Nodo* p, int v);
void eliminar(Nodo*&p, int v);
int eliminarPrimerNodo(Nodo*&p);
Nodo* insertarOrdenado(Nodo*&p, int v);

// EJ 8 Y 9
void ordenar(Nodo*& p);
Nodo* buscaEInsertaOrdenado(Nodo* &p, int v, bool & enc);

int main()
{

	Nodo* lista = NULL;
	agregarNodo(lista,0);
	agregarNodo(lista,10);
	agregarNodo(lista,11);
    agregarNodo(lista,20);
    agregarNodo(lista,50);
    agregarNodo(lista,4);
    agregarNodo(lista,1);
    agregarNodo(lista,100);
    agregarNodo(lista,2);
	Nodo* buscado;
	buscado = buscar(lista,4);

	if(buscado != NULL) {
		eliminar(lista,4);
	} else {
		cout << "El valor no se encuentra" << endl;
	}
	cout<< "El nro. del primer nodo es " << eliminarPrimerNodo(lista) << endl;

	ordenar(lista);
	bool encontrado;
	Nodo * nodoBuscado = buscaEInsertaOrdenado(lista, 20, encontrado);
	cout << nodoBuscado->info << endl;
	if(encontrado) {
		 cout << "El nodo ya existia" << endl;
	} else {
		cout << "El nodo fue insertado" << endl;
	}

	mostrar(lista);
	liberar(lista);



    return 0;
}


Nodo* buscaEInsertaOrdenado(Nodo* &p, int v, bool & enc) {
	Nodo * nodoBuscado = buscar(p,v);
	if(nodoBuscado != NULL) { // el nodo est� en la lista
		enc = true;
	} else { // el nodo no est�
		nodoBuscado = insertarOrdenado(p,v); // EL INSERTAR ORDENADO DEVUELVE EL NODO QUE INSERTÓ
		enc = false;
	}

	return nodoBuscado;
}

void ordenar(Nodo*& p) {
	Nodo* q = NULL;
	int valor;

	while(p != NULL) {
		valor = eliminarPrimerNodo(p);
		insertarOrdenado(q, valor);
	}

	p = q;
}

Nodo* insertarOrdenado(Nodo*&p, int v){
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;
	Nodo* ant = NULL;
	Nodo* aux = p;

	while(aux!=NULL && aux->info <= v) {
		ant = aux;
		aux = aux->sig;
	}

	if(ant == NULL){ //Estoy insertando al principio
		p= nuevo;
	} else {
		ant->sig = nuevo;
	}
	nuevo->sig = aux;

	return nuevo;
}

int eliminarPrimerNodo(Nodo*&p) {
	int retorno = p->info;
	Nodo* aux = p;
	p = p->sig;
	delete aux;
	return retorno;
}

void eliminar(Nodo*&p, int v) {
	Nodo* aux = p;
	Nodo* ant = NULL;
	while(aux!= NULL && aux->info != v){
		ant = aux;
		aux = aux->sig;
	}

	if(ant == NULL) { //Estamos eliminando el primer nodo
		p = aux->sig;
	} else {
		ant->sig = aux->sig;
	}

	delete aux;
}

Nodo* buscar(Nodo* p, int v) {
	Nodo* aux = p;
	while(aux!= NULL && aux->info != v){
		aux = aux->sig;
	}
	return aux;
}

void liberar(Nodo*&p){
	Nodo* aux;
	while(p!=NULL) {
		aux = p;
		p=p->sig;
		delete aux;
	}
}

void mostrar (Nodo* p) {
	Nodo* aux = p;
	while(aux != NULL) {
		cout << aux->info << endl;
		aux = aux->sig;
	}
}

void agregarNodo(Nodo* & p, int x) {
	Nodo* nuevo = new Nodo();
	nuevo->info = x;
	nuevo->sig = NULL;
	if(p==NULL) { // la lista p esta vac�a
		p = nuevo;
	} else {
		Nodo* aux = p;
		while(aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}

}
