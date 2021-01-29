#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct huella{ // ARCHIVO
	int dni;
	char apeNom[50];
	int dedo;
	int tipo;
	int subtipo;
};

struct Dedo { // SE PUEDE O NO HACER EL INFODEDO PERO ERA 1 SOLO CAMPO, ENTONCES NO LO HAGO
	int nroDedo;
	Dedo* sig;
};

struct infoSospe {
	int dni;
	char apeNom[50];
	Dedo* dedos;
};

struct Sospechoso {
	infoSospe info;
	Sospechoso* sig;
};


void cargarMatrizSospechoso(*Sospechoso &matriz[][],FILE * archivo);
void emitirSospechosos(*Sospechoso matriz[][],int tipo,int subtipo);


*Sospechoso buscaEInserta(Sospechoso* &p,infoSospe v , bool enc);
*Sospechoso buscarSospechoso(Sospechoso* p, infoSospe v);

*Dedo agregarDedo(Dedo* p, int x);



int main()
{

 FILE * archHuellas = fopen("huellas.dat","rb");
 huella reg;
 fread(&reg,sizeof(huellas),1,archHuellas);

 Sospechoso* matriz[4][9];

for (int i = 0; i < 3; i++){ // LA VACIO

    for (int j = 0; j < 8; j++){

        matriz[i][j] = NULL;
    }
}

cargarMatrizSospechoso(matriz,archHuellas);

emitirSospechosos(matriz);

fclose(archHuellas);

    return 0;
}

void cargarMatrizSospechoso(*Sospechoso &matriz[][],FILE * archivo){

infoSospe info;
Dedo* infoDedo;
Sospechoso* sospechosoInteres = NULL;
Dedo* dedoInt;
bool enc;

while (!feof(archHuellas)){

strcpy(info.apeNom,reg.apeNom);
info.dni = reg.dni;
info.dedos = NULL;

sospechosoInteres = buscaEInsertaSospechoso(matriz[reg.tipo-1][reg.subtipo-1],info, bool enc); // LO INSERTA ORDENADO POR NOMBRE Y APELLIDO

agregarDedo(sospechosoInteres->info.dedos,reg.dedo);

 fread(&reg,sizeof(huellas),1,archHuellas);
    }

}

void emitirSospechosos(Sospechoso * matSospe[4][9], int tipo, int subtipo){
	Sospechoso * listaSospe = matSospe[tipo-1][subtipo-1]; // NO RECORRO TODA LA MATRIZ PORQUE SOLO ME PIDE EL TIPO Y SUBTIPO
	int nroDedo;
	while(listaSospe != NULL){
		cout << listaSospe->info.apeNom << endl;
		cout << listaSospe->info.dni << endl;
		Dedo* dedosAux = listaSospe->info.dedos;
		while(dedosAux != NULL){
			nroDedo = dedosAux->nroDedo;
			switch(nroDedo) {
				case 1:
					cout << "pulgar mano derecha" << endl;
					break;
				case 2:
					cout << "indice mano derecha" << endl;
					break;
				case 3:
					cout << "medio mano derecha" << endl;
					break;
				case 4:
					cout << "anular mano derecha"<< endl;
					break;
				case 5:
					cout << "menique mano derecha"<< endl;
					break;
				case 6:
					cout << "pulgar mano izquierda"<< endl;
					break;
				case 7:
					cout << "indice mano izquierda"<< endl;
					break;
				case 8:
					cout << "medio mano izquierda"<< endl;
					break;
				case 9:
					cout << "anular mano izquierda" << endl;
					break;
				case 10:
					cout << "menique mano izquierda" << endl;
					break;
			}


			dedosAux = dedosAux->sig;
		}

		listaSospe = listaSospe->sig;
	}

}
