#include <iostream>
#include <string.h>

using namespace std;

struct Nodo {
    int info;
    Nodo* sig;
};

struct NodoInv {
    char info[50];
    NodoInv* sig;
};

struct NodoApellidos{
    string nya;
    NodoApellidos* sig;
};

struct NodoOrdenar{
int info;
NodoOrdenar* sig;
};

void push(NodoInv*& p, char v);
int pop(NodoInv*& p);

void push1(NodoApellidos*& p, string v);
string pop1(NodoApellidos*& p);

void encolar(NodoInv* & cFte, NodoInv* & cFin, char v);
int desencolar(NodoInv* &cFte, NodoInv* & cFin);
//void eliminarLosDosPrimeros(Nodo* &pila, int x);
//void colocarEnTercerLugar(Nodo* &pila , int x, char& exitoso);
//void colocarEnPosicionYLugar(Nodo* &pila , int x, int y, char& exitoso);
//void reemplazarXporY(Nodo* &pila , int x, int y);
bool inversa(NodoInv* &colaFte, NodoInv* &colaFin);
void imprimirEstudiantes(NodoApellidos* &pila);
void ordenarPila(NodoOrdenar* &p);
Nodo* insertarOrdenado(NodoOrdenar*&p, int v); // FUNCION DE LISTA

int main()
{
//Pilas - Ejercicio 1
	/*Nodo * pila = NULL;
	push(pila,90);
	push(pila,100);
	push(pila,1);

	int x;
	cout << "Ingrese el valor X" << endl;
	cin >> x;

	eliminarLosDosPrimeros(pila, x);

	while(pila != NULL){
		cout << pop(pila) << endl;
	}
	*/

	/*
	//Pilas - Ejercicio 2
	Nodo * pila = NULL;
	push(pila,90);


	int x;
	cout << "Ingrese el valor X" << endl;
	cin >> x;

	char exitoso;
	colocarEnTercerLugar(pila,x,exitoso);

	if(exitoso == 'S') {
		cout << "Se pudo realizar el req" << endl;
	} else {
		cout << "No se pudo realizar el req" << endl;
	}

	while(pila != NULL){
		cout << pop(pila) << endl;
	}
	*/

	/*
	//Pilas - Ejericio 3
	Nodo * pila = NULL;
	push(pila,90);
	push(pila,100);
	push(pila,4);
	push(pila,1);

	int x;
	cout << "Ingrese el valor X" << endl;
	cin >> x;

	int y;
	cout << "Para reemplazar en la posicion Y" << endl;
	cin >> y;

	char exitoso;
	colocarEnPosicionYLugar(pila , x, y,exitoso);

	if(exitoso == 'S') {
		cout << "Se pudo realizar el req" << endl;
	} else {
		cout << "No se pudo realizar el req" << endl;
	}

	while(pila != NULL){
		cout << pop(pila) << endl;
	}
	*/

	/*
	//Pilas - Ejercicio 4
	Nodo * pila = NULL;
	push(pila,1);
	push(pila,100);
	push(pila,4);
	push(pila,1);
	push(pila,1);
	push(pila,200);

	int x;
	cout << "Ingrese el valor X" << endl;
	cin >> x;

	int y;
	cout << "Para reemplazar por valor Y" << endl;
	cin >> y;

	reemplazarXporY(pila , x, y);

	while(pila != NULL){
		cout << pop(pila) << endl;
	}
	*/

	//Pilas - Ejercicio 5
	/*NodoInv* colaFte = NULL;
	NodoInv* colaFin = NULL;

	char c;
	cout << "Ingrese el caracter" << endl;
	cin >> c;

	while (c != '0') {
		encolar(colaFte,colaFin,c);
		cout << "Ingrese el caracter" << endl;
		cin >> c;
	}

	bool esInversa = inversa(colaFte,colaFin);

	if(esInversa){
		cout << "Los caracteres son inversos" << endl;
	} else {
		cout << "Los caracteres no son inversos" << endl;
	}*/

	// Ej. 6

	NodoApellidos * pila = NULL;
	string apellido;



    imprimirEstudiantes(pila);

    return 0;
}

void ordenarPila(NodoOrdenar* &p){

NodoOrdenar* lista = NULL;

while (p!= NULL){
    insertarOrdenado(lista,pop(p));
    }

while (lista != NULL){

    push(pila,eliminarPrimerNodo(lista)); // INGRESA LOS VALORES ORDENADOS DENTRO DE LA PILA Y ELIMINA LOS NODOS DE LISTA

    }

}

void imprimirEstudiantes(NodoApellidos* &pila){

string apellido;

cout << "Ingrese Apellido: ";
cin >> apellido;

    while (apellido != "X"){

    push1(pila,apellido);
    cout << "Para terminar presione X" << endl;
    cout << "Ingrese Apellido: ";
    cin >> apellido;
    }

     while (pila != NULL){
        cout << pop1(pila) << endl;
        }
}

/*bool inversa(NodoInv* &colaFte, NodoInv* &colaFin) {
	bool retorno = true;
	NodoInv* pila = NULL;
	while(colaFte->info != '.') {
		push(pila, desencolar(colaFte,colaFin));
	}
	desencolar(colaFte, colaFin); // PARA SACAR EL PUNTO

	while(colaFte != NULL) {
		if(desencolar(colaFte, colaFin) != pop(pila)){
			retorno = false;
			break;
		}
	}

	return retorno;
}
*/

/*
void reemplazarXporY(Nodo* &pila , int x, int y) {
	Nodo * pilaAux = NULL;
	int valor;
	while(pila != NULL){
		valor = pop(pila);
		if(valor == x){
			valor = y;
		}
		push(pilaAux,valor);
	}

	while(pilaAux != NULL) {
		push(pila,pop(pilaAux));
	}

}

void colocarEnPosicionYLugar(Nodo* &pila , int x, int y, char& exitoso){
	Nodo * pilaAux = NULL;
	int i = 0;
	while(pila != NULL && i < (y-1)) {
		push(pilaAux,pop(pila));
		i++;
	}

	if(i == (y-1)) {
		exitoso = 'S';
		push(pila,x);
	} else {
		exitoso = 'N';
	}

	while(pilaAux != NULL){
		push(pila,pop(pilaAux));
	}
}

void colocarEnTercerLugar(Nodo* &pila , int x, char& exitoso){
	Nodo * pilaAux = NULL;
	int i = 0;
	while(pila != NULL && i < 2) {
		push(pilaAux,pop(pila));
		i++;
	}

	if(i == 2) {
		exitoso = 'S';
		push(pila,x);
	} else {
		exitoso = 'N';
	}

	while(pilaAux != NULL){
		push(pila,pop(pilaAux));
	}

}

void eliminarLosDosPrimeros(Nodo* &pila, int x) {

	for(int i = 0; i < 2; i++){
		pop(pila);
	}

	push(pila, x);
}
*/
/*
int desencolar(NodoInv* &cFte, NodoInv* & cFin){
	int retorno = cFte->info;
	NodoInv* aux =  cFte;
	cFte = aux->sig;
	if(cFte == NULL) {
		cFin = NULL;
	}
	delete aux;
	return retorno;
}

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
/*
int pop(NodoInv*& p) {
	int retorno = p->info;
	NodoInv* aux = p;
	p = aux->sig;
	delete aux;
	return retorno;
}

void push(NodoInv*& p, char v){
	NodoInv* nuevo = new NodoInv();
	nuevo->info = v;
	nuevo->sig = p;
	p = nuevo;
}
*/

void push1(NodoApellidos*& p, string v){
NodoApellidos* nuevo = new NodoApellidos();
	nuevo->nya = v;
	nuevo->sig = p;
	p = nuevo;
}

string pop1(NodoApellidos*& p){

string retorno = p->nya;
	NodoApellidos* aux = p;
	p = aux->sig;
	delete aux;
	return retorno;


}

Nodo* insertarOrdenado(NodoOrdenar*&p, int v){
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
