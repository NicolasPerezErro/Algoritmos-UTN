#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Nodo{
int info;
Nodo* sig;
};

struct NodoInv { // colas
    char info;
    NodoInv* sig;
};

// lista
void agregarNodo(Nodo* &p, int x);
void mostrar (Nodo* p);
void liberar(Nodo* &p);
Nodo* buscar(Nodo* p, int v);
void eliminar(Nodo*&p, int v);
int eliminarPrimerNodo(Nodo*&p);
Nodo* insertarOrdenado(Nodo*&p, int v);

// pila
void push(Nodo* &pila, int x);
int pop(Nodo* &pila);

// cola
void encolar(NodoInv* & cFte, NodoInv* & cFin, char v);
int desencolar(NodoInv* &cFte, NodoInv* & cFin);

//--------------------------------------------------------------

// EJERCICIO 1
struct turnos{ // ARCHIVO
int hora;
char pacientes[50];
};

struct Nodo2{
turnos info;
Nodo2* sig;
};

// EJERCICIO 2
struct NodoP{
char info;
NodoP* sig;
};

// 4

struct ventas{ // ARCHIVO
int nroCliente;
char articulo[50];
int cantComprada;
float precioUnitario;
};

struct infoArt{
char nombreArt[50];
int cantCompradaArt;
float precioUArt;
};

struct articulos{
infoArt infoA;
articulos* sig;
};

struct infoCliente{
int numeroCliente;
float dineroGastado;
articulos* listaArt;
};

struct cliente{
infoCliente infoC;
cliente* sig;
};

// EJERCICIO 2

void UnionDeListas(Nodo* &p, Nodo* &q, Nodo* &c);
void agregarNodo2(Nodo2* &p, int x);

// EJERCICIO 3
char popP(NodoP*& p);
void pushP(NodoP*& p, char v);


int main()
{

// EJERCICIO 1

/*
FILE * archivo = fopen("turnos20201031.dat","rb");
turnos reg;
fread(&reg,sizeof(turnos),1,archivo);
Nodo2* p = NULL; // LISTA


while (!feof(archivo)){

p->info.hora = reg.hora;
p->info.pacientes = reg.pacientes;

insertarOrdenado(p,reg); // INSERTO ORDENADO POR HORA

fread(&reg,sizeof(turnos),1,archivo);
}
fclose(archivo);

Nodo2* cFte = NULL;
Nodo2* cFin = NULL;

while (p != NULL){

    encolar(cFte,cFin,eliminarPrimerNodo(p));
}
*/


// EJERCICIO 2
/*
Nodo* p = NULL;
Nodo* q = NULL;
Nodo* c = NULL;

agregarNodo2(p,2);
agregarNodo2(p,5);
agregarNodo2(p,7);
agregarNodo2(p,1);
agregarNodo2(q,8);
agregarNodo2(q,0);
agregarNodo2(q,9);
agregarNodo2(q,5);

UnionDeListas(p,q,c);

while (c != NULL){

    cout << eliminarPrimerNodo(c) << endl;
}
*/

// EJERCICIO 3
/*
char caracter;
NodoP* pila = NULL;
cout << "introduce caracter:";
cin >> caracter;

while (caracter != '.'){

if (caracter >= 65 && caracter <= 90){

    pushP(pila,caracter);

    } else if(caracter=='*'){

cout << popP(pila) << endl;
    }

cout << "introduce caracter:";
cin >> caracter;

}

cout << "Resto de la pila " << endl;
while (pila != NULL){
        cout << popP(pila) << endl;
}
*/

// EJERCICIO 4
/*
FILE * archivo = fopen("ventas.dat","rb");
ventas reg;
fread(&reg,sizeof(ventas),1,archivo);
cliente* listaCliente = NULL;
cliente* clienteBuscado;
articulos* articuloBuscado;
infoCliente infoC;
infoArt infoA;

while (!feof(archivo)){

infoC.numeroCliente = reg.nroCliente;
infoC.listaArt = NULL;
infoC.dineroGastado = 0;

clienteBuscado = buscaEInsertaCliente(listaCliente,infoC,enc); // SI NO LO ENCUENTRA EN LA LISTA LO AGREGA, SI LO ENCUENTRA NO HACE NADA

infoA.cantCompradaArt = reg.cantComprada;
infoA.precioUArt = reg.precioUnitario;
strcpy(infoA.nombreArt,reg.articulo);

articuloBuscado = buscaEInsertaArticulo(clienteBuscado->infoC.listaArt,infoA,enc);

if (enc==true){ // SI ESTA REPETIDO
articuloBuscado->infoA.cantCompradaArt += infoA.cantComprada;
listaCliente->infoC.dineroGastado = (infoA.precioUnitario*infoA.cantComprada); // SI SE REPITE TENGO QUE OPERAR CON EL PRECIO REPETIDO
}



fread(&reg,sizeof(ventas),1,archivo);
}
fclose(archivo);


cliente* auxCliente = listaCliente;
articulos* auxArt;

int clienteQueMenosGasto = 0;
int menor = 9999999;

int clienteMayorCantidadComprada = 0;
int mayorCantComprada = 0;
int mayor = 0;

while (auxCliente != NULL){
    auxArt = auxCliente->infoC.listaArt;

    while (auxArt != NULL){

        mayorCantComprada += auxArt->infoA.cantCompradaArt;

        auxArt = auxArt->sig;
    }

    if (auxCliente->infoC.dineroGastado < menor){
        menor = auxCliente->infoC.dineroGastado;
        clienteQueMenosGasto = auxCliente->infoC.numeroCliente;
        }

    if (mayorCantComprada > mayor){
        mayor = mayorCantComprada;
        clienteMayorCantidadComprada = auxCliente->infoC.numeroCliente;
    }

       auxCliente = auxCliente->sig;
}

cout << "El cliente que menos dinero gasto fue: " << clienteQueMenosGasto << endl;
cout << "El cliente con la mayor cantidad de unidades compradas fue: " << clienteMayorCantidadComprada << endl;
*/

    return 0;
}
/*
void UnionDeListas(Nodo* &p, Nodo* &q, Nodo* &c){

Nodo* auxP = p;

while (auxP != NULL){

agregarNodo(c,auxP->info);

}

Nodo* auxQ = q;

while (auxQ!= NULL){

buscaEInserta(c,auxQ->info,enc);
auxQ = auxQ->sig;

    }
}
*/





//--------------------------------------------------------------------------------------------
/*
void agregarNodo2(Nodo2* &p, int x) { // LE PASO LA LISTA Y UN VALOR INT
	Nodo2* nuevo = new Nodo2();     // RESERVO UN ESPACIO PARA UNA VARIABLE DE TIPO NODO
	nuevo->info = x;              // LO QUE VA A TENER ADENTRO EL NODO
	nuevo->sig = NULL;            // EL SIGUIENTE DE NUEVO ES NULL SIEMPRE (ES EL ULTIMO)
	if(p==NULL) { // SI LA LISTA p ESTA VACIA
		p = nuevo; // ES DECIR QUE LE ASIGNO A LA LISTA UN NUEVO (NODO)
	} else {
		Nodo2* aux = p;            // NODO AUXILIAR QUE LE ASIGNO EL VALOR DE LA LISTA
		while(aux->sig != NULL) {
			aux = aux->sig;         // ESO ES PARA AVANZAR
		}
		aux->sig = nuevo;           // ENGANCHAR EL NUEVO NODO
	}

}
*/
/*
Curso* buscaEInsertaNodo(Nodo2* &p, infocurso v, bool & enc){
	Curso * nodoBuscado = buscarCurso(p,v);
	if(nodoBuscado != NULL) { // el nodo est� en la lista
		enc = true;
	} else { // el nodo no est�
		nodoBuscado = agregarCurso(p,v);
		enc = false;
	}

	return nodoBuscado;
}
*/

char popP(NodoP*& p) {
	char retorno = p->info;
	NodoP* aux = p;
	p = aux->sig;
	delete aux;
	return retorno;
}

void pushP(NodoP*& p, char v){
	NodoP* nuevo = new NodoP();
	nuevo->info = v;
	nuevo->sig = p;
	p = nuevo;
}
