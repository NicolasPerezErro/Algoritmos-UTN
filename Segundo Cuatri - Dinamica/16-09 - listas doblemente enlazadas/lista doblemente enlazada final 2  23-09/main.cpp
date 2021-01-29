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

struct pisoEliminado {
	int piso;
	int diffEntreSubenYBajan;
};

int EliminarLosPisosPrimosArribaDe(NodoAscensor* &unPisoActual,)
void EliminarPiso(Nodo& *unPiso);

int main()
{
  //Final 2
	NodoAscensor* ascensor = NULL;
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

	info.piso =  1;
	info.suben = 9;
	info.bajan = 5;

	agregarNodoListaDoble(ascensor, info);

	info.piso =  2;
	info.suben = 1;
	info.bajan = 15;

	agregarNodoListaDoble(ascensor, info);

	info.piso =  3;
	info.suben = 34;
	info.bajan = 7;

	agregarNodoListaDoble(ascensor, info);

	info.piso =  4;
	info.suben = 20;
	info.bajan = 9;

	agregarNodoListaDoble(ascensor, info);

	info.piso =  5;
	info.suben = 9;
	info.bajan = 2;

	agregarNodoListaDoble(ascensor, info);

	FILE * archivo = fopen("pisosPrimos.dat","wb+");
	pisoEliminado reg;
	int cantPisosEliminados;

	NodoAscensor* pisoActual = ascensor;
	//Me posiciono en el piso anterior al que voy a empezar a eliminar si es primo
	while(pisoActual != NULL && pisoActual->info.piso != 1 ) {
		pisoActual = pisoActual->arriba;
	}

	cantPisosEliminados = eliminarLosPisosPrimosArribaDe(pisoActual,archivo);

	cout << "La cantidad de pisos eliminados fue " << cantPisosEliminados << endl;

	rewind(archivo);

	fread(&reg,sizeof(pisoEliminado),1,archivo);
	while(!feof(archivo)){
		cout << reg.piso << endl;
		cout << reg.diffEntreSubenYBajan << endl;
		cout << "----------------------" << endl;
		fread(&reg,sizeof(pisoEliminado),1,archivo);
	}

	fclose(archivo);

	cout << "---------------------" << endl;

	while(pisoActual->arriba != NULL){
		pisoActual = pisoActual->arriba;
	}

	while(pisoActual != NULL){
		cout << pisoActual->info.piso << endl;
		pisoActual = pisoActual->abajo;
	}


    return 0;
}

void eliminarPiso(NodoAscensor* &unPiso){

	if(unPiso->abajo){
		unPiso->abajo->arriba = unPiso->arriba;
	}

	if(unPiso->arriba != NULL){
		unPiso->arriba->abajo = unPiso->abajo;
	}

	delete(unPiso);
}

bool esPrimo(int numero){
	bool resultado = true;

	for(int i = 2; i < numero; i++){
		if(numero%i == 0){
			resultado = false;
			break;
		}
	}

	return resultado;
}

int eliminarLosPisosPrimosArribaDe(NodoAscensor* &unPisoActual,FILE* arch){
	int cantPisosEliminados = 0;
	pisoEliminado reg;

	NodoAscensor* aux = unPisoActual;
	aux = aux->arriba;
	while(aux != NULL){
		if(esPrimo(aux->info.piso)){
			reg.piso = aux->info.piso;
			reg.diffEntreSubenYBajan = aux->info.suben - aux->info.bajan;
			fwrite(&reg,sizeof(pisoEliminado),1,arch);
			eliminarPiso(aux);
			cantPisosEliminados++;
		}
		aux = aux->arriba;
	}

	return cantPisosEliminados;
}
