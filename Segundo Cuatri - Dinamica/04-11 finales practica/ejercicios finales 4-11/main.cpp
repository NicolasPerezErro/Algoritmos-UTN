#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//FINAL WHATSAPP

struct contactos{ // VECTOR
int idUsuario;
string nombreContacto; // AL NO TENER ARCHIVOS PODEMOS USAR DIRECTAMENTE STRING
bool blockear;
};

struct infoConversacion{
int idConversacion;
string nombreGrupo; // AL NO TENER ARCHIVOS PODEMOS USAR DIRECTAMENTE STRING
bool notificar;
bool vistaPrevia;
};


struct conversacion{
infoConversacion infoC;
conversacion* sig;
};

void notificarMensajeRecibido(Conversacion* lista, contacto vec[], int len, int idConversacion, int idUsuarioEmisor, string mensaje);
Conversacion* buscarConversacion(Conversacion* p, int v);
int buscarContacto(contacto arr[], int len, int v);
string numeroTelefonicoUsuario (int idUsuarioEmisor);
string vistaPrevia(string mensaje);
void emitirNotificacion(string titulo, string descripcion);
void agregarConversacion(Conversacion* &lista, infoConver x);


//////////////////////////////////////////////////////////////////////////////////////////////////////
// FINAL VECTORES

struct candidato {
	string nombre;
	int lista;
};

struct resultado {
	candidato cand;
	float pos;
};

void generarListaConsejerosDocentes(candidato vecCandidatos[], int lenCan, resultado vecResultado[], int &lenRes);
float votos1 = 50;
float votos2 = 35;
float votos3 = 15;

void ordenarVector(resultado vecAuxiliar[], int lenAux);


int main()
{

conversacion* conversaciones = NULL;
contactos vecContactos[200];










    return 0;
}

void ordenarVector(resultado vecAuxiliar[], int lenAux) {
	resultado temp;
	bool huboIntercambio = true;

	for(int i = 0; i < lenAux && huboIntercambio; i++) {

		huboIntercambio = false;
		for(int j=0; j < lenAux-1; j ++) {
			if(vecAuxiliar[j].pos < vecAuxiliar[j+1].pos) {
				huboIntercambio = true;
				temp = vecAuxiliar[j+1];
				vecAuxiliar[j+1] = vecAuxiliar[j];
				vecAuxiliar[j] = temp;
			}
	}
}
}

void generarListaConsejerosDocentes(candidato vecCandidatos[], int lenCan, resultado vecResultado[], int &lenRes){
	float votos[3] = {votos1, votos2, votos3};
	float votosLista;
	int k = 0;

	resultado vecAuxiliar[15];
	int lenAux = 15;

	for(int i=0; i < 3; i++){
		votosLista = votos[i];
		for(int j=0; j < 5; j++ ){
			vecAuxiliar[k].cand = vecCandidatos[k];
			vecAuxiliar[k].pos = votosLista / (j+1);
			k++;
		}
	}

	ordenarVector(vecAuxiliar,lenAux); // ordenar de mayor a menor

	for(int i= 0; i<5; i++){
		vecResultado[i].pos = i+1;
		vecResultado[i].cand = vecAuxiliar[i].cand;
		lenRes ++;
	}
}



void agregarConversacion(Conversacion* &lista, infoConver x){
	Conversacion* nuevo = new Conversacion();
	nuevo->info = x;
	nuevo->sig = NULL;
	if(lista==NULL) { // la lista p esta vac�a
		lista = nuevo;
	} else {
		Conversacion* aux = lista;
		while(aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

Conversacion* buscarConversacion(Conversacion* p, int v) {
    Conversacion* aux = p;
    while (aux != NULL && aux->info.idConversacion != v)
    {
        aux = aux->sig;
    }
    return aux;
}

int buscarContacto(contacto arr[], int len, int v) {
    int i = 0;
    int pos = -1;
    while (i < len && arr[i].idUsuario != v) {
        i++;
    }
    if (i < len) {
        pos = i;
    }

    return pos;
}

string numeroTelefonicoUsuario (int idUsuarioEmisor) {
	string nro = "+54911675684934";
	return nro;
}

string vistaPrevia(string mensaje) {
	return mensaje;
}

void emitirNotificacion(string titulo, string descripcion){
	cout << "Titulo: " << titulo << endl;
	cout << "Descripcion: " << descripcion << endl;
}

void notificarMensajeRecibido(Conversacion* lista, contacto vec[], int len, int idConversacion, int idUsuarioEmisor, string mensaje){

    // LEER BIEN EL ENUNCIADO, NO PIDE LLENAR NINGUNA LISTA. LA LISTA YA VIENE LLENA CON LOS DATOS DE LA CONVERSACION
    // LO QUE HACE ES IR OBTENIENDO LA INFO QUE NECESITA PASANDOLA A VARIABLES Y DESPUES USARLAS
	Conversacion* conversacionBuscada =	buscarConversacion(lista, idConversacion);
	int posContactoBuscado = buscarContacto(vec,len,idUsuarioEmisor);
	bool bloqueado;
	string nombreContacto;

	if(posContactoBuscado != -1){ // Si est� en el vector de contactos
		bloqueado = vec[posContactoBuscado].bloqueado;
		nombreContacto = vec[posContactoBuscado].nombre;
	} else { // No est� en el vector de contactos
		bloqueado = false;
		nombreContacto = numeroTelefonicoUsuario(idUsuarioEmisor);
	}

	string titulo;
	string descripcion;
	bool vistaPreviaConver;

	if(!bloqueado && conversacionBuscada->info.notificar){  // Se puede notificar SI NO ESTA BLOCKIADO Y TIENE ACTIVADA LA NOTIFICACION
		vistaPreviaConver = conversacionBuscada->info.vistaPrevia; // LO HACE ACA PORQUE QUIERE LOS QUE NO SON BLOCKEADOS Y ACT LA NOTI
		if(conversacionBuscada->info.nombre != "" ){ // Conversaci�n grupal
			titulo = conversacionBuscada->info.nombre;
			if(vistaPreviaConver) { //Grupal con vista previa
				descripcion = nombreContacto + " : " + vistaPrevia(mensaje);
			} else {  // Grupal sin vista previa
				descripcion = "Nuevo Mensaje de: " + nombreContacto;
			}
		} else { //Conversaci�n directa
			titulo = nombreContacto;
			if(vistaPreviaConver) { // directa con vista previa
				descripcion = vistaPrevia(mensaje);
			} else { // directa sin vista previa
				descripcion = "Nuevo mensaje.";
			}
		}

		emitirNotificacion(titulo, descripcion);
	} else {
		if(bloqueado){
			cout << "Esta bloqueado" << endl;
		}

		if(!conversacionBuscada->info.notificar) {
			cout << "No notificar" << endl;
		}
	}

}
