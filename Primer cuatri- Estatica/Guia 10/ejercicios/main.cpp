#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct articulos{

int numeroArt;
char descripcion[50];
int cantidad;

};

struct consolidar{

articulos depositos;
char lugarArticulo[50];

};

void agregar(consolidar vec[],int n, int& len, consolidar v);
void mostrar(consolidar vec[],int len);

int main()
{

articulos datos;
consolidar datosConsolidados;

FILE * reg1 = fopen("deposito1.dat","rb");

fread(&datos,sizeof(articulos),1,reg1);

consolidar vec[10];
int lenVec = 0;


while (!feof(reg1)){

datosConsolidados.depositos = datos;

strcpy(datosConsolidados.lugarArticulo,"Deposito 1");

agregar(vec,10,lenVec,datosConsolidados);

fread(&datos,sizeof(articulos),1,reg1);
}

fclose(reg1);




FILE * reg2 = fopen("deposito2.dat","rb");

fread(&datos,sizeof(articulos),1,reg2);

consolidar vec2[10];
int lenVec2 = 0;


while (!feof(reg2)){

datosConsolidados.depositos = datos;

strcpy(datosConsolidados.lugarArticulo,"Deposito 2");

agregar(vec2,10,lenVec2,datosConsolidados);

fread(&datos,sizeof(articulos),1,reg2);
}

fclose(reg2);



FILE * regConsolidar = fopen("stock.dat","wb+");

int pos1 = 0;
int pos2 = 0;

while (pos1 < lenVec && pos2 < lenVec2){

     if(vec[pos1].depositos.numeroArt < vec2[pos2].depositos.numeroArt) {
      fwrite(&vec[pos1],sizeof(consolidar),1,regConsolidar);
      pos1++;

    } else {
      fwrite(&vec2[pos2],sizeof(consolidar),1,regConsolidar);
      pos2++;
    }

}

while (pos1 < lenVec){

fwrite(&vec[pos1],sizeof(consolidar),1,regConsolidar);
pos1++;

}

while (pos2 < lenVec2){

fwrite(&vec2[pos2],sizeof(consolidar),1,regConsolidar);
pos2++;

}

rewind(regConsolidar);

fread(&datosConsolidados,sizeof(consolidar),1,regConsolidar);


while (!feof(regConsolidar)){

    cout << "Articulo: "<< datosConsolidados.depositos.numeroArt << endl;
    cout << "Descripcion: " << datosConsolidados.depositos.descripcion << endl;
    cout << "Cantidad: " << datosConsolidados.depositos.cantidad << endl;
    cout << "Deposito: " << datosConsolidados.lugarArticulo << endl;
    cout << "------------------" << endl;

  fread(&datosConsolidados,sizeof(consolidar),1,regConsolidar);
}

fclose(regConsolidar);


    return 0;
}


void agregar(consolidar vec[],int n, int& len, consolidar v){

if (len < n){

    vec[len] = v;
    len++;
    }

}

void mostrar(consolidar vec[],int len){

for (int i = 0; i < len; i++){

    cout << vec[i].depositos.cantidad << endl;
    cout << vec[i].depositos.descripcion<< endl;
    cout << vec[i].depositos.numeroArt << endl;
    cout << "-------------" << endl;

    }

}
