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

//ej 3





// colas
void encolar(NodoInv* & cFte, NodoInv* & cFin, char v);
char desencolar(NodoInv* &cFte, NodoInv* & cFin);

// listas
void agregarNodo(Nodo* &p, int x);
void mostrar (Nodo* p);
Nodo* buscar(Nodo* p, int v);
int eliminarPrimerNodo(Nodo*&p);
Nodo* insertarOrdenado(Nodo*&p, int v);
Nodo* buscaEInsertaOrdenado(Nodo* &p, int v, bool & enc);

//pilas
void push(NodoInv*& p, char v);
int pop(NodoInv*& p);

//09/09

bool secuencia(char vec[],int len);
int polacaInversa(char vec[],int len);
void pushUsandoArray(char vec[],int &len,char valor);
char popUsandoArray(char vec[],int& len);
void pushUsandoCola(NodoInv* &cfte, NodoInv* &cfin,char v);
char popUsandoCola(NodoInv* &cfte, NodoInv* &cfin);


int main()
{

//ej 1
/*
char vec[50] = {'{','[','(',')',']','}'};
int len = 6;

bool resul = secuencia(vec,len);

if (resul == true){

    cout << "Esta balanceada " << endl;
} else {
    cout << "No esta balanceada" << endl;
}
*/

// ej 2

char vec2[50] = {'5','1','2','+','4','*','+','3','-'};
int len2 = 9;

cout << "Resultado: " << polacaInversa(vec2,len2) << endl;

// ej 3

char vec3[50];
int len3 = 0;

pushUsandoArray(vec3,len3,'C');
pushUsandoArray(vec3,len3,'D');
pushUsandoArray(vec3,len3,'T');
pushUsandoArray(vec3,len3,'F');
pushUsandoArray(vec3,len3,'N');
/*
for (int i = 0; i < len3; i++){

    cout << vec3[i] << endl;
}
*/
// cout << popUsandoArray(vec3,len3) << endl;

NodoInv* cfte = NULL;
NodoInv* cfin = NULL;

pushUsandoCola(cfte,cfin,'C');
pushUsandoCola(cfte,cfin,'D');
pushUsandoCola(cfte,cfin,'T');
pushUsandoCola(cfte,cfin,'F');
pushUsandoCola(cfte,cfin,'N');

cout << popUsandoCola(cfte,cfin) << endl;
cout << popUsandoCola(cfte,cfin) << endl;
cout << popUsandoCola(cfte,cfin) << endl;
cout << popUsandoCola(cfte,cfin) << endl;
cout << popUsandoCola(cfte,cfin) << endl;


    return 0;
}

char popUsandoCola(NodoInv* &cfte, NodoInv* &cfin){
    return desencolar(cfte,cfin);
}

void pushUsandoCola(NodoInv* &cfte, NodoInv* &cfin,char v){ // LA IDEA ES AGREGAR UN VALOR A UNA COLA Y AGREGAR LOS OTROS VALORES DE LA OTRA COLA
// PRIMERO VALOR Y DESPUES PILA QUE LOS DEJA ARRIBA
NodoInv* cfte2 = NULL;
NodoInv* cfin2 = NULL;

encolar(cfte2,cfin2,v);

    while (cfte != NULL){

    encolar(cfte2,cfin2,desencolar(cfte,cfin));
    }
    cfte = cfte2; // REASIGNO PUNTEROS PARA LUEGO PODER HACER EL POP CON LA COLA ORIGINAL
    cfin = cfin2;
}

char popUsandoArray(char vec[],int& len){

char ret = vec[0];

    for (int i = 0; i < len; i++){

    vec[i] = vec[i+1]; // MUEVO TODO PARA LA IZQUIERDA Y LO PISO

    }
len--;
return ret;
}

void pushUsandoArray(char vec[],int &len, char valor){

    for (int i = len-1; i >= 0; i--){

    vec[i+1] = vec[i]; // LO VOY MOVIENDO PARA LA DERECHA

    }

vec[0] = valor; // LO MUEVO PARA LA DERECHA y PONGO EL PRIMER VALOR
len++;

}


int polacaInversa(char vec[],int len){

NodoInv* pila = NULL;
int resultado = 0;

for (int i = 0; i < len; i++){

    switch(vec[i]){

        case '+': push(pila, pop(pila) + pop(pila)); break;
        case '*': push(pila, pop(pila) * pop(pila)); break;
        case '-': push(pila, pop(pila) - pop(pila)); break;
        default: push(pila,vec[i]-'0'); break;
    }

}

resultado = pop(pila);

return resultado;
}


bool secuencia(char vec[],int len){

NodoInv* pila = NULL;
bool resultado = true;

for (int i = 0; i < len; i++){

        switch (vec[i]){

        case '{':
        case '[':
        case '(':
        push(pila,vec[i]);
        break;
        case '}':
            if (pop(pila) != '{'){resultado = false;} break;
        case ']':
            if (pop(pila) != '['){resultado = false;} break;
        case ')':
            if (pop(pila) != '('){resultado = false;} break;
        }

    }

return resultado;

}




char desencolar(NodoInv* &cFte, NodoInv* & cFin){
	char retorno = cFte->info;
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

void push(NodoInv*& p, char v){
	NodoInv* nuevo = new NodoInv();
	nuevo->info = v;
	nuevo->sig = p;
	p = nuevo;
}
