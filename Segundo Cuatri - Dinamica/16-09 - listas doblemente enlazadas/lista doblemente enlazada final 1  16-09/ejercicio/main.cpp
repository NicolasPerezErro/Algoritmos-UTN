#include <iostream>
#include <string.h>
using namespace std;

struct Nodo{
	int info;
	Nodo* sig;
};

struct planta {
	int piso;
	int suben;
	int bajan;
};

struct NodoAscensor {
	planta info;
	NodoAscensor* arriba;
	NodoAscensor* abajo;
};

//Devuelve distancia a la planta Baja
int insertarPisoArribaDelActualYMedir(NodoAscensor* &unNuevoPiso, NodoAscensor* &unPisoActual,int &distanciaPlantaAlta, int &distanciaPlantaBaja);
void medirDistanciaAPisosExtremos(NodoAscensor* unPiso, int &distanciaPlantaBaja, int &distanciaPlantaAlta);
void agregarNodoListaDoble(NodoAscensor* &lista, planta v);

int main()
{

NodoAscensor* ascensor;
planta info;

	info.piso = -3;
	info.suben = 23;
	info.bajan = 3;

	agregarNodoListaDoble(ascensor, info);

	info.piso = -1;
	info.suben = 25;
	info.bajan = 5;

	agregarNodoListaDoble(ascensor, info);


	info.piso =  0;
	info.suben = 7;
	info.bajan = 30;

	agregarNodoListaDoble(ascensor, info);

	info.piso =  2;
	info.suben = 9;
	info.bajan = 5;

	agregarNodoListaDoble(ascensor, info);

	info.piso =  4;
	info.suben = 1;
	info.bajan = 15;

	agregarNodoListaDoble(ascensor, info);

	//NodoAscensor* aux = ascensor;
	//Recorro hasta el final
	/*while(aux != NULL) {
		cout << aux->info.piso << endl;
		aux = aux->arriba;
	}
	*/
	//Recorro hasta el �ltimo nodo
	/*while(aux->arriba != NULL) {
		aux = aux->arriba;
	}

	while(aux != NULL) {
		cout << aux->info.piso << endl;
		aux = aux->abajo;
	}
	*/

	NodoAscensor* pisoActual = ascensor;

	//Me posiciono en el piso anterior al que voy a insertar
	while(pisoActual != NULL && pisoActual->info.piso != 2 ) {
		pisoActual = pisoActual->arriba;
	}

	NodoAscensor* unNuevoPiso = new NodoAscensor();
	unNuevoPiso->info.piso = 3;
	unNuevoPiso->info.suben = 4;
	unNuevoPiso->info.bajan = 0;
	unNuevoPiso->abajo = NULL;
	unNuevoPiso->arriba = NULL;

	int distanciaPlantaBaja = 0;
	int distanciaPlantaMasBaja = 0;
	int distanciaPlantaMasAlta = 0;

	distanciaPlantaBaja = insertarPisoArribaDelActualYMedir(unNuevoPiso, pisoActual, distanciaPlantaMasAlta, distanciaPlantaMasBaja);

	cout << "La distancia a la planta baja es " <<  distanciaPlantaBaja << endl;
	cout << "La distancia a la planta mas baja es " <<  distanciaPlantaMasBaja << endl;
	cout << "La distancia a la planta mas alta es " <<  distanciaPlantaMasAlta << endl;

    return 0;
}

void agregarNodoListaDoble(NodoAscensor* &lista, planta v) {
	NodoAscensor* nuevo = new NodoAscensor();
	nuevo->info = v;
	nuevo->arriba = NULL;
	nuevo->abajo = NULL;
	if(lista==NULL) { // la lista esta vac�a
		lista = nuevo;
	} else {
		NodoAscensor* aux = lista;
		while(aux->arriba != NULL) {
			aux = aux->arriba;
		}
		aux->arriba = nuevo;
		nuevo->abajo = aux;
	}

}

int insertarPisoArribaDelActualYMedir(NodoAscensor* &unNuevoPiso, NodoAscensor* &unPisoActual,int &distanciaPlantaMasAlta, int &distanciaPlantaMasBaja){
		unNuevoPiso->arriba = unPisoActual->arriba;
		unNuevoPiso->abajo = unPisoActual;
		unPisoActual->arriba->abajo = unNuevoPiso;
		unPisoActual->arriba = unNuevoPiso;

		medirDistanciaAPisosExtremos(unNuevoPiso,distanciaPlantaMasBaja,distanciaPlantaMasAlta);

		int distanciaPlantaBaja = 0;

		NodoAscensor* aux = unNuevoPiso;
		while(aux != NULL && aux->info.piso != 0){
			distanciaPlantaBaja++;
			if(aux->info.piso < 0) {
				aux = aux ->arriba;
			} else {
				aux = aux->abajo;
			}
		}

		return 	distanciaPlantaBaja;
	}

void medirDistanciaAPisosExtremos(NodoAscensor* unPiso, int &distanciaPlantaMasBaja, int &distanciaPlantaMasAlta){
	distanciaPlantaMasBaja = 0;
	distanciaPlantaMasAlta = 0;

	cout << "Mas bajo" << endl;
	NodoAscensor* auxAbajo = unPiso->abajo;
	while(auxAbajo != NULL){
		cout << auxAbajo->info.piso << endl;
		distanciaPlantaMasBaja++;
		auxAbajo = auxAbajo->abajo;
	}

	cout << "Mas alto" << endl;
	NodoAscensor* auxArriba = unPiso->arriba;
	while(auxArriba != NULL){
		cout << auxArriba->info.piso << endl;
		distanciaPlantaMasAlta++;
		auxArriba = auxArriba->arriba;
	}
}
