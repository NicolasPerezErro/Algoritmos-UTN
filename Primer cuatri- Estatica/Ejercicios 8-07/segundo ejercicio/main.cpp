#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct pelicula {
	int idPeli;
	char nombrePeli[50];
	int cantEsp;
};

struct peliculaFDS {
	char nombrePeli[50];
	int cantEsp;
};

void burbuja(pelicula vec[], int len);
int busquedaSecuencial(pelicula vec[], int len, int valorBuscado);



int main()
{


	FILE* uni = fopen("unicenter.dat","rb");
	FILE* dot = fopen("dot.dat","rb");
	FILE* finDeSemana = fopen("finDeSemana.dat","wb+");

	pelicula vec[20];
	int lenVec = 0;

	pelicula reg;

	fread(&reg,sizeof(pelicula),1,uni); // LEO EL PRIMER ARCHIVO - UNICENTER

	while(!feof(uni)){
		vec[lenVec] = reg; // PASA EL REG DIRECTO AL VECTOR -- SE PODRIA USAR EL INSERTAR?
		lenVec++;
		fread(&reg,sizeof(pelicula),1,uni);
	}

	int pos;

	fread(&reg,sizeof(pelicula),1,dot); // LEO EL SEGUNDO ARCHIVO - DOT

	while(!feof(dot)){
		pos = busquedaSecuencial(vec, lenVec, reg.idPeli); // BUSCO EN EL VECTOR (UNICENTER) POR ID PARA VER SI ESTA LA PELICULA O NO (BUSQUEDA SI O SI PORQUE LAS PELICULAS PUEDEN ESTAR DESORNADAS, NO PUEDO COMPARAR 1 POR 1)

		if(pos == -1){                  // SI NO ESTA LA PELICULA, AGREGO ESE REGISTRO AL VECTOR
			vec[lenVec] = reg;
			lenVec++;
		} else {
			vec[pos].cantEsp += reg.cantEsp;    // SI ESTA LA PELICULA, ACUMULO LA CANTIDAD DE EXPECTADORES EN EL VECTOR
		}

		fread(&reg,sizeof(pelicula),1,dot);
	}

	burbuja(vec, lenVec); // ORDENO DE MAYOR A MENOR

	cout << "La pelicula menos vista fue " << vec[lenVec-1].nombrePeli << " con " << vec[lenVec-1].cantEsp << " espectadores" << endl; // LENVEC-1 POS 4
	cout << "Las 3 peliculas mas vistas fueron: " << endl;
	for(int i = 0; i < lenVec-2; i++) {
		cout << "- " << vec[i].nombrePeli << " con " << vec[i].cantEsp << endl;
	}

	peliculaFDS regFDS;
	for(int i = 0; i< lenVec; i++) {
		strcpy(regFDS.nombrePeli,vec[i].nombrePeli);
		regFDS.cantEsp = vec[i].cantEsp;
		fwrite(&regFDS,sizeof(peliculaFDS),1,finDeSemana);
	}

	rewind(finDeSemana);

	fread(&regFDS,sizeof(peliculaFDS),1,finDeSemana);

	while(!feof(finDeSemana)){
		cout << regFDS.nombrePeli << endl;
		cout << regFDS.cantEsp << endl;
		cout << "___________________" << endl;
		fread(&regFDS,sizeof(peliculaFDS),1,finDeSemana);
	}

	fclose(uni);
	fclose(dot);
	fclose(finDeSemana);













    return 0;
}


void burbuja(pelicula vec[], int len) {
	pelicula temp;
	bool huboIntercambio = true;

	for(int i = 0; i < len && huboIntercambio; i++) {

		huboIntercambio = false;
		for(int j=0; j < len-1; j ++) {
			if(vec[j].cantEsp < vec[j+1].cantEsp) {
				huboIntercambio = true;
				temp = vec[j+1];
				vec[j+1] = vec[j];
				vec[j] = temp;
			}
		}

	}

}

int busquedaSecuencial(pelicula vec[], int len, int valorBuscado){
	int pos = -1;

	int i = 0;
	while(i<len && vec[i].idPeli != valorBuscado) {
		i++;
	}

	if(vec[i].idPeli == valorBuscado) {
		pos = i;
	}

	return pos;
}
