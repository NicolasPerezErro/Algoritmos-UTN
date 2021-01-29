#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct est{ // ARCHIVO
int legajo;
char nya[50];
int curso;
};

struct infoEst{
est infoE;
};

struct NodoEstudiante{
infoEst info;
NodoEstudiante* sig;
};

void mostrar (NodoEstudiante* p);
void agregarNodo(NodoEstudiante* &p, est x);
void push(NodoEstudiante*& p, est v);
infoEst eliminarPrimerNodo(NodoEstudiante*&p);
est pop(NodoEstudiante*& p);
NodoEstudiante* insertarOrdenado(NodoEstudiante*&p, infoEst v);

// 02/09
int cantidadNodos(NodoEstudiante* &p);
void unionListas(NodoEstudiante* &p, NodoEstudiante* &l, NodoEstudiante* &c);
void imprimirLista(NodoEstudiante* &p);
void apareoListas(NodoEstudiante* &p , NodoEstudiante* &l, NodoEstudiante* &c);

int main()
{
/*
NodoEstudiante * listaA = NULL;

est aux;

aux.curso = 5;
aux.legajo = 53535;
strcpy(aux.nya,"pepe");
agregarNodo(listaA,aux);

aux.curso = 7;
aux.legajo = 54532;
strcpy(aux.nya,"matu");
agregarNodo(listaA,aux);

aux.curso = 10;
aux.legajo = 54632;
strcpy(aux.nya,"clara");
agregarNodo(listaA,aux);

// EJ 1
int cantidad = cantidadNodos(listaA);

cout << "Cantidad de nodos de la lista: " << cantidad << endl;

NodoEstudiante* listaB = NULL;

aux.curso = 8;
aux.legajo = 22235;
strcpy(aux.nya,"juan");
agregarNodo(listaB,aux);

aux.curso = 0;
aux.legajo = 54555;
strcpy(aux.nya,"jeni");
agregarNodo(listaB,aux);

aux.curso = 22;
aux.legajo = 75632;
strcpy(aux.nya,"marta");
agregarNodo(listaB,aux);

NodoEstudiante* listaC = NULL;

// EJ 2
// unionListas(listaA,listaB,listaC);
// mostrar(listaC);

// EJ 3
imprimirLista(listaA);

// EJ 4
//apareoListas(listaA,listaB,listaC);
//mostrar(listaC);

*/
// EJ 5

est registro;

FILE * Archa = fopen("archa.dat","rb");
fread (&registro,sizeof(est),1,Archa);


NodoEstudiante* listaOrdenar = NULL;
infoEst regEst;

while (!feof(Archa)){

    regEst.infoE.curso = registro.curso;
    regEst.infoE.legajo = registro.legajo;
    strcpy(regEst.infoE.nya, registro.nya);

    insertarOrdenado(listaOrdenar,regEst);

    fread (&registro,sizeof(est),1,Archa);
}

fclose(Archa);

FILE * Archal = fopen("archaL.dat","wb+");
NodoEstudiante* aux22 = listaOrdenar;

while (aux22 != NULL){

    fwrite(&aux22->info,sizeof(est),1,Archal);
    aux22 = aux22->sig;
}

rewind(Archal);
fread (&registro,sizeof(est),1,Archal); // LO GRABA CON LA MISMA ESTRUCTURA POR USAR LOS MISMOS PARAMETROS

while (!feof(Archal)){

    cout << registro.legajo << endl;
    cout << registro.nya << endl;
    cout << registro.curso << endl;
    cout << ".-.-..-..-.-" << endl;


 fread (&registro,sizeof(est),1,Archal);
}

fclose(Archal);



    return 0;
}

/*
void apareoListas(NodoEstudiante* &p , NodoEstudiante* &l, NodoEstudiante* &c){

    while(p != NULL && l != NULL){

        if(p->info.legajo < l->info.legajo){

            agregarNodo(c,eliminarPrimerNodo(p));
        }else{

            agregarNodo(c,eliminarPrimerNodo(l));
            }
    }

    while (p != NULL){

        agregarNodo(c,eliminarPrimerNodo(p));
    }

    while (l != NULL){

        agregarNodo(c,eliminarPrimerNodo(l));
    }

}

void imprimirLista(NodoEstudiante* &p){
NodoEstudiante* aux = p;
NodoEstudiante* pila = NULL;
int cantidad = cantidadNodos(p);
est aux1;

    if (cantidad > 100){

        mostrar(p);
    } else{
        while (p != NULL){
        push(pila,eliminarPrimerNodo(p));
        }
    }

    while (pila != NULL){
        agregarNodo(p,pop(pila));
    }
    mostrar(p);


}

void unionListas(NodoEstudiante* &p, NodoEstudiante* &l, NodoEstudiante* &c){

NodoEstudiante* pAux = p;
NodoEstudiante* lAux = l;

while (pAux != NULL){

agregarNodo(c,pAux->info);
pAux = pAux->sig;
}

while (lAux != NULL){

agregarNodo(c,lAux->info);
lAux = lAux->sig;
}


}

int cantidadNodos(NodoEstudiante* &p){

NodoEstudiante* aux = p;
int cantidad = 0;

while (aux != NULL){

cantidad++;
aux = aux->sig;
}

return cantidad;

}

void agregarNodo(NodoEstudiante* & p, est x) {
	NodoEstudiante* nuevo = new NodoEstudiante();
	nuevo->info = x;
	nuevo->sig = NULL;
	if(p==NULL) { // la lista p esta vacía
		p = nuevo;
	} else {
		NodoEstudiante* aux = p;
		while(aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}

}

void mostrar (NodoEstudiante* p) {
	NodoEstudiante* aux = p;
	while(aux != NULL) {            // ES AUX Y NO AUX SIGUIENTE PORQUE PRIMERO PREGUNTA POR EL PRIMER NODO
		cout << "Curso: " << aux->info.curso << endl;
        cout << "Nombre: " << aux->info.nya << endl;
        cout << "Legajo: " << aux->info.legajo << endl;
        cout << "---------------" << endl;
		aux = aux->sig;             // AVANZAR
	}
}

est pop(NodoEstudiante*& p) {
	est retorno = p->info;
	NodoEstudiante* aux = p;
	p = aux->sig;
	delete aux;
	return retorno;
}

void push(NodoEstudiante*& p, est v){
	NodoEstudiante* nuevo = new NodoEstudiante();
	nuevo->info = v;
	nuevo->sig = p;
	p = nuevo;
}
*/
infoEst eliminarPrimerNodo(NodoEstudiante* &p) {
	infoEst retorno = p->info;
	NodoEstudiante* aux = p;
	p = p->sig;
	delete aux;
	return retorno;
}

NodoEstudiante* insertarOrdenado(NodoEstudiante* &p, infoEst v){
	NodoEstudiante* nuevo = new NodoEstudiante();
	nuevo->info = v;
	nuevo->sig = NULL;
	NodoEstudiante* ant = NULL;
	NodoEstudiante* aux = p;

	while(aux!=NULL && aux->info.infoE.legajo <= v.infoE.legajo) {
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
