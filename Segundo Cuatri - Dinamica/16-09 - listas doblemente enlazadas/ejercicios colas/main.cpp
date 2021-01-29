#include <iostream>

using namespace std;

struct Nodo {
    int info;
    Nodo* sig;
};

struct NodoInv {
    int info;
    NodoInv* sig;
};

// colas
void encolar(NodoInv* & cFte, NodoInv* & cFin, char v);
int desencolar(NodoInv* &cFte, NodoInv* & cFin);

// listas
void agregarNodo(Nodo* &p, int x);
void mostrar (Nodo* p);
Nodo* buscar(Nodo* p, int v);
int eliminarPrimerNodo(Nodo*&p);
Nodo* insertarOrdenado(Nodo*&p, int v);
Nodo* buscaEInsertaOrdenado(Nodo* &p, int v, bool & enc);

//pilas
void push(NodoInv*& p, int v);
int pop(NodoInv*& p);


//16-09

void encolarUsandoLista(Nodo* &p, int x);
int desencolarUsandoLista(Nodo* &p);

void encolarUsandoArray(int vec[],int n,int& len, int x);
int desencolarUsandoArray(int vec[],int &len);

void encolarUsandoPila(NodoInv*&p, int x);
int desencolarUsandoPila(NodoInv*&p);

int main()
{

int vec[10];
int len = 0;

Nodo* lista = NULL;

/* EJ 1
encolarUsandoLista(lista,5);
encolarUsandoLista(lista,1);
encolarUsandoLista(lista,7);

cout << desencolarUsandoLista(lista) << endl;
cout << desencolarUsandoLista(lista) << endl;
cout << desencolarUsandoLista(lista) << endl;
*/

//EJ 2
/*
encolarUsandoArray(vec,10,len,1);
encolarUsandoArray(vec,10,len,5);
encolarUsandoArray(vec,10,len,8);
encolarUsandoArray(vec,10,len,10);
encolarUsandoArray(vec,10,len,4);

cout << desencolarUsandoArray(vec,len) << endl;
cout << desencolarUsandoArray(vec,len) << endl;
cout << desencolarUsandoArray(vec,len) << endl;
cout << desencolarUsandoArray(vec,len) << endl;
*/

NodoInv* pila = NULL;

encolarUsandoPila(pila,5);
encolarUsandoPila(pila,10);
encolarUsandoPila(pila,4);
encolarUsandoPila(pila,3);

cout << desencolarUsandoPila(pila) << endl;
cout << desencolarUsandoPila(pila) << endl;
cout << desencolarUsandoPila(pila) << endl;
cout << desencolarUsandoPila(pila) << endl;


    return 0;
}

void encolarUsandoPila(NodoInv*&p,int v){ // ENCOLAR DEJA EL VALOR PRIMERO Y LUEGO LOS DEMAS VALORES, ENTONCES METO LOS VALORES DE LA PILA Y DESPUES EL VALOR
// TENGO LOS NUMEROS EN UNA PILA, LOS PASO A OTRA PILA(SE DAN VUELTA Y AGREGO EL VALOR)
    NodoInv* pilaAux = NULL;

    while (p != NULL){

      push(pilaAux,pop(p));
    }

    push(pilaAux,v);

    while (pilaAux != NULL){ // LO VUELVO A METER EN LA PILA ORIGINAL

        push(p,pop(pilaAux));
    }

}

int desencolarUsandoPila(NodoInv*&p){

return pop(p);

}

void encolarUsandoArray(int vec[],int n,int& len, int x){

    if (len < n){

        vec[len] = x;
        len++;
    }

}

int desencolarUsandoArray(int vec[],int& len){

int valor = vec[0];

    for (int i = 0; i < len; i++){

        vec[i] = vec[i+1];

    }

    len--;
    return valor;
}

void encolarUsandoLista(Nodo* &p, int x){

    agregarNodo(p,x);

}

int desencolarUsandoLista(Nodo* &p){

return eliminarPrimerNodo(p);

}


/*int desencolar(NodoInv* &cFte, NodoInv* & cFin){
	int retorno = cFte->info;
	NodoInv* aux =  cFte;
	cFte = aux->sig;
	if(cFte == NULL) {
		cFin = NULL;
	}
	delete aux;
	return retorno;
}
*/
/*
void encolar(NodoInv* & cFte, NodoInv* & cFin, char v){
	NodoInv * nuevo = new NodoInv();
	nuevo->info = v;
	nuevo->sig = NULL;
	if(cFte == NULL) {
		cFte = nuevo;
	} else {
		cFin->sig = nuevo;
	}
	cFin = nuevo;
}
*/

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


Nodo* buscar(Nodo* p, int v) {
	Nodo* aux = p;                          // PUNTERO A LA DIRECCION DE MEMORIA DE LA LISTA
	while(aux!= NULL && aux->info != v){
		aux = aux->sig;                     // AVANZAMOS
	}
	return aux;                             // SI SALE DEL WHILE ES PORQUE LO ENCONTRO O ESTA VACIA. SI LO ENCUENTRA ME DEVUELVE AUX (DIRECC DE MEMORIA)
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
		p = nuevo;
	} else {
		Nodo* aux = p;
		while(aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
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

int pop(NodoInv*& p) {
	int retorno = p->info;
	NodoInv* aux = p;
	p = aux->sig;
	delete aux;
	return retorno;
}

void push(NodoInv*& p, int v){
	NodoInv* nuevo = new NodoInv();
	nuevo->info = v;
	nuevo->sig = p;
	p = nuevo;
}

