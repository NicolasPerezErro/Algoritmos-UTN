#include <iostream>

using namespace std;

struct Nodo {
    int info;
    Nodo* sig;
};

struct NodoInv {
    char info;
    NodoInv* sig;
};


struct est{
int legajo;
char nya[50];
int curso;
};

struct NodoEstudiante{
est info;
NodoEstudiante* sig;
};

void encolar(NodoInv* & cFte, NodoInv* & cFin, char v);
int desencolar(NodoInv* &cFte, NodoInv* & cFin);
char eliminarXNodos(Nodo* &cfte,Nodo* &cfin, int x);
int cantNodos(NodoEstudiante* &cfte, NodoEstudiante* &cfin);
void unirColas(NodoEstudiante* &cfte1,NodoEstudiante* &cfin1,NodoEstudiante* &cfte2,NodoEstudiante* &cfin2, NodoEstudiante* &cfte3,NodoEstudiante* &cfin3);
void imprimirCola(NodoEstudiante* &cfte,NodoEstudiante* &cfin1);
void apareoColas(NodoEstudiante* &cfte1,NodoEstudiante* &cfin1,NodoEstudiante* &cfte2,NodoEstudiante* &cfin2, NodoEstudiante* &cfte3,NodoEstudiante* &cfin3);

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

void apareoColas(NodoEstudiante* &cfte1,NodoEstudiante* &cfin1,NodoEstudiante* &cfte2,NodoEstudiante* &cfin2, NodoEstudiante* &cfte3,NodoEstudiante* &cfin3){

    while (cfte1 != NULL && cfte2 != NULL){

    if (cfte1->info.legajo < cfte2->info.legajo){
        encolar(cfte3,cfin3,desencolar(cfte1,cfin1));
        } else{
        encolar(cfte3,cfin3,desencolar(cfte2,cfin2));
        }
    }

    while (cfte1 != NULL){
    encolar(cfte3,cfin3,desencolar(cfte1,cfin1));
    }
    while (cfte2 != NULL){
    encolar(cfte3,cfin3,desencolar(cfte2,cfin2));
    }
}

void imprimirCola(NodoEstudiante* &cfte,NodoEstudiante* &cfin){

int cNodos = cantNodos(cfte,cfin);
NodoEstudiante* pila = NULL;
est aux; // AL SER DE TIPO ESTRUCTURA SE TIENE QUE IGUALAR UNA VARIABLE AL DESENCOLAR PARA DESPUES IMPRIMIR CADA CAMPO

if (cNodos > 100){
        while (cfte != NULL){
            aux = desencolar(cfte,cfin);
            cout << aux.curso << endl;
            cout << aux.nya << endl;
            cout << aux.legajo << endl;
            }
    } else{
        while (cfte != NULL){
            push(pila,desencolar(cfte,cfin)) << endl;
            }
        while (pila != NULL){
            aux = pop(pila);
            cout << aux.curso << endl;
            cout << aux.nya << endl;
            cout << aux.legajo << endl;
            }
    }

}


void unirColas(NodoEstudiante* &cfte1,NodoEstudiante* &cfin1,NodoEstudiante* &cfte2,NodoEstudiante* &cfin2, NodoEstudiante* &cfte3,NodoEstudiante* &cfin3){

    while (cfte1 != NULL){
    encolar(cfte3,cfin3,desencolar(cfte1,cfin1))
    }

    while (cfte2 != NULL){

    encolar(cfte3,cfin3,desencolar(cfte2,cfin2))
    }

}

int cantNodos(NodoEstudiante* &cfte, NodoEstudiante* &cfin){

Nodo* lista = NULL;
int contador = 0;

while (cfte != NULL){

    agregarNodo(lista,desencolar(cfte,cfin)));
    contador++;
    }

while (lista != NULL){

    encolar(cfte,cfin,eliminarPrimerNodo(lista));
    }

return contador;
}


char eliminarXNodos(Nodo* &cfte,Nodo* &cfin, int x){ // FIJARME SI ESTA BIEN

int contador = 0;
char resultado[50];

while (cfte != NULL && contador < x){
desencolar(cfte,cfin);
contador++;
}

if (contador == x){
    resultado = 'S';
} else{
    resultado = 'N';
}

return resultado;

}

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
