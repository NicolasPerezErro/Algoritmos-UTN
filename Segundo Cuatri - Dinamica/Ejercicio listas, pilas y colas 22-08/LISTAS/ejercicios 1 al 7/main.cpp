#include <iostream>
#include <stdio.h>
#include <string.h>

struct Nodo {
    int info; // ES LA INFORMACION QUE CONTIENE EL NODO
    Nodo* sig;
};

void agregarNodo(Nodo* &p, int x);
void mostrar (Nodo* p);
void liberar(Nodo* &p);
Nodo* buscar(Nodo* p, int v);
void eliminar(Nodo*&p, int v);
int eliminarPrimerNodo(Nodo*&p);
Nodo* insertarOrdenado(Nodo*&p, int v);

using namespace std;

int main()
{

/*

    int a = 10;
	//cout << &a << endl;       DIRECCION DE MEMORIA DE LA VARIABLE a
	int *p = &a;                PUNTERO A LA DIRECCION DE MEMORIA
	//cout << p << endl;        MUESTRA LA DIRECCION DE MEMORIA --- EL *p MUESTRA EL CONTENIDO DE LA VARIABLE

	int *l = new int();         // RESERVO UN ESPACIO DE MEMORIA PARA UNA VARIABLE DE TIPO INT
	*l = 10;                    // *L ME MUESTRA EL CONTENDIO DE LA VARIABLE ALMACENADA EN LA DIRECCION DE MEMORIA
	//cout << *l << endl;

	delete l;                   // BORRO EL CONTENIDO DE LA VARIABLE


	Nodo *lista = new Nodo();

	(*lista).info = 10;         // *lista ACCEDO A LO DE ADENTRO DEL NODO Y LE ASIGNO UN VALOR
	lista->info = 10;           //SIMPLIFICA LA NOTACION DE ARRIBA

	//cout << (*lista).info << endl; // 10
	//cout << lista->info << endl;   // 10 // QUE ES LO QUE TIENE EL NODO ADENTRO

  */



	Nodo* lista = NULL;
	insertarOrdenado(lista,0);
	insertarOrdenado(lista,10);
	insertarOrdenado(lista,11);
    insertarOrdenado(lista,20);
    insertarOrdenado(lista,50);
    insertarOrdenado(lista,4);
    insertarOrdenado(lista,1);
    insertarOrdenado(lista,100);
    insertarOrdenado(lista,2);
	Nodo* buscado;
	buscado = buscar(lista,4);

	if(buscado != NULL) {
		eliminar(lista,4);
	} else {
		cout << "El valor no se encuentra" << endl;
	}
	cout<< "El nro. del primer nodo es " << eliminarPrimerNodo(lista) << endl;
	mostrar(lista);
	liberar(lista);
	//cout << lista << endl;









    return 0;
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
	Nodo* aux = p;                          // PUNTERO A LA DIRECCION DE MEMORIA DE LA LISTA
	while(aux!= NULL && aux->info != v){
		aux = aux->sig;                     // AVANZAMOS
	}
	return aux;                             // SI SALE DEL WHILE ES PORQUE LO ENCONTRO O ESTA VACIA. SI LO ENCUENTRA ME DEVUELVE AUX (DIRECC DE MEMORIA)
}

void liberar(Nodo*&p){
	Nodo* aux;
	while(p!=NULL) {
		aux = p;
		p=p->sig;           // AVANZO CON P
		delete aux;         // ELMINIO NODOS CON AUX PORQUE TIENE LA MISMA DIRECCION QUE P
	}
}

void mostrar (Nodo* p) {
	Nodo* aux = p;
	while(aux != NULL) {            // ES AUX Y NO AUX SIGUIENTE PORQUE PRIMERO PREGUNTA POR EL PRIMER NODO
		cout << aux->info << endl;  // MOSTRAR EL CONTENIDO DEL NODO
		aux = aux->sig;             // AVANZAR
	}
}

void agregarNodo(Nodo* &p, int x) { // LE PASO LA LISTA Y UN VALOR INT
	Nodo* nuevo = new Nodo();     // RESERVO UN ESPACIO PARA UNA VARIABLE DE TIPO NODO
	nuevo->info = x;              // LO QUE VA A TENER ADENTRO EL NODO
	nuevo->sig = NULL;            // EL SIGUIENTE DE NUEVO ES NULL SIEMPRE (ES EL ULTIMO)
	if(p==NULL) { // SI LA LISTA p ESTA VACIA
		p = nuevo; // ES DECIR QUE LE ASIGNO A LA LISTA UN NUEVO (NODO)
	} else {
		Nodo* aux = p;            // NODO AUXILIAR QUE LE ASIGNO EL VALOR DE LA LISTA
		while(aux->sig != NULL) {
			aux = aux->sig;         // ESO ES PARA AVANZAR
		}
		aux->sig = nuevo;           // ENGANCHAR EL NUEVO NODO
	}

}
