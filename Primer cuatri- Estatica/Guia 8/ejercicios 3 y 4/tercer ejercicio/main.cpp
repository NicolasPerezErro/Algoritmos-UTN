#include <iostream>
#include "vectores.h"
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;


int main()
{

venta libreria;

FILE * archivo = fopen("ventas052018.dat","rb");

venta vecDatos[12]; //PREGUNTAR A LA PROFESORA POR EL TAMAÑO DEL ARCHIVO QUE NO SABEMOS ,  SE PONE EL TAMAÑO CONVENIENTE
int lenDatos = 0;

fread(&libreria,sizeof(venta),1,archivo);

while (!feof(archivo)){

agregarVentas(vecDatos,12,lenDatos,libreria);

fread(&libreria,sizeof(venta),1,archivo);

}

fclose(archivo);


int posDatos = 0;
int artMasVendido = 0;
int MaximoArtVendido = 0;
int ventasFacturadasEnElMes = 0;
int ArticuloAnterior;
int cantVendidaXArticulo;
int maximo = -1;

while (posDatos < lenDatos){

ArticuloAnterior = vecDatos[posDatos].codArt;
cantVendidaXArticulo = 0;


while (posDatos < lenDatos && ArticuloAnterior == vecDatos[posDatos].codArt){

cantVendidaXArticulo = cantVendidaXArticulo + vecDatos[posDatos].cantVendida;
ventasFacturadasEnElMes += vecDatos[posDatos].cantVendida * vecDatos[posDatos].precioUnitario; // ACUMULAS EL PRECIO POR LA VENTA DE CADA UNO

posDatos++;
    }

cout << "Cantidad vendida por el articulo " << ArticuloAnterior << " es: " << cantVendidaXArticulo << endl;



if (cantVendidaXArticulo > maximo){

    maximo = cantVendidaXArticulo;
    artMasVendido = ArticuloAnterior;

    }

}

cout << "Ventas facturadas en el mes: " << ventasFacturadasEnElMes << endl;
cout << "El articulo mas vendido es: " << artMasVendido << " con el total de " << maximo <<   endl;


cout << " --------------" << endl;
cout << " --------------" << endl;

cout << "Contenido del archivo: " << endl;

FILE * archleer = fopen("ventas052018.dat","rb");

fread(&libreria,sizeof(venta),1,archleer);

while (!feof(archleer)){

    cout << "Codigo: " << libreria.codArt << endl;
    cout << "Cant Vendida: " <<libreria.cantVendida << endl;
    cout << "Precio unitario: " << libreria.precioUnitario << endl;
    cout << "-------------" << endl;


    fread(&libreria,sizeof(venta),1,archleer);
}

fclose(archleer);


    return 0;
}
