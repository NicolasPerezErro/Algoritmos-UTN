#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


struct Nodo{
	int info;
	Nodo* sig;
};


void agregarNodo(Cliente* &p, int x);
Cliente* buscaEInsertaEstudiante(Cliente* &p, infoestudiante v, bool & enc);

/*
void mostrar (Nodo* p);
void liberar(Nodo* &p);
Nodo* buscar(Nodo* p, int v);
void eliminar(Nodo*&p, int v);
int eliminarPrimerNodo(Nodo*&p);
Nodo* insertarOrdenado(Nodo*&p, int v);
*/

// STRUCT DEL ARCHIVO
struct venta {
	int nroCliente;
	char articulo[50];
	int cant;
	float precioUnitario;
};

// listas

struct infoArt {
	char articulo[50];
	int cantidad;
	float precioUnitario;
};

struct Articulo {
	infoArt info;
	Articulo* sig;
};

struct infoCliente{
	int nroCliente;
	float dineroGastado;
	Articulo* articulosComprados;
};

struct Cliente {
	infoCliente info;
	Cliente* sig;
};


int main()
{

//7-10 -> Ej 1: Resolver
    FILE * archivoVenta = fopen("ventas.dat","rb");
	venta reg;
	Cliente * listaClientes = NULL;
	bool enc;
	infoCliente infoC;
	Cliente * clienteBuscado;
	infoArt infoA;
	Articulo * articuloBuscado;

	fread(&reg,sizeof(venta),1,archivoVenta);

	while(!feof(archivoVenta)){
		infoC.nroCliente = reg.nroCliente;
		infoC.dineroGastado = 0;
		infoC.articulosComprados = NULL;

		clienteBuscado = buscaEInsertaCliente(listaClientes,infoC,enc);

		strcpy(infoA.articulo,reg.articulo);
		infoA.cantidad = reg.cant;
		infoA.precioUnitario = reg.precioUnitario;

		articuloBuscado = buscaEInsertaArticulo(clienteBuscado->info.articulosComprados,infoA,enc);

		if(enc){
			articuloBuscado->info.cantidad += reg.cant;
		}

		clienteBuscado->info.dineroGastado += reg.cant * reg.precioUnitario;

		fread(&reg,sizeof(venta),1,archivoVenta);
	}

	fclose(archivoVenta);

	float dineroGastadoPorTodosLosClientes = 0;

	Cliente * clienteAux = listaClientes;
	while(clienteAux != NULL) {
		cout << "El cliente " << clienteAux->info.nroCliente << " gasto $ " << clienteAux->info.dineroGastado << endl;
		cout << "Detalle: " << endl;
		Articulo* articuloAux = clienteAux->info.articulosComprados;
		while(articuloAux != NULL) {
			cout << articuloAux->info.articulo << "-" << articuloAux->info.cantidad << "-" <<
			articuloAux->info.precioUnitario << "-" << articuloAux->info.cantidad * articuloAux->info.precioUnitario << endl;
			articuloAux = articuloAux->sig;
		}
		dineroGastadoPorTodosLosClientes += clienteAux->info.dineroGastado;
		clienteAux = clienteAux->sig;
	}

	cout << "Total de Dinero Recaudado: " << dineroGastadoPorTodosLosClientes << endl;


    return 0;
}


Articulo* buscarArticulo(Articulo* p, infoArt v){
	Articulo* aux = p;
	while(aux!= NULL && strcmp(aux->info.articulo,v.articulo) != 0){
		aux = aux->sig;
	}
	return aux;
}

Articulo* agregarArticulo(Articulo* &p, infoArt x){
	Articulo* nuevo = new Articulo();
	nuevo->info = x;
	nuevo->sig = NULL;
	if(p==NULL) { // la lista p esta vac�a
		p = nuevo;
	} else {
		Articulo* aux = p;
		while(aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}

	return nuevo;
}

Articulo* buscaEInsertaArticulo(Articulo* &p, infoArt v, bool & enc) {
	Articulo * nodoBuscado = buscarArticulo(p,v);
	if(nodoBuscado != NULL) { // el nodo est� en la lista
		enc = true;
	} else { // el nodo no est�
		nodoBuscado = agregarArticulo(p,v);
		enc = false;
	}

	return nodoBuscado;
}


Cliente* buscarCliente(Cliente* p, infoCliente v){
	Cliente* aux = p;
	while(aux!= NULL && aux->info.nroCliente != v.nroCliente){
		aux = aux->sig;
	}
	return aux;
}

Cliente* agregarCliente(Cliente* &p, infoCliente x){
	Cliente* nuevo = new Cliente();
	nuevo->info = x;
	nuevo->sig = NULL;
	if(p==NULL) { // la lista p esta vac�a
		p = nuevo;
	} else {
		Cliente* aux = p;
		while(aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}

	return nuevo;
}

Cliente* buscaEInsertaCliente(Cliente* &p, infoCliente v, bool & enc) {
	Cliente * nodoBuscado = buscarCliente(p,v);
	if(nodoBuscado != NULL) { // el nodo est� en la lista
		enc = true;
	} else { // el nodo no est�
		nodoBuscado = agregarCliente(p,v);
		enc = false;
	}

	return nodoBuscado;
}

