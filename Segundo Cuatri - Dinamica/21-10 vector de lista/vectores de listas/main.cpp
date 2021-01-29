#include <iostream>
#include <stdio.h>
#include <string.h>

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

// 21-10 -----------------------------------------------------------

struct ventaAnual { // ARCHIVO
int idMes;
int idTicket;
char descProducto[50];
int cantVendida;
float precioUnitario;
};

struct infoProducto{
char descProducto[50];
int cantVendida;
float precioUnitario;
};

struct Producto{
infoProducto info;
Producto* sig;
};

struct infoTickets{
int nroTicket;
Producto* producto;
};

struct Tickets{
infoTickets info;
Tickets* sig;
};

/*struct vecMes{ SE PUEDE HACER??
Tickets* sig;
};
*/

Tickets* buscaEInsertaTicket(Tickets* &listaTicket,infoTickets v , bool enc);
Tickets* buscarTicket(Tickets* p, infoTickets v);
Tickets* agregarTicketOrdenado(Tickets* &p, infoTickets x);

Producto* buscaEInsertaProducto(Producto* &listaProducto,infoProducto v , bool enc);
Producto* buscarProducto(Tickets* p, infoProducto v);
Producto* agregarProducto(Producto* &p, infoProducto x);



int main()
{

FILE * archivo = fopen("ventas2018.dat","rb");

ventaAnual reg;
Tickets* vectorMes[12]; // VECTOR DE LISTA (ESTA ES LA LISTA)
Tickets* ticketDeInteres;
Producto* productoInsertado;

for (int i = 0; i < 12; i++){ // INICIALIZO LOS PUNTEROS EN NULL
    vectorMes[i] = NULL;
}


fread(&reg,sizeof(ventaAnual),1,archivo);

while (!feof(archivo)){

infoTickets regTicket;
int enc;
regTicket.nroTicket = reg.idTicket;
regTicket.producto = NULL;

ticketDeInteres = buscaEInsertaTicket(vectorMes[reg.idMes-1],regTicket,enc); // SI NO ESTA LO AGREGA Y SINO NO HACE NADA (NO DICE QUE NO SE REPITE EL TICKET)

infoProducto regProducto; // EL PRODUCTO NO HACE FALTA AGREGAR PORQUE NO ESTA REPETIDO (CONSIGNAS DEL EJ)

regProducto.cantVendida = reg.cantVendida;
strcpy(regProducto.descProducto,reg.descProducto);
regProducto.precioUnitario = reg.precioUnitario;

agregarProducto(ticketDeInteres->info.producto,regProducto); // EL PRODUCTO NO HACE FALTA NUSCAR PORQUE NO ESTA REPETIDO (CONSIGNAS DEL EJ)

 fread(&reg,sizeof(ventaAnual),1,archivo);
}
fclose(archivo);


Tickets* auxT;
Producto* auxP;
float PrecioTotalItem;
float montoTotalTicket;

// PARTE B
float ticketMayorMontoXMes;
int idTicketMayor;
int idTickeMenor;
float ticketMenorMontoXMes;
float montoTotalTicketXMes;

float importePromedioXMes;
int idTicketPromedio;
int cantTicketXMes;

float ticketMayorMontoXAnio = 0;
int idMesMayorXAnio = 0;
int idMesMenorXAnio = 9999999;
float ticketMenorMontoXAnio = 0;

float importePromedioXAnio = 0;
int cantTicketXAnio = 0;

for (int i = 0; i < 12; i++){ // COMO ES VECTOR DE LISTA USO FOR
    cout << "Mes: " << i+1 << endl;
    auxT = vectorMes[i]; // LE ASIGNO AL AUXT LA PRIMERA POSICION DEL VECTOR
     ticketMayorMontoXMes = 0;
     idTicketMayor = 0;
     idTickeMenor = 0;
     ticketMenorMontoXMes= 99999999999999;
     montoTotalTicketXMes = 0;
     importePromedioXMes = 0;
     idTicketPromedio = 0;
     cantTicketXMes = 0;
    // RECORRO LISTA DE TICKETS
    while(auxT != NULL){
    cout << "Ticket: " << auxT->info.nroTicket << endl; // IMPRIMO CADA TICKET
    montoTotalTicket = 0; // LO INICIALIZO ACA PORQUE ES POR TICKET
    auxP = auxT->info.producto;
    // RECORRO LISTA DE PRODUCTOS
    while (auxP != NULL){
    PrecioTotalItem = auxP->info.cantVendida * auxP->info.precioUnitario;
    cout << auxP->info.descProducto << " " << auxP->info.cantVendida << "unidades $ " << auxP->info.precioUnitario << " pu " << PrecioTotalItem << endl;
    montoTotalTicket += PrecioTotalItem;

    montoTotalTicketXMes += montoTotalTicket; // ESTA NO SE REINICIA

    auxP = auxP->sig;
        }

        if (montoTotalTicket > ticketMayorMontoXMes){
            ticketMayorMontoXMes = montoTotalTicket;
            idTicketMayor = auxT->info.nroTicket;
        }
         if (montoTotalTicket < ticketMenorMontoXMes){
            ticketMenorMontoXMes = montoTotalTicket;
            idTickeMenor = auxT->info.nroTicket;
        }

        if (montoTotalTicket > ticketMayorMontoXAnio){
            ticketMayorMontoXAnio = montoTotalTicket;
            idMesMayorXAnio = i+1;
        }
         if (montoTotalTicket < ticketMenorMontoXAnio){
            ticketMenorMontoXAnio = montoTotalTicket;
            idMesMenorXAnio = i+1;
        }



        cantTicketXMes++;

        auxT = auxT->sig;
    }
cout << "El mayor monto fue: " << ticketMayorMontoXMes << " por " << idTicketMayor << endl;
cout << "El menor monto fue: " << ticketMenorMontoXMes << " por " << idTickeMenor << endl;
cout << "El promedio de tickets es: " << montoTotalTicketXMes/cantTicketXMes << endl;

}

cout << "El ticket con mayor monto en el anio fue: " << ticketMayorMontoXAnio << " por " << idMesMayorXAnio << endl;
cout << "El ticket con menor monto en el anio fue: " << ticketMenorMontoXAnio << " por " << idMesMenorXAnio << endl;

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

void agregarNodo(Nodo* &p, int x){ // LE PASO LA LISTA Y UN VALOR INT
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

// pilas
void push(Nodo* &pila, int x){
Nodo* nuevo = new Nodo();
nuevo->info = x;
nuevo->sig = pila;
pila = nuevo;

}

int pop(Nodo* &pila){
int retorno = pila->info;
Nodo* aux = pila;
pila = aux->sig;
delete aux;
return retorno;
}

// colas
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
